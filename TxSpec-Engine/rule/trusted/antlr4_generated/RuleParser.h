
// Generated from RuleParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  RuleParser : public antlr4::Parser {
public:
  enum {
    REGULATION = 1, ENTITIES = 2, RULES = 3, REFERENCES = 4, ENTITY = 5, 
    ARTICLE = 6, RULE = 7, NUMBER = 8, STRING = 9, BOOLEAN = 10, DATE = 11, 
    SET = 12, YEAR = 13, MONTH = 14, DAY = 15, HOUR = 16, MINUTE = 17, SECOND = 18, 
    ALIAS = 19, STATE = 20, EVENT = 21, ELSE = 22, IF = 23, THEN = 24, L_PAREN = 25, 
    R_PAREN = 26, L_CURLY = 27, R_CURLY = 28, L_BRACKET = 29, R_BRACKET = 30, 
    ASSIGN = 31, COMMA = 32, SEMI = 33, COLON = 34, DOT = 35, LOGICAL_OR = 36, 
    LOGICAL_AND = 37, LOGICAL_NOT = 38, SET_IN = 39, SET_NOT_IN = 40, SET_UNION = 41, 
    SET_INTERSECT = 42, EQUALS = 43, NOT_EQUALS = 44, LESS_THAN = 45, LESS_OR_EQUALS = 46, 
    GREATER_THAN = 47, GREATER_OR_EQUALS = 48, PLUS = 49, MINUS = 50, MULTIPLY = 51, 
    DIVIDE = 52, MODULO = 53, IS = 54, WITHIN = 55, BEFORE = 56, AFTER = 57, 
    FOLLOW = 58, ACCUMULATE = 59, COUNT = 60, ON = 61, PROVIDED = 62, WHERE = 63, 
    BOOLEAN_LIT = 64, DECIMAL_LIT = 65, DECIMAL_FLOAT_LIT = 66, DATE_LIT = 67, 
    TIME_LIT = 68, RUNE_LIT = 69, BYTE_VALUE = 70, OCTAL_BYTE_VALUE = 71, 
    HEX_BYTE_VALUE = 72, LITTLE_U_VALUE = 73, BIG_U_VALUE = 74, RAW_STRING_LIT = 75, 
    INTERPRETED_STRING_LIT = 76, IDENTIFIER = 77, WS = 78, COMMENT = 79, 
    TERMINATOR = 80, LINE_COMMENT = 81
  };

  enum {
    RuleRoot = 0, RuleRegulationDecl = 1, RuleEntitiesBlock = 2, RuleEntityList = 3, 
    RuleEntityDecl = 4, RuleEntityName = 5, RuleAttributeList = 6, RuleAttributeDecl = 7, 
    RuleAttributeName = 8, RuleTypeAnno = 9, RuleBasicType = 10, RuleCompositeType = 11, 
    RuleSetType = 12, RuleRulesBlock = 13, RuleRuleList = 14, RuleBasicRule = 15, 
    RuleRuleName = 16, RuleRuleStmtList = 17, RuleRuleStmt = 18, RuleSimpleStmt = 19, 
    RuleComplexStmt = 20, RuleSetStmt = 21, RuleSetExpr = 22, RuleRelationStmt = 23, 
    RuleRelationExpr = 24, RuleNumberExpr = 25, RuleSelectorIdent = 26, 
    RuleAggregationExpr = 27, RuleBooleanExpr = 28, RuleLogicalStmt = 29, 
    RuleLogicalExpr = 30, RuleIfStmt = 31, RuleSequentialStmt = 32, RuleSequentialExpr = 33, 
    RuleDateStmt = 34, RuleDateExpr = 35, RuleTimeStmt = 36, RuleTimeExpr = 37, 
    RuleEos = 38
  };

  explicit RuleParser(antlr4::TokenStream *input);
  ~RuleParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class RootContext;
  class RegulationDeclContext;
  class EntitiesBlockContext;
  class EntityListContext;
  class EntityDeclContext;
  class EntityNameContext;
  class AttributeListContext;
  class AttributeDeclContext;
  class AttributeNameContext;
  class TypeAnnoContext;
  class BasicTypeContext;
  class CompositeTypeContext;
  class SetTypeContext;
  class RulesBlockContext;
  class RuleListContext;
  class BasicRuleContext;
  class RuleNameContext;
  class RuleStmtListContext;
  class RuleStmtContext;
  class SimpleStmtContext;
  class ComplexStmtContext;
  class SetStmtContext;
  class SetExprContext;
  class RelationStmtContext;
  class RelationExprContext;
  class NumberExprContext;
  class SelectorIdentContext;
  class AggregationExprContext;
  class BooleanExprContext;
  class LogicalStmtContext;
  class LogicalExprContext;
  class IfStmtContext;
  class SequentialStmtContext;
  class SequentialExprContext;
  class DateStmtContext;
  class DateExprContext;
  class TimeStmtContext;
  class TimeExprContext;
  class EosContext; 

  class  RootContext : public antlr4::ParserRuleContext {
  public:
    RootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RegulationDeclContext *regulationDecl();
    EntitiesBlockContext *entitiesBlock();
    RulesBlockContext *rulesBlock();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RootContext* root();

  class  RegulationDeclContext : public antlr4::ParserRuleContext {
  public:
    RegulationDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REGULATION();
    std::vector<antlr4::tree::TerminalNode *> IDENTIFIER();
    antlr4::tree::TerminalNode* IDENTIFIER(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DOT();
    antlr4::tree::TerminalNode* DOT(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RegulationDeclContext* regulationDecl();

  class  EntitiesBlockContext : public antlr4::ParserRuleContext {
  public:
    EntitiesBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ENTITIES();
    antlr4::tree::TerminalNode *L_CURLY();
    EntityListContext *entityList();
    antlr4::tree::TerminalNode *R_CURLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EntitiesBlockContext* entitiesBlock();

  class  EntityListContext : public antlr4::ParserRuleContext {
  public:
    EntityListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ENTITY();
    antlr4::tree::TerminalNode* ENTITY(size_t i);
    std::vector<EntityDeclContext *> entityDecl();
    EntityDeclContext* entityDecl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EntityListContext* entityList();

  class  EntityDeclContext : public antlr4::ParserRuleContext {
  public:
    EntityDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EntityNameContext *entityName();
    antlr4::tree::TerminalNode *L_CURLY();
    AttributeListContext *attributeList();
    antlr4::tree::TerminalNode *R_CURLY();
    antlr4::tree::TerminalNode *IS();
    CompositeTypeContext *compositeType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EntityDeclContext* entityDecl();

  class  EntityNameContext : public antlr4::ParserRuleContext {
  public:
    EntityNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EntityNameContext* entityName();

  class  AttributeListContext : public antlr4::ParserRuleContext {
  public:
    AttributeListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AttributeDeclContext *> attributeDecl();
    AttributeDeclContext* attributeDecl(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttributeListContext* attributeList();

  class  AttributeDeclContext : public antlr4::ParserRuleContext {
  public:
    AttributeDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    AttributeNameContext *attributeName();
    antlr4::tree::TerminalNode *IS();
    TypeAnnoContext *typeAnno();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttributeDeclContext* attributeDecl();

  class  AttributeNameContext : public antlr4::ParserRuleContext {
  public:
    AttributeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AttributeNameContext* attributeName();

  class  TypeAnnoContext : public antlr4::ParserRuleContext {
  public:
    TypeAnnoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CompositeTypeContext *compositeType();
    BasicTypeContext *basicType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeAnnoContext* typeAnno();

  class  BasicTypeContext : public antlr4::ParserRuleContext {
  public:
    BasicTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *STRING();
    antlr4::tree::TerminalNode *DATE();
    antlr4::tree::TerminalNode *BOOLEAN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BasicTypeContext* basicType();

  class  CompositeTypeContext : public antlr4::ParserRuleContext {
  public:
    CompositeTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SetTypeContext *setType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompositeTypeContext* compositeType();

  class  SetTypeContext : public antlr4::ParserRuleContext {
  public:
    SetTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SET();
    antlr4::tree::TerminalNode *L_BRACKET();
    antlr4::tree::TerminalNode *R_BRACKET();
    antlr4::tree::TerminalNode *IDENTIFIER();
    BasicTypeContext *basicType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetTypeContext* setType();

  class  RulesBlockContext : public antlr4::ParserRuleContext {
  public:
    RulesBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RULES();
    antlr4::tree::TerminalNode *L_CURLY();
    RuleListContext *ruleList();
    antlr4::tree::TerminalNode *R_CURLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RulesBlockContext* rulesBlock();

  class  RuleListContext : public antlr4::ParserRuleContext {
  public:
    RuleListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<BasicRuleContext *> basicRule();
    BasicRuleContext* basicRule(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleListContext* ruleList();

  class  BasicRuleContext : public antlr4::ParserRuleContext {
  public:
    BasicRuleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RULE();
    RuleNameContext *ruleName();
    antlr4::tree::TerminalNode *L_CURLY();
    RuleStmtListContext *ruleStmtList();
    antlr4::tree::TerminalNode *R_CURLY();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BasicRuleContext* basicRule();

  class  RuleNameContext : public antlr4::ParserRuleContext {
  public:
    RuleNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleNameContext* ruleName();

  class  RuleStmtListContext : public antlr4::ParserRuleContext {
  public:
    RuleStmtListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<RuleStmtContext *> ruleStmt();
    RuleStmtContext* ruleStmt(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleStmtListContext* ruleStmtList();

  class  RuleStmtContext : public antlr4::ParserRuleContext {
  public:
    RuleStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpleStmtContext *simpleStmt();
    ComplexStmtContext *complexStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RuleStmtContext* ruleStmt();

  class  SimpleStmtContext : public antlr4::ParserRuleContext {
  public:
    SimpleStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SetStmtContext *setStmt();
    RelationStmtContext *relationStmt();
    LogicalStmtContext *logicalStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleStmtContext* simpleStmt();

  class  ComplexStmtContext : public antlr4::ParserRuleContext {
  public:
    ComplexStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IfStmtContext *ifStmt();
    SequentialStmtContext *sequentialStmt();
    DateStmtContext *dateStmt();
    TimeStmtContext *timeStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ComplexStmtContext* complexStmt();

  class  SetStmtContext : public antlr4::ParserRuleContext {
  public:
    SetStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SetExprContext *setExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetStmtContext* setStmt();

  class  SetExprContext : public antlr4::ParserRuleContext {
  public:
    SetExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_PAREN();
    SetExprContext *setExpr();
    antlr4::tree::TerminalNode *R_PAREN();
    SelectorIdentContext *selectorIdent();
    EntityNameContext *entityName();
    antlr4::tree::TerminalNode *SET_IN();
    antlr4::tree::TerminalNode *SET_NOT_IN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SetExprContext* setExpr();

  class  RelationStmtContext : public antlr4::ParserRuleContext {
  public:
    RelationStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RelationExprContext *relationExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationStmtContext* relationStmt();

  class  RelationExprContext : public antlr4::ParserRuleContext {
  public:
    RelationExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_PAREN();
    RelationExprContext *relationExpr();
    antlr4::tree::TerminalNode *R_PAREN();
    std::vector<NumberExprContext *> numberExpr();
    NumberExprContext* numberExpr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUALS();
    antlr4::tree::TerminalNode* EQUALS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NOT_EQUALS();
    antlr4::tree::TerminalNode* NOT_EQUALS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LESS_THAN();
    antlr4::tree::TerminalNode* LESS_THAN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LESS_OR_EQUALS();
    antlr4::tree::TerminalNode* LESS_OR_EQUALS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GREATER_THAN();
    antlr4::tree::TerminalNode* GREATER_THAN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> GREATER_OR_EQUALS();
    antlr4::tree::TerminalNode* GREATER_OR_EQUALS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelationExprContext* relationExpr();

  class  NumberExprContext : public antlr4::ParserRuleContext {
  public:
    NumberExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_PAREN();
    std::vector<NumberExprContext *> numberExpr();
    NumberExprContext* numberExpr(size_t i);
    antlr4::tree::TerminalNode *R_PAREN();
    SelectorIdentContext *selectorIdent();
    antlr4::tree::TerminalNode *DECIMAL_LIT();
    antlr4::tree::TerminalNode *DECIMAL_FLOAT_LIT();
    AggregationExprContext *aggregationExpr();
    antlr4::tree::TerminalNode *MULTIPLY();
    antlr4::tree::TerminalNode *DIVIDE();
    antlr4::tree::TerminalNode *MODULO();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberExprContext* numberExpr();
  NumberExprContext* numberExpr(int precedence);
  class  SelectorIdentContext : public antlr4::ParserRuleContext {
  public:
    SelectorIdentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EntityNameContext *entityName();
    antlr4::tree::TerminalNode *DOT();
    AttributeNameContext *attributeName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectorIdentContext* selectorIdent();

  class  AggregationExprContext : public antlr4::ParserRuleContext {
  public:
    AggregationExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACCUMULATE();
    NumberExprContext *numberExpr();
    antlr4::tree::TerminalNode *ON();
    EntityNameContext *entityName();
    antlr4::tree::TerminalNode *WITHIN();
    antlr4::tree::TerminalNode *TIME_LIT();
    antlr4::tree::TerminalNode *PROVIDED();
    std::vector<SelectorIdentContext *> selectorIdent();
    SelectorIdentContext* selectorIdent(size_t i);
    antlr4::tree::TerminalNode *WHERE();
    BooleanExprContext *booleanExpr();
    std::vector<antlr4::tree::TerminalNode *> LOGICAL_AND();
    antlr4::tree::TerminalNode* LOGICAL_AND(size_t i);
    antlr4::tree::TerminalNode *COUNT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AggregationExprContext* aggregationExpr();

  class  BooleanExprContext : public antlr4::ParserRuleContext {
  public:
    BooleanExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_PAREN();
    BooleanExprContext *booleanExpr();
    antlr4::tree::TerminalNode *R_PAREN();
    antlr4::tree::TerminalNode *BOOLEAN_LIT();
    SelectorIdentContext *selectorIdent();
    SetExprContext *setExpr();
    RelationExprContext *relationExpr();
    LogicalExprContext *logicalExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanExprContext* booleanExpr();

  class  LogicalStmtContext : public antlr4::ParserRuleContext {
  public:
    LogicalStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LogicalExprContext *logicalExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalStmtContext* logicalStmt();

  class  LogicalExprContext : public antlr4::ParserRuleContext {
  public:
    LogicalExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_PAREN();
    antlr4::tree::TerminalNode *LOGICAL_NOT();
    antlr4::tree::TerminalNode *R_PAREN();
    std::vector<antlr4::tree::TerminalNode *> BOOLEAN_LIT();
    antlr4::tree::TerminalNode* BOOLEAN_LIT(size_t i);
    std::vector<SelectorIdentContext *> selectorIdent();
    SelectorIdentContext* selectorIdent(size_t i);
    antlr4::tree::TerminalNode *LOGICAL_AND();
    antlr4::tree::TerminalNode *LOGICAL_OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LogicalExprContext* logicalExpr();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    BooleanExprContext *booleanExpr();
    antlr4::tree::TerminalNode *THEN();
    std::vector<antlr4::tree::TerminalNode *> L_CURLY();
    antlr4::tree::TerminalNode* L_CURLY(size_t i);
    std::vector<RuleStmtListContext *> ruleStmtList();
    RuleStmtListContext* ruleStmtList(size_t i);
    std::vector<antlr4::tree::TerminalNode *> R_CURLY();
    antlr4::tree::TerminalNode* R_CURLY(size_t i);
    antlr4::tree::TerminalNode *ELSE();
    IfStmtContext *ifStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStmtContext* ifStmt();

  class  SequentialStmtContext : public antlr4::ParserRuleContext {
  public:
    SequentialStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SequentialExprContext *sequentialExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SequentialStmtContext* sequentialStmt();

  class  SequentialExprContext : public antlr4::ParserRuleContext {
  public:
    SequentialExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<EntityNameContext *> entityName();
    EntityNameContext* entityName(size_t i);
    antlr4::tree::TerminalNode *BEFORE();
    antlr4::tree::TerminalNode *AFTER();
    antlr4::tree::TerminalNode *FOLLOW();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SequentialExprContext* sequentialExpr();

  class  DateStmtContext : public antlr4::ParserRuleContext {
  public:
    DateStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DateExprContext *dateExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DateStmtContext* dateStmt();

  class  DateExprContext : public antlr4::ParserRuleContext {
  public:
    DateExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanExprContext *booleanExpr();
    antlr4::tree::TerminalNode *DATE_LIT();
    antlr4::tree::TerminalNode *BEFORE();
    antlr4::tree::TerminalNode *AFTER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DateExprContext* dateExpr();

  class  TimeStmtContext : public antlr4::ParserRuleContext {
  public:
    TimeStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TimeExprContext *timeExpr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimeStmtContext* timeStmt();

  class  TimeExprContext : public antlr4::ParserRuleContext {
  public:
    TimeExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BooleanExprContext *booleanExpr();
    antlr4::tree::TerminalNode *WITHIN();
    antlr4::tree::TerminalNode *TIME_LIT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TimeExprContext* timeExpr();

  class  EosContext : public antlr4::ParserRuleContext {
  public:
    EosContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *TERMINATOR();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EosContext* eos();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool numberExprSempred(NumberExprContext *_localctx, size_t predicateIndex);

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

