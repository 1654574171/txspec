#include "nft_transfer.h"
#include <string>
#include <regex>

using namespace json11;
using namespace std;
// data of binding
string TestNFTListContractName = "TestNFTList";
string TestNFTListContractBindingContent0 =
    R"(rules{ nft_receive -> [TestNFTListRule.nft_white_list];})";

// data of rules
string TestNFTListRuleName = "TestNFTListRule";
string TestNFTListRuleContent =
    R"(regulation erc20 entities { entity interchainnftreceive {  hash  sender  receiver  class_id  tocken_id  timestamp }  } rules {rule nft_white_list { interchainnftreceive.tocken_id in discountnftlist}})";

interchain_nft_receives nft_transfer_succ_1 {
    "0x307831303030"/*hash*/, "succ" /*class_id*/, "succ_1" /*tocken_id*/
};

interchain_nft_receives nft_transfer_fail_1 {
    "0x307832303030"/*hash*/, "fail" /*class_id*/, "fail_1" /*tocken_id*/
};

void mockProofRequest_NFTList_succ1(request_proto::ProofRequest* request) {
    request->set_txhash("0x1000");

    request_proto::Data* data = new request_proto::Data();
    request_proto::ContractEvent* contractEvent = data->add_events();
    contractEvent->set_contractid(TestNFTListContractName);
    request_proto::Event* event = contractEvent->add_events();
    event->set_eventname("nft_receive");
    request->set_allocated_data(data);
}

void mockProofRequest_NFTList_fail1(request_proto::ProofRequest* request) {
    request->set_txhash("0x2000");

    request_proto::Data* data = new request_proto::Data();
    request_proto::ContractEvent* contractEvent = data->add_events();
    contractEvent->set_contractid(TestNFTListContractName);
    request_proto::Event* event = contractEvent->add_events();
    event->set_eventname("nft_receive");
    request->set_allocated_data(data);
}

void InitMockDataBase_NFTList0(MockDatabase_NFT& mockDatabase) {
    mockDatabase.insertBinding(TestNFTListContractName, TestNFTListContractBindingContent0);
    mockDatabase.insertRule(TestNFTListRuleName, TestNFTListRuleContent);
    mockDatabase.insertNFTItem(&nft_transfer_succ_1);
    mockDatabase.insertNFTItem(&nft_transfer_fail_1);
}

std::string MockDatabase_NFTlist::handleQuery(std::string& query, std::string& target){
    if (target.compare(TestNFTListContractName) == 0) 
        return handleContractQuery(query);
    
    if (target.compare("system") == 0)
        return MockDatabase_NFT::handleSystemQuery(query);

    return "";
}

bool MockDatabase_NFTlist::matchDatabase (std::string& target) {
    if (target.compare(TestNFTListContractName) == 0)
        return true;
    if (target.compare("system") == 0)
        return true;
    return false;
}

std::string MockDatabase_NFTlist::handleContractQuery(std::string& query) {
    smatch m;
    if (regex_search(query, m, regex(R"-(hash:\\"(.*)\\")-"))) {
        string hash = m[1].str();
        cout << "test" << hash << endl;
        interchain_nft_receives* t = GetNFTByhash(hash);

        cout << "test" << t->classid << "  " << t->tocken_id << endl;

        Json::object value {
            {"class_id", t->classid},
            {"tocken_id", t->tocken_id}
        };
        Json::object transfers {
           { "interchainnftreceives", Json::array{value}}
        };
        Json::object data {
            {"data", Json::object{transfers}}
        };
        Json result = data;
        return result.dump();
    }

    if (regex_search(query, m, regex("succ"))) {
        Json::object value {
            {"class_id", "0x1"},
            {"tocken_id", "0x2"}
        };
        Json::object transfers {
           { "discountnftlists", Json::array{value}}
        };
        Json::object data {
            {"data", Json::object{transfers}}
        };
        Json result = data;
        return result.dump();
    }

    if (regex_search(query, m, regex("fail"))) {
        Json::object transfers {
           { "discountnftlists", Json::array{}}
        };
        Json::object data {
            {"data", Json::object{transfers}}
        };
        Json result = data;
        return result.dump();
    }
    return "";
}