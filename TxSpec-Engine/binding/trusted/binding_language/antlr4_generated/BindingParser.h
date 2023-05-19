
// Generated from BindingParser.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  BindingParser : public antlr4::Parser {
public:
  enum {
    RULES = 1, L_CURLY = 2, R_CURLY = 3, L_BRACKET = 4, R_BRACKET = 5, MAP = 6, 
    DOT = 7, COMMA = 8, SEMI = 9, WS = 10, COMMENT = 11, TERMINATOR = 12, 
    LINE_COMMENT = 13, IDENTIFIER = 14
  };

  enum {
    RuleRoot = 0, RuleRuleBinding = 1, RuleBindingList = 2, RuleEventToRules = 3, 
    RuleEvent = 4, RuleRuleList = 5, RuleRuleItem = 6, RuleRuleFileName = 7, 
    RuleRuleID = 8
  };

  explicit BindingParser(antlr4::TokenStream *input);
  ~BindingParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class RootContext;
  class RuleBindingContext;
  class BindingListContext;
  class EventToRulesContext;
  class EventContext;
  class RuleListContext;
  class RuleItemContext;
  class RuleFileNameContext;
  class RuleIDContext; 

  class  RootContext : public antlr4::ParserRuleContext {
  public:
    RootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RuleBindingContext *ruleBinding();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RootContext* root();

  class  RuleBindingContext : public antlr4::ParserRuleContext {
  public:
    RuleBindingContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RULES();
    antlr4::tree::TerminalNode *L_CURLY();
    BindingListContext *bindingList();
    antlr4::tree::TerminalNode *R_CURLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RuleBindingContext* ruleBinding();

  class  BindingListContext : public antlr4::ParserRuleContext {
  public:
    BindingListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EventToRulesContext *> eventToRules();
    EventToRulesContext* eventToRules(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMI();
    antlr4::tree::TerminalNode* SEMI(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BindingListContext* bindingList();

  class  EventToRulesContext : public antlr4::ParserRuleContext {
  public:
    EventToRulesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EventContext *event();
    antlr4::tree::TerminalNode *MAP();
    antlr4::tree::TerminalNode *L_BRACKET();
    RuleListContext *ruleList();
    antlr4::tree::TerminalNode *R_BRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EventToRulesContext* eventToRules();

  class  EventContext : public antlr4::ParserRuleContext {
  public:
    EventContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  EventContext* event();

  class  RuleListContext : public antlr4::ParserRuleContext {
  public:
    RuleListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RuleItemContext *> ruleItem();
    RuleItemContext* ruleItem(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RuleListContext* ruleList();

  class  RuleItemContext : public antlr4::ParserRuleContext {
  public:
    RuleItemContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RuleFileNameContext *ruleFileName();
    antlr4::tree::TerminalNode *DOT();
    RuleIDContext *ruleID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RuleItemContext* ruleItem();

  class  RuleFileNameContext : public antlr4::ParserRuleContext {
  public:
    RuleFileNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RuleFileNameContext* ruleFileName();

  class  RuleIDContext : public antlr4::ParserRuleContext {
  public:
    RuleIDContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RuleIDContext* ruleID();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

