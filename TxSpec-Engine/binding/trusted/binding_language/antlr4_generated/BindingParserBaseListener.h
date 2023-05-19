
// Generated from BindingParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"
#include "BindingParserListener.h"


/**
 * This class provides an empty implementation of BindingParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  BindingParserBaseListener : public BindingParserListener {
public:

  virtual void enterRoot(BindingParser::RootContext * /*ctx*/) override { }
  virtual void exitRoot(BindingParser::RootContext * /*ctx*/) override { }

  virtual void enterRuleBinding(BindingParser::RuleBindingContext * /*ctx*/) override { }
  virtual void exitRuleBinding(BindingParser::RuleBindingContext * /*ctx*/) override { }

  virtual void enterBindingList(BindingParser::BindingListContext * /*ctx*/) override { }
  virtual void exitBindingList(BindingParser::BindingListContext * /*ctx*/) override { }

  virtual void enterEventToRules(BindingParser::EventToRulesContext * /*ctx*/) override { }
  virtual void exitEventToRules(BindingParser::EventToRulesContext * /*ctx*/) override { }

  virtual void enterEvent(BindingParser::EventContext * /*ctx*/) override { }
  virtual void exitEvent(BindingParser::EventContext * /*ctx*/) override { }

  virtual void enterRuleList(BindingParser::RuleListContext * /*ctx*/) override { }
  virtual void exitRuleList(BindingParser::RuleListContext * /*ctx*/) override { }

  virtual void enterRuleItem(BindingParser::RuleItemContext * /*ctx*/) override { }
  virtual void exitRuleItem(BindingParser::RuleItemContext * /*ctx*/) override { }

  virtual void enterRuleFileName(BindingParser::RuleFileNameContext * /*ctx*/) override { }
  virtual void exitRuleFileName(BindingParser::RuleFileNameContext * /*ctx*/) override { }

  virtual void enterRuleID(BindingParser::RuleIDContext * /*ctx*/) override { }
  virtual void exitRuleID(BindingParser::RuleIDContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

