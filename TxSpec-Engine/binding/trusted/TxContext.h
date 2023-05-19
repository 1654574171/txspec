// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// Request resolver and response constructor.
#pragma once

#include <map>
#include <string>
#include <vector>

#include "BindingEnclave_t.h"
#include "binding_language/BindingResolver.h"
#include "binding_enclave/ProofRequest.pb.h"
#include "binding_enclave/ProofResponse.pb.h"

// helper class used to record contract ids in an transaction
// and the related binding string and RuleCheck Request
class ContractInfo {
    public:
        std::string contractID;
        std::string contractBindingString;
        std::vector<std::string> contractEvents;
        e2e_message::RuleCheckRequest* ruleCheckRequest;
        e2e_message::RuleCheckResponse* ruleCheckResponse;

    public:
        ContractInfo() = default;
        ContractInfo(const std::string& contractid) : contractID(contractid) {}
        ~ContractInfo() {
            SAFE_DELETE(ruleCheckRequest);
            SAFE_DELETE(ruleCheckResponse);
        }
};


class TxContext {
    public:
        request_proto::ProofRequest* proofRequest;
        request_proto::ProofResponse* proofResponse;
        std::map<std::string, ContractInfo*> contractInfos;
        
    public:
        // init Proof Request from string stream
        void initTxContext (std::string& rquestString);

        // get constracts binding string
        void getBindingStrings();

        // handle bingding string and generate ruleCheckRequests
        void generateRuleCheckRequests();

        // call ruleCheck enclave for result
        void checkRules();

        // get signature from key management enclave
        std::string getSignature(const char* data);

        // generate Proof Response
        void generateProofResponse();
        void serializeProofResponse(char* output, size_t size);

        // safe release malloc memory
        ~TxContext();

    private:
        sgx_enclave_id_t bindingEnclaveId;
        sgx_enclave_id_t keyEnclaveId;
        sgx_enclave_id_t ruleEnclaveId;

};