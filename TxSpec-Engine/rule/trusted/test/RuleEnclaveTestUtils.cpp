#include "RuleEnclaveTestUtils.h"

using namespace std;
using namespace json11;
using namespace e2e_call_proto;

/* Example QueryEntity output JSON
    {
        "transfer":{
            "channel_id": "mychannel",
            "chaincode_id": "oxtoken",
            "originator": "",
            "from": "alice",
            "to": "bob",
            "value": "100",
            "timestamp": "1234",
            "block_num": "10",
            "tx_index": "1"
        }
    }
*/

/* Example QueryEntitySet output JSON
    [
        {
            "transfer":{
                "channel_id": "mychannel",
                "chaincode_id": "oxtoken",
                "originator": "",
                "from": "alice",
                "to": "bob",
                "value": "100",
                "timestamp": "1234",
                "block_num": "10",
                "tx_index": "1"
            }
        },
        {
            "transfer":{
                "channel_id": "mychannel",
                "chaincode_id": "oxtoken",
                "originator": "",
                "from": "alice",
                "to": "bob",
                "value": "100",
                "timestamp": "1234",
                "block_num": "10",
                "tx_index": "1"
            }
        }
    ]
*/

// for erc20 rule example
const string kERC20QueryEntityOutputJSON = "{\n"
                                           "  \"message\": \"SUCCESS\",\n"
                                           "  \"result\": {\n"
                                           "    \"Transfer\": {\n"
                                           "      \"Sender\": [\n"
                                           "        \"0xAlice\"\n"
                                           "      ],\n"
                                           "      \"Receiver\": [\n"
                                           "        \"0xBob\"\n"
                                           "      ]\n"
                                           "    }\n"
                                           "  },\n"
                                           "  \"type\": \"entity\"\n"
                                           "}";
const string kERC20QueryEntitySetOutputJSON = "{\n"
                                              "  \"message\": \"SUCCESS\",\n"
                                              "  \"result\": {\n"
                                              "    \"SuspiciousAccountList\": {\n"
                                              "      \"Account\": [\n"
                                              "        \"0xAlice\"\n"
                                              "      ]\n"
                                              "    }\n"
                                              "  },\n"
                                              "  \"type\": \"entity\"\n"
                                              "}";

// for hello world rule example
const string kHelloWorldQueryEntityOutputJSON = "{\n"
                                                "\t\"Hello\": {\n"
                                                "\t\t\"World\": 100\n"
                                                "\t}\n"
                                                "}";

// for number attribute rule example
const string kNumberAttributeQueryEntityOutputJSON = "{\n"
                                                     "\t\"Number\": {\n"
                                                     "\t\t\"Attribute\": 12.34\n"
                                                     "\t}\n"
                                                     "}";

// for set not in rule example
const string kSetNotInQueryEntityOutputJSON = "{\n"
                                              "\t\"Element\": {\n"
                                              "\t\t\"Attribute\": 250\n"
                                              "\t}\n"
                                              "}";
const string kSetNotInQueryEntitySetOutputJSON = "[360, 110, 250]";

/* Mock Binding Functions for Rule Enclave Debug */

const string MockBindingQueryEntity(const string &base64_serialized_input)
{
    ocall_print_string("enter MockBindingQueryEntity");

    ocall_print_string((string("base64 serialized input in RuleEnclaveTestUtils: ") +
                        base64_serialized_input)
                           .c_str());

    // decode Base64 serialized input
    string serialized_input = DecodeFromStringToString(base64_serialized_input);

    // parse serialized input as E2ERequest with QueryEntityInput
    E2ERequest e2e_request;
    e2e_request.ParseFromString(serialized_input);

    ocall_print_string((string("enclave to enclave request in RuleEnclaveTestUtils:\n" +
                               e2e_request.Utf8DebugString()))
                           .c_str());

    // parse serialized input as QueryEntity function input
    QueryEntityInput query_input;
    // TODO add error handling
    assert(e2e_request.has_query_entity_input());
    query_input = e2e_request.query_entity_input();

    ocall_print_string(string("received QueryEntityInput request:\n" +
                              query_input.Utf8DebugString())
                           .c_str());

    // generate mock QueryEntity function output
    // NOTE: `query_output` is managed and delted by `e2e_response` (which is later created)
    QueryEntityOutput *query_output = new QueryEntityOutput();
    query_output->set_request_id(query_input.request_id());

    // TODO decide on request id (which should be Entity name for Debug)
    if (query_input.request_id() == "erc20")
    {
        query_output->set_json_str(kERC20QueryEntityOutputJSON);
    }

    ocall_print_string((string("prepared QueryEntityOutput response:\n" +
                               query_output->Utf8DebugString()))
                           .c_str());

    // serialized QueryEntityOut function output into E2EResponse
    E2EResponse e2e_response;
    e2e_response.set_allocated_query_entity_output(query_output);

    ocall_print_string((string("constructed E2EResponse:\n" +
                               e2e_response.Utf8DebugString()))
                           .c_str());

    // serialize QueryEntity function output
    string serialized_output;
    e2e_response.SerializeToString(&serialized_output);

    // encode serialized output with Base64 encoding
    string base64_serialized_output = EncodeFromStringToString(serialized_output);

    ocall_print_string((string("base64 serialized output in RuleEnclaveTestUtils:" +
                               base64_serialized_output))
                           .c_str());

    return base64_serialized_output;
}

const string MockBindingQueryEntitySet(const string &base64_serialized_input)
{
    ocall_print_string("enter MockBindingQueryEntitySet");

    ocall_print_string((string("base64 serialized input in RuleEnclaveTestUtils: ") +
                        base64_serialized_input)
                           .c_str());

    // decode Base64 serialized input
    string serialized_input = DecodeFromStringToString(base64_serialized_input);

    // parse serialized input as E2ERequest with QueryEntityInput
    E2ERequest e2e_request;
    e2e_request.ParseFromString(serialized_input);

    ocall_print_string((string("enclave to enclave request in RuleEnclaveTestUtils:\n" +
                               e2e_request.Utf8DebugString()))
                           .c_str());

    // parse serialized input as QueryEntitySet function input
    QueryEntitySetInput query_input;
    // TODO add error handling
    assert(e2e_request.has_query_entity_set_input());
    query_input = e2e_request.query_entity_set_input();

    ocall_print_string(string("received QueryEntitySetInput request:\n" +
                              query_input.Utf8DebugString())
                           .c_str());

    // generate mock QueryEntitySet function output
    // NOTE: `query_output` is managed and delted by `e2e_response` (which is later created)
    QueryEntitySetOutput *query_output = new QueryEntitySetOutput();
    query_output->set_request_id(query_input.request_id());

    // TODO decide on request id (which should be EntitySet name for Debug)
    if (query_input.request_id() == "erc20")
    {
        query_output->set_json_str(kERC20QueryEntitySetOutputJSON);
    }

    ocall_print_string((string("prepared QueryEntitSetyOutput response:\n" +
                               query_output->Utf8DebugString()))
                           .c_str());

    // serialized QueryEntityOut function output into E2EResponse
    E2EResponse e2e_response;
    e2e_response.set_allocated_query_entity_set_output(query_output);

    ocall_print_string((string("constructed E2EResponse:\n" +
                               e2e_response.Utf8DebugString()))
                           .c_str());

    // serialize QueryEntity function output
    string serialized_output;
    e2e_response.SerializeToString(&serialized_output);

    // encode serialized output with Base64 encoding
    string base64_serialized_output = EncodeFromStringToString(serialized_output);

    ocall_print_string((string("base64 serialized output in RuleEnclaveTestUtils:" +
                               base64_serialized_output))
                           .c_str());

    return base64_serialized_output;
}