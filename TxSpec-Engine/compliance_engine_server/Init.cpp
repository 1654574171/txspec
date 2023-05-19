#include "compliance_engine_server/Init.h"
#include <fstream>
#include <iostream>

static struct option long_options[] = {
    {"log", required_argument, NULL, 'l'},
    {"config", required_argument, NULL, 'c'}};


Client *kPrometheus;
std::mutex mtx_kPrometheus;

using namespace std;

static void parse_args(int argc, char *argv[], string* config_file, string* log_file)
{
    int c = 0;
    int index = 0;
    while (EOF != (c = getopt_long(argc, argv, "l:c:", long_options, &index)))
    {
        switch (c)
        {
        case 'l':
            cout << "Running with argument 'log': " << optarg << endl;
            *log_file = string(optarg);
            break;
        case 'c':
            cout << "Running with argument 'config': " << optarg << endl;
            *config_file = string(optarg);
            break;
        case '?':
            cout << "Running with unknown argument: " << optopt << endl;
            *config_file = string(optarg);
            break;
        default:
            break;
        }
    }
    if (*log_file == "")
    {
        cout << "Running with default argument 'log': ../logs/compliance_engine.log" << endl;
        *log_file = "../logs/compliance_engine.log";
    }
    if (*config_file == "")
    {
        cout << "Running with default argument 'config': ../config/ComplianceEngine.yaml" << endl;
        *config_file = "../config/ComplianceEngine.yaml";
    }
    cout << "Finish parsing arguments" << endl;
}

static void setup_logger(string log_file)
{
    // check if log file exist. If not, create one
    // fstream fs;
    // fs.open(log_file);
    // if (!fs)
    // {
    //     ofstream fout(log_file);
    // }

    auto max_file_size = 1024 * 1024 * 5;
    auto max_file_num = 5;
    auto console_sink_untrusted = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink_untrusted = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(log_file, max_file_size, max_file_num);
    std::vector<spdlog::sink_ptr> sinks_untrusted;
    sinks_untrusted.push_back(console_sink_untrusted);
    sinks_untrusted.push_back(file_sink_untrusted);

    auto console_sink_trusted = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink_trusted = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(log_file, max_file_size, max_file_num);
    std::vector<spdlog::sink_ptr> sinks_trusted;
    sinks_trusted.push_back(console_sink_trusted);
    sinks_trusted.push_back(file_sink_trusted);

    auto untrusted_logger = std::make_shared<spdlog::logger>("untrusted_logger", begin(sinks_untrusted), end(sinks_untrusted));
    untrusted_logger->set_pattern("[%t][%Y-%m-%d %H:%M:%S.%e][%n][%l][%@,%!] : %v");
    untrusted_logger->set_level(spdlog::level::info);
    untrusted_logger->flush_on(spdlog::level::info);

    auto trusted_logger = std::make_shared<spdlog::logger>("trusted_logger", begin(sinks_trusted), end(sinks_trusted));
    trusted_logger->set_pattern("[%t][%Y-%m-%d %H:%M:%S.%e][%n][%l] : %v");
    trusted_logger->set_level(spdlog::level::info);
    trusted_logger->flush_on(spdlog::level::info);

    spdlog::register_logger(untrusted_logger);
    spdlog::register_logger(trusted_logger);

    spdlog::set_default_logger(untrusted_logger);

    SPDLOG_INFO("Finish setting loggers (console and file)");
}

static void setup_metrics_monitor()
{
    char *tmp = getenv("CORE_MONITOR_ADDRESS");
    string ip_address;
    if (tmp == NULL)
    {
        try
        {
            ip_address = config["monitor"]["CORE_MONITOR_ADDRESS"].as<string>();
        }
        catch (YAML::TypedBadConversion<string> &e)
        {
            SPDLOG_INFO("monitor:CORE_MONITOR_ADDRESS is NULL");
            return;
        }
    }
    else
    {
        ip_address = string(tmp);
    }

    SPDLOG_INFO("Successfully get monitor_address env variable: {0}", ip_address);
    kPrometheus = new Client();
    kPrometheus->SetupGateway(ip_address, {{"instance", "Cplusplus_client"}});
    kPrometheus->NewHistogramMetrics("time_consume_histogram",
                                     "Record all types of consuming-time",
                                     {{"target", "time"}, {"unit", "ms"}});
    SPDLOG_INFO("Finish setting up Histogram Metrics");
    SPDLOG_INFO("Finish setting up all Metrics");
}

int init_logger_monitor(int argc, char *argv[])
{
    string log_file = "";
    string config_file = "";
    parse_args(argc, argv, &config_file, &log_file);
    setup_logger(log_file);

    // obtain config information for yaml file
    if (loadConfigFromYamlFile(config_file) != uint32_t(EngineStatus::kOK))
    {
        SPDLOG_INFO("obtain config Failure");
        return int(ConfigStatus::kConfigReadError);
    }

    setup_metrics_monitor();
    return int(ConfigStatus::kOK);
}