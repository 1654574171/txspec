// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares methods for ComplianceEngine launching up.

#pragma once

#include <map>
#include <iostream>
#include <string>
#include <stdio.h>
#include <mutex>
#include <memory>

#include "compliance_engine_server/request_processor/RegulatorServer.h"
#include "sgx_urts.h"
#include "common/data_types/EnclaveId.h"
#include <http_client/HttpClient.h>
#include <yaml-cpp/yaml.h>
#include "Config.h"

// EngineStatus is used to express status of complianceEngine launching up
enum class EngineStatus
{
    kOK = 0,
    kEnclaveLoadError,
    kLocalAttestationError,
    kHttpClientError,
    kGRPCServerError,
    kPeerClientError,
    kConfigReadError,
    kInitLoggerError,
};

// #define KEY_MANAGEMENT_ENCLAVE_FILENAME "key_management_enclave.signed.so"
// #define RULE_ENCLAVE_FILENAME "rule_enclave.signed.so"
// #define BINDING_ENCLAVE_FILENAME "binding_enclave.signed.so"

// map from enclave id to enclave index (used for ocall forward)
extern std::map<sgx_enclave_id_t, SubModule> g_enclave_id_map;
extern std::unique_ptr<HttpClient> httpClient;

class ComplianceEngine
{
    public:
        // SGX related
        uint32_t LoadEnclaves();
        uint32_t StartLocalAttesttion();

        // grpc server
        uint32_t LaunchGRPCServer();

        // http client
        uint32_t LaunchHttpClient();

        // Logout helper functions
        uint32_t SafeLogout();

    private:
        RegulatorServer server;
        sgx_enclave_id_t g_key_management_enclave_id;
        sgx_enclave_id_t g_rule_enclave_id;
        sgx_enclave_id_t g_binding_enclave_id;

        // wrapper function for create local attestation
        uint32_t BindingCreateSession (sgx_enclave_id_t dest_enclave_id);
        uint32_t KeyManagementCreateSession (sgx_enclave_id_t dest_enclave_id);
        uint32_t RuleCreateSession (sgx_enclave_id_t dest_enclave_id);

        // for debug
        std::map<sgx_enclave_id_t, std::string> enclaveIDDebugString;
        void ReportCreateSessionError (sgx_enclave_id_t source_enclave_id,
                                       sgx_enclave_id_t dest_enclave_id,
                                       uint32_t status, uint32_t ret_status);
};
