#pragma once
#include <iostream>

#ifdef __cplusplus
extern "C"
{
#endif
void ocall_get_binding (const char* query_request, size_t request_length,
                        char* query_result, size_t result_length);

// for binding debug
void ocall_print(const char* output_string, size_t string_length);

#ifdef __cplusplus
}
#endif