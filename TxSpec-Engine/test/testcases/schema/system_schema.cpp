#include "system_schema.h"

#include <iostream>
#include <regex>

using namespace std;
using namespace json11;


std::string MockSystemDatabase::GetBinding(std::string& contract_address) {
    Json::object content {
        {"content", this->Relation[contract_address]},
    };
    Json::object binding {
        {"binding", content}
    };
    Json::object relations {
        {"relations", Json::array{binding}}
    };
    Json::object data {
        {"data", relations}
    };
    Json result = data;
    string result_string = result.dump();

    return result_string;
}

std::string MockSystemDatabase::GetRule(std::string& name) { 
    Json::object content {
        {"content", this->Rules[name]},
    };
    Json::object rules {
        {"rules", Json::array {content}},
    };
    Json::object data {
        {"data", Json::object{rules}},
    };
    Json result = data;
    return result.dump();
}

string MockSystemDatabase::handleSystemQuery(string& query) {
    if (regex_search(query, regex("relations"))) {
        smatch m;
        if (regex_search(query, m, regex(R"-(contract_address:\\"(.*)\\")-")))
        {
            string contract_address = m[1].str();
            return GetBinding(contract_address);
        }
    }

    if (regex_search(query, regex("rules"))) {
        smatch m;
        if (regex_search(query, m, regex(R"-(name:\\"(.*)\\")-"))) {
            string rulefile_name = m[1].str();
            return GetRule(rulefile_name);
        }
    }
    cout << "error occur! check your test case!" << endl;
    return "";
}



