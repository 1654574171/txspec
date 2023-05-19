#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>

#include <common/json_lib/json11.hpp>
#include "basic_server/database.h"
#include "ProofRequest.pb.h"

class MockSystemDatabase : public Database {
   public:

    // self-define database function
    void insertBinding(std::string contract_address,
                       std::string binding_content) {
        Relation.insert({contract_address, binding_content});
    }

    void insertRule(std::string name, std::string rule_content) {
        Rules.insert({name, rule_content});
    }

    std::string GetBinding(std::string& contract_address);
    std::string GetRule(std::string& name);
    std::string handleSystemQuery(std::string& query);

    // contract_address  ->  binding.content
    std::map<std::string, std::string> Relation;

    // name -> content
    std::map<std::string, std::string> Rules;

    
};