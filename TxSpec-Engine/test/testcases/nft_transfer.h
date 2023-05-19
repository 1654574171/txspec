#pragma once
#include "schema/nft_schema.h"

class MockDatabase_NFTlist : public MockDatabase_NFT {
    // function override by Database
    bool matchDatabase (std::string& target) override;
    std::string handleQuery(std::string& query, std::string& target) override;

    std::string handleContractQuery(std::string& query);
};

void InitMockDataBase_NFTList0(MockDatabase_NFT& mockDatabase);
void mockProofRequest_NFTList_succ1(request_proto::ProofRequest* request);
void mockProofRequest_NFTList_fail1(request_proto::ProofRequest* request);