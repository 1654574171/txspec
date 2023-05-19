#pragma once
#include <grpcpp/grpcpp.h>

#include "Firehose.grpc.pb.h"
#include "Firehose.pb.h"

class FirehoseClient {

    private:
        std::unique_ptr<reg_tx_collector::TxCollectorService::Stub> stub_;

    public:
        FirehoseClient(std::shared_ptr<grpc::Channel> channel)
                : stub_(reg_tx_collector::TxCollectorService::NewStub(channel)) {}
        
        bool routeBlockData(const reg_tx_collector::Request& request);
};