
// Generated from RuleParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "RuleParserListener.h"


/**
 * This class provides an empty implementation of RuleParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  RuleParserBaseListener : public RuleParserListener {
public:

  virtual void enterRoot(RuleParser::RootContext * /*ctx*/) override { }
  virtual void exitRoot(RuleParser::RootContext * /*ctx*/) override { }

  virtual void enterRegulationDecl(RuleParser::RegulationDeclContext * /*ctx*/) override { }
  virtual void exitRegulationDecl(RuleParser::RegulationDeclContext * /*ctx*/) override { }

  virtual void enterEntitiesBlock(RuleParser::EntitiesBlockContext * /*ctx*/) override { }
  virtual void exitEntitiesBlock(RuleParser::EntitiesBlockContext * /*ctx*/) override { }

  virtual void enterEntityList(RuleParser::EntityListContext * /*ctx*/) override { }
  virtual void exitEntityList(RuleParser::EntityListContext * /*ctx*/) override { }

  virtual void enterEntityDecl(RuleParser::EntityDeclContext * /*ctx*/) override { }
  virtual void exitEntityDecl(RuleParser::EntityDeclContext * /*ctx*/) override { }

  virtual void enterEntityName(RuleParser::EntityNameContext * /*ctx*/) override { }
  virtual void exitEntityName(RuleParser::EntityNameContext * /*ctx*/) override { }

  virtual void enterAttributeList(RuleParser::AttributeListContext * /*ctx*/) override { }
  virtual void exitAttributeList(RuleParser::AttributeListContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(RuleParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(RuleParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeName(RuleParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(RuleParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterTypeAnno(RuleParser::TypeAnnoContext * /*ctx*/) override { }
  virtual void exitTypeAnno(RuleParser::TypeAnnoContext * /*ctx*/) override { }

  virtual void enterBasicType(RuleParser::BasicTypeContext * /*ctx*/) override { }
  virtual void exitBasicType(RuleParser::BasicTypeContext * /*ctx*/) override { }

  virtual void enterCompositeType(RuleParser::CompositeTypeContext * /*ctx*/) override { }
  virtual void exitCompositeType(RuleParser::CompositeTypeContext * /*ctx*/) override { }

  virtual void enterSetType(RuleParser::SetTypeContext * /*ctx*/) override { }
  virtual void exitSetType(RuleParser::SetTypeContext * /*ctx*/) override { }

  virtual void enterRulesBlock(RuleParser::RulesBlockContext * /*ctx*/) override { }
  virtual void exitRulesBlock(RuleParser::RulesBlockContext * /*ctx*/) override { }

  virtual void enterRuleList(RuleParser::RuleListContext * /*ctx*/) override { }
  virtual void exitRuleList(RuleParser::RuleListContext * /*ctx*/) override { }

  virtual void enterBasicRule(RuleParser::BasicRuleContext * /*ctx*/) override { }
  virtual void exitBasicRule(RuleParser::BasicRuleContext * /*ctx*/) override { }

  virtual void enterRuleName(RuleParser::RuleNameContext * /*ctx*/) override { }
  virtual void exitRuleName(RuleParser::RuleNameContext * /*ctx*/) override { }

  virtual void enterRuleStmtList(RuleParser::RuleStmtListContext * /*ctx*/) override { }
  virtual void exitRuleStmtList(RuleParser::RuleStmtListContext * /*ctx*/) override { }

  virtual void enterRuleStmt(RuleParser::RuleStmtContext * /*ctx*/) override { }
  virtual void exitRuleStmt(RuleParser::RuleStmtContext * /*ctx*/) override { }

  virtual void enterSimpleStmt(RuleParser::SimpleStmtContext * /*ctx*/) override { }
  virtual void exitSimpleStmt(RuleParser::SimpleStmtContext * /*ctx*/) override { }

  virtual void enterComplexStmt(RuleParser::ComplexStmtContext * /*ctx*/) override { }
  virtual void exitComplexStmt(RuleParser::ComplexStmtContext * /*ctx*/) override { }

  virtual void enterSetStmt(RuleParser::SetStmtContext * /*ctx*/) override { }
  virtual void exitSetStmt(RuleParser::SetStmtContext * /*ctx*/) override { }

  virtual void enterSetExpr(RuleParser::SetExprContext * /*ctx*/) override { }
  virtual void exitSetExpr(RuleParser::SetExprContext * /*ctx*/) override { }

  virtual void enterRelationStmt(RuleParser::RelationStmtContext * /*ctx*/) override { }
  virtual void exitRelationStmt(RuleParser::RelationStmtContext * /*ctx*/) override { }

  virtual void enterRelationExpr(RuleParser::RelationExprContext * /*ctx*/) override { }
  virtual void exitRelationExpr(RuleParser::RelationExprContext * /*ctx*/) override { }

  virtual void enterNumberExpr(RuleParser::NumberExprContext * /*ctx*/) override { }
  virtual void exitNumberExpr(RuleParser::NumberExprContext * /*ctx*/) override { }

  virtual void enterSelectorIdent(RuleParser::SelectorIdentContext * /*ctx*/) override { }
  virtual void exitSelectorIdent(RuleParser::SelectorIdentContext * /*ctx*/) override { }

  virtual void enterAggregationExpr(RuleParser::AggregationExprContext * /*ctx*/) override { }
  virtual void exitAggregationExpr(RuleParser::AggregationExprContext * /*ctx*/) override { }

  virtual void enterBooleanExpr(RuleParser::BooleanExprContext * /*ctx*/) override { }
  virtual void exitBooleanExpr(RuleParser::BooleanExprContext * /*ctx*/) override { }

  virtual void enterLogicalStmt(RuleParser::LogicalStmtContext * /*ctx*/) override { }
  virtual void exitLogicalStmt(RuleParser::LogicalStmtContext * /*ctx*/) override { }

  virtual void enterLogicalExpr(RuleParser::LogicalExprContext * /*ctx*/) override { }
  virtual void exitLogicalExpr(RuleParser::LogicalExprContext * /*ctx*/) override { }

  virtual void enterIfStmt(RuleParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(RuleParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterSequentialStmt(RuleParser::SequentialStmtContext * /*ctx*/) override { }
  virtual void exitSequentialStmt(RuleParser::SequentialStmtContext * /*ctx*/) override { }

  virtual void enterSequentialExpr(RuleParser::SequentialExprContext * /*ctx*/) override { }
  virtual void exitSequentialExpr(RuleParser::SequentialExprContext * /*ctx*/) override { }

  virtual void enterDateStmt(RuleParser::DateStmtContext * /*ctx*/) override { }
  virtual void exitDateStmt(RuleParser::DateStmtContext * /*ctx*/) override { }

  virtual void enterDateExpr(RuleParser::DateExprContext * /*ctx*/) override { }
  virtual void exitDateExpr(RuleParser::DateExprContext * /*ctx*/) override { }

  virtual void enterTimeStmt(RuleParser::TimeStmtContext * /*ctx*/) override { }
  virtual void exitTimeStmt(RuleParser::TimeStmtContext * /*ctx*/) override { }

  virtual void enterTimeExpr(RuleParser::TimeExprContext * /*ctx*/) override { }
  virtual void exitTimeExpr(RuleParser::TimeExprContext * /*ctx*/) override { }

  virtual void enterEos(RuleParser::EosContext * /*ctx*/) override { }
  virtual void exitEos(RuleParser::EosContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

