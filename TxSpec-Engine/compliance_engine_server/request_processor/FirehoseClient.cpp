#include "FirehoseClient.h"
#include <spdlog/spdlog.h>

bool FirehoseClient::routeBlockData(const reg_tx_collector::Request& request) {
    reg_tx_collector::Reply reply;

    grpc::ClientContext context;
    grpc::Status status = stub_->SendRegTx(&context, request, &reply);

    if (!status.ok()) {
        SPDLOG_INFO("Error! communication failed!");
        return false;
    }

    if (reply.code() != 0) {
        SPDLOG_INFO("Error! error code: {} \n error message: {}", reply.code(), reply.message());
        return false;
    }

    return true;
}