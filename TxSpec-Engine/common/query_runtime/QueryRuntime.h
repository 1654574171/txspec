#pragma once

#include <map>

#include "request_proto/Compliance.pb.h" //maybe trusted or untrusted, according to includepath
// #include "common/utils/third_party/spdlog-1.4.2/include/spdlog/spdlog.h"
#include "QueryEntityERC20Impl.h"
#include "QueryEntityDABImpl.h"

class QueryRuntime
{
public:
    enum class QueryType
    {
        ERC20 = 1,
        ERC721 = 2,
        DAB = 3
    };

    std::map<QueryType, QueryEntity *> queryers;

    QueryRuntime();

    std::string QueryEntityWithType(QueryType qType, request_proto::TransactionInfo *tx);
};