// LICENSE: Apache 2.0 
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
// 
// This file declares class Client. 

#pragma once

#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include "spdlog/spdlog.h"
#include "prometheus/client_metric.h"
#include "prometheus/counter.h"
#include "prometheus/family.h"
#include "prometheus/gateway.h"
#include "prometheus/registry.h"
#include "prometheus/histogram.h"

#ifdef _WIN32
#include <Winsock2.h>
#else
#include <unistd.h>
#endif

// Client is used to connect with prometheus pushgateway,
// establish metrics, collect time series data with different labels,
// and push metrics data.
// Example of usage:
//   Client *prometheus = new Client();
//   prometheus->SetupGateway("ip:port", {{"label_key", "label_value"}});
//   prometheus->NewHistogramMetrics("new_histogram_metric_name",
//                                   "how to use new histogram metric?",
//                                   {{"new_histogram_metric_key", "value"}});
//   ...
//   auto& histogram_1 = prometheus->histogram_family->Add(...);
//   double data_value = ...;
//   histogram_1.Observe(data_value);
//   ...
//   prometheus->PushAll();
class Client
{

public:
    Client();
    ~Client();

    bool SetupGateway(const std::string core_monitor_address,
                      const std::map<std::string, std::string> &label);
    void NewCounterMetrics(const std::string name,
                           const std::string help,
                           const std::map<std::string, std::string> &labels);
    void NewGaugeMetrics(const std::string name,
                         const std::string help,
                         const std::map<std::string, std::string> &labels);
    void NewHistogramMetrics(const std::string name,
                             const std::string help,
                             const std::map<std::string, std::string> &labels);
    void NewSummaryMetrics(const std::string name,
                           const std::string help,
                           const std::map<std::string, std::string> &labels);
    int PushAll();
    void Register();

    prometheus::Family<prometheus::Counter> *counter_family;
    prometheus::Family<prometheus::Gauge> *gauge_family;
    prometheus::Family<prometheus::Histogram> *histogram_family;
    // prometheus::Family<prometheus::Summary> *summary_family;

private:
    std::string ip;
    std::string port;
    std::string job = "compliance_engine";
    prometheus::Gateway *gateway;
    // registry is an intelligent pointer. Do not need to free it explicitly
    std::shared_ptr<prometheus::Registry> registry;
};