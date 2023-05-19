#include "period_transfer_limit.h"
#include "schema/transfer_schema.h"

#include <string>
#include <regex>

using namespace json11;
using namespace std;

// data of binding
string TestContractName1 = "TestContract1";
string TestContractBindingContent1 =
    R"(rules{ transfer -> [TestRule1.period_transfer_limit]; approve -> [TestRule1.period_transfer_limit];})";

// data of rules
string TestRuleName1 = "TestRule1";
string TestRuleContent1 =
    R"(regulation erc20 entities { entity transfer {  originator  sender  receiver  value is number timestamp is number} } rules {rule period_transfer_limit { count on transfer provided transfer.receiver within 7 days <= 10 accumulate transfer.value on transfer within 1 day <= 200000 }})";

Transfer period_transfer_limit_succ_0{
    "0x307831303030" /*hash*/, "TestContract1" /*contract_address*/,
    "0x0" /*sender*/,   "0x1" /*receiver*/,
    2000 /*value*/,     604800000 /*timestamp*/};

Transfer period_transfer_limit_fail_0{
    "0x307832303030" /*hash*/, "TestContract1" /*contract_address*/,
    "0x0" /*sender*/,   "0x1" /*receiver*/,
    2000 /*value*/,     604800001 /*timestamp*/};

void InitMockDataBase1(MockDatabase& mockDatabase) {
    mockDatabase.insertBinding(TestContractName1, TestContractBindingContent1);
    mockDatabase.insertRule(TestRuleName1, TestRuleContent1);
    mockDatabase.insertTransferItem(&period_transfer_limit_succ_0);
    mockDatabase.insertTransferItem(&period_transfer_limit_fail_0);
}

void mockProofRequest_period_transfer_limit_succ1(request_proto::ProofRequest* request) {
    request->set_txhash("0x1000");
    

    request_proto::Data* data = new request_proto::Data();
    request_proto::ContractEvent* contractEvent = data->add_events();
    contractEvent->set_contractid("TestContract1");
    request_proto::Event* event = contractEvent->add_events();
    event->set_eventname("transfer");
    request->set_allocated_data(data);

    request_proto::TxMetaData* meta = new request_proto::TxMetaData();
    meta->set_fromaddress("0x0");
    meta->set_toaddress("0x1");
    data->set_allocated_meta(meta);
}

void mockProofRequest_period_transfer_limit_fail1(request_proto::ProofRequest* request) {
    request->set_txhash("0x2000");

    request_proto::Data* data = new request_proto::Data();
    request_proto::ContractEvent* contractEvent = data->add_events();
    contractEvent->set_contractid("TestContract1");
    request_proto::Event* event = contractEvent->add_events();
    event->set_eventname("transfer");
    request->set_allocated_data(data);

    request_proto::TxMetaData* meta = new request_proto::TxMetaData();
    meta->set_fromaddress("0x1");
    meta->set_toaddress("0x0");
    data->set_allocated_meta(meta);
}


std::string MockDatabase_period_transfer_limit::handleQuery(std::string& query, std::string& target){

    if (target.compare("TestContract1") == 0) 
        return handleTestContract1Query(query);
    
    if (target.compare("system") == 0)
        return MockDatabase::handleSystemQuery(query);

    return "";
}

bool MockDatabase_period_transfer_limit::matchDatabase (std::string& target) {
     if (target.compare("TestContract1") == 0)
        return true;
    if (target.compare("system") == 0)
        return true;
    return false;
}

std::string MockDatabase_period_transfer_limit::handleTestContract1Query(std::string& query) {
    smatch m;
    if (regex_search(query, m, regex(R"-(hash:\\"(.*)\\")-"))) {
        string hash = m[1].str();
        Transfer* t = GetTransferByHash(hash);
        Json::object value {
            {"value", to_string(t->value)},
            {"originator", t->sender},
            {"receiver", t->receiver},
            {"timestamp", to_string(t->timestamp)}
        };
        Json::object transfers {
           { "transfers", Json::array{value}}
        };
        Json::object data {
            {"data", Json::object{transfers}}
        };
        Json result = data;
        return result.dump();
    } else if (regex_search(query, m, regex("timestamp_gt:0|timestamp_gt:518400000"))) {
        Json::object value {
            {"value", to_string(1)},
            {"originator", "0x1"},
            {"receiver", "0x0"},
            {"timestamp", to_string(0)}
        };
        Json::object transfers {
           { "transfers", Json::array{value}}
        };
        Json::object data {
            {"data", Json::object{transfers}}
        };
        Json result = data;
        return result.dump();
    } else if (regex_search(query, m, regex("timestamp_gt:1|timestamp_gt:518400001"))) {
        Json::array array;
        for (int i = 0; i < 11; i++) {
            Json::object value {
                {"value", to_string(200000)},
                {"originator", "0x1"},
                {"receiver", "0x0"},
                {"timestamp", to_string(0)}
            };
            array.push_back(value);
        }
        Json::object transfers {
           { "transfers", Json::array(array)}
        };
        Json::object data {
            {"data", Json::object{transfers}}
        };
        Json result = data;
        return result.dump();
    }
    return "";
}


