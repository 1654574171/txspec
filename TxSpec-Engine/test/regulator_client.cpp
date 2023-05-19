#include <grpcpp/grpcpp.h>
#include <gtest/gtest.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include "ProofRequest.pb.h"
#include "ProofResponse.pb.h"
#include "Regulator.grpc.pb.h"
#include "Regulator.pb.h"

#include "basic_server/firehose_server.hpp"
#include "basic_server/http_server.h"
#include "basic_server/database.h"

#include "testcases/single_transfer_limit.h"
#include "testcases/period_transfer_limit.h"
#include "testcases/list.h"

#include "testcases/nft_transfer.h"

using namespace std;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;


// helper function used to start mocked firehose server
void RunFirehoseServer(FirehoseTestServer& server) {
    server.RunServer();
    return;
}

// helper function used to start mocked graphnode server
void RunGraphnodeServer(GraphNodeTestServer& server) {
    server.RunServer();
    return;
}

// database used by http connection to mock graphql query result
Database* testdatabase;

class RegulatorClientTest : public ::testing::Test {
   protected:
    static void SetUpTestSuite() {
        firehose_server_thread = std::thread(RunFirehoseServer, std::ref(firehose_server));
        graphnode_server_thread = std::thread(RunGraphnodeServer, std::ref(graphnode_server));
    }

    static void TearDownTestSuite() {
        firehose_server.ShutDownServer();
        graphnode_server.ShutDownServer();
        firehose_server_thread.join();
        graphnode_server_thread.join();
    }

    void SetUp() {
        string target_str = "localhost:50051";
        shared_ptr<Channel> channel =
            grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials());
        stub_ = request_proto::Regulator::NewStub(channel);
        
        std::shared_ptr<grpc::ClientReaderWriter<request_proto::ProofRequest,
                                             request_proto::ProofResponse>>
        stream_(stub_->GetComplianceProof(&context));
        stream = stream_;
    }

    // testcase resource: grpc stream
    std::unique_ptr<request_proto::Regulator::Stub> stub_;
    ClientContext context;
    std::shared_ptr<grpc::ClientReaderWriter<request_proto::ProofRequest,
                                             request_proto::ProofResponse>> stream;

    // testsuite resources : thread and server
    static std::thread firehose_server_thread;
    static FirehoseTestServer firehose_server;
    static std::thread graphnode_server_thread;
    static GraphNodeTestServer graphnode_server;
};

// definition of testsuite resource
std::thread RegulatorClientTest::firehose_server_thread;
FirehoseTestServer RegulatorClientTest::firehose_server;
std::thread RegulatorClientTest::graphnode_server_thread;
GraphNodeTestServer RegulatorClientTest::graphnode_server;

// TEST_F(RegulatorClientTest, RegulatorSucc1) {

//     // registe your own database
//     MockDatabase* database_ = new MockDatabase_single_transfer_limit();
//     InitMockDataBase0(*database_);
//     testdatabase = database_;

//     // generate test request and send
//     request_proto::ProofRequest request;
//     mockProofRequest_succ1(&request);
//     EXPECT_TRUE(stream->Write(request));
//     while (!stream->WritesDone()) {
//         sleep(1);
//     }

//     // receive response and check
//     request_proto::ProofResponse response;
//     EXPECT_TRUE(stream->Read(&response));
//     EXPECT_EQ(response.proofs_size(), 1);

//     const request_proto::Proof& proof = response.proofs(0);
//     EXPECT_TRUE(proof.status());
//     EXPECT_EQ(proof.receipts_size(), 1);

//     const request_proto::Receipt& receipt = proof.receipts(0);
//     EXPECT_TRUE(receipt.status());
//     EXPECT_EQ(receipt.contractid(), string("TestContract0"));
//     EXPECT_EQ(receipt.errorinfo_size(), 1);

//     const request_proto::ErrorInfo& info = receipt.errorinfo(0);
//     EXPECT_TRUE(info.status());
//     EXPECT_EQ(info.rulefilename(), string("TestRule0"));
//     EXPECT_EQ(info.rulefileid(), string("single_transfer_limit"));

//     // clean up
//     delete(testdatabase);
//     testdatabase = nullptr;
// }

// TEST_F(RegulatorClientTest, RegulatorFail1) {

//     // registe your own database
//     MockDatabase* database_ = new MockDatabase_single_transfer_limit();
//     InitMockDataBase0(*database_);
//     testdatabase = database_;

//     // generate test request and send
//     request_proto::ProofRequest request;
//     mockProofRequest_fail1(&request);
//     EXPECT_TRUE(stream->Write(request));
//     while (!stream->WritesDone()) {
//         sleep(1);
//     }

//     // receive response and check
//     request_proto::ProofResponse response;
//     EXPECT_TRUE(stream->Read(&response));
//     EXPECT_EQ(response.proofs_size(), 1);

//     const request_proto::Proof& proof = response.proofs(0);
//     EXPECT_FALSE(proof.status());
//     EXPECT_EQ(proof.receipts_size(), 1);

//     const request_proto::Receipt& receipt = proof.receipts(0);
//     EXPECT_FALSE(receipt.status());
//     EXPECT_EQ(receipt.contractid(), string("TestContract0"));
//     EXPECT_EQ(receipt.errorinfo_size(), 1);

//     const request_proto::ErrorInfo& info = receipt.errorinfo(0);
//     EXPECT_FALSE(info.status());
//     EXPECT_EQ(info.rulefilename(), string("TestRule0"));
//     EXPECT_EQ(info.rulefileid(), string("single_transfer_limit"));

//     // clean up
//     delete(testdatabase);
//     testdatabase = nullptr;
// }

// TEST_F(RegulatorClientTest, RegulatorPeriodSucc1) {

//     // registe your own database
//     MockDatabase* database_ = new MockDatabase_period_transfer_limit();
//     InitMockDataBase1(*database_);
//     testdatabase = database_;

//     // generate test request and send
//     request_proto::ProofRequest request;
//     mockProofRequest_period_transfer_limit_succ1(&request);
//     EXPECT_TRUE(stream->Write(request));
//     while (!stream->WritesDone()) {
//         sleep(1);
//     }

//     // receive response and check
//     request_proto::ProofResponse response;
//     EXPECT_TRUE(stream->Read(&response));
//     EXPECT_EQ(response.proofs_size(), 1);

//     const request_proto::Proof& proof = response.proofs(0);
//     EXPECT_TRUE(proof.status());
//     EXPECT_EQ(proof.receipts_size(), 1);

//     const request_proto::Receipt& receipt = proof.receipts(0);
//     EXPECT_TRUE(receipt.status());
//     EXPECT_EQ(receipt.contractid(), string("TestContract1"));
//     EXPECT_EQ(receipt.errorinfo_size(), 1);

//     const request_proto::ErrorInfo& info = receipt.errorinfo(0);
//     EXPECT_TRUE(info.status());
//     EXPECT_EQ(info.rulefilename(), string("TestRule1"));
//     EXPECT_EQ(info.rulefileid(), string("period_transfer_limit"));

//     // clean up
//     delete(testdatabase);
//     testdatabase = nullptr;
// }

// TEST_F(RegulatorClientTest, RegulatorPeriodFail1) {

//     // registe your own database
//     MockDatabase* database_ = new MockDatabase_period_transfer_limit();
//     InitMockDataBase1(*database_);
//     testdatabase = database_;

//     // generate test request and send
//     request_proto::ProofRequest request;
//     mockProofRequest_period_transfer_limit_fail1(&request);
//     EXPECT_TRUE(stream->Write(request));
//     while (!stream->WritesDone()) {
//         sleep(1);
//     }

//     // receive response and check
//     request_proto::ProofResponse response;
//     EXPECT_TRUE(stream->Read(&response));
//     EXPECT_EQ(response.proofs_size(), 1);

//     const request_proto::Proof& proof = response.proofs(0);
//     EXPECT_FALSE(proof.status());
//     EXPECT_EQ(proof.receipts_size(), 1);

//     const request_proto::Receipt& receipt = proof.receipts(0);
//     EXPECT_FALSE(receipt.status());
//     EXPECT_EQ(receipt.contractid(), string("TestContract1"));
//     EXPECT_EQ(receipt.errorinfo_size(), 1);

//     const request_proto::ErrorInfo& info = receipt.errorinfo(0);
//     EXPECT_FALSE(info.status());
//     EXPECT_EQ(info.rulefilename(), string("TestRule1"));
//     EXPECT_EQ(info.rulefileid(), string("period_transfer_limit"));

//     // clean up
//     delete(testdatabase);
//     testdatabase = nullptr;
// }


// TEST_F(RegulatorClientTest, RegulatorListSucc1) {

//     // registe your own database
//     MockDatabase* database_ = new MockDatabase_list();
//     InitMockDataBase_List0(*database_);
//     testdatabase = database_;

//     // generate test request and send
//     request_proto::ProofRequest request;
//     mockProofRequest_List_succ1(&request);
//     EXPECT_TRUE(stream->Write(request));
//     while (!stream->WritesDone()) {
//         sleep(1);
//     }

//     // receive response and check
//     request_proto::ProofResponse response;
//     EXPECT_TRUE(stream->Read(&response));
//     EXPECT_EQ(response.proofs_size(), 1);

//     const request_proto::Proof& proof = response.proofs(0);
//     EXPECT_TRUE(proof.status());
//     EXPECT_EQ(proof.receipts_size(), 1);

//     const request_proto::Receipt& receipt = proof.receipts(0);
//     EXPECT_TRUE(receipt.status());
//     EXPECT_EQ(receipt.contractid(), string("TestContractList"));
//     EXPECT_EQ(receipt.errorinfo_size(), 1);

//     const request_proto::ErrorInfo& info = receipt.errorinfo(0);
//     EXPECT_TRUE(info.status());
//     EXPECT_EQ(info.rulefilename(), string("TestListRule"));
//     EXPECT_EQ(info.rulefileid(), string("white_list"));

//     // clean up
//     delete(testdatabase);
//     testdatabase = nullptr;
// }

// TEST_F(RegulatorClientTest, RegulatorListFail1) {

//     // registe your own database
//     MockDatabase* database_ = new MockDatabase_list();
//     InitMockDataBase_List0(*database_);
//     testdatabase = database_;

//     // generate test request and send
//     request_proto::ProofRequest request;
//     mockProofRequest_List_fail1(&request);
//     EXPECT_TRUE(stream->Write(request));
//     while (!stream->WritesDone()) {
//         sleep(1);
//     }

//     // receive response and check
//     request_proto::ProofResponse response;
//     EXPECT_TRUE(stream->Read(&response));
//     EXPECT_EQ(response.proofs_size(), 1);

//     const request_proto::Proof& proof = response.proofs(0);
//     EXPECT_FALSE(proof.status());
//     EXPECT_EQ(proof.receipts_size(), 1);

//     const request_proto::Receipt& receipt = proof.receipts(0);
//     EXPECT_FALSE(receipt.status());
//     EXPECT_EQ(receipt.contractid(), string("TestContractList"));
//     EXPECT_EQ(receipt.errorinfo_size(), 1);

//     const request_proto::ErrorInfo& info = receipt.errorinfo(0);
//     EXPECT_FALSE(info.status());
//     EXPECT_EQ(info.rulefilename(), string("TestListRule"));
//     EXPECT_EQ(info.rulefileid(), string("white_list"));

//     // clean up
//     delete(testdatabase);
//     testdatabase = nullptr;
// }


TEST_F(RegulatorClientTest, NFTListFail1) {

    // registe your own database
    MockDatabase_NFT* database_ = new MockDatabase_NFTlist();
    InitMockDataBase_NFTList0(*database_);
    testdatabase = database_;

    // generate test request and send
    request_proto::ProofRequest request;
    mockProofRequest_NFTList_fail1(&request);
    EXPECT_TRUE(stream->Write(request));
    while (!stream->WritesDone()) {
        sleep(1);
    }

    // receive response and check
    request_proto::ProofResponse response;
    EXPECT_TRUE(stream->Read(&response));
    EXPECT_EQ(response.proofs_size(), 1);

    const request_proto::Proof& proof = response.proofs(0);
    EXPECT_FALSE(proof.status());
    EXPECT_EQ(proof.receipts_size(), 1);

    const request_proto::Receipt& receipt = proof.receipts(0);
    EXPECT_FALSE(receipt.status());
    EXPECT_EQ(receipt.contractid(), string("TestNFTList"));
    EXPECT_EQ(receipt.errorinfo_size(), 1);

    const request_proto::ErrorInfo& info = receipt.errorinfo(0);
    EXPECT_FALSE(info.status());
    EXPECT_EQ(info.rulefilename(), string("TestNFTListRule"));
    EXPECT_EQ(info.rulefileid(), string("nft_white_list"));

    // clean up
    delete(testdatabase);
    testdatabase = nullptr;
}