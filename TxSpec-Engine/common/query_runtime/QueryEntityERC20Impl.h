#pragma once

#include "QueryEntity.h"

class QueryEntityERC20Impl : public QueryEntity
{
public:
    std::string QueryEntityString(request_proto::TransactionInfo *tx);
};