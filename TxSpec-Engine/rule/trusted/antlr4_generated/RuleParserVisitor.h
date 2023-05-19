
// Generated from RuleParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "RuleParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by RuleParser.
 */
class  RuleParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by RuleParser.
   */
    virtual antlrcpp::Any visitRoot(RuleParser::RootContext *context) = 0;

    virtual antlrcpp::Any visitRegulationDecl(RuleParser::RegulationDeclContext *context) = 0;

    virtual antlrcpp::Any visitEntitiesBlock(RuleParser::EntitiesBlockContext *context) = 0;

    virtual antlrcpp::Any visitEntityList(RuleParser::EntityListContext *context) = 0;

    virtual antlrcpp::Any visitEntityDecl(RuleParser::EntityDeclContext *context) = 0;

    virtual antlrcpp::Any visitEntityName(RuleParser::EntityNameContext *context) = 0;

    virtual antlrcpp::Any visitAttributeList(RuleParser::AttributeListContext *context) = 0;

    virtual antlrcpp::Any visitAttributeDecl(RuleParser::AttributeDeclContext *context) = 0;

    virtual antlrcpp::Any visitAttributeName(RuleParser::AttributeNameContext *context) = 0;

    virtual antlrcpp::Any visitTypeAnno(RuleParser::TypeAnnoContext *context) = 0;

    virtual antlrcpp::Any visitBasicType(RuleParser::BasicTypeContext *context) = 0;

    virtual antlrcpp::Any visitCompositeType(RuleParser::CompositeTypeContext *context) = 0;

    virtual antlrcpp::Any visitSetType(RuleParser::SetTypeContext *context) = 0;

    virtual antlrcpp::Any visitRulesBlock(RuleParser::RulesBlockContext *context) = 0;

    virtual antlrcpp::Any visitRuleList(RuleParser::RuleListContext *context) = 0;

    virtual antlrcpp::Any visitBasicRule(RuleParser::BasicRuleContext *context) = 0;

    virtual antlrcpp::Any visitRuleName(RuleParser::RuleNameContext *context) = 0;

    virtual antlrcpp::Any visitRuleStmtList(RuleParser::RuleStmtListContext *context) = 0;

    virtual antlrcpp::Any visitRuleStmt(RuleParser::RuleStmtContext *context) = 0;

    virtual antlrcpp::Any visitSimpleStmt(RuleParser::SimpleStmtContext *context) = 0;

    virtual antlrcpp::Any visitComplexStmt(RuleParser::ComplexStmtContext *context) = 0;

    virtual antlrcpp::Any visitSetStmt(RuleParser::SetStmtContext *context) = 0;

    virtual antlrcpp::Any visitSetExpr(RuleParser::SetExprContext *context) = 0;

    virtual antlrcpp::Any visitRelationStmt(RuleParser::RelationStmtContext *context) = 0;

    virtual antlrcpp::Any visitRelationExpr(RuleParser::RelationExprContext *context) = 0;

    virtual antlrcpp::Any visitNumberExpr(RuleParser::NumberExprContext *context) = 0;

    virtual antlrcpp::Any visitSelectorIdent(RuleParser::SelectorIdentContext *context) = 0;

    virtual antlrcpp::Any visitAggregationExpr(RuleParser::AggregationExprContext *context) = 0;

    virtual antlrcpp::Any visitBooleanExpr(RuleParser::BooleanExprContext *context) = 0;

    virtual antlrcpp::Any visitLogicalStmt(RuleParser::LogicalStmtContext *context) = 0;

    virtual antlrcpp::Any visitLogicalExpr(RuleParser::LogicalExprContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(RuleParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitSequentialStmt(RuleParser::SequentialStmtContext *context) = 0;

    virtual antlrcpp::Any visitSequentialExpr(RuleParser::SequentialExprContext *context) = 0;

    virtual antlrcpp::Any visitDateStmt(RuleParser::DateStmtContext *context) = 0;

    virtual antlrcpp::Any visitDateExpr(RuleParser::DateExprContext *context) = 0;

    virtual antlrcpp::Any visitTimeStmt(RuleParser::TimeStmtContext *context) = 0;

    virtual antlrcpp::Any visitTimeExpr(RuleParser::TimeExprContext *context) = 0;

    virtual antlrcpp::Any visitEos(RuleParser::EosContext *context) = 0;


};

