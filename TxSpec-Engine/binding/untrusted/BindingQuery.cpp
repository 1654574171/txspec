
#include <string>
#include "BindingQuery.h"
#include <common/base64/Transform.h>
#include <spdlog/spdlog.h>
#include <http_client/HttpClient.h>

using namespace std;


void BindingQuery::initBindingQuery (const char* queryRequest) {
    string queryRequestString = DecodeFromStringToString(queryRequest);
    this->bindingQuery.ParseFromString(queryRequestString);
}

char* BindingQuery::generateBindingQueryContent(const std::string& contractId) {
    char* buffer = (char*)malloc(this->maxSize);
    int size = snprintf(buffer, this->maxSize, 
                        "{\"query\":\"{relations(where:{contract_address:\\\"%s\\\"}){binding{content}}}\"}", contractId.c_str());
    if (size < 0) {
        SPDLOG_ERROR("generate binding query failed!");
        return nullptr;
    }
    return buffer;
}

string BindingQuery::handleQueryResult(json11::Json& queryResult) {
        
    string bindingString;
    if (queryResult.is_null()) {
        SPDLOG_ERROR("query binding string failed!");
        return bindingString;
    }

    // check the validation of query result

    if (queryResult["data"]["relations"].array_items().size() > 1) {
        SPDLOG_ERROR("There are more than one binding!");
        SPDLOG_INFO(queryResult.dump());
        return bindingString;
    }

    if (queryResult["data"]["relations"][0]["binding"]["content"].is_null()) {
        SPDLOG_ERROR("Invalid query result!");
        SPDLOG_INFO(queryResult.dump());
        return bindingString;
    }

    bindingString = queryResult["data"]["relations"][0]["binding"]["content"].string_value();
        
    SPDLOG_INFO("Get Binding String {}", bindingString);
    return bindingString; 
}

bool BindingQuery::queryBindingString (char* result) {
    
    for (int i = 0; i < this->bindingQuery.items_size(); i++) {
        
        request_proto::BindingQueryItem * resultItem = this->bindingResult.add_items();
        const string& contractId = bindingQuery.items(i).contractid();
        resultItem->set_contractid(contractId);
        
        SPDLOG_INFO("query binding string by using contractid");
        char* queryBindingSentence = generateBindingQueryContent(contractId);
        json11::Json queryResult = httpClient->query(queryBindingSentence, "regchain-system-subgraph");
        string bindingString = handleQueryResult(queryResult);

        int times = 5;
        while (bindingString.empty() && times >= 0) {
            SPDLOG_INFO("retry query binding times {}", times);
            json11::Json queryResult = httpClient->query(queryBindingSentence, "regchain-system-subgraph");
            string bindingString = handleQueryResult(queryResult);
            times--;
        }

        resultItem->set_contractbinding(bindingString);
    }

    // serialize and write to query result 
    string queryResultString = this->bindingResult.SerializeAsString();
    string encodedQueryResult = EncodeFromStringToString(queryResultString);
    SPDLOG_INFO("Original string {}. encoded string {}", queryResultString, encodedQueryResult);
    memcpy(result, encodedQueryResult.c_str(), encodedQueryResult.length() + 1);
    SPDLOG_INFO("return result data is {}", result);
    return true;
}
