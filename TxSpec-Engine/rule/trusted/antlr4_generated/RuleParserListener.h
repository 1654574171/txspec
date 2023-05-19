
// Generated from RuleParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "RuleParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by RuleParser.
 */
class  RuleParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterRoot(RuleParser::RootContext *ctx) = 0;
  virtual void exitRoot(RuleParser::RootContext *ctx) = 0;

  virtual void enterRegulationDecl(RuleParser::RegulationDeclContext *ctx) = 0;
  virtual void exitRegulationDecl(RuleParser::RegulationDeclContext *ctx) = 0;

  virtual void enterEntitiesBlock(RuleParser::EntitiesBlockContext *ctx) = 0;
  virtual void exitEntitiesBlock(RuleParser::EntitiesBlockContext *ctx) = 0;

  virtual void enterEntityList(RuleParser::EntityListContext *ctx) = 0;
  virtual void exitEntityList(RuleParser::EntityListContext *ctx) = 0;

  virtual void enterEntityDecl(RuleParser::EntityDeclContext *ctx) = 0;
  virtual void exitEntityDecl(RuleParser::EntityDeclContext *ctx) = 0;

  virtual void enterEntityName(RuleParser::EntityNameContext *ctx) = 0;
  virtual void exitEntityName(RuleParser::EntityNameContext *ctx) = 0;

  virtual void enterAttributeList(RuleParser::AttributeListContext *ctx) = 0;
  virtual void exitAttributeList(RuleParser::AttributeListContext *ctx) = 0;

  virtual void enterAttributeDecl(RuleParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(RuleParser::AttributeDeclContext *ctx) = 0;

  virtual void enterAttributeName(RuleParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(RuleParser::AttributeNameContext *ctx) = 0;

  virtual void enterTypeAnno(RuleParser::TypeAnnoContext *ctx) = 0;
  virtual void exitTypeAnno(RuleParser::TypeAnnoContext *ctx) = 0;

  virtual void enterBasicType(RuleParser::BasicTypeContext *ctx) = 0;
  virtual void exitBasicType(RuleParser::BasicTypeContext *ctx) = 0;

  virtual void enterCompositeType(RuleParser::CompositeTypeContext *ctx) = 0;
  virtual void exitCompositeType(RuleParser::CompositeTypeContext *ctx) = 0;

  virtual void enterSetType(RuleParser::SetTypeContext *ctx) = 0;
  virtual void exitSetType(RuleParser::SetTypeContext *ctx) = 0;

  virtual void enterRulesBlock(RuleParser::RulesBlockContext *ctx) = 0;
  virtual void exitRulesBlock(RuleParser::RulesBlockContext *ctx) = 0;

  virtual void enterRuleList(RuleParser::RuleListContext *ctx) = 0;
  virtual void exitRuleList(RuleParser::RuleListContext *ctx) = 0;

  virtual void enterBasicRule(RuleParser::BasicRuleContext *ctx) = 0;
  virtual void exitBasicRule(RuleParser::BasicRuleContext *ctx) = 0;

  virtual void enterRuleName(RuleParser::RuleNameContext *ctx) = 0;
  virtual void exitRuleName(RuleParser::RuleNameContext *ctx) = 0;

  virtual void enterRuleStmtList(RuleParser::RuleStmtListContext *ctx) = 0;
  virtual void exitRuleStmtList(RuleParser::RuleStmtListContext *ctx) = 0;

  virtual void enterRuleStmt(RuleParser::RuleStmtContext *ctx) = 0;
  virtual void exitRuleStmt(RuleParser::RuleStmtContext *ctx) = 0;

  virtual void enterSimpleStmt(RuleParser::SimpleStmtContext *ctx) = 0;
  virtual void exitSimpleStmt(RuleParser::SimpleStmtContext *ctx) = 0;

  virtual void enterComplexStmt(RuleParser::ComplexStmtContext *ctx) = 0;
  virtual void exitComplexStmt(RuleParser::ComplexStmtContext *ctx) = 0;

  virtual void enterSetStmt(RuleParser::SetStmtContext *ctx) = 0;
  virtual void exitSetStmt(RuleParser::SetStmtContext *ctx) = 0;

  virtual void enterSetExpr(RuleParser::SetExprContext *ctx) = 0;
  virtual void exitSetExpr(RuleParser::SetExprContext *ctx) = 0;

  virtual void enterRelationStmt(RuleParser::RelationStmtContext *ctx) = 0;
  virtual void exitRelationStmt(RuleParser::RelationStmtContext *ctx) = 0;

  virtual void enterRelationExpr(RuleParser::RelationExprContext *ctx) = 0;
  virtual void exitRelationExpr(RuleParser::RelationExprContext *ctx) = 0;

  virtual void enterNumberExpr(RuleParser::NumberExprContext *ctx) = 0;
  virtual void exitNumberExpr(RuleParser::NumberExprContext *ctx) = 0;

  virtual void enterSelectorIdent(RuleParser::SelectorIdentContext *ctx) = 0;
  virtual void exitSelectorIdent(RuleParser::SelectorIdentContext *ctx) = 0;

  virtual void enterAggregationExpr(RuleParser::AggregationExprContext *ctx) = 0;
  virtual void exitAggregationExpr(RuleParser::AggregationExprContext *ctx) = 0;

  virtual void enterBooleanExpr(RuleParser::BooleanExprContext *ctx) = 0;
  virtual void exitBooleanExpr(RuleParser::BooleanExprContext *ctx) = 0;

  virtual void enterLogicalStmt(RuleParser::LogicalStmtContext *ctx) = 0;
  virtual void exitLogicalStmt(RuleParser::LogicalStmtContext *ctx) = 0;

  virtual void enterLogicalExpr(RuleParser::LogicalExprContext *ctx) = 0;
  virtual void exitLogicalExpr(RuleParser::LogicalExprContext *ctx) = 0;

  virtual void enterIfStmt(RuleParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(RuleParser::IfStmtContext *ctx) = 0;

  virtual void enterSequentialStmt(RuleParser::SequentialStmtContext *ctx) = 0;
  virtual void exitSequentialStmt(RuleParser::SequentialStmtContext *ctx) = 0;

  virtual void enterSequentialExpr(RuleParser::SequentialExprContext *ctx) = 0;
  virtual void exitSequentialExpr(RuleParser::SequentialExprContext *ctx) = 0;

  virtual void enterDateStmt(RuleParser::DateStmtContext *ctx) = 0;
  virtual void exitDateStmt(RuleParser::DateStmtContext *ctx) = 0;

  virtual void enterDateExpr(RuleParser::DateExprContext *ctx) = 0;
  virtual void exitDateExpr(RuleParser::DateExprContext *ctx) = 0;

  virtual void enterTimeStmt(RuleParser::TimeStmtContext *ctx) = 0;
  virtual void exitTimeStmt(RuleParser::TimeStmtContext *ctx) = 0;

  virtual void enterTimeExpr(RuleParser::TimeExprContext *ctx) = 0;
  virtual void exitTimeExpr(RuleParser::TimeExprContext *ctx) = 0;

  virtual void enterEos(RuleParser::EosContext *ctx) = 0;
  virtual void exitEos(RuleParser::EosContext *ctx) = 0;


};

