#pragma once
#include "schema/transfer_schema.h"

class MockDatabase_list : public MockDatabase {
    // function override by Database
    bool matchDatabase (std::string& target) override;
    std::string handleQuery(std::string& query, std::string& target) override;

    std::string handleTestContractListQuery(std::string& query);
};

void InitMockDataBase_List0(MockDatabase& mockDatabase);
void mockProofRequest_List_succ1(request_proto::ProofRequest* request);
void mockProofRequest_List_fail1(request_proto::ProofRequest* request);