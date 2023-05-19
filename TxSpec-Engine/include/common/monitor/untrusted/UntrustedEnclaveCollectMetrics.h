// LICENSE: Apache 2.0 
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
// 
// This file declares some ocall functions used for metric monitor
// when program running inside enclave.

#pragma once

#include <time.h>
#include <thread>
#include <sstream>

#include "common/monitor/prometheus_client/client.h"
#include "common/monitor/trusted/MetricsType.h"


extern Client *kPrometheus;
extern std::mutex mtx_kPrometheus;
#ifdef __cplusplus
extern "C"
{
#endif
    // Example of usage:
    //   // Inside trusted code
    //   sgx_status_t ret = ocall_push_metrics(kMT_COUNTER,
    //                                         "key", "value",
    //                                         0.0, NULL);
    // Params:
    //   metric: enum data type indicates which type of metric you're going to use
    //   label_key: a string shows the key of key-value label
    //   label_value: a string shows the value of key-value label
    //   data_value: a numeric data shows the metric value you're going to record
    //   bounderies: a vector of numeric data shows the bounderies of histogram metric.
    //               If not histogram metric, just pass NULL
    // Returns:
    //   there's no output, but sgx_status_t will be returned.
    void ocall_push_metrics(const metric_type_t metric,
                            const char *label_key,
                            const char *label_value,
                            const float data_value);
    
    // Example of usage:
    //   // Inside trusted code
    //   long time;
    //   sgx_status_t = ocall_get_time(&time);
    // Params:
    //   there's no inputs
    // Returns: 
    //   long int: shows a timer, as a output.
    //   sgx_status_t will be returned.
    int64_t ocall_get_time();

#ifdef __cplusplus
}
#endif