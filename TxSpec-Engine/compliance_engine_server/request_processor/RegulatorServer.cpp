#include "compliance_engine_server/request_processor/RegulatorServer.h"
#include "RegulatorServiceImpl.h"
#include "RegisterServiceImpl.h"

#include "compliance_engine_server/Config.h"
#include <yaml-cpp/yaml.h>
#include <spdlog/spdlog.h>
// #include <spdlog/sinks/stdout_color_sinks.h>

using namespace std;

REQUESTPROCESSOR_ERROR_CODE RegulatorServer::ReadConfig() {
    string core_regulator_endpoint;
    try
    {
        core_regulator_endpoint = config["requestprocessor"]["CORE_REGULATOR_ENDPOINT"].as<string>();
    }
    catch (YAML::TypedBadConversion<string> &e)
    {
        SPDLOG_INFO("requestprocessor:CORE_REGULATOR_ENDPOINT is NULL");
        return REQUESTPROCESSOR_ERROR_CODE::kGRPCSERVICE_SETUP_ERROR;
    }

    SPDLOG_INFO("Compliance Engine Endpoint: {0}", core_regulator_endpoint);

    if (!core_regulator_endpoint.empty())
    {
        int idx = core_regulator_endpoint.find(":");
        string ip_tmp = core_regulator_endpoint.substr(0, idx);
        string port_tmp = core_regulator_endpoint.substr(idx + 1);
        // verify ip
        if (!CheckIPAddrIsValid(ip_tmp) || !CheckPortIsValid(port_tmp))
        {
        SPDLOG_INFO("Failed to verfiy Compliance Engine Endpoint {0}", core_regulator_endpoint);
        return REQUESTPROCESSOR_ERROR_CODE::kGRPCSERVICE_SETUP_ERROR;
        }
    }

    this->address = core_regulator_endpoint;
}

REQUESTPROCESSOR_ERROR_CODE RegulatorServer::RunServer()
{
    ReadConfig();
    RegulatorServiceImpl regulatorService(this->bindingEnclaveID);
    RegisterServiceImpl registerService(this->keyManagementEnclaveID);

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder builder;

    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(this->address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&regulatorService);
    builder.RegisterService(&registerService);


    // Finally assemble the server.
    this->server = move(builder.BuildAndStart());
    SPDLOG_INFO("Server listening on {}", this->address);

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    this->server->Wait();
    return REQUESTPROCESSOR_ERROR_CODE::kRPSUCCESS;
}

void RegulatorServer::RegisteEnclaveID(sgx_enclave_id_t key_management_id, sgx_enclave_id_t binding_id)
{
    this->keyManagementEnclaveID = key_management_id;
    this->bindingEnclaveID = binding_id;
}