// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares EntityCollector class.

#pragma once

#include <map>
#include <vector>
#include <string>
#include <regex>

#include "RuleEnclave_t.h" /* sgx generated proxy header */

#include "antlr4-runtime.h"
#include "trusted/data_types/Entity.h"
#include "trusted/data_types/EntitySet.h"
#include "common/data_types/rule_check/ErrorType.h"
#include "rule_enclave/EntityQuery.pb.h"

#include "BaseVisitor.h"

#include "trusted/data_types/RequestContext.h"
#include "trusted/antlr4_generated/RuleParserBaseVisitor.h"
#include "trusted/antlr4_generated/RuleLexer.h"

// using namespace std;
// using namespace antlr4;

// `EntityCollector` extends BaseVisitor with additional utility functions
class EntityCollector : public BaseVisitor
{
private:
    // map from entity name (aka id) to entity request
    std::map<std::string, Entity *> entity_map_;

    // list of entity set requestes
    std::vector<EntitySet *> entity_set_list_;

    // rule check request context
    RequestContext *request_context_;

    // map from set (entity) name to set element
    // for retrieve set element from set name
    std::map<std::string, std::string> set_element_map_;

    /* Internal Handler Member Functions */

    // mark set and element name as known
    RuleEnclaveStatus KeepTrackOfNewSet(const std::string &set_name, const std::string &element_name);

    // TODO the following some functions are shared with RuleEvaluator,
    //      and can be put into a common Base class
    // std::string FilterNumberLiteral(const std::string &number_string);
    // double ParseNumberLiteral(const std::string &number_string);
    // double ParseNumberLiteral(antlr4::tree::TerminalNode *const terminal_node);

    // mark entity in collection
    void KeepTrackOfNewEntity(const std::string &entity_name);
    void KeepTrackOfNewEntityAttribute(const std::string &entity_name, const std::string &attribute_name);

    // NOTE: The following functions assume `constraint` and `constraint_list` to be created outside of
    //       these functions and managed (e.g., freed) as well
    void GetNewProvidedConstraint(RuleParser::SelectorIdentContext *const context,
                                  rule_check_proto::Constraint *const constraint);
    void GetNewWithinConstraint(antlr4::tree::TerminalNode *const terminal_node,
                                rule_check_proto::Constraint *const constraint);
    void GetNewWhereConstraint(RuleParser::BooleanExprContext *const context,
                               std::vector<rule_check_proto::Constraint> *const constraint_list);
    void GetNewWhereConstraint(RuleParser::SetExprContext *const context,
                               rule_check_proto::Constraint *const constraint);

    void CollectEntitySetFromAggregationExpr(RuleParser::AggregationExprContext *const context);

public:
    EntityCollector(RequestContext *const request_context);
    ~EntityCollector();

    /* Data Member Getters */

    const std::vector<Entity> get_entity_list() const;
    const std::vector<EntitySet> get_entity_set_list() const;
    const std::map<std::string, Entity*>& get_initial_entity() const;

    RequestContext *const get_request_context();

    const std::string &get_set_element_name(const std::string &set_name);

    /* Overridden Visitor Member Functions for Traversing Rule Language Nodes */

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

    // virtual antlrcpp::Any visitRuleStmtList(RuleParser::RuleStmtListContext *context) = 0;

    // virtual antlrcpp::Any visitRuleStmt(RuleParser::RuleStmtContext *context) = 0;

    // virtual antlrcpp::Any visitSimpleStmt(RuleParser::SimpleStmtContext *context) = 0;

    // virtual antlrcpp::Any visitComplexStmt(RuleParser::ComplexStmtContext *context) = 0;

    // virtual antlrcpp::Any visitSetStmt(RuleParser::SetStmtContext *context) = 0;

    virtual antlrcpp::Any visitSetExpr(RuleParser::SetExprContext *context) override;

    // virtual antlrcpp::Any visitRelationStmt(RuleParser::RelationStmtContext *context) = 0;

    // virtual antlrcpp::Any visitRelationExpr(RuleParser::RelationExprContext *context) = 0;

    virtual antlrcpp::Any visitNumberExpr(RuleParser::NumberExprContext *context) override;

    // virtual antlrcpp::Any visitSelectorIdent(RuleParser::SelectorIdentContext *context) = 0;

    virtual antlrcpp::Any visitAggregationExpr(RuleParser::AggregationExprContext *context) override;

    virtual antlrcpp::Any visitBooleanExpr(RuleParser::BooleanExprContext *context) override;

    // virtual antlrcpp::Any visitLogicalStmt(RuleParser::LogicalStmtContext *context) = 0;

    virtual antlrcpp::Any visitLogicalExpr(RuleParser::LogicalExprContext *context) override;

    // virtual antlrcpp::Any visitIfStmt(RuleParser::IfStmtContext *context) = 0;

    // virtual antlrcpp::Any visitSequentialStmt(RuleParser::SequentialStmtContext *context) = 0;

    // virtual antlrcpp::Any visitSequentialExpr(RuleParser::SequentialExprContext *context) = 0;

    // virtual antlrcpp::Any visitDateStmt(RuleParser::DateStmtContext *context) = 0;

    // virtual antlrcpp::Any visitDateExpr(RuleParser::DateExprContext *context) = 0;

    // virtual antlrcpp::Any visitTimeStmt(RuleParser::TimeStmtContext *context) = 0;

    // virtual antlrcpp::Any visitTimeExpr(RuleParser::TimeExprContext *context) = 0;

    // virtual antlrcpp::Any visitEos(RuleParser::EosContext *context) = 0;
};