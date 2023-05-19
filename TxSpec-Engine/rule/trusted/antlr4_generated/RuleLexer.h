
// Generated from RuleLexer.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  RuleLexer : public antlr4::Lexer {
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

  explicit RuleLexer(antlr4::CharStream *input);
  ~RuleLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

