// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares RuleEvaluator class.

#pragma once

#include <map>
#include <string>
#include <vector>
#include <cstdlib>

#include "RuleEnclave_t.h" /* sgx generated proxy header */

#include "antlr4-runtime.h"
#include "trusted/data_types/Entity.h"
#include "trusted/data_types/EntitySet.h"
#include "common/data_types/rule_check/ErrorType.h"

#include "BaseVisitor.h"

#include "trusted/antlr4_generated/RuleLexer.h"
#include "trusted/antlr4_generated/RuleParser.h"
#include "trusted/antlr4_generated/RuleParserBaseVisitor.h"
#include "trusted/data_types/RequestContext.h"

// using namespace std;
// using namespace antlr4;

// `RuleEvaluator` extends BaseVisitor with additional utility functions
class RuleEvaluator : public BaseVisitor
{
private:
    RequestContext *request_context_;

    // map from rule id (e.g., "r1") to evaluation result
    // map<string, bool> rule_evaluation_result_map_;

    // overall rule evaluation result, i.e., and[rule_evaluation_result_map_]
    // bool overall_evaluation_result_;

    // temporary map from entity name to corresponding entity binding (JSON)
    // NOTE this map meant to tweak how entity data binding are resolved
    // NOTE see Json get_entity_binding(string entity_id);
    std::map<std::string, json11::Json> temporary_entity_binding_map_;

    // temporary map from rule context text to corresponding entity set binding (JSON)
    // NOTE this map meant to tweak how entity set data binding are resolved
    // NOTE see Json get_entity_set_binding(string entity_set_id);

    // TODO we should have used a smarter way to mark each entity set request,
    // TODO instead of the whole rule context text
    std::map<std::string, json11::Json> temporary_entity_set_binding_map_;

    // map from set (entity) name to set element
    // for retrieve set element from set name
    std::map<std::string, std::string> set_element_map_;

    /* helper functions for internal use */

    // mark set and element name as known
    RuleEnclaveStatus KeepTrackOfNewSet(const std::string &set_name, const std::string &element_name);

    // std::string FilterNumberLiteral(std::string number_string);
    // double ParseNumberLiteral(std::string number_string);
    // double ParseNumberLiteral(antlr4::tree::TerminalNode *terminal_node);

    // bool ParseBooleanLiteral(std::string boolean_string);
    // bool ParseBooleanLiteral(antlr4::tree::TerminalNode *terminal_node);

    // parse and retrieve bool values from given parse tree pointer list
    void ParseBooleanExpression(std::vector<antlr4::tree::ParseTree *> context_list,
                                std::vector<bool> *const boolean_value_list);

    // function wrapper for RequestContext
    // NOTE the two functions are meant to change how entity (set) binding resolves
    // NOTE specifically, in some cases, we need to temporarily change data binding
    // NOTE for some entity (set), which however should restore after
    // NOTE to facilitate the above behaviour, we provide the two wrapper functions
    const json11::Json &get_entity_binding(const std::string &entity_id);
    const json11::Json &get_entity_set_binding(const std::string &entity_set_id);

    // temporarily set (unset) entity (set) data binding to override request context
    void set_temporary_entity_binding(const std::string &entity_id, const json11::Json &binding);
    void set_temporary_entity_set_binding(const std::string &entity_set_id, const json11::Json &binding);

    void clear_temporary_entity_binding_map();
    void clear_temporary_entity_set_binding_map();

    // set evaluation result for specific rule id
    // void set_rule_evaluation_result(string rule_id, bool evaluation_result);

public:
    RuleEvaluator(RequestContext *const request_context);
    ~RuleEvaluator();

    /* Data Member Getters */

    RequestContext *const get_request_context();

    const std::string &get_set_element_name(const std::string &set_name);

    // map<string, bool> get_rule_evaluation_result_map();

    // bool get_overall_evaluation_result();

    // /* Overridden Visitor Member Functions for Traversing Rule Language Nodes */

    // virtual antlrcpp::Any visitRoot(RuleParser::RootContext *context) = 0;

    // virtual antlrcpp::Any visitRegulationDecl(RuleParser::RegulationDeclContext *context) = 0;

    // virtual antlrcpp::Any visitEntitiesBlock(RuleParser::EntitiesBlockContext *context) = 0;

    // virtual antlrcpp::Any visitEntityList(RuleParser::EntityListContext *context) = 0;

    virtual antlrcpp::Any visitEntityDecl(RuleParser::EntityDeclContext *context) override;

    // virtual antlrcpp::Any visitEntityName(RuleParser::EntityNameContext *context) = 0;

    // virtual antlrcpp::Any visitAttributeList(RuleParser::AttributeListContext *context) = 0;

    // virtual antlrcpp::Any visitAttributeDecl(RuleParser::AttributeDeclContext *context) = 0;

    // virtual antlrcpp::Any visitAttributeName(RuleParser::AttributeNameContext *context) = 0;

    // virtual antlrcpp::Any visitTypeAnno(RuleParser::TypeAnnoContext *context) = 0;

    // virtual antlrcpp::Any visitBasicType(RuleParser::BasicTypeContext *context) = 0;

    // virtual antlrcpp::Any visitCompositeType(RuleParser::CompositeTypeContext *context) = 0;

    // virtual antlrcpp::Any visitSetType(RuleParser::SetTypeContext *context) = 0;

    // virtual antlrcpp::Any visitRulesBlock(RuleParser::RulesBlockContext *context) = 0;

    // virtual antlrcpp::Any visitRuleList(RuleParser::RuleListContext *context) = 0;

    virtual antlrcpp::Any visitBasicRule(RuleParser::BasicRuleContext *context) override;

    // virtual antlrcpp::Any visitRuleName(RuleParser::RuleNameContext *context) = 0;

    virtual antlrcpp::Any visitRuleStmtList(RuleParser::RuleStmtListContext *context) override;

    virtual antlrcpp::Any visitRuleStmt(RuleParser::RuleStmtContext *context) override;

    virtual antlrcpp::Any visitSimpleStmt(RuleParser::SimpleStmtContext *context) override;

    virtual antlrcpp::Any visitComplexStmt(RuleParser::ComplexStmtContext *context) override;

    virtual antlrcpp::Any visitSetStmt(RuleParser::SetStmtContext *context) override;

    virtual antlrcpp::Any visitSetExpr(RuleParser::SetExprContext *context) override;

    virtual antlrcpp::Any visitRelationStmt(RuleParser::RelationStmtContext *context) override;

    virtual antlrcpp::Any visitRelationExpr(RuleParser::RelationExprContext *context) override;

    virtual antlrcpp::Any visitNumberExpr(RuleParser::NumberExprContext *context) override;

    // virtual antlrcpp::Any visitSelectorIdent(RuleParser::SelectorIdentContext *context) = 0;

    virtual antlrcpp::Any visitAggregationExpr(RuleParser::AggregationExprContext *context) override;

    virtual antlrcpp::Any visitBooleanExpr(RuleParser::BooleanExprContext *context) override;

    virtual antlrcpp::Any visitLogicalStmt(RuleParser::LogicalStmtContext *context) override;

    virtual antlrcpp::Any visitLogicalExpr(RuleParser::LogicalExprContext *context) override;

    virtual antlrcpp::Any visitIfStmt(RuleParser::IfStmtContext *context) override;

    // virtual antlrcpp::Any visitSequentialStmt(RuleParser::SequentialStmtContext *context) = 0;

    // virtual antlrcpp::Any visitSequentialExpr(RuleParser::SequentialExprContext *context) = 0;

    // virtual antlrcpp::Any visitDateStmt(RuleParser::DateStmtContext *context) = 0;

    // virtual antlrcpp::Any visitDateExpr(RuleParser::DateExprContext *context) = 0;

    // virtual antlrcpp::Any visitTimeStmt(RuleParser::TimeStmtContext *context) = 0;

    // virtual antlrcpp::Any visitTimeExpr(RuleParser::TimeExprContext *context) = 0;

    // virtual antlrcpp::Any visitEos(RuleParser::EosContext *context) = 0;
};