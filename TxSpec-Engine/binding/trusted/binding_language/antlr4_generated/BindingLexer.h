
// Generated from BindingLexer.g4 by ANTLR 4.9.3

#pragma once


#include "antlr4-runtime.h"




class  BindingLexer : public antlr4::Lexer {
public:
  enum {
    RULES = 1, L_CURLY = 2, R_CURLY = 3, L_BRACKET = 4, R_BRACKET = 5, MAP = 6, 
    DOT = 7, COMMA = 8, SEMI = 9, WS = 10, COMMENT = 11, TERMINATOR = 12, 
    LINE_COMMENT = 13, IDENTIFIER = 14
  };

  explicit BindingLexer(antlr4::CharStream *input);
  ~BindingLexer();

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

