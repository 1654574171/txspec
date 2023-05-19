
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include "common/base64/Transform.h"

#include "RegulatorServiceImpl.h"
#include "Queue.h"
#include "FirehoseClient.h"
#include "compliance_engine_server/Config.h"
#include <spdlog/spdlog.h>
#include <google/protobuf/util/json_util.h>

static const unsigned long kMaxOutSize = 8192UL;

using namespace std;

static string EmitJsonString (const google::protobuf::Message& message) {
    string jsonString;
    google::protobuf::util::MessageToJsonString(message, &jsonString);
    return jsonString;
}

REQUESTPROCESSOR_ERROR_CODE RegulatorServiceImpl::ProofRequestProcess(
    const request_proto::ProofRequest& request,
    request_proto::ProofResponse* response) {

    string requestString = request.SerializeAsString();
    string requestEncodedString = EncodeFromStringToString(requestString);

    BINDING_ERROR_CODE errorCode;
    char* responseBuffer = (char*) malloc(kMaxOutSize);
#ifdef USE_ENCLAVE_PREFIX
    BindingEnclave_ecall_process_proof_request(this->eid, &errorCode, requestEncodedString.c_str(), kMaxOutSize, responseBuffer, kMaxOutSize);
#else
    ecall_process_proof_request(this->eid, &errorCode, requestEncodedString.c_str(), kMaxOutSize, responseBuffer, kMaxOutSize);
#endif
    SPDLOG_INFO("return to untrsted zoom");
    string responseString = DecodeFromCharToString(responseBuffer);
    response->ParseFromString(responseString);

    SPDLOG_INFO("Receive proof response {}", responseString);
    return kRPSUCCESS;

}



// GetComplianceProof receives compliance request from RegChain system,
// parses the transaction and processes comliance.
// Finally, returns the compliance proof about transaction to RegChain system.
grpc::Status RegulatorServiceImpl::GetComplianceProof(
    ::grpc::ServerContext *context,
    grpc::ServerReaderWriter<::request_proto::ProofResponse, ::request_proto::ProofRequest> *stream)
{
    Queue<request_proto::ProofRequest> inputQueue(10000);
    Queue<request_proto::ProofResponse> outputQueue(10000);

    string configfirehoseAddress;
    try
    {
        configfirehoseAddress = config["firehose"]["FIREHOSE_ADDRESS"].as<string>();
    }
    catch (YAML::TypedBadConversion<string> &e)
    {
        SPDLOG_INFO("firehose:FIREHOSE_ADDRESS is NULL, use default value: localhost:50052");
        configfirehoseAddress = this->firehoseAddress;
    }
    FirehoseClient firehoseClient(grpc::CreateChannel(configfirehoseAddress, grpc::InsecureChannelCredentials()));    std::mutex mtx_streamWrite;

    int32_t processThreadPoolSize;
    try
    {
        processThreadPoolSize = config["requestprocessor"]["THREAD_POOL_SIZE"].as<int32_t>();
    }
    catch (YAML::TypedBadConversion<int32_t> &e)
    {
        SPDLOG_INFO("requestprocessor:THREAD_POOL_SIZE is NULL, use default value: 3");
        processThreadPoolSize = 5;
    }

    SPDLOG_INFO("start check compliance request");

    auto ReadReq = [&]() {
        request_proto::ProofRequest proofRequest;
        SPDLOG_INFO("start read request");
        while (stream->Read(&proofRequest)) {
            SPDLOG_INFO("read request {}", proofRequest.txhash());
            inputQueue.push(proofRequest);
        }
    };

    auto WriteRes = [&]() {
        request_proto::ProofResponse proofResponse;
        int i = 0;
        while (outputQueue.pop(proofResponse)) {
            stream->Write(proofResponse);
            i++; 
        }
    };

    auto RunReqGetRes = [&]() {
        auto threadID = std::this_thread::get_id();
        stringstream ss;
        ss << threadID;
        string idstr = ss.str();

        while (1) {
            request_proto::ProofRequest proofRequest;
            inputQueue.pop(proofRequest);
            // call ecall_process_request to get the response
            request_proto::ProofResponse proofResponse;

            reg_tx_collector::Request request;
            request.set_id("0");
            request.set_block(proofRequest.originaldata());
            if (!firehoseClient.routeBlockData(request)) {
                SPDLOG_INFO("route block to firehose faild! ");
                outputQueue.push(proofResponse);
                continue;
            }

            SPDLOG_INFO("handle request: \n {}", EmitJsonString(proofRequest));
            this->ProofRequestProcess(proofRequest, &proofResponse);
            SPDLOG_INFO("get response: \n {}", EmitJsonString(proofResponse));
            outputQueue.push(proofResponse);
        }
    };

    std::vector<thread> thread_pool;
    thread_pool.push_back(thread(ReadReq));
    thread_pool.push_back(thread(WriteRes));

    for (int i = 0; i < processThreadPoolSize; i++) {
        thread_pool.push_back(thread(RunReqGetRes));
    }
    
    for (auto &t: thread_pool) {
        t.join();
    }

    return grpc::Status::OK;
}