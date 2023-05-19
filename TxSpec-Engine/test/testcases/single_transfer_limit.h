#pragma once
#include "schema/transfer_schema.h"

class MockDatabase_single_transfer_limit : public MockDatabase {
    // function override by Database
    bool matchDatabase (std::string& target) override;
    std::string handleQuery(std::string& query, std::string& target) override;

    std::string handleTestContract0Query(std::string& query);
};

void InitMockDataBase0(MockDatabase& mockDatabase);
void mockProofRequest_succ1(request_proto::ProofRequest* request);
void mockProofRequest_fail1(request_proto::ProofRequest* request);