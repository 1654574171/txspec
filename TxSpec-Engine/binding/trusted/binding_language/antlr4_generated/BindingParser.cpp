
// Generated from BindingParser.g4 by ANTLR 4.9.3


#include "BindingParserListener.h"

#include "BindingParser.h"


using namespace antlrcpp;
using namespace antlr4;

BindingParser::BindingParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

BindingParser::~BindingParser() {
  delete _interpreter;
}

std::string BindingParser::getGrammarFileName() const {
  return "BindingParser.g4";
}

const std::vector<std::string>& BindingParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& BindingParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- RootContext ------------------------------------------------------------------

BindingParser::RootContext::RootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BindingParser::RuleBindingContext* BindingParser::RootContext::ruleBinding() {
  return getRuleContext<BindingParser::RuleBindingContext>(0);
}

tree::TerminalNode* BindingParser::RootContext::EOF() {
  return getToken(BindingParser::EOF, 0);
}


size_t BindingParser::RootContext::getRuleIndex() const {
  return BindingParser::RuleRoot;
}

void BindingParser::RootContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRoot(this);
}

void BindingParser::RootContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRoot(this);
}

BindingParser::RootContext* BindingParser::root() {
  RootContext *_localctx = _tracker.createInstance<RootContext>(_ctx, getState());
  enterRule(_localctx, 0, BindingParser::RuleRoot);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    ruleBinding();
    setState(19);
    match(BindingParser::EOF);
   
  }
  catch (RecognitionException &e) {
    // _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleBindingContext ------------------------------------------------------------------

BindingParser::RuleBindingContext::RuleBindingContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BindingParser::RuleBindingContext::RULES() {
  return getToken(BindingParser::RULES, 0);
}

tree::TerminalNode* BindingParser::RuleBindingContext::L_CURLY() {
  return getToken(BindingParser::L_CURLY, 0);
}

BindingParser::BindingListContext* BindingParser::RuleBindingContext::bindingList() {
  return getRuleContext<BindingParser::BindingListContext>(0);
}

tree::TerminalNode* BindingParser::RuleBindingContext::R_CURLY() {
  return getToken(BindingParser::R_CURLY, 0);
}


size_t BindingParser::RuleBindingContext::getRuleIndex() const {
  return BindingParser::RuleRuleBinding;
}

void BindingParser::RuleBindingContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleBinding(this);
}

void BindingParser::RuleBindingContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleBinding(this);
}

BindingParser::RuleBindingContext* BindingParser::ruleBinding() {
  RuleBindingContext *_localctx = _tracker.createInstance<RuleBindingContext>(_ctx, getState());
  enterRule(_localctx, 2, BindingParser::RuleRuleBinding);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    match(BindingParser::RULES);
    setState(22);
    match(BindingParser::L_CURLY);
    setState(23);
    bindingList();
    setState(24);
    match(BindingParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    // _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BindingListContext ------------------------------------------------------------------

BindingParser::BindingListContext::BindingListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BindingParser::EventToRulesContext *> BindingParser::BindingListContext::eventToRules() {
  return getRuleContexts<BindingParser::EventToRulesContext>();
}

BindingParser::EventToRulesContext* BindingParser::BindingListContext::eventToRules(size_t i) {
  return getRuleContext<BindingParser::EventToRulesContext>(i);
}

std::vector<tree::TerminalNode *> BindingParser::BindingListContext::SEMI() {
  return getTokens(BindingParser::SEMI);
}

tree::TerminalNode* BindingParser::BindingListContext::SEMI(size_t i) {
  return getToken(BindingParser::SEMI, i);
}


size_t BindingParser::BindingListContext::getRuleIndex() const {
  return BindingParser::RuleBindingList;
}

void BindingParser::BindingListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBindingList(this);
}

void BindingParser::BindingListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBindingList(this);
}

BindingParser::BindingListContext* BindingParser::bindingList() {
  BindingListContext *_localctx = _tracker.createInstance<BindingListContext>(_ctx, getState());
  enterRule(_localctx, 4, BindingParser::RuleBindingList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(29); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(26);
      eventToRules();
      setState(27);
      match(BindingParser::SEMI);
      setState(31); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == BindingParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    // _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EventToRulesContext ------------------------------------------------------------------

BindingParser::EventToRulesContext::EventToRulesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BindingParser::EventContext* BindingParser::EventToRulesContext::event() {
  return getRuleContext<BindingParser::EventContext>(0);
}

tree::TerminalNode* BindingParser::EventToRulesContext::MAP() {
  return getToken(BindingParser::MAP, 0);
}

tree::TerminalNode* BindingParser::EventToRulesContext::L_BRACKET() {
  return getToken(BindingParser::L_BRACKET, 0);
}

BindingParser::RuleListContext* BindingParser::EventToRulesContext::ruleList() {
  return getRuleContext<BindingParser::RuleListContext>(0);
}

tree::TerminalNode* BindingParser::EventToRulesContext::R_BRACKET() {
  return getToken(BindingParser::R_BRACKET, 0);
}


size_t BindingParser::EventToRulesContext::getRuleIndex() const {
  return BindingParser::RuleEventToRules;
}

void BindingParser::EventToRulesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEventToRules(this);
}

void BindingParser::EventToRulesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEventToRules(this);
}

BindingParser::EventToRulesContext* BindingParser::eventToRules() {
  EventToRulesContext *_localctx = _tracker.createInstance<EventToRulesContext>(_ctx, getState());
  enterRule(_localctx, 6, BindingParser::RuleEventToRules);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    event();
    setState(34);
    match(BindingParser::MAP);
    setState(35);
    match(BindingParser::L_BRACKET);
    setState(36);
    ruleList();
    setState(37);
    match(BindingParser::R_BRACKET);
   
  }
  catch (RecognitionException &e) {
    // _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EventContext ------------------------------------------------------------------

BindingParser::EventContext::EventContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BindingParser::EventContext::IDENTIFIER() {
  return getToken(BindingParser::IDENTIFIER, 0);
}


size_t BindingParser::EventContext::getRuleIndex() const {
  return BindingParser::RuleEvent;
}

void BindingParser::EventContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEvent(this);
}

void BindingParser::EventContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEvent(this);
}

BindingParser::EventContext* BindingParser::event() {
  EventContext *_localctx = _tracker.createInstance<EventContext>(_ctx, getState());
  enterRule(_localctx, 8, BindingParser::RuleEvent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(39);
    match(BindingParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    // _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleListContext ------------------------------------------------------------------

BindingParser::RuleListContext::RuleListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BindingParser::RuleItemContext *> BindingParser::RuleListContext::ruleItem() {
  return getRuleContexts<BindingParser::RuleItemContext>();
}

BindingParser::RuleItemContext* BindingParser::RuleListContext::ruleItem(size_t i) {
  return getRuleContext<BindingParser::RuleItemContext>(i);
}

std::vector<tree::TerminalNode *> BindingParser::RuleListContext::COMMA() {
  return getTokens(BindingParser::COMMA);
}

tree::TerminalNode* BindingParser::RuleListContext::COMMA(size_t i) {
  return getToken(BindingParser::COMMA, i);
}


size_t BindingParser::RuleListContext::getRuleIndex() const {
  return BindingParser::RuleRuleList;
}

void BindingParser::RuleListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleList(this);
}

void BindingParser::RuleListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleList(this);
}

BindingParser::RuleListContext* BindingParser::ruleList() {
  RuleListContext *_localctx = _tracker.createInstance<RuleListContext>(_ctx, getState());
  enterRule(_localctx, 10, BindingParser::RuleRuleList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(51);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(41);
      ruleItem();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(45); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(42);
                ruleItem();
                setState(43);
                match(BindingParser::COMMA);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(47); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(49);
      ruleItem();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    // _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleItemContext ------------------------------------------------------------------

BindingParser::RuleItemContext::RuleItemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BindingParser::RuleFileNameContext* BindingParser::RuleItemContext::ruleFileName() {
  return getRuleContext<BindingParser::RuleFileNameContext>(0);
}

tree::TerminalNode* BindingParser::RuleItemContext::DOT() {
  return getToken(BindingParser::DOT, 0);
}

BindingParser::RuleIDContext* BindingParser::RuleItemContext::ruleID() {
  return getRuleContext<BindingParser::RuleIDContext>(0);
}


size_t BindingParser::RuleItemContext::getRuleIndex() const {
  return BindingParser::RuleRuleItem;
}

void BindingParser::RuleItemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleItem(this);
}

void BindingParser::RuleItemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleItem(this);
}

BindingParser::RuleItemContext* BindingParser::ruleItem() {
  RuleItemContext *_localctx = _tracker.createInstance<RuleItemContext>(_ctx, getState());
  enterRule(_localctx, 12, BindingParser::RuleRuleItem);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    ruleFileName();
    setState(54);
    match(BindingParser::DOT);
    setState(55);
    ruleID();
   
  }
  catch (RecognitionException &e) {
    // _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleFileNameContext ------------------------------------------------------------------

BindingParser::RuleFileNameContext::RuleFileNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BindingParser::RuleFileNameContext::IDENTIFIER() {
  return getToken(BindingParser::IDENTIFIER, 0);
}


size_t BindingParser::RuleFileNameContext::getRuleIndex() const {
  return BindingParser::RuleRuleFileName;
}

void BindingParser::RuleFileNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleFileName(this);
}

void BindingParser::RuleFileNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleFileName(this);
}

BindingParser::RuleFileNameContext* BindingParser::ruleFileName() {
  RuleFileNameContext *_localctx = _tracker.createInstance<RuleFileNameContext>(_ctx, getState());
  enterRule(_localctx, 14, BindingParser::RuleRuleFileName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(BindingParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    // _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleIDContext ------------------------------------------------------------------

BindingParser::RuleIDContext::RuleIDContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BindingParser::RuleIDContext::IDENTIFIER() {
  return getToken(BindingParser::IDENTIFIER, 0);
}


size_t BindingParser::RuleIDContext::getRuleIndex() const {
  return BindingParser::RuleRuleID;
}

void BindingParser::RuleIDContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleID(this);
}

void BindingParser::RuleIDContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BindingParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleID(this);
}

BindingParser::RuleIDContext* BindingParser::ruleID() {
  RuleIDContext *_localctx = _tracker.createInstance<RuleIDContext>(_ctx, getState());
  enterRule(_localctx, 16, BindingParser::RuleRuleID);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(59);
    match(BindingParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    // _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> BindingParser::_decisionToDFA;
atn::PredictionContextCache BindingParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN BindingParser::_atn;
std::vector<uint16_t> BindingParser::_serializedATN;

std::vector<std::string> BindingParser::_ruleNames = {
  "root", "ruleBinding", "bindingList", "eventToRules", "event", "ruleList", 
  "ruleItem", "ruleFileName", "ruleID"
};

std::vector<std::string> BindingParser::_literalNames = {
  "", "", "'{'", "'}'", "'['", "']'", "'->'", "'.'", "','", "';'"
};

std::vector<std::string> BindingParser::_symbolicNames = {
  "", "RULES", "L_CURLY", "R_CURLY", "L_BRACKET", "R_BRACKET", "MAP", "DOT", 
  "COMMA", "SEMI", "WS", "COMMENT", "TERMINATOR", "LINE_COMMENT", "IDENTIFIER"
};

dfa::Vocabulary BindingParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> BindingParser::_tokenNames;

BindingParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x10, 0x40, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 0x20, 0xa, 
       0x4, 0xd, 0x4, 0xe, 0x4, 0x21, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
       0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x30, 0xa, 0x7, 0xd, 0x7, 0xe, 0x7, 
       0x31, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x36, 0xa, 0x7, 0x3, 0x8, 0x3, 
       0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x2, 0x2, 0xb, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
       0x12, 0x2, 0x2, 0x2, 0x39, 0x2, 0x14, 0x3, 0x2, 0x2, 0x2, 0x4, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x6, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x23, 0x3, 
       0x2, 0x2, 0x2, 0xa, 0x29, 0x3, 0x2, 0x2, 0x2, 0xc, 0x35, 0x3, 0x2, 
       0x2, 0x2, 0xe, 0x37, 0x3, 0x2, 0x2, 0x2, 0x10, 0x3b, 0x3, 0x2, 0x2, 
       0x2, 0x12, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x14, 0x15, 0x5, 0x4, 0x3, 0x2, 
       0x15, 0x16, 0x7, 0x2, 0x2, 0x3, 0x16, 0x3, 0x3, 0x2, 0x2, 0x2, 0x17, 
       0x18, 0x7, 0x3, 0x2, 0x2, 0x18, 0x19, 0x7, 0x4, 0x2, 0x2, 0x19, 0x1a, 
       0x5, 0x6, 0x4, 0x2, 0x1a, 0x1b, 0x7, 0x5, 0x2, 0x2, 0x1b, 0x5, 0x3, 
       0x2, 0x2, 0x2, 0x1c, 0x1d, 0x5, 0x8, 0x5, 0x2, 0x1d, 0x1e, 0x7, 0xb, 
       0x2, 0x2, 0x1e, 0x20, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x1c, 0x3, 0x2, 0x2, 
       0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x1f, 0x3, 0x2, 0x2, 0x2, 
       0x21, 0x22, 0x3, 0x2, 0x2, 0x2, 0x22, 0x7, 0x3, 0x2, 0x2, 0x2, 0x23, 
       0x24, 0x5, 0xa, 0x6, 0x2, 0x24, 0x25, 0x7, 0x8, 0x2, 0x2, 0x25, 0x26, 
       0x7, 0x6, 0x2, 0x2, 0x26, 0x27, 0x5, 0xc, 0x7, 0x2, 0x27, 0x28, 0x7, 
       0x7, 0x2, 0x2, 0x28, 0x9, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x10, 
       0x2, 0x2, 0x2a, 0xb, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x36, 0x5, 0xe, 0x8, 
       0x2, 0x2c, 0x2d, 0x5, 0xe, 0x8, 0x2, 0x2d, 0x2e, 0x7, 0xa, 0x2, 0x2, 
       0x2e, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x30, 
       0x31, 0x3, 0x2, 0x2, 0x2, 0x31, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 
       0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 0x34, 0x5, 
       0xe, 0x8, 0x2, 0x34, 0x36, 0x3, 0x2, 0x2, 0x2, 0x35, 0x2b, 0x3, 0x2, 
       0x2, 0x2, 0x35, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x36, 0xd, 0x3, 0x2, 0x2, 
       0x2, 0x37, 0x38, 0x5, 0x10, 0x9, 0x2, 0x38, 0x39, 0x7, 0x9, 0x2, 
       0x2, 0x39, 0x3a, 0x5, 0x12, 0xa, 0x2, 0x3a, 0xf, 0x3, 0x2, 0x2, 0x2, 
       0x3b, 0x3c, 0x7, 0x10, 0x2, 0x2, 0x3c, 0x11, 0x3, 0x2, 0x2, 0x2, 
       0x3d, 0x3e, 0x7, 0x10, 0x2, 0x2, 0x3e, 0x13, 0x3, 0x2, 0x2, 0x2, 
       0x5, 0x21, 0x31, 0x35, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

BindingParser::Initializer BindingParser::_init;
