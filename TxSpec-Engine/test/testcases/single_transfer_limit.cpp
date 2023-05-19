#include "single_transfer_limit.h"
#include <string>
#include <regex>

using namespace json11;
using namespace std;
// data of binding
string TestContractName0 = "TestContract0";
string TestContractBindingContent0 =
    R"(rules{ transfer -> [TestRule0.single_transfer_limit]; approve -> [TestRule0.single_transfer_limit];})";

// data of rules
string TestRuleName0 = "TestRule0";
string TestRuleContent0 =
    R"(regulation erc20 entities { entity transfer {  originator  sender  receiver  value is number } } rules {rule single_transfer_limit { 0 < transfer.value <= 20000 }})";

// data of transfers
Transfer single_transfer_limit_succ_1{
    "0x307831303030" /*hash*/, "TestContract0" /*contract_address*/,
    "0x0" /*sender*/,   "0x1" /*receiver*/,
    2000 /*value*/,     2000 /*timestamp*/};

Transfer single_transfer_limit_fail_1{
    "0x307832303030" /*hash*/, "TestContract0" /*contract_address*/,
    "0x0" /*sender*/,   "0x1" /*receiver*/,
    30000 /*value*/,     3000 /*timestamp*/};

void mockProofRequest_succ1(request_proto::ProofRequest* request) {
    request->set_txhash("0x1000");

    request_proto::Data* data = new request_proto::Data();
    request_proto::ContractEvent* contractEvent = data->add_events();
    contractEvent->set_contractid("TestContract0");
    request_proto::Event* event = contractEvent->add_events();
    event->set_eventname("transfer");
    request->set_allocated_data(data);
}

void mockProofRequest_fail1(request_proto::ProofRequest* request) {
    request->set_txhash("0x2000");

    request_proto::Data* data = new request_proto::Data();
    request_proto::ContractEvent* contractEvent = data->add_events();
    contractEvent->set_contractid("TestContract0");
    request_proto::Event* event = contractEvent->add_events();
    event->set_eventname("transfer");
    request->set_allocated_data(data);
}

void InitMockDataBase0(MockDatabase& mockDatabase) {
    // mockDatabase.setSubgraphName(TestContractName0);
    mockDatabase.insertBinding(TestContractName0, TestContractBindingContent0);
    mockDatabase.insertRule(TestRuleName0, TestRuleContent0);
    mockDatabase.insertTransferItem(&single_transfer_limit_fail_1);
    mockDatabase.insertTransferItem(&single_transfer_limit_succ_1);
}

std::string MockDatabase_single_transfer_limit::handleQuery(std::string& query, std::string& target){
    if (target.compare("TestContract0") == 0) 
        return handleTestContract0Query(query);
    
    if (target.compare("system") == 0)
        return MockDatabase::handleSystemQuery(query);

    return "";
}

bool MockDatabase_single_transfer_limit::matchDatabase (std::string& target) {
    if (target.compare("TestContract0") == 0)
        return true;
    if (target.compare("system") == 0)
        return true;
    return false;
}


std::string MockDatabase_single_transfer_limit::handleTestContract0Query(std::string& query) {
    smatch m;
    if (regex_search(query, m, regex(R"-(hash:\\"(.*)\\")-"))) {
        string hash = m[1].str();
        Transfer* t = GetTransferByHash(hash);
        Json::object value {
            {"value", to_string(t->value)}
        };
        Json::object transfers {
           { "transfers", Json::array{value}}
        };
        Json::object data {
            {"data", Json::object{transfers}}
        };
        Json result = data;
        return result.dump();
    }
    return "";
}



