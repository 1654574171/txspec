// LICENSE: Apache 2.0 
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
// 
// This file implements some ocall functions used for metric monitor
// when program running inside enclave. 

#include "common/monitor/untrusted/UntrustedEnclaveCollectMetrics.h"

using namespace std;

// ocall_push_metrics adds a new time series for a metric, 
// with {label_key, label_value} as a specific label,
// and collects metric value of this metric{label_key = label_value}
void ocall_push_metrics(const metric_type_t metric,
                        const char *label_key,
                        const char *label_value,
                        const float data_value)
{
    auto t_id = std::this_thread::get_id();
    stringstream ss;
    ss << t_id;
    string idstr = ss.str();
    switch (metric)
    {
    case kMT_COUNTER:
    {
        // auto &counter = kPrometheus->counter_family->Add({{string(label_key), string(label_value)}, {"thread_id", idstr}});
        // counter.Increment(data_value);
        break;
    }

    case kMT_GAUGE:
    {
        // auto &gauge = kPrometheus->gauge_family->Add({{string(label_key), string(label_value)}, {"thread_id", idstr}});
        // if (data_value >= 0)
        //     gauge.Increment(data_value);
        // else
        //     gauge.Decrement(-data_value);
        break;
    }

    case kMT_HISTOGRAM:
    {
        mtx_kPrometheus.lock();
        vector<double> tmp_bounderies = {0.1, 0.5, 1.0, 5.0, 10.0, 50.0};
        auto &histogram = kPrometheus->histogram_family->Add({{string(label_key), string(label_value)}, {"thread_id", idstr}}, tmp_bounderies);
        mtx_kPrometheus.unlock();
        histogram.Observe(data_value);
        break;
    }

    default:
        // TODO (Xufei) Should add in log output
        break;
    }
}


// ocall_get_time acquire program timer from outside of trusted environment
int64_t ocall_get_time()
{
    return std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch()).count();
}