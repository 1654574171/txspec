#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include <iostream>
#include <memory>
#include <string>

#include "Firehose.grpc.pb.h"
#include "Firehose.pb.h"

using grpc::Status;

class  TxCollectorServiceImpl final : public reg_tx_collector::TxCollectorService::Service
{
    private:
    virtual grpc::Status SendRegTx(::grpc::ServerContext* context, 
                                   const reg_tx_collector::Request* request, 
                                   reg_tx_collector::Reply* response) override {
                                    response->set_code(0);
                                    response->set_message("ok");
                                    return Status::OK;
                                   }
};

class FirehoseTestServer {
public:
    void RunServer () {
        grpc::ServerBuilder builder;
        TxCollectorServiceImpl txCollector;

        grpc::reflection::InitProtoReflectionServerBuilderPlugin();

        // Listen on the given address without any authentication mechanism.
        builder.AddListeningPort("127.0.0.1:50052", grpc::InsecureServerCredentials());
        builder.RegisterService(&txCollector);
        server = move(builder.BuildAndStart());
        server->Wait();
    }

    void ShutDownServer() {
        server->Shutdown();
    }

private:
    std::unique_ptr<grpc::Server> server;
};

