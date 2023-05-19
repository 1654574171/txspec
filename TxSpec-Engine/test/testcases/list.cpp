#include "list.h"
#include <string>
#include <regex>

using namespace json11;
using namespace std;
// data of binding
string TestListContractName0 = "TestContractList";
string TestListContractBindingContent0 =
    R"(rules{ transfer -> [TestListRule.white_list];})";

// data of rules
string TestListRuleName0 = "TestListRule";
string TestListRuleContent0 =
    R"(regulation erc20 entities { entity transfer {  originator  sender  receiver  value is number } } rules {rule white_list { transfer.sender not in SuspiciousAccountList }})";

// data of transfers
Transfer white_list_succ_1{
    "0x307831303030" /*hash*/, TestListContractName0 /*contract_address*/,
    "0x0" /*sender*/,   "0x1" /*receiver*/,
    2000 /*value*/,     2000 /*timestamp*/};

Transfer white_list_fail_1{
    "0x307832303030" /*hash*/, TestListContractName0 /*contract_address*/,
    "0x1" /*sender*/,   "0x0" /*receiver*/,
    30000 /*value*/,     3000 /*timestamp*/};

void mockProofRequest_List_succ1(request_proto::ProofRequest* request) {
    request->set_txhash("0x1000");

    request_proto::Data* data = new request_proto::Data();
    request_proto::ContractEvent* contractEvent = data->add_events();
    contractEvent->set_contractid(TestListContractName0);
    request_proto::Event* event = contractEvent->add_events();
    event->set_eventname("transfer");
    request->set_allocated_data(data);
}

void mockProofRequest_List_fail1(request_proto::ProofRequest* request) {
    request->set_txhash("0x2000");

    request_proto::Data* data = new request_proto::Data();
    request_proto::ContractEvent* contractEvent = data->add_events();
    contractEvent->set_contractid(TestListContractName0);
    request_proto::Event* event = contractEvent->add_events();
    event->set_eventname("transfer");
    request->set_allocated_data(data);
}

void InitMockDataBase_List0(MockDatabase& mockDatabase) {
    mockDatabase.insertBinding(TestListContractName0, TestListContractBindingContent0);
    mockDatabase.insertRule(TestListRuleName0, TestListRuleContent0);
    mockDatabase.insertTransferItem(&white_list_succ_1);
    mockDatabase.insertTransferItem(&white_list_fail_1);
}

std::string MockDatabase_list::handleQuery(std::string& query, std::string& target){
    if (target.compare("TestContractList") == 0) 
        return handleTestContractListQuery(query);
    
    if (target.compare("system") == 0)
        return MockDatabase::handleSystemQuery(query);

    return "";
}

bool MockDatabase_list::matchDatabase (std::string& target) {
    if (target.compare("TestContractList") == 0)
        return true;
    if (target.compare("system") == 0)
        return true;
    return false;
}


std::string MockDatabase_list::handleTestContractListQuery(std::string& query) {
    smatch m;
    if (regex_search(query, m, regex(R"-(hash:\\"(.*)\\")-"))) {
        string hash = m[1].str();
        Transfer* t = GetTransferByHash(hash);
        Json::object value {
            {"sender", t->sender}
        };
        Json::object transfers {
           { "transfers", Json::array{value}}
        };
        Json::object data {
            {"data", Json::object{transfers}}
        };
        Json result = data;
        return result.dump();
    } else if (regex_search(query, m, regex(R"-(account:\\"0x0\\")-"))) {
        Json::object accounts {
           { "SuspiciousAccountList", Json::array{}}
        };
        Json::object data {
            {"data", Json::object{accounts}}
        };
        Json result = data;
        return result.dump();
    } else if (regex_search(query, m, regex(R"-(account:\\"0x1\\")-"))) {
        Json::object value {
            {"account", "0x1"}
        };
        Json::object accounts {
           { "SuspiciousAccountList", Json::array{value}}
        };
        Json::object data {
            {"data", Json::object{accounts}}
        };
        Json result = data;
        return result.dump();
    }
    return "";
}
