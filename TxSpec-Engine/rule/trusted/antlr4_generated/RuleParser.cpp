
// Generated from RuleParser.g4 by ANTLR 4.9.1


#include "RuleParserListener.h"
#include "RuleParserVisitor.h"

#include "RuleParser.h"


using namespace antlrcpp;
using namespace antlr4;

RuleParser::RuleParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

RuleParser::~RuleParser() {
  delete _interpreter;
}

std::string RuleParser::getGrammarFileName() const {
  return "RuleParser.g4";
}

const std::vector<std::string>& RuleParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& RuleParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- RootContext ------------------------------------------------------------------

RuleParser::RootContext::RootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::RegulationDeclContext* RuleParser::RootContext::regulationDecl() {
  return getRuleContext<RuleParser::RegulationDeclContext>(0);
}

RuleParser::EntitiesBlockContext* RuleParser::RootContext::entitiesBlock() {
  return getRuleContext<RuleParser::EntitiesBlockContext>(0);
}

RuleParser::RulesBlockContext* RuleParser::RootContext::rulesBlock() {
  return getRuleContext<RuleParser::RulesBlockContext>(0);
}

tree::TerminalNode* RuleParser::RootContext::EOF() {
  return getToken(RuleParser::EOF, 0);
}


size_t RuleParser::RootContext::getRuleIndex() const {
  return RuleParser::RuleRoot;
}

void RuleParser::RootContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRoot(this);
}

void RuleParser::RootContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRoot(this);
}


antlrcpp::Any RuleParser::RootContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRoot(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RootContext* RuleParser::root() {
  RootContext *_localctx = _tracker.createInstance<RootContext>(_ctx, getState());
  enterRule(_localctx, 0, RuleParser::RuleRoot);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    regulationDecl();
    setState(79);
    entitiesBlock();
    setState(80);
    rulesBlock();
    setState(81);
    match(RuleParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RegulationDeclContext ------------------------------------------------------------------

RuleParser::RegulationDeclContext::RegulationDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::RegulationDeclContext::REGULATION() {
  return getToken(RuleParser::REGULATION, 0);
}

std::vector<tree::TerminalNode *> RuleParser::RegulationDeclContext::IDENTIFIER() {
  return getTokens(RuleParser::IDENTIFIER);
}

tree::TerminalNode* RuleParser::RegulationDeclContext::IDENTIFIER(size_t i) {
  return getToken(RuleParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> RuleParser::RegulationDeclContext::DOT() {
  return getTokens(RuleParser::DOT);
}

tree::TerminalNode* RuleParser::RegulationDeclContext::DOT(size_t i) {
  return getToken(RuleParser::DOT, i);
}


size_t RuleParser::RegulationDeclContext::getRuleIndex() const {
  return RuleParser::RuleRegulationDecl;
}

void RuleParser::RegulationDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRegulationDecl(this);
}

void RuleParser::RegulationDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRegulationDecl(this);
}


antlrcpp::Any RuleParser::RegulationDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRegulationDecl(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RegulationDeclContext* RuleParser::regulationDecl() {
  RegulationDeclContext *_localctx = _tracker.createInstance<RegulationDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, RuleParser::RuleRegulationDecl);
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
    setState(83);
    match(RuleParser::REGULATION);
    setState(84);
    match(RuleParser::IDENTIFIER);
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RuleParser::DOT) {
      setState(85);
      match(RuleParser::DOT);
      setState(86);
      match(RuleParser::IDENTIFIER);
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntitiesBlockContext ------------------------------------------------------------------

RuleParser::EntitiesBlockContext::EntitiesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::EntitiesBlockContext::ENTITIES() {
  return getToken(RuleParser::ENTITIES, 0);
}

tree::TerminalNode* RuleParser::EntitiesBlockContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

RuleParser::EntityListContext* RuleParser::EntitiesBlockContext::entityList() {
  return getRuleContext<RuleParser::EntityListContext>(0);
}

tree::TerminalNode* RuleParser::EntitiesBlockContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}


size_t RuleParser::EntitiesBlockContext::getRuleIndex() const {
  return RuleParser::RuleEntitiesBlock;
}

void RuleParser::EntitiesBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntitiesBlock(this);
}

void RuleParser::EntitiesBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntitiesBlock(this);
}


antlrcpp::Any RuleParser::EntitiesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitEntitiesBlock(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::EntitiesBlockContext* RuleParser::entitiesBlock() {
  EntitiesBlockContext *_localctx = _tracker.createInstance<EntitiesBlockContext>(_ctx, getState());
  enterRule(_localctx, 4, RuleParser::RuleEntitiesBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    match(RuleParser::ENTITIES);
    setState(93);
    match(RuleParser::L_CURLY);
    setState(94);
    entityList();
    setState(95);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntityListContext ------------------------------------------------------------------

RuleParser::EntityListContext::EntityListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> RuleParser::EntityListContext::ENTITY() {
  return getTokens(RuleParser::ENTITY);
}

tree::TerminalNode* RuleParser::EntityListContext::ENTITY(size_t i) {
  return getToken(RuleParser::ENTITY, i);
}

std::vector<RuleParser::EntityDeclContext *> RuleParser::EntityListContext::entityDecl() {
  return getRuleContexts<RuleParser::EntityDeclContext>();
}

RuleParser::EntityDeclContext* RuleParser::EntityListContext::entityDecl(size_t i) {
  return getRuleContext<RuleParser::EntityDeclContext>(i);
}


size_t RuleParser::EntityListContext::getRuleIndex() const {
  return RuleParser::RuleEntityList;
}

void RuleParser::EntityListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntityList(this);
}

void RuleParser::EntityListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntityList(this);
}


antlrcpp::Any RuleParser::EntityListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitEntityList(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::EntityListContext* RuleParser::entityList() {
  EntityListContext *_localctx = _tracker.createInstance<EntityListContext>(_ctx, getState());
  enterRule(_localctx, 6, RuleParser::RuleEntityList);
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
    setState(99); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(97);
      match(RuleParser::ENTITY);
      setState(98);
      entityDecl();
      setState(101); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == RuleParser::ENTITY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntityDeclContext ------------------------------------------------------------------

RuleParser::EntityDeclContext::EntityDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::EntityNameContext* RuleParser::EntityDeclContext::entityName() {
  return getRuleContext<RuleParser::EntityNameContext>(0);
}

tree::TerminalNode* RuleParser::EntityDeclContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

RuleParser::AttributeListContext* RuleParser::EntityDeclContext::attributeList() {
  return getRuleContext<RuleParser::AttributeListContext>(0);
}

tree::TerminalNode* RuleParser::EntityDeclContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}

tree::TerminalNode* RuleParser::EntityDeclContext::IS() {
  return getToken(RuleParser::IS, 0);
}

RuleParser::CompositeTypeContext* RuleParser::EntityDeclContext::compositeType() {
  return getRuleContext<RuleParser::CompositeTypeContext>(0);
}


size_t RuleParser::EntityDeclContext::getRuleIndex() const {
  return RuleParser::RuleEntityDecl;
}

void RuleParser::EntityDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntityDecl(this);
}

void RuleParser::EntityDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntityDecl(this);
}


antlrcpp::Any RuleParser::EntityDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitEntityDecl(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::EntityDeclContext* RuleParser::entityDecl() {
  EntityDeclContext *_localctx = _tracker.createInstance<EntityDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, RuleParser::RuleEntityDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(112);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(103);
      entityName();
      setState(104);
      match(RuleParser::L_CURLY);
      setState(105);
      attributeList();
      setState(106);
      match(RuleParser::R_CURLY);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(108);
      entityName();
      setState(109);
      match(RuleParser::IS);
      setState(110);
      compositeType();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntityNameContext ------------------------------------------------------------------

RuleParser::EntityNameContext::EntityNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::EntityNameContext::IDENTIFIER() {
  return getToken(RuleParser::IDENTIFIER, 0);
}


size_t RuleParser::EntityNameContext::getRuleIndex() const {
  return RuleParser::RuleEntityName;
}

void RuleParser::EntityNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntityName(this);
}

void RuleParser::EntityNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntityName(this);
}


antlrcpp::Any RuleParser::EntityNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitEntityName(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::EntityNameContext* RuleParser::entityName() {
  EntityNameContext *_localctx = _tracker.createInstance<EntityNameContext>(_ctx, getState());
  enterRule(_localctx, 10, RuleParser::RuleEntityName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    match(RuleParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeListContext ------------------------------------------------------------------

RuleParser::AttributeListContext::AttributeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RuleParser::AttributeDeclContext *> RuleParser::AttributeListContext::attributeDecl() {
  return getRuleContexts<RuleParser::AttributeDeclContext>();
}

RuleParser::AttributeDeclContext* RuleParser::AttributeListContext::attributeDecl(size_t i) {
  return getRuleContext<RuleParser::AttributeDeclContext>(i);
}


size_t RuleParser::AttributeListContext::getRuleIndex() const {
  return RuleParser::RuleAttributeList;
}

void RuleParser::AttributeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeList(this);
}

void RuleParser::AttributeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeList(this);
}


antlrcpp::Any RuleParser::AttributeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitAttributeList(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::AttributeListContext* RuleParser::attributeList() {
  AttributeListContext *_localctx = _tracker.createInstance<AttributeListContext>(_ctx, getState());
  enterRule(_localctx, 12, RuleParser::RuleAttributeList);
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
    setState(117); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(116);
      attributeDecl();
      setState(119); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == RuleParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

RuleParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::AttributeNameContext* RuleParser::AttributeDeclContext::attributeName() {
  return getRuleContext<RuleParser::AttributeNameContext>(0);
}

tree::TerminalNode* RuleParser::AttributeDeclContext::IS() {
  return getToken(RuleParser::IS, 0);
}

RuleParser::TypeAnnoContext* RuleParser::AttributeDeclContext::typeAnno() {
  return getRuleContext<RuleParser::TypeAnnoContext>(0);
}


size_t RuleParser::AttributeDeclContext::getRuleIndex() const {
  return RuleParser::RuleAttributeDecl;
}

void RuleParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void RuleParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}


antlrcpp::Any RuleParser::AttributeDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitAttributeDecl(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::AttributeDeclContext* RuleParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 14, RuleParser::RuleAttributeDecl);
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
    setState(121);
    attributeName();
    setState(124);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RuleParser::IS) {
      setState(122);
      match(RuleParser::IS);
      setState(123);
      typeAnno();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeNameContext ------------------------------------------------------------------

RuleParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::AttributeNameContext::IDENTIFIER() {
  return getToken(RuleParser::IDENTIFIER, 0);
}


size_t RuleParser::AttributeNameContext::getRuleIndex() const {
  return RuleParser::RuleAttributeName;
}

void RuleParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void RuleParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}


antlrcpp::Any RuleParser::AttributeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitAttributeName(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::AttributeNameContext* RuleParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 16, RuleParser::RuleAttributeName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(126);
    match(RuleParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeAnnoContext ------------------------------------------------------------------

RuleParser::TypeAnnoContext::TypeAnnoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::CompositeTypeContext* RuleParser::TypeAnnoContext::compositeType() {
  return getRuleContext<RuleParser::CompositeTypeContext>(0);
}

RuleParser::BasicTypeContext* RuleParser::TypeAnnoContext::basicType() {
  return getRuleContext<RuleParser::BasicTypeContext>(0);
}


size_t RuleParser::TypeAnnoContext::getRuleIndex() const {
  return RuleParser::RuleTypeAnno;
}

void RuleParser::TypeAnnoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeAnno(this);
}

void RuleParser::TypeAnnoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeAnno(this);
}


antlrcpp::Any RuleParser::TypeAnnoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitTypeAnno(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::TypeAnnoContext* RuleParser::typeAnno() {
  TypeAnnoContext *_localctx = _tracker.createInstance<TypeAnnoContext>(_ctx, getState());
  enterRule(_localctx, 18, RuleParser::RuleTypeAnno);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(130);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RuleParser::SET: {
        enterOuterAlt(_localctx, 1);
        setState(128);
        compositeType();
        break;
      }

      case RuleParser::NUMBER:
      case RuleParser::STRING:
      case RuleParser::BOOLEAN:
      case RuleParser::DATE: {
        enterOuterAlt(_localctx, 2);
        setState(129);
        basicType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicTypeContext ------------------------------------------------------------------

RuleParser::BasicTypeContext::BasicTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::BasicTypeContext::NUMBER() {
  return getToken(RuleParser::NUMBER, 0);
}

tree::TerminalNode* RuleParser::BasicTypeContext::STRING() {
  return getToken(RuleParser::STRING, 0);
}

tree::TerminalNode* RuleParser::BasicTypeContext::DATE() {
  return getToken(RuleParser::DATE, 0);
}

tree::TerminalNode* RuleParser::BasicTypeContext::BOOLEAN() {
  return getToken(RuleParser::BOOLEAN, 0);
}


size_t RuleParser::BasicTypeContext::getRuleIndex() const {
  return RuleParser::RuleBasicType;
}

void RuleParser::BasicTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicType(this);
}

void RuleParser::BasicTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicType(this);
}


antlrcpp::Any RuleParser::BasicTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitBasicType(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::BasicTypeContext* RuleParser::basicType() {
  BasicTypeContext *_localctx = _tracker.createInstance<BasicTypeContext>(_ctx, getState());
  enterRule(_localctx, 20, RuleParser::RuleBasicType);
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
    setState(132);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RuleParser::NUMBER)
      | (1ULL << RuleParser::STRING)
      | (1ULL << RuleParser::BOOLEAN)
      | (1ULL << RuleParser::DATE))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompositeTypeContext ------------------------------------------------------------------

RuleParser::CompositeTypeContext::CompositeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::SetTypeContext* RuleParser::CompositeTypeContext::setType() {
  return getRuleContext<RuleParser::SetTypeContext>(0);
}


size_t RuleParser::CompositeTypeContext::getRuleIndex() const {
  return RuleParser::RuleCompositeType;
}

void RuleParser::CompositeTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompositeType(this);
}

void RuleParser::CompositeTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompositeType(this);
}


antlrcpp::Any RuleParser::CompositeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitCompositeType(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::CompositeTypeContext* RuleParser::compositeType() {
  CompositeTypeContext *_localctx = _tracker.createInstance<CompositeTypeContext>(_ctx, getState());
  enterRule(_localctx, 22, RuleParser::RuleCompositeType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    setType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetTypeContext ------------------------------------------------------------------

RuleParser::SetTypeContext::SetTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::SetTypeContext::SET() {
  return getToken(RuleParser::SET, 0);
}

tree::TerminalNode* RuleParser::SetTypeContext::L_BRACKET() {
  return getToken(RuleParser::L_BRACKET, 0);
}

tree::TerminalNode* RuleParser::SetTypeContext::R_BRACKET() {
  return getToken(RuleParser::R_BRACKET, 0);
}

tree::TerminalNode* RuleParser::SetTypeContext::IDENTIFIER() {
  return getToken(RuleParser::IDENTIFIER, 0);
}

RuleParser::BasicTypeContext* RuleParser::SetTypeContext::basicType() {
  return getRuleContext<RuleParser::BasicTypeContext>(0);
}


size_t RuleParser::SetTypeContext::getRuleIndex() const {
  return RuleParser::RuleSetType;
}

void RuleParser::SetTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetType(this);
}

void RuleParser::SetTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetType(this);
}


antlrcpp::Any RuleParser::SetTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitSetType(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::SetTypeContext* RuleParser::setType() {
  SetTypeContext *_localctx = _tracker.createInstance<SetTypeContext>(_ctx, getState());
  enterRule(_localctx, 24, RuleParser::RuleSetType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(136);
    match(RuleParser::SET);
    setState(137);
    match(RuleParser::L_BRACKET);
    setState(140);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RuleParser::IDENTIFIER: {
        setState(138);
        match(RuleParser::IDENTIFIER);
        break;
      }

      case RuleParser::NUMBER:
      case RuleParser::STRING:
      case RuleParser::BOOLEAN:
      case RuleParser::DATE: {
        setState(139);
        basicType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(142);
    match(RuleParser::R_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RulesBlockContext ------------------------------------------------------------------

RuleParser::RulesBlockContext::RulesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::RulesBlockContext::RULES() {
  return getToken(RuleParser::RULES, 0);
}

tree::TerminalNode* RuleParser::RulesBlockContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

RuleParser::RuleListContext* RuleParser::RulesBlockContext::ruleList() {
  return getRuleContext<RuleParser::RuleListContext>(0);
}

tree::TerminalNode* RuleParser::RulesBlockContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}


size_t RuleParser::RulesBlockContext::getRuleIndex() const {
  return RuleParser::RuleRulesBlock;
}

void RuleParser::RulesBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRulesBlock(this);
}

void RuleParser::RulesBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRulesBlock(this);
}


antlrcpp::Any RuleParser::RulesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRulesBlock(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RulesBlockContext* RuleParser::rulesBlock() {
  RulesBlockContext *_localctx = _tracker.createInstance<RulesBlockContext>(_ctx, getState());
  enterRule(_localctx, 26, RuleParser::RuleRulesBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(RuleParser::RULES);
    setState(145);
    match(RuleParser::L_CURLY);
    setState(146);
    ruleList();
    setState(147);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleListContext ------------------------------------------------------------------

RuleParser::RuleListContext::RuleListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RuleParser::BasicRuleContext *> RuleParser::RuleListContext::basicRule() {
  return getRuleContexts<RuleParser::BasicRuleContext>();
}

RuleParser::BasicRuleContext* RuleParser::RuleListContext::basicRule(size_t i) {
  return getRuleContext<RuleParser::BasicRuleContext>(i);
}


size_t RuleParser::RuleListContext::getRuleIndex() const {
  return RuleParser::RuleRuleList;
}

void RuleParser::RuleListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleList(this);
}

void RuleParser::RuleListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleList(this);
}


antlrcpp::Any RuleParser::RuleListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRuleList(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RuleListContext* RuleParser::ruleList() {
  RuleListContext *_localctx = _tracker.createInstance<RuleListContext>(_ctx, getState());
  enterRule(_localctx, 28, RuleParser::RuleRuleList);
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
    setState(150); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(149);
      basicRule();
      setState(152); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == RuleParser::RULE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicRuleContext ------------------------------------------------------------------

RuleParser::BasicRuleContext::BasicRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::BasicRuleContext::RULE() {
  return getToken(RuleParser::RULE, 0);
}

RuleParser::RuleNameContext* RuleParser::BasicRuleContext::ruleName() {
  return getRuleContext<RuleParser::RuleNameContext>(0);
}

tree::TerminalNode* RuleParser::BasicRuleContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

RuleParser::RuleStmtListContext* RuleParser::BasicRuleContext::ruleStmtList() {
  return getRuleContext<RuleParser::RuleStmtListContext>(0);
}

tree::TerminalNode* RuleParser::BasicRuleContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}


size_t RuleParser::BasicRuleContext::getRuleIndex() const {
  return RuleParser::RuleBasicRule;
}

void RuleParser::BasicRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicRule(this);
}

void RuleParser::BasicRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicRule(this);
}


antlrcpp::Any RuleParser::BasicRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitBasicRule(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::BasicRuleContext* RuleParser::basicRule() {
  BasicRuleContext *_localctx = _tracker.createInstance<BasicRuleContext>(_ctx, getState());
  enterRule(_localctx, 30, RuleParser::RuleBasicRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    match(RuleParser::RULE);
    setState(155);
    ruleName();
    setState(156);
    match(RuleParser::L_CURLY);
    setState(157);
    ruleStmtList();
    setState(158);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleNameContext ------------------------------------------------------------------

RuleParser::RuleNameContext::RuleNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::RuleNameContext::IDENTIFIER() {
  return getToken(RuleParser::IDENTIFIER, 0);
}


size_t RuleParser::RuleNameContext::getRuleIndex() const {
  return RuleParser::RuleRuleName;
}

void RuleParser::RuleNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleName(this);
}

void RuleParser::RuleNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleName(this);
}


antlrcpp::Any RuleParser::RuleNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRuleName(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RuleNameContext* RuleParser::ruleName() {
  RuleNameContext *_localctx = _tracker.createInstance<RuleNameContext>(_ctx, getState());
  enterRule(_localctx, 32, RuleParser::RuleRuleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(160);
    match(RuleParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleStmtListContext ------------------------------------------------------------------

RuleParser::RuleStmtListContext::RuleStmtListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RuleParser::RuleStmtContext *> RuleParser::RuleStmtListContext::ruleStmt() {
  return getRuleContexts<RuleParser::RuleStmtContext>();
}

RuleParser::RuleStmtContext* RuleParser::RuleStmtListContext::ruleStmt(size_t i) {
  return getRuleContext<RuleParser::RuleStmtContext>(i);
}


size_t RuleParser::RuleStmtListContext::getRuleIndex() const {
  return RuleParser::RuleRuleStmtList;
}

void RuleParser::RuleStmtListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleStmtList(this);
}

void RuleParser::RuleStmtListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleStmtList(this);
}


antlrcpp::Any RuleParser::RuleStmtListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRuleStmtList(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RuleStmtListContext* RuleParser::ruleStmtList() {
  RuleStmtListContext *_localctx = _tracker.createInstance<RuleStmtListContext>(_ctx, getState());
  enterRule(_localctx, 34, RuleParser::RuleRuleStmtList);
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
    setState(163); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(162);
      ruleStmt();
      setState(165); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (((((_la - 23) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 23)) & ((1ULL << (RuleParser::IF - 23))
      | (1ULL << (RuleParser::L_PAREN - 23))
      | (1ULL << (RuleParser::LOGICAL_NOT - 23))
      | (1ULL << (RuleParser::ACCUMULATE - 23))
      | (1ULL << (RuleParser::COUNT - 23))
      | (1ULL << (RuleParser::BOOLEAN_LIT - 23))
      | (1ULL << (RuleParser::DECIMAL_LIT - 23))
      | (1ULL << (RuleParser::DECIMAL_FLOAT_LIT - 23))
      | (1ULL << (RuleParser::IDENTIFIER - 23)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleStmtContext ------------------------------------------------------------------

RuleParser::RuleStmtContext::RuleStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::SimpleStmtContext* RuleParser::RuleStmtContext::simpleStmt() {
  return getRuleContext<RuleParser::SimpleStmtContext>(0);
}

RuleParser::ComplexStmtContext* RuleParser::RuleStmtContext::complexStmt() {
  return getRuleContext<RuleParser::ComplexStmtContext>(0);
}


size_t RuleParser::RuleStmtContext::getRuleIndex() const {
  return RuleParser::RuleRuleStmt;
}

void RuleParser::RuleStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleStmt(this);
}

void RuleParser::RuleStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleStmt(this);
}


antlrcpp::Any RuleParser::RuleStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRuleStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RuleStmtContext* RuleParser::ruleStmt() {
  RuleStmtContext *_localctx = _tracker.createInstance<RuleStmtContext>(_ctx, getState());
  enterRule(_localctx, 36, RuleParser::RuleRuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(169);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(167);
      simpleStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(168);
      complexStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleStmtContext ------------------------------------------------------------------

RuleParser::SimpleStmtContext::SimpleStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::SetStmtContext* RuleParser::SimpleStmtContext::setStmt() {
  return getRuleContext<RuleParser::SetStmtContext>(0);
}

RuleParser::RelationStmtContext* RuleParser::SimpleStmtContext::relationStmt() {
  return getRuleContext<RuleParser::RelationStmtContext>(0);
}

RuleParser::LogicalStmtContext* RuleParser::SimpleStmtContext::logicalStmt() {
  return getRuleContext<RuleParser::LogicalStmtContext>(0);
}


size_t RuleParser::SimpleStmtContext::getRuleIndex() const {
  return RuleParser::RuleSimpleStmt;
}

void RuleParser::SimpleStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleStmt(this);
}

void RuleParser::SimpleStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleStmt(this);
}


antlrcpp::Any RuleParser::SimpleStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitSimpleStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::SimpleStmtContext* RuleParser::simpleStmt() {
  SimpleStmtContext *_localctx = _tracker.createInstance<SimpleStmtContext>(_ctx, getState());
  enterRule(_localctx, 38, RuleParser::RuleSimpleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(174);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(171);
      setStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(172);
      relationStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(173);
      logicalStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComplexStmtContext ------------------------------------------------------------------

RuleParser::ComplexStmtContext::ComplexStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::IfStmtContext* RuleParser::ComplexStmtContext::ifStmt() {
  return getRuleContext<RuleParser::IfStmtContext>(0);
}

RuleParser::SequentialStmtContext* RuleParser::ComplexStmtContext::sequentialStmt() {
  return getRuleContext<RuleParser::SequentialStmtContext>(0);
}

RuleParser::DateStmtContext* RuleParser::ComplexStmtContext::dateStmt() {
  return getRuleContext<RuleParser::DateStmtContext>(0);
}

RuleParser::TimeStmtContext* RuleParser::ComplexStmtContext::timeStmt() {
  return getRuleContext<RuleParser::TimeStmtContext>(0);
}


size_t RuleParser::ComplexStmtContext::getRuleIndex() const {
  return RuleParser::RuleComplexStmt;
}

void RuleParser::ComplexStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComplexStmt(this);
}

void RuleParser::ComplexStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComplexStmt(this);
}


antlrcpp::Any RuleParser::ComplexStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitComplexStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ComplexStmtContext* RuleParser::complexStmt() {
  ComplexStmtContext *_localctx = _tracker.createInstance<ComplexStmtContext>(_ctx, getState());
  enterRule(_localctx, 40, RuleParser::RuleComplexStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(180);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(176);
      ifStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(177);
      sequentialStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(178);
      dateStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(179);
      timeStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetStmtContext ------------------------------------------------------------------

RuleParser::SetStmtContext::SetStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::SetExprContext* RuleParser::SetStmtContext::setExpr() {
  return getRuleContext<RuleParser::SetExprContext>(0);
}


size_t RuleParser::SetStmtContext::getRuleIndex() const {
  return RuleParser::RuleSetStmt;
}

void RuleParser::SetStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetStmt(this);
}

void RuleParser::SetStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetStmt(this);
}


antlrcpp::Any RuleParser::SetStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitSetStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::SetStmtContext* RuleParser::setStmt() {
  SetStmtContext *_localctx = _tracker.createInstance<SetStmtContext>(_ctx, getState());
  enterRule(_localctx, 42, RuleParser::RuleSetStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    setExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SetExprContext ------------------------------------------------------------------

RuleParser::SetExprContext::SetExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::SetExprContext::L_PAREN() {
  return getToken(RuleParser::L_PAREN, 0);
}

RuleParser::SetExprContext* RuleParser::SetExprContext::setExpr() {
  return getRuleContext<RuleParser::SetExprContext>(0);
}

tree::TerminalNode* RuleParser::SetExprContext::R_PAREN() {
  return getToken(RuleParser::R_PAREN, 0);
}

RuleParser::SelectorIdentContext* RuleParser::SetExprContext::selectorIdent() {
  return getRuleContext<RuleParser::SelectorIdentContext>(0);
}

RuleParser::EntityNameContext* RuleParser::SetExprContext::entityName() {
  return getRuleContext<RuleParser::EntityNameContext>(0);
}

tree::TerminalNode* RuleParser::SetExprContext::SET_IN() {
  return getToken(RuleParser::SET_IN, 0);
}

tree::TerminalNode* RuleParser::SetExprContext::SET_NOT_IN() {
  return getToken(RuleParser::SET_NOT_IN, 0);
}


size_t RuleParser::SetExprContext::getRuleIndex() const {
  return RuleParser::RuleSetExpr;
}

void RuleParser::SetExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSetExpr(this);
}

void RuleParser::SetExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSetExpr(this);
}


antlrcpp::Any RuleParser::SetExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitSetExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::SetExprContext* RuleParser::setExpr() {
  SetExprContext *_localctx = _tracker.createInstance<SetExprContext>(_ctx, getState());
  enterRule(_localctx, 44, RuleParser::RuleSetExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(192);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RuleParser::L_PAREN: {
        enterOuterAlt(_localctx, 1);
        setState(184);
        match(RuleParser::L_PAREN);
        setState(185);
        setExpr();
        setState(186);
        match(RuleParser::R_PAREN);
        break;
      }

      case RuleParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(188);
        selectorIdent();
        setState(189);
        _la = _input->LA(1);
        if (!(_la == RuleParser::SET_IN

        || _la == RuleParser::SET_NOT_IN)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(190);
        entityName();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationStmtContext ------------------------------------------------------------------

RuleParser::RelationStmtContext::RelationStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::RelationExprContext* RuleParser::RelationStmtContext::relationExpr() {
  return getRuleContext<RuleParser::RelationExprContext>(0);
}


size_t RuleParser::RelationStmtContext::getRuleIndex() const {
  return RuleParser::RuleRelationStmt;
}

void RuleParser::RelationStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationStmt(this);
}

void RuleParser::RelationStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationStmt(this);
}


antlrcpp::Any RuleParser::RelationStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRelationStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RelationStmtContext* RuleParser::relationStmt() {
  RelationStmtContext *_localctx = _tracker.createInstance<RelationStmtContext>(_ctx, getState());
  enterRule(_localctx, 46, RuleParser::RuleRelationStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(194);
    relationExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationExprContext ------------------------------------------------------------------

RuleParser::RelationExprContext::RelationExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::RelationExprContext::L_PAREN() {
  return getToken(RuleParser::L_PAREN, 0);
}

RuleParser::RelationExprContext* RuleParser::RelationExprContext::relationExpr() {
  return getRuleContext<RuleParser::RelationExprContext>(0);
}

tree::TerminalNode* RuleParser::RelationExprContext::R_PAREN() {
  return getToken(RuleParser::R_PAREN, 0);
}

std::vector<RuleParser::NumberExprContext *> RuleParser::RelationExprContext::numberExpr() {
  return getRuleContexts<RuleParser::NumberExprContext>();
}

RuleParser::NumberExprContext* RuleParser::RelationExprContext::numberExpr(size_t i) {
  return getRuleContext<RuleParser::NumberExprContext>(i);
}

std::vector<tree::TerminalNode *> RuleParser::RelationExprContext::EQUALS() {
  return getTokens(RuleParser::EQUALS);
}

tree::TerminalNode* RuleParser::RelationExprContext::EQUALS(size_t i) {
  return getToken(RuleParser::EQUALS, i);
}

std::vector<tree::TerminalNode *> RuleParser::RelationExprContext::NOT_EQUALS() {
  return getTokens(RuleParser::NOT_EQUALS);
}

tree::TerminalNode* RuleParser::RelationExprContext::NOT_EQUALS(size_t i) {
  return getToken(RuleParser::NOT_EQUALS, i);
}

std::vector<tree::TerminalNode *> RuleParser::RelationExprContext::LESS_THAN() {
  return getTokens(RuleParser::LESS_THAN);
}

tree::TerminalNode* RuleParser::RelationExprContext::LESS_THAN(size_t i) {
  return getToken(RuleParser::LESS_THAN, i);
}

std::vector<tree::TerminalNode *> RuleParser::RelationExprContext::LESS_OR_EQUALS() {
  return getTokens(RuleParser::LESS_OR_EQUALS);
}

tree::TerminalNode* RuleParser::RelationExprContext::LESS_OR_EQUALS(size_t i) {
  return getToken(RuleParser::LESS_OR_EQUALS, i);
}

std::vector<tree::TerminalNode *> RuleParser::RelationExprContext::GREATER_THAN() {
  return getTokens(RuleParser::GREATER_THAN);
}

tree::TerminalNode* RuleParser::RelationExprContext::GREATER_THAN(size_t i) {
  return getToken(RuleParser::GREATER_THAN, i);
}

std::vector<tree::TerminalNode *> RuleParser::RelationExprContext::GREATER_OR_EQUALS() {
  return getTokens(RuleParser::GREATER_OR_EQUALS);
}

tree::TerminalNode* RuleParser::RelationExprContext::GREATER_OR_EQUALS(size_t i) {
  return getToken(RuleParser::GREATER_OR_EQUALS, i);
}


size_t RuleParser::RelationExprContext::getRuleIndex() const {
  return RuleParser::RuleRelationExpr;
}

void RuleParser::RelationExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationExpr(this);
}

void RuleParser::RelationExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationExpr(this);
}


antlrcpp::Any RuleParser::RelationExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRelationExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RelationExprContext* RuleParser::relationExpr() {
  RelationExprContext *_localctx = _tracker.createInstance<RelationExprContext>(_ctx, getState());
  enterRule(_localctx, 48, RuleParser::RuleRelationExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(207);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(196);
      match(RuleParser::L_PAREN);
      setState(197);
      relationExpr();
      setState(198);
      match(RuleParser::R_PAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(200);
      numberExpr(0);
      setState(203); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(201);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << RuleParser::EQUALS)
          | (1ULL << RuleParser::NOT_EQUALS)
          | (1ULL << RuleParser::LESS_THAN)
          | (1ULL << RuleParser::LESS_OR_EQUALS)
          | (1ULL << RuleParser::GREATER_THAN)
          | (1ULL << RuleParser::GREATER_OR_EQUALS))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(202);
        numberExpr(0);
        setState(205); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << RuleParser::EQUALS)
        | (1ULL << RuleParser::NOT_EQUALS)
        | (1ULL << RuleParser::LESS_THAN)
        | (1ULL << RuleParser::LESS_OR_EQUALS)
        | (1ULL << RuleParser::GREATER_THAN)
        | (1ULL << RuleParser::GREATER_OR_EQUALS))) != 0));
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberExprContext ------------------------------------------------------------------

RuleParser::NumberExprContext::NumberExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::NumberExprContext::L_PAREN() {
  return getToken(RuleParser::L_PAREN, 0);
}

std::vector<RuleParser::NumberExprContext *> RuleParser::NumberExprContext::numberExpr() {
  return getRuleContexts<RuleParser::NumberExprContext>();
}

RuleParser::NumberExprContext* RuleParser::NumberExprContext::numberExpr(size_t i) {
  return getRuleContext<RuleParser::NumberExprContext>(i);
}

tree::TerminalNode* RuleParser::NumberExprContext::R_PAREN() {
  return getToken(RuleParser::R_PAREN, 0);
}

RuleParser::SelectorIdentContext* RuleParser::NumberExprContext::selectorIdent() {
  return getRuleContext<RuleParser::SelectorIdentContext>(0);
}

tree::TerminalNode* RuleParser::NumberExprContext::DECIMAL_LIT() {
  return getToken(RuleParser::DECIMAL_LIT, 0);
}

tree::TerminalNode* RuleParser::NumberExprContext::DECIMAL_FLOAT_LIT() {
  return getToken(RuleParser::DECIMAL_FLOAT_LIT, 0);
}

RuleParser::AggregationExprContext* RuleParser::NumberExprContext::aggregationExpr() {
  return getRuleContext<RuleParser::AggregationExprContext>(0);
}

tree::TerminalNode* RuleParser::NumberExprContext::MULTIPLY() {
  return getToken(RuleParser::MULTIPLY, 0);
}

tree::TerminalNode* RuleParser::NumberExprContext::DIVIDE() {
  return getToken(RuleParser::DIVIDE, 0);
}

tree::TerminalNode* RuleParser::NumberExprContext::MODULO() {
  return getToken(RuleParser::MODULO, 0);
}

tree::TerminalNode* RuleParser::NumberExprContext::PLUS() {
  return getToken(RuleParser::PLUS, 0);
}

tree::TerminalNode* RuleParser::NumberExprContext::MINUS() {
  return getToken(RuleParser::MINUS, 0);
}


size_t RuleParser::NumberExprContext::getRuleIndex() const {
  return RuleParser::RuleNumberExpr;
}

void RuleParser::NumberExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberExpr(this);
}

void RuleParser::NumberExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberExpr(this);
}


antlrcpp::Any RuleParser::NumberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitNumberExpr(this);
  else
    return visitor->visitChildren(this);
}


RuleParser::NumberExprContext* RuleParser::numberExpr() {
   return numberExpr(0);
}

RuleParser::NumberExprContext* RuleParser::numberExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  RuleParser::NumberExprContext *_localctx = _tracker.createInstance<NumberExprContext>(_ctx, parentState);
  RuleParser::NumberExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 50;
  enterRecursionRule(_localctx, 50, RuleParser::RuleNumberExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(217);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RuleParser::L_PAREN: {
        setState(210);
        match(RuleParser::L_PAREN);
        setState(211);
        numberExpr(0);
        setState(212);
        match(RuleParser::R_PAREN);
        break;
      }

      case RuleParser::IDENTIFIER: {
        setState(214);
        selectorIdent();
        break;
      }

      case RuleParser::DECIMAL_LIT:
      case RuleParser::DECIMAL_FLOAT_LIT: {
        setState(215);
        _la = _input->LA(1);
        if (!(_la == RuleParser::DECIMAL_LIT

        || _la == RuleParser::DECIMAL_FLOAT_LIT)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case RuleParser::ACCUMULATE:
      case RuleParser::COUNT: {
        setState(216);
        aggregationExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(227);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(225);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NumberExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumberExpr);
          setState(219);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(220);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << RuleParser::MULTIPLY)
            | (1ULL << RuleParser::DIVIDE)
            | (1ULL << RuleParser::MODULO))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(221);
          numberExpr(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NumberExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumberExpr);
          setState(222);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(223);
          _la = _input->LA(1);
          if (!(_la == RuleParser::PLUS

          || _la == RuleParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(224);
          numberExpr(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(229);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SelectorIdentContext ------------------------------------------------------------------

RuleParser::SelectorIdentContext::SelectorIdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::EntityNameContext* RuleParser::SelectorIdentContext::entityName() {
  return getRuleContext<RuleParser::EntityNameContext>(0);
}

tree::TerminalNode* RuleParser::SelectorIdentContext::DOT() {
  return getToken(RuleParser::DOT, 0);
}

RuleParser::AttributeNameContext* RuleParser::SelectorIdentContext::attributeName() {
  return getRuleContext<RuleParser::AttributeNameContext>(0);
}


size_t RuleParser::SelectorIdentContext::getRuleIndex() const {
  return RuleParser::RuleSelectorIdent;
}

void RuleParser::SelectorIdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectorIdent(this);
}

void RuleParser::SelectorIdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectorIdent(this);
}


antlrcpp::Any RuleParser::SelectorIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitSelectorIdent(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::SelectorIdentContext* RuleParser::selectorIdent() {
  SelectorIdentContext *_localctx = _tracker.createInstance<SelectorIdentContext>(_ctx, getState());
  enterRule(_localctx, 52, RuleParser::RuleSelectorIdent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    entityName();
    setState(231);
    match(RuleParser::DOT);
    setState(232);
    attributeName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AggregationExprContext ------------------------------------------------------------------

RuleParser::AggregationExprContext::AggregationExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::AggregationExprContext::ACCUMULATE() {
  return getToken(RuleParser::ACCUMULATE, 0);
}

RuleParser::NumberExprContext* RuleParser::AggregationExprContext::numberExpr() {
  return getRuleContext<RuleParser::NumberExprContext>(0);
}

tree::TerminalNode* RuleParser::AggregationExprContext::ON() {
  return getToken(RuleParser::ON, 0);
}

RuleParser::EntityNameContext* RuleParser::AggregationExprContext::entityName() {
  return getRuleContext<RuleParser::EntityNameContext>(0);
}

tree::TerminalNode* RuleParser::AggregationExprContext::WITHIN() {
  return getToken(RuleParser::WITHIN, 0);
}

tree::TerminalNode* RuleParser::AggregationExprContext::TIME_LIT() {
  return getToken(RuleParser::TIME_LIT, 0);
}

tree::TerminalNode* RuleParser::AggregationExprContext::PROVIDED() {
  return getToken(RuleParser::PROVIDED, 0);
}

std::vector<RuleParser::SelectorIdentContext *> RuleParser::AggregationExprContext::selectorIdent() {
  return getRuleContexts<RuleParser::SelectorIdentContext>();
}

RuleParser::SelectorIdentContext* RuleParser::AggregationExprContext::selectorIdent(size_t i) {
  return getRuleContext<RuleParser::SelectorIdentContext>(i);
}

tree::TerminalNode* RuleParser::AggregationExprContext::WHERE() {
  return getToken(RuleParser::WHERE, 0);
}

RuleParser::BooleanExprContext* RuleParser::AggregationExprContext::booleanExpr() {
  return getRuleContext<RuleParser::BooleanExprContext>(0);
}

std::vector<tree::TerminalNode *> RuleParser::AggregationExprContext::LOGICAL_AND() {
  return getTokens(RuleParser::LOGICAL_AND);
}

tree::TerminalNode* RuleParser::AggregationExprContext::LOGICAL_AND(size_t i) {
  return getToken(RuleParser::LOGICAL_AND, i);
}

tree::TerminalNode* RuleParser::AggregationExprContext::COUNT() {
  return getToken(RuleParser::COUNT, 0);
}


size_t RuleParser::AggregationExprContext::getRuleIndex() const {
  return RuleParser::RuleAggregationExpr;
}

void RuleParser::AggregationExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregationExpr(this);
}

void RuleParser::AggregationExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregationExpr(this);
}


antlrcpp::Any RuleParser::AggregationExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitAggregationExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::AggregationExprContext* RuleParser::aggregationExpr() {
  AggregationExprContext *_localctx = _tracker.createInstance<AggregationExprContext>(_ctx, getState());
  enterRule(_localctx, 54, RuleParser::RuleAggregationExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(277);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RuleParser::ACCUMULATE: {
        enterOuterAlt(_localctx, 1);
        setState(234);
        match(RuleParser::ACCUMULATE);
        setState(235);
        numberExpr(0);
        setState(236);
        match(RuleParser::ON);
        setState(237);
        entityName();
        setState(247);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == RuleParser::PROVIDED) {
          setState(238);
          match(RuleParser::PROVIDED);
          setState(239);
          selectorIdent();
          setState(244);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == RuleParser::LOGICAL_AND) {
            setState(240);
            match(RuleParser::LOGICAL_AND);
            setState(241);
            selectorIdent();
            setState(246);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(251);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == RuleParser::WHERE) {
          setState(249);
          match(RuleParser::WHERE);
          setState(250);
          booleanExpr();
        }
        setState(253);
        match(RuleParser::WITHIN);
        setState(254);
        match(RuleParser::TIME_LIT);
        break;
      }

      case RuleParser::COUNT: {
        enterOuterAlt(_localctx, 2);
        setState(256);
        match(RuleParser::COUNT);
        setState(257);
        match(RuleParser::ON);
        setState(258);
        entityName();
        setState(268);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == RuleParser::PROVIDED) {
          setState(259);
          match(RuleParser::PROVIDED);
          setState(260);
          selectorIdent();
          setState(265);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == RuleParser::LOGICAL_AND) {
            setState(261);
            match(RuleParser::LOGICAL_AND);
            setState(262);
            selectorIdent();
            setState(267);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
        }
        setState(272);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == RuleParser::WHERE) {
          setState(270);
          match(RuleParser::WHERE);
          setState(271);
          booleanExpr();
        }
        setState(274);
        match(RuleParser::WITHIN);
        setState(275);
        match(RuleParser::TIME_LIT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanExprContext ------------------------------------------------------------------

RuleParser::BooleanExprContext::BooleanExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::BooleanExprContext::L_PAREN() {
  return getToken(RuleParser::L_PAREN, 0);
}

RuleParser::BooleanExprContext* RuleParser::BooleanExprContext::booleanExpr() {
  return getRuleContext<RuleParser::BooleanExprContext>(0);
}

tree::TerminalNode* RuleParser::BooleanExprContext::R_PAREN() {
  return getToken(RuleParser::R_PAREN, 0);
}

tree::TerminalNode* RuleParser::BooleanExprContext::BOOLEAN_LIT() {
  return getToken(RuleParser::BOOLEAN_LIT, 0);
}

RuleParser::SelectorIdentContext* RuleParser::BooleanExprContext::selectorIdent() {
  return getRuleContext<RuleParser::SelectorIdentContext>(0);
}

RuleParser::SetExprContext* RuleParser::BooleanExprContext::setExpr() {
  return getRuleContext<RuleParser::SetExprContext>(0);
}

RuleParser::RelationExprContext* RuleParser::BooleanExprContext::relationExpr() {
  return getRuleContext<RuleParser::RelationExprContext>(0);
}

RuleParser::LogicalExprContext* RuleParser::BooleanExprContext::logicalExpr() {
  return getRuleContext<RuleParser::LogicalExprContext>(0);
}


size_t RuleParser::BooleanExprContext::getRuleIndex() const {
  return RuleParser::RuleBooleanExpr;
}

void RuleParser::BooleanExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanExpr(this);
}

void RuleParser::BooleanExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanExpr(this);
}


antlrcpp::Any RuleParser::BooleanExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitBooleanExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::BooleanExprContext* RuleParser::booleanExpr() {
  BooleanExprContext *_localctx = _tracker.createInstance<BooleanExprContext>(_ctx, getState());
  enterRule(_localctx, 56, RuleParser::RuleBooleanExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(288);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(279);
      match(RuleParser::L_PAREN);
      setState(280);
      booleanExpr();
      setState(281);
      match(RuleParser::R_PAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(283);
      match(RuleParser::BOOLEAN_LIT);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(284);
      selectorIdent();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(285);
      setExpr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(286);
      relationExpr();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(287);
      logicalExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalStmtContext ------------------------------------------------------------------

RuleParser::LogicalStmtContext::LogicalStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::LogicalExprContext* RuleParser::LogicalStmtContext::logicalExpr() {
  return getRuleContext<RuleParser::LogicalExprContext>(0);
}


size_t RuleParser::LogicalStmtContext::getRuleIndex() const {
  return RuleParser::RuleLogicalStmt;
}

void RuleParser::LogicalStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalStmt(this);
}

void RuleParser::LogicalStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalStmt(this);
}


antlrcpp::Any RuleParser::LogicalStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitLogicalStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::LogicalStmtContext* RuleParser::logicalStmt() {
  LogicalStmtContext *_localctx = _tracker.createInstance<LogicalStmtContext>(_ctx, getState());
  enterRule(_localctx, 58, RuleParser::RuleLogicalStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(290);
    logicalExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalExprContext ------------------------------------------------------------------

RuleParser::LogicalExprContext::LogicalExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::LogicalExprContext::L_PAREN() {
  return getToken(RuleParser::L_PAREN, 0);
}

tree::TerminalNode* RuleParser::LogicalExprContext::LOGICAL_NOT() {
  return getToken(RuleParser::LOGICAL_NOT, 0);
}

tree::TerminalNode* RuleParser::LogicalExprContext::R_PAREN() {
  return getToken(RuleParser::R_PAREN, 0);
}

std::vector<tree::TerminalNode *> RuleParser::LogicalExprContext::BOOLEAN_LIT() {
  return getTokens(RuleParser::BOOLEAN_LIT);
}

tree::TerminalNode* RuleParser::LogicalExprContext::BOOLEAN_LIT(size_t i) {
  return getToken(RuleParser::BOOLEAN_LIT, i);
}

std::vector<RuleParser::SelectorIdentContext *> RuleParser::LogicalExprContext::selectorIdent() {
  return getRuleContexts<RuleParser::SelectorIdentContext>();
}

RuleParser::SelectorIdentContext* RuleParser::LogicalExprContext::selectorIdent(size_t i) {
  return getRuleContext<RuleParser::SelectorIdentContext>(i);
}

tree::TerminalNode* RuleParser::LogicalExprContext::LOGICAL_AND() {
  return getToken(RuleParser::LOGICAL_AND, 0);
}

tree::TerminalNode* RuleParser::LogicalExprContext::LOGICAL_OR() {
  return getToken(RuleParser::LOGICAL_OR, 0);
}


size_t RuleParser::LogicalExprContext::getRuleIndex() const {
  return RuleParser::RuleLogicalExpr;
}

void RuleParser::LogicalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalExpr(this);
}

void RuleParser::LogicalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalExpr(this);
}


antlrcpp::Any RuleParser::LogicalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitLogicalExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::LogicalExprContext* RuleParser::logicalExpr() {
  LogicalExprContext *_localctx = _tracker.createInstance<LogicalExprContext>(_ctx, getState());
  enterRule(_localctx, 60, RuleParser::RuleLogicalExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(344);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(292);
      match(RuleParser::L_PAREN);
      setState(293);
      match(RuleParser::LOGICAL_NOT);
      setState(296);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::BOOLEAN_LIT: {
          setState(294);
          match(RuleParser::BOOLEAN_LIT);
          break;
        }

        case RuleParser::IDENTIFIER: {
          setState(295);
          selectorIdent();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(298);
      match(RuleParser::R_PAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(299);
      match(RuleParser::LOGICAL_NOT);
      setState(302);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::BOOLEAN_LIT: {
          setState(300);
          match(RuleParser::BOOLEAN_LIT);
          break;
        }

        case RuleParser::IDENTIFIER: {
          setState(301);
          selectorIdent();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(304);
      match(RuleParser::L_PAREN);
      setState(307);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::BOOLEAN_LIT: {
          setState(305);
          match(RuleParser::BOOLEAN_LIT);
          break;
        }

        case RuleParser::IDENTIFIER: {
          setState(306);
          selectorIdent();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(309);
      match(RuleParser::LOGICAL_AND);
      setState(312);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::BOOLEAN_LIT: {
          setState(310);
          match(RuleParser::BOOLEAN_LIT);
          break;
        }

        case RuleParser::IDENTIFIER: {
          setState(311);
          selectorIdent();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(314);
      match(RuleParser::R_PAREN);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(317);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::BOOLEAN_LIT: {
          setState(315);
          match(RuleParser::BOOLEAN_LIT);
          break;
        }

        case RuleParser::IDENTIFIER: {
          setState(316);
          selectorIdent();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(319);
      match(RuleParser::LOGICAL_AND);
      setState(322);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::BOOLEAN_LIT: {
          setState(320);
          match(RuleParser::BOOLEAN_LIT);
          break;
        }

        case RuleParser::IDENTIFIER: {
          setState(321);
          selectorIdent();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(324);
      match(RuleParser::L_PAREN);
      setState(327);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::BOOLEAN_LIT: {
          setState(325);
          match(RuleParser::BOOLEAN_LIT);
          break;
        }

        case RuleParser::IDENTIFIER: {
          setState(326);
          selectorIdent();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(329);
      match(RuleParser::LOGICAL_OR);
      setState(332);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::BOOLEAN_LIT: {
          setState(330);
          match(RuleParser::BOOLEAN_LIT);
          break;
        }

        case RuleParser::IDENTIFIER: {
          setState(331);
          selectorIdent();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(334);
      match(RuleParser::R_PAREN);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(337);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::BOOLEAN_LIT: {
          setState(335);
          match(RuleParser::BOOLEAN_LIT);
          break;
        }

        case RuleParser::IDENTIFIER: {
          setState(336);
          selectorIdent();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(339);
      match(RuleParser::LOGICAL_OR);
      setState(342);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::BOOLEAN_LIT: {
          setState(340);
          match(RuleParser::BOOLEAN_LIT);
          break;
        }

        case RuleParser::IDENTIFIER: {
          setState(341);
          selectorIdent();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

RuleParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::IfStmtContext::IF() {
  return getToken(RuleParser::IF, 0);
}

RuleParser::BooleanExprContext* RuleParser::IfStmtContext::booleanExpr() {
  return getRuleContext<RuleParser::BooleanExprContext>(0);
}

tree::TerminalNode* RuleParser::IfStmtContext::THEN() {
  return getToken(RuleParser::THEN, 0);
}

std::vector<tree::TerminalNode *> RuleParser::IfStmtContext::L_CURLY() {
  return getTokens(RuleParser::L_CURLY);
}

tree::TerminalNode* RuleParser::IfStmtContext::L_CURLY(size_t i) {
  return getToken(RuleParser::L_CURLY, i);
}

std::vector<RuleParser::RuleStmtListContext *> RuleParser::IfStmtContext::ruleStmtList() {
  return getRuleContexts<RuleParser::RuleStmtListContext>();
}

RuleParser::RuleStmtListContext* RuleParser::IfStmtContext::ruleStmtList(size_t i) {
  return getRuleContext<RuleParser::RuleStmtListContext>(i);
}

std::vector<tree::TerminalNode *> RuleParser::IfStmtContext::R_CURLY() {
  return getTokens(RuleParser::R_CURLY);
}

tree::TerminalNode* RuleParser::IfStmtContext::R_CURLY(size_t i) {
  return getToken(RuleParser::R_CURLY, i);
}

tree::TerminalNode* RuleParser::IfStmtContext::ELSE() {
  return getToken(RuleParser::ELSE, 0);
}

RuleParser::IfStmtContext* RuleParser::IfStmtContext::ifStmt() {
  return getRuleContext<RuleParser::IfStmtContext>(0);
}


size_t RuleParser::IfStmtContext::getRuleIndex() const {
  return RuleParser::RuleIfStmt;
}

void RuleParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void RuleParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}


antlrcpp::Any RuleParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::IfStmtContext* RuleParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 62, RuleParser::RuleIfStmt);
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
    setState(346);
    match(RuleParser::IF);
    setState(347);
    booleanExpr();
    setState(348);
    match(RuleParser::THEN);
    setState(349);
    match(RuleParser::L_CURLY);
    setState(350);
    ruleStmtList();
    setState(351);
    match(RuleParser::R_CURLY);
    setState(360);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RuleParser::ELSE) {
      setState(352);
      match(RuleParser::ELSE);
      setState(358);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::IF: {
          setState(353);
          ifStmt();
          break;
        }

        case RuleParser::L_CURLY: {
          setState(354);
          match(RuleParser::L_CURLY);
          setState(355);
          ruleStmtList();
          setState(356);
          match(RuleParser::R_CURLY);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SequentialStmtContext ------------------------------------------------------------------

RuleParser::SequentialStmtContext::SequentialStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::SequentialExprContext* RuleParser::SequentialStmtContext::sequentialExpr() {
  return getRuleContext<RuleParser::SequentialExprContext>(0);
}


size_t RuleParser::SequentialStmtContext::getRuleIndex() const {
  return RuleParser::RuleSequentialStmt;
}

void RuleParser::SequentialStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequentialStmt(this);
}

void RuleParser::SequentialStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequentialStmt(this);
}


antlrcpp::Any RuleParser::SequentialStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitSequentialStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::SequentialStmtContext* RuleParser::sequentialStmt() {
  SequentialStmtContext *_localctx = _tracker.createInstance<SequentialStmtContext>(_ctx, getState());
  enterRule(_localctx, 64, RuleParser::RuleSequentialStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    sequentialExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SequentialExprContext ------------------------------------------------------------------

RuleParser::SequentialExprContext::SequentialExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RuleParser::EntityNameContext *> RuleParser::SequentialExprContext::entityName() {
  return getRuleContexts<RuleParser::EntityNameContext>();
}

RuleParser::EntityNameContext* RuleParser::SequentialExprContext::entityName(size_t i) {
  return getRuleContext<RuleParser::EntityNameContext>(i);
}

tree::TerminalNode* RuleParser::SequentialExprContext::BEFORE() {
  return getToken(RuleParser::BEFORE, 0);
}

tree::TerminalNode* RuleParser::SequentialExprContext::AFTER() {
  return getToken(RuleParser::AFTER, 0);
}

tree::TerminalNode* RuleParser::SequentialExprContext::FOLLOW() {
  return getToken(RuleParser::FOLLOW, 0);
}


size_t RuleParser::SequentialExprContext::getRuleIndex() const {
  return RuleParser::RuleSequentialExpr;
}

void RuleParser::SequentialExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequentialExpr(this);
}

void RuleParser::SequentialExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequentialExpr(this);
}


antlrcpp::Any RuleParser::SequentialExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitSequentialExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::SequentialExprContext* RuleParser::sequentialExpr() {
  SequentialExprContext *_localctx = _tracker.createInstance<SequentialExprContext>(_ctx, getState());
  enterRule(_localctx, 66, RuleParser::RuleSequentialExpr);
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
    setState(364);
    entityName();
    setState(365);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RuleParser::BEFORE)
      | (1ULL << RuleParser::AFTER)
      | (1ULL << RuleParser::FOLLOW))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(366);
    entityName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DateStmtContext ------------------------------------------------------------------

RuleParser::DateStmtContext::DateStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::DateExprContext* RuleParser::DateStmtContext::dateExpr() {
  return getRuleContext<RuleParser::DateExprContext>(0);
}


size_t RuleParser::DateStmtContext::getRuleIndex() const {
  return RuleParser::RuleDateStmt;
}

void RuleParser::DateStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDateStmt(this);
}

void RuleParser::DateStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDateStmt(this);
}


antlrcpp::Any RuleParser::DateStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitDateStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::DateStmtContext* RuleParser::dateStmt() {
  DateStmtContext *_localctx = _tracker.createInstance<DateStmtContext>(_ctx, getState());
  enterRule(_localctx, 68, RuleParser::RuleDateStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(368);
    dateExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DateExprContext ------------------------------------------------------------------

RuleParser::DateExprContext::DateExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::BooleanExprContext* RuleParser::DateExprContext::booleanExpr() {
  return getRuleContext<RuleParser::BooleanExprContext>(0);
}

tree::TerminalNode* RuleParser::DateExprContext::DATE_LIT() {
  return getToken(RuleParser::DATE_LIT, 0);
}

tree::TerminalNode* RuleParser::DateExprContext::BEFORE() {
  return getToken(RuleParser::BEFORE, 0);
}

tree::TerminalNode* RuleParser::DateExprContext::AFTER() {
  return getToken(RuleParser::AFTER, 0);
}


size_t RuleParser::DateExprContext::getRuleIndex() const {
  return RuleParser::RuleDateExpr;
}

void RuleParser::DateExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDateExpr(this);
}

void RuleParser::DateExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDateExpr(this);
}


antlrcpp::Any RuleParser::DateExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitDateExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::DateExprContext* RuleParser::dateExpr() {
  DateExprContext *_localctx = _tracker.createInstance<DateExprContext>(_ctx, getState());
  enterRule(_localctx, 70, RuleParser::RuleDateExpr);
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
    setState(370);
    booleanExpr();
    setState(371);
    _la = _input->LA(1);
    if (!(_la == RuleParser::BEFORE

    || _la == RuleParser::AFTER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(372);
    match(RuleParser::DATE_LIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeStmtContext ------------------------------------------------------------------

RuleParser::TimeStmtContext::TimeStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::TimeExprContext* RuleParser::TimeStmtContext::timeExpr() {
  return getRuleContext<RuleParser::TimeExprContext>(0);
}


size_t RuleParser::TimeStmtContext::getRuleIndex() const {
  return RuleParser::RuleTimeStmt;
}

void RuleParser::TimeStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeStmt(this);
}

void RuleParser::TimeStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeStmt(this);
}


antlrcpp::Any RuleParser::TimeStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitTimeStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::TimeStmtContext* RuleParser::timeStmt() {
  TimeStmtContext *_localctx = _tracker.createInstance<TimeStmtContext>(_ctx, getState());
  enterRule(_localctx, 72, RuleParser::RuleTimeStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(374);
    timeExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeExprContext ------------------------------------------------------------------

RuleParser::TimeExprContext::TimeExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::BooleanExprContext* RuleParser::TimeExprContext::booleanExpr() {
  return getRuleContext<RuleParser::BooleanExprContext>(0);
}

tree::TerminalNode* RuleParser::TimeExprContext::WITHIN() {
  return getToken(RuleParser::WITHIN, 0);
}

tree::TerminalNode* RuleParser::TimeExprContext::TIME_LIT() {
  return getToken(RuleParser::TIME_LIT, 0);
}


size_t RuleParser::TimeExprContext::getRuleIndex() const {
  return RuleParser::RuleTimeExpr;
}

void RuleParser::TimeExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeExpr(this);
}

void RuleParser::TimeExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeExpr(this);
}


antlrcpp::Any RuleParser::TimeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitTimeExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::TimeExprContext* RuleParser::timeExpr() {
  TimeExprContext *_localctx = _tracker.createInstance<TimeExprContext>(_ctx, getState());
  enterRule(_localctx, 74, RuleParser::RuleTimeExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(376);
    booleanExpr();
    setState(377);
    match(RuleParser::WITHIN);
    setState(378);
    match(RuleParser::TIME_LIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EosContext ------------------------------------------------------------------

RuleParser::EosContext::EosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::EosContext::SEMI() {
  return getToken(RuleParser::SEMI, 0);
}

tree::TerminalNode* RuleParser::EosContext::TERMINATOR() {
  return getToken(RuleParser::TERMINATOR, 0);
}

tree::TerminalNode* RuleParser::EosContext::EOF() {
  return getToken(RuleParser::EOF, 0);
}


size_t RuleParser::EosContext::getRuleIndex() const {
  return RuleParser::RuleEos;
}

void RuleParser::EosContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEos(this);
}

void RuleParser::EosContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEos(this);
}


antlrcpp::Any RuleParser::EosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitEos(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::EosContext* RuleParser::eos() {
  EosContext *_localctx = _tracker.createInstance<EosContext>(_ctx, getState());
  enterRule(_localctx, 76, RuleParser::RuleEos);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(384);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(380);
      match(RuleParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(381);
      match(RuleParser::TERMINATOR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);

      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(383);
      match(RuleParser::EOF);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool RuleParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 25: return numberExprSempred(dynamic_cast<NumberExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool RuleParser::numberExprSempred(NumberExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> RuleParser::_decisionToDFA;
atn::PredictionContextCache RuleParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN RuleParser::_atn;
std::vector<uint16_t> RuleParser::_serializedATN;

std::vector<std::string> RuleParser::_ruleNames = {
  "root", "regulationDecl", "entitiesBlock", "entityList", "entityDecl", 
  "entityName", "attributeList", "attributeDecl", "attributeName", "typeAnno", 
  "basicType", "compositeType", "setType", "rulesBlock", "ruleList", "basicRule", 
  "ruleName", "ruleStmtList", "ruleStmt", "simpleStmt", "complexStmt", "setStmt", 
  "setExpr", "relationStmt", "relationExpr", "numberExpr", "selectorIdent", 
  "aggregationExpr", "booleanExpr", "logicalStmt", "logicalExpr", "ifStmt", 
  "sequentialStmt", "sequentialExpr", "dateStmt", "dateExpr", "timeStmt", 
  "timeExpr", "eos"
};

std::vector<std::string> RuleParser::_literalNames = {
  "", "'regulation'", "'entities'", "'rules'", "'references'", "'entity'", 
  "'article'", "'rule'", "'number'", "'string'", "'boolean'", "'date'", 
  "'set'", "", "", "", "", "", "", "'alias'", "'state'", "'event'", "'else'", 
  "'if'", "'then'", "'('", "')'", "'{'", "'}'", "'['", "']'", "'='", "','", 
  "';'", "':'", "'.'", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "'is'", "'within'", "'before'", "'after'", "'follow'", 
  "'accumulate'", "'count'", "'on'", "'provided'", "'where'"
};

std::vector<std::string> RuleParser::_symbolicNames = {
  "", "REGULATION", "ENTITIES", "RULES", "REFERENCES", "ENTITY", "ARTICLE", 
  "RULE", "NUMBER", "STRING", "BOOLEAN", "DATE", "SET", "YEAR", "MONTH", 
  "DAY", "HOUR", "MINUTE", "SECOND", "ALIAS", "STATE", "EVENT", "ELSE", 
  "IF", "THEN", "L_PAREN", "R_PAREN", "L_CURLY", "R_CURLY", "L_BRACKET", 
  "R_BRACKET", "ASSIGN", "COMMA", "SEMI", "COLON", "DOT", "LOGICAL_OR", 
  "LOGICAL_AND", "LOGICAL_NOT", "SET_IN", "SET_NOT_IN", "SET_UNION", "SET_INTERSECT", 
  "EQUALS", "NOT_EQUALS", "LESS_THAN", "LESS_OR_EQUALS", "GREATER_THAN", 
  "GREATER_OR_EQUALS", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULO", 
  "IS", "WITHIN", "BEFORE", "AFTER", "FOLLOW", "ACCUMULATE", "COUNT", "ON", 
  "PROVIDED", "WHERE", "BOOLEAN_LIT", "DECIMAL_LIT", "DECIMAL_FLOAT_LIT", 
  "DATE_LIT", "TIME_LIT", "RUNE_LIT", "BYTE_VALUE", "OCTAL_BYTE_VALUE", 
  "HEX_BYTE_VALUE", "LITTLE_U_VALUE", "BIG_U_VALUE", "RAW_STRING_LIT", "INTERPRETED_STRING_LIT", 
  "IDENTIFIER", "WS", "COMMENT", "TERMINATOR", "LINE_COMMENT"
};

dfa::Vocabulary RuleParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> RuleParser::_tokenNames;

RuleParser::Initializer::Initializer() {
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

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x53, 0x185, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x5a, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x5d, 
    0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x6, 0x5, 0x66, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x67, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x73, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x6, 
    0x8, 0x78, 0xa, 0x8, 0xd, 0x8, 0xe, 0x8, 0x79, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x5, 0x9, 0x7f, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0x85, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x8f, 0xa, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 
    0x6, 0x10, 0x99, 0xa, 0x10, 0xd, 0x10, 0xe, 0x10, 0x9a, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x13, 0x6, 0x13, 0xa6, 0xa, 0x13, 0xd, 0x13, 0xe, 0x13, 0xa7, 0x3, 
    0x14, 0x3, 0x14, 0x5, 0x14, 0xac, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x5, 0x15, 0xb1, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x5, 0x16, 0xb7, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 
    0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x5, 0x18, 0xc3, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x6, 0x1a, 0xce, 
    0xa, 0x1a, 0xd, 0x1a, 0xe, 0x1a, 0xcf, 0x5, 0x1a, 0xd2, 0xa, 0x1a, 0x3, 
    0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x5, 0x1b, 0xdc, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0xe4, 0xa, 0x1b, 0xc, 0x1b, 
    0xe, 0x1b, 0xe7, 0xb, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x7, 0x1d, 0xf5, 0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0xf8, 
    0xb, 0x1d, 0x5, 0x1d, 0xfa, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 
    0xfe, 0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x10a, 
    0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x10d, 0xb, 0x1d, 0x5, 0x1d, 0x10f, 
    0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x113, 0xa, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x118, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x5, 0x1e, 0x123, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x12b, 0xa, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x131, 0xa, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x136, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x5, 0x20, 0x13b, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x5, 0x20, 0x140, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 
    0x145, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x14a, 
    0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x14f, 0xa, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x154, 0xa, 0x20, 0x3, 0x20, 
    0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x159, 0xa, 0x20, 0x5, 0x20, 0x15b, 
    0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x5, 0x21, 0x169, 0xa, 0x21, 0x5, 0x21, 0x16b, 0xa, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x3, 0x28, 0x5, 0x28, 0x183, 0xa, 0x28, 0x3, 0x28, 0x2, 0x3, 0x34, 
    0x29, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 
    0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 
    0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 
    0x4a, 0x4c, 0x4e, 0x2, 0xa, 0x3, 0x2, 0xa, 0xd, 0x3, 0x2, 0x29, 0x2a, 
    0x3, 0x2, 0x2d, 0x32, 0x3, 0x2, 0x43, 0x44, 0x3, 0x2, 0x35, 0x37, 0x3, 
    0x2, 0x33, 0x34, 0x3, 0x2, 0x3a, 0x3c, 0x3, 0x2, 0x3a, 0x3b, 0x2, 0x194, 
    0x2, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4, 0x55, 0x3, 0x2, 0x2, 0x2, 0x6, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x65, 0x3, 0x2, 0x2, 0x2, 0xa, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x74, 0x3, 0x2, 0x2, 0x2, 0xe, 0x77, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x12, 0x80, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x84, 0x3, 0x2, 0x2, 0x2, 0x16, 0x86, 0x3, 0x2, 0x2, 0x2, 0x18, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0x1a, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x92, 0x3, 
    0x2, 0x2, 0x2, 0x1e, 0x98, 0x3, 0x2, 0x2, 0x2, 0x20, 0x9c, 0x3, 0x2, 
    0x2, 0x2, 0x22, 0xa2, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0xab, 0x3, 0x2, 0x2, 0x2, 0x28, 0xb0, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0xb6, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x2e, 
    0xc2, 0x3, 0x2, 0x2, 0x2, 0x30, 0xc4, 0x3, 0x2, 0x2, 0x2, 0x32, 0xd1, 
    0x3, 0x2, 0x2, 0x2, 0x34, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x36, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x117, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x122, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x124, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x15a, 0x3, 0x2, 0x2, 
    0x2, 0x40, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x42, 0x16c, 0x3, 0x2, 0x2, 0x2, 
    0x44, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x46, 0x172, 0x3, 0x2, 0x2, 0x2, 0x48, 
    0x174, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x178, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x17a, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x182, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x5, 
    0x4, 0x3, 0x2, 0x51, 0x52, 0x5, 0x6, 0x4, 0x2, 0x52, 0x53, 0x5, 0x1c, 
    0xf, 0x2, 0x53, 0x54, 0x7, 0x2, 0x2, 0x3, 0x54, 0x3, 0x3, 0x2, 0x2, 
    0x2, 0x55, 0x56, 0x7, 0x3, 0x2, 0x2, 0x56, 0x5b, 0x7, 0x4f, 0x2, 0x2, 
    0x57, 0x58, 0x7, 0x25, 0x2, 0x2, 0x58, 0x5a, 0x7, 0x4f, 0x2, 0x2, 0x59, 
    0x57, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x4, 
    0x2, 0x2, 0x5f, 0x60, 0x7, 0x1d, 0x2, 0x2, 0x60, 0x61, 0x5, 0x8, 0x5, 
    0x2, 0x61, 0x62, 0x7, 0x1e, 0x2, 0x2, 0x62, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x63, 0x64, 0x7, 0x7, 0x2, 0x2, 0x64, 0x66, 0x5, 0xa, 0x6, 0x2, 0x65, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x6a, 0x5, 0xc, 0x7, 0x2, 0x6a, 0x6b, 0x7, 0x1d, 
    0x2, 0x2, 0x6b, 0x6c, 0x5, 0xe, 0x8, 0x2, 0x6c, 0x6d, 0x7, 0x1e, 0x2, 
    0x2, 0x6d, 0x73, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0xc, 0x7, 0x2, 
    0x6f, 0x70, 0x7, 0x38, 0x2, 0x2, 0x70, 0x71, 0x5, 0x18, 0xd, 0x2, 0x71, 
    0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x69, 0x3, 0x2, 0x2, 0x2, 0x72, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x73, 0xb, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 
    0x4f, 0x2, 0x2, 0x75, 0xd, 0x3, 0x2, 0x2, 0x2, 0x76, 0x78, 0x5, 0x10, 
    0x9, 0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 
    0x7a, 0xf, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7e, 0x5, 0x12, 0xa, 0x2, 0x7c, 
    0x7d, 0x7, 0x38, 0x2, 0x2, 0x7d, 0x7f, 0x5, 0x14, 0xb, 0x2, 0x7e, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x11, 0x3, 
    0x2, 0x2, 0x2, 0x80, 0x81, 0x7, 0x4f, 0x2, 0x2, 0x81, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x85, 0x5, 0x18, 0xd, 0x2, 0x83, 0x85, 0x5, 0x16, 0xc, 
    0x2, 0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x84, 0x83, 0x3, 0x2, 0x2, 0x2, 
    0x85, 0x15, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x9, 0x2, 0x2, 0x2, 0x87, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x5, 0x1a, 0xe, 0x2, 0x89, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0xe, 0x2, 0x2, 0x8b, 0x8e, 0x7, 
    0x1f, 0x2, 0x2, 0x8c, 0x8f, 0x7, 0x4f, 0x2, 0x2, 0x8d, 0x8f, 0x5, 0x16, 
    0xc, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x7, 0x20, 0x2, 0x2, 
    0x91, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x5, 0x2, 0x2, 0x93, 
    0x94, 0x7, 0x1d, 0x2, 0x2, 0x94, 0x95, 0x5, 0x1e, 0x10, 0x2, 0x95, 0x96, 
    0x7, 0x1e, 0x2, 0x2, 0x96, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x97, 0x99, 0x5, 
    0x20, 0x11, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9b, 0x3, 0x2, 0x2, 
    0x2, 0x9b, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x9, 0x2, 0x2, 
    0x9d, 0x9e, 0x5, 0x22, 0x12, 0x2, 0x9e, 0x9f, 0x7, 0x1d, 0x2, 0x2, 0x9f, 
    0xa0, 0x5, 0x24, 0x13, 0x2, 0xa0, 0xa1, 0x7, 0x1e, 0x2, 0x2, 0xa1, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x7, 0x4f, 0x2, 0x2, 0xa3, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0xa6, 0x5, 0x26, 0x14, 0x2, 0xa5, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0xa9, 0xac, 0x5, 0x28, 0x15, 0x2, 0xaa, 0xac, 0x5, 0x2a, 0x16, 0x2, 
    0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0xad, 0xb1, 0x5, 0x2c, 0x17, 0x2, 0xae, 0xb1, 
    0x5, 0x30, 0x19, 0x2, 0xaf, 0xb1, 0x5, 0x3c, 0x1f, 0x2, 0xb0, 0xad, 
    0x3, 0x2, 0x2, 0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0xb1, 0x29, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb7, 0x5, 0x40, 
    0x21, 0x2, 0xb3, 0xb7, 0x5, 0x42, 0x22, 0x2, 0xb4, 0xb7, 0x5, 0x46, 
    0x24, 0x2, 0xb5, 0xb7, 0x5, 0x4a, 0x26, 0x2, 0xb6, 0xb2, 0x3, 0x2, 0x2, 
    0x2, 0xb6, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 
    0xb6, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xb8, 
    0xb9, 0x5, 0x2e, 0x18, 0x2, 0xb9, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 
    0x7, 0x1b, 0x2, 0x2, 0xbb, 0xbc, 0x5, 0x2e, 0x18, 0x2, 0xbc, 0xbd, 0x7, 
    0x1c, 0x2, 0x2, 0xbd, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x36, 
    0x1c, 0x2, 0xbf, 0xc0, 0x9, 0x3, 0x2, 0x2, 0xc0, 0xc1, 0x5, 0xc, 0x7, 
    0x2, 0xc1, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xba, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc3, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xc4, 
    0xc5, 0x5, 0x32, 0x1a, 0x2, 0xc5, 0x31, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 
    0x7, 0x1b, 0x2, 0x2, 0xc7, 0xc8, 0x5, 0x32, 0x1a, 0x2, 0xc8, 0xc9, 0x7, 
    0x1c, 0x2, 0x2, 0xc9, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcd, 0x5, 0x34, 
    0x1b, 0x2, 0xcb, 0xcc, 0x9, 0x4, 0x2, 0x2, 0xcc, 0xce, 0x5, 0x34, 0x1b, 
    0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd0, 
    0xd2, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xca, 
    0x3, 0x2, 0x2, 0x2, 0xd2, 0x33, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x8, 
    0x1b, 0x1, 0x2, 0xd4, 0xd5, 0x7, 0x1b, 0x2, 0x2, 0xd5, 0xd6, 0x5, 0x34, 
    0x1b, 0x2, 0xd6, 0xd7, 0x7, 0x1c, 0x2, 0x2, 0xd7, 0xdc, 0x3, 0x2, 0x2, 
    0x2, 0xd8, 0xdc, 0x5, 0x36, 0x1c, 0x2, 0xd9, 0xdc, 0x9, 0x5, 0x2, 0x2, 
    0xda, 0xdc, 0x5, 0x38, 0x1d, 0x2, 0xdb, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xdb, 
    0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xda, 
    0x3, 0x2, 0x2, 0x2, 0xdc, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0xc, 
    0x5, 0x2, 0x2, 0xde, 0xdf, 0x9, 0x6, 0x2, 0x2, 0xdf, 0xe4, 0x5, 0x34, 
    0x1b, 0x6, 0xe0, 0xe1, 0xc, 0x4, 0x2, 0x2, 0xe1, 0xe2, 0x9, 0x7, 0x2, 
    0x2, 0xe2, 0xe4, 0x5, 0x34, 0x1b, 0x5, 0xe3, 0xdd, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe5, 
    0xe3, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe6, 0x35, 
    0x3, 0x2, 0x2, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x5, 
    0xc, 0x7, 0x2, 0xe9, 0xea, 0x7, 0x25, 0x2, 0x2, 0xea, 0xeb, 0x5, 0x12, 
    0xa, 0x2, 0xeb, 0x37, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 0x3d, 0x2, 
    0x2, 0xed, 0xee, 0x5, 0x34, 0x1b, 0x2, 0xee, 0xef, 0x7, 0x3f, 0x2, 0x2, 
    0xef, 0xf9, 0x5, 0xc, 0x7, 0x2, 0xf0, 0xf1, 0x7, 0x40, 0x2, 0x2, 0xf1, 
    0xf6, 0x5, 0x36, 0x1c, 0x2, 0xf2, 0xf3, 0x7, 0x27, 0x2, 0x2, 0xf3, 0xf5, 
    0x5, 0x36, 0x1c, 0x2, 0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf8, 0x3, 
    0x2, 0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 
    0x2, 0x2, 0xf7, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf6, 0x3, 0x2, 0x2, 
    0x2, 0xf9, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 
    0xfa, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfc, 0x7, 0x41, 0x2, 0x2, 0xfc, 
    0xfe, 0x5, 0x3a, 0x1e, 0x2, 0xfd, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 
    0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 
    0x39, 0x2, 0x2, 0x100, 0x101, 0x7, 0x46, 0x2, 0x2, 0x101, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x102, 0x103, 0x7, 0x3e, 0x2, 0x2, 0x103, 0x104, 0x7, 
    0x3f, 0x2, 0x2, 0x104, 0x10e, 0x5, 0xc, 0x7, 0x2, 0x105, 0x106, 0x7, 
    0x40, 0x2, 0x2, 0x106, 0x10b, 0x5, 0x36, 0x1c, 0x2, 0x107, 0x108, 0x7, 
    0x27, 0x2, 0x2, 0x108, 0x10a, 0x5, 0x36, 0x1c, 0x2, 0x109, 0x107, 0x3, 
    0x2, 0x2, 0x2, 0x10a, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x109, 0x3, 
    0x2, 0x2, 0x2, 0x10b, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10f, 0x3, 
    0x2, 0x2, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x105, 0x3, 
    0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x112, 0x3, 
    0x2, 0x2, 0x2, 0x110, 0x111, 0x7, 0x41, 0x2, 0x2, 0x111, 0x113, 0x5, 
    0x3a, 0x1e, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 
    0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x7, 
    0x39, 0x2, 0x2, 0x115, 0x116, 0x7, 0x46, 0x2, 0x2, 0x116, 0x118, 0x3, 
    0x2, 0x2, 0x2, 0x117, 0xec, 0x3, 0x2, 0x2, 0x2, 0x117, 0x102, 0x3, 0x2, 
    0x2, 0x2, 0x118, 0x39, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x7, 0x1b, 
    0x2, 0x2, 0x11a, 0x11b, 0x5, 0x3a, 0x1e, 0x2, 0x11b, 0x11c, 0x7, 0x1c, 
    0x2, 0x2, 0x11c, 0x123, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x123, 0x7, 0x42, 
    0x2, 0x2, 0x11e, 0x123, 0x5, 0x36, 0x1c, 0x2, 0x11f, 0x123, 0x5, 0x2e, 
    0x18, 0x2, 0x120, 0x123, 0x5, 0x32, 0x1a, 0x2, 0x121, 0x123, 0x5, 0x3e, 
    0x20, 0x2, 0x122, 0x119, 0x3, 0x2, 0x2, 0x2, 0x122, 0x11d, 0x3, 0x2, 
    0x2, 0x2, 0x122, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x122, 0x11f, 0x3, 0x2, 
    0x2, 0x2, 0x122, 0x120, 0x3, 0x2, 0x2, 0x2, 0x122, 0x121, 0x3, 0x2, 
    0x2, 0x2, 0x123, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x124, 0x125, 0x5, 0x3e, 
    0x20, 0x2, 0x125, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x7, 0x1b, 
    0x2, 0x2, 0x127, 0x12a, 0x7, 0x28, 0x2, 0x2, 0x128, 0x12b, 0x7, 0x42, 
    0x2, 0x2, 0x129, 0x12b, 0x5, 0x36, 0x1c, 0x2, 0x12a, 0x128, 0x3, 0x2, 
    0x2, 0x2, 0x12a, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 
    0x2, 0x2, 0x12c, 0x15b, 0x7, 0x1c, 0x2, 0x2, 0x12d, 0x130, 0x7, 0x28, 
    0x2, 0x2, 0x12e, 0x131, 0x7, 0x42, 0x2, 0x2, 0x12f, 0x131, 0x5, 0x36, 
    0x1c, 0x2, 0x130, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x130, 0x12f, 0x3, 0x2, 
    0x2, 0x2, 0x131, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x132, 0x135, 0x7, 0x1b, 
    0x2, 0x2, 0x133, 0x136, 0x7, 0x42, 0x2, 0x2, 0x134, 0x136, 0x5, 0x36, 
    0x1c, 0x2, 0x135, 0x133, 0x3, 0x2, 0x2, 0x2, 0x135, 0x134, 0x3, 0x2, 
    0x2, 0x2, 0x136, 0x137, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13a, 0x7, 0x27, 
    0x2, 0x2, 0x138, 0x13b, 0x7, 0x42, 0x2, 0x2, 0x139, 0x13b, 0x5, 0x36, 
    0x1c, 0x2, 0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x139, 0x3, 0x2, 
    0x2, 0x2, 0x13b, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x15b, 0x7, 0x1c, 
    0x2, 0x2, 0x13d, 0x140, 0x7, 0x42, 0x2, 0x2, 0x13e, 0x140, 0x5, 0x36, 
    0x1c, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13e, 0x3, 0x2, 
    0x2, 0x2, 0x140, 0x141, 0x3, 0x2, 0x2, 0x2, 0x141, 0x144, 0x7, 0x27, 
    0x2, 0x2, 0x142, 0x145, 0x7, 0x42, 0x2, 0x2, 0x143, 0x145, 0x5, 0x36, 
    0x1c, 0x2, 0x144, 0x142, 0x3, 0x2, 0x2, 0x2, 0x144, 0x143, 0x3, 0x2, 
    0x2, 0x2, 0x145, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x146, 0x149, 0x7, 0x1b, 
    0x2, 0x2, 0x147, 0x14a, 0x7, 0x42, 0x2, 0x2, 0x148, 0x14a, 0x5, 0x36, 
    0x1c, 0x2, 0x149, 0x147, 0x3, 0x2, 0x2, 0x2, 0x149, 0x148, 0x3, 0x2, 
    0x2, 0x2, 0x14a, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14e, 0x7, 0x26, 
    0x2, 0x2, 0x14c, 0x14f, 0x7, 0x42, 0x2, 0x2, 0x14d, 0x14f, 0x5, 0x36, 
    0x1c, 0x2, 0x14e, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14d, 0x3, 0x2, 
    0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 0x15b, 0x7, 0x1c, 
    0x2, 0x2, 0x151, 0x154, 0x7, 0x42, 0x2, 0x2, 0x152, 0x154, 0x5, 0x36, 
    0x1c, 0x2, 0x153, 0x151, 0x3, 0x2, 0x2, 0x2, 0x153, 0x152, 0x3, 0x2, 
    0x2, 0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 0x155, 0x158, 0x7, 0x26, 
    0x2, 0x2, 0x156, 0x159, 0x7, 0x42, 0x2, 0x2, 0x157, 0x159, 0x5, 0x36, 
    0x1c, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x158, 0x157, 0x3, 0x2, 
    0x2, 0x2, 0x159, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x126, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x132, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x146, 0x3, 0x2, 
    0x2, 0x2, 0x15a, 0x153, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x15c, 0x15d, 0x7, 0x19, 0x2, 0x2, 0x15d, 0x15e, 0x5, 0x3a, 0x1e, 
    0x2, 0x15e, 0x15f, 0x7, 0x1a, 0x2, 0x2, 0x15f, 0x160, 0x7, 0x1d, 0x2, 
    0x2, 0x160, 0x161, 0x5, 0x24, 0x13, 0x2, 0x161, 0x16a, 0x7, 0x1e, 0x2, 
    0x2, 0x162, 0x168, 0x7, 0x18, 0x2, 0x2, 0x163, 0x169, 0x5, 0x40, 0x21, 
    0x2, 0x164, 0x165, 0x7, 0x1d, 0x2, 0x2, 0x165, 0x166, 0x5, 0x24, 0x13, 
    0x2, 0x166, 0x167, 0x7, 0x1e, 0x2, 0x2, 0x167, 0x169, 0x3, 0x2, 0x2, 
    0x2, 0x168, 0x163, 0x3, 0x2, 0x2, 0x2, 0x168, 0x164, 0x3, 0x2, 0x2, 
    0x2, 0x169, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x162, 0x3, 0x2, 0x2, 
    0x2, 0x16a, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x16c, 0x16d, 0x5, 0x44, 0x23, 0x2, 0x16d, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x16e, 0x16f, 0x5, 0xc, 0x7, 0x2, 0x16f, 0x170, 0x9, 0x8, 0x2, 0x2, 
    0x170, 0x171, 0x5, 0xc, 0x7, 0x2, 0x171, 0x45, 0x3, 0x2, 0x2, 0x2, 0x172, 
    0x173, 0x5, 0x48, 0x25, 0x2, 0x173, 0x47, 0x3, 0x2, 0x2, 0x2, 0x174, 
    0x175, 0x5, 0x3a, 0x1e, 0x2, 0x175, 0x176, 0x9, 0x9, 0x2, 0x2, 0x176, 
    0x177, 0x7, 0x45, 0x2, 0x2, 0x177, 0x49, 0x3, 0x2, 0x2, 0x2, 0x178, 
    0x179, 0x5, 0x4c, 0x27, 0x2, 0x179, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x17a, 
    0x17b, 0x5, 0x3a, 0x1e, 0x2, 0x17b, 0x17c, 0x7, 0x39, 0x2, 0x2, 0x17c, 
    0x17d, 0x7, 0x46, 0x2, 0x2, 0x17d, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x17e, 
    0x183, 0x7, 0x23, 0x2, 0x2, 0x17f, 0x183, 0x7, 0x52, 0x2, 0x2, 0x180, 
    0x183, 0x3, 0x2, 0x2, 0x2, 0x181, 0x183, 0x7, 0x2, 0x2, 0x3, 0x182, 
    0x17e, 0x3, 0x2, 0x2, 0x2, 0x182, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x182, 
    0x180, 0x3, 0x2, 0x2, 0x2, 0x182, 0x181, 0x3, 0x2, 0x2, 0x2, 0x183, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x5b, 0x67, 0x72, 0x79, 0x7e, 0x84, 
    0x8e, 0x9a, 0xa7, 0xab, 0xb0, 0xb6, 0xc2, 0xcf, 0xd1, 0xdb, 0xe3, 0xe5, 
    0xf6, 0xf9, 0xfd, 0x10b, 0x10e, 0x112, 0x117, 0x122, 0x12a, 0x130, 0x135, 
    0x13a, 0x13f, 0x144, 0x149, 0x14e, 0x153, 0x158, 0x15a, 0x168, 0x16a, 
    0x182, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

RuleParser::Initializer RuleParser::_init;
