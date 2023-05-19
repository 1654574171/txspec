#include "TxContext.h"
#include "common/base64/Transform.h"

#include "binding_enclave/BindingQuery.pb.h"
#include "e2e_message/E2EMessage.pb.h"
#include "e2e_message/Signature.pb.h"

#include "common/data_types/EnclaveId.h"
#include "common/local_attestation/trusted/RequestResponseUtil.h"
#include "key_management/KeyManagementExportFunction.h"
#include "rule/RuleExportFunction.h"
#include "BindingEnclave_t.h"
#include "test_utils/TestUtils.h"


using namespace std;
static const unsigned long kMaxOutSize = 8192UL;

// init Proof Request from string stream
// Todo
void TxContext::initTxContext (string& requestString) {
    BINDING_INFO("BindingEnclave: init proof request");
    this->proofRequest = new request_proto::ProofRequest();
    this->proofRequest->ParseFromString(requestString);

    BINDING_INFO("BindingEnclave: init enclave id");
    sgx_status_t status;
    uint32_t retcode;
    status = ocall_query_enclave_id(&retcode, uint64_t(SubModule::kKeyManagement), &this->keyEnclaveId);
    status = ocall_query_enclave_id(&retcode, uint64_t(SubModule::kBinding), &this->bindingEnclaveId);
    status = ocall_query_enclave_id(&retcode, uint64_t(SubModule::kRuleCheck), &this->ruleEnclaveId);
}

void TxContext::getBindingStrings() {
    request_proto::BindingQueryMessage bindingQuery;

    BINDING_INFO("BindingEnclave: collect message from proof request and generate binding query");
    const request_proto::Data& requestEventData = this->proofRequest->data();
    for (int i = 0; i < requestEventData.events_size(); i++) {
        // get contractid and event from proofRequest
        const string& contractid = requestEventData.events(i).contractid();
        ContractInfo* contract = new ContractInfo(contractid);
        this->contractInfos.insert({contractid, contract});
        for (int j = 0; j < requestEventData.events(i).events_size(); j++) {
            const string& eventName = requestEventData.events(i).events(j).eventname();
            contract->contractEvents.push_back(eventName);
        }

        // generate Binding Query 
        request_proto::BindingQueryItem* item = bindingQuery.add_items();
        item->set_contractid(contractid);
    }

    // serialize bindingQuery and call data service for result
    BINDING_INFO("BindingEnclave: serialize binding query");
    string queryString = bindingQuery.SerializeAsString();
    string queryEncodeString = EncodeFromStringToString(queryString);

    // prepare input and output
    uint32_t queryOutputLength = queryEncodeString.length() + 1;
    char* queryMessage = (char*)(malloc(queryOutputLength));
    memcpy(queryMessage, queryEncodeString.c_str(), queryOutputLength);
    char* queryResult = (char*)(malloc(kMaxOutSize));

    BINDING_INFO("BindingEnclave: get binding");
    ocall_get_binding(queryMessage, queryOutputLength, queryResult, kMaxOutSize);

    string queryResultString = DecodeFromCharToString(queryResult);
    bindingQuery.ParseFromString(queryResultString);

    BINDING_INFO("the query result is :");
    BINDING_INFO_STRING(bindingQuery.SerializeAsString());

    for (int i = 0; i < bindingQuery.items_size(); i++) {
        const request_proto::BindingQueryItem& item = bindingQuery.items(i); 
        BINDING_INFO("the contract id :");
        BINDING_INFO_STRING(item.contractid());

        BINDING_INFO("the binding string :");
        BINDING_INFO_STRING(item.contractbinding());
        this->contractInfos[item.contractid()]->contractBindingString = item.contractbinding();
    }

    SAFE_FREE(queryMessage);
    SAFE_FREE(queryResult);
 
}

// handle bingding string inside this->proofRequest and generate this->ruleCheckRequest
void TxContext::generateRuleCheckRequests() {

    BindingResolver bindingResolver;
    for (auto contract : this->contractInfos) {
        ContractInfo* contracInfo = contract.second;
        bindingResolver.resolveBindingString(contracInfo->contractBindingString);
        e2e_message::RuleCheckRequest* newRequest = new e2e_message::RuleCheckRequest();
         
        newRequest->set_contractid(contracInfo->contractID);
        newRequest->set_txhash(this->proofRequest->txhash());
        newRequest->set_blockheight(this->proofRequest->height());
        newRequest->set_txindex(this->proofRequest->txindex());

        bindingResolver.fillRuleCheckRequest(newRequest, contracInfo->contractEvents);

        contracInfo->ruleCheckRequest = newRequest;
        
    }
}

// serialize this->ruleChecRequest and call ruleCheck enclave for result
// Todo
void TxContext::checkRules() {
    for (auto contract : this->contractInfos) {
        ContractInfo* contractInfo = contract.second;

        e2e_message::E2ERequest e2eRuleCheckRequest;
        e2eRuleCheckRequest.set_func_id((uint64_t)ExportedRuleFunction::kCheckRule);
        e2eRuleCheckRequest.set_allocated_rule_check_input(contractInfo->ruleCheckRequest);

        string rulecheckString = e2eRuleCheckRequest.SerializeAsString();
        string rulecheckResponseString;

        BINDING_INFO_STRING(rulecheckString);

        BINDING_INFO("BindingEnclave: send rule check e2e request");
        RequestResponseUtil::E2ERequestResponse(this->bindingEnclaveId, this->ruleEnclaveId,
                                            uint32_t(ExportedRuleFunction::kCheckRule),
                                            ENCLAVE_TO_ENCLAVE_CALL,
                                            rulecheckString, &rulecheckResponseString);

        BINDING_INFO("check response");
        BINDING_INFO_STRING(rulecheckResponseString);

        e2e_message::E2EResponse response;
        response.ParseFromString(rulecheckResponseString);
        contractInfo->ruleCheckResponse = new e2e_message::RuleCheckResponse(response.rule_check_output());
        BINDING_INFO_STRING(contractInfo->ruleCheckResponse->SerializeAsString());
        BINDING_INFO("BindingEnclave: receive response");
    }

    BINDING_INFO("BindingEnclave: end check rules");

}
        
// get signature from key management enclave
// Todo
string TxContext::getSignature(const char* data) {

    e2e_message::E2ERequest signRequest;
    // mock an siganture request
    BINDING_INFO("BindingEnclave: start getting signature");
    e2e_message::SignInput* signData = new e2e_message::SignInput();

    signData->set_datas(data);
    signRequest.set_allocated_sign_input(signData);

    // // prepare e2e call
    string serializedSignRequest = signRequest.SerializeAsString();
    string serializedSignResonse;

    BINDING_INFO("BindingEnclave: send signature e2e request");
    RequestResponseUtil::E2ERequestResponse(this->bindingEnclaveId, this->keyEnclaveId,
                                            uint32_t(ExportedKeyManagementFunction::kSign),
                                            ENCLAVE_TO_ENCLAVE_CALL,
                                            serializedSignRequest, &serializedSignResonse);
    
    e2e_message::E2EResponse signResponse;
    if (!signResponse.ParseFromString(serializedSignResonse)) {
        BINDING_INFO("GetSignature failed! Invalid output!");
        return "";
    }

    if (signResponse.output_case() != e2e_message::E2EResponse::kSignOutput) {
        BINDING_INFO("GetSignature failed! Invalid output format!");
        return "";
    }

    const string& signString = signResponse.sign_output().signature();
    BINDING_INFO_STRING(signString);

    return signString;
}

// generate Proof Response
void TxContext::generateProofResponse() {

    BINDING_INFO("BindingEnclave: start generate proof response");
    this->proofResponse = new request_proto::ProofResponse();
    this->proofResponse->set_txhash(this->proofRequest->txhash());

    // if we have proofs from difference compliance engine
    // we should add multiple proof
    // for now, there is one compliance engine

    BINDING_INFO("BindingEnclave: start filling proof");
    request_proto::Proof* proof = this->proofResponse->add_proofs();
    bool proof_status = true;
    for (auto contract : this->contractInfos) {
        BINDING_INFO("BindingEnclave: start filling receipt");
        request_proto::Receipt* receipt = proof->add_receipts();
        e2e_message::RuleCheckResponse* contractRulecheckRes = contract.second->ruleCheckResponse;

        bool contract_status = contractRulecheckRes->status();
        proof_status &= contract_status;
        receipt->set_status(contract_status);
        receipt->set_contractid(contract.first);

        BINDING_INFO("BindingEnclave: start filling result");
        for (int i = 0; i < contractRulecheckRes->results_size(); i++) {
            for (int j = 0; j < contractRulecheckRes->results(i).errorinfo_size(); j++) {
                request_proto::ErrorInfo* errInfo = receipt->add_errorinfo();
                const e2e_message::ErrorInfo& resErrInfo = contractRulecheckRes->results(i).errorinfo(j);
                errInfo->set_status(resErrInfo.status());
                errInfo->set_rulefilename(resErrInfo.rulefilename());
                errInfo->set_rulefileid(resErrInfo.rulefileid());
                errInfo->set_errorstring(resErrInfo.errorstring());
            }
        }
    }

    proof->set_status(proof_status);

    // TODO
    // should replace raw data to hashed data
    BINDING_INFO("BindingEnclave: get signature of proof");
    string proofString = proof->SerializeAsString();
    string proofSignature = getSignature(proofString.c_str());
    proof->set_signature(proofSignature);

    BINDING_INFO("BindingEnclave: get signature of proof response");
    string proofResString = this->proofResponse->SerializeAsString();
    string proofResSignature = getSignature(proofResString.c_str());
    this->proofResponse->set_teesignature(proofResSignature);

}

void TxContext::serializeProofResponse(char* output, size_t size) {
    string outputString = this->proofResponse->SerializeAsString();

    string encodeOutputString = EncodeFromStringToString(outputString);
    uint32_t outputSize = encodeOutputString.length() + 1;

    if (outputSize > size) {
        BINDING_INFO("Binding Enclave: Error! output data exceed the max output size! ");
        return;
    }

    BINDING_INFO("Binding Enclave: output proof response data");
    memcpy(output, encodeOutputString.c_str(), outputSize);
    BINDING_INFO(output);
    return;
}

TxContext::~TxContext() {
    SAFE_DELETE(proofRequest);
    SAFE_DELETE(proofResponse);
}
