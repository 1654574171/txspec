// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements glue methods between enclave to enclave.

#include "RuleResponse.h"

using namespace std;
using namespace e2e_message;
using namespace json11;

static void helper_function(const string& output) {
    uint32_t length = output.length() + 1;
    if (length <= 1) {
        ocall_print_string("Warning! want to output an empty string", __FILE__,
                           __LINE__);
    }
    char* outputBuffer = (char*)malloc(length);
    memcpy(outputBuffer, output.c_str(), length);
    ocall_print_string(outputBuffer, __FILE__, __LINE__);
}

#define RULE_INFO_STRING(str) helper_function(str)

// check_rule function for E2E Incoming Call
// NOTE: `status_list` is assumed to be created outside of this function and
// managed (e.g., freed) as well
RuleEnclaveStatus check_rule(const string& req_id, const string& rule_text,
                             const vector<string>& rule_id_list,
                             vector<bool>* const status_list) {
    RequestHandler request_handler;
    RuleEnclaveStatus ret =
        request_handler.CheckRule(req_id, rule_text, rule_id_list, status_list);
    return ret;
}

// get RuleCheckRequest from buffer of ms which inputed by binding enclave
bool get_RuleCheckRequest_from_ms(ms_in_msg_exchange_t* ms,
                                  RuleCheckRequest& request_input) {
    E2ERequest e2e_request;
    RULE_INFO_STRING("enter unmarshal_input_param");
    string function_input;
    ocall_print_string(
        string("rulechecker ms->inparam_buff:" + string(ms->inparam_buff))
            .c_str(),
        __FILE__, __LINE__);

    if (RequestResponseUtil::UnmarshalFunctionInput(&function_input, ms) !=
        (uint32_t)kLA_SUCCESS)
        return false;

    ocall_print_string(
        string("function_input rulechecker:" + function_input).c_str(),
        __FILE__, __LINE__);
    e2e_request.ParseFromString(function_input);

    if (!e2e_request.has_rule_check_input()) {
        return false;
    }
    request_input = e2e_request.rule_check_input();
    return true;
}

// encode contract id with tx hash in request id by using delimiter ":"
string generate_request_id(const RuleCheckRequest& request_input) {
    // prepare input parameters
    string contract_id = request_input.contractid();
    // transfer txhash to hex string format
    const string& txhash_raw = request_input.txhash();
    string tx_hash("0x");
    string hex("0123456789abcdef");

    for (int i = 0; i < txhash_raw.length(); i++) {
        char c = txhash_raw.at(i);
        tx_hash.push_back(hex[(c & 0xf0) >> 4]);
        tx_hash.push_back(hex[c & 0x0f]);
    }

    return contract_id + ":" + tx_hash;
}

RuleEnclaveStatus get_rulefile_content(const e2e_message::RuleItem& rule_item,
                                       const string& rule_file_name,
                                       vector<string>& ruleid_list,
                                       string& rule_content) {
    RULE_INFO_STRING("enter get_rulefile_content");
    RULE_INFO_STRING("Rule file name : " + rule_file_name);
    
    QueryBuilder query_builder;
    EntityRule entity(rule_file_name);
    string query_string = query_builder.GenerateQueryString(entity);

    Json entity_binding;
    Json query_result;
    DataProvider data_provider;
    if (data_provider.QueryDataFromGraphnodeJson(query_string, "", query_result) != RuleEnclaveStatus::kOK) {
        return RuleEnclaveStatus::kEntity_Query_Rulefile_error;
    }
    if (data_provider.ParseEntityOutputJSON(query_result, &entity_binding) != RuleEnclaveStatus::kOK ) {
        return RuleEnclaveStatus::kEntity_Query_Rulefile_error;
    }

    Json rule_text = entity_binding["rule"]["content"];
    rule_content = rule_text.string_value();
    RULE_INFO_STRING("Rule Enclave: get rulefile text");
    RULE_INFO_STRING(rule_content);

    for (const auto& rule_id : rule_item.ruleid()) {
        ruleid_list.push_back(rule_id);
    }

    return RuleEnclaveStatus::kOK;
}

void fill_rule_check_result(RuleCheckResult* rule_check_result,
                            const vector<bool>& status_list,
                            const vector<string>& rule_id_list,
                            const string& rule_file_name) {
    for (int i = 0; i < status_list.size(); i++) {
        ErrorInfo* info = rule_check_result->add_errorinfo();
        info->set_status(status_list[i]);
        info->set_rulefilename(rule_file_name);
        info->set_rulefileid(rule_id_list[i]);
        info->set_errorstring("");

        rule_check_result->set_status(rule_check_result->status() &&
                                      status_list[i]);
    }
}

string serialize_function_output(RuleCheckResponse* rulecheck_response) {
    E2EResponse e2e_response;
    e2e_response.set_allocated_rule_check_output(rulecheck_response);

    // build output value
    string function_output;
    e2e_response.SerializeToString(&function_output);
    return function_output;
}

RuleEnclaveStatus fill_rule_check_response(
    const RuleCheckRequest& request_input, RuleCheckResponse* response_output) {
    RULE_INFO_STRING("enter fill_rule_check_response");

    // init rule check response
    response_output->set_status(false);
    RuleCheckResult* rule_result = response_output->add_results();
    rule_result->set_status(true);
    rule_result->set_contractid(request_input.contractid());

    // check rule and fill response
    RULE_INFO_STRING("Rule Enclave: start query rule items");
    bool response_status = true;
    RuleEnclaveStatus status_code = RuleEnclaveStatus::kOK;
    for (const auto& rule_item : request_input.ruleitems()) {
        // get rule file content
        string rule_content;
        vector<string> rule_id_list;
        string rule_file_name = rule_item.rulefilename();
        status_code = get_rulefile_content(rule_item, rule_file_name,
                                           rule_id_list, rule_content);
        if (status_code != RuleEnclaveStatus::kOK) {
            return status_code;
        }

        // call delegate function to get rule result
        vector<bool> status_list;
        string request_id = generate_request_id(request_input);
        status_code =
            check_rule(request_id, rule_content, rule_id_list, &status_list);
        if (status_code != RuleEnclaveStatus::kOK) {
            return status_code;
        }

        // file result
        fill_rule_check_result(rule_result, status_list, rule_id_list,
                               rule_file_name);

        response_status = response_status && rule_result->status();
    }
    response_output->set_status(response_status);
    RULE_INFO_STRING(string("rule check response is: " +
                            response_output->SerializeAsString()));
    return status_code;
}

// Wrapper function which is executed on request from the binding enclave
RuleEnclaveStatus check_rule_wrapper(ms_in_msg_exchange_t* ms,
                                     size_t param_lenth, char** resp_buffer,
                                     size_t* resp_length) {
    UNUSED(param_lenth);
    ocall_print_string("enter check_rule_wrapper", __FILE__, __LINE__);
    if (!ms || !resp_length) {
        return RuleEnclaveStatus::kInvalid_parameter_error;
    }

    RuleCheckRequest request_input;
    if (!get_RuleCheckRequest_from_ms(ms, request_input)) {
        return RuleEnclaveStatus::kInvalid_parameter_error;
    }

    RuleCheckResponse* response_output = new RuleCheckResponse();
    RuleEnclaveStatus status =
        fill_rule_check_response(request_input, response_output);
    if (status != RuleEnclaveStatus::kOK) {
        return status;
    }

    // construct function output, response_output will be delete after this
    // invoke
    string function_output = serialize_function_output(response_output);

    // serialize function response output
    if (RequestResponseUtil::MarshalFunctionOutput(resp_buffer, resp_length,
                                                   &function_output) !=
        (uint32_t)kLA_SUCCESS) {
        ocall_print_string("enter check_rule_wrapper::Malloc_error", __FILE__,
                           __LINE__);
        return RuleEnclaveStatus::kMalloc_error;  // can set resp buffer to null
                                                  // here
    }

    ocall_print_string("exit check_rule_wrapper", __FILE__, __LINE__);
    return RuleEnclaveStatus::kOK;
}