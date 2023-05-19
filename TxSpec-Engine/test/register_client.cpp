// #include "time.h"
// #include <iostream>
#include <memory>
// #include <string>
// #include <vector>
// #include <random>
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <gtest/gtest.h>
#include <thread>


#include "Register.grpc.pb.h"
#include "Register.pb.h"

using namespace std;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

void mockRegisterRequest (request_proto::RegisterRequest* request) {
    request->set_chaintype("cosmos-regchain");
    request->set_chainid("8500");
}


class RegisterTest : public ::testing::Test
{
    protected:
    void SetUp() override {
        string target_str = "localhost:50051";
        shared_ptr<Channel> channel =
            grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials());
        this->stub_ = request_proto::Register::NewStub(channel);
    }

    std::unique_ptr<request_proto::Register::Stub> stub_;
};



TEST_F(RegisterTest, RegisterSucc)
{
    request_proto::RegisterRequest* request = new request_proto::RegisterRequest();
    mockRegisterRequest(request);
    ClientContext context;
    request_proto::RegisterResponse response;
    Status status = stub_->RegisterRegulatoryService(&context, *request, &response);
    EXPECT_EQ(status.ok(), true);
    EXPECT_EQ(response.error_info().length(), 0);
}




