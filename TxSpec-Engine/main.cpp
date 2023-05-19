// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares the entrypoint of ComplianceEngine.

#include <unistd.h>
#include <stdio.h>
#include <fstream>
#include <mutex>

#include "compliance_engine_server/ComplianceEngine.h"
#include "compliance_engine_server/Config.h"
#include "compliance_engine_server/Init.h"

using namespace std;

// extern int optind, opterr, optopt;
// extern char *optarg;


// main is the entrypoint of ComplianceEngine
int main(int argc, char *argv[])
{

    ComplianceEngine complianceEngine;
    if (init_logger_monitor(argc, argv))
    {
        SPDLOG_INFO("Init Logger and monitor faile!");
        return int(EngineStatus::kInitLoggerError);
    }

    // first, load all enclaves needed, i.e., key management, rule check, and binding
    if (complianceEngine.LoadEnclaves() != SGX_SUCCESS)
    {
        // Print log with manul-set file name and line number.
        SPDLOG_INFO("Load Enclave Failure");
        return int(EngineStatus::kEnclaveLoadError);
    }

    // then, establish secure channel between enclave pairs through local attestation
    if (complianceEngine.StartLocalAttesttion() != SGX_SUCCESS)
    {
        SPDLOG_INFO("Local Attestion Failure");
        return int(EngineStatus::kLocalAttestationError);
    }

    // create http client use for query data service
    if (complianceEngine.LaunchHttpClient() != SGX_SUCCESS)
    {
        SPDLOG_INFO("launch http client Failure");
        return int(EngineStatus::kHttpClientError);
    }

    // then, launch main grpc server to start compliance engine service
    if (complianceEngine.LaunchGRPCServer() != uint32_t(EngineStatus::kOK))
    {
        SPDLOG_INFO("Launch gRPC Server Failure");
        return int(EngineStatus::kGRPCServerError);
    }

    return int(EngineStatus::kOK);
}
