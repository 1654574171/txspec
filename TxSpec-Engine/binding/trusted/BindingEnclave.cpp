#include "BindingEnclave.h"
#include "common/base64/Transform.h"
#include "trusted/test_utils/TestUtils.h"


using namespace std;

// handle 
BINDING_ERROR_CODE ecall_process_proof_request(const char *request, size_t input_size, char *response, size_t output_size) {
    
    BINDING_INFO("BindingEnclave: ecall_process_proof_request start");
    TxContext txContext;
    string requestString = DecodeFromCharToString(request);

    txContext.initTxContext(requestString);

    txContext.getBindingStrings();
    txContext.generateRuleCheckRequests();

    // get Response
    BINDING_INFO("BindingEnclave: check rule");
    txContext.checkRules();
    txContext.generateProofResponse();

    // // serialized and output response
    BINDING_INFO("BindingEnclave: return response");
    txContext.serializeProofResponse(response, output_size);
    BINDING_INFO("ecall_process_proof_request end.");
    return kBD_SUCCESS;
}



