#pragma once
#include "schema/transfer_schema.h"

class MockDatabase_period_transfer_limit : public MockDatabase {
    // function override by Database
    bool matchDatabase (std::string& target) override;
    std::string handleQuery(std::string& query, std::string& target) override;
    std::string handleTestContract1Query(std::string& query);
};

void mockProofRequest_period_transfer_limit_succ1(request_proto::ProofRequest* request);
void mockProofRequest_period_transfer_limit_fail1(request_proto::ProofRequest* request);
void InitMockDataBase1(MockDatabase& mockDatabase);