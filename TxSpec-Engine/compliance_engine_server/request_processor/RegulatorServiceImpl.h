#pragma once

#include <iostream>
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>

#include <sgx_error.h>
#include <BindingEnclave_u.h>
#include "common/data_types/request_processor/ErrorType.h"

#include <ProofRequest.pb.h>
#include <ProofResponse.pb.h>
#include <Regulator.pb.h>
#include <Regulator.grpc.pb.h>

class  RegulatorServiceImpl final : public request_proto::Regulator::Service
{

    private:
        sgx_enclave_id_t eid;
        std::string firehoseAddress;

    private:
    // Example of usage:
    // Params: context: the grpc connetion context between client and server;
    //         ProofRequest: the compliance request contains transaction information.
    // Return: ProofResponse: the compliance response contains conpliance proof information.
    virtual grpc::Status GetComplianceProof(::grpc::ServerContext *context,
                                            grpc::ServerReaderWriter<::request_proto::ProofResponse, ::request_proto::ProofRequest> *stream) override;

    REQUESTPROCESSOR_ERROR_CODE ProofRequestProcess(const request_proto::ProofRequest& request, request_proto::ProofResponse* response);
    
    public:
        RegulatorServiceImpl(sgx_enclave_id_t g_binding_enclave_id, std::string address) : eid(g_binding_enclave_id), firehoseAddress(address) {}
        RegulatorServiceImpl(sgx_enclave_id_t g_binding_enclave_id) : eid(g_binding_enclave_id), firehoseAddress("localhost:50052") {}

};