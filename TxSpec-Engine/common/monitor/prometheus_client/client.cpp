#include "common/monitor/prometheus_client/client.h"

using namespace std;
using namespace prometheus;

Client::Client()
{
    this->gateway = NULL;
    this->registry = NULL;
    this->counter_family = NULL;
    this->gauge_family = NULL;
    this->histogram_family = NULL;
    // this->summary_family = NULL;
}

Client::~Client()
{

    delete this->gateway;
    this->gateway = NULL;

    // delete this->registry;
    // this->registry = NULL;

    if (this->counter_family != NULL)
    {
        delete this->counter_family;
        this->counter_family = NULL;
    }
    if (this->gauge_family != NULL)
    {
        delete this->gauge_family;
        this->gauge_family = NULL;
    }
    if (this->histogram_family != NULL)
    {
        delete this->histogram_family;
        this->histogram_family = NULL;
    }
    // if (this->summary_family != NULL)
    // {
    //     delete this->summary_family;
    //     this->summary_family = NULL;
    // }
}

// SetupGateway Connects to prometheus pushgateway with given ip address
bool Client::SetupGateway(const string monitor_address,
                          const std::map<std::string, std::string> &label)
{
    // TODO (Xufei) Add in syntax check for ip and port
    // TODO (Xufei) Add in dynamic config for ip, port, job. [DONE]

    int idx = monitor_address.find(":");
    string ip_tmp = monitor_address.substr(0, idx);
    string port_tmp = monitor_address.substr(idx + 1);
    this->ip = ip_tmp;
    this->port = port_tmp;

    this->gateway = new Gateway(this->ip, this->port, this->job, label);
    this->registry = std::make_shared<Registry>();
    return true;
}

void Client::NewCounterMetrics(const std::string name,
                               const std::string help,
                               const std::map<std::string, std::string> &labels)
{
    // this->counter_family = new Family<Counter>(name, help, labels);
    prometheus::detail::Builder<prometheus::Counter> tmp_builder;
    tmp_builder = tmp_builder.Name(name);
    tmp_builder = tmp_builder.Help(help);
    tmp_builder = tmp_builder.Labels(labels);
    this->counter_family = &(tmp_builder.Register(*(this->registry)));
    this->Register();
}

void Client::NewGaugeMetrics(const std::string name,
                             const std::string help,
                             const std::map<std::string, std::string> &labels)
{
    prometheus::detail::Builder<prometheus::Gauge> tmp_builder;
    tmp_builder = tmp_builder.Name(name);
    tmp_builder = tmp_builder.Help(help);
    tmp_builder = tmp_builder.Labels(labels);
    this->gauge_family = &(tmp_builder.Register(*(this->registry)));
    this->Register();
}
void Client::NewHistogramMetrics(const std::string name,
                                 const std::string help,
                                 const std::map<std::string, std::string> &labels)
{
    prometheus::detail::Builder<prometheus::Histogram> tmp_builder;
    tmp_builder = tmp_builder.Name(name);
    tmp_builder = tmp_builder.Help(help);
    tmp_builder = tmp_builder.Labels(labels);
    this->histogram_family = &(tmp_builder.Register(*(this->registry)));
    this->Register();
}
void Client::NewSummaryMetrics(const std::string name,
                               const std::string help,
                               const std::map<std::string, std::string> &labels)
{
    // this->summary_family = new Family<Summary>(name, help, labels);
}

int Client::PushAll()
{
    // this->gateway->RegisterCollectable(this->registry);
    int ret = this->gateway->Push();
    // cout << "return code:" << ret << endl;
}

void Client::Register()
{
    this->gateway->RegisterCollectable(this->registry);
}