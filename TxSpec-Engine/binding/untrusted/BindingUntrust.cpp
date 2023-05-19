#include <iostream>
#include <common/base64/Transform.h>
#include <spdlog/spdlog.h>
#include "BindingQuery.h"

#include <BindingQuery.pb.h>
#include "BindingUntrust.h"
#include <http_client/HttpClient.h>

using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif

    void ocall_get_binding (const char* query_request, size_t request_length,
                            char* query_result, size_t result_length) {
        
        BindingQuery bindingQuery;
        bindingQuery.initBindingQuery(query_request);

        if (!bindingQuery.queryBindingString(query_result)) {
            cout<< "Error: query Binding String fail!" << endl;
            return;
        }
        
    }

    // for binding debug
    void ocall_print(const char* output_string, size_t string_length) {
        SPDLOG_INFO(output_string);
    }

#ifdef __cplusplus
}
#endif
