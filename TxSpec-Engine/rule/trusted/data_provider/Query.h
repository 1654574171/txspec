#pragma once

#include <string>
#include <vector>
#include "RuleEnclave_t.h"
#include "common/json_lib/json11.hpp"
#include "rule_enclave/EntityQuery.pb.h"
#include "trusted/data_provider/DataProvider.h"
#include "trusted/data_types/RequestContext.h"

#include "trusted/data_types/Entity.h"
#include "trusted/data_types/EntityRule.h"
#include "trusted/data_types/EntitySet.h"

class QueryBuilder {
   public:
    // Constructor of DataProvider
    QueryBuilder() = default;

    // Destructor of DataProvider
    ~QueryBuilder() = default;

    /******************************/
    std::string GenerateQueryString(const EntityRule& entity);
    std::string GenerateQueryString(EntitySet& entity, const RequestContext* context);
    std::string GenerateQueryString(const Entity& entity, const RequestContext* context);

    private:
    uint64_t handleWithinValue(uint64_t timestamp, const rule_check_proto::Within& within);
    uint64_t getTimestampValue(const RequestContext* context, const string& entity_name);
    void collectConstrainStrings(EntitySet& entity, const RequestContext* context, vector<string>& constraintStrs);
    void collectConstrainStrings(const Entity& entity, const RequestContext* context, vector<string>& constraintStrs);
    string concatenateQueryString (const EntityType&, const RequestContext* context, const vector<string>& constraintStrs);


    static const std::string QUERY_PREFIX;
    static const std::string QUERY_SUBFIX;
    static const std::string QUERY_CONSTRAINS_PREFIX;
    static const std::string QUERY_CONSTRAINS_SUBFIX;
    static const std::string QUERY_ATTRIBUTES_PREFIX;
    static const std::string QUERY_ATTRIBUTES_SUBFIX;
};
