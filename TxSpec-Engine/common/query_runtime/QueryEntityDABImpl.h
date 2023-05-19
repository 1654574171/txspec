#pragma once

#include "QueryEntity.h"
#include "json11.hpp"
#include "utils.h"

class QueryEntityDABImpl : public QueryEntity
{
public:
    std::string QueryEntityString(request_proto::TransactionInfo *tx);
};