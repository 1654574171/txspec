
// Generated from BindingParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "BindingParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by BindingParser.
 */
class  BindingParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterRoot(BindingParser::RootContext *ctx) = 0;
  virtual void exitRoot(BindingParser::RootContext *ctx) = 0;

  virtual void enterRuleBinding(BindingParser::RuleBindingContext *ctx) = 0;
  virtual void exitRuleBinding(BindingParser::RuleBindingContext *ctx) = 0;

  virtual void enterBindingList(BindingParser::BindingListContext *ctx) = 0;
  virtual void exitBindingList(BindingParser::BindingListContext *ctx) = 0;

  virtual void enterEventToRules(BindingParser::EventToRulesContext *ctx) = 0;
  virtual void exitEventToRules(BindingParser::EventToRulesContext *ctx) = 0;

  virtual void enterEvent(BindingParser::EventContext *ctx) = 0;
  virtual void exitEvent(BindingParser::EventContext *ctx) = 0;

  virtual void enterRuleList(BindingParser::RuleListContext *ctx) = 0;
  virtual void exitRuleList(BindingParser::RuleListContext *ctx) = 0;

  virtual void enterRuleItem(BindingParser::RuleItemContext *ctx) = 0;
  virtual void exitRuleItem(BindingParser::RuleItemContext *ctx) = 0;

  virtual void enterRuleFileName(BindingParser::RuleFileNameContext *ctx) = 0;
  virtual void exitRuleFileName(BindingParser::RuleFileNameContext *ctx) = 0;

  virtual void enterRuleID(BindingParser::RuleIDContext *ctx) = 0;
  virtual void exitRuleID(BindingParser::RuleIDContext *ctx) = 0;


};

