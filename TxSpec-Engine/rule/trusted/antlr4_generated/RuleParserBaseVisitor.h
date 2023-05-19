
// Generated from RuleParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "RuleParserVisitor.h"


/**
 * This class provides an empty implementation of RuleParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  RuleParserBaseVisitor : public RuleParserVisitor {
public:

  virtual antlrcpp::Any visitRoot(RuleParser::RootContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRegulationDecl(RuleParser::RegulationDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntitiesBlock(RuleParser::EntitiesBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntityList(RuleParser::EntityListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntityDecl(RuleParser::EntityDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEntityName(RuleParser::EntityNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttributeList(RuleParser::AttributeListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttributeDecl(RuleParser::AttributeDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAttributeName(RuleParser::AttributeNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypeAnno(RuleParser::TypeAnnoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBasicType(RuleParser::BasicTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompositeType(RuleParser::CompositeTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetType(RuleParser::SetTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRulesBlock(RuleParser::RulesBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRuleList(RuleParser::RuleListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBasicRule(RuleParser::BasicRuleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRuleName(RuleParser::RuleNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRuleStmtList(RuleParser::RuleStmtListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRuleStmt(RuleParser::RuleStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleStmt(RuleParser::SimpleStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitComplexStmt(RuleParser::ComplexStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetStmt(RuleParser::SetStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSetExpr(RuleParser::SetExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationStmt(RuleParser::RelationStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelationExpr(RuleParser::RelationExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberExpr(RuleParser::NumberExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectorIdent(RuleParser::SelectorIdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAggregationExpr(RuleParser::AggregationExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBooleanExpr(RuleParser::BooleanExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalStmt(RuleParser::LogicalStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicalExpr(RuleParser::LogicalExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStmt(RuleParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequentialStmt(RuleParser::SequentialStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSequentialExpr(RuleParser::SequentialExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDateStmt(RuleParser::DateStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDateExpr(RuleParser::DateExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimeStmt(RuleParser::TimeStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTimeExpr(RuleParser::TimeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEos(RuleParser::EosContext *ctx) override {
    return visitChildren(ctx);
  }


};

