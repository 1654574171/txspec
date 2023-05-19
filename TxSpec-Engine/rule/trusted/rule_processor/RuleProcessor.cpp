// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements RuleProcessor class.

#include "RuleProcessor.h"

using namespace std;
using namespace json11;
using namespace antlr4;

static void dumpEntityList(vector<Entity>& entity_list) {
    ocall_print_string("EvaluateRule: dump entity list", __FILE__, __LINE__);

    for (auto &entity : entity_list)
    {
        string entity_string;
        // basic entity info
        auto entity_name = entity.get_name();
        auto attribute_set = entity.get_attribute_set();

        entity_string += ("EvaluateRule: entity: " + entity_name + "[");

        // traverse through attribute set
        uint64_t counter = 0;
        for (auto &attribute : attribute_set)
        {
            if (counter++ > 0)
            {
                entity_string += ", ";
            }
            entity_string += attribute;
        }

        entity_string += "]";

        ocall_print_string((string("EvaluateRule: new entity: ") + entity_string).c_str(), __FILE__, __LINE__);
    }
}

static void dumpEntitySetList(vector<EntitySet>& entity_set_list) {
    ocall_print_string("EvaluateRule: dump entity set list", __FILE__, __LINE__);
    for (auto &entity_set : entity_set_list)
    {
        string entity_set_string;

        // basic entity set info
        auto entity_name = entity_set.get_name();
        auto constraint_list = entity_set.get_constraint_list();

        entity_set_string += ("EvaluateRule: entity set: " + entity_name + "[");

        ocall_print_string(("EvaluateRule: constraint_list size: " +
                            to_string(constraint_list.size())).c_str(), __FILE__, __LINE__);

        // traverse through constraint list
        uint64_t counter = 0;
        for (auto constraint_iter = constraint_list.begin();
             constraint_iter != constraint_list.end(); constraint_iter++)
        {
            if (counter++ > 0)
            {
                entity_set_string += ", ";
            }
            entity_set_string += constraint_iter->Utf8DebugString();
        }

        entity_set_string += "]";

        ocall_print_string((string("EvaluateRule: new entity set: ") + entity_set_string).c_str(), __FILE__, __LINE__);
    }
}

// EvaluateRule is used to regulate transaction with rules
RuleEnclaveStatus RuleProcessor::EvaluateRule(RequestContext *const request_context)
{
    ocall_print_string("enter EvaluateRule", __FILE__, __LINE__);

    RuleEnclaveStatus status_code = RuleEnclaveStatus::kOK;

    // handlers for use in rule evaluation:
    // retrieve referenced entities and entity_sets
    EntityCollector entity_collector = EntityCollector(request_context); // rule language visitor
    ocall_print_string("parse rule text", __FILE__, __LINE__);

    // build a parse tree from requested rule text
    ANTLRInputStream input(request_context->get_rule_text());
    RuleLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    // print out lexer parsed tokens
    tokens.fill();
    uint64_t counter = 0;

    ocall_print_string("traverse tokens", __FILE__, __LINE__);
    for (const auto &token : tokens.getTokens())
    {
        ocall_print_string((string("token at pos ") +
                            to_string(counter++) +
                            string(": ") + token->toString()).c_str(), __FILE__, __LINE__);
    }
    ocall_print_string("parse rule tree", __FILE__, __LINE__);
    RuleParser parser(&tokens);
    ocall_print_string("get tree root", __FILE__, __LINE__);
    // every rule starts with a "root" node
    auto *tree = parser.root();

    // ocall_print_string("collect entity and entity set list");
    // visit parse tree to retrieve referenced entities and entity_sets
    tree->accept(&entity_collector);

    // get and dump entity list for Debug
    auto entity_list = entity_collector.get_entity_list();
    dumpEntityList(entity_list);

    // get and dump entity set list for Debug
    auto entity_set_list = entity_collector.get_entity_set_list();
    dumpEntitySetList(entity_set_list);

    ocall_print_string("request entity binding", __FILE__, __LINE__);

    // ask binding module for data binding (for both entities and entity sets)
    // for entity data binding
    for (auto entity : entity_list)
    {
        ocall_print_string(("request entity: " + entity.dump()).c_str(), __FILE__, __LINE__);
        ocall_print_string(("request id is : " + request_context->get_req_id()).c_str(), __FILE__, __LINE__);

        QueryBuilder builder;
        string query_string = builder.GenerateQueryString(entity, request_context);

        DataProvider provider;
        Json query_result;
        provider.QueryDataFromGraphnodeJson(query_string, request_context->contract_id, query_result);
        ocall_print_string(("entity binding" + query_result.dump()).c_str(), __FILE__, __LINE__);

        Json binding_result;
        provider.ParseEntityOutputJSON(query_result, &binding_result);

        ocall_print_string(("EvaluateRule: requested entity: " + binding_result.dump()).c_str(), __FILE__, __LINE__);
        request_context->set_entity_binding(entity.get_id(), binding_result);
        // TODO Decide on lifespan of binding, whether it can last longer
    }

    ocall_print_string("request entity set binding", __FILE__, __LINE__);
    // for entity set data binding
    for (auto entity_set : entity_set_list)
    {
        ocall_print_string(("request entity set: " + entity_set.dump()).c_str(), __FILE__, __LINE__);

        QueryBuilder builder;
        string query_string = builder.GenerateQueryString(entity_set, request_context);
        ocall_print_string(("query string is: " + query_string).c_str(), __FILE__, __LINE__);

        DataProvider provider;
        Json query_result;
        provider.QueryDataFromGraphnodeJson(query_string, request_context->contract_id, query_result);
        ocall_print_string(("entity set query result" + query_result.dump()).c_str(), __FILE__, __LINE__);

        Json binding_result;
        provider.ParseEntitySetOutputJSON(query_result, &binding_result);

        ocall_print_string(("EvaluateRule: requested entity set: " + binding_result.dump()).c_str(), __FILE__, __LINE__);
        request_context->set_entity_set_binding(entity_set.get_id(), binding_result);
    }

    ocall_print_string("evalute rule with entity and entity set binding", __FILE__, __LINE__);

    // visit parse tree to evaluate rule and decide on result
    // evaluation result is stored inside request context
    RuleEvaluator rule_evaluator = RuleEvaluator(request_context);       // rule language visitor
    tree->accept(&rule_evaluator);

    // TODO build rule check result

    ocall_print_string("exit EvaluateRule", __FILE__, __LINE__);
    return RuleEnclaveStatus::kOK;
}