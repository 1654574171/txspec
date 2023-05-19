#pragma once

#include <string>
#include <iostream>
#include "request_proto/Compliance.pb.h"
// #include "common/utils/third_party/spdlog-1.4.2/include/spdlog/spdlog.h"

class QueryEntity
{
public:
    virtual std::string QueryEntityString(request_proto::TransactionInfo *tx);
};