#pragma once
#include <common/json_lib/json11.hpp>
#include <BindingQuery.pb.h>

class BindingQuery {

    private:
        const uint32_t maxSize = 8192U;
    
    public:
        request_proto::BindingQueryMessage bindingQuery;
        request_proto::BindingQueryMessage bindingResult;

    public:
        void initBindingQuery (const char* queryRequestString);
        bool queryBindingString (char* queryResult);

        std::string handleQueryResult(json11::Json& queryResult);
        char* generateBindingQueryContent(const std::string& contractId);
};