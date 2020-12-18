
// Generated from c:\Projects\ForexTester\MQL2FT_REPO\MQL2FT\MQL2FT\Translator\Grammar.g4 by ANTLR 4.7.1


#include "GrammarListener.h"

#include "GrammarParser.h"


using namespace antlrcpp;
using namespace antlr4;

GrammarParser::GrammarParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

GrammarParser::~GrammarParser() {
  delete _interpreter;
}

std::string GrammarParser::getGrammarFileName() const {
  return "Grammar.g4";
}

const std::vector<std::string>& GrammarParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& GrammarParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompileUnitContext ------------------------------------------------------------------

GrammarParser::CompileUnitContext::CompileUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::CompileUnitContext::EOF() {
  return getToken(GrammarParser::EOF, 0);
}

std::vector<GrammarParser::UnitContext *> GrammarParser::CompileUnitContext::unit() {
  return getRuleContexts<GrammarParser::UnitContext>();
}

GrammarParser::UnitContext* GrammarParser::CompileUnitContext::unit(size_t i) {
  return getRuleContext<GrammarParser::UnitContext>(i);
}


size_t GrammarParser::CompileUnitContext::getRuleIndex() const {
  return GrammarParser::RuleCompileUnit;
}

void GrammarParser::CompileUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompileUnit(this);
}

void GrammarParser::CompileUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompileUnit(this);
}

GrammarParser::CompileUnitContext* GrammarParser::compileUnit() {
  CompileUnitContext *_localctx = _tracker.createInstance<CompileUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, GrammarParser::RuleCompileUnit);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(243); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(242);
      unit();
      setState(245); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
      | (1ULL << GrammarParser::COMMA)
      | (1ULL << GrammarParser::DOT)
      | (1ULL << GrammarParser::OP_BR)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::CL_PARETHESES)
      | (1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::COLON)
      | (1ULL << GrammarParser::SC)
      | (1ULL << GrammarParser::S_QUOTE)
      | (1ULL << GrammarParser::EQ)
      | (1ULL << GrammarParser::COMPARISSON)
      | (1ULL << GrammarParser::COMPARISSON_NOT)
      | (1ULL << GrammarParser::MORE_OR_EQUAL)
      | (1ULL << GrammarParser::LESS_OR_EQUAL)
      | (1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH)
      | (1ULL << GrammarParser::AMPERSAND)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::BD_SLASH)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC)
      | (1ULL << GrammarParser::K_STRICT)
      | (1ULL << GrammarParser::K_NULL)
      | (1ULL << GrammarParser::K_CONST)
      | (1ULL << GrammarParser::K_UNSIGNED)
      | (1ULL << GrammarParser::K_ENUM)
      | (1ULL << GrammarParser::K_ELSE)
      | (1ULL << GrammarParser::K_SWITCH)
      | (1ULL << GrammarParser::K_CASE)
      | (1ULL << GrammarParser::K_RETURN)
      | (1ULL << GrammarParser::K_FOR)
      | (1ULL << GrammarParser::K_IF)
      | (1ULL << GrammarParser::T_DOUBLE)
      | (1ULL << GrammarParser::T_FLOAT)
      | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
      | (1ULL << (GrammarParser::T_BOOL - 64))
      | (1ULL << (GrammarParser::T_LONG - 64))
      | (1ULL << (GrammarParser::T_SHORT - 64))
      | (1ULL << (GrammarParser::T_CHAR - 64))
      | (1ULL << (GrammarParser::T_STRING - 64))
      | (1ULL << (GrammarParser::T_COLOR - 64))
      | (1ULL << (GrammarParser::T_ULONG - 64))
      | (1ULL << (GrammarParser::T_DATETIME - 64))
      | (1ULL << (GrammarParser::PROPERTY - 64))
      | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
      | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
      | (1ULL << (GrammarParser::ALERT - 64))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
      | (1ULL << (GrammarParser::PLAY_SOUND - 64))
      | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
      | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
      | (1ULL << (GrammarParser::TIME_CURRENT - 64))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
      | (1ULL << (GrammarParser::IMA_MODE - 64))
      | (1ULL << (GrammarParser::PRICE_TYPE - 64))
      | (1ULL << (GrammarParser::TIMEFRAME - 64))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
      | (1ULL << (GrammarParser::REGULAR_STRING - 64))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
      | (1ULL << (GrammarParser::NAME - 64))
      | (1ULL << (GrammarParser::INTEGER - 64))
      | (1ULL << (GrammarParser::HEX_INTEGER - 64))
      | (1ULL << (GrammarParser::DATE_LITERAL - 64))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
      | (1ULL << (GrammarParser::ANY - 64))
      | (1ULL << (GrammarParser::MANY - 64)))) != 0));
    setState(247);
    match(GrammarParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

GrammarParser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::PropertyContext* GrammarParser::UnitContext::property() {
  return getRuleContext<GrammarParser::PropertyContext>(0);
}

GrammarParser::DirectiveContext* GrammarParser::UnitContext::directive() {
  return getRuleContext<GrammarParser::DirectiveContext>(0);
}

GrammarParser::Enum_extract2headerContext* GrammarParser::UnitContext::enum_extract2header() {
  return getRuleContext<GrammarParser::Enum_extract2headerContext>(0);
}

GrammarParser::Any_function_definitionContext* GrammarParser::UnitContext::any_function_definition() {
  return getRuleContext<GrammarParser::Any_function_definitionContext>(0);
}

GrammarParser::Scope_contentContext* GrammarParser::UnitContext::scope_content() {
  return getRuleContext<GrammarParser::Scope_contentContext>(0);
}


size_t GrammarParser::UnitContext::getRuleIndex() const {
  return GrammarParser::RuleUnit;
}

void GrammarParser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void GrammarParser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

GrammarParser::UnitContext* GrammarParser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 2, GrammarParser::RuleUnit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(254);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(249);
      property();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(250);
      directive();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(251);
      enum_extract2header();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(252);
      any_function_definition();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(253);
      scope_content();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_function_definitionContext ------------------------------------------------------------------

GrammarParser::Any_function_definitionContext::Any_function_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Function_definitionContext* GrammarParser::Any_function_definitionContext::function_definition() {
  return getRuleContext<GrammarParser::Function_definitionContext>(0);
}

GrammarParser::Append_scopeContext* GrammarParser::Any_function_definitionContext::append_scope() {
  return getRuleContext<GrammarParser::Append_scopeContext>(0);
}

tree::TerminalNode* GrammarParser::Any_function_definitionContext::SC() {
  return getToken(GrammarParser::SC, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Any_function_definitionContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Any_function_definitionContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::Entry_pointContext* GrammarParser::Any_function_definitionContext::entry_point() {
  return getRuleContext<GrammarParser::Entry_pointContext>(0);
}


size_t GrammarParser::Any_function_definitionContext::getRuleIndex() const {
  return GrammarParser::RuleAny_function_definition;
}

void GrammarParser::Any_function_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_function_definition(this);
}

void GrammarParser::Any_function_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_function_definition(this);
}

GrammarParser::Any_function_definitionContext* GrammarParser::any_function_definition() {
  Any_function_definitionContext *_localctx = _tracker.createInstance<Any_function_definitionContext>(_ctx, getState());
  enterRule(_localctx, 4, GrammarParser::RuleAny_function_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(270);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(256);
      function_definition();
      setState(265);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
      case 1: {
        setState(257);
        append_scope();
        break;
      }

      case 2: {
        setState(261);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GrammarParser::NEWLINE

        || _la == GrammarParser::WS) {
          setState(258);
          space();
          setState(263);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(264);
        match(GrammarParser::SC);
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(267);
      entry_point();
      setState(268);
      append_scope();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Append_scopeContext ------------------------------------------------------------------

GrammarParser::Append_scopeContext::Append_scopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Function_scopeContext* GrammarParser::Append_scopeContext::function_scope() {
  return getRuleContext<GrammarParser::Function_scopeContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Append_scopeContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Append_scopeContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Append_scopeContext::getRuleIndex() const {
  return GrammarParser::RuleAppend_scope;
}

void GrammarParser::Append_scopeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAppend_scope(this);
}

void GrammarParser::Append_scopeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAppend_scope(this);
}

GrammarParser::Append_scopeContext* GrammarParser::append_scope() {
  Append_scopeContext *_localctx = _tracker.createInstance<Append_scopeContext>(_ctx, getState());
  enterRule(_localctx, 6, GrammarParser::RuleAppend_scope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(275);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(272);
      space();
      setState(277);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(278);
    function_scope();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_scopeContext ------------------------------------------------------------------

GrammarParser::Function_scopeContext::Function_scopeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Function_scopeContext::OP_CRL_BR() {
  return getToken(GrammarParser::OP_CRL_BR, 0);
}

tree::TerminalNode* GrammarParser::Function_scopeContext::CL_CRL_BR() {
  return getToken(GrammarParser::CL_CRL_BR, 0);
}

std::vector<GrammarParser::Scope_contentContext *> GrammarParser::Function_scopeContext::scope_content() {
  return getRuleContexts<GrammarParser::Scope_contentContext>();
}

GrammarParser::Scope_contentContext* GrammarParser::Function_scopeContext::scope_content(size_t i) {
  return getRuleContext<GrammarParser::Scope_contentContext>(i);
}


size_t GrammarParser::Function_scopeContext::getRuleIndex() const {
  return GrammarParser::RuleFunction_scope;
}

void GrammarParser::Function_scopeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_scope(this);
}

void GrammarParser::Function_scopeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_scope(this);
}

GrammarParser::Function_scopeContext* GrammarParser::function_scope() {
  Function_scopeContext *_localctx = _tracker.createInstance<Function_scopeContext>(_ctx, getState());
  enterRule(_localctx, 8, GrammarParser::RuleFunction_scope);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    match(GrammarParser::OP_CRL_BR);
    setState(284);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
      | (1ULL << GrammarParser::COMMA)
      | (1ULL << GrammarParser::DOT)
      | (1ULL << GrammarParser::OP_BR)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::CL_PARETHESES)
      | (1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::COLON)
      | (1ULL << GrammarParser::SC)
      | (1ULL << GrammarParser::S_QUOTE)
      | (1ULL << GrammarParser::EQ)
      | (1ULL << GrammarParser::COMPARISSON)
      | (1ULL << GrammarParser::COMPARISSON_NOT)
      | (1ULL << GrammarParser::MORE_OR_EQUAL)
      | (1ULL << GrammarParser::LESS_OR_EQUAL)
      | (1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH)
      | (1ULL << GrammarParser::AMPERSAND)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::BD_SLASH)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC)
      | (1ULL << GrammarParser::K_STRICT)
      | (1ULL << GrammarParser::K_NULL)
      | (1ULL << GrammarParser::K_CONST)
      | (1ULL << GrammarParser::K_UNSIGNED)
      | (1ULL << GrammarParser::K_ENUM)
      | (1ULL << GrammarParser::K_ELSE)
      | (1ULL << GrammarParser::K_SWITCH)
      | (1ULL << GrammarParser::K_CASE)
      | (1ULL << GrammarParser::K_RETURN)
      | (1ULL << GrammarParser::K_FOR)
      | (1ULL << GrammarParser::K_IF)
      | (1ULL << GrammarParser::T_DOUBLE)
      | (1ULL << GrammarParser::T_FLOAT)
      | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
      | (1ULL << (GrammarParser::T_BOOL - 64))
      | (1ULL << (GrammarParser::T_LONG - 64))
      | (1ULL << (GrammarParser::T_SHORT - 64))
      | (1ULL << (GrammarParser::T_CHAR - 64))
      | (1ULL << (GrammarParser::T_STRING - 64))
      | (1ULL << (GrammarParser::T_COLOR - 64))
      | (1ULL << (GrammarParser::T_ULONG - 64))
      | (1ULL << (GrammarParser::T_DATETIME - 64))
      | (1ULL << (GrammarParser::PROPERTY - 64))
      | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
      | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
      | (1ULL << (GrammarParser::ALERT - 64))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
      | (1ULL << (GrammarParser::PLAY_SOUND - 64))
      | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
      | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
      | (1ULL << (GrammarParser::TIME_CURRENT - 64))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
      | (1ULL << (GrammarParser::IMA_MODE - 64))
      | (1ULL << (GrammarParser::PRICE_TYPE - 64))
      | (1ULL << (GrammarParser::TIMEFRAME - 64))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
      | (1ULL << (GrammarParser::REGULAR_STRING - 64))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
      | (1ULL << (GrammarParser::NAME - 64))
      | (1ULL << (GrammarParser::INTEGER - 64))
      | (1ULL << (GrammarParser::HEX_INTEGER - 64))
      | (1ULL << (GrammarParser::DATE_LITERAL - 64))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
      | (1ULL << (GrammarParser::ANY - 64))
      | (1ULL << (GrammarParser::MANY - 64)))) != 0)) {
      setState(281);
      scope_content();
      setState(286);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(287);
    match(GrammarParser::CL_CRL_BR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Scope_contentContext ------------------------------------------------------------------

GrammarParser::Scope_contentContext::Scope_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Return_statementContext* GrammarParser::Scope_contentContext::return_statement() {
  return getRuleContext<GrammarParser::Return_statementContext>(0);
}

GrammarParser::Function_scopeContext* GrammarParser::Scope_contentContext::function_scope() {
  return getRuleContext<GrammarParser::Function_scopeContext>(0);
}

GrammarParser::Commented_blockContext* GrammarParser::Scope_contentContext::commented_block() {
  return getRuleContext<GrammarParser::Commented_blockContext>(0);
}

GrammarParser::Modifier_variable_declarationContext* GrammarParser::Scope_contentContext::modifier_variable_declaration() {
  return getRuleContext<GrammarParser::Modifier_variable_declarationContext>(0);
}

GrammarParser::For_loopContext* GrammarParser::Scope_contentContext::for_loop() {
  return getRuleContext<GrammarParser::For_loopContext>(0);
}

GrammarParser::Function_callContext* GrammarParser::Scope_contentContext::function_call() {
  return getRuleContext<GrammarParser::Function_callContext>(0);
}

GrammarParser::Variable_change_valueContext* GrammarParser::Scope_contentContext::variable_change_value() {
  return getRuleContext<GrammarParser::Variable_change_valueContext>(0);
}

GrammarParser::Subscript_operatorContext* GrammarParser::Scope_contentContext::subscript_operator() {
  return getRuleContext<GrammarParser::Subscript_operatorContext>(0);
}

GrammarParser::Sq_argumentsContext* GrammarParser::Scope_contentContext::sq_arguments() {
  return getRuleContext<GrammarParser::Sq_argumentsContext>(0);
}

GrammarParser::Single_nameContext* GrammarParser::Scope_contentContext::single_name() {
  return getRuleContext<GrammarParser::Single_nameContext>(0);
}

GrammarParser::DirectiveContext* GrammarParser::Scope_contentContext::directive() {
  return getRuleContext<GrammarParser::DirectiveContext>(0);
}

GrammarParser::Datetime_litteralContext* GrammarParser::Scope_contentContext::datetime_litteral() {
  return getRuleContext<GrammarParser::Datetime_litteralContext>(0);
}

GrammarParser::Color_litteralContext* GrammarParser::Scope_contentContext::color_litteral() {
  return getRuleContext<GrammarParser::Color_litteralContext>(0);
}

GrammarParser::SpaceContext* GrammarParser::Scope_contentContext::space() {
  return getRuleContext<GrammarParser::SpaceContext>(0);
}

GrammarParser::PropertyContext* GrammarParser::Scope_contentContext::property() {
  return getRuleContext<GrammarParser::PropertyContext>(0);
}

GrammarParser::Any_lexContext* GrammarParser::Scope_contentContext::any_lex() {
  return getRuleContext<GrammarParser::Any_lexContext>(0);
}


size_t GrammarParser::Scope_contentContext::getRuleIndex() const {
  return GrammarParser::RuleScope_content;
}

void GrammarParser::Scope_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScope_content(this);
}

void GrammarParser::Scope_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScope_content(this);
}

GrammarParser::Scope_contentContext* GrammarParser::scope_content() {
  Scope_contentContext *_localctx = _tracker.createInstance<Scope_contentContext>(_ctx, getState());
  enterRule(_localctx, 10, GrammarParser::RuleScope_content);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(305);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(289);
      return_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(290);
      function_scope();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(291);
      commented_block();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(292);
      modifier_variable_declaration();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(293);
      for_loop();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(294);
      function_call();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(295);
      variable_change_value();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(296);
      subscript_operator();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(297);
      sq_arguments();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(298);
      single_name();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(299);
      directive();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(300);
      datetime_litteral();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(301);
      color_litteral();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(302);
      space();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(303);
      property();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(304);
      any_lex();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_statementContext ------------------------------------------------------------------

GrammarParser::Return_statementContext::Return_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Void_returnContext* GrammarParser::Return_statementContext::void_return() {
  return getRuleContext<GrammarParser::Void_returnContext>(0);
}

GrammarParser::Standart_returnContext* GrammarParser::Return_statementContext::standart_return() {
  return getRuleContext<GrammarParser::Standart_returnContext>(0);
}


size_t GrammarParser::Return_statementContext::getRuleIndex() const {
  return GrammarParser::RuleReturn_statement;
}

void GrammarParser::Return_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_statement(this);
}

void GrammarParser::Return_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_statement(this);
}

GrammarParser::Return_statementContext* GrammarParser::return_statement() {
  Return_statementContext *_localctx = _tracker.createInstance<Return_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, GrammarParser::RuleReturn_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(309);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(307);
      void_return();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(308);
      standart_return();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Void_returnContext ------------------------------------------------------------------

GrammarParser::Void_returnContext::Void_returnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Void_returnContext::K_RETURN() {
  return getToken(GrammarParser::K_RETURN, 0);
}

tree::TerminalNode* GrammarParser::Void_returnContext::SC() {
  return getToken(GrammarParser::SC, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Void_returnContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Void_returnContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Void_returnContext::getRuleIndex() const {
  return GrammarParser::RuleVoid_return;
}

void GrammarParser::Void_returnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVoid_return(this);
}

void GrammarParser::Void_returnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVoid_return(this);
}

GrammarParser::Void_returnContext* GrammarParser::void_return() {
  Void_returnContext *_localctx = _tracker.createInstance<Void_returnContext>(_ctx, getState());
  enterRule(_localctx, 14, GrammarParser::RuleVoid_return);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(311);
    match(GrammarParser::K_RETURN);
    setState(315);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(312);
      space();
      setState(317);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(318);
    match(GrammarParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Standart_returnContext ------------------------------------------------------------------

GrammarParser::Standart_returnContext::Standart_returnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Standart_returnContext::K_RETURN() {
  return getToken(GrammarParser::K_RETURN, 0);
}

GrammarParser::Parantheses_any_expressionContext* GrammarParser::Standart_returnContext::parantheses_any_expression() {
  return getRuleContext<GrammarParser::Parantheses_any_expressionContext>(0);
}

tree::TerminalNode* GrammarParser::Standart_returnContext::SC() {
  return getToken(GrammarParser::SC, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Standart_returnContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Standart_returnContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Standart_returnContext::getRuleIndex() const {
  return GrammarParser::RuleStandart_return;
}

void GrammarParser::Standart_returnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStandart_return(this);
}

void GrammarParser::Standart_returnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStandart_return(this);
}

GrammarParser::Standart_returnContext* GrammarParser::standart_return() {
  Standart_returnContext *_localctx = _tracker.createInstance<Standart_returnContext>(_ctx, getState());
  enterRule(_localctx, 16, GrammarParser::RuleStandart_return);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(320);
    match(GrammarParser::K_RETURN);
    setState(324);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(321);
      space();
      setState(326);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(327);
    parantheses_any_expression();
    setState(331);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(328);
      space();
      setState(333);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(334);
    match(GrammarParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_loopContext ------------------------------------------------------------------

GrammarParser::For_loopContext::For_loopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::For_loopContext::K_FOR() {
  return getToken(GrammarParser::K_FOR, 0);
}

tree::TerminalNode* GrammarParser::For_loopContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

GrammarParser::For_loop_declarationContext* GrammarParser::For_loopContext::for_loop_declaration() {
  return getRuleContext<GrammarParser::For_loop_declarationContext>(0);
}

GrammarParser::For_loop_conditionContext* GrammarParser::For_loopContext::for_loop_condition() {
  return getRuleContext<GrammarParser::For_loop_conditionContext>(0);
}

GrammarParser::For_loop_incrementContext* GrammarParser::For_loopContext::for_loop_increment() {
  return getRuleContext<GrammarParser::For_loop_incrementContext>(0);
}

tree::TerminalNode* GrammarParser::For_loopContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::For_loopContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::For_loopContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::For_loopContext::getRuleIndex() const {
  return GrammarParser::RuleFor_loop;
}

void GrammarParser::For_loopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_loop(this);
}

void GrammarParser::For_loopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_loop(this);
}

GrammarParser::For_loopContext* GrammarParser::for_loop() {
  For_loopContext *_localctx = _tracker.createInstance<For_loopContext>(_ctx, getState());
  enterRule(_localctx, 18, GrammarParser::RuleFor_loop);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(336);
    match(GrammarParser::K_FOR);
    setState(340);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(337);
      space();
      setState(342);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(343);
    match(GrammarParser::OP_PARETHESES);
    setState(344);
    for_loop_declaration();
    setState(345);
    for_loop_condition();
    setState(346);
    for_loop_increment();
    setState(347);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_loop_declarationContext ------------------------------------------------------------------

GrammarParser::For_loop_declarationContext::For_loop_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::For_loop_variable_declContext* GrammarParser::For_loop_declarationContext::for_loop_variable_decl() {
  return getRuleContext<GrammarParser::For_loop_variable_declContext>(0);
}

GrammarParser::Variable_change_valueContext* GrammarParser::For_loop_declarationContext::variable_change_value() {
  return getRuleContext<GrammarParser::Variable_change_valueContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::For_loop_declarationContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::For_loop_declarationContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::For_loop_declarationContext::getRuleIndex() const {
  return GrammarParser::RuleFor_loop_declaration;
}

void GrammarParser::For_loop_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_loop_declaration(this);
}

void GrammarParser::For_loop_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_loop_declaration(this);
}

GrammarParser::For_loop_declarationContext* GrammarParser::for_loop_declaration() {
  For_loop_declarationContext *_localctx = _tracker.createInstance<For_loop_declarationContext>(_ctx, getState());
  enterRule(_localctx, 20, GrammarParser::RuleFor_loop_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(352);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(349);
      space();
      setState(354);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(357);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(355);
      for_loop_variable_decl();
      break;
    }

    case 2: {
      setState(356);
      variable_change_value();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_loop_variable_declContext ------------------------------------------------------------------

GrammarParser::For_loop_variable_declContext::For_loop_variable_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::For_loop_variable_declContext::SC() {
  return getToken(GrammarParser::SC, 0);
}

GrammarParser::Variable_declarationContext* GrammarParser::For_loop_variable_declContext::variable_declaration() {
  return getRuleContext<GrammarParser::Variable_declarationContext>(0);
}

std::vector<GrammarParser::Append_variable_declarationContext *> GrammarParser::For_loop_variable_declContext::append_variable_declaration() {
  return getRuleContexts<GrammarParser::Append_variable_declarationContext>();
}

GrammarParser::Append_variable_declarationContext* GrammarParser::For_loop_variable_declContext::append_variable_declaration(size_t i) {
  return getRuleContext<GrammarParser::Append_variable_declarationContext>(i);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::For_loop_variable_declContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::For_loop_variable_declContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::For_loop_variable_declContext::getRuleIndex() const {
  return GrammarParser::RuleFor_loop_variable_decl;
}

void GrammarParser::For_loop_variable_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_loop_variable_decl(this);
}

void GrammarParser::For_loop_variable_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_loop_variable_decl(this);
}

GrammarParser::For_loop_variable_declContext* GrammarParser::for_loop_variable_decl() {
  For_loop_variable_declContext *_localctx = _tracker.createInstance<For_loop_variable_declContext>(_ctx, getState());
  enterRule(_localctx, 22, GrammarParser::RuleFor_loop_variable_decl);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(372);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & ((1ULL << (GrammarParser::K_CONST - 52))
      | (1ULL << (GrammarParser::K_UNSIGNED - 52))
      | (1ULL << (GrammarParser::T_DOUBLE - 52))
      | (1ULL << (GrammarParser::T_FLOAT - 52))
      | (1ULL << (GrammarParser::T_VOID - 52))
      | (1ULL << (GrammarParser::T_INT - 52))
      | (1ULL << (GrammarParser::T_BOOL - 52))
      | (1ULL << (GrammarParser::T_LONG - 52))
      | (1ULL << (GrammarParser::T_SHORT - 52))
      | (1ULL << (GrammarParser::T_CHAR - 52))
      | (1ULL << (GrammarParser::T_STRING - 52))
      | (1ULL << (GrammarParser::T_COLOR - 52))
      | (1ULL << (GrammarParser::T_ULONG - 52))
      | (1ULL << (GrammarParser::T_DATETIME - 52))
      | (1ULL << (GrammarParser::NAME - 52)))) != 0)) {
      setState(359);
      variable_declaration();
      setState(363);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(360);
          append_variable_declaration(); 
        }
        setState(365);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
      }
      setState(369);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(366);
        space();
        setState(371);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(374);
    match(GrammarParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_loop_conditionContext ------------------------------------------------------------------

GrammarParser::For_loop_conditionContext::For_loop_conditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::For_loop_conditionContext::SC() {
  return getToken(GrammarParser::SC, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::For_loop_conditionContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::For_loop_conditionContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

std::vector<GrammarParser::RvalueContext *> GrammarParser::For_loop_conditionContext::rvalue() {
  return getRuleContexts<GrammarParser::RvalueContext>();
}

GrammarParser::RvalueContext* GrammarParser::For_loop_conditionContext::rvalue(size_t i) {
  return getRuleContext<GrammarParser::RvalueContext>(i);
}


size_t GrammarParser::For_loop_conditionContext::getRuleIndex() const {
  return GrammarParser::RuleFor_loop_condition;
}

void GrammarParser::For_loop_conditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_loop_condition(this);
}

void GrammarParser::For_loop_conditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_loop_condition(this);
}

GrammarParser::For_loop_conditionContext* GrammarParser::for_loop_condition() {
  For_loop_conditionContext *_localctx = _tracker.createInstance<For_loop_conditionContext>(_ctx, getState());
  enterRule(_localctx, 24, GrammarParser::RuleFor_loop_condition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(379);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(376);
        space(); 
      }
      setState(381);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
    setState(393);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
      | (1ULL << GrammarParser::DOT)
      | (1ULL << GrammarParser::OP_BR)
      | (1ULL << GrammarParser::CL_BR)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::CL_CRL_BR)
      | (1ULL << GrammarParser::COLON)
      | (1ULL << GrammarParser::D_QUOTE)
      | (1ULL << GrammarParser::S_QUOTE)
      | (1ULL << GrammarParser::EQ)
      | (1ULL << GrammarParser::COMPARISSON)
      | (1ULL << GrammarParser::COMPARISSON_NOT)
      | (1ULL << GrammarParser::MORE_OR_EQUAL)
      | (1ULL << GrammarParser::LESS_OR_EQUAL)
      | (1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH)
      | (1ULL << GrammarParser::AMPERSAND)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::BD_SLASH)
      | (1ULL << GrammarParser::OP_COMMENT)
      | (1ULL << GrammarParser::CL_COMMENT)
      | (1ULL << GrammarParser::MULTILINE_COMMENT)
      | (1ULL << GrammarParser::ONELINE_COMMENT)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::ON_CHART_EVENT)
      | (1ULL << GrammarParser::TRY_BLOCK_DASH)
      | (1ULL << GrammarParser::TRY_BLOCK_START)
      | (1ULL << GrammarParser::TRY_BLOCK_END)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC)
      | (1ULL << GrammarParser::K_STRICT)
      | (1ULL << GrammarParser::K_NULL)
      | (1ULL << GrammarParser::K_CONST)
      | (1ULL << GrammarParser::K_UNSIGNED)
      | (1ULL << GrammarParser::K_ENUM)
      | (1ULL << GrammarParser::K_ELSE)
      | (1ULL << GrammarParser::K_SWITCH)
      | (1ULL << GrammarParser::K_CASE)
      | (1ULL << GrammarParser::K_RETURN)
      | (1ULL << GrammarParser::K_FOR)
      | (1ULL << GrammarParser::K_IF)
      | (1ULL << GrammarParser::T_DOUBLE)
      | (1ULL << GrammarParser::T_FLOAT)
      | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
      | (1ULL << (GrammarParser::T_BOOL - 64))
      | (1ULL << (GrammarParser::T_LONG - 64))
      | (1ULL << (GrammarParser::T_SHORT - 64))
      | (1ULL << (GrammarParser::T_CHAR - 64))
      | (1ULL << (GrammarParser::T_STRING - 64))
      | (1ULL << (GrammarParser::T_COLOR - 64))
      | (1ULL << (GrammarParser::T_ULONG - 64))
      | (1ULL << (GrammarParser::T_DATETIME - 64))
      | (1ULL << (GrammarParser::PROPERTY - 64))
      | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
      | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
      | (1ULL << (GrammarParser::ALERT - 64))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
      | (1ULL << (GrammarParser::PLAY_SOUND - 64))
      | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
      | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
      | (1ULL << (GrammarParser::TIME_CURRENT - 64))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
      | (1ULL << (GrammarParser::IMA_MODE - 64))
      | (1ULL << (GrammarParser::PRICE_TYPE - 64))
      | (1ULL << (GrammarParser::TIMEFRAME - 64))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
      | (1ULL << (GrammarParser::REGULAR_STRING - 64))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
      | (1ULL << (GrammarParser::NAME - 64))
      | (1ULL << (GrammarParser::INTEGER - 64))
      | (1ULL << (GrammarParser::HEX_INTEGER - 64))
      | (1ULL << (GrammarParser::DATE_LITERAL - 64))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
      | (1ULL << (GrammarParser::LETTER - 64))
      | (1ULL << (GrammarParser::DIGIT - 64))
      | (1ULL << (GrammarParser::ANY - 64))
      | (1ULL << (GrammarParser::MANY - 64)))) != 0)) {
      setState(383); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(382);
                rvalue();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(385); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(390);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(387);
        space();
        setState(392);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(395);
    match(GrammarParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_loop_incrementContext ------------------------------------------------------------------

GrammarParser::For_loop_incrementContext::For_loop_incrementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::For_loop_incrementContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::For_loop_incrementContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::Variable_modify_rulesContext* GrammarParser::For_loop_incrementContext::variable_modify_rules() {
  return getRuleContext<GrammarParser::Variable_modify_rulesContext>(0);
}

std::vector<GrammarParser::For_loop_append_incrementContext *> GrammarParser::For_loop_incrementContext::for_loop_append_increment() {
  return getRuleContexts<GrammarParser::For_loop_append_incrementContext>();
}

GrammarParser::For_loop_append_incrementContext* GrammarParser::For_loop_incrementContext::for_loop_append_increment(size_t i) {
  return getRuleContext<GrammarParser::For_loop_append_incrementContext>(i);
}


size_t GrammarParser::For_loop_incrementContext::getRuleIndex() const {
  return GrammarParser::RuleFor_loop_increment;
}

void GrammarParser::For_loop_incrementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_loop_increment(this);
}

void GrammarParser::For_loop_incrementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_loop_increment(this);
}

GrammarParser::For_loop_incrementContext* GrammarParser::for_loop_increment() {
  For_loop_incrementContext *_localctx = _tracker.createInstance<For_loop_incrementContext>(_ctx, getState());
  enterRule(_localctx, 26, GrammarParser::RuleFor_loop_increment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(400);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(397);
      space();
      setState(402);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(416);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE))) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 76)) & ((1ULL << (GrammarParser::ALERT - 76))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 76))
      | (1ULL << (GrammarParser::PLAY_SOUND - 76))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 76))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 76))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 76))
      | (1ULL << (GrammarParser::NAME - 76)))) != 0)) {
      setState(403);
      variable_modify_rules();
      setState(407);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(404);
          for_loop_append_increment(); 
        }
        setState(409);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
      }
      setState(413);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(410);
        space();
        setState(415);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_loop_append_incrementContext ------------------------------------------------------------------

GrammarParser::For_loop_append_incrementContext::For_loop_append_incrementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::For_loop_append_incrementContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

GrammarParser::Variable_modify_rulesContext* GrammarParser::For_loop_append_incrementContext::variable_modify_rules() {
  return getRuleContext<GrammarParser::Variable_modify_rulesContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::For_loop_append_incrementContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::For_loop_append_incrementContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::For_loop_append_incrementContext::getRuleIndex() const {
  return GrammarParser::RuleFor_loop_append_increment;
}

void GrammarParser::For_loop_append_incrementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFor_loop_append_increment(this);
}

void GrammarParser::For_loop_append_incrementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFor_loop_append_increment(this);
}

GrammarParser::For_loop_append_incrementContext* GrammarParser::for_loop_append_increment() {
  For_loop_append_incrementContext *_localctx = _tracker.createInstance<For_loop_append_incrementContext>(_ctx, getState());
  enterRule(_localctx, 28, GrammarParser::RuleFor_loop_append_increment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(418);
      space();
      setState(423);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(424);
    match(GrammarParser::COMMA);
    setState(428);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(425);
      space();
      setState(430);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(431);
    variable_modify_rules();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RvalueContext ------------------------------------------------------------------

GrammarParser::RvalueContext::RvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Function_callContext* GrammarParser::RvalueContext::function_call() {
  return getRuleContext<GrammarParser::Function_callContext>(0);
}

GrammarParser::Subscript_operatorContext* GrammarParser::RvalueContext::subscript_operator() {
  return getRuleContext<GrammarParser::Subscript_operatorContext>(0);
}

GrammarParser::Sq_argumentsContext* GrammarParser::RvalueContext::sq_arguments() {
  return getRuleContext<GrammarParser::Sq_argumentsContext>(0);
}

GrammarParser::Datetime_litteralContext* GrammarParser::RvalueContext::datetime_litteral() {
  return getRuleContext<GrammarParser::Datetime_litteralContext>(0);
}

GrammarParser::Variable_change_valueContext* GrammarParser::RvalueContext::variable_change_value() {
  return getRuleContext<GrammarParser::Variable_change_valueContext>(0);
}

GrammarParser::Color_litteralContext* GrammarParser::RvalueContext::color_litteral() {
  return getRuleContext<GrammarParser::Color_litteralContext>(0);
}

GrammarParser::Parantheses_any_expressionContext* GrammarParser::RvalueContext::parantheses_any_expression() {
  return getRuleContext<GrammarParser::Parantheses_any_expressionContext>(0);
}

GrammarParser::NameContext* GrammarParser::RvalueContext::name() {
  return getRuleContext<GrammarParser::NameContext>(0);
}

GrammarParser::Single_nameContext* GrammarParser::RvalueContext::single_name() {
  return getRuleContext<GrammarParser::Single_nameContext>(0);
}

GrammarParser::No_parant_comma_scContext* GrammarParser::RvalueContext::no_parant_comma_sc() {
  return getRuleContext<GrammarParser::No_parant_comma_scContext>(0);
}


size_t GrammarParser::RvalueContext::getRuleIndex() const {
  return GrammarParser::RuleRvalue;
}

void GrammarParser::RvalueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRvalue(this);
}

void GrammarParser::RvalueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRvalue(this);
}

GrammarParser::RvalueContext* GrammarParser::rvalue() {
  RvalueContext *_localctx = _tracker.createInstance<RvalueContext>(_ctx, getState());
  enterRule(_localctx, 30, GrammarParser::RuleRvalue);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(443);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(433);
      function_call();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(434);
      subscript_operator();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(435);
      sq_arguments();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(436);
      datetime_litteral();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(437);
      variable_change_value();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(438);
      color_litteral();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(439);
      parantheses_any_expression();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(440);
      name();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(441);
      single_name();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(442);
      no_parant_comma_sc();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parantheses_any_expressionContext ------------------------------------------------------------------

GrammarParser::Parantheses_any_expressionContext::Parantheses_any_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Parantheses_any_expressionContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Parantheses_any_expressionContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

GrammarParser::Parantheses_contentContext* GrammarParser::Parantheses_any_expressionContext::parantheses_content() {
  return getRuleContext<GrammarParser::Parantheses_contentContext>(0);
}


size_t GrammarParser::Parantheses_any_expressionContext::getRuleIndex() const {
  return GrammarParser::RuleParantheses_any_expression;
}

void GrammarParser::Parantheses_any_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParantheses_any_expression(this);
}

void GrammarParser::Parantheses_any_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParantheses_any_expression(this);
}

GrammarParser::Parantheses_any_expressionContext* GrammarParser::parantheses_any_expression() {
  Parantheses_any_expressionContext *_localctx = _tracker.createInstance<Parantheses_any_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, GrammarParser::RuleParantheses_any_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(445);
    match(GrammarParser::OP_PARETHESES);
    setState(447);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
      | (1ULL << GrammarParser::COMMA)
      | (1ULL << GrammarParser::DOT)
      | (1ULL << GrammarParser::OP_BR)
      | (1ULL << GrammarParser::CL_BR)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::CL_CRL_BR)
      | (1ULL << GrammarParser::COLON)
      | (1ULL << GrammarParser::D_QUOTE)
      | (1ULL << GrammarParser::S_QUOTE)
      | (1ULL << GrammarParser::EQ)
      | (1ULL << GrammarParser::COMPARISSON)
      | (1ULL << GrammarParser::COMPARISSON_NOT)
      | (1ULL << GrammarParser::MORE_OR_EQUAL)
      | (1ULL << GrammarParser::LESS_OR_EQUAL)
      | (1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH)
      | (1ULL << GrammarParser::AMPERSAND)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::BD_SLASH)
      | (1ULL << GrammarParser::OP_COMMENT)
      | (1ULL << GrammarParser::CL_COMMENT)
      | (1ULL << GrammarParser::MULTILINE_COMMENT)
      | (1ULL << GrammarParser::ONELINE_COMMENT)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::ON_CHART_EVENT)
      | (1ULL << GrammarParser::TRY_BLOCK_DASH)
      | (1ULL << GrammarParser::TRY_BLOCK_START)
      | (1ULL << GrammarParser::TRY_BLOCK_END)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC)
      | (1ULL << GrammarParser::K_STRICT)
      | (1ULL << GrammarParser::K_NULL)
      | (1ULL << GrammarParser::K_CONST)
      | (1ULL << GrammarParser::K_UNSIGNED)
      | (1ULL << GrammarParser::K_ENUM)
      | (1ULL << GrammarParser::K_ELSE)
      | (1ULL << GrammarParser::K_SWITCH)
      | (1ULL << GrammarParser::K_CASE)
      | (1ULL << GrammarParser::K_RETURN)
      | (1ULL << GrammarParser::K_FOR)
      | (1ULL << GrammarParser::K_IF)
      | (1ULL << GrammarParser::T_DOUBLE)
      | (1ULL << GrammarParser::T_FLOAT)
      | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
      | (1ULL << (GrammarParser::T_BOOL - 64))
      | (1ULL << (GrammarParser::T_LONG - 64))
      | (1ULL << (GrammarParser::T_SHORT - 64))
      | (1ULL << (GrammarParser::T_CHAR - 64))
      | (1ULL << (GrammarParser::T_STRING - 64))
      | (1ULL << (GrammarParser::T_COLOR - 64))
      | (1ULL << (GrammarParser::T_ULONG - 64))
      | (1ULL << (GrammarParser::T_DATETIME - 64))
      | (1ULL << (GrammarParser::PROPERTY - 64))
      | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
      | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
      | (1ULL << (GrammarParser::ALERT - 64))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
      | (1ULL << (GrammarParser::PLAY_SOUND - 64))
      | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
      | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
      | (1ULL << (GrammarParser::TIME_CURRENT - 64))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
      | (1ULL << (GrammarParser::IMA_MODE - 64))
      | (1ULL << (GrammarParser::PRICE_TYPE - 64))
      | (1ULL << (GrammarParser::TIMEFRAME - 64))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
      | (1ULL << (GrammarParser::REGULAR_STRING - 64))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
      | (1ULL << (GrammarParser::NAME - 64))
      | (1ULL << (GrammarParser::INTEGER - 64))
      | (1ULL << (GrammarParser::HEX_INTEGER - 64))
      | (1ULL << (GrammarParser::DATE_LITERAL - 64))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
      | (1ULL << (GrammarParser::LETTER - 64))
      | (1ULL << (GrammarParser::DIGIT - 64))
      | (1ULL << (GrammarParser::ANY - 64))
      | (1ULL << (GrammarParser::MANY - 64)))) != 0)) {
      setState(446);
      parantheses_content();
    }
    setState(449);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parantheses_contentContext ------------------------------------------------------------------

GrammarParser::Parantheses_contentContext::Parantheses_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::Parantheses_content_expressionContext *> GrammarParser::Parantheses_contentContext::parantheses_content_expression() {
  return getRuleContexts<GrammarParser::Parantheses_content_expressionContext>();
}

GrammarParser::Parantheses_content_expressionContext* GrammarParser::Parantheses_contentContext::parantheses_content_expression(size_t i) {
  return getRuleContext<GrammarParser::Parantheses_content_expressionContext>(i);
}


size_t GrammarParser::Parantheses_contentContext::getRuleIndex() const {
  return GrammarParser::RuleParantheses_content;
}

void GrammarParser::Parantheses_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParantheses_content(this);
}

void GrammarParser::Parantheses_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParantheses_content(this);
}

GrammarParser::Parantheses_contentContext* GrammarParser::parantheses_content() {
  Parantheses_contentContext *_localctx = _tracker.createInstance<Parantheses_contentContext>(_ctx, getState());
  enterRule(_localctx, 34, GrammarParser::RuleParantheses_content);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(451);
      parantheses_content_expression();
      setState(454); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
      | (1ULL << GrammarParser::COMMA)
      | (1ULL << GrammarParser::DOT)
      | (1ULL << GrammarParser::OP_BR)
      | (1ULL << GrammarParser::CL_BR)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::CL_CRL_BR)
      | (1ULL << GrammarParser::COLON)
      | (1ULL << GrammarParser::D_QUOTE)
      | (1ULL << GrammarParser::S_QUOTE)
      | (1ULL << GrammarParser::EQ)
      | (1ULL << GrammarParser::COMPARISSON)
      | (1ULL << GrammarParser::COMPARISSON_NOT)
      | (1ULL << GrammarParser::MORE_OR_EQUAL)
      | (1ULL << GrammarParser::LESS_OR_EQUAL)
      | (1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH)
      | (1ULL << GrammarParser::AMPERSAND)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::BD_SLASH)
      | (1ULL << GrammarParser::OP_COMMENT)
      | (1ULL << GrammarParser::CL_COMMENT)
      | (1ULL << GrammarParser::MULTILINE_COMMENT)
      | (1ULL << GrammarParser::ONELINE_COMMENT)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::ON_CHART_EVENT)
      | (1ULL << GrammarParser::TRY_BLOCK_DASH)
      | (1ULL << GrammarParser::TRY_BLOCK_START)
      | (1ULL << GrammarParser::TRY_BLOCK_END)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC)
      | (1ULL << GrammarParser::K_STRICT)
      | (1ULL << GrammarParser::K_NULL)
      | (1ULL << GrammarParser::K_CONST)
      | (1ULL << GrammarParser::K_UNSIGNED)
      | (1ULL << GrammarParser::K_ENUM)
      | (1ULL << GrammarParser::K_ELSE)
      | (1ULL << GrammarParser::K_SWITCH)
      | (1ULL << GrammarParser::K_CASE)
      | (1ULL << GrammarParser::K_RETURN)
      | (1ULL << GrammarParser::K_FOR)
      | (1ULL << GrammarParser::K_IF)
      | (1ULL << GrammarParser::T_DOUBLE)
      | (1ULL << GrammarParser::T_FLOAT)
      | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
      | (1ULL << (GrammarParser::T_BOOL - 64))
      | (1ULL << (GrammarParser::T_LONG - 64))
      | (1ULL << (GrammarParser::T_SHORT - 64))
      | (1ULL << (GrammarParser::T_CHAR - 64))
      | (1ULL << (GrammarParser::T_STRING - 64))
      | (1ULL << (GrammarParser::T_COLOR - 64))
      | (1ULL << (GrammarParser::T_ULONG - 64))
      | (1ULL << (GrammarParser::T_DATETIME - 64))
      | (1ULL << (GrammarParser::PROPERTY - 64))
      | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
      | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
      | (1ULL << (GrammarParser::ALERT - 64))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
      | (1ULL << (GrammarParser::PLAY_SOUND - 64))
      | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
      | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
      | (1ULL << (GrammarParser::TIME_CURRENT - 64))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
      | (1ULL << (GrammarParser::IMA_MODE - 64))
      | (1ULL << (GrammarParser::PRICE_TYPE - 64))
      | (1ULL << (GrammarParser::TIMEFRAME - 64))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
      | (1ULL << (GrammarParser::REGULAR_STRING - 64))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
      | (1ULL << (GrammarParser::NAME - 64))
      | (1ULL << (GrammarParser::INTEGER - 64))
      | (1ULL << (GrammarParser::HEX_INTEGER - 64))
      | (1ULL << (GrammarParser::DATE_LITERAL - 64))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
      | (1ULL << (GrammarParser::LETTER - 64))
      | (1ULL << (GrammarParser::DIGIT - 64))
      | (1ULL << (GrammarParser::ANY - 64))
      | (1ULL << (GrammarParser::MANY - 64)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parantheses_content_expressionContext ------------------------------------------------------------------

GrammarParser::Parantheses_content_expressionContext::Parantheses_content_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::RvalueContext* GrammarParser::Parantheses_content_expressionContext::rvalue() {
  return getRuleContext<GrammarParser::RvalueContext>(0);
}

GrammarParser::No_parant_scContext* GrammarParser::Parantheses_content_expressionContext::no_parant_sc() {
  return getRuleContext<GrammarParser::No_parant_scContext>(0);
}


size_t GrammarParser::Parantheses_content_expressionContext::getRuleIndex() const {
  return GrammarParser::RuleParantheses_content_expression;
}

void GrammarParser::Parantheses_content_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParantheses_content_expression(this);
}

void GrammarParser::Parantheses_content_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParantheses_content_expression(this);
}

GrammarParser::Parantheses_content_expressionContext* GrammarParser::parantheses_content_expression() {
  Parantheses_content_expressionContext *_localctx = _tracker.createInstance<Parantheses_content_expressionContext>(_ctx, getState());
  enterRule(_localctx, 36, GrammarParser::RuleParantheses_content_expression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(458);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(456);
      rvalue();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(457);
      no_parant_sc();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- No_parant_comma_scContext ------------------------------------------------------------------

GrammarParser::No_parant_comma_scContext::No_parant_comma_scContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::No_parant_comma_scContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::No_parant_comma_scContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::No_parant_comma_scContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

tree::TerminalNode* GrammarParser::No_parant_comma_scContext::SC() {
  return getToken(GrammarParser::SC, 0);
}


size_t GrammarParser::No_parant_comma_scContext::getRuleIndex() const {
  return GrammarParser::RuleNo_parant_comma_sc;
}

void GrammarParser::No_parant_comma_scContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNo_parant_comma_sc(this);
}

void GrammarParser::No_parant_comma_scContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNo_parant_comma_sc(this);
}

GrammarParser::No_parant_comma_scContext* GrammarParser::no_parant_comma_sc() {
  No_parant_comma_scContext *_localctx = _tracker.createInstance<No_parant_comma_scContext>(_ctx, getState());
  enterRule(_localctx, 38, GrammarParser::RuleNo_parant_comma_sc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    _la = _input->LA(1);
    if (_la == 0 || _la == Token::EOF || ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::COMMA)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::CL_PARETHESES)
      | (1ULL << GrammarParser::SC))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- No_parant_scContext ------------------------------------------------------------------

GrammarParser::No_parant_scContext::No_parant_scContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::No_parant_scContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::No_parant_scContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::No_parant_scContext::SC() {
  return getToken(GrammarParser::SC, 0);
}


size_t GrammarParser::No_parant_scContext::getRuleIndex() const {
  return GrammarParser::RuleNo_parant_sc;
}

void GrammarParser::No_parant_scContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNo_parant_sc(this);
}

void GrammarParser::No_parant_scContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNo_parant_sc(this);
}

GrammarParser::No_parant_scContext* GrammarParser::no_parant_sc() {
  No_parant_scContext *_localctx = _tracker.createInstance<No_parant_scContext>(_ctx, getState());
  enterRule(_localctx, 40, GrammarParser::RuleNo_parant_sc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    _la = _input->LA(1);
    if (_la == 0 || _la == Token::EOF || ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::CL_PARETHESES)
      | (1ULL << GrammarParser::SC))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_contentContext ------------------------------------------------------------------

GrammarParser::Argument_contentContext::Argument_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Commented_blockContext* GrammarParser::Argument_contentContext::commented_block() {
  return getRuleContext<GrammarParser::Commented_blockContext>(0);
}

GrammarParser::Function_callContext* GrammarParser::Argument_contentContext::function_call() {
  return getRuleContext<GrammarParser::Function_callContext>(0);
}

GrammarParser::Subscript_operatorContext* GrammarParser::Argument_contentContext::subscript_operator() {
  return getRuleContext<GrammarParser::Subscript_operatorContext>(0);
}

GrammarParser::Sq_argumentsContext* GrammarParser::Argument_contentContext::sq_arguments() {
  return getRuleContext<GrammarParser::Sq_argumentsContext>(0);
}

GrammarParser::Single_nameContext* GrammarParser::Argument_contentContext::single_name() {
  return getRuleContext<GrammarParser::Single_nameContext>(0);
}

GrammarParser::NameContext* GrammarParser::Argument_contentContext::name() {
  return getRuleContext<GrammarParser::NameContext>(0);
}

GrammarParser::Variable_change_valueContext* GrammarParser::Argument_contentContext::variable_change_value() {
  return getRuleContext<GrammarParser::Variable_change_valueContext>(0);
}

GrammarParser::SpaceContext* GrammarParser::Argument_contentContext::space() {
  return getRuleContext<GrammarParser::SpaceContext>(0);
}


size_t GrammarParser::Argument_contentContext::getRuleIndex() const {
  return GrammarParser::RuleArgument_content;
}

void GrammarParser::Argument_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_content(this);
}

void GrammarParser::Argument_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_content(this);
}

GrammarParser::Argument_contentContext* GrammarParser::argument_content() {
  Argument_contentContext *_localctx = _tracker.createInstance<Argument_contentContext>(_ctx, getState());
  enterRule(_localctx, 42, GrammarParser::RuleArgument_content);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(472);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(464);
      commented_block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(465);
      function_call();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(466);
      subscript_operator();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(467);
      sq_arguments();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(468);
      single_name();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(469);
      name();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(470);
      variable_change_value();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(471);
      space();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Commented_blockContext ------------------------------------------------------------------

GrammarParser::Commented_blockContext::Commented_blockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Tryblock_replacement_startContext* GrammarParser::Commented_blockContext::tryblock_replacement_start() {
  return getRuleContext<GrammarParser::Tryblock_replacement_startContext>(0);
}

GrammarParser::Tryblock_replacement_endContext* GrammarParser::Commented_blockContext::tryblock_replacement_end() {
  return getRuleContext<GrammarParser::Tryblock_replacement_endContext>(0);
}


size_t GrammarParser::Commented_blockContext::getRuleIndex() const {
  return GrammarParser::RuleCommented_block;
}

void GrammarParser::Commented_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommented_block(this);
}

void GrammarParser::Commented_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommented_block(this);
}

GrammarParser::Commented_blockContext* GrammarParser::commented_block() {
  Commented_blockContext *_localctx = _tracker.createInstance<Commented_blockContext>(_ctx, getState());
  enterRule(_localctx, 44, GrammarParser::RuleCommented_block);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(476);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(474);
      tryblock_replacement_start();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(475);
      tryblock_replacement_end();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_callContext ------------------------------------------------------------------

GrammarParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::AlertContext* GrammarParser::Function_callContext::alert() {
  return getRuleContext<GrammarParser::AlertContext>(0);
}

GrammarParser::Add_bracketsContext* GrammarParser::Function_callContext::add_brackets() {
  return getRuleContext<GrammarParser::Add_bracketsContext>(0);
}

GrammarParser::Change_bracketsContext* GrammarParser::Function_callContext::change_brackets() {
  return getRuleContext<GrammarParser::Change_bracketsContext>(0);
}

GrammarParser::Return_datetimeContext* GrammarParser::Function_callContext::return_datetime() {
  return getRuleContext<GrammarParser::Return_datetimeContext>(0);
}

GrammarParser::Indicator_buffers_funcContext* GrammarParser::Function_callContext::indicator_buffers_func() {
  return getRuleContext<GrammarParser::Indicator_buffers_funcContext>(0);
}

GrammarParser::Set_index_bufferContext* GrammarParser::Function_callContext::set_index_buffer() {
  return getRuleContext<GrammarParser::Set_index_bufferContext>(0);
}

GrammarParser::Set_level_styleContext* GrammarParser::Function_callContext::set_level_style() {
  return getRuleContext<GrammarParser::Set_level_styleContext>(0);
}

GrammarParser::Any_function_callContext* GrammarParser::Function_callContext::any_function_call() {
  return getRuleContext<GrammarParser::Any_function_callContext>(0);
}


size_t GrammarParser::Function_callContext::getRuleIndex() const {
  return GrammarParser::RuleFunction_call;
}

void GrammarParser::Function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_call(this);
}

void GrammarParser::Function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_call(this);
}

GrammarParser::Function_callContext* GrammarParser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 46, GrammarParser::RuleFunction_call);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(486);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(478);
      alert();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(479);
      add_brackets();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(480);
      change_brackets();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(481);
      return_datetime();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(482);
      indicator_buffers_func();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(483);
      set_index_buffer();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(484);
      set_level_style();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(485);
      any_function_call();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_function_callContext ------------------------------------------------------------------

GrammarParser::Any_function_callContext::Any_function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::NameContext* GrammarParser::Any_function_callContext::name() {
  return getRuleContext<GrammarParser::NameContext>(0);
}

GrammarParser::Any_fcall_parantheses_exprContext* GrammarParser::Any_function_callContext::any_fcall_parantheses_expr() {
  return getRuleContext<GrammarParser::Any_fcall_parantheses_exprContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Any_function_callContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Any_function_callContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Any_function_callContext::getRuleIndex() const {
  return GrammarParser::RuleAny_function_call;
}

void GrammarParser::Any_function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_function_call(this);
}

void GrammarParser::Any_function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_function_call(this);
}

GrammarParser::Any_function_callContext* GrammarParser::any_function_call() {
  Any_function_callContext *_localctx = _tracker.createInstance<Any_function_callContext>(_ctx, getState());
  enterRule(_localctx, 48, GrammarParser::RuleAny_function_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(488);
    name();
    setState(492);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(489);
      space();
      setState(494);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(495);
    any_fcall_parantheses_expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_fcall_parantheses_exprContext ------------------------------------------------------------------

GrammarParser::Any_fcall_parantheses_exprContext::Any_fcall_parantheses_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Any_fcall_parantheses_exprContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Any_fcall_parantheses_exprContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

GrammarParser::Any_fcall_parantheses_contentContext* GrammarParser::Any_fcall_parantheses_exprContext::any_fcall_parantheses_content() {
  return getRuleContext<GrammarParser::Any_fcall_parantheses_contentContext>(0);
}


size_t GrammarParser::Any_fcall_parantheses_exprContext::getRuleIndex() const {
  return GrammarParser::RuleAny_fcall_parantheses_expr;
}

void GrammarParser::Any_fcall_parantheses_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_fcall_parantheses_expr(this);
}

void GrammarParser::Any_fcall_parantheses_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_fcall_parantheses_expr(this);
}

GrammarParser::Any_fcall_parantheses_exprContext* GrammarParser::any_fcall_parantheses_expr() {
  Any_fcall_parantheses_exprContext *_localctx = _tracker.createInstance<Any_fcall_parantheses_exprContext>(_ctx, getState());
  enterRule(_localctx, 50, GrammarParser::RuleAny_fcall_parantheses_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(497);
    match(GrammarParser::OP_PARETHESES);
    setState(499);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
      | (1ULL << GrammarParser::DOT)
      | (1ULL << GrammarParser::OP_BR)
      | (1ULL << GrammarParser::CL_BR)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::CL_CRL_BR)
      | (1ULL << GrammarParser::COLON)
      | (1ULL << GrammarParser::D_QUOTE)
      | (1ULL << GrammarParser::S_QUOTE)
      | (1ULL << GrammarParser::EQ)
      | (1ULL << GrammarParser::COMPARISSON)
      | (1ULL << GrammarParser::COMPARISSON_NOT)
      | (1ULL << GrammarParser::MORE_OR_EQUAL)
      | (1ULL << GrammarParser::LESS_OR_EQUAL)
      | (1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH)
      | (1ULL << GrammarParser::AMPERSAND)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::BD_SLASH)
      | (1ULL << GrammarParser::OP_COMMENT)
      | (1ULL << GrammarParser::CL_COMMENT)
      | (1ULL << GrammarParser::MULTILINE_COMMENT)
      | (1ULL << GrammarParser::ONELINE_COMMENT)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::ON_CHART_EVENT)
      | (1ULL << GrammarParser::TRY_BLOCK_DASH)
      | (1ULL << GrammarParser::TRY_BLOCK_START)
      | (1ULL << GrammarParser::TRY_BLOCK_END)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC)
      | (1ULL << GrammarParser::K_STRICT)
      | (1ULL << GrammarParser::K_NULL)
      | (1ULL << GrammarParser::K_CONST)
      | (1ULL << GrammarParser::K_UNSIGNED)
      | (1ULL << GrammarParser::K_ENUM)
      | (1ULL << GrammarParser::K_ELSE)
      | (1ULL << GrammarParser::K_SWITCH)
      | (1ULL << GrammarParser::K_CASE)
      | (1ULL << GrammarParser::K_RETURN)
      | (1ULL << GrammarParser::K_FOR)
      | (1ULL << GrammarParser::K_IF)
      | (1ULL << GrammarParser::T_DOUBLE)
      | (1ULL << GrammarParser::T_FLOAT)
      | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
      | (1ULL << (GrammarParser::T_BOOL - 64))
      | (1ULL << (GrammarParser::T_LONG - 64))
      | (1ULL << (GrammarParser::T_SHORT - 64))
      | (1ULL << (GrammarParser::T_CHAR - 64))
      | (1ULL << (GrammarParser::T_STRING - 64))
      | (1ULL << (GrammarParser::T_COLOR - 64))
      | (1ULL << (GrammarParser::T_ULONG - 64))
      | (1ULL << (GrammarParser::T_DATETIME - 64))
      | (1ULL << (GrammarParser::PROPERTY - 64))
      | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
      | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
      | (1ULL << (GrammarParser::ALERT - 64))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
      | (1ULL << (GrammarParser::PLAY_SOUND - 64))
      | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
      | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
      | (1ULL << (GrammarParser::TIME_CURRENT - 64))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
      | (1ULL << (GrammarParser::IMA_MODE - 64))
      | (1ULL << (GrammarParser::PRICE_TYPE - 64))
      | (1ULL << (GrammarParser::TIMEFRAME - 64))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
      | (1ULL << (GrammarParser::REGULAR_STRING - 64))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
      | (1ULL << (GrammarParser::NAME - 64))
      | (1ULL << (GrammarParser::INTEGER - 64))
      | (1ULL << (GrammarParser::HEX_INTEGER - 64))
      | (1ULL << (GrammarParser::DATE_LITERAL - 64))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
      | (1ULL << (GrammarParser::LETTER - 64))
      | (1ULL << (GrammarParser::DIGIT - 64))
      | (1ULL << (GrammarParser::ANY - 64))
      | (1ULL << (GrammarParser::MANY - 64)))) != 0)) {
      setState(498);
      any_fcall_parantheses_content();
    }
    setState(501);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_fcall_parantheses_contentContext ------------------------------------------------------------------

GrammarParser::Any_fcall_parantheses_contentContext::Any_fcall_parantheses_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::RvalueContext* GrammarParser::Any_fcall_parantheses_contentContext::rvalue() {
  return getRuleContext<GrammarParser::RvalueContext>(0);
}

std::vector<GrammarParser::Any_fcall_append_argumentContext *> GrammarParser::Any_fcall_parantheses_contentContext::any_fcall_append_argument() {
  return getRuleContexts<GrammarParser::Any_fcall_append_argumentContext>();
}

GrammarParser::Any_fcall_append_argumentContext* GrammarParser::Any_fcall_parantheses_contentContext::any_fcall_append_argument(size_t i) {
  return getRuleContext<GrammarParser::Any_fcall_append_argumentContext>(i);
}


size_t GrammarParser::Any_fcall_parantheses_contentContext::getRuleIndex() const {
  return GrammarParser::RuleAny_fcall_parantheses_content;
}

void GrammarParser::Any_fcall_parantheses_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_fcall_parantheses_content(this);
}

void GrammarParser::Any_fcall_parantheses_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_fcall_parantheses_content(this);
}

GrammarParser::Any_fcall_parantheses_contentContext* GrammarParser::any_fcall_parantheses_content() {
  Any_fcall_parantheses_contentContext *_localctx = _tracker.createInstance<Any_fcall_parantheses_contentContext>(_ctx, getState());
  enterRule(_localctx, 52, GrammarParser::RuleAny_fcall_parantheses_content);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(503);
    rvalue();
    setState(507);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::COMMA)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::WS))) != 0)) {
      setState(504);
      any_fcall_append_argument();
      setState(509);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_fcall_append_argumentContext ------------------------------------------------------------------

GrammarParser::Any_fcall_append_argumentContext::Any_fcall_append_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Any_fcall_append_argumentContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

GrammarParser::RvalueContext* GrammarParser::Any_fcall_append_argumentContext::rvalue() {
  return getRuleContext<GrammarParser::RvalueContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Any_fcall_append_argumentContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Any_fcall_append_argumentContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Any_fcall_append_argumentContext::getRuleIndex() const {
  return GrammarParser::RuleAny_fcall_append_argument;
}

void GrammarParser::Any_fcall_append_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_fcall_append_argument(this);
}

void GrammarParser::Any_fcall_append_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_fcall_append_argument(this);
}

GrammarParser::Any_fcall_append_argumentContext* GrammarParser::any_fcall_append_argument() {
  Any_fcall_append_argumentContext *_localctx = _tracker.createInstance<Any_fcall_append_argumentContext>(_ctx, getState());
  enterRule(_localctx, 54, GrammarParser::RuleAny_fcall_append_argument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(513);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(510);
      space();
      setState(515);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(516);
    match(GrammarParser::COMMA);
    setState(520);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(517);
        space(); 
      }
      setState(522);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
    }
    setState(523);
    rvalue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Entry_pointContext ------------------------------------------------------------------

GrammarParser::Entry_pointContext::Entry_pointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Deinit_function_callContext* GrammarParser::Entry_pointContext::deinit_function_call() {
  return getRuleContext<GrammarParser::Deinit_function_callContext>(0);
}

GrammarParser::Init_function_callContext* GrammarParser::Entry_pointContext::init_function_call() {
  return getRuleContext<GrammarParser::Init_function_callContext>(0);
}

GrammarParser::Start_function_callContext* GrammarParser::Entry_pointContext::start_function_call() {
  return getRuleContext<GrammarParser::Start_function_callContext>(0);
}

GrammarParser::On_calculate_handlerContext* GrammarParser::Entry_pointContext::on_calculate_handler() {
  return getRuleContext<GrammarParser::On_calculate_handlerContext>(0);
}

GrammarParser::On_tick_handlerContext* GrammarParser::Entry_pointContext::on_tick_handler() {
  return getRuleContext<GrammarParser::On_tick_handlerContext>(0);
}

GrammarParser::On_init_handlerContext* GrammarParser::Entry_pointContext::on_init_handler() {
  return getRuleContext<GrammarParser::On_init_handlerContext>(0);
}

GrammarParser::On_deinit_handlerContext* GrammarParser::Entry_pointContext::on_deinit_handler() {
  return getRuleContext<GrammarParser::On_deinit_handlerContext>(0);
}

GrammarParser::On_timer_handlerContext* GrammarParser::Entry_pointContext::on_timer_handler() {
  return getRuleContext<GrammarParser::On_timer_handlerContext>(0);
}

GrammarParser::On_chart_event_handlerContext* GrammarParser::Entry_pointContext::on_chart_event_handler() {
  return getRuleContext<GrammarParser::On_chart_event_handlerContext>(0);
}


size_t GrammarParser::Entry_pointContext::getRuleIndex() const {
  return GrammarParser::RuleEntry_point;
}

void GrammarParser::Entry_pointContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntry_point(this);
}

void GrammarParser::Entry_pointContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntry_point(this);
}

GrammarParser::Entry_pointContext* GrammarParser::entry_point() {
  Entry_pointContext *_localctx = _tracker.createInstance<Entry_pointContext>(_ctx, getState());
  enterRule(_localctx, 56, GrammarParser::RuleEntry_point);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(534);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(525);
      deinit_function_call();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(526);
      init_function_call();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(527);
      start_function_call();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(528);
      on_calculate_handler();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(529);
      on_tick_handler();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(530);
      on_init_handler();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(531);
      on_deinit_handler();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(532);
      on_timer_handler();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(533);
      on_chart_event_handler();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Single_nameContext ------------------------------------------------------------------

GrammarParser::Single_nameContext::Single_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Single_nameContext::INDICATORS_ONLY() {
  return getToken(GrammarParser::INDICATORS_ONLY, 0);
}

tree::TerminalNode* GrammarParser::Single_nameContext::STRATEGY_ONLY() {
  return getToken(GrammarParser::STRATEGY_ONLY, 0);
}

tree::TerminalNode* GrammarParser::Single_nameContext::HOOKING_FUNCS() {
  return getToken(GrammarParser::HOOKING_FUNCS, 0);
}

tree::TerminalNode* GrammarParser::Single_nameContext::ON_TIMER() {
  return getToken(GrammarParser::ON_TIMER, 0);
}

GrammarParser::Unsupported_object_typesContext* GrammarParser::Single_nameContext::unsupported_object_types() {
  return getRuleContext<GrammarParser::Unsupported_object_typesContext>(0);
}

GrammarParser::Unsupported_object_propertiesContext* GrammarParser::Single_nameContext::unsupported_object_properties() {
  return getRuleContext<GrammarParser::Unsupported_object_propertiesContext>(0);
}


size_t GrammarParser::Single_nameContext::getRuleIndex() const {
  return GrammarParser::RuleSingle_name;
}

void GrammarParser::Single_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle_name(this);
}

void GrammarParser::Single_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle_name(this);
}

GrammarParser::Single_nameContext* GrammarParser::single_name() {
  Single_nameContext *_localctx = _tracker.createInstance<Single_nameContext>(_ctx, getState());
  enterRule(_localctx, 58, GrammarParser::RuleSingle_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(542);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::INDICATORS_ONLY: {
        enterOuterAlt(_localctx, 1);
        setState(536);
        match(GrammarParser::INDICATORS_ONLY);
        break;
      }

      case GrammarParser::STRATEGY_ONLY: {
        enterOuterAlt(_localctx, 2);
        setState(537);
        match(GrammarParser::STRATEGY_ONLY);
        break;
      }

      case GrammarParser::HOOKING_FUNCS: {
        enterOuterAlt(_localctx, 3);
        setState(538);
        match(GrammarParser::HOOKING_FUNCS);
        break;
      }

      case GrammarParser::ON_TIMER: {
        enterOuterAlt(_localctx, 4);
        setState(539);
        match(GrammarParser::ON_TIMER);
        break;
      }

      case GrammarParser::UNSUPPORTED_OBJECTS: {
        enterOuterAlt(_localctx, 5);
        setState(540);
        unsupported_object_types();
        break;
      }

      case GrammarParser::UNSUPPORTED_PROPERTIES: {
        enterOuterAlt(_localctx, 6);
        setState(541);
        unsupported_object_properties();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Datetime_litteralContext ------------------------------------------------------------------

GrammarParser::Datetime_litteralContext::Datetime_litteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Datetime_litteralContext::DT_LITTERAL_ST() {
  return getToken(GrammarParser::DT_LITTERAL_ST, 0);
}

tree::TerminalNode* GrammarParser::Datetime_litteralContext::S_QUOTE() {
  return getToken(GrammarParser::S_QUOTE, 0);
}

GrammarParser::Time_litteralContext* GrammarParser::Datetime_litteralContext::time_litteral() {
  return getRuleContext<GrammarParser::Time_litteralContext>(0);
}

GrammarParser::Date_litteralContext* GrammarParser::Datetime_litteralContext::date_litteral() {
  return getRuleContext<GrammarParser::Date_litteralContext>(0);
}

GrammarParser::Append_time_litteralContext* GrammarParser::Datetime_litteralContext::append_time_litteral() {
  return getRuleContext<GrammarParser::Append_time_litteralContext>(0);
}


size_t GrammarParser::Datetime_litteralContext::getRuleIndex() const {
  return GrammarParser::RuleDatetime_litteral;
}

void GrammarParser::Datetime_litteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDatetime_litteral(this);
}

void GrammarParser::Datetime_litteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDatetime_litteral(this);
}

GrammarParser::Datetime_litteralContext* GrammarParser::datetime_litteral() {
  Datetime_litteralContext *_localctx = _tracker.createInstance<Datetime_litteralContext>(_ctx, getState());
  enterRule(_localctx, 60, GrammarParser::RuleDatetime_litteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(544);
    match(GrammarParser::DT_LITTERAL_ST);
    setState(550);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::INTEGER: {
        setState(545);
        time_litteral();
        break;
      }

      case GrammarParser::DATE_LITERAL: {
        setState(546);
        date_litteral();
        setState(548);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == GrammarParser::NEWLINE

        || _la == GrammarParser::WS) {
          setState(547);
          append_time_litteral();
        }
        break;
      }

      case GrammarParser::S_QUOTE: {
        break;
      }

    default:
      break;
    }
    setState(552);
    match(GrammarParser::S_QUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Append_time_litteralContext ------------------------------------------------------------------

GrammarParser::Append_time_litteralContext::Append_time_litteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Time_litteralContext* GrammarParser::Append_time_litteralContext::time_litteral() {
  return getRuleContext<GrammarParser::Time_litteralContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Append_time_litteralContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Append_time_litteralContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Append_time_litteralContext::getRuleIndex() const {
  return GrammarParser::RuleAppend_time_litteral;
}

void GrammarParser::Append_time_litteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAppend_time_litteral(this);
}

void GrammarParser::Append_time_litteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAppend_time_litteral(this);
}

GrammarParser::Append_time_litteralContext* GrammarParser::append_time_litteral() {
  Append_time_litteralContext *_localctx = _tracker.createInstance<Append_time_litteralContext>(_ctx, getState());
  enterRule(_localctx, 62, GrammarParser::RuleAppend_time_litteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(555); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(554);
      space();
      setState(557); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS);
    setState(559);
    time_litteral();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Date_litteralContext ------------------------------------------------------------------

GrammarParser::Date_litteralContext::Date_litteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Date_litteralContext::DATE_LITERAL() {
  return getToken(GrammarParser::DATE_LITERAL, 0);
}


size_t GrammarParser::Date_litteralContext::getRuleIndex() const {
  return GrammarParser::RuleDate_litteral;
}

void GrammarParser::Date_litteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDate_litteral(this);
}

void GrammarParser::Date_litteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDate_litteral(this);
}

GrammarParser::Date_litteralContext* GrammarParser::date_litteral() {
  Date_litteralContext *_localctx = _tracker.createInstance<Date_litteralContext>(_ctx, getState());
  enterRule(_localctx, 64, GrammarParser::RuleDate_litteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(561);
    match(GrammarParser::DATE_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Time_litteralContext ------------------------------------------------------------------

GrammarParser::Time_litteralContext::Time_litteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GrammarParser::Time_litteralContext::INTEGER() {
  return getTokens(GrammarParser::INTEGER);
}

tree::TerminalNode* GrammarParser::Time_litteralContext::INTEGER(size_t i) {
  return getToken(GrammarParser::INTEGER, i);
}

std::vector<tree::TerminalNode *> GrammarParser::Time_litteralContext::COLON() {
  return getTokens(GrammarParser::COLON);
}

tree::TerminalNode* GrammarParser::Time_litteralContext::COLON(size_t i) {
  return getToken(GrammarParser::COLON, i);
}


size_t GrammarParser::Time_litteralContext::getRuleIndex() const {
  return GrammarParser::RuleTime_litteral;
}

void GrammarParser::Time_litteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTime_litteral(this);
}

void GrammarParser::Time_litteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTime_litteral(this);
}

GrammarParser::Time_litteralContext* GrammarParser::time_litteral() {
  Time_litteralContext *_localctx = _tracker.createInstance<Time_litteralContext>(_ctx, getState());
  enterRule(_localctx, 66, GrammarParser::RuleTime_litteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(563);
    match(GrammarParser::INTEGER);
    setState(570);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::COLON) {
      setState(564);
      match(GrammarParser::COLON);
      setState(565);
      match(GrammarParser::INTEGER);
      setState(568);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GrammarParser::COLON) {
        setState(566);
        match(GrammarParser::COLON);
        setState(567);
        match(GrammarParser::INTEGER);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Color_litteralContext ------------------------------------------------------------------

GrammarParser::Color_litteralContext::Color_litteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Color_litteralContext::CLR_LITTERAL() {
  return getToken(GrammarParser::CLR_LITTERAL, 0);
}

GrammarParser::Rgb_litteralContext* GrammarParser::Color_litteralContext::rgb_litteral() {
  return getRuleContext<GrammarParser::Rgb_litteralContext>(0);
}

tree::TerminalNode* GrammarParser::Color_litteralContext::S_QUOTE() {
  return getToken(GrammarParser::S_QUOTE, 0);
}


size_t GrammarParser::Color_litteralContext::getRuleIndex() const {
  return GrammarParser::RuleColor_litteral;
}

void GrammarParser::Color_litteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColor_litteral(this);
}

void GrammarParser::Color_litteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColor_litteral(this);
}

GrammarParser::Color_litteralContext* GrammarParser::color_litteral() {
  Color_litteralContext *_localctx = _tracker.createInstance<Color_litteralContext>(_ctx, getState());
  enterRule(_localctx, 68, GrammarParser::RuleColor_litteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(572);
    match(GrammarParser::CLR_LITTERAL);
    setState(573);
    rgb_litteral();
    setState(574);
    match(GrammarParser::S_QUOTE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rgb_litteralContext ------------------------------------------------------------------

GrammarParser::Rgb_litteralContext::Rgb_litteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::Hex_or_regular_integerContext *> GrammarParser::Rgb_litteralContext::hex_or_regular_integer() {
  return getRuleContexts<GrammarParser::Hex_or_regular_integerContext>();
}

GrammarParser::Hex_or_regular_integerContext* GrammarParser::Rgb_litteralContext::hex_or_regular_integer(size_t i) {
  return getRuleContext<GrammarParser::Hex_or_regular_integerContext>(i);
}

std::vector<GrammarParser::Arg_commaContext *> GrammarParser::Rgb_litteralContext::arg_comma() {
  return getRuleContexts<GrammarParser::Arg_commaContext>();
}

GrammarParser::Arg_commaContext* GrammarParser::Rgb_litteralContext::arg_comma(size_t i) {
  return getRuleContext<GrammarParser::Arg_commaContext>(i);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Rgb_litteralContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Rgb_litteralContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Rgb_litteralContext::getRuleIndex() const {
  return GrammarParser::RuleRgb_litteral;
}

void GrammarParser::Rgb_litteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRgb_litteral(this);
}

void GrammarParser::Rgb_litteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRgb_litteral(this);
}

GrammarParser::Rgb_litteralContext* GrammarParser::rgb_litteral() {
  Rgb_litteralContext *_localctx = _tracker.createInstance<Rgb_litteralContext>(_ctx, getState());
  enterRule(_localctx, 70, GrammarParser::RuleRgb_litteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(579);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(576);
      space();
      setState(581);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(582);
    hex_or_regular_integer();
    setState(583);
    arg_comma();
    setState(584);
    hex_or_regular_integer();
    setState(585);
    arg_comma();
    setState(586);
    hex_or_regular_integer();
    setState(590);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(587);
      space();
      setState(592);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Hex_or_regular_integerContext ------------------------------------------------------------------

GrammarParser::Hex_or_regular_integerContext::Hex_or_regular_integerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Hex_or_regular_integerContext::INTEGER() {
  return getToken(GrammarParser::INTEGER, 0);
}

tree::TerminalNode* GrammarParser::Hex_or_regular_integerContext::HEX_INTEGER() {
  return getToken(GrammarParser::HEX_INTEGER, 0);
}


size_t GrammarParser::Hex_or_regular_integerContext::getRuleIndex() const {
  return GrammarParser::RuleHex_or_regular_integer;
}

void GrammarParser::Hex_or_regular_integerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHex_or_regular_integer(this);
}

void GrammarParser::Hex_or_regular_integerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHex_or_regular_integer(this);
}

GrammarParser::Hex_or_regular_integerContext* GrammarParser::hex_or_regular_integer() {
  Hex_or_regular_integerContext *_localctx = _tracker.createInstance<Hex_or_regular_integerContext>(_ctx, getState());
  enterRule(_localctx, 72, GrammarParser::RuleHex_or_regular_integer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(593);
    _la = _input->LA(1);
    if (!(_la == GrammarParser::INTEGER

    || _la == GrammarParser::HEX_INTEGER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_lexContext ------------------------------------------------------------------

GrammarParser::Any_lexContext::Any_lexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Any_lexContext::MANY() {
  return getToken(GrammarParser::MANY, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::ANY() {
  return getToken(GrammarParser::ANY, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::SC() {
  return getToken(GrammarParser::SC, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::COLON() {
  return getToken(GrammarParser::COLON, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::DOT() {
  return getToken(GrammarParser::DOT, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::AMPERSAND() {
  return getToken(GrammarParser::AMPERSAND, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::HASH() {
  return getToken(GrammarParser::HASH, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::EQ() {
  return getToken(GrammarParser::EQ, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::INCREMENT() {
  return getToken(GrammarParser::INCREMENT, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::DECREMENT() {
  return getToken(GrammarParser::DECREMENT, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::PLUS() {
  return getToken(GrammarParser::PLUS, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::MINUS() {
  return getToken(GrammarParser::MINUS, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::ASTRISK() {
  return getToken(GrammarParser::ASTRISK, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::SLASH() {
  return getToken(GrammarParser::SLASH, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::COMPARISSON() {
  return getToken(GrammarParser::COMPARISSON, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::COMPARISSON_NOT() {
  return getToken(GrammarParser::COMPARISSON_NOT, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::MORE_OR_EQUAL() {
  return getToken(GrammarParser::MORE_OR_EQUAL, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::LESS_OR_EQUAL() {
  return getToken(GrammarParser::LESS_OR_EQUAL, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::CHAR_LITTERAL() {
  return getToken(GrammarParser::CHAR_LITTERAL, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::INPUT() {
  return getToken(GrammarParser::INPUT, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::SINPUT() {
  return getToken(GrammarParser::SINPUT, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::EXTERN() {
  return getToken(GrammarParser::EXTERN, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_STATIC() {
  return getToken(GrammarParser::K_STATIC, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_STRICT() {
  return getToken(GrammarParser::K_STRICT, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_CONST() {
  return getToken(GrammarParser::K_CONST, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_NULL() {
  return getToken(GrammarParser::K_NULL, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_UNSIGNED() {
  return getToken(GrammarParser::K_UNSIGNED, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_ENUM() {
  return getToken(GrammarParser::K_ENUM, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_ELSE() {
  return getToken(GrammarParser::K_ELSE, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_RETURN() {
  return getToken(GrammarParser::K_RETURN, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_SWITCH() {
  return getToken(GrammarParser::K_SWITCH, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_CASE() {
  return getToken(GrammarParser::K_CASE, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_IF() {
  return getToken(GrammarParser::K_IF, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::K_FOR() {
  return getToken(GrammarParser::K_FOR, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::T_VOID() {
  return getToken(GrammarParser::T_VOID, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::T_BOOL() {
  return getToken(GrammarParser::T_BOOL, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::T_LONG() {
  return getToken(GrammarParser::T_LONG, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::T_DATETIME() {
  return getToken(GrammarParser::T_DATETIME, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::T_DOUBLE() {
  return getToken(GrammarParser::T_DOUBLE, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::T_CHAR() {
  return getToken(GrammarParser::T_CHAR, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::T_STRING() {
  return getToken(GrammarParser::T_STRING, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::T_INT() {
  return getToken(GrammarParser::T_INT, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::T_COLOR() {
  return getToken(GrammarParser::T_COLOR, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::T_ULONG() {
  return getToken(GrammarParser::T_ULONG, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::DT_LITTERAL_ST() {
  return getToken(GrammarParser::DT_LITTERAL_ST, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::CLR_LITTERAL() {
  return getToken(GrammarParser::CLR_LITTERAL, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::DATE_LITERAL() {
  return getToken(GrammarParser::DATE_LITERAL, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::S_QUOTE() {
  return getToken(GrammarParser::S_QUOTE, 0);
}

GrammarParser::Hex_or_regular_integerContext* GrammarParser::Any_lexContext::hex_or_regular_integer() {
  return getRuleContext<GrammarParser::Hex_or_regular_integerContext>(0);
}

GrammarParser::Float_valueContext* GrammarParser::Any_lexContext::float_value() {
  return getRuleContext<GrammarParser::Float_valueContext>(0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::INDICATOR_LINE_IDENTIFIER_MODE() {
  return getToken(GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::TIMEFRAME() {
  return getToken(GrammarParser::TIMEFRAME, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::IMA_MODE() {
  return getToken(GrammarParser::IMA_MODE, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::PRICE_TYPE() {
  return getToken(GrammarParser::PRICE_TYPE, 0);
}

GrammarParser::NameContext* GrammarParser::Any_lexContext::name() {
  return getRuleContext<GrammarParser::NameContext>(0);
}

GrammarParser::StrContext* GrammarParser::Any_lexContext::str() {
  return getRuleContext<GrammarParser::StrContext>(0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::PROPERTY() {
  return getToken(GrammarParser::PROPERTY, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::INDICATOR_BUFFERS() {
  return getToken(GrammarParser::INDICATOR_BUFFERS, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::INDICATOR_CHART_WINDOW() {
  return getToken(GrammarParser::INDICATOR_CHART_WINDOW, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::INDICATOR_SEPARATE_WINDOW() {
  return getToken(GrammarParser::INDICATOR_SEPARATE_WINDOW, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::ADD_BRACKETS_FUNCTIONS() {
  return getToken(GrammarParser::ADD_BRACKETS_FUNCTIONS, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::CHANGE_BRACKETS_FUNCTIONS() {
  return getToken(GrammarParser::CHANGE_BRACKETS_FUNCTIONS, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::INDICATOR_BUFFERS_FUNC() {
  return getToken(GrammarParser::INDICATOR_BUFFERS_FUNC, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::SET_INDEX_BUFFER() {
  return getToken(GrammarParser::SET_INDEX_BUFFER, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::SET_LEVEL_STYLE() {
  return getToken(GrammarParser::SET_LEVEL_STYLE, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::TIME_CURRENT() {
  return getToken(GrammarParser::TIME_CURRENT, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::ORDER_OPEN_TIME() {
  return getToken(GrammarParser::ORDER_OPEN_TIME, 0);
}

tree::TerminalNode* GrammarParser::Any_lexContext::ORDER_CLOSE_TIME() {
  return getToken(GrammarParser::ORDER_CLOSE_TIME, 0);
}


size_t GrammarParser::Any_lexContext::getRuleIndex() const {
  return GrammarParser::RuleAny_lex;
}

void GrammarParser::Any_lexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_lex(this);
}

void GrammarParser::Any_lexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_lex(this);
}

GrammarParser::Any_lexContext* GrammarParser::any_lex() {
  Any_lexContext *_localctx = _tracker.createInstance<Any_lexContext>(_ctx, getState());
  enterRule(_localctx, 74, GrammarParser::RuleAny_lex);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(666);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::MANY: {
        enterOuterAlt(_localctx, 1);
        setState(595);
        match(GrammarParser::MANY);
        break;
      }

      case GrammarParser::ANY: {
        enterOuterAlt(_localctx, 2);
        setState(596);
        match(GrammarParser::ANY);
        break;
      }

      case GrammarParser::SC: {
        enterOuterAlt(_localctx, 3);
        setState(597);
        match(GrammarParser::SC);
        break;
      }

      case GrammarParser::COLON: {
        enterOuterAlt(_localctx, 4);
        setState(598);
        match(GrammarParser::COLON);
        break;
      }

      case GrammarParser::COMMA: {
        enterOuterAlt(_localctx, 5);
        setState(599);
        match(GrammarParser::COMMA);
        break;
      }

      case GrammarParser::DOT: {
        enterOuterAlt(_localctx, 6);
        setState(600);
        match(GrammarParser::DOT);
        break;
      }

      case GrammarParser::AMPERSAND: {
        enterOuterAlt(_localctx, 7);
        setState(601);
        match(GrammarParser::AMPERSAND);
        break;
      }

      case GrammarParser::HASH: {
        enterOuterAlt(_localctx, 8);
        setState(602);
        match(GrammarParser::HASH);
        break;
      }

      case GrammarParser::EQ: {
        enterOuterAlt(_localctx, 9);
        setState(603);
        match(GrammarParser::EQ);
        break;
      }

      case GrammarParser::INCREMENT: {
        enterOuterAlt(_localctx, 10);
        setState(604);
        match(GrammarParser::INCREMENT);
        break;
      }

      case GrammarParser::DECREMENT: {
        enterOuterAlt(_localctx, 11);
        setState(605);
        match(GrammarParser::DECREMENT);
        break;
      }

      case GrammarParser::PLUS: {
        enterOuterAlt(_localctx, 12);
        setState(606);
        match(GrammarParser::PLUS);
        break;
      }

      case GrammarParser::MINUS: {
        enterOuterAlt(_localctx, 13);
        setState(607);
        match(GrammarParser::MINUS);
        break;
      }

      case GrammarParser::ASTRISK: {
        enterOuterAlt(_localctx, 14);
        setState(608);
        match(GrammarParser::ASTRISK);
        break;
      }

      case GrammarParser::SLASH: {
        enterOuterAlt(_localctx, 15);
        setState(609);
        match(GrammarParser::SLASH);
        break;
      }

      case GrammarParser::OP_PARETHESES: {
        enterOuterAlt(_localctx, 16);
        setState(610);
        match(GrammarParser::OP_PARETHESES);
        break;
      }

      case GrammarParser::CL_PARETHESES: {
        enterOuterAlt(_localctx, 17);
        setState(611);
        match(GrammarParser::CL_PARETHESES);
        break;
      }

      case GrammarParser::COMPARISSON: {
        enterOuterAlt(_localctx, 18);
        setState(612);
        match(GrammarParser::COMPARISSON);
        break;
      }

      case GrammarParser::COMPARISSON_NOT: {
        enterOuterAlt(_localctx, 19);
        setState(613);
        match(GrammarParser::COMPARISSON_NOT);
        break;
      }

      case GrammarParser::MORE_OR_EQUAL: {
        enterOuterAlt(_localctx, 20);
        setState(614);
        match(GrammarParser::MORE_OR_EQUAL);
        break;
      }

      case GrammarParser::LESS_OR_EQUAL: {
        enterOuterAlt(_localctx, 21);
        setState(615);
        match(GrammarParser::LESS_OR_EQUAL);
        break;
      }

      case GrammarParser::CHAR_LITTERAL: {
        enterOuterAlt(_localctx, 22);
        setState(616);
        match(GrammarParser::CHAR_LITTERAL);
        break;
      }

      case GrammarParser::INPUT: {
        enterOuterAlt(_localctx, 23);
        setState(617);
        match(GrammarParser::INPUT);
        break;
      }

      case GrammarParser::SINPUT: {
        enterOuterAlt(_localctx, 24);
        setState(618);
        match(GrammarParser::SINPUT);
        break;
      }

      case GrammarParser::EXTERN: {
        enterOuterAlt(_localctx, 25);
        setState(619);
        match(GrammarParser::EXTERN);
        break;
      }

      case GrammarParser::K_STATIC: {
        enterOuterAlt(_localctx, 26);
        setState(620);
        match(GrammarParser::K_STATIC);
        break;
      }

      case GrammarParser::K_STRICT: {
        enterOuterAlt(_localctx, 27);
        setState(621);
        match(GrammarParser::K_STRICT);
        break;
      }

      case GrammarParser::K_CONST: {
        enterOuterAlt(_localctx, 28);
        setState(622);
        match(GrammarParser::K_CONST);
        break;
      }

      case GrammarParser::K_NULL: {
        enterOuterAlt(_localctx, 29);
        setState(623);
        match(GrammarParser::K_NULL);
        break;
      }

      case GrammarParser::K_UNSIGNED: {
        enterOuterAlt(_localctx, 30);
        setState(624);
        match(GrammarParser::K_UNSIGNED);
        break;
      }

      case GrammarParser::K_ENUM: {
        enterOuterAlt(_localctx, 31);
        setState(625);
        match(GrammarParser::K_ENUM);
        break;
      }

      case GrammarParser::K_ELSE: {
        enterOuterAlt(_localctx, 32);
        setState(626);
        match(GrammarParser::K_ELSE);
        break;
      }

      case GrammarParser::K_RETURN: {
        enterOuterAlt(_localctx, 33);
        setState(627);
        match(GrammarParser::K_RETURN);
        break;
      }

      case GrammarParser::K_SWITCH: {
        enterOuterAlt(_localctx, 34);
        setState(628);
        match(GrammarParser::K_SWITCH);
        break;
      }

      case GrammarParser::K_CASE: {
        enterOuterAlt(_localctx, 35);
        setState(629);
        match(GrammarParser::K_CASE);
        break;
      }

      case GrammarParser::K_IF: {
        enterOuterAlt(_localctx, 36);
        setState(630);
        match(GrammarParser::K_IF);
        break;
      }

      case GrammarParser::K_FOR: {
        enterOuterAlt(_localctx, 37);
        setState(631);
        match(GrammarParser::K_FOR);
        break;
      }

      case GrammarParser::T_VOID: {
        enterOuterAlt(_localctx, 38);
        setState(632);
        match(GrammarParser::T_VOID);
        break;
      }

      case GrammarParser::T_BOOL: {
        enterOuterAlt(_localctx, 39);
        setState(633);
        match(GrammarParser::T_BOOL);
        break;
      }

      case GrammarParser::T_LONG: {
        enterOuterAlt(_localctx, 40);
        setState(634);
        match(GrammarParser::T_LONG);
        break;
      }

      case GrammarParser::T_DATETIME: {
        enterOuterAlt(_localctx, 41);
        setState(635);
        match(GrammarParser::T_DATETIME);
        break;
      }

      case GrammarParser::T_DOUBLE: {
        enterOuterAlt(_localctx, 42);
        setState(636);
        match(GrammarParser::T_DOUBLE);
        break;
      }

      case GrammarParser::T_CHAR: {
        enterOuterAlt(_localctx, 43);
        setState(637);
        match(GrammarParser::T_CHAR);
        break;
      }

      case GrammarParser::T_STRING: {
        enterOuterAlt(_localctx, 44);
        setState(638);
        match(GrammarParser::T_STRING);
        break;
      }

      case GrammarParser::T_INT: {
        enterOuterAlt(_localctx, 45);
        setState(639);
        match(GrammarParser::T_INT);
        break;
      }

      case GrammarParser::T_COLOR: {
        enterOuterAlt(_localctx, 46);
        setState(640);
        match(GrammarParser::T_COLOR);
        break;
      }

      case GrammarParser::T_ULONG: {
        enterOuterAlt(_localctx, 47);
        setState(641);
        match(GrammarParser::T_ULONG);
        break;
      }

      case GrammarParser::DT_LITTERAL_ST: {
        enterOuterAlt(_localctx, 48);
        setState(642);
        match(GrammarParser::DT_LITTERAL_ST);
        break;
      }

      case GrammarParser::CLR_LITTERAL: {
        enterOuterAlt(_localctx, 49);
        setState(643);
        match(GrammarParser::CLR_LITTERAL);
        break;
      }

      case GrammarParser::DATE_LITERAL: {
        enterOuterAlt(_localctx, 50);
        setState(644);
        match(GrammarParser::DATE_LITERAL);
        break;
      }

      case GrammarParser::S_QUOTE: {
        enterOuterAlt(_localctx, 51);
        setState(645);
        match(GrammarParser::S_QUOTE);
        break;
      }

      case GrammarParser::INTEGER:
      case GrammarParser::HEX_INTEGER: {
        enterOuterAlt(_localctx, 52);
        setState(646);
        hex_or_regular_integer();
        break;
      }

      case GrammarParser::FLOATING_LITERAL: {
        enterOuterAlt(_localctx, 53);
        setState(647);
        float_value();
        break;
      }

      case GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE: {
        enterOuterAlt(_localctx, 54);
        setState(648);
        match(GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE);
        break;
      }

      case GrammarParser::TIMEFRAME: {
        enterOuterAlt(_localctx, 55);
        setState(649);
        match(GrammarParser::TIMEFRAME);
        break;
      }

      case GrammarParser::IMA_MODE: {
        enterOuterAlt(_localctx, 56);
        setState(650);
        match(GrammarParser::IMA_MODE);
        break;
      }

      case GrammarParser::PRICE_TYPE: {
        enterOuterAlt(_localctx, 57);
        setState(651);
        match(GrammarParser::PRICE_TYPE);
        break;
      }

      case GrammarParser::DEINIT:
      case GrammarParser::INIT:
      case GrammarParser::START:
      case GrammarParser::ON_CALCULATE:
      case GrammarParser::ON_TICK:
      case GrammarParser::ON_INIT:
      case GrammarParser::ON_DEINIT:
      case GrammarParser::ON_TIMER:
      case GrammarParser::INDEX_BUFFER_TYPE:
      case GrammarParser::ALERT:
      case GrammarParser::GET_LAST_ERROR:
      case GrammarParser::PLAY_SOUND:
      case GrammarParser::INDICATORS_ONLY:
      case GrammarParser::STRATEGY_ONLY:
      case GrammarParser::HOOKING_FUNCS:
      case GrammarParser::NAME: {
        enterOuterAlt(_localctx, 58);
        setState(652);
        name();
        break;
      }

      case GrammarParser::REGULAR_STRING: {
        enterOuterAlt(_localctx, 59);
        setState(653);
        str();
        break;
      }

      case GrammarParser::PROPERTY: {
        enterOuterAlt(_localctx, 60);
        setState(654);
        match(GrammarParser::PROPERTY);
        break;
      }

      case GrammarParser::INDICATOR_BUFFERS: {
        enterOuterAlt(_localctx, 61);
        setState(655);
        match(GrammarParser::INDICATOR_BUFFERS);
        break;
      }

      case GrammarParser::INDICATOR_CHART_WINDOW: {
        enterOuterAlt(_localctx, 62);
        setState(656);
        match(GrammarParser::INDICATOR_CHART_WINDOW);
        break;
      }

      case GrammarParser::INDICATOR_SEPARATE_WINDOW: {
        enterOuterAlt(_localctx, 63);
        setState(657);
        match(GrammarParser::INDICATOR_SEPARATE_WINDOW);
        break;
      }

      case GrammarParser::ADD_BRACKETS_FUNCTIONS: {
        enterOuterAlt(_localctx, 64);
        setState(658);
        match(GrammarParser::ADD_BRACKETS_FUNCTIONS);
        break;
      }

      case GrammarParser::CHANGE_BRACKETS_FUNCTIONS: {
        enterOuterAlt(_localctx, 65);
        setState(659);
        match(GrammarParser::CHANGE_BRACKETS_FUNCTIONS);
        break;
      }

      case GrammarParser::INDICATOR_BUFFERS_FUNC: {
        enterOuterAlt(_localctx, 66);
        setState(660);
        match(GrammarParser::INDICATOR_BUFFERS_FUNC);
        break;
      }

      case GrammarParser::SET_INDEX_BUFFER: {
        enterOuterAlt(_localctx, 67);
        setState(661);
        match(GrammarParser::SET_INDEX_BUFFER);
        break;
      }

      case GrammarParser::SET_LEVEL_STYLE: {
        enterOuterAlt(_localctx, 68);
        setState(662);
        match(GrammarParser::SET_LEVEL_STYLE);
        break;
      }

      case GrammarParser::TIME_CURRENT: {
        enterOuterAlt(_localctx, 69);
        setState(663);
        match(GrammarParser::TIME_CURRENT);
        break;
      }

      case GrammarParser::ORDER_OPEN_TIME: {
        enterOuterAlt(_localctx, 70);
        setState(664);
        match(GrammarParser::ORDER_OPEN_TIME);
        break;
      }

      case GrammarParser::ORDER_CLOSE_TIME: {
        enterOuterAlt(_localctx, 71);
        setState(665);
        match(GrammarParser::ORDER_CLOSE_TIME);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sq_argumentsContext ------------------------------------------------------------------

GrammarParser::Sq_argumentsContext::Sq_argumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Sq_argumentsContext::OP_BR() {
  return getToken(GrammarParser::OP_BR, 0);
}

tree::TerminalNode* GrammarParser::Sq_argumentsContext::CL_BR() {
  return getToken(GrammarParser::CL_BR, 0);
}

GrammarParser::Sq_contentContext* GrammarParser::Sq_argumentsContext::sq_content() {
  return getRuleContext<GrammarParser::Sq_contentContext>(0);
}


size_t GrammarParser::Sq_argumentsContext::getRuleIndex() const {
  return GrammarParser::RuleSq_arguments;
}

void GrammarParser::Sq_argumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSq_arguments(this);
}

void GrammarParser::Sq_argumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSq_arguments(this);
}

GrammarParser::Sq_argumentsContext* GrammarParser::sq_arguments() {
  Sq_argumentsContext *_localctx = _tracker.createInstance<Sq_argumentsContext>(_ctx, getState());
  enterRule(_localctx, 76, GrammarParser::RuleSq_arguments);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(668);
    match(GrammarParser::OP_BR);
    setState(670);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
      | (1ULL << GrammarParser::DOT)
      | (1ULL << GrammarParser::OP_BR)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::CL_PARETHESES)
      | (1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::CL_CRL_BR)
      | (1ULL << GrammarParser::COLON)
      | (1ULL << GrammarParser::SC)
      | (1ULL << GrammarParser::D_QUOTE)
      | (1ULL << GrammarParser::S_QUOTE)
      | (1ULL << GrammarParser::EQ)
      | (1ULL << GrammarParser::COMPARISSON)
      | (1ULL << GrammarParser::COMPARISSON_NOT)
      | (1ULL << GrammarParser::MORE_OR_EQUAL)
      | (1ULL << GrammarParser::LESS_OR_EQUAL)
      | (1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH)
      | (1ULL << GrammarParser::AMPERSAND)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::BD_SLASH)
      | (1ULL << GrammarParser::OP_COMMENT)
      | (1ULL << GrammarParser::CL_COMMENT)
      | (1ULL << GrammarParser::MULTILINE_COMMENT)
      | (1ULL << GrammarParser::ONELINE_COMMENT)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::ON_CHART_EVENT)
      | (1ULL << GrammarParser::TRY_BLOCK_DASH)
      | (1ULL << GrammarParser::TRY_BLOCK_START)
      | (1ULL << GrammarParser::TRY_BLOCK_END)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC)
      | (1ULL << GrammarParser::K_STRICT)
      | (1ULL << GrammarParser::K_NULL)
      | (1ULL << GrammarParser::K_CONST)
      | (1ULL << GrammarParser::K_UNSIGNED)
      | (1ULL << GrammarParser::K_ENUM)
      | (1ULL << GrammarParser::K_ELSE)
      | (1ULL << GrammarParser::K_SWITCH)
      | (1ULL << GrammarParser::K_CASE)
      | (1ULL << GrammarParser::K_RETURN)
      | (1ULL << GrammarParser::K_FOR)
      | (1ULL << GrammarParser::K_IF)
      | (1ULL << GrammarParser::T_DOUBLE)
      | (1ULL << GrammarParser::T_FLOAT)
      | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
      | (1ULL << (GrammarParser::T_BOOL - 64))
      | (1ULL << (GrammarParser::T_LONG - 64))
      | (1ULL << (GrammarParser::T_SHORT - 64))
      | (1ULL << (GrammarParser::T_CHAR - 64))
      | (1ULL << (GrammarParser::T_STRING - 64))
      | (1ULL << (GrammarParser::T_COLOR - 64))
      | (1ULL << (GrammarParser::T_ULONG - 64))
      | (1ULL << (GrammarParser::T_DATETIME - 64))
      | (1ULL << (GrammarParser::PROPERTY - 64))
      | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
      | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
      | (1ULL << (GrammarParser::ALERT - 64))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
      | (1ULL << (GrammarParser::PLAY_SOUND - 64))
      | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
      | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
      | (1ULL << (GrammarParser::TIME_CURRENT - 64))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
      | (1ULL << (GrammarParser::IMA_MODE - 64))
      | (1ULL << (GrammarParser::PRICE_TYPE - 64))
      | (1ULL << (GrammarParser::TIMEFRAME - 64))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
      | (1ULL << (GrammarParser::REGULAR_STRING - 64))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
      | (1ULL << (GrammarParser::NAME - 64))
      | (1ULL << (GrammarParser::INTEGER - 64))
      | (1ULL << (GrammarParser::HEX_INTEGER - 64))
      | (1ULL << (GrammarParser::DATE_LITERAL - 64))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
      | (1ULL << (GrammarParser::LETTER - 64))
      | (1ULL << (GrammarParser::DIGIT - 64))
      | (1ULL << (GrammarParser::ANY - 64))
      | (1ULL << (GrammarParser::MANY - 64)))) != 0)) {
      setState(669);
      sq_content();
    }
    setState(672);
    match(GrammarParser::CL_BR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sq_contentContext ------------------------------------------------------------------

GrammarParser::Sq_contentContext::Sq_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Sq_brackets_argumentContext* GrammarParser::Sq_contentContext::sq_brackets_argument() {
  return getRuleContext<GrammarParser::Sq_brackets_argumentContext>(0);
}

std::vector<GrammarParser::Append_sq_contentContext *> GrammarParser::Sq_contentContext::append_sq_content() {
  return getRuleContexts<GrammarParser::Append_sq_contentContext>();
}

GrammarParser::Append_sq_contentContext* GrammarParser::Sq_contentContext::append_sq_content(size_t i) {
  return getRuleContext<GrammarParser::Append_sq_contentContext>(i);
}


size_t GrammarParser::Sq_contentContext::getRuleIndex() const {
  return GrammarParser::RuleSq_content;
}

void GrammarParser::Sq_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSq_content(this);
}

void GrammarParser::Sq_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSq_content(this);
}

GrammarParser::Sq_contentContext* GrammarParser::sq_content() {
  Sq_contentContext *_localctx = _tracker.createInstance<Sq_contentContext>(_ctx, getState());
  enterRule(_localctx, 78, GrammarParser::RuleSq_content);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(674);
    sq_brackets_argument();
    setState(678);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::COMMA) {
      setState(675);
      append_sq_content();
      setState(680);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Append_sq_contentContext ------------------------------------------------------------------

GrammarParser::Append_sq_contentContext::Append_sq_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Append_sq_contentContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

GrammarParser::Sq_brackets_argumentContext* GrammarParser::Append_sq_contentContext::sq_brackets_argument() {
  return getRuleContext<GrammarParser::Sq_brackets_argumentContext>(0);
}


size_t GrammarParser::Append_sq_contentContext::getRuleIndex() const {
  return GrammarParser::RuleAppend_sq_content;
}

void GrammarParser::Append_sq_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAppend_sq_content(this);
}

void GrammarParser::Append_sq_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAppend_sq_content(this);
}

GrammarParser::Append_sq_contentContext* GrammarParser::append_sq_content() {
  Append_sq_contentContext *_localctx = _tracker.createInstance<Append_sq_contentContext>(_ctx, getState());
  enterRule(_localctx, 80, GrammarParser::RuleAppend_sq_content);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(681);
    match(GrammarParser::COMMA);
    setState(682);
    sq_brackets_argument();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sq_brackets_argumentContext ------------------------------------------------------------------

GrammarParser::Sq_brackets_argumentContext::Sq_brackets_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::Sq_brackets_anyruleContext *> GrammarParser::Sq_brackets_argumentContext::sq_brackets_anyrule() {
  return getRuleContexts<GrammarParser::Sq_brackets_anyruleContext>();
}

GrammarParser::Sq_brackets_anyruleContext* GrammarParser::Sq_brackets_argumentContext::sq_brackets_anyrule(size_t i) {
  return getRuleContext<GrammarParser::Sq_brackets_anyruleContext>(i);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Sq_brackets_argumentContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Sq_brackets_argumentContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

std::vector<GrammarParser::Fcall_paramsContext *> GrammarParser::Sq_brackets_argumentContext::fcall_params() {
  return getRuleContexts<GrammarParser::Fcall_paramsContext>();
}

GrammarParser::Fcall_paramsContext* GrammarParser::Sq_brackets_argumentContext::fcall_params(size_t i) {
  return getRuleContext<GrammarParser::Fcall_paramsContext>(i);
}


size_t GrammarParser::Sq_brackets_argumentContext::getRuleIndex() const {
  return GrammarParser::RuleSq_brackets_argument;
}

void GrammarParser::Sq_brackets_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSq_brackets_argument(this);
}

void GrammarParser::Sq_brackets_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSq_brackets_argument(this);
}

GrammarParser::Sq_brackets_argumentContext* GrammarParser::sq_brackets_argument() {
  Sq_brackets_argumentContext *_localctx = _tracker.createInstance<Sq_brackets_argumentContext>(_ctx, getState());
  enterRule(_localctx, 82, GrammarParser::RuleSq_brackets_argument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(707);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(684);
      sq_brackets_anyrule();
      setState(688);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(685);
        space();
        setState(690);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(698); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(691);
        fcall_params();
        setState(695);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(692);
            sq_brackets_anyrule(); 
          }
          setState(697);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx);
        }
        setState(700); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == GrammarParser::OP_PARETHESES);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(703); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(702);
        sq_brackets_anyrule();
        setState(705); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
        | (1ULL << GrammarParser::DOT)
        | (1ULL << GrammarParser::OP_BR)
        | (1ULL << GrammarParser::OP_PARETHESES)
        | (1ULL << GrammarParser::CL_PARETHESES)
        | (1ULL << GrammarParser::OP_CRL_BR)
        | (1ULL << GrammarParser::CL_CRL_BR)
        | (1ULL << GrammarParser::COLON)
        | (1ULL << GrammarParser::SC)
        | (1ULL << GrammarParser::D_QUOTE)
        | (1ULL << GrammarParser::S_QUOTE)
        | (1ULL << GrammarParser::EQ)
        | (1ULL << GrammarParser::COMPARISSON)
        | (1ULL << GrammarParser::COMPARISSON_NOT)
        | (1ULL << GrammarParser::MORE_OR_EQUAL)
        | (1ULL << GrammarParser::LESS_OR_EQUAL)
        | (1ULL << GrammarParser::INCREMENT)
        | (1ULL << GrammarParser::DECREMENT)
        | (1ULL << GrammarParser::PLUS)
        | (1ULL << GrammarParser::MINUS)
        | (1ULL << GrammarParser::ASTRISK)
        | (1ULL << GrammarParser::SLASH)
        | (1ULL << GrammarParser::AMPERSAND)
        | (1ULL << GrammarParser::NEWLINE)
        | (1ULL << GrammarParser::BD_SLASH)
        | (1ULL << GrammarParser::OP_COMMENT)
        | (1ULL << GrammarParser::CL_COMMENT)
        | (1ULL << GrammarParser::MULTILINE_COMMENT)
        | (1ULL << GrammarParser::ONELINE_COMMENT)
        | (1ULL << GrammarParser::WS)
        | (1ULL << GrammarParser::DEINIT)
        | (1ULL << GrammarParser::INIT)
        | (1ULL << GrammarParser::START)
        | (1ULL << GrammarParser::ON_CALCULATE)
        | (1ULL << GrammarParser::ON_TICK)
        | (1ULL << GrammarParser::ON_INIT)
        | (1ULL << GrammarParser::ON_DEINIT)
        | (1ULL << GrammarParser::ON_TIMER)
        | (1ULL << GrammarParser::ON_CHART_EVENT)
        | (1ULL << GrammarParser::TRY_BLOCK_DASH)
        | (1ULL << GrammarParser::TRY_BLOCK_START)
        | (1ULL << GrammarParser::TRY_BLOCK_END)
        | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
        | (1ULL << GrammarParser::EXTERN)
        | (1ULL << GrammarParser::INPUT)
        | (1ULL << GrammarParser::SINPUT)
        | (1ULL << GrammarParser::K_STATIC)
        | (1ULL << GrammarParser::K_STRICT)
        | (1ULL << GrammarParser::K_NULL)
        | (1ULL << GrammarParser::K_CONST)
        | (1ULL << GrammarParser::K_UNSIGNED)
        | (1ULL << GrammarParser::K_ENUM)
        | (1ULL << GrammarParser::K_ELSE)
        | (1ULL << GrammarParser::K_SWITCH)
        | (1ULL << GrammarParser::K_CASE)
        | (1ULL << GrammarParser::K_RETURN)
        | (1ULL << GrammarParser::K_FOR)
        | (1ULL << GrammarParser::K_IF)
        | (1ULL << GrammarParser::T_DOUBLE)
        | (1ULL << GrammarParser::T_FLOAT)
        | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
        | (1ULL << (GrammarParser::T_BOOL - 64))
        | (1ULL << (GrammarParser::T_LONG - 64))
        | (1ULL << (GrammarParser::T_SHORT - 64))
        | (1ULL << (GrammarParser::T_CHAR - 64))
        | (1ULL << (GrammarParser::T_STRING - 64))
        | (1ULL << (GrammarParser::T_COLOR - 64))
        | (1ULL << (GrammarParser::T_ULONG - 64))
        | (1ULL << (GrammarParser::T_DATETIME - 64))
        | (1ULL << (GrammarParser::PROPERTY - 64))
        | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
        | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
        | (1ULL << (GrammarParser::ALERT - 64))
        | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
        | (1ULL << (GrammarParser::PLAY_SOUND - 64))
        | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
        | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
        | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
        | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
        | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
        | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
        | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
        | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
        | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
        | (1ULL << (GrammarParser::TIME_CURRENT - 64))
        | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
        | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
        | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
        | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
        | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
        | (1ULL << (GrammarParser::IMA_MODE - 64))
        | (1ULL << (GrammarParser::PRICE_TYPE - 64))
        | (1ULL << (GrammarParser::TIMEFRAME - 64))
        | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
        | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
        | (1ULL << (GrammarParser::REGULAR_STRING - 64))
        | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
        | (1ULL << (GrammarParser::NAME - 64))
        | (1ULL << (GrammarParser::INTEGER - 64))
        | (1ULL << (GrammarParser::HEX_INTEGER - 64))
        | (1ULL << (GrammarParser::DATE_LITERAL - 64))
        | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
        | (1ULL << (GrammarParser::LETTER - 64))
        | (1ULL << (GrammarParser::DIGIT - 64))
        | (1ULL << (GrammarParser::ANY - 64))
        | (1ULL << (GrammarParser::MANY - 64)))) != 0));
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Sq_brackets_anyruleContext ------------------------------------------------------------------

GrammarParser::Sq_brackets_anyruleContext::Sq_brackets_anyruleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Argument_contentContext* GrammarParser::Sq_brackets_anyruleContext::argument_content() {
  return getRuleContext<GrammarParser::Argument_contentContext>(0);
}

GrammarParser::Parantheses_any_expressionContext* GrammarParser::Sq_brackets_anyruleContext::parantheses_any_expression() {
  return getRuleContext<GrammarParser::Parantheses_any_expressionContext>(0);
}

GrammarParser::No_comma_sq_brContext* GrammarParser::Sq_brackets_anyruleContext::no_comma_sq_br() {
  return getRuleContext<GrammarParser::No_comma_sq_brContext>(0);
}


size_t GrammarParser::Sq_brackets_anyruleContext::getRuleIndex() const {
  return GrammarParser::RuleSq_brackets_anyrule;
}

void GrammarParser::Sq_brackets_anyruleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSq_brackets_anyrule(this);
}

void GrammarParser::Sq_brackets_anyruleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSq_brackets_anyrule(this);
}

GrammarParser::Sq_brackets_anyruleContext* GrammarParser::sq_brackets_anyrule() {
  Sq_brackets_anyruleContext *_localctx = _tracker.createInstance<Sq_brackets_anyruleContext>(_ctx, getState());
  enterRule(_localctx, 84, GrammarParser::RuleSq_brackets_anyrule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(712);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(709);
      argument_content();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(710);
      parantheses_any_expression();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(711);
      no_comma_sq_br();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectiveContext ------------------------------------------------------------------

GrammarParser::DirectiveContext::DirectiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::DirectiveContext::HASH() {
  return getToken(GrammarParser::HASH, 0);
}

GrammarParser::NameContext* GrammarParser::DirectiveContext::name() {
  return getRuleContext<GrammarParser::NameContext>(0);
}

std::vector<tree::TerminalNode *> GrammarParser::DirectiveContext::WS() {
  return getTokens(GrammarParser::WS);
}

tree::TerminalNode* GrammarParser::DirectiveContext::WS(size_t i) {
  return getToken(GrammarParser::WS, i);
}

GrammarParser::Ol_contentContext* GrammarParser::DirectiveContext::ol_content() {
  return getRuleContext<GrammarParser::Ol_contentContext>(0);
}


size_t GrammarParser::DirectiveContext::getRuleIndex() const {
  return GrammarParser::RuleDirective;
}

void GrammarParser::DirectiveContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDirective(this);
}

void GrammarParser::DirectiveContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDirective(this);
}

GrammarParser::DirectiveContext* GrammarParser::directive() {
  DirectiveContext *_localctx = _tracker.createInstance<DirectiveContext>(_ctx, getState());
  enterRule(_localctx, 86, GrammarParser::RuleDirective);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(714);
    match(GrammarParser::HASH);
    setState(718);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::WS) {
      setState(715);
      match(GrammarParser::WS);
      setState(720);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(721);
    name();
    setState(723);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      setState(722);
      ol_content();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PropertyContext ------------------------------------------------------------------

GrammarParser::PropertyContext::PropertyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::PropertyContext::HASH() {
  return getToken(GrammarParser::HASH, 0);
}

tree::TerminalNode* GrammarParser::PropertyContext::PROPERTY() {
  return getToken(GrammarParser::PROPERTY, 0);
}

GrammarParser::Property_contentContext* GrammarParser::PropertyContext::property_content() {
  return getRuleContext<GrammarParser::Property_contentContext>(0);
}

std::vector<tree::TerminalNode *> GrammarParser::PropertyContext::WS() {
  return getTokens(GrammarParser::WS);
}

tree::TerminalNode* GrammarParser::PropertyContext::WS(size_t i) {
  return getToken(GrammarParser::WS, i);
}


size_t GrammarParser::PropertyContext::getRuleIndex() const {
  return GrammarParser::RuleProperty;
}

void GrammarParser::PropertyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty(this);
}

void GrammarParser::PropertyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty(this);
}

GrammarParser::PropertyContext* GrammarParser::property() {
  PropertyContext *_localctx = _tracker.createInstance<PropertyContext>(_ctx, getState());
  enterRule(_localctx, 88, GrammarParser::RuleProperty);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(725);
    match(GrammarParser::HASH);
    setState(729);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::WS) {
      setState(726);
      match(GrammarParser::WS);
      setState(731);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(732);
    match(GrammarParser::PROPERTY);
    setState(733);
    property_content();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StrContext ------------------------------------------------------------------

GrammarParser::StrContext::StrContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::StrContext::REGULAR_STRING() {
  return getToken(GrammarParser::REGULAR_STRING, 0);
}


size_t GrammarParser::StrContext::getRuleIndex() const {
  return GrammarParser::RuleStr;
}

void GrammarParser::StrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStr(this);
}

void GrammarParser::StrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStr(this);
}

GrammarParser::StrContext* GrammarParser::str() {
  StrContext *_localctx = _tracker.createInstance<StrContext>(_ctx, getState());
  enterRule(_localctx, 90, GrammarParser::RuleStr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(735);
    match(GrammarParser::REGULAR_STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Property_contentContext ------------------------------------------------------------------

GrammarParser::Property_contentContext::Property_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Property_contentContext::INDICATOR_BUFFERS() {
  return getToken(GrammarParser::INDICATOR_BUFFERS, 0);
}

tree::TerminalNode* GrammarParser::Property_contentContext::INTEGER() {
  return getToken(GrammarParser::INTEGER, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::Property_contentContext::WS() {
  return getTokens(GrammarParser::WS);
}

tree::TerminalNode* GrammarParser::Property_contentContext::WS(size_t i) {
  return getToken(GrammarParser::WS, i);
}

tree::TerminalNode* GrammarParser::Property_contentContext::INDICATOR_CHART_WINDOW() {
  return getToken(GrammarParser::INDICATOR_CHART_WINDOW, 0);
}

tree::TerminalNode* GrammarParser::Property_contentContext::INDICATOR_SEPARATE_WINDOW() {
  return getToken(GrammarParser::INDICATOR_SEPARATE_WINDOW, 0);
}

tree::TerminalNode* GrammarParser::Property_contentContext::K_STRICT() {
  return getToken(GrammarParser::K_STRICT, 0);
}

GrammarParser::Property_style_definitionContext* GrammarParser::Property_contentContext::property_style_definition() {
  return getRuleContext<GrammarParser::Property_style_definitionContext>(0);
}

GrammarParser::Ol_contentContext* GrammarParser::Property_contentContext::ol_content() {
  return getRuleContext<GrammarParser::Ol_contentContext>(0);
}


size_t GrammarParser::Property_contentContext::getRuleIndex() const {
  return GrammarParser::RuleProperty_content;
}

void GrammarParser::Property_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty_content(this);
}

void GrammarParser::Property_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty_content(this);
}

GrammarParser::Property_contentContext* GrammarParser::property_content() {
  Property_contentContext *_localctx = _tracker.createInstance<Property_contentContext>(_ctx, getState());
  enterRule(_localctx, 92, GrammarParser::RuleProperty_content);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(789);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(738); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(737);
        match(GrammarParser::WS);
        setState(740); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == GrammarParser::WS);
      setState(742);
      match(GrammarParser::INDICATOR_BUFFERS);
      setState(744); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(743);
        match(GrammarParser::WS);
        setState(746); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == GrammarParser::WS);
      setState(748);
      match(GrammarParser::INTEGER);
      setState(752);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(749);
          match(GrammarParser::WS); 
        }
        setState(754);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(756); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(755);
        match(GrammarParser::WS);
        setState(758); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == GrammarParser::WS);
      setState(760);
      match(GrammarParser::INDICATOR_CHART_WINDOW);
      setState(764);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(761);
          match(GrammarParser::WS); 
        }
        setState(766);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(768); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(767);
        match(GrammarParser::WS);
        setState(770); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == GrammarParser::WS);
      setState(772);
      match(GrammarParser::INDICATOR_SEPARATE_WINDOW);
      setState(776);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(773);
          match(GrammarParser::WS); 
        }
        setState(778);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(780); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(779);
        match(GrammarParser::WS);
        setState(782); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == GrammarParser::WS);
      setState(784);
      match(GrammarParser::K_STRICT);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(785);
      property_style_definition();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(787);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 69, _ctx)) {
      case 1: {
        setState(786);
        ol_content();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Property_style_definitionContext ------------------------------------------------------------------

GrammarParser::Property_style_definitionContext::Property_style_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::NameContext *> GrammarParser::Property_style_definitionContext::name() {
  return getRuleContexts<GrammarParser::NameContext>();
}

GrammarParser::NameContext* GrammarParser::Property_style_definitionContext::name(size_t i) {
  return getRuleContext<GrammarParser::NameContext>(i);
}

GrammarParser::StrContext* GrammarParser::Property_style_definitionContext::str() {
  return getRuleContext<GrammarParser::StrContext>(0);
}

GrammarParser::Float_valueContext* GrammarParser::Property_style_definitionContext::float_value() {
  return getRuleContext<GrammarParser::Float_valueContext>(0);
}

GrammarParser::Hex_or_regular_integerContext* GrammarParser::Property_style_definitionContext::hex_or_regular_integer() {
  return getRuleContext<GrammarParser::Hex_or_regular_integerContext>(0);
}

std::vector<tree::TerminalNode *> GrammarParser::Property_style_definitionContext::WS() {
  return getTokens(GrammarParser::WS);
}

tree::TerminalNode* GrammarParser::Property_style_definitionContext::WS(size_t i) {
  return getToken(GrammarParser::WS, i);
}


size_t GrammarParser::Property_style_definitionContext::getRuleIndex() const {
  return GrammarParser::RuleProperty_style_definition;
}

void GrammarParser::Property_style_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProperty_style_definition(this);
}

void GrammarParser::Property_style_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProperty_style_definition(this);
}

GrammarParser::Property_style_definitionContext* GrammarParser::property_style_definition() {
  Property_style_definitionContext *_localctx = _tracker.createInstance<Property_style_definitionContext>(_ctx, getState());
  enterRule(_localctx, 94, GrammarParser::RuleProperty_style_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(792); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(791);
      match(GrammarParser::WS);
      setState(794); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::WS);
    setState(796);
    name();
    setState(798); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(797);
      match(GrammarParser::WS);
      setState(800); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::WS);
    setState(806);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::REGULAR_STRING: {
        setState(802);
        str();
        break;
      }

      case GrammarParser::DEINIT:
      case GrammarParser::INIT:
      case GrammarParser::START:
      case GrammarParser::ON_CALCULATE:
      case GrammarParser::ON_TICK:
      case GrammarParser::ON_INIT:
      case GrammarParser::ON_DEINIT:
      case GrammarParser::ON_TIMER:
      case GrammarParser::INDEX_BUFFER_TYPE:
      case GrammarParser::ALERT:
      case GrammarParser::GET_LAST_ERROR:
      case GrammarParser::PLAY_SOUND:
      case GrammarParser::INDICATORS_ONLY:
      case GrammarParser::STRATEGY_ONLY:
      case GrammarParser::HOOKING_FUNCS:
      case GrammarParser::NAME: {
        setState(803);
        name();
        break;
      }

      case GrammarParser::FLOATING_LITERAL: {
        setState(804);
        float_value();
        break;
      }

      case GrammarParser::INTEGER:
      case GrammarParser::HEX_INTEGER: {
        setState(805);
        hex_or_regular_integer();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(811);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(808);
        match(GrammarParser::WS); 
      }
      setState(813);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_extract2headerContext ------------------------------------------------------------------

GrammarParser::Enum_extract2headerContext::Enum_extract2headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Enum_declarationContext* GrammarParser::Enum_extract2headerContext::enum_declaration() {
  return getRuleContext<GrammarParser::Enum_declarationContext>(0);
}


size_t GrammarParser::Enum_extract2headerContext::getRuleIndex() const {
  return GrammarParser::RuleEnum_extract2header;
}

void GrammarParser::Enum_extract2headerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_extract2header(this);
}

void GrammarParser::Enum_extract2headerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_extract2header(this);
}

GrammarParser::Enum_extract2headerContext* GrammarParser::enum_extract2header() {
  Enum_extract2headerContext *_localctx = _tracker.createInstance<Enum_extract2headerContext>(_ctx, getState());
  enterRule(_localctx, 96, GrammarParser::RuleEnum_extract2header);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(814);
    enum_declaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_declarationContext ------------------------------------------------------------------

GrammarParser::Enum_declarationContext::Enum_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Enum_declarationContext::K_ENUM() {
  return getToken(GrammarParser::K_ENUM, 0);
}

tree::TerminalNode* GrammarParser::Enum_declarationContext::NAME() {
  return getToken(GrammarParser::NAME, 0);
}

tree::TerminalNode* GrammarParser::Enum_declarationContext::OP_CRL_BR() {
  return getToken(GrammarParser::OP_CRL_BR, 0);
}

tree::TerminalNode* GrammarParser::Enum_declarationContext::CL_CRL_BR() {
  return getToken(GrammarParser::CL_CRL_BR, 0);
}

tree::TerminalNode* GrammarParser::Enum_declarationContext::SC() {
  return getToken(GrammarParser::SC, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Enum_declarationContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Enum_declarationContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::Enum_item_listContext* GrammarParser::Enum_declarationContext::enum_item_list() {
  return getRuleContext<GrammarParser::Enum_item_listContext>(0);
}


size_t GrammarParser::Enum_declarationContext::getRuleIndex() const {
  return GrammarParser::RuleEnum_declaration;
}

void GrammarParser::Enum_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_declaration(this);
}

void GrammarParser::Enum_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_declaration(this);
}

GrammarParser::Enum_declarationContext* GrammarParser::enum_declaration() {
  Enum_declarationContext *_localctx = _tracker.createInstance<Enum_declarationContext>(_ctx, getState());
  enterRule(_localctx, 98, GrammarParser::RuleEnum_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(816);
    match(GrammarParser::K_ENUM);
    setState(818); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(817);
      space();
      setState(820); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS);
    setState(822);
    match(GrammarParser::NAME);
    setState(826);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(823);
      space();
      setState(828);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(829);
    match(GrammarParser::OP_CRL_BR);
    setState(833);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(830);
        space(); 
      }
      setState(835);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx);
    }
    setState(837);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::NAME) {
      setState(836);
      enum_item_list();
    }
    setState(842);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(839);
      space();
      setState(844);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(845);
    match(GrammarParser::CL_CRL_BR);
    setState(849);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(846);
      space();
      setState(851);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(852);
    match(GrammarParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_item_listContext ------------------------------------------------------------------

GrammarParser::Enum_item_listContext::Enum_item_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::Enum_itemContext *> GrammarParser::Enum_item_listContext::enum_item() {
  return getRuleContexts<GrammarParser::Enum_itemContext>();
}

GrammarParser::Enum_itemContext* GrammarParser::Enum_item_listContext::enum_item(size_t i) {
  return getRuleContext<GrammarParser::Enum_itemContext>(i);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Enum_item_listContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Enum_item_listContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

std::vector<tree::TerminalNode *> GrammarParser::Enum_item_listContext::COMMA() {
  return getTokens(GrammarParser::COMMA);
}

tree::TerminalNode* GrammarParser::Enum_item_listContext::COMMA(size_t i) {
  return getToken(GrammarParser::COMMA, i);
}


size_t GrammarParser::Enum_item_listContext::getRuleIndex() const {
  return GrammarParser::RuleEnum_item_list;
}

void GrammarParser::Enum_item_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_item_list(this);
}

void GrammarParser::Enum_item_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_item_list(this);
}

GrammarParser::Enum_item_listContext* GrammarParser::enum_item_list() {
  Enum_item_listContext *_localctx = _tracker.createInstance<Enum_item_listContext>(_ctx, getState());
  enterRule(_localctx, 100, GrammarParser::RuleEnum_item_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(854);
    enum_item();
    setState(858);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(855);
        space(); 
      }
      setState(860);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
    }
    setState(862);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::COMMA) {
      setState(861);
      match(GrammarParser::COMMA);
    }
    setState(881);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(867);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GrammarParser::NEWLINE

        || _la == GrammarParser::WS) {
          setState(864);
          space();
          setState(869);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(870);
        enum_item();
        setState(874);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GrammarParser::NEWLINE

        || _la == GrammarParser::WS) {
          setState(871);
          space();
          setState(876);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(877);
        match(GrammarParser::COMMA); 
      }
      setState(883);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 85, _ctx);
    }
    setState(887);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(884);
        space(); 
      }
      setState(889);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 86, _ctx);
    }
    setState(891);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::NAME) {
      setState(890);
      enum_item();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Enum_itemContext ------------------------------------------------------------------

GrammarParser::Enum_itemContext::Enum_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Enum_itemContext::NAME() {
  return getToken(GrammarParser::NAME, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Enum_itemContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Enum_itemContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

tree::TerminalNode* GrammarParser::Enum_itemContext::EQ() {
  return getToken(GrammarParser::EQ, 0);
}

tree::TerminalNode* GrammarParser::Enum_itemContext::INTEGER() {
  return getToken(GrammarParser::INTEGER, 0);
}


size_t GrammarParser::Enum_itemContext::getRuleIndex() const {
  return GrammarParser::RuleEnum_item;
}

void GrammarParser::Enum_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum_item(this);
}

void GrammarParser::Enum_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum_item(this);
}

GrammarParser::Enum_itemContext* GrammarParser::enum_item() {
  Enum_itemContext *_localctx = _tracker.createInstance<Enum_itemContext>(_ctx, getState());
  enterRule(_localctx, 102, GrammarParser::RuleEnum_item);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(893);
    match(GrammarParser::NAME);
    setState(897);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(894);
        space(); 
      }
      setState(899);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx);
    }
    setState(908);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::EQ) {
      setState(900);
      match(GrammarParser::EQ);
      setState(904);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(901);
        space();
        setState(906);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(907);
      match(GrammarParser::INTEGER);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_change_valueContext ------------------------------------------------------------------

GrammarParser::Variable_change_valueContext::Variable_change_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Variable_modify_rulesContext* GrammarParser::Variable_change_valueContext::variable_modify_rules() {
  return getRuleContext<GrammarParser::Variable_modify_rulesContext>(0);
}


size_t GrammarParser::Variable_change_valueContext::getRuleIndex() const {
  return GrammarParser::RuleVariable_change_value;
}

void GrammarParser::Variable_change_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_change_value(this);
}

void GrammarParser::Variable_change_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_change_value(this);
}

GrammarParser::Variable_change_valueContext* GrammarParser::variable_change_value() {
  Variable_change_valueContext *_localctx = _tracker.createInstance<Variable_change_valueContext>(_ctx, getState());
  enterRule(_localctx, 104, GrammarParser::RuleVariable_change_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(910);
    variable_modify_rules();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_modify_rulesContext ------------------------------------------------------------------

GrammarParser::Variable_modify_rulesContext::Variable_modify_rulesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GrammarParser::Variable_modify_rulesContext::getRuleIndex() const {
  return GrammarParser::RuleVariable_modify_rules;
}

void GrammarParser::Variable_modify_rulesContext::copyFrom(Variable_modify_rulesContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Variable_change_value_assignmentContext ------------------------------------------------------------------

GrammarParser::Subscript_operatorContext* GrammarParser::Variable_change_value_assignmentContext::subscript_operator() {
  return getRuleContext<GrammarParser::Subscript_operatorContext>(0);
}

GrammarParser::Last_multi_assignment_rvalueContext* GrammarParser::Variable_change_value_assignmentContext::last_multi_assignment_rvalue() {
  return getRuleContext<GrammarParser::Last_multi_assignment_rvalueContext>(0);
}

tree::TerminalNode* GrammarParser::Variable_change_value_assignmentContext::SC() {
  return getToken(GrammarParser::SC, 0);
}

std::vector<GrammarParser::Multi_assignmentContext *> GrammarParser::Variable_change_value_assignmentContext::multi_assignment() {
  return getRuleContexts<GrammarParser::Multi_assignmentContext>();
}

GrammarParser::Multi_assignmentContext* GrammarParser::Variable_change_value_assignmentContext::multi_assignment(size_t i) {
  return getRuleContext<GrammarParser::Multi_assignmentContext>(i);
}

GrammarParser::Variable_change_value_assignmentContext::Variable_change_value_assignmentContext(Variable_modify_rulesContext *ctx) { copyFrom(ctx); }

void GrammarParser::Variable_change_value_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_change_value_assignment(this);
}
void GrammarParser::Variable_change_value_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_change_value_assignment(this);
}
//----------------- Variable_change_value_name_fistContext ------------------------------------------------------------------

GrammarParser::Subscript_operatorContext* GrammarParser::Variable_change_value_name_fistContext::subscript_operator() {
  return getRuleContext<GrammarParser::Subscript_operatorContext>(0);
}

GrammarParser::Unary_operatorContext* GrammarParser::Variable_change_value_name_fistContext::unary_operator() {
  return getRuleContext<GrammarParser::Unary_operatorContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Variable_change_value_name_fistContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Variable_change_value_name_fistContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::Variable_change_value_name_fistContext::Variable_change_value_name_fistContext(Variable_modify_rulesContext *ctx) { copyFrom(ctx); }

void GrammarParser::Variable_change_value_name_fistContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_change_value_name_fist(this);
}
void GrammarParser::Variable_change_value_name_fistContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_change_value_name_fist(this);
}
//----------------- Variable_change_value_name_lastContext ------------------------------------------------------------------

GrammarParser::Unary_operatorContext* GrammarParser::Variable_change_value_name_lastContext::unary_operator() {
  return getRuleContext<GrammarParser::Unary_operatorContext>(0);
}

GrammarParser::Subscript_operatorContext* GrammarParser::Variable_change_value_name_lastContext::subscript_operator() {
  return getRuleContext<GrammarParser::Subscript_operatorContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Variable_change_value_name_lastContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Variable_change_value_name_lastContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::Variable_change_value_name_lastContext::Variable_change_value_name_lastContext(Variable_modify_rulesContext *ctx) { copyFrom(ctx); }

void GrammarParser::Variable_change_value_name_lastContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_change_value_name_last(this);
}
void GrammarParser::Variable_change_value_name_lastContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_change_value_name_last(this);
}
GrammarParser::Variable_modify_rulesContext* GrammarParser::variable_modify_rules() {
  Variable_modify_rulesContext *_localctx = _tracker.createInstance<Variable_modify_rulesContext>(_ctx, getState());
  enterRule(_localctx, 106, GrammarParser::RuleVariable_modify_rules);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(940);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Variable_modify_rulesContext *>(_tracker.createInstance<GrammarParser::Variable_change_value_assignmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(912);
      subscript_operator();
      setState(916);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(913);
          multi_assignment(); 
        }
        setState(918);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 91, _ctx);
      }
      setState(919);
      last_multi_assignment_rvalue();
      setState(920);
      match(GrammarParser::SC);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Variable_modify_rulesContext *>(_tracker.createInstance<GrammarParser::Variable_change_value_name_fistContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(922);
      subscript_operator();
      setState(926);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(923);
        space();
        setState(928);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(929);
      unary_operator();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<Variable_modify_rulesContext *>(_tracker.createInstance<GrammarParser::Variable_change_value_name_lastContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(931);
      unary_operator();
      setState(935);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(932);
        space();
        setState(937);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(938);
      subscript_operator();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Subscript_operatorContext ------------------------------------------------------------------

GrammarParser::Subscript_operatorContext::Subscript_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::NameContext* GrammarParser::Subscript_operatorContext::name() {
  return getRuleContext<GrammarParser::NameContext>(0);
}

GrammarParser::Sq_argumentsContext* GrammarParser::Subscript_operatorContext::sq_arguments() {
  return getRuleContext<GrammarParser::Sq_argumentsContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Subscript_operatorContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Subscript_operatorContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Subscript_operatorContext::getRuleIndex() const {
  return GrammarParser::RuleSubscript_operator;
}

void GrammarParser::Subscript_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscript_operator(this);
}

void GrammarParser::Subscript_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscript_operator(this);
}

GrammarParser::Subscript_operatorContext* GrammarParser::subscript_operator() {
  Subscript_operatorContext *_localctx = _tracker.createInstance<Subscript_operatorContext>(_ctx, getState());
  enterRule(_localctx, 108, GrammarParser::RuleSubscript_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(942);
    name();
    setState(950);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 96, _ctx)) {
    case 1: {
      setState(946);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(943);
        space();
        setState(948);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(949);
      sq_arguments();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Multi_assignmentContext ------------------------------------------------------------------

GrammarParser::Multi_assignmentContext::Multi_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Asssignment_operatorContext* GrammarParser::Multi_assignmentContext::asssignment_operator() {
  return getRuleContext<GrammarParser::Asssignment_operatorContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Multi_assignmentContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Multi_assignmentContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::Subscript_operatorContext* GrammarParser::Multi_assignmentContext::subscript_operator() {
  return getRuleContext<GrammarParser::Subscript_operatorContext>(0);
}

std::vector<GrammarParser::RvalueContext *> GrammarParser::Multi_assignmentContext::rvalue() {
  return getRuleContexts<GrammarParser::RvalueContext>();
}

GrammarParser::RvalueContext* GrammarParser::Multi_assignmentContext::rvalue(size_t i) {
  return getRuleContext<GrammarParser::RvalueContext>(i);
}


size_t GrammarParser::Multi_assignmentContext::getRuleIndex() const {
  return GrammarParser::RuleMulti_assignment;
}

void GrammarParser::Multi_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulti_assignment(this);
}

void GrammarParser::Multi_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulti_assignment(this);
}

GrammarParser::Multi_assignmentContext* GrammarParser::multi_assignment() {
  Multi_assignmentContext *_localctx = _tracker.createInstance<Multi_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 110, GrammarParser::RuleMulti_assignment);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(955);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(952);
      space();
      setState(957);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(958);
    asssignment_operator();
    setState(962);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(959);
        space(); 
      }
      setState(964);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx);
    }
    setState(971);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 100, _ctx)) {
    case 1: {
      setState(965);
      subscript_operator();
      break;
    }

    case 2: {
      setState(967); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(966);
                rvalue();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(969); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 99, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Last_multi_assignment_rvalueContext ------------------------------------------------------------------

GrammarParser::Last_multi_assignment_rvalueContext::Last_multi_assignment_rvalueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Asssignment_operatorContext* GrammarParser::Last_multi_assignment_rvalueContext::asssignment_operator() {
  return getRuleContext<GrammarParser::Asssignment_operatorContext>(0);
}

GrammarParser::Subscript_operatorContext* GrammarParser::Last_multi_assignment_rvalueContext::subscript_operator() {
  return getRuleContext<GrammarParser::Subscript_operatorContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Last_multi_assignment_rvalueContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Last_multi_assignment_rvalueContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

std::vector<GrammarParser::RvalueContext *> GrammarParser::Last_multi_assignment_rvalueContext::rvalue() {
  return getRuleContexts<GrammarParser::RvalueContext>();
}

GrammarParser::RvalueContext* GrammarParser::Last_multi_assignment_rvalueContext::rvalue(size_t i) {
  return getRuleContext<GrammarParser::RvalueContext>(i);
}


size_t GrammarParser::Last_multi_assignment_rvalueContext::getRuleIndex() const {
  return GrammarParser::RuleLast_multi_assignment_rvalue;
}

void GrammarParser::Last_multi_assignment_rvalueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLast_multi_assignment_rvalue(this);
}

void GrammarParser::Last_multi_assignment_rvalueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLast_multi_assignment_rvalue(this);
}

GrammarParser::Last_multi_assignment_rvalueContext* GrammarParser::last_multi_assignment_rvalue() {
  Last_multi_assignment_rvalueContext *_localctx = _tracker.createInstance<Last_multi_assignment_rvalueContext>(_ctx, getState());
  enterRule(_localctx, 112, GrammarParser::RuleLast_multi_assignment_rvalue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(976);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(973);
      space();
      setState(978);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(979);
    asssignment_operator();
    setState(983);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(980);
        space(); 
      }
      setState(985);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
    }
    setState(992);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx)) {
    case 1: {
      setState(986);
      subscript_operator();
      break;
    }

    case 2: {
      setState(988); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(987);
        rvalue();
        setState(990); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
        | (1ULL << GrammarParser::DOT)
        | (1ULL << GrammarParser::OP_BR)
        | (1ULL << GrammarParser::CL_BR)
        | (1ULL << GrammarParser::OP_PARETHESES)
        | (1ULL << GrammarParser::OP_CRL_BR)
        | (1ULL << GrammarParser::CL_CRL_BR)
        | (1ULL << GrammarParser::COLON)
        | (1ULL << GrammarParser::D_QUOTE)
        | (1ULL << GrammarParser::S_QUOTE)
        | (1ULL << GrammarParser::EQ)
        | (1ULL << GrammarParser::COMPARISSON)
        | (1ULL << GrammarParser::COMPARISSON_NOT)
        | (1ULL << GrammarParser::MORE_OR_EQUAL)
        | (1ULL << GrammarParser::LESS_OR_EQUAL)
        | (1ULL << GrammarParser::INCREMENT)
        | (1ULL << GrammarParser::DECREMENT)
        | (1ULL << GrammarParser::PLUS)
        | (1ULL << GrammarParser::MINUS)
        | (1ULL << GrammarParser::ASTRISK)
        | (1ULL << GrammarParser::SLASH)
        | (1ULL << GrammarParser::AMPERSAND)
        | (1ULL << GrammarParser::NEWLINE)
        | (1ULL << GrammarParser::BD_SLASH)
        | (1ULL << GrammarParser::OP_COMMENT)
        | (1ULL << GrammarParser::CL_COMMENT)
        | (1ULL << GrammarParser::MULTILINE_COMMENT)
        | (1ULL << GrammarParser::ONELINE_COMMENT)
        | (1ULL << GrammarParser::WS)
        | (1ULL << GrammarParser::DEINIT)
        | (1ULL << GrammarParser::INIT)
        | (1ULL << GrammarParser::START)
        | (1ULL << GrammarParser::ON_CALCULATE)
        | (1ULL << GrammarParser::ON_TICK)
        | (1ULL << GrammarParser::ON_INIT)
        | (1ULL << GrammarParser::ON_DEINIT)
        | (1ULL << GrammarParser::ON_TIMER)
        | (1ULL << GrammarParser::ON_CHART_EVENT)
        | (1ULL << GrammarParser::TRY_BLOCK_DASH)
        | (1ULL << GrammarParser::TRY_BLOCK_START)
        | (1ULL << GrammarParser::TRY_BLOCK_END)
        | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
        | (1ULL << GrammarParser::EXTERN)
        | (1ULL << GrammarParser::INPUT)
        | (1ULL << GrammarParser::SINPUT)
        | (1ULL << GrammarParser::K_STATIC)
        | (1ULL << GrammarParser::K_STRICT)
        | (1ULL << GrammarParser::K_NULL)
        | (1ULL << GrammarParser::K_CONST)
        | (1ULL << GrammarParser::K_UNSIGNED)
        | (1ULL << GrammarParser::K_ENUM)
        | (1ULL << GrammarParser::K_ELSE)
        | (1ULL << GrammarParser::K_SWITCH)
        | (1ULL << GrammarParser::K_CASE)
        | (1ULL << GrammarParser::K_RETURN)
        | (1ULL << GrammarParser::K_FOR)
        | (1ULL << GrammarParser::K_IF)
        | (1ULL << GrammarParser::T_DOUBLE)
        | (1ULL << GrammarParser::T_FLOAT)
        | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
        | (1ULL << (GrammarParser::T_BOOL - 64))
        | (1ULL << (GrammarParser::T_LONG - 64))
        | (1ULL << (GrammarParser::T_SHORT - 64))
        | (1ULL << (GrammarParser::T_CHAR - 64))
        | (1ULL << (GrammarParser::T_STRING - 64))
        | (1ULL << (GrammarParser::T_COLOR - 64))
        | (1ULL << (GrammarParser::T_ULONG - 64))
        | (1ULL << (GrammarParser::T_DATETIME - 64))
        | (1ULL << (GrammarParser::PROPERTY - 64))
        | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
        | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
        | (1ULL << (GrammarParser::ALERT - 64))
        | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
        | (1ULL << (GrammarParser::PLAY_SOUND - 64))
        | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
        | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
        | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
        | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
        | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
        | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
        | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
        | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
        | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
        | (1ULL << (GrammarParser::TIME_CURRENT - 64))
        | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
        | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
        | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
        | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
        | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
        | (1ULL << (GrammarParser::IMA_MODE - 64))
        | (1ULL << (GrammarParser::PRICE_TYPE - 64))
        | (1ULL << (GrammarParser::TIMEFRAME - 64))
        | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
        | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
        | (1ULL << (GrammarParser::REGULAR_STRING - 64))
        | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
        | (1ULL << (GrammarParser::NAME - 64))
        | (1ULL << (GrammarParser::INTEGER - 64))
        | (1ULL << (GrammarParser::HEX_INTEGER - 64))
        | (1ULL << (GrammarParser::DATE_LITERAL - 64))
        | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
        | (1ULL << (GrammarParser::LETTER - 64))
        | (1ULL << (GrammarParser::DIGIT - 64))
        | (1ULL << (GrammarParser::ANY - 64))
        | (1ULL << (GrammarParser::MANY - 64)))) != 0));
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

GrammarParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Single_expr_spaceContext* GrammarParser::ExpressionContext::single_expr_space() {
  return getRuleContext<GrammarParser::Single_expr_spaceContext>(0);
}

GrammarParser::Unary_operatorContext* GrammarParser::ExpressionContext::unary_operator() {
  return getRuleContext<GrammarParser::Unary_operatorContext>(0);
}

GrammarParser::ExpressionContext* GrammarParser::ExpressionContext::expression() {
  return getRuleContext<GrammarParser::ExpressionContext>(0);
}

tree::TerminalNode* GrammarParser::ExpressionContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::ExpressionContext::OP_BR() {
  return getToken(GrammarParser::OP_BR, 0);
}

tree::TerminalNode* GrammarParser::ExpressionContext::CL_BR() {
  return getToken(GrammarParser::CL_BR, 0);
}

GrammarParser::Op_exprContext* GrammarParser::ExpressionContext::op_expr() {
  return getRuleContext<GrammarParser::Op_exprContext>(0);
}

tree::TerminalNode* GrammarParser::ExpressionContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}


size_t GrammarParser::ExpressionContext::getRuleIndex() const {
  return GrammarParser::RuleExpression;
}

void GrammarParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void GrammarParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


GrammarParser::ExpressionContext* GrammarParser::expression() {
   return expression(0);
}

GrammarParser::ExpressionContext* GrammarParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GrammarParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  GrammarParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 114;
  enterRecursionRule(_localctx, 114, GrammarParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1006);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx)) {
    case 1: {
      setState(995);
      single_expr_space();
      break;
    }

    case 2: {
      setState(997);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GrammarParser::OP_PARETHESES) {
        setState(996);
        match(GrammarParser::OP_PARETHESES);
      }
      setState(999);
      unary_operator();
      setState(1000);
      expression(2);
      break;
    }

    case 3: {
      setState(1002);
      match(GrammarParser::OP_BR);
      setState(1003);
      expression(0);
      setState(1004);
      match(GrammarParser::CL_BR);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(1017);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(1015);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 108, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1008);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(1009);
          op_expr();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(1010);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(1011);
          unary_operator();
          setState(1013);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx)) {
          case 1: {
            setState(1012);
            match(GrammarParser::CL_PARETHESES);
            break;
          }

          }
          break;
        }

        } 
      }
      setState(1019);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Op_exprContext ------------------------------------------------------------------

GrammarParser::Op_exprContext::Op_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Binary_operatorContext* GrammarParser::Op_exprContext::binary_operator() {
  return getRuleContext<GrammarParser::Binary_operatorContext>(0);
}

GrammarParser::Single_expr_spaceContext* GrammarParser::Op_exprContext::single_expr_space() {
  return getRuleContext<GrammarParser::Single_expr_spaceContext>(0);
}


size_t GrammarParser::Op_exprContext::getRuleIndex() const {
  return GrammarParser::RuleOp_expr;
}

void GrammarParser::Op_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOp_expr(this);
}

void GrammarParser::Op_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOp_expr(this);
}

GrammarParser::Op_exprContext* GrammarParser::op_expr() {
  Op_exprContext *_localctx = _tracker.createInstance<Op_exprContext>(_ctx, getState());
  enterRule(_localctx, 116, GrammarParser::RuleOp_expr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1020);
    binary_operator();
    setState(1021);
    single_expr_space();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Binary_operatorContext ------------------------------------------------------------------

GrammarParser::Binary_operatorContext::Binary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Binary_operatorContext::PLUS() {
  return getToken(GrammarParser::PLUS, 0);
}

tree::TerminalNode* GrammarParser::Binary_operatorContext::MINUS() {
  return getToken(GrammarParser::MINUS, 0);
}

tree::TerminalNode* GrammarParser::Binary_operatorContext::ASTRISK() {
  return getToken(GrammarParser::ASTRISK, 0);
}

tree::TerminalNode* GrammarParser::Binary_operatorContext::SLASH() {
  return getToken(GrammarParser::SLASH, 0);
}


size_t GrammarParser::Binary_operatorContext::getRuleIndex() const {
  return GrammarParser::RuleBinary_operator;
}

void GrammarParser::Binary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinary_operator(this);
}

void GrammarParser::Binary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinary_operator(this);
}

GrammarParser::Binary_operatorContext* GrammarParser::binary_operator() {
  Binary_operatorContext *_localctx = _tracker.createInstance<Binary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 118, GrammarParser::RuleBinary_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1023);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_operatorContext ------------------------------------------------------------------

GrammarParser::Unary_operatorContext::Unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Unary_operatorContext::INCREMENT() {
  return getToken(GrammarParser::INCREMENT, 0);
}

tree::TerminalNode* GrammarParser::Unary_operatorContext::DECREMENT() {
  return getToken(GrammarParser::DECREMENT, 0);
}


size_t GrammarParser::Unary_operatorContext::getRuleIndex() const {
  return GrammarParser::RuleUnary_operator;
}

void GrammarParser::Unary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_operator(this);
}

void GrammarParser::Unary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_operator(this);
}

GrammarParser::Unary_operatorContext* GrammarParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 120, GrammarParser::RuleUnary_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1025);
    _la = _input->LA(1);
    if (!(_la == GrammarParser::INCREMENT

    || _la == GrammarParser::DECREMENT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Single_expr_spaceContext ------------------------------------------------------------------

GrammarParser::Single_expr_spaceContext::Single_expr_spaceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Single_exprContext* GrammarParser::Single_expr_spaceContext::single_expr() {
  return getRuleContext<GrammarParser::Single_exprContext>(0);
}

tree::TerminalNode* GrammarParser::Single_expr_spaceContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Single_expr_spaceContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Single_expr_spaceContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

tree::TerminalNode* GrammarParser::Single_expr_spaceContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}


size_t GrammarParser::Single_expr_spaceContext::getRuleIndex() const {
  return GrammarParser::RuleSingle_expr_space;
}

void GrammarParser::Single_expr_spaceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle_expr_space(this);
}

void GrammarParser::Single_expr_spaceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle_expr_space(this);
}

GrammarParser::Single_expr_spaceContext* GrammarParser::single_expr_space() {
  Single_expr_spaceContext *_localctx = _tracker.createInstance<Single_expr_spaceContext>(_ctx, getState());
  enterRule(_localctx, 122, GrammarParser::RuleSingle_expr_space);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1028);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::OP_PARETHESES) {
      setState(1027);
      match(GrammarParser::OP_PARETHESES);
    }
    setState(1033);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1030);
      space();
      setState(1035);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1036);
    single_expr();
    setState(1040);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1037);
        space(); 
      }
      setState(1042);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx);
    }
    setState(1050);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx)) {
    case 1: {
      setState(1043);
      match(GrammarParser::CL_PARETHESES);
      setState(1047);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1044);
          space(); 
        }
        setState(1049);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 113, _ctx);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Single_exprContext ------------------------------------------------------------------

GrammarParser::Single_exprContext::Single_exprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::NameContext* GrammarParser::Single_exprContext::name() {
  return getRuleContext<GrammarParser::NameContext>(0);
}

GrammarParser::Sq_argumentsContext* GrammarParser::Single_exprContext::sq_arguments() {
  return getRuleContext<GrammarParser::Sq_argumentsContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Single_exprContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Single_exprContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::Float_valueContext* GrammarParser::Single_exprContext::float_value() {
  return getRuleContext<GrammarParser::Float_valueContext>(0);
}

GrammarParser::IntegerContext* GrammarParser::Single_exprContext::integer() {
  return getRuleContext<GrammarParser::IntegerContext>(0);
}

GrammarParser::StrContext* GrammarParser::Single_exprContext::str() {
  return getRuleContext<GrammarParser::StrContext>(0);
}


size_t GrammarParser::Single_exprContext::getRuleIndex() const {
  return GrammarParser::RuleSingle_expr;
}

void GrammarParser::Single_exprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingle_expr(this);
}

void GrammarParser::Single_exprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingle_expr(this);
}

GrammarParser::Single_exprContext* GrammarParser::single_expr() {
  Single_exprContext *_localctx = _tracker.createInstance<Single_exprContext>(_ctx, getState());
  enterRule(_localctx, 124, GrammarParser::RuleSingle_expr);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1065);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::DEINIT:
      case GrammarParser::INIT:
      case GrammarParser::START:
      case GrammarParser::ON_CALCULATE:
      case GrammarParser::ON_TICK:
      case GrammarParser::ON_INIT:
      case GrammarParser::ON_DEINIT:
      case GrammarParser::ON_TIMER:
      case GrammarParser::INDEX_BUFFER_TYPE:
      case GrammarParser::ALERT:
      case GrammarParser::GET_LAST_ERROR:
      case GrammarParser::PLAY_SOUND:
      case GrammarParser::INDICATORS_ONLY:
      case GrammarParser::STRATEGY_ONLY:
      case GrammarParser::HOOKING_FUNCS:
      case GrammarParser::NAME: {
        enterOuterAlt(_localctx, 1);
        setState(1052);
        name();
        setState(1060);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx)) {
        case 1: {
          setState(1056);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == GrammarParser::NEWLINE

          || _la == GrammarParser::WS) {
            setState(1053);
            space();
            setState(1058);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(1059);
          sq_arguments();
          break;
        }

        }
        break;
      }

      case GrammarParser::FLOATING_LITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(1062);
        float_value();
        break;
      }

      case GrammarParser::PLUS:
      case GrammarParser::MINUS:
      case GrammarParser::INTEGER: {
        enterOuterAlt(_localctx, 3);
        setState(1063);
        integer();
        break;
      }

      case GrammarParser::REGULAR_STRING: {
        enterOuterAlt(_localctx, 4);
        setState(1064);
        str();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Asssignment_operatorContext ------------------------------------------------------------------

GrammarParser::Asssignment_operatorContext::Asssignment_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Asssignment_operatorContext::EQ() {
  return getToken(GrammarParser::EQ, 0);
}

tree::TerminalNode* GrammarParser::Asssignment_operatorContext::PLUS() {
  return getToken(GrammarParser::PLUS, 0);
}

tree::TerminalNode* GrammarParser::Asssignment_operatorContext::MINUS() {
  return getToken(GrammarParser::MINUS, 0);
}

tree::TerminalNode* GrammarParser::Asssignment_operatorContext::ASTRISK() {
  return getToken(GrammarParser::ASTRISK, 0);
}

tree::TerminalNode* GrammarParser::Asssignment_operatorContext::SLASH() {
  return getToken(GrammarParser::SLASH, 0);
}

tree::TerminalNode* GrammarParser::Asssignment_operatorContext::AMPERSAND() {
  return getToken(GrammarParser::AMPERSAND, 0);
}

tree::TerminalNode* GrammarParser::Asssignment_operatorContext::ANY() {
  return getToken(GrammarParser::ANY, 0);
}


size_t GrammarParser::Asssignment_operatorContext::getRuleIndex() const {
  return GrammarParser::RuleAsssignment_operator;
}

void GrammarParser::Asssignment_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsssignment_operator(this);
}

void GrammarParser::Asssignment_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsssignment_operator(this);
}

GrammarParser::Asssignment_operatorContext* GrammarParser::asssignment_operator() {
  Asssignment_operatorContext *_localctx = _tracker.createInstance<Asssignment_operatorContext>(_ctx, getState());
  enterRule(_localctx, 126, GrammarParser::RuleAsssignment_operator);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1080);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GrammarParser::EQ: {
        enterOuterAlt(_localctx, 1);
        setState(1067);
        match(GrammarParser::EQ);
        break;
      }

      case GrammarParser::PLUS: {
        enterOuterAlt(_localctx, 2);
        setState(1068);
        match(GrammarParser::PLUS);
        setState(1069);
        match(GrammarParser::EQ);
        break;
      }

      case GrammarParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(1070);
        match(GrammarParser::MINUS);
        setState(1071);
        match(GrammarParser::EQ);
        break;
      }

      case GrammarParser::ASTRISK: {
        enterOuterAlt(_localctx, 4);
        setState(1072);
        match(GrammarParser::ASTRISK);
        setState(1073);
        match(GrammarParser::EQ);
        break;
      }

      case GrammarParser::SLASH: {
        enterOuterAlt(_localctx, 5);
        setState(1074);
        match(GrammarParser::SLASH);
        setState(1075);
        match(GrammarParser::EQ);
        break;
      }

      case GrammarParser::AMPERSAND: {
        enterOuterAlt(_localctx, 6);
        setState(1076);
        match(GrammarParser::AMPERSAND);
        setState(1077);
        match(GrammarParser::EQ);
        break;
      }

      case GrammarParser::ANY: {
        enterOuterAlt(_localctx, 7);
        setState(1078);
        match(GrammarParser::ANY);
        setState(1079);
        match(GrammarParser::EQ);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Add_bracketsContext ------------------------------------------------------------------

GrammarParser::Add_bracketsContext::Add_bracketsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Add_bracketsContext::ADD_BRACKETS_FUNCTIONS() {
  return getToken(GrammarParser::ADD_BRACKETS_FUNCTIONS, 0);
}

tree::TerminalNode* GrammarParser::Add_bracketsContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Add_bracketsContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Add_bracketsContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Add_bracketsContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Add_bracketsContext::getRuleIndex() const {
  return GrammarParser::RuleAdd_brackets;
}

void GrammarParser::Add_bracketsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdd_brackets(this);
}

void GrammarParser::Add_bracketsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdd_brackets(this);
}

GrammarParser::Add_bracketsContext* GrammarParser::add_brackets() {
  Add_bracketsContext *_localctx = _tracker.createInstance<Add_bracketsContext>(_ctx, getState());
  enterRule(_localctx, 128, GrammarParser::RuleAdd_brackets);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1082);
    match(GrammarParser::ADD_BRACKETS_FUNCTIONS);
    setState(1097);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 121, _ctx)) {
    case 1: {
      setState(1086);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1083);
        space();
        setState(1088);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1089);
      match(GrammarParser::OP_PARETHESES);
      setState(1093);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1090);
        space();
        setState(1095);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1096);
      match(GrammarParser::CL_PARETHESES);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Change_bracketsContext ------------------------------------------------------------------

GrammarParser::Change_bracketsContext::Change_bracketsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Change_bracketsContext::CHANGE_BRACKETS_FUNCTIONS() {
  return getToken(GrammarParser::CHANGE_BRACKETS_FUNCTIONS, 0);
}

tree::TerminalNode* GrammarParser::Change_bracketsContext::OP_BR() {
  return getToken(GrammarParser::OP_BR, 0);
}

GrammarParser::Sq_contentContext* GrammarParser::Change_bracketsContext::sq_content() {
  return getRuleContext<GrammarParser::Sq_contentContext>(0);
}

tree::TerminalNode* GrammarParser::Change_bracketsContext::CL_BR() {
  return getToken(GrammarParser::CL_BR, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Change_bracketsContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Change_bracketsContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Change_bracketsContext::getRuleIndex() const {
  return GrammarParser::RuleChange_brackets;
}

void GrammarParser::Change_bracketsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChange_brackets(this);
}

void GrammarParser::Change_bracketsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChange_brackets(this);
}

GrammarParser::Change_bracketsContext* GrammarParser::change_brackets() {
  Change_bracketsContext *_localctx = _tracker.createInstance<Change_bracketsContext>(_ctx, getState());
  enterRule(_localctx, 130, GrammarParser::RuleChange_brackets);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1099);
    match(GrammarParser::CHANGE_BRACKETS_FUNCTIONS);
    setState(1103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1100);
      space();
      setState(1105);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1106);
    match(GrammarParser::OP_BR);
    setState(1107);
    sq_content();
    setState(1108);
    match(GrammarParser::CL_BR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unsupported_object_typesContext ------------------------------------------------------------------

GrammarParser::Unsupported_object_typesContext::Unsupported_object_typesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Unsupported_object_typesContext::UNSUPPORTED_OBJECTS() {
  return getToken(GrammarParser::UNSUPPORTED_OBJECTS, 0);
}


size_t GrammarParser::Unsupported_object_typesContext::getRuleIndex() const {
  return GrammarParser::RuleUnsupported_object_types;
}

void GrammarParser::Unsupported_object_typesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnsupported_object_types(this);
}

void GrammarParser::Unsupported_object_typesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnsupported_object_types(this);
}

GrammarParser::Unsupported_object_typesContext* GrammarParser::unsupported_object_types() {
  Unsupported_object_typesContext *_localctx = _tracker.createInstance<Unsupported_object_typesContext>(_ctx, getState());
  enterRule(_localctx, 132, GrammarParser::RuleUnsupported_object_types);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1110);
    match(GrammarParser::UNSUPPORTED_OBJECTS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unsupported_object_propertiesContext ------------------------------------------------------------------

GrammarParser::Unsupported_object_propertiesContext::Unsupported_object_propertiesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Unsupported_object_propertiesContext::UNSUPPORTED_PROPERTIES() {
  return getToken(GrammarParser::UNSUPPORTED_PROPERTIES, 0);
}


size_t GrammarParser::Unsupported_object_propertiesContext::getRuleIndex() const {
  return GrammarParser::RuleUnsupported_object_properties;
}

void GrammarParser::Unsupported_object_propertiesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnsupported_object_properties(this);
}

void GrammarParser::Unsupported_object_propertiesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnsupported_object_properties(this);
}

GrammarParser::Unsupported_object_propertiesContext* GrammarParser::unsupported_object_properties() {
  Unsupported_object_propertiesContext *_localctx = _tracker.createInstance<Unsupported_object_propertiesContext>(_ctx, getState());
  enterRule(_localctx, 134, GrammarParser::RuleUnsupported_object_properties);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1112);
    match(GrammarParser::UNSUPPORTED_PROPERTIES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_datetimeContext ------------------------------------------------------------------

GrammarParser::Return_datetimeContext::Return_datetimeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Return_datetimeContext::TIME_CURRENT() {
  return getToken(GrammarParser::TIME_CURRENT, 0);
}

tree::TerminalNode* GrammarParser::Return_datetimeContext::ORDER_OPEN_TIME() {
  return getToken(GrammarParser::ORDER_OPEN_TIME, 0);
}

tree::TerminalNode* GrammarParser::Return_datetimeContext::ORDER_CLOSE_TIME() {
  return getToken(GrammarParser::ORDER_CLOSE_TIME, 0);
}


size_t GrammarParser::Return_datetimeContext::getRuleIndex() const {
  return GrammarParser::RuleReturn_datetime;
}

void GrammarParser::Return_datetimeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn_datetime(this);
}

void GrammarParser::Return_datetimeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn_datetime(this);
}

GrammarParser::Return_datetimeContext* GrammarParser::return_datetime() {
  Return_datetimeContext *_localctx = _tracker.createInstance<Return_datetimeContext>(_ctx, getState());
  enterRule(_localctx, 136, GrammarParser::RuleReturn_datetime);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1114);
    _la = _input->LA(1);
    if (!(((((_la - 88) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 88)) & ((1ULL << (GrammarParser::TIME_CURRENT - 88))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 88))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 88)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Indicator_buffers_funcContext ------------------------------------------------------------------

GrammarParser::Indicator_buffers_funcContext::Indicator_buffers_funcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Indicator_buffers_funcContext::INDICATOR_BUFFERS_FUNC() {
  return getToken(GrammarParser::INDICATOR_BUFFERS_FUNC, 0);
}

tree::TerminalNode* GrammarParser::Indicator_buffers_funcContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Indicator_buffers_funcContext::INTEGER() {
  return getToken(GrammarParser::INTEGER, 0);
}

tree::TerminalNode* GrammarParser::Indicator_buffers_funcContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Indicator_buffers_funcContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Indicator_buffers_funcContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Indicator_buffers_funcContext::getRuleIndex() const {
  return GrammarParser::RuleIndicator_buffers_func;
}

void GrammarParser::Indicator_buffers_funcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndicator_buffers_func(this);
}

void GrammarParser::Indicator_buffers_funcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndicator_buffers_func(this);
}

GrammarParser::Indicator_buffers_funcContext* GrammarParser::indicator_buffers_func() {
  Indicator_buffers_funcContext *_localctx = _tracker.createInstance<Indicator_buffers_funcContext>(_ctx, getState());
  enterRule(_localctx, 138, GrammarParser::RuleIndicator_buffers_func);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1116);
    match(GrammarParser::INDICATOR_BUFFERS_FUNC);
    setState(1120);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1117);
      space();
      setState(1122);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1123);
    match(GrammarParser::OP_PARETHESES);
    setState(1127);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1124);
      space();
      setState(1129);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1130);
    match(GrammarParser::INTEGER);
    setState(1134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1131);
      space();
      setState(1136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1137);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arg_commaContext ------------------------------------------------------------------

GrammarParser::Arg_commaContext::Arg_commaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Arg_commaContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Arg_commaContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Arg_commaContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Arg_commaContext::getRuleIndex() const {
  return GrammarParser::RuleArg_comma;
}

void GrammarParser::Arg_commaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg_comma(this);
}

void GrammarParser::Arg_commaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg_comma(this);
}

GrammarParser::Arg_commaContext* GrammarParser::arg_comma() {
  Arg_commaContext *_localctx = _tracker.createInstance<Arg_commaContext>(_ctx, getState());
  enterRule(_localctx, 140, GrammarParser::RuleArg_comma);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1142);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1139);
      space();
      setState(1144);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1145);
    match(GrammarParser::COMMA);
    setState(1149);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1146);
      space();
      setState(1151);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Modifier_variable_declarationContext ------------------------------------------------------------------

GrammarParser::Modifier_variable_declarationContext::Modifier_variable_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Variable_declarationContext* GrammarParser::Modifier_variable_declarationContext::variable_declaration() {
  return getRuleContext<GrammarParser::Variable_declarationContext>(0);
}

std::vector<GrammarParser::Append_variable_declarationContext *> GrammarParser::Modifier_variable_declarationContext::append_variable_declaration() {
  return getRuleContexts<GrammarParser::Append_variable_declarationContext>();
}

GrammarParser::Append_variable_declarationContext* GrammarParser::Modifier_variable_declarationContext::append_variable_declaration(size_t i) {
  return getRuleContext<GrammarParser::Append_variable_declarationContext>(i);
}

tree::TerminalNode* GrammarParser::Modifier_variable_declarationContext::SC() {
  return getToken(GrammarParser::SC, 0);
}

tree::TerminalNode* GrammarParser::Modifier_variable_declarationContext::K_STATIC() {
  return getToken(GrammarParser::K_STATIC, 0);
}

tree::TerminalNode* GrammarParser::Modifier_variable_declarationContext::EXTERN() {
  return getToken(GrammarParser::EXTERN, 0);
}

tree::TerminalNode* GrammarParser::Modifier_variable_declarationContext::INPUT() {
  return getToken(GrammarParser::INPUT, 0);
}

tree::TerminalNode* GrammarParser::Modifier_variable_declarationContext::SINPUT() {
  return getToken(GrammarParser::SINPUT, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Modifier_variable_declarationContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Modifier_variable_declarationContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Modifier_variable_declarationContext::getRuleIndex() const {
  return GrammarParser::RuleModifier_variable_declaration;
}

void GrammarParser::Modifier_variable_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModifier_variable_declaration(this);
}

void GrammarParser::Modifier_variable_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModifier_variable_declaration(this);
}

GrammarParser::Modifier_variable_declarationContext* GrammarParser::modifier_variable_declaration() {
  Modifier_variable_declarationContext *_localctx = _tracker.createInstance<Modifier_variable_declarationContext>(_ctx, getState());
  enterRule(_localctx, 142, GrammarParser::RuleModifier_variable_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1158);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC))) != 0)) {
      setState(1152);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GrammarParser::EXTERN)
        | (1ULL << GrammarParser::INPUT)
        | (1ULL << GrammarParser::SINPUT)
        | (1ULL << GrammarParser::K_STATIC))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(1154); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1153);
        space();
        setState(1156); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS);
    }
    setState(1160);
    variable_declaration();
    setState(1164);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1161);
        append_variable_declaration(); 
      }
      setState(1166);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx);
    }
    setState(1174);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx)) {
    case 1: {
      setState(1170);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1167);
        space();
        setState(1172);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1173);
      match(GrammarParser::SC);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declarationContext ------------------------------------------------------------------

GrammarParser::Variable_declarationContext::Variable_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::TypeContext* GrammarParser::Variable_declarationContext::type() {
  return getRuleContext<GrammarParser::TypeContext>(0);
}

GrammarParser::NameContext* GrammarParser::Variable_declarationContext::name() {
  return getRuleContext<GrammarParser::NameContext>(0);
}

tree::TerminalNode* GrammarParser::Variable_declarationContext::K_CONST() {
  return getToken(GrammarParser::K_CONST, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Variable_declarationContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Variable_declarationContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

tree::TerminalNode* GrammarParser::Variable_declarationContext::AMPERSAND() {
  return getToken(GrammarParser::AMPERSAND, 0);
}

GrammarParser::Dynamic_array_brackets_paramsContext* GrammarParser::Variable_declarationContext::dynamic_array_brackets_params() {
  return getRuleContext<GrammarParser::Dynamic_array_brackets_paramsContext>(0);
}

GrammarParser::Initialization_valueContext* GrammarParser::Variable_declarationContext::initialization_value() {
  return getRuleContext<GrammarParser::Initialization_valueContext>(0);
}


size_t GrammarParser::Variable_declarationContext::getRuleIndex() const {
  return GrammarParser::RuleVariable_declaration;
}

void GrammarParser::Variable_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable_declaration(this);
}

void GrammarParser::Variable_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable_declaration(this);
}

GrammarParser::Variable_declarationContext* GrammarParser::variable_declaration() {
  Variable_declarationContext *_localctx = _tracker.createInstance<Variable_declarationContext>(_ctx, getState());
  enterRule(_localctx, 144, GrammarParser::RuleVariable_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1182);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 134, _ctx)) {
    case 1: {
      setState(1176);
      match(GrammarParser::K_CONST);
      setState(1178); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1177);
        space();
        setState(1180); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS);
      break;
    }

    }
    setState(1184);
    type();
    setState(1188);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1185);
      space();
      setState(1190);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1198);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::AMPERSAND) {
      setState(1191);
      match(GrammarParser::AMPERSAND);
      setState(1195);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1192);
        space();
        setState(1197);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1200);
    name();
    setState(1208);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 139, _ctx)) {
    case 1: {
      setState(1204);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1201);
        space();
        setState(1206);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1207);
      dynamic_array_brackets_params();
      break;
    }

    }
    setState(1217);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 141, _ctx)) {
    case 1: {
      setState(1213);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1210);
        space();
        setState(1215);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1216);
      initialization_value();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Append_variable_declarationContext ------------------------------------------------------------------

GrammarParser::Append_variable_declarationContext::Append_variable_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Append_variable_declarationContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

GrammarParser::NameContext* GrammarParser::Append_variable_declarationContext::name() {
  return getRuleContext<GrammarParser::NameContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Append_variable_declarationContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Append_variable_declarationContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::Dynamic_array_brackets_paramsContext* GrammarParser::Append_variable_declarationContext::dynamic_array_brackets_params() {
  return getRuleContext<GrammarParser::Dynamic_array_brackets_paramsContext>(0);
}

GrammarParser::Initialization_valueContext* GrammarParser::Append_variable_declarationContext::initialization_value() {
  return getRuleContext<GrammarParser::Initialization_valueContext>(0);
}


size_t GrammarParser::Append_variable_declarationContext::getRuleIndex() const {
  return GrammarParser::RuleAppend_variable_declaration;
}

void GrammarParser::Append_variable_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAppend_variable_declaration(this);
}

void GrammarParser::Append_variable_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAppend_variable_declaration(this);
}

GrammarParser::Append_variable_declarationContext* GrammarParser::append_variable_declaration() {
  Append_variable_declarationContext *_localctx = _tracker.createInstance<Append_variable_declarationContext>(_ctx, getState());
  enterRule(_localctx, 146, GrammarParser::RuleAppend_variable_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1222);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1219);
      space();
      setState(1224);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1225);
    match(GrammarParser::COMMA);
    setState(1229);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1226);
      space();
      setState(1231);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1232);
    name();
    setState(1240);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 145, _ctx)) {
    case 1: {
      setState(1236);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1233);
        space();
        setState(1238);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1239);
      dynamic_array_brackets_params();
      break;
    }

    }
    setState(1245);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 146, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1242);
        space(); 
      }
      setState(1247);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 146, _ctx);
    }
    setState(1249);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 147, _ctx)) {
    case 1: {
      setState(1248);
      initialization_value();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Initialization_valueContext ------------------------------------------------------------------

GrammarParser::Initialization_valueContext::Initialization_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Initialization_valueContext::EQ() {
  return getToken(GrammarParser::EQ, 0);
}

GrammarParser::Array_initialization_listContext* GrammarParser::Initialization_valueContext::array_initialization_list() {
  return getRuleContext<GrammarParser::Array_initialization_listContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Initialization_valueContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Initialization_valueContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

std::vector<GrammarParser::RvalueContext *> GrammarParser::Initialization_valueContext::rvalue() {
  return getRuleContexts<GrammarParser::RvalueContext>();
}

GrammarParser::RvalueContext* GrammarParser::Initialization_valueContext::rvalue(size_t i) {
  return getRuleContext<GrammarParser::RvalueContext>(i);
}


size_t GrammarParser::Initialization_valueContext::getRuleIndex() const {
  return GrammarParser::RuleInitialization_value;
}

void GrammarParser::Initialization_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitialization_value(this);
}

void GrammarParser::Initialization_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitialization_value(this);
}

GrammarParser::Initialization_valueContext* GrammarParser::initialization_value() {
  Initialization_valueContext *_localctx = _tracker.createInstance<Initialization_valueContext>(_ctx, getState());
  enterRule(_localctx, 148, GrammarParser::RuleInitialization_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1251);
    match(GrammarParser::EQ);
    setState(1255);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 148, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1252);
        space(); 
      }
      setState(1257);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 148, _ctx);
    }
    setState(1264);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx)) {
    case 1: {
      setState(1258);
      array_initialization_list();
      break;
    }

    case 2: {
      setState(1260); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(1259);
                rvalue();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(1262); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 149, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_initialization_listContext ------------------------------------------------------------------

GrammarParser::Array_initialization_listContext::Array_initialization_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Array_initialization_listContext::OP_CRL_BR() {
  return getToken(GrammarParser::OP_CRL_BR, 0);
}

tree::TerminalNode* GrammarParser::Array_initialization_listContext::CL_CRL_BR() {
  return getToken(GrammarParser::CL_CRL_BR, 0);
}

GrammarParser::Initialization_list_itemsContext* GrammarParser::Array_initialization_listContext::initialization_list_items() {
  return getRuleContext<GrammarParser::Initialization_list_itemsContext>(0);
}

std::vector<GrammarParser::Initialization_list_append_itemsContext *> GrammarParser::Array_initialization_listContext::initialization_list_append_items() {
  return getRuleContexts<GrammarParser::Initialization_list_append_itemsContext>();
}

GrammarParser::Initialization_list_append_itemsContext* GrammarParser::Array_initialization_listContext::initialization_list_append_items(size_t i) {
  return getRuleContext<GrammarParser::Initialization_list_append_itemsContext>(i);
}


size_t GrammarParser::Array_initialization_listContext::getRuleIndex() const {
  return GrammarParser::RuleArray_initialization_list;
}

void GrammarParser::Array_initialization_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArray_initialization_list(this);
}

void GrammarParser::Array_initialization_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArray_initialization_list(this);
}

GrammarParser::Array_initialization_listContext* GrammarParser::array_initialization_list() {
  Array_initialization_listContext *_localctx = _tracker.createInstance<Array_initialization_listContext>(_ctx, getState());
  enterRule(_localctx, 150, GrammarParser::RuleArray_initialization_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1266);
    match(GrammarParser::OP_CRL_BR);
    setState(1274);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::K_NULL))) != 0) || ((((_la - 91) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 91)) & ((1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 91))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 91))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 91))
      | (1ULL << (GrammarParser::IMA_MODE - 91))
      | (1ULL << (GrammarParser::PRICE_TYPE - 91))
      | (1ULL << (GrammarParser::TIMEFRAME - 91))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 91))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 91))
      | (1ULL << (GrammarParser::REGULAR_STRING - 91))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 91))
      | (1ULL << (GrammarParser::NAME - 91))
      | (1ULL << (GrammarParser::INTEGER - 91))
      | (1ULL << (GrammarParser::DATE_LITERAL - 91))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 91)))) != 0)) {
      setState(1267);
      initialization_list_items();
      setState(1271);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::COMMA) {
        setState(1268);
        initialization_list_append_items();
        setState(1273);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1276);
    match(GrammarParser::CL_CRL_BR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Initialization_list_append_itemsContext ------------------------------------------------------------------

GrammarParser::Initialization_list_append_itemsContext::Initialization_list_append_itemsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Initialization_list_append_itemsContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

GrammarParser::Initialization_list_itemsContext* GrammarParser::Initialization_list_append_itemsContext::initialization_list_items() {
  return getRuleContext<GrammarParser::Initialization_list_itemsContext>(0);
}


size_t GrammarParser::Initialization_list_append_itemsContext::getRuleIndex() const {
  return GrammarParser::RuleInitialization_list_append_items;
}

void GrammarParser::Initialization_list_append_itemsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitialization_list_append_items(this);
}

void GrammarParser::Initialization_list_append_itemsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitialization_list_append_items(this);
}

GrammarParser::Initialization_list_append_itemsContext* GrammarParser::initialization_list_append_items() {
  Initialization_list_append_itemsContext *_localctx = _tracker.createInstance<Initialization_list_append_itemsContext>(_ctx, getState());
  enterRule(_localctx, 152, GrammarParser::RuleInitialization_list_append_items);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1278);
    match(GrammarParser::COMMA);
    setState(1279);
    initialization_list_items();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Initialization_list_itemsContext ------------------------------------------------------------------

GrammarParser::Initialization_list_itemsContext::Initialization_list_itemsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Array_initialization_listContext* GrammarParser::Initialization_list_itemsContext::array_initialization_list() {
  return getRuleContext<GrammarParser::Array_initialization_listContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Initialization_list_itemsContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Initialization_list_itemsContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

std::vector<GrammarParser::Initialization_list_itemContext *> GrammarParser::Initialization_list_itemsContext::initialization_list_item() {
  return getRuleContexts<GrammarParser::Initialization_list_itemContext>();
}

GrammarParser::Initialization_list_itemContext* GrammarParser::Initialization_list_itemsContext::initialization_list_item(size_t i) {
  return getRuleContext<GrammarParser::Initialization_list_itemContext>(i);
}


size_t GrammarParser::Initialization_list_itemsContext::getRuleIndex() const {
  return GrammarParser::RuleInitialization_list_items;
}

void GrammarParser::Initialization_list_itemsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitialization_list_items(this);
}

void GrammarParser::Initialization_list_itemsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitialization_list_items(this);
}

GrammarParser::Initialization_list_itemsContext* GrammarParser::initialization_list_items() {
  Initialization_list_itemsContext *_localctx = _tracker.createInstance<Initialization_list_itemsContext>(_ctx, getState());
  enterRule(_localctx, 154, GrammarParser::RuleInitialization_list_items);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1304);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 157, _ctx)) {
    case 1: {
      setState(1284);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1281);
        space();
        setState(1286);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1287);
      array_initialization_list();
      setState(1291);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1288);
        space();
        setState(1293);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    case 2: {
      setState(1295); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1294);
        space();
        setState(1297); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS);
      break;
    }

    case 3: {
      setState(1300); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(1299);
        initialization_list_item();
        setState(1302); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GrammarParser::PLUS)
        | (1ULL << GrammarParser::MINUS)
        | (1ULL << GrammarParser::NEWLINE)
        | (1ULL << GrammarParser::WS)
        | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
        | (1ULL << GrammarParser::K_NULL))) != 0) || ((((_la - 91) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 91)) & ((1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 91))
        | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 91))
        | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 91))
        | (1ULL << (GrammarParser::IMA_MODE - 91))
        | (1ULL << (GrammarParser::PRICE_TYPE - 91))
        | (1ULL << (GrammarParser::TIMEFRAME - 91))
        | (1ULL << (GrammarParser::DT_LITTERAL_ST - 91))
        | (1ULL << (GrammarParser::CLR_LITTERAL - 91))
        | (1ULL << (GrammarParser::REGULAR_STRING - 91))
        | (1ULL << (GrammarParser::CHAR_LITTERAL - 91))
        | (1ULL << (GrammarParser::NAME - 91))
        | (1ULL << (GrammarParser::INTEGER - 91))
        | (1ULL << (GrammarParser::DATE_LITERAL - 91))
        | (1ULL << (GrammarParser::FLOATING_LITERAL - 91)))) != 0));
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Initialization_list_itemContext ------------------------------------------------------------------

GrammarParser::Initialization_list_itemContext::Initialization_list_itemContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Initialization_list_itemContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Initialization_list_itemContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::IntegerContext* GrammarParser::Initialization_list_itemContext::integer() {
  return getRuleContext<GrammarParser::IntegerContext>(0);
}

GrammarParser::Float_valueContext* GrammarParser::Initialization_list_itemContext::float_value() {
  return getRuleContext<GrammarParser::Float_valueContext>(0);
}

tree::TerminalNode* GrammarParser::Initialization_list_itemContext::NAME() {
  return getToken(GrammarParser::NAME, 0);
}

GrammarParser::StrContext* GrammarParser::Initialization_list_itemContext::str() {
  return getRuleContext<GrammarParser::StrContext>(0);
}

tree::TerminalNode* GrammarParser::Initialization_list_itemContext::CHAR_LITTERAL() {
  return getToken(GrammarParser::CHAR_LITTERAL, 0);
}

tree::TerminalNode* GrammarParser::Initialization_list_itemContext::K_NULL() {
  return getToken(GrammarParser::K_NULL, 0);
}

GrammarParser::Const_nameContext* GrammarParser::Initialization_list_itemContext::const_name() {
  return getRuleContext<GrammarParser::Const_nameContext>(0);
}

GrammarParser::Date_litteralContext* GrammarParser::Initialization_list_itemContext::date_litteral() {
  return getRuleContext<GrammarParser::Date_litteralContext>(0);
}

GrammarParser::Datetime_litteralContext* GrammarParser::Initialization_list_itemContext::datetime_litteral() {
  return getRuleContext<GrammarParser::Datetime_litteralContext>(0);
}

GrammarParser::Color_litteralContext* GrammarParser::Initialization_list_itemContext::color_litteral() {
  return getRuleContext<GrammarParser::Color_litteralContext>(0);
}


size_t GrammarParser::Initialization_list_itemContext::getRuleIndex() const {
  return GrammarParser::RuleInitialization_list_item;
}

void GrammarParser::Initialization_list_itemContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitialization_list_item(this);
}

void GrammarParser::Initialization_list_itemContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitialization_list_item(this);
}

GrammarParser::Initialization_list_itemContext* GrammarParser::initialization_list_item() {
  Initialization_list_itemContext *_localctx = _tracker.createInstance<Initialization_list_itemContext>(_ctx, getState());
  enterRule(_localctx, 156, GrammarParser::RuleInitialization_list_item);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1322);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 159, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1307); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(1306);
                space();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(1309); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 158, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1311);
      integer();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(1312);
      float_value();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(1313);
      match(GrammarParser::NAME);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(1314);
      str();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(1315);
      match(GrammarParser::CHAR_LITTERAL);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(1316);
      match(GrammarParser::K_NULL);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(1317);
      const_name();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(1318);
      date_litteral();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(1319);
      datetime_litteral();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(1320);
      color_litteral();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(1321);
      float_value();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_nameContext ------------------------------------------------------------------

GrammarParser::Const_nameContext::Const_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Const_nameContext::TIMEFRAME() {
  return getToken(GrammarParser::TIMEFRAME, 0);
}

tree::TerminalNode* GrammarParser::Const_nameContext::PRICE_TYPE() {
  return getToken(GrammarParser::PRICE_TYPE, 0);
}

tree::TerminalNode* GrammarParser::Const_nameContext::IMA_MODE() {
  return getToken(GrammarParser::IMA_MODE, 0);
}

tree::TerminalNode* GrammarParser::Const_nameContext::INDICATOR_LINE_IDENTIFIER_MODE() {
  return getToken(GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE, 0);
}

tree::TerminalNode* GrammarParser::Const_nameContext::UNSUPPORTED_PROPERTIES() {
  return getToken(GrammarParser::UNSUPPORTED_PROPERTIES, 0);
}

tree::TerminalNode* GrammarParser::Const_nameContext::UNSUPPORTED_OBJECTS() {
  return getToken(GrammarParser::UNSUPPORTED_OBJECTS, 0);
}

tree::TerminalNode* GrammarParser::Const_nameContext::INDEX_BUFFER_TYPE() {
  return getToken(GrammarParser::INDEX_BUFFER_TYPE, 0);
}


size_t GrammarParser::Const_nameContext::getRuleIndex() const {
  return GrammarParser::RuleConst_name;
}

void GrammarParser::Const_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConst_name(this);
}

void GrammarParser::Const_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConst_name(this);
}

GrammarParser::Const_nameContext* GrammarParser::const_name() {
  Const_nameContext *_localctx = _tracker.createInstance<Const_nameContext>(_ctx, getState());
  enterRule(_localctx, 158, GrammarParser::RuleConst_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1324);
    _la = _input->LA(1);
    if (!(((((_la - 45) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 45)) & ((1ULL << (GrammarParser::INDEX_BUFFER_TYPE - 45))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 45))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 45))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 45))
      | (1ULL << (GrammarParser::IMA_MODE - 45))
      | (1ULL << (GrammarParser::PRICE_TYPE - 45))
      | (1ULL << (GrammarParser::TIMEFRAME - 45)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dynamic_array_brackets_paramsContext ------------------------------------------------------------------

GrammarParser::Dynamic_array_brackets_paramsContext::Dynamic_array_brackets_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::Dynamic_array_brackets_parameterContext *> GrammarParser::Dynamic_array_brackets_paramsContext::dynamic_array_brackets_parameter() {
  return getRuleContexts<GrammarParser::Dynamic_array_brackets_parameterContext>();
}

GrammarParser::Dynamic_array_brackets_parameterContext* GrammarParser::Dynamic_array_brackets_paramsContext::dynamic_array_brackets_parameter(size_t i) {
  return getRuleContext<GrammarParser::Dynamic_array_brackets_parameterContext>(i);
}


size_t GrammarParser::Dynamic_array_brackets_paramsContext::getRuleIndex() const {
  return GrammarParser::RuleDynamic_array_brackets_params;
}

void GrammarParser::Dynamic_array_brackets_paramsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDynamic_array_brackets_params(this);
}

void GrammarParser::Dynamic_array_brackets_paramsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDynamic_array_brackets_params(this);
}

GrammarParser::Dynamic_array_brackets_paramsContext* GrammarParser::dynamic_array_brackets_params() {
  Dynamic_array_brackets_paramsContext *_localctx = _tracker.createInstance<Dynamic_array_brackets_paramsContext>(_ctx, getState());
  enterRule(_localctx, 160, GrammarParser::RuleDynamic_array_brackets_params);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1327); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(1326);
              dynamic_array_brackets_parameter();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(1329); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 160, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dynamic_array_brackets_parameterContext ------------------------------------------------------------------

GrammarParser::Dynamic_array_brackets_parameterContext::Dynamic_array_brackets_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Dynamic_array_brackets_parameterContext::OP_BR() {
  return getToken(GrammarParser::OP_BR, 0);
}

tree::TerminalNode* GrammarParser::Dynamic_array_brackets_parameterContext::CL_BR() {
  return getToken(GrammarParser::CL_BR, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Dynamic_array_brackets_parameterContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Dynamic_array_brackets_parameterContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::Dynamic_array_parameterContext* GrammarParser::Dynamic_array_brackets_parameterContext::dynamic_array_parameter() {
  return getRuleContext<GrammarParser::Dynamic_array_parameterContext>(0);
}

std::vector<GrammarParser::Dynamic_array_append_parameterContext *> GrammarParser::Dynamic_array_brackets_parameterContext::dynamic_array_append_parameter() {
  return getRuleContexts<GrammarParser::Dynamic_array_append_parameterContext>();
}

GrammarParser::Dynamic_array_append_parameterContext* GrammarParser::Dynamic_array_brackets_parameterContext::dynamic_array_append_parameter(size_t i) {
  return getRuleContext<GrammarParser::Dynamic_array_append_parameterContext>(i);
}


size_t GrammarParser::Dynamic_array_brackets_parameterContext::getRuleIndex() const {
  return GrammarParser::RuleDynamic_array_brackets_parameter;
}

void GrammarParser::Dynamic_array_brackets_parameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDynamic_array_brackets_parameter(this);
}

void GrammarParser::Dynamic_array_brackets_parameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDynamic_array_brackets_parameter(this);
}

GrammarParser::Dynamic_array_brackets_parameterContext* GrammarParser::dynamic_array_brackets_parameter() {
  Dynamic_array_brackets_parameterContext *_localctx = _tracker.createInstance<Dynamic_array_brackets_parameterContext>(_ctx, getState());
  enterRule(_localctx, 162, GrammarParser::RuleDynamic_array_brackets_parameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1331);
    match(GrammarParser::OP_BR);
    setState(1335);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 161, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1332);
        space(); 
      }
      setState(1337);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 161, _ctx);
    }
    setState(1353);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 165, _ctx)) {
    case 1: {
      setState(1338);
      dynamic_array_parameter();
      setState(1342);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(1339);
          dynamic_array_append_parameter(); 
        }
        setState(1344);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx);
      }
      break;
    }

    case 2: {
      setState(1346);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GrammarParser::NAME

      || _la == GrammarParser::INTEGER) {
        setState(1345);
        dynamic_array_parameter();
      }
      setState(1349); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(1348);
                dynamic_array_append_parameter();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(1351); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 164, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    }
    setState(1358);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1355);
      space();
      setState(1360);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1361);
    match(GrammarParser::CL_BR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dynamic_array_append_parameterContext ------------------------------------------------------------------

GrammarParser::Dynamic_array_append_parameterContext::Dynamic_array_append_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Dynamic_array_append_parameterContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Dynamic_array_append_parameterContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Dynamic_array_append_parameterContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::Dynamic_array_parameterContext* GrammarParser::Dynamic_array_append_parameterContext::dynamic_array_parameter() {
  return getRuleContext<GrammarParser::Dynamic_array_parameterContext>(0);
}


size_t GrammarParser::Dynamic_array_append_parameterContext::getRuleIndex() const {
  return GrammarParser::RuleDynamic_array_append_parameter;
}

void GrammarParser::Dynamic_array_append_parameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDynamic_array_append_parameter(this);
}

void GrammarParser::Dynamic_array_append_parameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDynamic_array_append_parameter(this);
}

GrammarParser::Dynamic_array_append_parameterContext* GrammarParser::dynamic_array_append_parameter() {
  Dynamic_array_append_parameterContext *_localctx = _tracker.createInstance<Dynamic_array_append_parameterContext>(_ctx, getState());
  enterRule(_localctx, 164, GrammarParser::RuleDynamic_array_append_parameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1366);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1363);
      space();
      setState(1368);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1369);
    match(GrammarParser::COMMA);
    setState(1373);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1370);
        space(); 
      }
      setState(1375);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 168, _ctx);
    }
    setState(1377);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::NAME

    || _la == GrammarParser::INTEGER) {
      setState(1376);
      dynamic_array_parameter();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Dynamic_array_parameterContext ------------------------------------------------------------------

GrammarParser::Dynamic_array_parameterContext::Dynamic_array_parameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Dynamic_array_parameterContext::NAME() {
  return getToken(GrammarParser::NAME, 0);
}

tree::TerminalNode* GrammarParser::Dynamic_array_parameterContext::INTEGER() {
  return getToken(GrammarParser::INTEGER, 0);
}


size_t GrammarParser::Dynamic_array_parameterContext::getRuleIndex() const {
  return GrammarParser::RuleDynamic_array_parameter;
}

void GrammarParser::Dynamic_array_parameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDynamic_array_parameter(this);
}

void GrammarParser::Dynamic_array_parameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDynamic_array_parameter(this);
}

GrammarParser::Dynamic_array_parameterContext* GrammarParser::dynamic_array_parameter() {
  Dynamic_array_parameterContext *_localctx = _tracker.createInstance<Dynamic_array_parameterContext>(_ctx, getState());
  enterRule(_localctx, 166, GrammarParser::RuleDynamic_array_parameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1379);
    _la = _input->LA(1);
    if (!(_la == GrammarParser::NAME

    || _la == GrammarParser::INTEGER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_index_bufferContext ------------------------------------------------------------------

GrammarParser::Set_index_bufferContext::Set_index_bufferContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Set_index_bufferContext::SET_INDEX_BUFFER() {
  return getToken(GrammarParser::SET_INDEX_BUFFER, 0);
}

tree::TerminalNode* GrammarParser::Set_index_bufferContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::Set_index_bufferContext::COMMA() {
  return getTokens(GrammarParser::COMMA);
}

tree::TerminalNode* GrammarParser::Set_index_bufferContext::COMMA(size_t i) {
  return getToken(GrammarParser::COMMA, i);
}

GrammarParser::NameContext* GrammarParser::Set_index_bufferContext::name() {
  return getRuleContext<GrammarParser::NameContext>(0);
}

tree::TerminalNode* GrammarParser::Set_index_bufferContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Set_index_bufferContext::INTEGER() {
  return getToken(GrammarParser::INTEGER, 0);
}

GrammarParser::RvalueContext* GrammarParser::Set_index_bufferContext::rvalue() {
  return getRuleContext<GrammarParser::RvalueContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Set_index_bufferContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Set_index_bufferContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

tree::TerminalNode* GrammarParser::Set_index_bufferContext::INDEX_BUFFER_TYPE() {
  return getToken(GrammarParser::INDEX_BUFFER_TYPE, 0);
}


size_t GrammarParser::Set_index_bufferContext::getRuleIndex() const {
  return GrammarParser::RuleSet_index_buffer;
}

void GrammarParser::Set_index_bufferContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSet_index_buffer(this);
}

void GrammarParser::Set_index_bufferContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSet_index_buffer(this);
}

GrammarParser::Set_index_bufferContext* GrammarParser::set_index_buffer() {
  Set_index_bufferContext *_localctx = _tracker.createInstance<Set_index_bufferContext>(_ctx, getState());
  enterRule(_localctx, 168, GrammarParser::RuleSet_index_buffer);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1381);
    match(GrammarParser::SET_INDEX_BUFFER);
    setState(1385);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1382);
      space();
      setState(1387);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1388);
    match(GrammarParser::OP_PARETHESES);
    setState(1392);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 171, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1389);
        space(); 
      }
      setState(1394);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 171, _ctx);
    }
    setState(1397);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 172, _ctx)) {
    case 1: {
      setState(1395);
      match(GrammarParser::INTEGER);
      break;
    }

    case 2: {
      setState(1396);
      rvalue();
      break;
    }

    }
    setState(1402);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1399);
      space();
      setState(1404);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1405);
    match(GrammarParser::COMMA);
    setState(1409);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1406);
      space();
      setState(1411);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1412);
    name();
    setState(1416);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1413);
      space();
      setState(1418);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1433);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::COMMA) {
      setState(1419);
      match(GrammarParser::COMMA);
      setState(1423);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1420);
        space();
        setState(1425);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1426);
      match(GrammarParser::INDEX_BUFFER_TYPE);
      setState(1430);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1427);
        space();
        setState(1432);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1435);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Set_level_styleContext ------------------------------------------------------------------

GrammarParser::Set_level_styleContext::Set_level_styleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Set_level_styleContext::SET_LEVEL_STYLE() {
  return getToken(GrammarParser::SET_LEVEL_STYLE, 0);
}

tree::TerminalNode* GrammarParser::Set_level_styleContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

GrammarParser::No_semicolonContext* GrammarParser::Set_level_styleContext::no_semicolon() {
  return getRuleContext<GrammarParser::No_semicolonContext>(0);
}

tree::TerminalNode* GrammarParser::Set_level_styleContext::SC() {
  return getToken(GrammarParser::SC, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Set_level_styleContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Set_level_styleContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Set_level_styleContext::getRuleIndex() const {
  return GrammarParser::RuleSet_level_style;
}

void GrammarParser::Set_level_styleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSet_level_style(this);
}

void GrammarParser::Set_level_styleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSet_level_style(this);
}

GrammarParser::Set_level_styleContext* GrammarParser::set_level_style() {
  Set_level_styleContext *_localctx = _tracker.createInstance<Set_level_styleContext>(_ctx, getState());
  enterRule(_localctx, 170, GrammarParser::RuleSet_level_style);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1437);
    match(GrammarParser::SET_LEVEL_STYLE);
    setState(1441);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1438);
      space();
      setState(1443);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1444);
    match(GrammarParser::OP_PARETHESES);
    setState(1445);
    no_semicolon();
    setState(1446);
    match(GrammarParser::SC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AlertContext ------------------------------------------------------------------

GrammarParser::AlertContext::AlertContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::AlertContext::ALERT() {
  return getToken(GrammarParser::ALERT, 0);
}

tree::TerminalNode* GrammarParser::AlertContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::AlertContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::AlertContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::AlertContext::getRuleIndex() const {
  return GrammarParser::RuleAlert;
}

void GrammarParser::AlertContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlert(this);
}

void GrammarParser::AlertContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlert(this);
}

GrammarParser::AlertContext* GrammarParser::alert() {
  AlertContext *_localctx = _tracker.createInstance<AlertContext>(_ctx, getState());
  enterRule(_localctx, 172, GrammarParser::RuleAlert);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1448);
    match(GrammarParser::ALERT);
    setState(1452);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1449);
      space();
      setState(1454);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1455);
    match(GrammarParser::OP_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_definitionContext ------------------------------------------------------------------

GrammarParser::Function_definitionContext::Function_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::TypeContext* GrammarParser::Function_definitionContext::type() {
  return getRuleContext<GrammarParser::TypeContext>(0);
}

tree::TerminalNode* GrammarParser::Function_definitionContext::NAME() {
  return getToken(GrammarParser::NAME, 0);
}

tree::TerminalNode* GrammarParser::Function_definitionContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Function_definitionContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Function_definitionContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Function_definitionContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

tree::TerminalNode* GrammarParser::Function_definitionContext::AMPERSAND() {
  return getToken(GrammarParser::AMPERSAND, 0);
}

GrammarParser::Params_listContext* GrammarParser::Function_definitionContext::params_list() {
  return getRuleContext<GrammarParser::Params_listContext>(0);
}


size_t GrammarParser::Function_definitionContext::getRuleIndex() const {
  return GrammarParser::RuleFunction_definition;
}

void GrammarParser::Function_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_definition(this);
}

void GrammarParser::Function_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_definition(this);
}

GrammarParser::Function_definitionContext* GrammarParser::function_definition() {
  Function_definitionContext *_localctx = _tracker.createInstance<Function_definitionContext>(_ctx, getState());
  enterRule(_localctx, 174, GrammarParser::RuleFunction_definition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1457);
    type();
    setState(1461);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 181, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1458);
        space(); 
      }
      setState(1463);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 181, _ctx);
    }
    setState(1465);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::AMPERSAND) {
      setState(1464);
      match(GrammarParser::AMPERSAND);
    }
    setState(1470);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1467);
      space();
      setState(1472);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1473);
    match(GrammarParser::NAME);
    setState(1477);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1474);
      space();
      setState(1479);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1480);
    match(GrammarParser::OP_PARETHESES);
    setState(1484);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1481);
      space();
      setState(1486);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1488);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & ((1ULL << (GrammarParser::K_CONST - 52))
      | (1ULL << (GrammarParser::K_UNSIGNED - 52))
      | (1ULL << (GrammarParser::T_DOUBLE - 52))
      | (1ULL << (GrammarParser::T_FLOAT - 52))
      | (1ULL << (GrammarParser::T_VOID - 52))
      | (1ULL << (GrammarParser::T_INT - 52))
      | (1ULL << (GrammarParser::T_BOOL - 52))
      | (1ULL << (GrammarParser::T_LONG - 52))
      | (1ULL << (GrammarParser::T_SHORT - 52))
      | (1ULL << (GrammarParser::T_CHAR - 52))
      | (1ULL << (GrammarParser::T_STRING - 52))
      | (1ULL << (GrammarParser::T_COLOR - 52))
      | (1ULL << (GrammarParser::T_ULONG - 52))
      | (1ULL << (GrammarParser::T_DATETIME - 52))
      | (1ULL << (GrammarParser::NAME - 52)))) != 0)) {
      setState(1487);
      params_list(0);
    }
    setState(1490);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

GrammarParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::Type_nameContext *> GrammarParser::TypeContext::type_name() {
  return getRuleContexts<GrammarParser::Type_nameContext>();
}

GrammarParser::Type_nameContext* GrammarParser::TypeContext::type_name(size_t i) {
  return getRuleContext<GrammarParser::Type_nameContext>(i);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::TypeContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::TypeContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::TypeContext::getRuleIndex() const {
  return GrammarParser::RuleType;
}

void GrammarParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void GrammarParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

GrammarParser::TypeContext* GrammarParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 176, GrammarParser::RuleType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1492);
    type_name();
    setState(1502);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 188, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1496);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GrammarParser::NEWLINE

        || _la == GrammarParser::WS) {
          setState(1493);
          space();
          setState(1498);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(1499);
        type_name(); 
      }
      setState(1504);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 188, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_nameContext ------------------------------------------------------------------

GrammarParser::Type_nameContext::Type_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_VOID() {
  return getToken(GrammarParser::T_VOID, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_INT() {
  return getToken(GrammarParser::T_INT, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_DOUBLE() {
  return getToken(GrammarParser::T_DOUBLE, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_FLOAT() {
  return getToken(GrammarParser::T_FLOAT, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::K_CONST() {
  return getToken(GrammarParser::K_CONST, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_BOOL() {
  return getToken(GrammarParser::T_BOOL, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_CHAR() {
  return getToken(GrammarParser::T_CHAR, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::K_UNSIGNED() {
  return getToken(GrammarParser::K_UNSIGNED, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_LONG() {
  return getToken(GrammarParser::T_LONG, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_SHORT() {
  return getToken(GrammarParser::T_SHORT, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_STRING() {
  return getToken(GrammarParser::T_STRING, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_COLOR() {
  return getToken(GrammarParser::T_COLOR, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_ULONG() {
  return getToken(GrammarParser::T_ULONG, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::T_DATETIME() {
  return getToken(GrammarParser::T_DATETIME, 0);
}

tree::TerminalNode* GrammarParser::Type_nameContext::NAME() {
  return getToken(GrammarParser::NAME, 0);
}


size_t GrammarParser::Type_nameContext::getRuleIndex() const {
  return GrammarParser::RuleType_name;
}

void GrammarParser::Type_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_name(this);
}

void GrammarParser::Type_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_name(this);
}

GrammarParser::Type_nameContext* GrammarParser::type_name() {
  Type_nameContext *_localctx = _tracker.createInstance<Type_nameContext>(_ctx, getState());
  enterRule(_localctx, 178, GrammarParser::RuleType_name);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1505);
    _la = _input->LA(1);
    if (!(((((_la - 52) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 52)) & ((1ULL << (GrammarParser::K_CONST - 52))
      | (1ULL << (GrammarParser::K_UNSIGNED - 52))
      | (1ULL << (GrammarParser::T_DOUBLE - 52))
      | (1ULL << (GrammarParser::T_FLOAT - 52))
      | (1ULL << (GrammarParser::T_VOID - 52))
      | (1ULL << (GrammarParser::T_INT - 52))
      | (1ULL << (GrammarParser::T_BOOL - 52))
      | (1ULL << (GrammarParser::T_LONG - 52))
      | (1ULL << (GrammarParser::T_SHORT - 52))
      | (1ULL << (GrammarParser::T_CHAR - 52))
      | (1ULL << (GrammarParser::T_STRING - 52))
      | (1ULL << (GrammarParser::T_COLOR - 52))
      | (1ULL << (GrammarParser::T_ULONG - 52))
      | (1ULL << (GrammarParser::T_DATETIME - 52))
      | (1ULL << (GrammarParser::NAME - 52)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Params_listContext ------------------------------------------------------------------

GrammarParser::Params_listContext::Params_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::ArgumentContext* GrammarParser::Params_listContext::argument() {
  return getRuleContext<GrammarParser::ArgumentContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Params_listContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Params_listContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

GrammarParser::Params_listContext* GrammarParser::Params_listContext::params_list() {
  return getRuleContext<GrammarParser::Params_listContext>(0);
}

GrammarParser::Append_argumentContext* GrammarParser::Params_listContext::append_argument() {
  return getRuleContext<GrammarParser::Append_argumentContext>(0);
}


size_t GrammarParser::Params_listContext::getRuleIndex() const {
  return GrammarParser::RuleParams_list;
}

void GrammarParser::Params_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParams_list(this);
}

void GrammarParser::Params_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParams_list(this);
}


GrammarParser::Params_listContext* GrammarParser::params_list() {
   return params_list(0);
}

GrammarParser::Params_listContext* GrammarParser::params_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GrammarParser::Params_listContext *_localctx = _tracker.createInstance<Params_listContext>(_ctx, parentState);
  GrammarParser::Params_listContext *previousContext = _localctx;
  size_t startState = 180;
  enterRecursionRule(_localctx, 180, GrammarParser::RuleParams_list, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1508);
    argument();
    setState(1512);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 189, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1509);
        space(); 
      }
      setState(1514);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 189, _ctx);
    }
    _ctx->stop = _input->LT(-1);
    setState(1519);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 190, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Params_listContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParams_list);
        setState(1515);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1516);
        append_argument(); 
      }
      setState(1521);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 190, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Append_argumentContext ------------------------------------------------------------------

GrammarParser::Append_argumentContext::Append_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Append_argumentContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

GrammarParser::ArgumentContext* GrammarParser::Append_argumentContext::argument() {
  return getRuleContext<GrammarParser::ArgumentContext>(0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Append_argumentContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Append_argumentContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Append_argumentContext::getRuleIndex() const {
  return GrammarParser::RuleAppend_argument;
}

void GrammarParser::Append_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAppend_argument(this);
}

void GrammarParser::Append_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAppend_argument(this);
}

GrammarParser::Append_argumentContext* GrammarParser::append_argument() {
  Append_argumentContext *_localctx = _tracker.createInstance<Append_argumentContext>(_ctx, getState());
  enterRule(_localctx, 182, GrammarParser::RuleAppend_argument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1522);
    match(GrammarParser::COMMA);
    setState(1526);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1523);
      space();
      setState(1528);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1529);
    argument();
    setState(1533);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 192, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(1530);
        space(); 
      }
      setState(1535);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 192, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

GrammarParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Variable_declarationContext* GrammarParser::ArgumentContext::variable_declaration() {
  return getRuleContext<GrammarParser::Variable_declarationContext>(0);
}


size_t GrammarParser::ArgumentContext::getRuleIndex() const {
  return GrammarParser::RuleArgument;
}

void GrammarParser::ArgumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument(this);
}

void GrammarParser::ArgumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument(this);
}

GrammarParser::ArgumentContext* GrammarParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 184, GrammarParser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1536);
    variable_declaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fcall_argumentContext ------------------------------------------------------------------

GrammarParser::Fcall_argumentContext::Fcall_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GrammarParser::Fcall_anyruleContext *> GrammarParser::Fcall_argumentContext::fcall_anyrule() {
  return getRuleContexts<GrammarParser::Fcall_anyruleContext>();
}

GrammarParser::Fcall_anyruleContext* GrammarParser::Fcall_argumentContext::fcall_anyrule(size_t i) {
  return getRuleContext<GrammarParser::Fcall_anyruleContext>(i);
}

std::vector<GrammarParser::Fcall_paramsContext *> GrammarParser::Fcall_argumentContext::fcall_params() {
  return getRuleContexts<GrammarParser::Fcall_paramsContext>();
}

GrammarParser::Fcall_paramsContext* GrammarParser::Fcall_argumentContext::fcall_params(size_t i) {
  return getRuleContext<GrammarParser::Fcall_paramsContext>(i);
}


size_t GrammarParser::Fcall_argumentContext::getRuleIndex() const {
  return GrammarParser::RuleFcall_argument;
}

void GrammarParser::Fcall_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFcall_argument(this);
}

void GrammarParser::Fcall_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFcall_argument(this);
}

GrammarParser::Fcall_argumentContext* GrammarParser::fcall_argument() {
  Fcall_argumentContext *_localctx = _tracker.createInstance<Fcall_argumentContext>(_ctx, getState());
  enterRule(_localctx, 186, GrammarParser::RuleFcall_argument);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(1560);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 197, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1539); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(1538);
                fcall_anyrule();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(1541); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 193, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1546);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
        | (1ULL << GrammarParser::DOT)
        | (1ULL << GrammarParser::OP_BR)
        | (1ULL << GrammarParser::CL_BR)
        | (1ULL << GrammarParser::OP_CRL_BR)
        | (1ULL << GrammarParser::CL_CRL_BR)
        | (1ULL << GrammarParser::COLON)
        | (1ULL << GrammarParser::SC)
        | (1ULL << GrammarParser::D_QUOTE)
        | (1ULL << GrammarParser::S_QUOTE)
        | (1ULL << GrammarParser::EQ)
        | (1ULL << GrammarParser::COMPARISSON)
        | (1ULL << GrammarParser::COMPARISSON_NOT)
        | (1ULL << GrammarParser::MORE_OR_EQUAL)
        | (1ULL << GrammarParser::LESS_OR_EQUAL)
        | (1ULL << GrammarParser::INCREMENT)
        | (1ULL << GrammarParser::DECREMENT)
        | (1ULL << GrammarParser::PLUS)
        | (1ULL << GrammarParser::MINUS)
        | (1ULL << GrammarParser::ASTRISK)
        | (1ULL << GrammarParser::SLASH)
        | (1ULL << GrammarParser::AMPERSAND)
        | (1ULL << GrammarParser::NEWLINE)
        | (1ULL << GrammarParser::BD_SLASH)
        | (1ULL << GrammarParser::OP_COMMENT)
        | (1ULL << GrammarParser::CL_COMMENT)
        | (1ULL << GrammarParser::MULTILINE_COMMENT)
        | (1ULL << GrammarParser::ONELINE_COMMENT)
        | (1ULL << GrammarParser::WS)
        | (1ULL << GrammarParser::DEINIT)
        | (1ULL << GrammarParser::INIT)
        | (1ULL << GrammarParser::START)
        | (1ULL << GrammarParser::ON_CALCULATE)
        | (1ULL << GrammarParser::ON_TICK)
        | (1ULL << GrammarParser::ON_INIT)
        | (1ULL << GrammarParser::ON_DEINIT)
        | (1ULL << GrammarParser::ON_TIMER)
        | (1ULL << GrammarParser::ON_CHART_EVENT)
        | (1ULL << GrammarParser::TRY_BLOCK_DASH)
        | (1ULL << GrammarParser::TRY_BLOCK_START)
        | (1ULL << GrammarParser::TRY_BLOCK_END)
        | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
        | (1ULL << GrammarParser::EXTERN)
        | (1ULL << GrammarParser::INPUT)
        | (1ULL << GrammarParser::SINPUT)
        | (1ULL << GrammarParser::K_STATIC)
        | (1ULL << GrammarParser::K_STRICT)
        | (1ULL << GrammarParser::K_NULL)
        | (1ULL << GrammarParser::K_CONST)
        | (1ULL << GrammarParser::K_UNSIGNED)
        | (1ULL << GrammarParser::K_ENUM)
        | (1ULL << GrammarParser::K_ELSE)
        | (1ULL << GrammarParser::K_SWITCH)
        | (1ULL << GrammarParser::K_CASE)
        | (1ULL << GrammarParser::K_RETURN)
        | (1ULL << GrammarParser::K_FOR)
        | (1ULL << GrammarParser::K_IF)
        | (1ULL << GrammarParser::T_DOUBLE)
        | (1ULL << GrammarParser::T_FLOAT)
        | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
        | (1ULL << (GrammarParser::T_BOOL - 64))
        | (1ULL << (GrammarParser::T_LONG - 64))
        | (1ULL << (GrammarParser::T_SHORT - 64))
        | (1ULL << (GrammarParser::T_CHAR - 64))
        | (1ULL << (GrammarParser::T_STRING - 64))
        | (1ULL << (GrammarParser::T_COLOR - 64))
        | (1ULL << (GrammarParser::T_ULONG - 64))
        | (1ULL << (GrammarParser::T_DATETIME - 64))
        | (1ULL << (GrammarParser::PROPERTY - 64))
        | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
        | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
        | (1ULL << (GrammarParser::ALERT - 64))
        | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
        | (1ULL << (GrammarParser::PLAY_SOUND - 64))
        | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
        | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
        | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
        | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
        | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
        | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
        | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
        | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
        | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
        | (1ULL << (GrammarParser::TIME_CURRENT - 64))
        | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
        | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
        | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
        | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
        | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
        | (1ULL << (GrammarParser::IMA_MODE - 64))
        | (1ULL << (GrammarParser::PRICE_TYPE - 64))
        | (1ULL << (GrammarParser::TIMEFRAME - 64))
        | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
        | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
        | (1ULL << (GrammarParser::REGULAR_STRING - 64))
        | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
        | (1ULL << (GrammarParser::NAME - 64))
        | (1ULL << (GrammarParser::INTEGER - 64))
        | (1ULL << (GrammarParser::HEX_INTEGER - 64))
        | (1ULL << (GrammarParser::DATE_LITERAL - 64))
        | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
        | (1ULL << (GrammarParser::LETTER - 64))
        | (1ULL << (GrammarParser::DIGIT - 64))
        | (1ULL << (GrammarParser::ANY - 64))
        | (1ULL << (GrammarParser::MANY - 64)))) != 0)) {
        setState(1543);
        fcall_anyrule();
        setState(1548);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(1556); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(1549);
                fcall_params();
                setState(1553);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 195, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                  if (alt == 1) {
                    setState(1550);
                    fcall_anyrule(); 
                  }
                  setState(1555);
                  _errHandler->sync(this);
                  alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 195, _ctx);
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(1558); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 196, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fcall_anyruleContext ------------------------------------------------------------------

GrammarParser::Fcall_anyruleContext::Fcall_anyruleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Argument_contentContext* GrammarParser::Fcall_anyruleContext::argument_content() {
  return getRuleContext<GrammarParser::Argument_contentContext>(0);
}

GrammarParser::No_commaContext* GrammarParser::Fcall_anyruleContext::no_comma() {
  return getRuleContext<GrammarParser::No_commaContext>(0);
}


size_t GrammarParser::Fcall_anyruleContext::getRuleIndex() const {
  return GrammarParser::RuleFcall_anyrule;
}

void GrammarParser::Fcall_anyruleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFcall_anyrule(this);
}

void GrammarParser::Fcall_anyruleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFcall_anyrule(this);
}

GrammarParser::Fcall_anyruleContext* GrammarParser::fcall_anyrule() {
  Fcall_anyruleContext *_localctx = _tracker.createInstance<Fcall_anyruleContext>(_ctx, getState());
  enterRule(_localctx, 188, GrammarParser::RuleFcall_anyrule);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(1564);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 198, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(1562);
      argument_content();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(1563);
      no_comma();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fcall_paramsContext ------------------------------------------------------------------

GrammarParser::Fcall_paramsContext::Fcall_paramsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Fcall_paramsContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Fcall_paramsContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

GrammarParser::Fcall_params_listContext* GrammarParser::Fcall_paramsContext::fcall_params_list() {
  return getRuleContext<GrammarParser::Fcall_params_listContext>(0);
}


size_t GrammarParser::Fcall_paramsContext::getRuleIndex() const {
  return GrammarParser::RuleFcall_params;
}

void GrammarParser::Fcall_paramsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFcall_params(this);
}

void GrammarParser::Fcall_paramsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFcall_params(this);
}

GrammarParser::Fcall_paramsContext* GrammarParser::fcall_params() {
  Fcall_paramsContext *_localctx = _tracker.createInstance<Fcall_paramsContext>(_ctx, getState());
  enterRule(_localctx, 190, GrammarParser::RuleFcall_params);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1566);
    match(GrammarParser::OP_PARETHESES);
    setState(1568);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
      | (1ULL << GrammarParser::DOT)
      | (1ULL << GrammarParser::OP_BR)
      | (1ULL << GrammarParser::CL_BR)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::CL_CRL_BR)
      | (1ULL << GrammarParser::COLON)
      | (1ULL << GrammarParser::SC)
      | (1ULL << GrammarParser::D_QUOTE)
      | (1ULL << GrammarParser::S_QUOTE)
      | (1ULL << GrammarParser::EQ)
      | (1ULL << GrammarParser::COMPARISSON)
      | (1ULL << GrammarParser::COMPARISSON_NOT)
      | (1ULL << GrammarParser::MORE_OR_EQUAL)
      | (1ULL << GrammarParser::LESS_OR_EQUAL)
      | (1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH)
      | (1ULL << GrammarParser::AMPERSAND)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::BD_SLASH)
      | (1ULL << GrammarParser::OP_COMMENT)
      | (1ULL << GrammarParser::CL_COMMENT)
      | (1ULL << GrammarParser::MULTILINE_COMMENT)
      | (1ULL << GrammarParser::ONELINE_COMMENT)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::ON_CHART_EVENT)
      | (1ULL << GrammarParser::TRY_BLOCK_DASH)
      | (1ULL << GrammarParser::TRY_BLOCK_START)
      | (1ULL << GrammarParser::TRY_BLOCK_END)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC)
      | (1ULL << GrammarParser::K_STRICT)
      | (1ULL << GrammarParser::K_NULL)
      | (1ULL << GrammarParser::K_CONST)
      | (1ULL << GrammarParser::K_UNSIGNED)
      | (1ULL << GrammarParser::K_ENUM)
      | (1ULL << GrammarParser::K_ELSE)
      | (1ULL << GrammarParser::K_SWITCH)
      | (1ULL << GrammarParser::K_CASE)
      | (1ULL << GrammarParser::K_RETURN)
      | (1ULL << GrammarParser::K_FOR)
      | (1ULL << GrammarParser::K_IF)
      | (1ULL << GrammarParser::T_DOUBLE)
      | (1ULL << GrammarParser::T_FLOAT)
      | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
      | (1ULL << (GrammarParser::T_BOOL - 64))
      | (1ULL << (GrammarParser::T_LONG - 64))
      | (1ULL << (GrammarParser::T_SHORT - 64))
      | (1ULL << (GrammarParser::T_CHAR - 64))
      | (1ULL << (GrammarParser::T_STRING - 64))
      | (1ULL << (GrammarParser::T_COLOR - 64))
      | (1ULL << (GrammarParser::T_ULONG - 64))
      | (1ULL << (GrammarParser::T_DATETIME - 64))
      | (1ULL << (GrammarParser::PROPERTY - 64))
      | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
      | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
      | (1ULL << (GrammarParser::ALERT - 64))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
      | (1ULL << (GrammarParser::PLAY_SOUND - 64))
      | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
      | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
      | (1ULL << (GrammarParser::TIME_CURRENT - 64))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
      | (1ULL << (GrammarParser::IMA_MODE - 64))
      | (1ULL << (GrammarParser::PRICE_TYPE - 64))
      | (1ULL << (GrammarParser::TIMEFRAME - 64))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
      | (1ULL << (GrammarParser::REGULAR_STRING - 64))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
      | (1ULL << (GrammarParser::NAME - 64))
      | (1ULL << (GrammarParser::INTEGER - 64))
      | (1ULL << (GrammarParser::HEX_INTEGER - 64))
      | (1ULL << (GrammarParser::DATE_LITERAL - 64))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
      | (1ULL << (GrammarParser::LETTER - 64))
      | (1ULL << (GrammarParser::DIGIT - 64))
      | (1ULL << (GrammarParser::ANY - 64))
      | (1ULL << (GrammarParser::MANY - 64)))) != 0)) {
      setState(1567);
      fcall_params_list(0);
    }
    setState(1570);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Fcall_params_listContext ------------------------------------------------------------------

GrammarParser::Fcall_params_listContext::Fcall_params_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Fcall_argumentContext* GrammarParser::Fcall_params_listContext::fcall_argument() {
  return getRuleContext<GrammarParser::Fcall_argumentContext>(0);
}

GrammarParser::Fcall_params_listContext* GrammarParser::Fcall_params_listContext::fcall_params_list() {
  return getRuleContext<GrammarParser::Fcall_params_listContext>(0);
}

GrammarParser::Append_fcall_argumentContext* GrammarParser::Fcall_params_listContext::append_fcall_argument() {
  return getRuleContext<GrammarParser::Append_fcall_argumentContext>(0);
}


size_t GrammarParser::Fcall_params_listContext::getRuleIndex() const {
  return GrammarParser::RuleFcall_params_list;
}

void GrammarParser::Fcall_params_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFcall_params_list(this);
}

void GrammarParser::Fcall_params_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFcall_params_list(this);
}


GrammarParser::Fcall_params_listContext* GrammarParser::fcall_params_list() {
   return fcall_params_list(0);
}

GrammarParser::Fcall_params_listContext* GrammarParser::fcall_params_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GrammarParser::Fcall_params_listContext *_localctx = _tracker.createInstance<Fcall_params_listContext>(_ctx, parentState);
  GrammarParser::Fcall_params_listContext *previousContext = _localctx;
  size_t startState = 192;
  enterRecursionRule(_localctx, 192, GrammarParser::RuleFcall_params_list, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(1573);
    fcall_argument();
    _ctx->stop = _input->LT(-1);
    setState(1579);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 200, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Fcall_params_listContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleFcall_params_list);
        setState(1575);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(1576);
        append_fcall_argument(); 
      }
      setState(1581);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 200, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Append_fcall_argumentContext ------------------------------------------------------------------

GrammarParser::Append_fcall_argumentContext::Append_fcall_argumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Append_fcall_argumentContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

GrammarParser::Fcall_argumentContext* GrammarParser::Append_fcall_argumentContext::fcall_argument() {
  return getRuleContext<GrammarParser::Fcall_argumentContext>(0);
}


size_t GrammarParser::Append_fcall_argumentContext::getRuleIndex() const {
  return GrammarParser::RuleAppend_fcall_argument;
}

void GrammarParser::Append_fcall_argumentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAppend_fcall_argument(this);
}

void GrammarParser::Append_fcall_argumentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAppend_fcall_argument(this);
}

GrammarParser::Append_fcall_argumentContext* GrammarParser::append_fcall_argument() {
  Append_fcall_argumentContext *_localctx = _tracker.createInstance<Append_fcall_argumentContext>(_ctx, getState());
  enterRule(_localctx, 194, GrammarParser::RuleAppend_fcall_argument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1582);
    match(GrammarParser::COMMA);
    setState(1583);
    fcall_argument();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Deinit_function_callContext ------------------------------------------------------------------

GrammarParser::Deinit_function_callContext::Deinit_function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Deinit_function_callContext::DEINIT() {
  return getToken(GrammarParser::DEINIT, 0);
}

tree::TerminalNode* GrammarParser::Deinit_function_callContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Deinit_function_callContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::Deinit_function_callContext::T_VOID() {
  return getTokens(GrammarParser::T_VOID);
}

tree::TerminalNode* GrammarParser::Deinit_function_callContext::T_VOID(size_t i) {
  return getToken(GrammarParser::T_VOID, i);
}

tree::TerminalNode* GrammarParser::Deinit_function_callContext::T_INT() {
  return getToken(GrammarParser::T_INT, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Deinit_function_callContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Deinit_function_callContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Deinit_function_callContext::getRuleIndex() const {
  return GrammarParser::RuleDeinit_function_call;
}

void GrammarParser::Deinit_function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeinit_function_call(this);
}

void GrammarParser::Deinit_function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeinit_function_call(this);
}

GrammarParser::Deinit_function_callContext* GrammarParser::deinit_function_call() {
  Deinit_function_callContext *_localctx = _tracker.createInstance<Deinit_function_callContext>(_ctx, getState());
  enterRule(_localctx, 196, GrammarParser::RuleDeinit_function_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1585);
    _la = _input->LA(1);
    if (!(_la == GrammarParser::T_VOID

    || _la == GrammarParser::T_INT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1587); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1586);
      space();
      setState(1589); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS);
    setState(1591);
    match(GrammarParser::DEINIT);
    setState(1595);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1592);
      space();
      setState(1597);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1598);
    match(GrammarParser::OP_PARETHESES);
    setState(1602);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1599);
      space();
      setState(1604);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1612);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::T_VOID) {
      setState(1605);
      match(GrammarParser::T_VOID);
      setState(1609);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1606);
        space();
        setState(1611);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1614);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Init_function_callContext ------------------------------------------------------------------

GrammarParser::Init_function_callContext::Init_function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Init_function_callContext::INIT() {
  return getToken(GrammarParser::INIT, 0);
}

tree::TerminalNode* GrammarParser::Init_function_callContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Init_function_callContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::Init_function_callContext::T_VOID() {
  return getTokens(GrammarParser::T_VOID);
}

tree::TerminalNode* GrammarParser::Init_function_callContext::T_VOID(size_t i) {
  return getToken(GrammarParser::T_VOID, i);
}

tree::TerminalNode* GrammarParser::Init_function_callContext::T_INT() {
  return getToken(GrammarParser::T_INT, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Init_function_callContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Init_function_callContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Init_function_callContext::getRuleIndex() const {
  return GrammarParser::RuleInit_function_call;
}

void GrammarParser::Init_function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInit_function_call(this);
}

void GrammarParser::Init_function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInit_function_call(this);
}

GrammarParser::Init_function_callContext* GrammarParser::init_function_call() {
  Init_function_callContext *_localctx = _tracker.createInstance<Init_function_callContext>(_ctx, getState());
  enterRule(_localctx, 198, GrammarParser::RuleInit_function_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1616);
    _la = _input->LA(1);
    if (!(_la == GrammarParser::T_VOID

    || _la == GrammarParser::T_INT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1618); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1617);
      space();
      setState(1620); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS);
    setState(1622);
    match(GrammarParser::INIT);
    setState(1626);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1623);
      space();
      setState(1628);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1629);
    match(GrammarParser::OP_PARETHESES);
    setState(1633);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1630);
      space();
      setState(1635);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1643);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::T_VOID) {
      setState(1636);
      match(GrammarParser::T_VOID);
      setState(1640);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1637);
        space();
        setState(1642);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1645);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Start_function_callContext ------------------------------------------------------------------

GrammarParser::Start_function_callContext::Start_function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Start_function_callContext::START() {
  return getToken(GrammarParser::START, 0);
}

tree::TerminalNode* GrammarParser::Start_function_callContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::Start_function_callContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::Start_function_callContext::T_VOID() {
  return getTokens(GrammarParser::T_VOID);
}

tree::TerminalNode* GrammarParser::Start_function_callContext::T_VOID(size_t i) {
  return getToken(GrammarParser::T_VOID, i);
}

tree::TerminalNode* GrammarParser::Start_function_callContext::T_INT() {
  return getToken(GrammarParser::T_INT, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::Start_function_callContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::Start_function_callContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::Start_function_callContext::getRuleIndex() const {
  return GrammarParser::RuleStart_function_call;
}

void GrammarParser::Start_function_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart_function_call(this);
}

void GrammarParser::Start_function_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart_function_call(this);
}

GrammarParser::Start_function_callContext* GrammarParser::start_function_call() {
  Start_function_callContext *_localctx = _tracker.createInstance<Start_function_callContext>(_ctx, getState());
  enterRule(_localctx, 200, GrammarParser::RuleStart_function_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1647);
    _la = _input->LA(1);
    if (!(_la == GrammarParser::T_VOID

    || _la == GrammarParser::T_INT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1649); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1648);
      space();
      setState(1651); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS);
    setState(1653);
    match(GrammarParser::START);
    setState(1657);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1654);
      space();
      setState(1659);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1660);
    match(GrammarParser::OP_PARETHESES);
    setState(1664);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1661);
      space();
      setState(1666);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1674);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::T_VOID) {
      setState(1667);
      match(GrammarParser::T_VOID);
      setState(1671);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1668);
        space();
        setState(1673);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1676);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- On_calculate_handlerContext ------------------------------------------------------------------

GrammarParser::On_calculate_handlerContext::On_calculate_handlerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::On_calculate_handlerContext::T_INT() {
  return getToken(GrammarParser::T_INT, 0);
}

tree::TerminalNode* GrammarParser::On_calculate_handlerContext::ON_CALCULATE() {
  return getToken(GrammarParser::ON_CALCULATE, 0);
}

tree::TerminalNode* GrammarParser::On_calculate_handlerContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

GrammarParser::No_cl_parenthesesContext* GrammarParser::On_calculate_handlerContext::no_cl_parentheses() {
  return getRuleContext<GrammarParser::No_cl_parenthesesContext>(0);
}

tree::TerminalNode* GrammarParser::On_calculate_handlerContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::On_calculate_handlerContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::On_calculate_handlerContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::On_calculate_handlerContext::getRuleIndex() const {
  return GrammarParser::RuleOn_calculate_handler;
}

void GrammarParser::On_calculate_handlerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOn_calculate_handler(this);
}

void GrammarParser::On_calculate_handlerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOn_calculate_handler(this);
}

GrammarParser::On_calculate_handlerContext* GrammarParser::on_calculate_handler() {
  On_calculate_handlerContext *_localctx = _tracker.createInstance<On_calculate_handlerContext>(_ctx, getState());
  enterRule(_localctx, 202, GrammarParser::RuleOn_calculate_handler);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1678);
    match(GrammarParser::T_INT);
    setState(1680); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1679);
      space();
      setState(1682); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS);
    setState(1684);
    match(GrammarParser::ON_CALCULATE);
    setState(1688);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1685);
      space();
      setState(1690);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1691);
    match(GrammarParser::OP_PARETHESES);
    setState(1692);
    no_cl_parentheses();
    setState(1693);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- On_tick_handlerContext ------------------------------------------------------------------

GrammarParser::On_tick_handlerContext::On_tick_handlerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Type_nameContext* GrammarParser::On_tick_handlerContext::type_name() {
  return getRuleContext<GrammarParser::Type_nameContext>(0);
}

tree::TerminalNode* GrammarParser::On_tick_handlerContext::ON_TICK() {
  return getToken(GrammarParser::ON_TICK, 0);
}

tree::TerminalNode* GrammarParser::On_tick_handlerContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::On_tick_handlerContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::On_tick_handlerContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::On_tick_handlerContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}

tree::TerminalNode* GrammarParser::On_tick_handlerContext::T_VOID() {
  return getToken(GrammarParser::T_VOID, 0);
}


size_t GrammarParser::On_tick_handlerContext::getRuleIndex() const {
  return GrammarParser::RuleOn_tick_handler;
}

void GrammarParser::On_tick_handlerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOn_tick_handler(this);
}

void GrammarParser::On_tick_handlerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOn_tick_handler(this);
}

GrammarParser::On_tick_handlerContext* GrammarParser::on_tick_handler() {
  On_tick_handlerContext *_localctx = _tracker.createInstance<On_tick_handlerContext>(_ctx, getState());
  enterRule(_localctx, 204, GrammarParser::RuleOn_tick_handler);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1695);
    type_name();
    setState(1697); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1696);
      space();
      setState(1699); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS);
    setState(1701);
    match(GrammarParser::ON_TICK);
    setState(1705);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1702);
      space();
      setState(1707);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1708);
    match(GrammarParser::OP_PARETHESES);
    setState(1712);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1709);
      space();
      setState(1714);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1722);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::T_VOID) {
      setState(1715);
      match(GrammarParser::T_VOID);
      setState(1719);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1716);
        space();
        setState(1721);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1724);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- On_init_handlerContext ------------------------------------------------------------------

GrammarParser::On_init_handlerContext::On_init_handlerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::On_init_handlerContext::ON_INIT() {
  return getToken(GrammarParser::ON_INIT, 0);
}

tree::TerminalNode* GrammarParser::On_init_handlerContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::On_init_handlerContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::On_init_handlerContext::T_VOID() {
  return getTokens(GrammarParser::T_VOID);
}

tree::TerminalNode* GrammarParser::On_init_handlerContext::T_VOID(size_t i) {
  return getToken(GrammarParser::T_VOID, i);
}

tree::TerminalNode* GrammarParser::On_init_handlerContext::T_INT() {
  return getToken(GrammarParser::T_INT, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::On_init_handlerContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::On_init_handlerContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::On_init_handlerContext::getRuleIndex() const {
  return GrammarParser::RuleOn_init_handler;
}

void GrammarParser::On_init_handlerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOn_init_handler(this);
}

void GrammarParser::On_init_handlerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOn_init_handler(this);
}

GrammarParser::On_init_handlerContext* GrammarParser::on_init_handler() {
  On_init_handlerContext *_localctx = _tracker.createInstance<On_init_handlerContext>(_ctx, getState());
  enterRule(_localctx, 206, GrammarParser::RuleOn_init_handler);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1726);
    _la = _input->LA(1);
    if (!(_la == GrammarParser::T_VOID

    || _la == GrammarParser::T_INT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1728); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1727);
      space();
      setState(1730); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS);
    setState(1732);
    match(GrammarParser::ON_INIT);
    setState(1736);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1733);
      space();
      setState(1738);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1739);
    match(GrammarParser::OP_PARETHESES);
    setState(1743);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1740);
      space();
      setState(1745);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1753);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::T_VOID) {
      setState(1746);
      match(GrammarParser::T_VOID);
      setState(1750);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1747);
        space();
        setState(1752);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1755);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- On_deinit_handlerContext ------------------------------------------------------------------

GrammarParser::On_deinit_handlerContext::On_deinit_handlerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GrammarParser::Type_nameContext* GrammarParser::On_deinit_handlerContext::type_name() {
  return getRuleContext<GrammarParser::Type_nameContext>(0);
}

tree::TerminalNode* GrammarParser::On_deinit_handlerContext::ON_DEINIT() {
  return getToken(GrammarParser::ON_DEINIT, 0);
}

tree::TerminalNode* GrammarParser::On_deinit_handlerContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::On_deinit_handlerContext::K_CONST() {
  return getToken(GrammarParser::K_CONST, 0);
}

tree::TerminalNode* GrammarParser::On_deinit_handlerContext::T_INT() {
  return getToken(GrammarParser::T_INT, 0);
}

tree::TerminalNode* GrammarParser::On_deinit_handlerContext::NAME() {
  return getToken(GrammarParser::NAME, 0);
}

tree::TerminalNode* GrammarParser::On_deinit_handlerContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::On_deinit_handlerContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::On_deinit_handlerContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::On_deinit_handlerContext::getRuleIndex() const {
  return GrammarParser::RuleOn_deinit_handler;
}

void GrammarParser::On_deinit_handlerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOn_deinit_handler(this);
}

void GrammarParser::On_deinit_handlerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOn_deinit_handler(this);
}

GrammarParser::On_deinit_handlerContext* GrammarParser::on_deinit_handler() {
  On_deinit_handlerContext *_localctx = _tracker.createInstance<On_deinit_handlerContext>(_ctx, getState());
  enterRule(_localctx, 208, GrammarParser::RuleOn_deinit_handler);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1757);
    type_name();
    setState(1759); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1758);
      space();
      setState(1761); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS);
    setState(1763);
    match(GrammarParser::ON_DEINIT);
    setState(1767);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1764);
      space();
      setState(1769);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1770);
    match(GrammarParser::OP_PARETHESES);
    setState(1774);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1771);
      space();
      setState(1776);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1777);
    match(GrammarParser::K_CONST);
    setState(1781);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1778);
      space();
      setState(1783);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1784);
    match(GrammarParser::T_INT);
    setState(1788);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1785);
      space();
      setState(1790);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1791);
    match(GrammarParser::NAME);
    setState(1795);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1792);
      space();
      setState(1797);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1798);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- On_timer_handlerContext ------------------------------------------------------------------

GrammarParser::On_timer_handlerContext::On_timer_handlerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::On_timer_handlerContext::ON_TIMER() {
  return getToken(GrammarParser::ON_TIMER, 0);
}

tree::TerminalNode* GrammarParser::On_timer_handlerContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::On_timer_handlerContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::On_timer_handlerContext::T_VOID() {
  return getTokens(GrammarParser::T_VOID);
}

tree::TerminalNode* GrammarParser::On_timer_handlerContext::T_VOID(size_t i) {
  return getToken(GrammarParser::T_VOID, i);
}

tree::TerminalNode* GrammarParser::On_timer_handlerContext::T_INT() {
  return getToken(GrammarParser::T_INT, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::On_timer_handlerContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::On_timer_handlerContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::On_timer_handlerContext::getRuleIndex() const {
  return GrammarParser::RuleOn_timer_handler;
}

void GrammarParser::On_timer_handlerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOn_timer_handler(this);
}

void GrammarParser::On_timer_handlerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOn_timer_handler(this);
}

GrammarParser::On_timer_handlerContext* GrammarParser::on_timer_handler() {
  On_timer_handlerContext *_localctx = _tracker.createInstance<On_timer_handlerContext>(_ctx, getState());
  enterRule(_localctx, 210, GrammarParser::RuleOn_timer_handler);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1800);
    _la = _input->LA(1);
    if (!(_la == GrammarParser::T_VOID

    || _la == GrammarParser::T_INT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1802); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1801);
      space();
      setState(1804); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS);
    setState(1806);
    match(GrammarParser::ON_TIMER);
    setState(1810);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1807);
      space();
      setState(1812);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1813);
    match(GrammarParser::OP_PARETHESES);
    setState(1817);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1814);
      space();
      setState(1819);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1827);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::T_VOID) {
      setState(1820);
      match(GrammarParser::T_VOID);
      setState(1824);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == GrammarParser::NEWLINE

      || _la == GrammarParser::WS) {
        setState(1821);
        space();
        setState(1826);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(1829);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- On_chart_event_handlerContext ------------------------------------------------------------------

GrammarParser::On_chart_event_handlerContext::On_chart_event_handlerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::ON_CHART_EVENT() {
  return getToken(GrammarParser::ON_CHART_EVENT, 0);
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::On_chart_event_handlerContext::K_CONST() {
  return getTokens(GrammarParser::K_CONST);
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::K_CONST(size_t i) {
  return getToken(GrammarParser::K_CONST, i);
}

std::vector<tree::TerminalNode *> GrammarParser::On_chart_event_handlerContext::T_INT() {
  return getTokens(GrammarParser::T_INT);
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::T_INT(size_t i) {
  return getToken(GrammarParser::T_INT, i);
}

std::vector<tree::TerminalNode *> GrammarParser::On_chart_event_handlerContext::NAME() {
  return getTokens(GrammarParser::NAME);
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::NAME(size_t i) {
  return getToken(GrammarParser::NAME, i);
}

std::vector<tree::TerminalNode *> GrammarParser::On_chart_event_handlerContext::COMMA() {
  return getTokens(GrammarParser::COMMA);
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::COMMA(size_t i) {
  return getToken(GrammarParser::COMMA, i);
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::T_LONG() {
  return getToken(GrammarParser::T_LONG, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::On_chart_event_handlerContext::AMPERSAND() {
  return getTokens(GrammarParser::AMPERSAND);
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::AMPERSAND(size_t i) {
  return getToken(GrammarParser::AMPERSAND, i);
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::T_DOUBLE() {
  return getToken(GrammarParser::T_DOUBLE, 0);
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::T_STRING() {
  return getToken(GrammarParser::T_STRING, 0);
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::On_chart_event_handlerContext::T_VOID() {
  return getToken(GrammarParser::T_VOID, 0);
}

std::vector<GrammarParser::SpaceContext *> GrammarParser::On_chart_event_handlerContext::space() {
  return getRuleContexts<GrammarParser::SpaceContext>();
}

GrammarParser::SpaceContext* GrammarParser::On_chart_event_handlerContext::space(size_t i) {
  return getRuleContext<GrammarParser::SpaceContext>(i);
}


size_t GrammarParser::On_chart_event_handlerContext::getRuleIndex() const {
  return GrammarParser::RuleOn_chart_event_handler;
}

void GrammarParser::On_chart_event_handlerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOn_chart_event_handler(this);
}

void GrammarParser::On_chart_event_handlerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOn_chart_event_handler(this);
}

GrammarParser::On_chart_event_handlerContext* GrammarParser::on_chart_event_handler() {
  On_chart_event_handlerContext *_localctx = _tracker.createInstance<On_chart_event_handlerContext>(_ctx, getState());
  enterRule(_localctx, 212, GrammarParser::RuleOn_chart_event_handler);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1831);
    _la = _input->LA(1);
    if (!(_la == GrammarParser::T_VOID

    || _la == GrammarParser::T_INT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(1833); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(1832);
      space();
      setState(1835); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS);
    setState(1837);
    match(GrammarParser::ON_CHART_EVENT);
    setState(1841);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1838);
      space();
      setState(1843);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1844);
    match(GrammarParser::OP_PARETHESES);
    setState(1848);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1845);
      space();
      setState(1850);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1851);
    match(GrammarParser::K_CONST);
    setState(1855);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1852);
      space();
      setState(1857);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1858);
    match(GrammarParser::T_INT);
    setState(1862);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1859);
      space();
      setState(1864);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1865);
    match(GrammarParser::NAME);
    setState(1869);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1866);
      space();
      setState(1871);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1872);
    match(GrammarParser::COMMA);
    setState(1876);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1873);
      space();
      setState(1878);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1879);
    match(GrammarParser::K_CONST);
    setState(1883);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1880);
      space();
      setState(1885);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1886);
    match(GrammarParser::T_LONG);
    setState(1890);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1887);
      space();
      setState(1892);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1893);
    match(GrammarParser::AMPERSAND);
    setState(1897);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1894);
      space();
      setState(1899);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1900);
    match(GrammarParser::NAME);
    setState(1904);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1901);
      space();
      setState(1906);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1907);
    match(GrammarParser::COMMA);
    setState(1911);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1908);
      space();
      setState(1913);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1914);
    match(GrammarParser::K_CONST);
    setState(1918);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1915);
      space();
      setState(1920);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1921);
    match(GrammarParser::T_DOUBLE);
    setState(1925);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1922);
      space();
      setState(1927);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1928);
    match(GrammarParser::AMPERSAND);
    setState(1932);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1929);
      space();
      setState(1934);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1935);
    match(GrammarParser::NAME);
    setState(1939);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1936);
      space();
      setState(1941);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1942);
    match(GrammarParser::COMMA);
    setState(1946);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1943);
      space();
      setState(1948);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1949);
    match(GrammarParser::K_CONST);
    setState(1953);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1950);
      space();
      setState(1955);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1956);
    match(GrammarParser::T_STRING);
    setState(1960);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1957);
      space();
      setState(1962);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1963);
    match(GrammarParser::AMPERSAND);
    setState(1967);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1964);
      space();
      setState(1969);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1970);
    match(GrammarParser::NAME);
    setState(1974);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS) {
      setState(1971);
      space();
      setState(1976);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(1977);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

GrammarParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::NameContext::NAME() {
  return getToken(GrammarParser::NAME, 0);
}

tree::TerminalNode* GrammarParser::NameContext::DEINIT() {
  return getToken(GrammarParser::DEINIT, 0);
}

tree::TerminalNode* GrammarParser::NameContext::START() {
  return getToken(GrammarParser::START, 0);
}

tree::TerminalNode* GrammarParser::NameContext::INIT() {
  return getToken(GrammarParser::INIT, 0);
}

tree::TerminalNode* GrammarParser::NameContext::ON_CALCULATE() {
  return getToken(GrammarParser::ON_CALCULATE, 0);
}

tree::TerminalNode* GrammarParser::NameContext::ON_TICK() {
  return getToken(GrammarParser::ON_TICK, 0);
}

tree::TerminalNode* GrammarParser::NameContext::ON_INIT() {
  return getToken(GrammarParser::ON_INIT, 0);
}

tree::TerminalNode* GrammarParser::NameContext::ON_DEINIT() {
  return getToken(GrammarParser::ON_DEINIT, 0);
}

tree::TerminalNode* GrammarParser::NameContext::ON_TIMER() {
  return getToken(GrammarParser::ON_TIMER, 0);
}

tree::TerminalNode* GrammarParser::NameContext::INDEX_BUFFER_TYPE() {
  return getToken(GrammarParser::INDEX_BUFFER_TYPE, 0);
}

tree::TerminalNode* GrammarParser::NameContext::ALERT() {
  return getToken(GrammarParser::ALERT, 0);
}

tree::TerminalNode* GrammarParser::NameContext::GET_LAST_ERROR() {
  return getToken(GrammarParser::GET_LAST_ERROR, 0);
}

tree::TerminalNode* GrammarParser::NameContext::PLAY_SOUND() {
  return getToken(GrammarParser::PLAY_SOUND, 0);
}

tree::TerminalNode* GrammarParser::NameContext::STRATEGY_ONLY() {
  return getToken(GrammarParser::STRATEGY_ONLY, 0);
}

tree::TerminalNode* GrammarParser::NameContext::HOOKING_FUNCS() {
  return getToken(GrammarParser::HOOKING_FUNCS, 0);
}

tree::TerminalNode* GrammarParser::NameContext::INDICATORS_ONLY() {
  return getToken(GrammarParser::INDICATORS_ONLY, 0);
}


size_t GrammarParser::NameContext::getRuleIndex() const {
  return GrammarParser::RuleName;
}

void GrammarParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void GrammarParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}

GrammarParser::NameContext* GrammarParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 214, GrammarParser::RuleName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1979);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE))) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 76)) & ((1ULL << (GrammarParser::ALERT - 76))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 76))
      | (1ULL << (GrammarParser::PLAY_SOUND - 76))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 76))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 76))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 76))
      | (1ULL << (GrammarParser::NAME - 76)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SpaceContext ------------------------------------------------------------------

GrammarParser::SpaceContext::SpaceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::SpaceContext::WS() {
  return getToken(GrammarParser::WS, 0);
}

tree::TerminalNode* GrammarParser::SpaceContext::NEWLINE() {
  return getToken(GrammarParser::NEWLINE, 0);
}


size_t GrammarParser::SpaceContext::getRuleIndex() const {
  return GrammarParser::RuleSpace;
}

void GrammarParser::SpaceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSpace(this);
}

void GrammarParser::SpaceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSpace(this);
}

GrammarParser::SpaceContext* GrammarParser::space() {
  SpaceContext *_localctx = _tracker.createInstance<SpaceContext>(_ctx, getState());
  enterRule(_localctx, 216, GrammarParser::RuleSpace);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1981);
    _la = _input->LA(1);
    if (!(_la == GrammarParser::NEWLINE

    || _la == GrammarParser::WS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerContext ------------------------------------------------------------------

GrammarParser::IntegerContext::IntegerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::IntegerContext::INTEGER() {
  return getToken(GrammarParser::INTEGER, 0);
}

tree::TerminalNode* GrammarParser::IntegerContext::MINUS() {
  return getToken(GrammarParser::MINUS, 0);
}

tree::TerminalNode* GrammarParser::IntegerContext::PLUS() {
  return getToken(GrammarParser::PLUS, 0);
}


size_t GrammarParser::IntegerContext::getRuleIndex() const {
  return GrammarParser::RuleInteger;
}

void GrammarParser::IntegerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger(this);
}

void GrammarParser::IntegerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger(this);
}

GrammarParser::IntegerContext* GrammarParser::integer() {
  IntegerContext *_localctx = _tracker.createInstance<IntegerContext>(_ctx, getState());
  enterRule(_localctx, 218, GrammarParser::RuleInteger);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1984);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GrammarParser::PLUS

    || _la == GrammarParser::MINUS) {
      setState(1983);
      _la = _input->LA(1);
      if (!(_la == GrammarParser::PLUS

      || _la == GrammarParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(1986);
    match(GrammarParser::INTEGER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Float_valueContext ------------------------------------------------------------------

GrammarParser::Float_valueContext::Float_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Float_valueContext::FLOATING_LITERAL() {
  return getToken(GrammarParser::FLOATING_LITERAL, 0);
}


size_t GrammarParser::Float_valueContext::getRuleIndex() const {
  return GrammarParser::RuleFloat_value;
}

void GrammarParser::Float_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloat_value(this);
}

void GrammarParser::Float_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloat_value(this);
}

GrammarParser::Float_valueContext* GrammarParser::float_value() {
  Float_valueContext *_localctx = _tracker.createInstance<Float_valueContext>(_ctx, getState());
  enterRule(_localctx, 220, GrammarParser::RuleFloat_value);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1988);
    match(GrammarParser::FLOATING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tryblock_replacement_startContext ------------------------------------------------------------------

GrammarParser::Tryblock_replacement_startContext::Tryblock_replacement_startContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Tryblock_replacement_startContext::BD_SLASH() {
  return getToken(GrammarParser::BD_SLASH, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::Tryblock_replacement_startContext::TRY_BLOCK_DASH() {
  return getTokens(GrammarParser::TRY_BLOCK_DASH);
}

tree::TerminalNode* GrammarParser::Tryblock_replacement_startContext::TRY_BLOCK_DASH(size_t i) {
  return getToken(GrammarParser::TRY_BLOCK_DASH, i);
}

tree::TerminalNode* GrammarParser::Tryblock_replacement_startContext::TRY_BLOCK_START() {
  return getToken(GrammarParser::TRY_BLOCK_START, 0);
}

tree::TerminalNode* GrammarParser::Tryblock_replacement_startContext::NAME() {
  return getToken(GrammarParser::NAME, 0);
}


size_t GrammarParser::Tryblock_replacement_startContext::getRuleIndex() const {
  return GrammarParser::RuleTryblock_replacement_start;
}

void GrammarParser::Tryblock_replacement_startContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTryblock_replacement_start(this);
}

void GrammarParser::Tryblock_replacement_startContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTryblock_replacement_start(this);
}

GrammarParser::Tryblock_replacement_startContext* GrammarParser::tryblock_replacement_start() {
  Tryblock_replacement_startContext *_localctx = _tracker.createInstance<Tryblock_replacement_startContext>(_ctx, getState());
  enterRule(_localctx, 222, GrammarParser::RuleTryblock_replacement_start);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1990);
    match(GrammarParser::BD_SLASH);
    setState(1991);
    match(GrammarParser::TRY_BLOCK_DASH);
    setState(1992);
    match(GrammarParser::TRY_BLOCK_START);
    setState(1993);
    match(GrammarParser::NAME);
    setState(1994);
    match(GrammarParser::TRY_BLOCK_DASH);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Tryblock_replacement_endContext ------------------------------------------------------------------

GrammarParser::Tryblock_replacement_endContext::Tryblock_replacement_endContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Tryblock_replacement_endContext::BD_SLASH() {
  return getToken(GrammarParser::BD_SLASH, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::Tryblock_replacement_endContext::TRY_BLOCK_DASH() {
  return getTokens(GrammarParser::TRY_BLOCK_DASH);
}

tree::TerminalNode* GrammarParser::Tryblock_replacement_endContext::TRY_BLOCK_DASH(size_t i) {
  return getToken(GrammarParser::TRY_BLOCK_DASH, i);
}

tree::TerminalNode* GrammarParser::Tryblock_replacement_endContext::TRY_BLOCK_END() {
  return getToken(GrammarParser::TRY_BLOCK_END, 0);
}

tree::TerminalNode* GrammarParser::Tryblock_replacement_endContext::NAME() {
  return getToken(GrammarParser::NAME, 0);
}


size_t GrammarParser::Tryblock_replacement_endContext::getRuleIndex() const {
  return GrammarParser::RuleTryblock_replacement_end;
}

void GrammarParser::Tryblock_replacement_endContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTryblock_replacement_end(this);
}

void GrammarParser::Tryblock_replacement_endContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTryblock_replacement_end(this);
}

GrammarParser::Tryblock_replacement_endContext* GrammarParser::tryblock_replacement_end() {
  Tryblock_replacement_endContext *_localctx = _tracker.createInstance<Tryblock_replacement_endContext>(_ctx, getState());
  enterRule(_localctx, 224, GrammarParser::RuleTryblock_replacement_end);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(1996);
    match(GrammarParser::BD_SLASH);
    setState(1997);
    match(GrammarParser::TRY_BLOCK_DASH);
    setState(1998);
    match(GrammarParser::TRY_BLOCK_END);
    setState(1999);
    match(GrammarParser::NAME);
    setState(2000);
    match(GrammarParser::TRY_BLOCK_DASH);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parantheses_expressionContext ------------------------------------------------------------------

GrammarParser::Parantheses_expressionContext::Parantheses_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::Parantheses_expressionContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

std::vector<tree::TerminalNode *> GrammarParser::Parantheses_expressionContext::CL_PARETHESES() {
  return getTokens(GrammarParser::CL_PARETHESES);
}

tree::TerminalNode* GrammarParser::Parantheses_expressionContext::CL_PARETHESES(size_t i) {
  return getToken(GrammarParser::CL_PARETHESES, i);
}

GrammarParser::Parantheses_expressionContext* GrammarParser::Parantheses_expressionContext::parantheses_expression() {
  return getRuleContext<GrammarParser::Parantheses_expressionContext>(0);
}

std::vector<tree::TerminalNode *> GrammarParser::Parantheses_expressionContext::EOF() {
  return getTokens(GrammarParser::EOF);
}

tree::TerminalNode* GrammarParser::Parantheses_expressionContext::EOF(size_t i) {
  return getToken(GrammarParser::EOF, i);
}


size_t GrammarParser::Parantheses_expressionContext::getRuleIndex() const {
  return GrammarParser::RuleParantheses_expression;
}

void GrammarParser::Parantheses_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParantheses_expression(this);
}

void GrammarParser::Parantheses_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParantheses_expression(this);
}

GrammarParser::Parantheses_expressionContext* GrammarParser::parantheses_expression() {
  Parantheses_expressionContext *_localctx = _tracker.createInstance<Parantheses_expressionContext>(_ctx, getState());
  enterRule(_localctx, 226, GrammarParser::RuleParantheses_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2002);
    match(GrammarParser::OP_PARETHESES);
    setState(2009);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 262, _ctx)) {
    case 1: {
      setState(2004); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(2003);
        _la = _input->LA(1);
        if (_la == 0 || _la == Token::EOF || (_la == GrammarParser::EOF

        || _la == GrammarParser::CL_PARETHESES)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(2006); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
        | (1ULL << GrammarParser::COMMA)
        | (1ULL << GrammarParser::DOT)
        | (1ULL << GrammarParser::OP_BR)
        | (1ULL << GrammarParser::CL_BR)
        | (1ULL << GrammarParser::OP_PARETHESES)
        | (1ULL << GrammarParser::OP_CRL_BR)
        | (1ULL << GrammarParser::CL_CRL_BR)
        | (1ULL << GrammarParser::COLON)
        | (1ULL << GrammarParser::SC)
        | (1ULL << GrammarParser::D_QUOTE)
        | (1ULL << GrammarParser::S_QUOTE)
        | (1ULL << GrammarParser::EQ)
        | (1ULL << GrammarParser::COMPARISSON)
        | (1ULL << GrammarParser::COMPARISSON_NOT)
        | (1ULL << GrammarParser::MORE_OR_EQUAL)
        | (1ULL << GrammarParser::LESS_OR_EQUAL)
        | (1ULL << GrammarParser::INCREMENT)
        | (1ULL << GrammarParser::DECREMENT)
        | (1ULL << GrammarParser::PLUS)
        | (1ULL << GrammarParser::MINUS)
        | (1ULL << GrammarParser::ASTRISK)
        | (1ULL << GrammarParser::SLASH)
        | (1ULL << GrammarParser::AMPERSAND)
        | (1ULL << GrammarParser::NEWLINE)
        | (1ULL << GrammarParser::BD_SLASH)
        | (1ULL << GrammarParser::OP_COMMENT)
        | (1ULL << GrammarParser::CL_COMMENT)
        | (1ULL << GrammarParser::MULTILINE_COMMENT)
        | (1ULL << GrammarParser::ONELINE_COMMENT)
        | (1ULL << GrammarParser::WS)
        | (1ULL << GrammarParser::DEINIT)
        | (1ULL << GrammarParser::INIT)
        | (1ULL << GrammarParser::START)
        | (1ULL << GrammarParser::ON_CALCULATE)
        | (1ULL << GrammarParser::ON_TICK)
        | (1ULL << GrammarParser::ON_INIT)
        | (1ULL << GrammarParser::ON_DEINIT)
        | (1ULL << GrammarParser::ON_TIMER)
        | (1ULL << GrammarParser::ON_CHART_EVENT)
        | (1ULL << GrammarParser::TRY_BLOCK_DASH)
        | (1ULL << GrammarParser::TRY_BLOCK_START)
        | (1ULL << GrammarParser::TRY_BLOCK_END)
        | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
        | (1ULL << GrammarParser::EXTERN)
        | (1ULL << GrammarParser::INPUT)
        | (1ULL << GrammarParser::SINPUT)
        | (1ULL << GrammarParser::K_STATIC)
        | (1ULL << GrammarParser::K_STRICT)
        | (1ULL << GrammarParser::K_NULL)
        | (1ULL << GrammarParser::K_CONST)
        | (1ULL << GrammarParser::K_UNSIGNED)
        | (1ULL << GrammarParser::K_ENUM)
        | (1ULL << GrammarParser::K_ELSE)
        | (1ULL << GrammarParser::K_SWITCH)
        | (1ULL << GrammarParser::K_CASE)
        | (1ULL << GrammarParser::K_RETURN)
        | (1ULL << GrammarParser::K_FOR)
        | (1ULL << GrammarParser::K_IF)
        | (1ULL << GrammarParser::T_DOUBLE)
        | (1ULL << GrammarParser::T_FLOAT)
        | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
        | (1ULL << (GrammarParser::T_BOOL - 64))
        | (1ULL << (GrammarParser::T_LONG - 64))
        | (1ULL << (GrammarParser::T_SHORT - 64))
        | (1ULL << (GrammarParser::T_CHAR - 64))
        | (1ULL << (GrammarParser::T_STRING - 64))
        | (1ULL << (GrammarParser::T_COLOR - 64))
        | (1ULL << (GrammarParser::T_ULONG - 64))
        | (1ULL << (GrammarParser::T_DATETIME - 64))
        | (1ULL << (GrammarParser::PROPERTY - 64))
        | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
        | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
        | (1ULL << (GrammarParser::ALERT - 64))
        | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
        | (1ULL << (GrammarParser::PLAY_SOUND - 64))
        | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
        | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
        | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
        | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
        | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
        | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
        | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
        | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
        | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
        | (1ULL << (GrammarParser::TIME_CURRENT - 64))
        | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
        | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
        | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
        | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
        | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
        | (1ULL << (GrammarParser::IMA_MODE - 64))
        | (1ULL << (GrammarParser::PRICE_TYPE - 64))
        | (1ULL << (GrammarParser::TIMEFRAME - 64))
        | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
        | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
        | (1ULL << (GrammarParser::REGULAR_STRING - 64))
        | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
        | (1ULL << (GrammarParser::NAME - 64))
        | (1ULL << (GrammarParser::INTEGER - 64))
        | (1ULL << (GrammarParser::HEX_INTEGER - 64))
        | (1ULL << (GrammarParser::DATE_LITERAL - 64))
        | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
        | (1ULL << (GrammarParser::LETTER - 64))
        | (1ULL << (GrammarParser::DIGIT - 64))
        | (1ULL << (GrammarParser::ANY - 64))
        | (1ULL << (GrammarParser::MANY - 64)))) != 0));
      break;
    }

    case 2: {
      setState(2008);
      parantheses_expression();
      break;
    }

    }
    setState(2011);
    match(GrammarParser::CL_PARETHESES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ml_contentContext ------------------------------------------------------------------

GrammarParser::Ml_contentContext::Ml_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GrammarParser::Ml_contentContext::CL_COMMENT() {
  return getTokens(GrammarParser::CL_COMMENT);
}

tree::TerminalNode* GrammarParser::Ml_contentContext::CL_COMMENT(size_t i) {
  return getToken(GrammarParser::CL_COMMENT, i);
}


size_t GrammarParser::Ml_contentContext::getRuleIndex() const {
  return GrammarParser::RuleMl_content;
}

void GrammarParser::Ml_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMl_content(this);
}

void GrammarParser::Ml_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMl_content(this);
}

GrammarParser::Ml_contentContext* GrammarParser::ml_content() {
  Ml_contentContext *_localctx = _tracker.createInstance<Ml_contentContext>(_ctx, getState());
  enterRule(_localctx, 228, GrammarParser::RuleMl_content);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2014); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(2013);
      _la = _input->LA(1);
      if (_la == 0 || _la == Token::EOF || (_la == GrammarParser::CL_COMMENT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(2016); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
      | (1ULL << GrammarParser::COMMA)
      | (1ULL << GrammarParser::DOT)
      | (1ULL << GrammarParser::OP_BR)
      | (1ULL << GrammarParser::CL_BR)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::CL_PARETHESES)
      | (1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::CL_CRL_BR)
      | (1ULL << GrammarParser::COLON)
      | (1ULL << GrammarParser::SC)
      | (1ULL << GrammarParser::D_QUOTE)
      | (1ULL << GrammarParser::S_QUOTE)
      | (1ULL << GrammarParser::EQ)
      | (1ULL << GrammarParser::COMPARISSON)
      | (1ULL << GrammarParser::COMPARISSON_NOT)
      | (1ULL << GrammarParser::MORE_OR_EQUAL)
      | (1ULL << GrammarParser::LESS_OR_EQUAL)
      | (1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH)
      | (1ULL << GrammarParser::AMPERSAND)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::BD_SLASH)
      | (1ULL << GrammarParser::OP_COMMENT)
      | (1ULL << GrammarParser::MULTILINE_COMMENT)
      | (1ULL << GrammarParser::ONELINE_COMMENT)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::ON_CHART_EVENT)
      | (1ULL << GrammarParser::TRY_BLOCK_DASH)
      | (1ULL << GrammarParser::TRY_BLOCK_START)
      | (1ULL << GrammarParser::TRY_BLOCK_END)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC)
      | (1ULL << GrammarParser::K_STRICT)
      | (1ULL << GrammarParser::K_NULL)
      | (1ULL << GrammarParser::K_CONST)
      | (1ULL << GrammarParser::K_UNSIGNED)
      | (1ULL << GrammarParser::K_ENUM)
      | (1ULL << GrammarParser::K_ELSE)
      | (1ULL << GrammarParser::K_SWITCH)
      | (1ULL << GrammarParser::K_CASE)
      | (1ULL << GrammarParser::K_RETURN)
      | (1ULL << GrammarParser::K_FOR)
      | (1ULL << GrammarParser::K_IF)
      | (1ULL << GrammarParser::T_DOUBLE)
      | (1ULL << GrammarParser::T_FLOAT)
      | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
      | (1ULL << (GrammarParser::T_BOOL - 64))
      | (1ULL << (GrammarParser::T_LONG - 64))
      | (1ULL << (GrammarParser::T_SHORT - 64))
      | (1ULL << (GrammarParser::T_CHAR - 64))
      | (1ULL << (GrammarParser::T_STRING - 64))
      | (1ULL << (GrammarParser::T_COLOR - 64))
      | (1ULL << (GrammarParser::T_ULONG - 64))
      | (1ULL << (GrammarParser::T_DATETIME - 64))
      | (1ULL << (GrammarParser::PROPERTY - 64))
      | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
      | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
      | (1ULL << (GrammarParser::ALERT - 64))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
      | (1ULL << (GrammarParser::PLAY_SOUND - 64))
      | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
      | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
      | (1ULL << (GrammarParser::TIME_CURRENT - 64))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
      | (1ULL << (GrammarParser::IMA_MODE - 64))
      | (1ULL << (GrammarParser::PRICE_TYPE - 64))
      | (1ULL << (GrammarParser::TIMEFRAME - 64))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
      | (1ULL << (GrammarParser::REGULAR_STRING - 64))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
      | (1ULL << (GrammarParser::NAME - 64))
      | (1ULL << (GrammarParser::INTEGER - 64))
      | (1ULL << (GrammarParser::HEX_INTEGER - 64))
      | (1ULL << (GrammarParser::DATE_LITERAL - 64))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
      | (1ULL << (GrammarParser::LETTER - 64))
      | (1ULL << (GrammarParser::DIGIT - 64))
      | (1ULL << (GrammarParser::ANY - 64))
      | (1ULL << (GrammarParser::MANY - 64)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Ol_contentContext ------------------------------------------------------------------

GrammarParser::Ol_contentContext::Ol_contentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GrammarParser::Ol_contentContext::NEWLINE() {
  return getTokens(GrammarParser::NEWLINE);
}

tree::TerminalNode* GrammarParser::Ol_contentContext::NEWLINE(size_t i) {
  return getToken(GrammarParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> GrammarParser::Ol_contentContext::EOF() {
  return getTokens(GrammarParser::EOF);
}

tree::TerminalNode* GrammarParser::Ol_contentContext::EOF(size_t i) {
  return getToken(GrammarParser::EOF, i);
}


size_t GrammarParser::Ol_contentContext::getRuleIndex() const {
  return GrammarParser::RuleOl_content;
}

void GrammarParser::Ol_contentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOl_content(this);
}

void GrammarParser::Ol_contentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOl_content(this);
}

GrammarParser::Ol_contentContext* GrammarParser::ol_content() {
  Ol_contentContext *_localctx = _tracker.createInstance<Ol_contentContext>(_ctx, getState());
  enterRule(_localctx, 230, GrammarParser::RuleOl_content);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(2019); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(2018);
              _la = _input->LA(1);
              if (_la == 0 || _la == Token::EOF || (_la == GrammarParser::EOF

              || _la == GrammarParser::NEWLINE)) {
              _errHandler->recoverInline(this);
              }
              else {
                _errHandler->reportMatch(this);
                consume();
              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(2021); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 264, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- No_cl_parenthesesContext ------------------------------------------------------------------

GrammarParser::No_cl_parenthesesContext::No_cl_parenthesesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GrammarParser::No_cl_parenthesesContext::CL_PARETHESES() {
  return getTokens(GrammarParser::CL_PARETHESES);
}

tree::TerminalNode* GrammarParser::No_cl_parenthesesContext::CL_PARETHESES(size_t i) {
  return getToken(GrammarParser::CL_PARETHESES, i);
}

std::vector<tree::TerminalNode *> GrammarParser::No_cl_parenthesesContext::SC() {
  return getTokens(GrammarParser::SC);
}

tree::TerminalNode* GrammarParser::No_cl_parenthesesContext::SC(size_t i) {
  return getToken(GrammarParser::SC, i);
}

std::vector<tree::TerminalNode *> GrammarParser::No_cl_parenthesesContext::EOF() {
  return getTokens(GrammarParser::EOF);
}

tree::TerminalNode* GrammarParser::No_cl_parenthesesContext::EOF(size_t i) {
  return getToken(GrammarParser::EOF, i);
}


size_t GrammarParser::No_cl_parenthesesContext::getRuleIndex() const {
  return GrammarParser::RuleNo_cl_parentheses;
}

void GrammarParser::No_cl_parenthesesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNo_cl_parentheses(this);
}

void GrammarParser::No_cl_parenthesesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNo_cl_parentheses(this);
}

GrammarParser::No_cl_parenthesesContext* GrammarParser::no_cl_parentheses() {
  No_cl_parenthesesContext *_localctx = _tracker.createInstance<No_cl_parenthesesContext>(_ctx, getState());
  enterRule(_localctx, 232, GrammarParser::RuleNo_cl_parentheses);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2024); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(2023);
      _la = _input->LA(1);
      if (_la == 0 || _la == Token::EOF || (((((_la - -1) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - -1)) & ((1ULL << (GrammarParser::EOF - -1))
        | (1ULL << (GrammarParser::CL_PARETHESES - -1))
        | (1ULL << (GrammarParser::SC - -1)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(2026); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
      | (1ULL << GrammarParser::COMMA)
      | (1ULL << GrammarParser::DOT)
      | (1ULL << GrammarParser::OP_BR)
      | (1ULL << GrammarParser::CL_BR)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::CL_CRL_BR)
      | (1ULL << GrammarParser::COLON)
      | (1ULL << GrammarParser::D_QUOTE)
      | (1ULL << GrammarParser::S_QUOTE)
      | (1ULL << GrammarParser::EQ)
      | (1ULL << GrammarParser::COMPARISSON)
      | (1ULL << GrammarParser::COMPARISSON_NOT)
      | (1ULL << GrammarParser::MORE_OR_EQUAL)
      | (1ULL << GrammarParser::LESS_OR_EQUAL)
      | (1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH)
      | (1ULL << GrammarParser::AMPERSAND)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::BD_SLASH)
      | (1ULL << GrammarParser::OP_COMMENT)
      | (1ULL << GrammarParser::CL_COMMENT)
      | (1ULL << GrammarParser::MULTILINE_COMMENT)
      | (1ULL << GrammarParser::ONELINE_COMMENT)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::ON_CHART_EVENT)
      | (1ULL << GrammarParser::TRY_BLOCK_DASH)
      | (1ULL << GrammarParser::TRY_BLOCK_START)
      | (1ULL << GrammarParser::TRY_BLOCK_END)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC)
      | (1ULL << GrammarParser::K_STRICT)
      | (1ULL << GrammarParser::K_NULL)
      | (1ULL << GrammarParser::K_CONST)
      | (1ULL << GrammarParser::K_UNSIGNED)
      | (1ULL << GrammarParser::K_ENUM)
      | (1ULL << GrammarParser::K_ELSE)
      | (1ULL << GrammarParser::K_SWITCH)
      | (1ULL << GrammarParser::K_CASE)
      | (1ULL << GrammarParser::K_RETURN)
      | (1ULL << GrammarParser::K_FOR)
      | (1ULL << GrammarParser::K_IF)
      | (1ULL << GrammarParser::T_DOUBLE)
      | (1ULL << GrammarParser::T_FLOAT)
      | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
      | (1ULL << (GrammarParser::T_BOOL - 64))
      | (1ULL << (GrammarParser::T_LONG - 64))
      | (1ULL << (GrammarParser::T_SHORT - 64))
      | (1ULL << (GrammarParser::T_CHAR - 64))
      | (1ULL << (GrammarParser::T_STRING - 64))
      | (1ULL << (GrammarParser::T_COLOR - 64))
      | (1ULL << (GrammarParser::T_ULONG - 64))
      | (1ULL << (GrammarParser::T_DATETIME - 64))
      | (1ULL << (GrammarParser::PROPERTY - 64))
      | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
      | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
      | (1ULL << (GrammarParser::ALERT - 64))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
      | (1ULL << (GrammarParser::PLAY_SOUND - 64))
      | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
      | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
      | (1ULL << (GrammarParser::TIME_CURRENT - 64))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
      | (1ULL << (GrammarParser::IMA_MODE - 64))
      | (1ULL << (GrammarParser::PRICE_TYPE - 64))
      | (1ULL << (GrammarParser::TIMEFRAME - 64))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
      | (1ULL << (GrammarParser::REGULAR_STRING - 64))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
      | (1ULL << (GrammarParser::NAME - 64))
      | (1ULL << (GrammarParser::INTEGER - 64))
      | (1ULL << (GrammarParser::HEX_INTEGER - 64))
      | (1ULL << (GrammarParser::DATE_LITERAL - 64))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
      | (1ULL << (GrammarParser::LETTER - 64))
      | (1ULL << (GrammarParser::DIGIT - 64))
      | (1ULL << (GrammarParser::ANY - 64))
      | (1ULL << (GrammarParser::MANY - 64)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- No_semicolonContext ------------------------------------------------------------------

GrammarParser::No_semicolonContext::No_semicolonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GrammarParser::No_semicolonContext::SC() {
  return getTokens(GrammarParser::SC);
}

tree::TerminalNode* GrammarParser::No_semicolonContext::SC(size_t i) {
  return getToken(GrammarParser::SC, i);
}

std::vector<tree::TerminalNode *> GrammarParser::No_semicolonContext::EOF() {
  return getTokens(GrammarParser::EOF);
}

tree::TerminalNode* GrammarParser::No_semicolonContext::EOF(size_t i) {
  return getToken(GrammarParser::EOF, i);
}


size_t GrammarParser::No_semicolonContext::getRuleIndex() const {
  return GrammarParser::RuleNo_semicolon;
}

void GrammarParser::No_semicolonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNo_semicolon(this);
}

void GrammarParser::No_semicolonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNo_semicolon(this);
}

GrammarParser::No_semicolonContext* GrammarParser::no_semicolon() {
  No_semicolonContext *_localctx = _tracker.createInstance<No_semicolonContext>(_ctx, getState());
  enterRule(_localctx, 234, GrammarParser::RuleNo_semicolon);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2029); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(2028);
      _la = _input->LA(1);
      if (_la == 0 || _la == Token::EOF || (_la == GrammarParser::EOF

      || _la == GrammarParser::SC)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(2031); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GrammarParser::HASH)
      | (1ULL << GrammarParser::COMMA)
      | (1ULL << GrammarParser::DOT)
      | (1ULL << GrammarParser::OP_BR)
      | (1ULL << GrammarParser::CL_BR)
      | (1ULL << GrammarParser::OP_PARETHESES)
      | (1ULL << GrammarParser::CL_PARETHESES)
      | (1ULL << GrammarParser::OP_CRL_BR)
      | (1ULL << GrammarParser::CL_CRL_BR)
      | (1ULL << GrammarParser::COLON)
      | (1ULL << GrammarParser::D_QUOTE)
      | (1ULL << GrammarParser::S_QUOTE)
      | (1ULL << GrammarParser::EQ)
      | (1ULL << GrammarParser::COMPARISSON)
      | (1ULL << GrammarParser::COMPARISSON_NOT)
      | (1ULL << GrammarParser::MORE_OR_EQUAL)
      | (1ULL << GrammarParser::LESS_OR_EQUAL)
      | (1ULL << GrammarParser::INCREMENT)
      | (1ULL << GrammarParser::DECREMENT)
      | (1ULL << GrammarParser::PLUS)
      | (1ULL << GrammarParser::MINUS)
      | (1ULL << GrammarParser::ASTRISK)
      | (1ULL << GrammarParser::SLASH)
      | (1ULL << GrammarParser::AMPERSAND)
      | (1ULL << GrammarParser::NEWLINE)
      | (1ULL << GrammarParser::BD_SLASH)
      | (1ULL << GrammarParser::OP_COMMENT)
      | (1ULL << GrammarParser::CL_COMMENT)
      | (1ULL << GrammarParser::MULTILINE_COMMENT)
      | (1ULL << GrammarParser::ONELINE_COMMENT)
      | (1ULL << GrammarParser::WS)
      | (1ULL << GrammarParser::DEINIT)
      | (1ULL << GrammarParser::INIT)
      | (1ULL << GrammarParser::START)
      | (1ULL << GrammarParser::ON_CALCULATE)
      | (1ULL << GrammarParser::ON_TICK)
      | (1ULL << GrammarParser::ON_INIT)
      | (1ULL << GrammarParser::ON_DEINIT)
      | (1ULL << GrammarParser::ON_TIMER)
      | (1ULL << GrammarParser::ON_CHART_EVENT)
      | (1ULL << GrammarParser::TRY_BLOCK_DASH)
      | (1ULL << GrammarParser::TRY_BLOCK_START)
      | (1ULL << GrammarParser::TRY_BLOCK_END)
      | (1ULL << GrammarParser::INDEX_BUFFER_TYPE)
      | (1ULL << GrammarParser::EXTERN)
      | (1ULL << GrammarParser::INPUT)
      | (1ULL << GrammarParser::SINPUT)
      | (1ULL << GrammarParser::K_STATIC)
      | (1ULL << GrammarParser::K_STRICT)
      | (1ULL << GrammarParser::K_NULL)
      | (1ULL << GrammarParser::K_CONST)
      | (1ULL << GrammarParser::K_UNSIGNED)
      | (1ULL << GrammarParser::K_ENUM)
      | (1ULL << GrammarParser::K_ELSE)
      | (1ULL << GrammarParser::K_SWITCH)
      | (1ULL << GrammarParser::K_CASE)
      | (1ULL << GrammarParser::K_RETURN)
      | (1ULL << GrammarParser::K_FOR)
      | (1ULL << GrammarParser::K_IF)
      | (1ULL << GrammarParser::T_DOUBLE)
      | (1ULL << GrammarParser::T_FLOAT)
      | (1ULL << GrammarParser::T_VOID))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GrammarParser::T_INT - 64))
      | (1ULL << (GrammarParser::T_BOOL - 64))
      | (1ULL << (GrammarParser::T_LONG - 64))
      | (1ULL << (GrammarParser::T_SHORT - 64))
      | (1ULL << (GrammarParser::T_CHAR - 64))
      | (1ULL << (GrammarParser::T_STRING - 64))
      | (1ULL << (GrammarParser::T_COLOR - 64))
      | (1ULL << (GrammarParser::T_ULONG - 64))
      | (1ULL << (GrammarParser::T_DATETIME - 64))
      | (1ULL << (GrammarParser::PROPERTY - 64))
      | (1ULL << (GrammarParser::INDICATOR_SEPARATE_WINDOW - 64))
      | (1ULL << (GrammarParser::INDICATOR_CHART_WINDOW - 64))
      | (1ULL << (GrammarParser::ALERT - 64))
      | (1ULL << (GrammarParser::GET_LAST_ERROR - 64))
      | (1ULL << (GrammarParser::PLAY_SOUND - 64))
      | (1ULL << (GrammarParser::ADD_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::CHANGE_BRACKETS_FUNCTIONS - 64))
      | (1ULL << (GrammarParser::SET_INDEX_BUFFER - 64))
      | (1ULL << (GrammarParser::SET_LEVEL_STYLE - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS - 64))
      | (1ULL << (GrammarParser::INDICATOR_BUFFERS_FUNC - 64))
      | (1ULL << (GrammarParser::INDICATORS_ONLY - 64))
      | (1ULL << (GrammarParser::STRATEGY_ONLY - 64))
      | (1ULL << (GrammarParser::HOOKING_FUNCS - 64))
      | (1ULL << (GrammarParser::TIME_CURRENT - 64))
      | (1ULL << (GrammarParser::ORDER_OPEN_TIME - 64))
      | (1ULL << (GrammarParser::ORDER_CLOSE_TIME - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_OBJECTS - 64))
      | (1ULL << (GrammarParser::UNSUPPORTED_PROPERTIES - 64))
      | (1ULL << (GrammarParser::INDICATOR_LINE_IDENTIFIER_MODE - 64))
      | (1ULL << (GrammarParser::IMA_MODE - 64))
      | (1ULL << (GrammarParser::PRICE_TYPE - 64))
      | (1ULL << (GrammarParser::TIMEFRAME - 64))
      | (1ULL << (GrammarParser::DT_LITTERAL_ST - 64))
      | (1ULL << (GrammarParser::CLR_LITTERAL - 64))
      | (1ULL << (GrammarParser::REGULAR_STRING - 64))
      | (1ULL << (GrammarParser::CHAR_LITTERAL - 64))
      | (1ULL << (GrammarParser::NAME - 64))
      | (1ULL << (GrammarParser::INTEGER - 64))
      | (1ULL << (GrammarParser::HEX_INTEGER - 64))
      | (1ULL << (GrammarParser::DATE_LITERAL - 64))
      | (1ULL << (GrammarParser::FLOATING_LITERAL - 64))
      | (1ULL << (GrammarParser::LETTER - 64))
      | (1ULL << (GrammarParser::DIGIT - 64))
      | (1ULL << (GrammarParser::ANY - 64))
      | (1ULL << (GrammarParser::MANY - 64)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- No_commaContext ------------------------------------------------------------------

GrammarParser::No_commaContext::No_commaContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::No_commaContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

tree::TerminalNode* GrammarParser::No_commaContext::OP_PARETHESES() {
  return getToken(GrammarParser::OP_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::No_commaContext::CL_PARETHESES() {
  return getToken(GrammarParser::CL_PARETHESES, 0);
}

tree::TerminalNode* GrammarParser::No_commaContext::EOF() {
  return getToken(GrammarParser::EOF, 0);
}


size_t GrammarParser::No_commaContext::getRuleIndex() const {
  return GrammarParser::RuleNo_comma;
}

void GrammarParser::No_commaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNo_comma(this);
}

void GrammarParser::No_commaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNo_comma(this);
}

GrammarParser::No_commaContext* GrammarParser::no_comma() {
  No_commaContext *_localctx = _tracker.createInstance<No_commaContext>(_ctx, getState());
  enterRule(_localctx, 236, GrammarParser::RuleNo_comma);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2033);
    _la = _input->LA(1);
    if (_la == 0 || _la == Token::EOF || (((((_la - -1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - -1)) & ((1ULL << (GrammarParser::EOF - -1))
      | (1ULL << (GrammarParser::COMMA - -1))
      | (1ULL << (GrammarParser::OP_PARETHESES - -1))
      | (1ULL << (GrammarParser::CL_PARETHESES - -1)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- No_comma_sq_brContext ------------------------------------------------------------------

GrammarParser::No_comma_sq_brContext::No_comma_sq_brContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::No_comma_sq_brContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

tree::TerminalNode* GrammarParser::No_comma_sq_brContext::OP_BR() {
  return getToken(GrammarParser::OP_BR, 0);
}

tree::TerminalNode* GrammarParser::No_comma_sq_brContext::CL_BR() {
  return getToken(GrammarParser::CL_BR, 0);
}

tree::TerminalNode* GrammarParser::No_comma_sq_brContext::EOF() {
  return getToken(GrammarParser::EOF, 0);
}


size_t GrammarParser::No_comma_sq_brContext::getRuleIndex() const {
  return GrammarParser::RuleNo_comma_sq_br;
}

void GrammarParser::No_comma_sq_brContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNo_comma_sq_br(this);
}

void GrammarParser::No_comma_sq_brContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNo_comma_sq_br(this);
}

GrammarParser::No_comma_sq_brContext* GrammarParser::no_comma_sq_br() {
  No_comma_sq_brContext *_localctx = _tracker.createInstance<No_comma_sq_brContext>(_ctx, getState());
  enterRule(_localctx, 238, GrammarParser::RuleNo_comma_sq_br);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2035);
    _la = _input->LA(1);
    if (_la == 0 || _la == Token::EOF || (((((_la - -1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - -1)) & ((1ULL << (GrammarParser::EOF - -1))
      | (1ULL << (GrammarParser::COMMA - -1))
      | (1ULL << (GrammarParser::OP_BR - -1))
      | (1ULL << (GrammarParser::CL_BR - -1)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- No_comma_semicolonContext ------------------------------------------------------------------

GrammarParser::No_comma_semicolonContext::No_comma_semicolonContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GrammarParser::No_comma_semicolonContext::COMMA() {
  return getToken(GrammarParser::COMMA, 0);
}

tree::TerminalNode* GrammarParser::No_comma_semicolonContext::SC() {
  return getToken(GrammarParser::SC, 0);
}

tree::TerminalNode* GrammarParser::No_comma_semicolonContext::EOF() {
  return getToken(GrammarParser::EOF, 0);
}


size_t GrammarParser::No_comma_semicolonContext::getRuleIndex() const {
  return GrammarParser::RuleNo_comma_semicolon;
}

void GrammarParser::No_comma_semicolonContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNo_comma_semicolon(this);
}

void GrammarParser::No_comma_semicolonContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GrammarListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNo_comma_semicolon(this);
}

GrammarParser::No_comma_semicolonContext* GrammarParser::no_comma_semicolon() {
  No_comma_semicolonContext *_localctx = _tracker.createInstance<No_comma_semicolonContext>(_ctx, getState());
  enterRule(_localctx, 240, GrammarParser::RuleNo_comma_semicolon);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(2037);
    _la = _input->LA(1);
    if (_la == 0 || _la == Token::EOF || (((((_la - -1) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - -1)) & ((1ULL << (GrammarParser::EOF - -1))
      | (1ULL << (GrammarParser::COMMA - -1))
      | (1ULL << (GrammarParser::SC - -1)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool GrammarParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 57: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);
    case 90: return params_listSempred(dynamic_cast<Params_listContext *>(context), predicateIndex);
    case 96: return fcall_params_listSempred(dynamic_cast<Fcall_params_listContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool GrammarParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool GrammarParser::params_listSempred(Params_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool GrammarParser::fcall_params_listSempred(Fcall_params_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> GrammarParser::_decisionToDFA;
atn::PredictionContextCache GrammarParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN GrammarParser::_atn;
std::vector<uint16_t> GrammarParser::_serializedATN;

std::vector<std::string> GrammarParser::_ruleNames = {
  "compileUnit", "unit", "any_function_definition", "append_scope", "function_scope", 
  "scope_content", "return_statement", "void_return", "standart_return", 
  "for_loop", "for_loop_declaration", "for_loop_variable_decl", "for_loop_condition", 
  "for_loop_increment", "for_loop_append_increment", "rvalue", "parantheses_any_expression", 
  "parantheses_content", "parantheses_content_expression", "no_parant_comma_sc", 
  "no_parant_sc", "argument_content", "commented_block", "function_call", 
  "any_function_call", "any_fcall_parantheses_expr", "any_fcall_parantheses_content", 
  "any_fcall_append_argument", "entry_point", "single_name", "datetime_litteral", 
  "append_time_litteral", "date_litteral", "time_litteral", "color_litteral", 
  "rgb_litteral", "hex_or_regular_integer", "any_lex", "sq_arguments", "sq_content", 
  "append_sq_content", "sq_brackets_argument", "sq_brackets_anyrule", "directive", 
  "property", "str", "property_content", "property_style_definition", "enum_extract2header", 
  "enum_declaration", "enum_item_list", "enum_item", "variable_change_value", 
  "variable_modify_rules", "subscript_operator", "multi_assignment", "last_multi_assignment_rvalue", 
  "expression", "op_expr", "binary_operator", "unary_operator", "single_expr_space", 
  "single_expr", "asssignment_operator", "add_brackets", "change_brackets", 
  "unsupported_object_types", "unsupported_object_properties", "return_datetime", 
  "indicator_buffers_func", "arg_comma", "modifier_variable_declaration", 
  "variable_declaration", "append_variable_declaration", "initialization_value", 
  "array_initialization_list", "initialization_list_append_items", "initialization_list_items", 
  "initialization_list_item", "const_name", "dynamic_array_brackets_params", 
  "dynamic_array_brackets_parameter", "dynamic_array_append_parameter", 
  "dynamic_array_parameter", "set_index_buffer", "set_level_style", "alert", 
  "function_definition", "type", "type_name", "params_list", "append_argument", 
  "argument", "fcall_argument", "fcall_anyrule", "fcall_params", "fcall_params_list", 
  "append_fcall_argument", "deinit_function_call", "init_function_call", 
  "start_function_call", "on_calculate_handler", "on_tick_handler", "on_init_handler", 
  "on_deinit_handler", "on_timer_handler", "on_chart_event_handler", "name", 
  "space", "integer", "float_value", "tryblock_replacement_start", "tryblock_replacement_end", 
  "parantheses_expression", "ml_content", "ol_content", "no_cl_parentheses", 
  "no_semicolon", "no_comma", "no_comma_sq_br", "no_comma_semicolon"
};

std::vector<std::string> GrammarParser::_literalNames = {
  "", "'#'", "','", "'.'", "'['", "']'", "'('", "')'", "'{'", "'}'", "':'", 
  "';'", "'\"'", "'''", "'='", "'=='", "'!='", "'>='", "'<='", "'++'", "'--'", 
  "'+'", "'-'", "'*'", "'/'", "'&'", "", "'//'", "'/*'", "'*/'", "", "", 
  "", "'deinit'", "'init'", "'start'", "'OnCalculate'", "'OnTick'", "'OnInit'", 
  "'OnDeinit'", "'OnTimer'", "'OnChartEvent'", "'----'", "'try block start function='", 
  "'try block end function='", "", "'extern'", "'input'", "'sinput'", "'static'", 
  "'strict'", "'NULL'", "'const'", "'unsigned'", "'enum'", "'else'", "'switch'", 
  "'case'", "'return'", "'for'", "'if'", "'double'", "'float'", "'void'", 
  "'int'", "'bool'", "'long'", "'short'", "'char'", "'string'", "'color'", 
  "'ulong'", "'datetime'", "'property'", "'indicator_separate_window'", 
  "'indicator_chart_window'", "'Alert'", "'GetLastError'", "'PlaySound'", 
  "", "", "'SetIndexBuffer'", "'SetLevelStyle'", "'indicator_buffers'", 
  "'IndicatorBuffers'", "", "", "", "'TimeCurrent'", "'OrderOpenTime'", 
  "'OrderCloseTime'", "", "", "", "", "", "", "'D''", "'C''"
};

std::vector<std::string> GrammarParser::_symbolicNames = {
  "", "HASH", "COMMA", "DOT", "OP_BR", "CL_BR", "OP_PARETHESES", "CL_PARETHESES", 
  "OP_CRL_BR", "CL_CRL_BR", "COLON", "SC", "D_QUOTE", "S_QUOTE", "EQ", "COMPARISSON", 
  "COMPARISSON_NOT", "MORE_OR_EQUAL", "LESS_OR_EQUAL", "INCREMENT", "DECREMENT", 
  "PLUS", "MINUS", "ASTRISK", "SLASH", "AMPERSAND", "NEWLINE", "BD_SLASH", 
  "OP_COMMENT", "CL_COMMENT", "MULTILINE_COMMENT", "ONELINE_COMMENT", "WS", 
  "DEINIT", "INIT", "START", "ON_CALCULATE", "ON_TICK", "ON_INIT", "ON_DEINIT", 
  "ON_TIMER", "ON_CHART_EVENT", "TRY_BLOCK_DASH", "TRY_BLOCK_START", "TRY_BLOCK_END", 
  "INDEX_BUFFER_TYPE", "EXTERN", "INPUT", "SINPUT", "K_STATIC", "K_STRICT", 
  "K_NULL", "K_CONST", "K_UNSIGNED", "K_ENUM", "K_ELSE", "K_SWITCH", "K_CASE", 
  "K_RETURN", "K_FOR", "K_IF", "T_DOUBLE", "T_FLOAT", "T_VOID", "T_INT", 
  "T_BOOL", "T_LONG", "T_SHORT", "T_CHAR", "T_STRING", "T_COLOR", "T_ULONG", 
  "T_DATETIME", "PROPERTY", "INDICATOR_SEPARATE_WINDOW", "INDICATOR_CHART_WINDOW", 
  "ALERT", "GET_LAST_ERROR", "PLAY_SOUND", "ADD_BRACKETS_FUNCTIONS", "CHANGE_BRACKETS_FUNCTIONS", 
  "SET_INDEX_BUFFER", "SET_LEVEL_STYLE", "INDICATOR_BUFFERS", "INDICATOR_BUFFERS_FUNC", 
  "INDICATORS_ONLY", "STRATEGY_ONLY", "HOOKING_FUNCS", "TIME_CURRENT", "ORDER_OPEN_TIME", 
  "ORDER_CLOSE_TIME", "UNSUPPORTED_OBJECTS", "UNSUPPORTED_PROPERTIES", "INDICATOR_LINE_IDENTIFIER_MODE", 
  "IMA_MODE", "PRICE_TYPE", "TIMEFRAME", "DT_LITTERAL_ST", "CLR_LITTERAL", 
  "REGULAR_STRING", "CHAR_LITTERAL", "NAME", "INTEGER", "HEX_INTEGER", "DATE_LITERAL", 
  "FLOATING_LITERAL", "LETTER", "DIGIT", "ANY", "MANY"
};

dfa::Vocabulary GrammarParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> GrammarParser::_tokenNames;

GrammarParser::Initializer::Initializer() {
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
    0x3, 0x6f, 0x7fa, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 
    0x46, 0x9, 0x46, 0x4, 0x47, 0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 
    0x9, 0x49, 0x4, 0x4a, 0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 
    0x4c, 0x4, 0x4d, 0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 
    0x4, 0x50, 0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 
    0x53, 0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
    0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 0x9, 
    0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 0x9, 0x5c, 
    0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 0x9, 0x5f, 0x4, 
    0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 0x9, 0x62, 0x4, 0x63, 
    0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x4, 0x65, 0x9, 0x65, 0x4, 0x66, 0x9, 
    0x66, 0x4, 0x67, 0x9, 0x67, 0x4, 0x68, 0x9, 0x68, 0x4, 0x69, 0x9, 0x69, 
    0x4, 0x6a, 0x9, 0x6a, 0x4, 0x6b, 0x9, 0x6b, 0x4, 0x6c, 0x9, 0x6c, 0x4, 
    0x6d, 0x9, 0x6d, 0x4, 0x6e, 0x9, 0x6e, 0x4, 0x6f, 0x9, 0x6f, 0x4, 0x70, 
    0x9, 0x70, 0x4, 0x71, 0x9, 0x71, 0x4, 0x72, 0x9, 0x72, 0x4, 0x73, 0x9, 
    0x73, 0x4, 0x74, 0x9, 0x74, 0x4, 0x75, 0x9, 0x75, 0x4, 0x76, 0x9, 0x76, 
    0x4, 0x77, 0x9, 0x77, 0x4, 0x78, 0x9, 0x78, 0x4, 0x79, 0x9, 0x79, 0x4, 
    0x7a, 0x9, 0x7a, 0x3, 0x2, 0x6, 0x2, 0xf6, 0xa, 0x2, 0xd, 0x2, 0xe, 
    0x2, 0xf7, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x5, 0x3, 0x101, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x106, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x109, 0xb, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x10c, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x111, 
    0xa, 0x4, 0x3, 0x5, 0x7, 0x5, 0x114, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x117, 
    0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x11d, 0xa, 
    0x6, 0xc, 0x6, 0xe, 0x6, 0x120, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0x134, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x138, 
    0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x13c, 0xa, 0x9, 0xc, 0x9, 0xe, 
    0x9, 0x13f, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0x145, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x148, 0xb, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x7, 0xa, 0x14c, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x14f, 0xb, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x155, 0xa, 0xb, 0xc, 
    0xb, 0xe, 0xb, 0x158, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x7, 0xc, 0x161, 0xa, 0xc, 0xc, 0xc, 0xe, 
    0xc, 0x164, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x168, 0xa, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0x16c, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x16f, 
    0xb, 0xd, 0x3, 0xd, 0x7, 0xd, 0x172, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x175, 
    0xb, 0xd, 0x5, 0xd, 0x177, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x7, 
    0xe, 0x17c, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x17f, 0xb, 0xe, 0x3, 0xe, 
    0x6, 0xe, 0x182, 0xa, 0xe, 0xd, 0xe, 0xe, 0xe, 0x183, 0x3, 0xe, 0x7, 
    0xe, 0x187, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x18a, 0xb, 0xe, 0x5, 0xe, 
    0x18c, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x7, 0xf, 0x191, 0xa, 
    0xf, 0xc, 0xf, 0xe, 0xf, 0x194, 0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 
    0x198, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x19b, 0xb, 0xf, 0x3, 0xf, 0x7, 
    0xf, 0x19e, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0x1a1, 0xb, 0xf, 0x5, 0xf, 
    0x1a3, 0xa, 0xf, 0x3, 0x10, 0x7, 0x10, 0x1a6, 0xa, 0x10, 0xc, 0x10, 
    0xe, 0x10, 0x1a9, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 0x7, 0x10, 0x1ad, 
    0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0x1b0, 0xb, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x1be, 0xa, 0x11, 
    0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x1c2, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x13, 0x6, 0x13, 0x1c7, 0xa, 0x13, 0xd, 0x13, 0xe, 0x13, 0x1c8, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x1cd, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x1db, 0xa, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 0x1df, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 
    0x19, 0x1e9, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x1ed, 0xa, 
    0x1a, 0xc, 0x1a, 0xe, 0x1a, 0x1f0, 0xb, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x1f6, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x1fc, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 
    0x1ff, 0xb, 0x1c, 0x3, 0x1d, 0x7, 0x1d, 0x202, 0xa, 0x1d, 0xc, 0x1d, 
    0xe, 0x1d, 0x205, 0xb, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x7, 0x1d, 0x209, 
    0xa, 0x1d, 0xc, 0x1d, 0xe, 0x1d, 0x20c, 0xb, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
    0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x5, 0x1e, 0x219, 0xa, 0x1e, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 0x221, 
    0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x227, 
    0xa, 0x20, 0x5, 0x20, 0x229, 0xa, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 
    0x6, 0x21, 0x22e, 0xa, 0x21, 0xd, 0x21, 0xe, 0x21, 0x22f, 0x3, 0x21, 
    0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x3, 0x23, 0x5, 0x23, 0x23b, 0xa, 0x23, 0x5, 0x23, 0x23d, 0xa, 
    0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x25, 0x7, 0x25, 
    0x244, 0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x247, 0xb, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x24f, 
    0xa, 0x25, 0xc, 0x25, 0xe, 0x25, 0x252, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 
    0x27, 0x29d, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x2a1, 0xa, 
    0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x2a7, 
    0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 0x2aa, 0xb, 0x29, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x2b1, 0xa, 0x2b, 0xc, 0x2b, 
    0xe, 0x2b, 0x2b4, 0xb, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x2b8, 
    0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 0x2bb, 0xb, 0x2b, 0x6, 0x2b, 0x2bd, 
    0xa, 0x2b, 0xd, 0x2b, 0xe, 0x2b, 0x2be, 0x3, 0x2b, 0x6, 0x2b, 0x2c2, 
    0xa, 0x2b, 0xd, 0x2b, 0xe, 0x2b, 0x2c3, 0x5, 0x2b, 0x2c6, 0xa, 0x2b, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x2cb, 0xa, 0x2c, 0x3, 0x2d, 
    0x3, 0x2d, 0x7, 0x2d, 0x2cf, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x2d2, 
    0xb, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 0x2d6, 0xa, 0x2d, 0x3, 0x2e, 
    0x3, 0x2e, 0x7, 0x2e, 0x2da, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x2dd, 
    0xb, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
    0x30, 0x6, 0x30, 0x2e5, 0xa, 0x30, 0xd, 0x30, 0xe, 0x30, 0x2e6, 0x3, 
    0x30, 0x3, 0x30, 0x6, 0x30, 0x2eb, 0xa, 0x30, 0xd, 0x30, 0xe, 0x30, 
    0x2ec, 0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 0x2f1, 0xa, 0x30, 0xc, 0x30, 
    0xe, 0x30, 0x2f4, 0xb, 0x30, 0x3, 0x30, 0x6, 0x30, 0x2f7, 0xa, 0x30, 
    0xd, 0x30, 0xe, 0x30, 0x2f8, 0x3, 0x30, 0x3, 0x30, 0x7, 0x30, 0x2fd, 
    0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x300, 0xb, 0x30, 0x3, 0x30, 0x6, 0x30, 
    0x303, 0xa, 0x30, 0xd, 0x30, 0xe, 0x30, 0x304, 0x3, 0x30, 0x3, 0x30, 
    0x7, 0x30, 0x309, 0xa, 0x30, 0xc, 0x30, 0xe, 0x30, 0x30c, 0xb, 0x30, 
    0x3, 0x30, 0x6, 0x30, 0x30f, 0xa, 0x30, 0xd, 0x30, 0xe, 0x30, 0x310, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x316, 0xa, 0x30, 0x5, 0x30, 
    0x318, 0xa, 0x30, 0x3, 0x31, 0x6, 0x31, 0x31b, 0xa, 0x31, 0xd, 0x31, 
    0xe, 0x31, 0x31c, 0x3, 0x31, 0x3, 0x31, 0x6, 0x31, 0x321, 0xa, 0x31, 
    0xd, 0x31, 0xe, 0x31, 0x322, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x5, 0x31, 0x329, 0xa, 0x31, 0x3, 0x31, 0x7, 0x31, 0x32c, 0xa, 0x31, 
    0xc, 0x31, 0xe, 0x31, 0x32f, 0xb, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 
    0x3, 0x33, 0x6, 0x33, 0x335, 0xa, 0x33, 0xd, 0x33, 0xe, 0x33, 0x336, 
    0x3, 0x33, 0x3, 0x33, 0x7, 0x33, 0x33b, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 
    0x33e, 0xb, 0x33, 0x3, 0x33, 0x3, 0x33, 0x7, 0x33, 0x342, 0xa, 0x33, 
    0xc, 0x33, 0xe, 0x33, 0x345, 0xb, 0x33, 0x3, 0x33, 0x5, 0x33, 0x348, 
    0xa, 0x33, 0x3, 0x33, 0x7, 0x33, 0x34b, 0xa, 0x33, 0xc, 0x33, 0xe, 0x33, 
    0x34e, 0xb, 0x33, 0x3, 0x33, 0x3, 0x33, 0x7, 0x33, 0x352, 0xa, 0x33, 
    0xc, 0x33, 0xe, 0x33, 0x355, 0xb, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 
    0x3, 0x34, 0x7, 0x34, 0x35b, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x35e, 
    0xb, 0x34, 0x3, 0x34, 0x5, 0x34, 0x361, 0xa, 0x34, 0x3, 0x34, 0x7, 0x34, 
    0x364, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x367, 0xb, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x7, 0x34, 0x36b, 0xa, 0x34, 0xc, 0x34, 0xe, 0x34, 0x36e, 
    0xb, 0x34, 0x3, 0x34, 0x3, 0x34, 0x7, 0x34, 0x372, 0xa, 0x34, 0xc, 0x34, 
    0xe, 0x34, 0x375, 0xb, 0x34, 0x3, 0x34, 0x7, 0x34, 0x378, 0xa, 0x34, 
    0xc, 0x34, 0xe, 0x34, 0x37b, 0xb, 0x34, 0x3, 0x34, 0x5, 0x34, 0x37e, 
    0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x382, 0xa, 0x35, 0xc, 0x35, 
    0xe, 0x35, 0x385, 0xb, 0x35, 0x3, 0x35, 0x3, 0x35, 0x7, 0x35, 0x389, 
    0xa, 0x35, 0xc, 0x35, 0xe, 0x35, 0x38c, 0xb, 0x35, 0x3, 0x35, 0x5, 0x35, 
    0x38f, 0xa, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 
    0x395, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 0x398, 0xb, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x7, 0x37, 0x39f, 0xa, 0x37, 
    0xc, 0x37, 0xe, 0x37, 0x3a2, 0xb, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x37, 0x7, 0x37, 0x3a8, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 0x3ab, 
    0xb, 0x37, 0x3, 0x37, 0x3, 0x37, 0x5, 0x37, 0x3af, 0xa, 0x37, 0x3, 0x38, 
    0x3, 0x38, 0x7, 0x38, 0x3b3, 0xa, 0x38, 0xc, 0x38, 0xe, 0x38, 0x3b6, 
    0xb, 0x38, 0x3, 0x38, 0x5, 0x38, 0x3b9, 0xa, 0x38, 0x3, 0x39, 0x7, 0x39, 
    0x3bc, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x3bf, 0xb, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x7, 0x39, 0x3c3, 0xa, 0x39, 0xc, 0x39, 0xe, 0x39, 0x3c6, 
    0xb, 0x39, 0x3, 0x39, 0x3, 0x39, 0x6, 0x39, 0x3ca, 0xa, 0x39, 0xd, 0x39, 
    0xe, 0x39, 0x3cb, 0x5, 0x39, 0x3ce, 0xa, 0x39, 0x3, 0x3a, 0x7, 0x3a, 
    0x3d1, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x3d4, 0xb, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x7, 0x3a, 0x3d8, 0xa, 0x3a, 0xc, 0x3a, 0xe, 0x3a, 0x3db, 
    0xb, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x6, 0x3a, 0x3df, 0xa, 0x3a, 0xd, 0x3a, 
    0xe, 0x3a, 0x3e0, 0x5, 0x3a, 0x3e3, 0xa, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x5, 0x3b, 0x3e8, 0xa, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x3f1, 0xa, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3b, 0x5, 0x3b, 0x3f8, 
    0xa, 0x3b, 0x7, 0x3b, 0x3fa, 0xa, 0x3b, 0xc, 0x3b, 0xe, 0x3b, 0x3fd, 
    0xb, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
    0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x5, 0x3f, 0x407, 0xa, 0x3f, 0x3, 0x3f, 
    0x7, 0x3f, 0x40a, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 0x40d, 0xb, 0x3f, 
    0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 0x411, 0xa, 0x3f, 0xc, 0x3f, 0xe, 0x3f, 
    0x414, 0xb, 0x3f, 0x3, 0x3f, 0x3, 0x3f, 0x7, 0x3f, 0x418, 0xa, 0x3f, 
    0xc, 0x3f, 0xe, 0x3f, 0x41b, 0xb, 0x3f, 0x5, 0x3f, 0x41d, 0xa, 0x3f, 
    0x3, 0x40, 0x3, 0x40, 0x7, 0x40, 0x421, 0xa, 0x40, 0xc, 0x40, 0xe, 0x40, 
    0x424, 0xb, 0x40, 0x3, 0x40, 0x5, 0x40, 0x427, 0xa, 0x40, 0x3, 0x40, 
    0x3, 0x40, 0x3, 0x40, 0x5, 0x40, 0x42c, 0xa, 0x40, 0x3, 0x41, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
    0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x5, 0x41, 0x43b, 
    0xa, 0x41, 0x3, 0x42, 0x3, 0x42, 0x7, 0x42, 0x43f, 0xa, 0x42, 0xc, 0x42, 
    0xe, 0x42, 0x442, 0xb, 0x42, 0x3, 0x42, 0x3, 0x42, 0x7, 0x42, 0x446, 
    0xa, 0x42, 0xc, 0x42, 0xe, 0x42, 0x449, 0xb, 0x42, 0x3, 0x42, 0x5, 0x42, 
    0x44c, 0xa, 0x42, 0x3, 0x43, 0x3, 0x43, 0x7, 0x43, 0x450, 0xa, 0x43, 
    0xc, 0x43, 0xe, 0x43, 0x453, 0xb, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 
    0x3, 0x43, 0x3, 0x44, 0x3, 0x44, 0x3, 0x45, 0x3, 0x45, 0x3, 0x46, 0x3, 
    0x46, 0x3, 0x47, 0x3, 0x47, 0x7, 0x47, 0x461, 0xa, 0x47, 0xc, 0x47, 
    0xe, 0x47, 0x464, 0xb, 0x47, 0x3, 0x47, 0x3, 0x47, 0x7, 0x47, 0x468, 
    0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x46b, 0xb, 0x47, 0x3, 0x47, 0x3, 0x47, 
    0x7, 0x47, 0x46f, 0xa, 0x47, 0xc, 0x47, 0xe, 0x47, 0x472, 0xb, 0x47, 
    0x3, 0x47, 0x3, 0x47, 0x3, 0x48, 0x7, 0x48, 0x477, 0xa, 0x48, 0xc, 0x48, 
    0xe, 0x48, 0x47a, 0xb, 0x48, 0x3, 0x48, 0x3, 0x48, 0x7, 0x48, 0x47e, 
    0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x481, 0xb, 0x48, 0x3, 0x49, 0x3, 0x49, 
    0x6, 0x49, 0x485, 0xa, 0x49, 0xd, 0x49, 0xe, 0x49, 0x486, 0x5, 0x49, 
    0x489, 0xa, 0x49, 0x3, 0x49, 0x3, 0x49, 0x7, 0x49, 0x48d, 0xa, 0x49, 
    0xc, 0x49, 0xe, 0x49, 0x490, 0xb, 0x49, 0x3, 0x49, 0x7, 0x49, 0x493, 
    0xa, 0x49, 0xc, 0x49, 0xe, 0x49, 0x496, 0xb, 0x49, 0x3, 0x49, 0x5, 0x49, 
    0x499, 0xa, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x6, 0x4a, 0x49d, 0xa, 0x4a, 
    0xd, 0x4a, 0xe, 0x4a, 0x49e, 0x5, 0x4a, 0x4a1, 0xa, 0x4a, 0x3, 0x4a, 
    0x3, 0x4a, 0x7, 0x4a, 0x4a5, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 0x4a8, 
    0xb, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 0x4ac, 0xa, 0x4a, 0xc, 0x4a, 
    0xe, 0x4a, 0x4af, 0xb, 0x4a, 0x5, 0x4a, 0x4b1, 0xa, 0x4a, 0x3, 0x4a, 
    0x3, 0x4a, 0x7, 0x4a, 0x4b5, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 0x4b8, 
    0xb, 0x4a, 0x3, 0x4a, 0x5, 0x4a, 0x4bb, 0xa, 0x4a, 0x3, 0x4a, 0x7, 0x4a, 
    0x4be, 0xa, 0x4a, 0xc, 0x4a, 0xe, 0x4a, 0x4c1, 0xb, 0x4a, 0x3, 0x4a, 
    0x5, 0x4a, 0x4c4, 0xa, 0x4a, 0x3, 0x4b, 0x7, 0x4b, 0x4c7, 0xa, 0x4b, 
    0xc, 0x4b, 0xe, 0x4b, 0x4ca, 0xb, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x7, 0x4b, 
    0x4ce, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x4d1, 0xb, 0x4b, 0x3, 0x4b, 
    0x3, 0x4b, 0x7, 0x4b, 0x4d5, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x4d8, 
    0xb, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x4db, 0xa, 0x4b, 0x3, 0x4b, 0x7, 0x4b, 
    0x4de, 0xa, 0x4b, 0xc, 0x4b, 0xe, 0x4b, 0x4e1, 0xb, 0x4b, 0x3, 0x4b, 
    0x5, 0x4b, 0x4e4, 0xa, 0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x7, 0x4c, 0x4e8, 
    0xa, 0x4c, 0xc, 0x4c, 0xe, 0x4c, 0x4eb, 0xb, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 
    0x6, 0x4c, 0x4ef, 0xa, 0x4c, 0xd, 0x4c, 0xe, 0x4c, 0x4f0, 0x5, 0x4c, 
    0x4f3, 0xa, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x7, 0x4d, 0x4f8, 
    0xa, 0x4d, 0xc, 0x4d, 0xe, 0x4d, 0x4fb, 0xb, 0x4d, 0x5, 0x4d, 0x4fd, 
    0xa, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
    0x4f, 0x7, 0x4f, 0x505, 0xa, 0x4f, 0xc, 0x4f, 0xe, 0x4f, 0x508, 0xb, 
    0x4f, 0x3, 0x4f, 0x3, 0x4f, 0x7, 0x4f, 0x50c, 0xa, 0x4f, 0xc, 0x4f, 
    0xe, 0x4f, 0x50f, 0xb, 0x4f, 0x3, 0x4f, 0x6, 0x4f, 0x512, 0xa, 0x4f, 
    0xd, 0x4f, 0xe, 0x4f, 0x513, 0x3, 0x4f, 0x6, 0x4f, 0x517, 0xa, 0x4f, 
    0xd, 0x4f, 0xe, 0x4f, 0x518, 0x5, 0x4f, 0x51b, 0xa, 0x4f, 0x3, 0x50, 
    0x6, 0x50, 0x51e, 0xa, 0x50, 0xd, 0x50, 0xe, 0x50, 0x51f, 0x3, 0x50, 
    0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 
    0x50, 0x3, 0x50, 0x3, 0x50, 0x3, 0x50, 0x5, 0x50, 0x52d, 0xa, 0x50, 
    0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 0x6, 0x52, 0x532, 0xa, 0x52, 0xd, 0x52, 
    0xe, 0x52, 0x533, 0x3, 0x53, 0x3, 0x53, 0x7, 0x53, 0x538, 0xa, 0x53, 
    0xc, 0x53, 0xe, 0x53, 0x53b, 0xb, 0x53, 0x3, 0x53, 0x3, 0x53, 0x7, 0x53, 
    0x53f, 0xa, 0x53, 0xc, 0x53, 0xe, 0x53, 0x542, 0xb, 0x53, 0x3, 0x53, 
    0x5, 0x53, 0x545, 0xa, 0x53, 0x3, 0x53, 0x6, 0x53, 0x548, 0xa, 0x53, 
    0xd, 0x53, 0xe, 0x53, 0x549, 0x5, 0x53, 0x54c, 0xa, 0x53, 0x3, 0x53, 
    0x7, 0x53, 0x54f, 0xa, 0x53, 0xc, 0x53, 0xe, 0x53, 0x552, 0xb, 0x53, 
    0x3, 0x53, 0x3, 0x53, 0x3, 0x54, 0x7, 0x54, 0x557, 0xa, 0x54, 0xc, 0x54, 
    0xe, 0x54, 0x55a, 0xb, 0x54, 0x3, 0x54, 0x3, 0x54, 0x7, 0x54, 0x55e, 
    0xa, 0x54, 0xc, 0x54, 0xe, 0x54, 0x561, 0xb, 0x54, 0x3, 0x54, 0x5, 0x54, 
    0x564, 0xa, 0x54, 0x3, 0x55, 0x3, 0x55, 0x3, 0x56, 0x3, 0x56, 0x7, 0x56, 
    0x56a, 0xa, 0x56, 0xc, 0x56, 0xe, 0x56, 0x56d, 0xb, 0x56, 0x3, 0x56, 
    0x3, 0x56, 0x7, 0x56, 0x571, 0xa, 0x56, 0xc, 0x56, 0xe, 0x56, 0x574, 
    0xb, 0x56, 0x3, 0x56, 0x3, 0x56, 0x5, 0x56, 0x578, 0xa, 0x56, 0x3, 0x56, 
    0x7, 0x56, 0x57b, 0xa, 0x56, 0xc, 0x56, 0xe, 0x56, 0x57e, 0xb, 0x56, 
    0x3, 0x56, 0x3, 0x56, 0x7, 0x56, 0x582, 0xa, 0x56, 0xc, 0x56, 0xe, 0x56, 
    0x585, 0xb, 0x56, 0x3, 0x56, 0x3, 0x56, 0x7, 0x56, 0x589, 0xa, 0x56, 
    0xc, 0x56, 0xe, 0x56, 0x58c, 0xb, 0x56, 0x3, 0x56, 0x3, 0x56, 0x7, 0x56, 
    0x590, 0xa, 0x56, 0xc, 0x56, 0xe, 0x56, 0x593, 0xb, 0x56, 0x3, 0x56, 
    0x3, 0x56, 0x7, 0x56, 0x597, 0xa, 0x56, 0xc, 0x56, 0xe, 0x56, 0x59a, 
    0xb, 0x56, 0x5, 0x56, 0x59c, 0xa, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 
    0x3, 0x57, 0x7, 0x57, 0x5a2, 0xa, 0x57, 0xc, 0x57, 0xe, 0x57, 0x5a5, 
    0xb, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x57, 0x3, 0x58, 0x3, 
    0x58, 0x7, 0x58, 0x5ad, 0xa, 0x58, 0xc, 0x58, 0xe, 0x58, 0x5b0, 0xb, 
    0x58, 0x3, 0x58, 0x3, 0x58, 0x3, 0x59, 0x3, 0x59, 0x7, 0x59, 0x5b6, 
    0xa, 0x59, 0xc, 0x59, 0xe, 0x59, 0x5b9, 0xb, 0x59, 0x3, 0x59, 0x5, 0x59, 
    0x5bc, 0xa, 0x59, 0x3, 0x59, 0x7, 0x59, 0x5bf, 0xa, 0x59, 0xc, 0x59, 
    0xe, 0x59, 0x5c2, 0xb, 0x59, 0x3, 0x59, 0x3, 0x59, 0x7, 0x59, 0x5c6, 
    0xa, 0x59, 0xc, 0x59, 0xe, 0x59, 0x5c9, 0xb, 0x59, 0x3, 0x59, 0x3, 0x59, 
    0x7, 0x59, 0x5cd, 0xa, 0x59, 0xc, 0x59, 0xe, 0x59, 0x5d0, 0xb, 0x59, 
    0x3, 0x59, 0x5, 0x59, 0x5d3, 0xa, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 
    0x3, 0x5a, 0x7, 0x5a, 0x5d9, 0xa, 0x5a, 0xc, 0x5a, 0xe, 0x5a, 0x5dc, 
    0xb, 0x5a, 0x3, 0x5a, 0x7, 0x5a, 0x5df, 0xa, 0x5a, 0xc, 0x5a, 0xe, 0x5a, 
    0x5e2, 0xb, 0x5a, 0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x3, 0x5c, 0x3, 0x5c, 
    0x7, 0x5c, 0x5e9, 0xa, 0x5c, 0xc, 0x5c, 0xe, 0x5c, 0x5ec, 0xb, 0x5c, 
    0x3, 0x5c, 0x3, 0x5c, 0x7, 0x5c, 0x5f0, 0xa, 0x5c, 0xc, 0x5c, 0xe, 0x5c, 
    0x5f3, 0xb, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x7, 0x5d, 0x5f7, 0xa, 0x5d, 
    0xc, 0x5d, 0xe, 0x5d, 0x5fa, 0xb, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x7, 0x5d, 
    0x5fe, 0xa, 0x5d, 0xc, 0x5d, 0xe, 0x5d, 0x601, 0xb, 0x5d, 0x3, 0x5e, 
    0x3, 0x5e, 0x3, 0x5f, 0x6, 0x5f, 0x606, 0xa, 0x5f, 0xd, 0x5f, 0xe, 0x5f, 
    0x607, 0x3, 0x5f, 0x7, 0x5f, 0x60b, 0xa, 0x5f, 0xc, 0x5f, 0xe, 0x5f, 
    0x60e, 0xb, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x7, 0x5f, 0x612, 0xa, 0x5f, 
    0xc, 0x5f, 0xe, 0x5f, 0x615, 0xb, 0x5f, 0x6, 0x5f, 0x617, 0xa, 0x5f, 
    0xd, 0x5f, 0xe, 0x5f, 0x618, 0x5, 0x5f, 0x61b, 0xa, 0x5f, 0x3, 0x60, 
    0x3, 0x60, 0x5, 0x60, 0x61f, 0xa, 0x60, 0x3, 0x61, 0x3, 0x61, 0x5, 0x61, 
    0x623, 0xa, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x62, 0x3, 0x62, 0x3, 0x62, 
    0x3, 0x62, 0x3, 0x62, 0x7, 0x62, 0x62c, 0xa, 0x62, 0xc, 0x62, 0xe, 0x62, 
    0x62f, 0xb, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 0x63, 0x3, 0x64, 0x3, 0x64, 
    0x6, 0x64, 0x636, 0xa, 0x64, 0xd, 0x64, 0xe, 0x64, 0x637, 0x3, 0x64, 
    0x3, 0x64, 0x7, 0x64, 0x63c, 0xa, 0x64, 0xc, 0x64, 0xe, 0x64, 0x63f, 
    0xb, 0x64, 0x3, 0x64, 0x3, 0x64, 0x7, 0x64, 0x643, 0xa, 0x64, 0xc, 0x64, 
    0xe, 0x64, 0x646, 0xb, 0x64, 0x3, 0x64, 0x3, 0x64, 0x7, 0x64, 0x64a, 
    0xa, 0x64, 0xc, 0x64, 0xe, 0x64, 0x64d, 0xb, 0x64, 0x5, 0x64, 0x64f, 
    0xa, 0x64, 0x3, 0x64, 0x3, 0x64, 0x3, 0x65, 0x3, 0x65, 0x6, 0x65, 0x655, 
    0xa, 0x65, 0xd, 0x65, 0xe, 0x65, 0x656, 0x3, 0x65, 0x3, 0x65, 0x7, 0x65, 
    0x65b, 0xa, 0x65, 0xc, 0x65, 0xe, 0x65, 0x65e, 0xb, 0x65, 0x3, 0x65, 
    0x3, 0x65, 0x7, 0x65, 0x662, 0xa, 0x65, 0xc, 0x65, 0xe, 0x65, 0x665, 
    0xb, 0x65, 0x3, 0x65, 0x3, 0x65, 0x7, 0x65, 0x669, 0xa, 0x65, 0xc, 0x65, 
    0xe, 0x65, 0x66c, 0xb, 0x65, 0x5, 0x65, 0x66e, 0xa, 0x65, 0x3, 0x65, 
    0x3, 0x65, 0x3, 0x66, 0x3, 0x66, 0x6, 0x66, 0x674, 0xa, 0x66, 0xd, 0x66, 
    0xe, 0x66, 0x675, 0x3, 0x66, 0x3, 0x66, 0x7, 0x66, 0x67a, 0xa, 0x66, 
    0xc, 0x66, 0xe, 0x66, 0x67d, 0xb, 0x66, 0x3, 0x66, 0x3, 0x66, 0x7, 0x66, 
    0x681, 0xa, 0x66, 0xc, 0x66, 0xe, 0x66, 0x684, 0xb, 0x66, 0x3, 0x66, 
    0x3, 0x66, 0x7, 0x66, 0x688, 0xa, 0x66, 0xc, 0x66, 0xe, 0x66, 0x68b, 
    0xb, 0x66, 0x5, 0x66, 0x68d, 0xa, 0x66, 0x3, 0x66, 0x3, 0x66, 0x3, 0x67, 
    0x3, 0x67, 0x6, 0x67, 0x693, 0xa, 0x67, 0xd, 0x67, 0xe, 0x67, 0x694, 
    0x3, 0x67, 0x3, 0x67, 0x7, 0x67, 0x699, 0xa, 0x67, 0xc, 0x67, 0xe, 0x67, 
    0x69c, 0xb, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x67, 0x3, 0x68, 
    0x3, 0x68, 0x6, 0x68, 0x6a4, 0xa, 0x68, 0xd, 0x68, 0xe, 0x68, 0x6a5, 
    0x3, 0x68, 0x3, 0x68, 0x7, 0x68, 0x6aa, 0xa, 0x68, 0xc, 0x68, 0xe, 0x68, 
    0x6ad, 0xb, 0x68, 0x3, 0x68, 0x3, 0x68, 0x7, 0x68, 0x6b1, 0xa, 0x68, 
    0xc, 0x68, 0xe, 0x68, 0x6b4, 0xb, 0x68, 0x3, 0x68, 0x3, 0x68, 0x7, 0x68, 
    0x6b8, 0xa, 0x68, 0xc, 0x68, 0xe, 0x68, 0x6bb, 0xb, 0x68, 0x5, 0x68, 
    0x6bd, 0xa, 0x68, 0x3, 0x68, 0x3, 0x68, 0x3, 0x69, 0x3, 0x69, 0x6, 0x69, 
    0x6c3, 0xa, 0x69, 0xd, 0x69, 0xe, 0x69, 0x6c4, 0x3, 0x69, 0x3, 0x69, 
    0x7, 0x69, 0x6c9, 0xa, 0x69, 0xc, 0x69, 0xe, 0x69, 0x6cc, 0xb, 0x69, 
    0x3, 0x69, 0x3, 0x69, 0x7, 0x69, 0x6d0, 0xa, 0x69, 0xc, 0x69, 0xe, 0x69, 
    0x6d3, 0xb, 0x69, 0x3, 0x69, 0x3, 0x69, 0x7, 0x69, 0x6d7, 0xa, 0x69, 
    0xc, 0x69, 0xe, 0x69, 0x6da, 0xb, 0x69, 0x5, 0x69, 0x6dc, 0xa, 0x69, 
    0x3, 0x69, 0x3, 0x69, 0x3, 0x6a, 0x3, 0x6a, 0x6, 0x6a, 0x6e2, 0xa, 0x6a, 
    0xd, 0x6a, 0xe, 0x6a, 0x6e3, 0x3, 0x6a, 0x3, 0x6a, 0x7, 0x6a, 0x6e8, 
    0xa, 0x6a, 0xc, 0x6a, 0xe, 0x6a, 0x6eb, 0xb, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 
    0x7, 0x6a, 0x6ef, 0xa, 0x6a, 0xc, 0x6a, 0xe, 0x6a, 0x6f2, 0xb, 0x6a, 
    0x3, 0x6a, 0x3, 0x6a, 0x7, 0x6a, 0x6f6, 0xa, 0x6a, 0xc, 0x6a, 0xe, 0x6a, 
    0x6f9, 0xb, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x7, 0x6a, 0x6fd, 0xa, 0x6a, 
    0xc, 0x6a, 0xe, 0x6a, 0x700, 0xb, 0x6a, 0x3, 0x6a, 0x3, 0x6a, 0x7, 0x6a, 
    0x704, 0xa, 0x6a, 0xc, 0x6a, 0xe, 0x6a, 0x707, 0xb, 0x6a, 0x3, 0x6a, 
    0x3, 0x6a, 0x3, 0x6b, 0x3, 0x6b, 0x6, 0x6b, 0x70d, 0xa, 0x6b, 0xd, 0x6b, 
    0xe, 0x6b, 0x70e, 0x3, 0x6b, 0x3, 0x6b, 0x7, 0x6b, 0x713, 0xa, 0x6b, 
    0xc, 0x6b, 0xe, 0x6b, 0x716, 0xb, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x7, 0x6b, 
    0x71a, 0xa, 0x6b, 0xc, 0x6b, 0xe, 0x6b, 0x71d, 0xb, 0x6b, 0x3, 0x6b, 
    0x3, 0x6b, 0x7, 0x6b, 0x721, 0xa, 0x6b, 0xc, 0x6b, 0xe, 0x6b, 0x724, 
    0xb, 0x6b, 0x5, 0x6b, 0x726, 0xa, 0x6b, 0x3, 0x6b, 0x3, 0x6b, 0x3, 0x6c, 
    0x3, 0x6c, 0x6, 0x6c, 0x72c, 0xa, 0x6c, 0xd, 0x6c, 0xe, 0x6c, 0x72d, 
    0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x732, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 
    0x735, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x739, 0xa, 0x6c, 
    0xc, 0x6c, 0xe, 0x6c, 0x73c, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 
    0x740, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x743, 0xb, 0x6c, 0x3, 0x6c, 
    0x3, 0x6c, 0x7, 0x6c, 0x747, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x74a, 
    0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x74e, 0xa, 0x6c, 0xc, 0x6c, 
    0xe, 0x6c, 0x751, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x755, 
    0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x758, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 
    0x7, 0x6c, 0x75c, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x75f, 0xb, 0x6c, 
    0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x763, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 
    0x766, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x76a, 0xa, 0x6c, 
    0xc, 0x6c, 0xe, 0x6c, 0x76d, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 
    0x771, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x774, 0xb, 0x6c, 0x3, 0x6c, 
    0x3, 0x6c, 0x7, 0x6c, 0x778, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x77b, 
    0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x77f, 0xa, 0x6c, 0xc, 0x6c, 
    0xe, 0x6c, 0x782, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x786, 
    0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x789, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 
    0x7, 0x6c, 0x78d, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x790, 0xb, 0x6c, 
    0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x794, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 
    0x797, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x79b, 0xa, 0x6c, 
    0xc, 0x6c, 0xe, 0x6c, 0x79e, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 
    0x7a2, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x7a5, 0xb, 0x6c, 0x3, 0x6c, 
    0x3, 0x6c, 0x7, 0x6c, 0x7a9, 0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x7ac, 
    0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x7b0, 0xa, 0x6c, 0xc, 0x6c, 
    0xe, 0x6c, 0x7b3, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 0x7, 0x6c, 0x7b7, 
    0xa, 0x6c, 0xc, 0x6c, 0xe, 0x6c, 0x7ba, 0xb, 0x6c, 0x3, 0x6c, 0x3, 0x6c, 
    0x3, 0x6d, 0x3, 0x6d, 0x3, 0x6e, 0x3, 0x6e, 0x3, 0x6f, 0x5, 0x6f, 0x7c3, 
    0xa, 0x6f, 0x3, 0x6f, 0x3, 0x6f, 0x3, 0x70, 0x3, 0x70, 0x3, 0x71, 0x3, 
    0x71, 0x3, 0x71, 0x3, 0x71, 0x3, 0x71, 0x3, 0x71, 0x3, 0x72, 0x3, 0x72, 
    0x3, 0x72, 0x3, 0x72, 0x3, 0x72, 0x3, 0x72, 0x3, 0x73, 0x3, 0x73, 0x6, 
    0x73, 0x7d7, 0xa, 0x73, 0xd, 0x73, 0xe, 0x73, 0x7d8, 0x3, 0x73, 0x5, 
    0x73, 0x7dc, 0xa, 0x73, 0x3, 0x73, 0x3, 0x73, 0x3, 0x74, 0x6, 0x74, 
    0x7e1, 0xa, 0x74, 0xd, 0x74, 0xe, 0x74, 0x7e2, 0x3, 0x75, 0x6, 0x75, 
    0x7e6, 0xa, 0x75, 0xd, 0x75, 0xe, 0x75, 0x7e7, 0x3, 0x76, 0x6, 0x76, 
    0x7eb, 0xa, 0x76, 0xd, 0x76, 0xe, 0x76, 0x7ec, 0x3, 0x77, 0x6, 0x77, 
    0x7f0, 0xa, 0x77, 0xd, 0x77, 0xe, 0x77, 0x7f1, 0x3, 0x78, 0x3, 0x78, 
    0x3, 0x79, 0x3, 0x79, 0x3, 0x7a, 0x3, 0x7a, 0x3, 0x7a, 0x2, 0x5, 0x74, 
    0xb6, 0xc2, 0x7b, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 
    0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 
    0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 
    0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 
    0x8e, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 
    0xa6, 0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 
    0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 
    0xd6, 0xd8, 0xda, 0xdc, 0xde, 0xe0, 0xe2, 0xe4, 0xe6, 0xe8, 0xea, 0xec, 
    0xee, 0xf0, 0xf2, 0x2, 0x18, 0x5, 0x2, 0x4, 0x4, 0x8, 0x9, 0xd, 0xd, 
    0x4, 0x2, 0x8, 0x9, 0xd, 0xd, 0x3, 0x2, 0x68, 0x69, 0x3, 0x2, 0x17, 
    0x1a, 0x3, 0x2, 0x15, 0x16, 0x3, 0x2, 0x5a, 0x5c, 0x3, 0x2, 0x30, 0x33, 
    0x4, 0x2, 0x2f, 0x2f, 0x5d, 0x62, 0x3, 0x2, 0x67, 0x68, 0x5, 0x2, 0x36, 
    0x37, 0x3f, 0x4a, 0x67, 0x67, 0x3, 0x2, 0x41, 0x42, 0x7, 0x2, 0x23, 
    0x2a, 0x2f, 0x2f, 0x4e, 0x50, 0x57, 0x59, 0x67, 0x67, 0x4, 0x2, 0x1c, 
    0x1c, 0x22, 0x22, 0x3, 0x2, 0x17, 0x18, 0x3, 0x3, 0x9, 0x9, 0x3, 0x2, 
    0x1f, 0x1f, 0x3, 0x3, 0x1c, 0x1c, 0x4, 0x3, 0x9, 0x9, 0xd, 0xd, 0x3, 
    0x3, 0xd, 0xd, 0x4, 0x3, 0x4, 0x4, 0x8, 0x9, 0x4, 0x3, 0x4, 0x4, 0x6, 
    0x7, 0x4, 0x3, 0x4, 0x4, 0xd, 0xd, 0x2, 0x91e, 0x2, 0xf5, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x100, 0x3, 0x2, 0x2, 0x2, 0x6, 0x110, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x115, 0x3, 0x2, 0x2, 0x2, 0xa, 0x11a, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0x133, 0x3, 0x2, 0x2, 0x2, 0xe, 0x137, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x139, 0x3, 0x2, 0x2, 0x2, 0x12, 0x142, 0x3, 0x2, 0x2, 0x2, 0x14, 0x152, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x162, 0x3, 0x2, 0x2, 0x2, 0x18, 0x176, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x192, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1bd, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x24, 0x1c6, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x28, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x1d0, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x1de, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x32, 0x1ea, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x36, 0x1f9, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x203, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x218, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x220, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x222, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x42, 0x233, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x235, 0x3, 0x2, 0x2, 0x2, 0x46, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x48, 0x245, 
    0x3, 0x2, 0x2, 0x2, 0x4a, 0x253, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x29c, 0x3, 
    0x2, 0x2, 0x2, 0x4e, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x2a4, 0x3, 0x2, 
    0x2, 0x2, 0x52, 0x2ab, 0x3, 0x2, 0x2, 0x2, 0x54, 0x2c5, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x58, 0x2cc, 0x3, 0x2, 0x2, 0x2, 
    0x5a, 0x2d7, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x5e, 
    0x317, 0x3, 0x2, 0x2, 0x2, 0x60, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x62, 0x330, 
    0x3, 0x2, 0x2, 0x2, 0x64, 0x332, 0x3, 0x2, 0x2, 0x2, 0x66, 0x358, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x390, 0x3, 0x2, 
    0x2, 0x2, 0x6c, 0x3ae, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x3b0, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x72, 0x3d2, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x3f0, 0x3, 0x2, 0x2, 0x2, 0x76, 0x3fe, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x401, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x403, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x406, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x42b, 0x3, 0x2, 0x2, 0x2, 0x80, 0x43a, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x43c, 0x3, 0x2, 0x2, 0x2, 0x84, 0x44d, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x458, 0x3, 0x2, 0x2, 0x2, 0x88, 0x45a, 0x3, 0x2, 0x2, 
    0x2, 0x8a, 0x45c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x45e, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x478, 0x3, 0x2, 0x2, 0x2, 0x90, 0x488, 0x3, 0x2, 0x2, 0x2, 0x92, 
    0x4a0, 0x3, 0x2, 0x2, 0x2, 0x94, 0x4c8, 0x3, 0x2, 0x2, 0x2, 0x96, 0x4e5, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x4f4, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x500, 0x3, 
    0x2, 0x2, 0x2, 0x9c, 0x51a, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x52c, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0x52e, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x531, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0x535, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x558, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0x565, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x567, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0x59f, 0x3, 0x2, 0x2, 0x2, 0xae, 0x5aa, 0x3, 0x2, 0x2, 0x2, 0xb0, 0x5b3, 
    0x3, 0x2, 0x2, 0x2, 0xb2, 0x5d6, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x5e3, 0x3, 
    0x2, 0x2, 0x2, 0xb6, 0x5e5, 0x3, 0x2, 0x2, 0x2, 0xb8, 0x5f4, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0x602, 0x3, 0x2, 0x2, 0x2, 0xbc, 0x61a, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0x61e, 0x3, 0x2, 0x2, 0x2, 0xc0, 0x620, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0x626, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x630, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0x633, 0x3, 0x2, 0x2, 0x2, 0xc8, 0x652, 0x3, 0x2, 0x2, 0x2, 0xca, 0x671, 
    0x3, 0x2, 0x2, 0x2, 0xcc, 0x690, 0x3, 0x2, 0x2, 0x2, 0xce, 0x6a1, 0x3, 
    0x2, 0x2, 0x2, 0xd0, 0x6c0, 0x3, 0x2, 0x2, 0x2, 0xd2, 0x6df, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0x70a, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x729, 0x3, 0x2, 0x2, 
    0x2, 0xd8, 0x7bd, 0x3, 0x2, 0x2, 0x2, 0xda, 0x7bf, 0x3, 0x2, 0x2, 0x2, 
    0xdc, 0x7c2, 0x3, 0x2, 0x2, 0x2, 0xde, 0x7c6, 0x3, 0x2, 0x2, 0x2, 0xe0, 
    0x7c8, 0x3, 0x2, 0x2, 0x2, 0xe2, 0x7ce, 0x3, 0x2, 0x2, 0x2, 0xe4, 0x7d4, 
    0x3, 0x2, 0x2, 0x2, 0xe6, 0x7e0, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x7e5, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0x7ea, 0x3, 0x2, 0x2, 0x2, 0xec, 0x7ef, 0x3, 0x2, 
    0x2, 0x2, 0xee, 0x7f3, 0x3, 0x2, 0x2, 0x2, 0xf0, 0x7f5, 0x3, 0x2, 0x2, 
    0x2, 0xf2, 0x7f7, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf6, 0x5, 0x4, 0x3, 0x2, 
    0xf5, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf7, 
    0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 
    0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x7, 0x2, 0x2, 0x3, 0xfa, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0x101, 0x5, 0x5a, 0x2e, 0x2, 0xfc, 0x101, 0x5, 
    0x58, 0x2d, 0x2, 0xfd, 0x101, 0x5, 0x62, 0x32, 0x2, 0xfe, 0x101, 0x5, 
    0x6, 0x4, 0x2, 0xff, 0x101, 0x5, 0xc, 0x7, 0x2, 0x100, 0xfb, 0x3, 0x2, 
    0x2, 0x2, 0x100, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfd, 0x3, 0x2, 0x2, 
    0x2, 0x100, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 
    0x101, 0x5, 0x3, 0x2, 0x2, 0x2, 0x102, 0x10b, 0x5, 0xb0, 0x59, 0x2, 
    0x103, 0x10c, 0x5, 0x8, 0x5, 0x2, 0x104, 0x106, 0x5, 0xda, 0x6e, 0x2, 
    0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 0x106, 0x109, 0x3, 0x2, 0x2, 0x2, 
    0x107, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 0x3, 0x2, 0x2, 0x2, 
    0x108, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 0x3, 0x2, 0x2, 0x2, 
    0x10a, 0x10c, 0x7, 0xd, 0x2, 0x2, 0x10b, 0x103, 0x3, 0x2, 0x2, 0x2, 
    0x10b, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x111, 0x3, 0x2, 0x2, 0x2, 
    0x10d, 0x10e, 0x5, 0x3a, 0x1e, 0x2, 0x10e, 0x10f, 0x5, 0x8, 0x5, 0x2, 
    0x10f, 0x111, 0x3, 0x2, 0x2, 0x2, 0x110, 0x102, 0x3, 0x2, 0x2, 0x2, 
    0x110, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x111, 0x7, 0x3, 0x2, 0x2, 0x2, 0x112, 
    0x114, 0x5, 0xda, 0x6e, 0x2, 0x113, 0x112, 0x3, 0x2, 0x2, 0x2, 0x114, 
    0x117, 0x3, 0x2, 0x2, 0x2, 0x115, 0x113, 0x3, 0x2, 0x2, 0x2, 0x115, 
    0x116, 0x3, 0x2, 0x2, 0x2, 0x116, 0x118, 0x3, 0x2, 0x2, 0x2, 0x117, 
    0x115, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x5, 0xa, 0x6, 0x2, 0x119, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11e, 0x7, 0xa, 0x2, 0x2, 0x11b, 0x11d, 
    0x5, 0xc, 0x7, 0x2, 0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x120, 
    0x3, 0x2, 0x2, 0x2, 0x11e, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x121, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11e, 
    0x3, 0x2, 0x2, 0x2, 0x121, 0x122, 0x7, 0xb, 0x2, 0x2, 0x122, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x123, 0x134, 0x5, 0xe, 0x8, 0x2, 0x124, 0x134, 0x5, 
    0xa, 0x6, 0x2, 0x125, 0x134, 0x5, 0x2e, 0x18, 0x2, 0x126, 0x134, 0x5, 
    0x90, 0x49, 0x2, 0x127, 0x134, 0x5, 0x14, 0xb, 0x2, 0x128, 0x134, 0x5, 
    0x30, 0x19, 0x2, 0x129, 0x134, 0x5, 0x6a, 0x36, 0x2, 0x12a, 0x134, 0x5, 
    0x6e, 0x38, 0x2, 0x12b, 0x134, 0x5, 0x4e, 0x28, 0x2, 0x12c, 0x134, 0x5, 
    0x3c, 0x1f, 0x2, 0x12d, 0x134, 0x5, 0x58, 0x2d, 0x2, 0x12e, 0x134, 0x5, 
    0x3e, 0x20, 0x2, 0x12f, 0x134, 0x5, 0x46, 0x24, 0x2, 0x130, 0x134, 0x5, 
    0xda, 0x6e, 0x2, 0x131, 0x134, 0x5, 0x5a, 0x2e, 0x2, 0x132, 0x134, 0x5, 
    0x4c, 0x27, 0x2, 0x133, 0x123, 0x3, 0x2, 0x2, 0x2, 0x133, 0x124, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x125, 0x3, 0x2, 0x2, 0x2, 0x133, 0x126, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x127, 0x3, 0x2, 0x2, 0x2, 0x133, 0x128, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x129, 0x3, 0x2, 0x2, 0x2, 0x133, 0x12a, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x133, 0x12c, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x133, 0x12e, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x133, 0x130, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 0x132, 0x3, 
    0x2, 0x2, 0x2, 0x134, 0xd, 0x3, 0x2, 0x2, 0x2, 0x135, 0x138, 0x5, 0x10, 
    0x9, 0x2, 0x136, 0x138, 0x5, 0x12, 0xa, 0x2, 0x137, 0x135, 0x3, 0x2, 
    0x2, 0x2, 0x137, 0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x139, 0x13d, 0x7, 0x3c, 0x2, 0x2, 0x13a, 0x13c, 0x5, 0xda, 0x6e, 
    0x2, 0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13f, 0x3, 0x2, 0x2, 
    0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x3, 0x2, 0x2, 
    0x2, 0x13e, 0x140, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 
    0x2, 0x140, 0x141, 0x7, 0xd, 0x2, 0x2, 0x141, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x142, 0x146, 0x7, 0x3c, 0x2, 0x2, 0x143, 0x145, 0x5, 0xda, 0x6e, 0x2, 
    0x144, 0x143, 0x3, 0x2, 0x2, 0x2, 0x145, 0x148, 0x3, 0x2, 0x2, 0x2, 
    0x146, 0x144, 0x3, 0x2, 0x2, 0x2, 0x146, 0x147, 0x3, 0x2, 0x2, 0x2, 
    0x147, 0x149, 0x3, 0x2, 0x2, 0x2, 0x148, 0x146, 0x3, 0x2, 0x2, 0x2, 
    0x149, 0x14d, 0x5, 0x22, 0x12, 0x2, 0x14a, 0x14c, 0x5, 0xda, 0x6e, 0x2, 
    0x14b, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14f, 0x3, 0x2, 0x2, 0x2, 
    0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 0x2, 0x2, 
    0x14e, 0x150, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 0x2, 
    0x150, 0x151, 0x7, 0xd, 0x2, 0x2, 0x151, 0x13, 0x3, 0x2, 0x2, 0x2, 0x152, 
    0x156, 0x7, 0x3d, 0x2, 0x2, 0x153, 0x155, 0x5, 0xda, 0x6e, 0x2, 0x154, 
    0x153, 0x3, 0x2, 0x2, 0x2, 0x155, 0x158, 0x3, 0x2, 0x2, 0x2, 0x156, 
    0x154, 0x3, 0x2, 0x2, 0x2, 0x156, 0x157, 0x3, 0x2, 0x2, 0x2, 0x157, 
    0x159, 0x3, 0x2, 0x2, 0x2, 0x158, 0x156, 0x3, 0x2, 0x2, 0x2, 0x159, 
    0x15a, 0x7, 0x8, 0x2, 0x2, 0x15a, 0x15b, 0x5, 0x16, 0xc, 0x2, 0x15b, 
    0x15c, 0x5, 0x1a, 0xe, 0x2, 0x15c, 0x15d, 0x5, 0x1c, 0xf, 0x2, 0x15d, 
    0x15e, 0x7, 0x9, 0x2, 0x2, 0x15e, 0x15, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x161, 
    0x5, 0xda, 0x6e, 0x2, 0x160, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x161, 0x164, 
    0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 
    0x3, 0x2, 0x2, 0x2, 0x163, 0x167, 0x3, 0x2, 0x2, 0x2, 0x164, 0x162, 
    0x3, 0x2, 0x2, 0x2, 0x165, 0x168, 0x5, 0x18, 0xd, 0x2, 0x166, 0x168, 
    0x5, 0x6a, 0x36, 0x2, 0x167, 0x165, 0x3, 0x2, 0x2, 0x2, 0x167, 0x166, 
    0x3, 0x2, 0x2, 0x2, 0x168, 0x17, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16d, 0x5, 
    0x92, 0x4a, 0x2, 0x16a, 0x16c, 0x5, 0x94, 0x4b, 0x2, 0x16b, 0x16a, 0x3, 
    0x2, 0x2, 0x2, 0x16c, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16b, 0x3, 
    0x2, 0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x173, 0x3, 
    0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x170, 0x172, 0x5, 
    0xda, 0x6e, 0x2, 0x171, 0x170, 0x3, 0x2, 0x2, 0x2, 0x172, 0x175, 0x3, 
    0x2, 0x2, 0x2, 0x173, 0x171, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 0x3, 
    0x2, 0x2, 0x2, 0x174, 0x177, 0x3, 0x2, 0x2, 0x2, 0x175, 0x173, 0x3, 
    0x2, 0x2, 0x2, 0x176, 0x169, 0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x3, 
    0x2, 0x2, 0x2, 0x177, 0x178, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x7, 
    0xd, 0x2, 0x2, 0x179, 0x19, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17c, 0x5, 0xda, 
    0x6e, 0x2, 0x17b, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x17f, 0x3, 0x2, 
    0x2, 0x2, 0x17d, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 0x3, 0x2, 
    0x2, 0x2, 0x17e, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17d, 0x3, 0x2, 
    0x2, 0x2, 0x180, 0x182, 0x5, 0x20, 0x11, 0x2, 0x181, 0x180, 0x3, 0x2, 
    0x2, 0x2, 0x182, 0x183, 0x3, 0x2, 0x2, 0x2, 0x183, 0x181, 0x3, 0x2, 
    0x2, 0x2, 0x183, 0x184, 0x3, 0x2, 0x2, 0x2, 0x184, 0x188, 0x3, 0x2, 
    0x2, 0x2, 0x185, 0x187, 0x5, 0xda, 0x6e, 0x2, 0x186, 0x185, 0x3, 0x2, 
    0x2, 0x2, 0x187, 0x18a, 0x3, 0x2, 0x2, 0x2, 0x188, 0x186, 0x3, 0x2, 
    0x2, 0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18c, 0x3, 0x2, 
    0x2, 0x2, 0x18a, 0x188, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x181, 0x3, 0x2, 
    0x2, 0x2, 0x18b, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18d, 0x3, 0x2, 
    0x2, 0x2, 0x18d, 0x18e, 0x7, 0xd, 0x2, 0x2, 0x18e, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x18f, 0x191, 0x5, 0xda, 0x6e, 0x2, 0x190, 0x18f, 0x3, 0x2, 0x2, 
    0x2, 0x191, 0x194, 0x3, 0x2, 0x2, 0x2, 0x192, 0x190, 0x3, 0x2, 0x2, 
    0x2, 0x192, 0x193, 0x3, 0x2, 0x2, 0x2, 0x193, 0x1a2, 0x3, 0x2, 0x2, 
    0x2, 0x194, 0x192, 0x3, 0x2, 0x2, 0x2, 0x195, 0x199, 0x5, 0x6c, 0x37, 
    0x2, 0x196, 0x198, 0x5, 0x1e, 0x10, 0x2, 0x197, 0x196, 0x3, 0x2, 0x2, 
    0x2, 0x198, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x199, 0x197, 0x3, 0x2, 0x2, 
    0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19f, 0x3, 0x2, 0x2, 
    0x2, 0x19b, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19e, 0x5, 0xda, 0x6e, 
    0x2, 0x19d, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x1a1, 0x3, 0x2, 0x2, 
    0x2, 0x19f, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x3, 0x2, 0x2, 
    0x2, 0x1a0, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x19f, 0x3, 0x2, 0x2, 
    0x2, 0x1a2, 0x195, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x3, 0x2, 0x2, 
    0x2, 0x1a3, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a6, 0x5, 0xda, 0x6e, 
    0x2, 0x1a5, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a9, 0x3, 0x2, 0x2, 
    0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 0x2, 0x2, 
    0x2, 0x1a8, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 0x2, 0x2, 
    0x2, 0x1aa, 0x1ae, 0x7, 0x4, 0x2, 0x2, 0x1ab, 0x1ad, 0x5, 0xda, 0x6e, 
    0x2, 0x1ac, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1b0, 0x3, 0x2, 0x2, 
    0x2, 0x1ae, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x3, 0x2, 0x2, 
    0x2, 0x1af, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1ae, 0x3, 0x2, 0x2, 
    0x2, 0x1b1, 0x1b2, 0x5, 0x6c, 0x37, 0x2, 0x1b2, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x1b3, 0x1be, 0x5, 0x30, 0x19, 0x2, 0x1b4, 0x1be, 0x5, 0x6e, 0x38, 
    0x2, 0x1b5, 0x1be, 0x5, 0x4e, 0x28, 0x2, 0x1b6, 0x1be, 0x5, 0x3e, 0x20, 
    0x2, 0x1b7, 0x1be, 0x5, 0x6a, 0x36, 0x2, 0x1b8, 0x1be, 0x5, 0x46, 0x24, 
    0x2, 0x1b9, 0x1be, 0x5, 0x22, 0x12, 0x2, 0x1ba, 0x1be, 0x5, 0xd8, 0x6d, 
    0x2, 0x1bb, 0x1be, 0x5, 0x3c, 0x1f, 0x2, 0x1bc, 0x1be, 0x5, 0x28, 0x15, 
    0x2, 0x1bd, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1b4, 0x3, 0x2, 0x2, 
    0x2, 0x1bd, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1b6, 0x3, 0x2, 0x2, 
    0x2, 0x1bd, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1b8, 0x3, 0x2, 0x2, 
    0x2, 0x1bd, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1ba, 0x3, 0x2, 0x2, 
    0x2, 0x1bd, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1bc, 0x3, 0x2, 0x2, 
    0x2, 0x1be, 0x21, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c1, 0x7, 0x8, 0x2, 0x2, 
    0x1c0, 0x1c2, 0x5, 0x24, 0x13, 0x2, 0x1c1, 0x1c0, 0x3, 0x2, 0x2, 0x2, 
    0x1c1, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x3, 0x2, 0x2, 0x2, 
    0x1c3, 0x1c4, 0x7, 0x9, 0x2, 0x2, 0x1c4, 0x23, 0x3, 0x2, 0x2, 0x2, 0x1c5, 
    0x1c7, 0x5, 0x26, 0x14, 0x2, 0x1c6, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c7, 
    0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c8, 
    0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c9, 0x25, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cd, 
    0x5, 0x20, 0x11, 0x2, 0x1cb, 0x1cd, 0x5, 0x2a, 0x16, 0x2, 0x1cc, 0x1ca, 
    0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0x1ce, 0x1cf, 0xa, 0x2, 0x2, 0x2, 0x1cf, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x1d0, 0x1d1, 0xa, 0x3, 0x2, 0x2, 0x1d1, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0x1d2, 0x1db, 0x5, 0x2e, 0x18, 0x2, 0x1d3, 0x1db, 0x5, 0x30, 0x19, 
    0x2, 0x1d4, 0x1db, 0x5, 0x6e, 0x38, 0x2, 0x1d5, 0x1db, 0x5, 0x4e, 0x28, 
    0x2, 0x1d6, 0x1db, 0x5, 0x3c, 0x1f, 0x2, 0x1d7, 0x1db, 0x5, 0xd8, 0x6d, 
    0x2, 0x1d8, 0x1db, 0x5, 0x6a, 0x36, 0x2, 0x1d9, 0x1db, 0x5, 0xda, 0x6e, 
    0x2, 0x1da, 0x1d2, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d3, 0x3, 0x2, 0x2, 
    0x2, 0x1da, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d5, 0x3, 0x2, 0x2, 
    0x2, 0x1da, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d7, 0x3, 0x2, 0x2, 
    0x2, 0x1da, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1d9, 0x3, 0x2, 0x2, 
    0x2, 0x1db, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1df, 0x5, 0xe0, 0x71, 
    0x2, 0x1dd, 0x1df, 0x5, 0xe2, 0x72, 0x2, 0x1de, 0x1dc, 0x3, 0x2, 0x2, 
    0x2, 0x1de, 0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x1e0, 0x1e9, 0x5, 0xae, 0x58, 0x2, 0x1e1, 0x1e9, 0x5, 0x82, 0x42, 0x2, 
    0x1e2, 0x1e9, 0x5, 0x84, 0x43, 0x2, 0x1e3, 0x1e9, 0x5, 0x8a, 0x46, 0x2, 
    0x1e4, 0x1e9, 0x5, 0x8c, 0x47, 0x2, 0x1e5, 0x1e9, 0x5, 0xaa, 0x56, 0x2, 
    0x1e6, 0x1e9, 0x5, 0xac, 0x57, 0x2, 0x1e7, 0x1e9, 0x5, 0x32, 0x1a, 0x2, 
    0x1e8, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e1, 0x3, 0x2, 0x2, 0x2, 
    0x1e8, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e3, 0x3, 0x2, 0x2, 0x2, 
    0x1e8, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e5, 0x3, 0x2, 0x2, 0x2, 
    0x1e8, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1e7, 0x3, 0x2, 0x2, 0x2, 
    0x1e9, 0x31, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1ee, 0x5, 0xd8, 0x6d, 0x2, 
    0x1eb, 0x1ed, 0x5, 0xda, 0x6e, 0x2, 0x1ec, 0x1eb, 0x3, 0x2, 0x2, 0x2, 
    0x1ed, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ec, 0x3, 0x2, 0x2, 0x2, 
    0x1ee, 0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f1, 0x3, 0x2, 0x2, 0x2, 
    0x1f0, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f2, 0x5, 0x34, 0x1b, 0x2, 
    0x1f2, 0x33, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f5, 0x7, 0x8, 0x2, 0x2, 0x1f4, 
    0x1f6, 0x5, 0x36, 0x1c, 0x2, 0x1f5, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f5, 
    0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f7, 
    0x1f8, 0x7, 0x9, 0x2, 0x2, 0x1f8, 0x35, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fd, 
    0x5, 0x20, 0x11, 0x2, 0x1fa, 0x1fc, 0x5, 0x38, 0x1d, 0x2, 0x1fb, 0x1fa, 
    0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fb, 
    0x3, 0x2, 0x2, 0x2, 0x1fd, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x1ff, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x200, 0x202, 0x5, 
    0xda, 0x6e, 0x2, 0x201, 0x200, 0x3, 0x2, 0x2, 0x2, 0x202, 0x205, 0x3, 
    0x2, 0x2, 0x2, 0x203, 0x201, 0x3, 0x2, 0x2, 0x2, 0x203, 0x204, 0x3, 
    0x2, 0x2, 0x2, 0x204, 0x206, 0x3, 0x2, 0x2, 0x2, 0x205, 0x203, 0x3, 
    0x2, 0x2, 0x2, 0x206, 0x20a, 0x7, 0x4, 0x2, 0x2, 0x207, 0x209, 0x5, 
    0xda, 0x6e, 0x2, 0x208, 0x207, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20c, 0x3, 
    0x2, 0x2, 0x2, 0x20a, 0x208, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x20b, 0x3, 
    0x2, 0x2, 0x2, 0x20b, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20a, 0x3, 
    0x2, 0x2, 0x2, 0x20d, 0x20e, 0x5, 0x20, 0x11, 0x2, 0x20e, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x20f, 0x219, 0x5, 0xc6, 0x64, 0x2, 0x210, 0x219, 0x5, 
    0xc8, 0x65, 0x2, 0x211, 0x219, 0x5, 0xca, 0x66, 0x2, 0x212, 0x219, 0x5, 
    0xcc, 0x67, 0x2, 0x213, 0x219, 0x5, 0xce, 0x68, 0x2, 0x214, 0x219, 0x5, 
    0xd0, 0x69, 0x2, 0x215, 0x219, 0x5, 0xd2, 0x6a, 0x2, 0x216, 0x219, 0x5, 
    0xd4, 0x6b, 0x2, 0x217, 0x219, 0x5, 0xd6, 0x6c, 0x2, 0x218, 0x20f, 0x3, 
    0x2, 0x2, 0x2, 0x218, 0x210, 0x3, 0x2, 0x2, 0x2, 0x218, 0x211, 0x3, 
    0x2, 0x2, 0x2, 0x218, 0x212, 0x3, 0x2, 0x2, 0x2, 0x218, 0x213, 0x3, 
    0x2, 0x2, 0x2, 0x218, 0x214, 0x3, 0x2, 0x2, 0x2, 0x218, 0x215, 0x3, 
    0x2, 0x2, 0x2, 0x218, 0x216, 0x3, 0x2, 0x2, 0x2, 0x218, 0x217, 0x3, 
    0x2, 0x2, 0x2, 0x219, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x21a, 0x221, 0x7, 0x57, 
    0x2, 0x2, 0x21b, 0x221, 0x7, 0x58, 0x2, 0x2, 0x21c, 0x221, 0x7, 0x59, 
    0x2, 0x2, 0x21d, 0x221, 0x7, 0x2a, 0x2, 0x2, 0x21e, 0x221, 0x5, 0x86, 
    0x44, 0x2, 0x21f, 0x221, 0x5, 0x88, 0x45, 0x2, 0x220, 0x21a, 0x3, 0x2, 
    0x2, 0x2, 0x220, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x220, 0x21c, 0x3, 0x2, 
    0x2, 0x2, 0x220, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x220, 0x21e, 0x3, 0x2, 
    0x2, 0x2, 0x220, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x221, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x222, 0x228, 0x7, 0x63, 0x2, 0x2, 0x223, 0x229, 0x5, 0x44, 0x23, 
    0x2, 0x224, 0x226, 0x5, 0x42, 0x22, 0x2, 0x225, 0x227, 0x5, 0x40, 0x21, 
    0x2, 0x226, 0x225, 0x3, 0x2, 0x2, 0x2, 0x226, 0x227, 0x3, 0x2, 0x2, 
    0x2, 0x227, 0x229, 0x3, 0x2, 0x2, 0x2, 0x228, 0x223, 0x3, 0x2, 0x2, 
    0x2, 0x228, 0x224, 0x3, 0x2, 0x2, 0x2, 0x228, 0x229, 0x3, 0x2, 0x2, 
    0x2, 0x229, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22a, 0x22b, 0x7, 0xf, 0x2, 
    0x2, 0x22b, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x22c, 0x22e, 0x5, 0xda, 0x6e, 
    0x2, 0x22d, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x22e, 0x22f, 0x3, 0x2, 0x2, 
    0x2, 0x22f, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x22f, 0x230, 0x3, 0x2, 0x2, 
    0x2, 0x230, 0x231, 0x3, 0x2, 0x2, 0x2, 0x231, 0x232, 0x5, 0x44, 0x23, 
    0x2, 0x232, 0x41, 0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x7, 0x6a, 0x2, 
    0x2, 0x234, 0x43, 0x3, 0x2, 0x2, 0x2, 0x235, 0x23c, 0x7, 0x68, 0x2, 
    0x2, 0x236, 0x237, 0x7, 0xc, 0x2, 0x2, 0x237, 0x23a, 0x7, 0x68, 0x2, 
    0x2, 0x238, 0x239, 0x7, 0xc, 0x2, 0x2, 0x239, 0x23b, 0x7, 0x68, 0x2, 
    0x2, 0x23a, 0x238, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x23b, 0x3, 0x2, 0x2, 
    0x2, 0x23b, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x236, 0x3, 0x2, 0x2, 
    0x2, 0x23c, 0x23d, 0x3, 0x2, 0x2, 0x2, 0x23d, 0x45, 0x3, 0x2, 0x2, 0x2, 
    0x23e, 0x23f, 0x7, 0x64, 0x2, 0x2, 0x23f, 0x240, 0x5, 0x48, 0x25, 0x2, 
    0x240, 0x241, 0x7, 0xf, 0x2, 0x2, 0x241, 0x47, 0x3, 0x2, 0x2, 0x2, 0x242, 
    0x244, 0x5, 0xda, 0x6e, 0x2, 0x243, 0x242, 0x3, 0x2, 0x2, 0x2, 0x244, 
    0x247, 0x3, 0x2, 0x2, 0x2, 0x245, 0x243, 0x3, 0x2, 0x2, 0x2, 0x245, 
    0x246, 0x3, 0x2, 0x2, 0x2, 0x246, 0x248, 0x3, 0x2, 0x2, 0x2, 0x247, 
    0x245, 0x3, 0x2, 0x2, 0x2, 0x248, 0x249, 0x5, 0x4a, 0x26, 0x2, 0x249, 
    0x24a, 0x5, 0x8e, 0x48, 0x2, 0x24a, 0x24b, 0x5, 0x4a, 0x26, 0x2, 0x24b, 
    0x24c, 0x5, 0x8e, 0x48, 0x2, 0x24c, 0x250, 0x5, 0x4a, 0x26, 0x2, 0x24d, 
    0x24f, 0x5, 0xda, 0x6e, 0x2, 0x24e, 0x24d, 0x3, 0x2, 0x2, 0x2, 0x24f, 
    0x252, 0x3, 0x2, 0x2, 0x2, 0x250, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x250, 
    0x251, 0x3, 0x2, 0x2, 0x2, 0x251, 0x49, 0x3, 0x2, 0x2, 0x2, 0x252, 0x250, 
    0x3, 0x2, 0x2, 0x2, 0x253, 0x254, 0x9, 0x4, 0x2, 0x2, 0x254, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x255, 0x29d, 0x7, 0x6f, 0x2, 0x2, 0x256, 0x29d, 0x7, 
    0x6e, 0x2, 0x2, 0x257, 0x29d, 0x7, 0xd, 0x2, 0x2, 0x258, 0x29d, 0x7, 
    0xc, 0x2, 0x2, 0x259, 0x29d, 0x7, 0x4, 0x2, 0x2, 0x25a, 0x29d, 0x7, 
    0x5, 0x2, 0x2, 0x25b, 0x29d, 0x7, 0x1b, 0x2, 0x2, 0x25c, 0x29d, 0x7, 
    0x3, 0x2, 0x2, 0x25d, 0x29d, 0x7, 0x10, 0x2, 0x2, 0x25e, 0x29d, 0x7, 
    0x15, 0x2, 0x2, 0x25f, 0x29d, 0x7, 0x16, 0x2, 0x2, 0x260, 0x29d, 0x7, 
    0x17, 0x2, 0x2, 0x261, 0x29d, 0x7, 0x18, 0x2, 0x2, 0x262, 0x29d, 0x7, 
    0x19, 0x2, 0x2, 0x263, 0x29d, 0x7, 0x1a, 0x2, 0x2, 0x264, 0x29d, 0x7, 
    0x8, 0x2, 0x2, 0x265, 0x29d, 0x7, 0x9, 0x2, 0x2, 0x266, 0x29d, 0x7, 
    0x11, 0x2, 0x2, 0x267, 0x29d, 0x7, 0x12, 0x2, 0x2, 0x268, 0x29d, 0x7, 
    0x13, 0x2, 0x2, 0x269, 0x29d, 0x7, 0x14, 0x2, 0x2, 0x26a, 0x29d, 0x7, 
    0x66, 0x2, 0x2, 0x26b, 0x29d, 0x7, 0x31, 0x2, 0x2, 0x26c, 0x29d, 0x7, 
    0x32, 0x2, 0x2, 0x26d, 0x29d, 0x7, 0x30, 0x2, 0x2, 0x26e, 0x29d, 0x7, 
    0x33, 0x2, 0x2, 0x26f, 0x29d, 0x7, 0x34, 0x2, 0x2, 0x270, 0x29d, 0x7, 
    0x36, 0x2, 0x2, 0x271, 0x29d, 0x7, 0x35, 0x2, 0x2, 0x272, 0x29d, 0x7, 
    0x37, 0x2, 0x2, 0x273, 0x29d, 0x7, 0x38, 0x2, 0x2, 0x274, 0x29d, 0x7, 
    0x39, 0x2, 0x2, 0x275, 0x29d, 0x7, 0x3c, 0x2, 0x2, 0x276, 0x29d, 0x7, 
    0x3a, 0x2, 0x2, 0x277, 0x29d, 0x7, 0x3b, 0x2, 0x2, 0x278, 0x29d, 0x7, 
    0x3e, 0x2, 0x2, 0x279, 0x29d, 0x7, 0x3d, 0x2, 0x2, 0x27a, 0x29d, 0x7, 
    0x41, 0x2, 0x2, 0x27b, 0x29d, 0x7, 0x43, 0x2, 0x2, 0x27c, 0x29d, 0x7, 
    0x44, 0x2, 0x2, 0x27d, 0x29d, 0x7, 0x4a, 0x2, 0x2, 0x27e, 0x29d, 0x7, 
    0x3f, 0x2, 0x2, 0x27f, 0x29d, 0x7, 0x46, 0x2, 0x2, 0x280, 0x29d, 0x7, 
    0x47, 0x2, 0x2, 0x281, 0x29d, 0x7, 0x42, 0x2, 0x2, 0x282, 0x29d, 0x7, 
    0x48, 0x2, 0x2, 0x283, 0x29d, 0x7, 0x49, 0x2, 0x2, 0x284, 0x29d, 0x7, 
    0x63, 0x2, 0x2, 0x285, 0x29d, 0x7, 0x64, 0x2, 0x2, 0x286, 0x29d, 0x7, 
    0x6a, 0x2, 0x2, 0x287, 0x29d, 0x7, 0xf, 0x2, 0x2, 0x288, 0x29d, 0x5, 
    0x4a, 0x26, 0x2, 0x289, 0x29d, 0x5, 0xde, 0x70, 0x2, 0x28a, 0x29d, 0x7, 
    0x5f, 0x2, 0x2, 0x28b, 0x29d, 0x7, 0x62, 0x2, 0x2, 0x28c, 0x29d, 0x7, 
    0x60, 0x2, 0x2, 0x28d, 0x29d, 0x7, 0x61, 0x2, 0x2, 0x28e, 0x29d, 0x5, 
    0xd8, 0x6d, 0x2, 0x28f, 0x29d, 0x5, 0x5c, 0x2f, 0x2, 0x290, 0x29d, 0x7, 
    0x4b, 0x2, 0x2, 0x291, 0x29d, 0x7, 0x55, 0x2, 0x2, 0x292, 0x29d, 0x7, 
    0x4d, 0x2, 0x2, 0x293, 0x29d, 0x7, 0x4c, 0x2, 0x2, 0x294, 0x29d, 0x7, 
    0x51, 0x2, 0x2, 0x295, 0x29d, 0x7, 0x52, 0x2, 0x2, 0x296, 0x29d, 0x7, 
    0x56, 0x2, 0x2, 0x297, 0x29d, 0x7, 0x53, 0x2, 0x2, 0x298, 0x29d, 0x7, 
    0x54, 0x2, 0x2, 0x299, 0x29d, 0x7, 0x5a, 0x2, 0x2, 0x29a, 0x29d, 0x7, 
    0x5b, 0x2, 0x2, 0x29b, 0x29d, 0x7, 0x5c, 0x2, 0x2, 0x29c, 0x255, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x256, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x257, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x258, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x259, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x25b, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x25c, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x25d, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x25e, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x25f, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x260, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x261, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x262, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x263, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x264, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x265, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x266, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x267, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x268, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x269, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x26b, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x26c, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x26d, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x26e, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x26f, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x270, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x271, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x272, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x273, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x274, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x275, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x276, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x277, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x278, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x279, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x27a, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x27b, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x27c, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x27d, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x27e, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x27f, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x280, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x281, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x282, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x283, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x284, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x285, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x286, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x287, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x288, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x289, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x28a, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x28b, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x28d, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x28e, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x28f, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x290, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x291, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x292, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x293, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x294, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x295, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x296, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x297, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x298, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x299, 0x3, 
    0x2, 0x2, 0x2, 0x29c, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29b, 0x3, 
    0x2, 0x2, 0x2, 0x29d, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x29e, 0x2a0, 0x7, 0x6, 
    0x2, 0x2, 0x29f, 0x2a1, 0x5, 0x50, 0x29, 0x2, 0x2a0, 0x29f, 0x3, 0x2, 
    0x2, 0x2, 0x2a0, 0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a2, 0x3, 0x2, 
    0x2, 0x2, 0x2a2, 0x2a3, 0x7, 0x7, 0x2, 0x2, 0x2a3, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x2a4, 0x2a8, 0x5, 0x54, 0x2b, 0x2, 0x2a5, 0x2a7, 0x5, 0x52, 0x2a, 
    0x2, 0x2a6, 0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a7, 0x2aa, 0x3, 0x2, 0x2, 
    0x2, 0x2a8, 0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2a9, 0x3, 0x2, 0x2, 
    0x2, 0x2a9, 0x51, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2a8, 0x3, 0x2, 0x2, 0x2, 
    0x2ab, 0x2ac, 0x7, 0x4, 0x2, 0x2, 0x2ac, 0x2ad, 0x5, 0x54, 0x2b, 0x2, 
    0x2ad, 0x53, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2b2, 0x5, 0x56, 0x2c, 0x2, 
    0x2af, 0x2b1, 0x5, 0xda, 0x6e, 0x2, 0x2b0, 0x2af, 0x3, 0x2, 0x2, 0x2, 
    0x2b1, 0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b0, 0x3, 0x2, 0x2, 0x2, 
    0x2b2, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b3, 0x2bc, 0x3, 0x2, 0x2, 0x2, 
    0x2b4, 0x2b2, 0x3, 0x2, 0x2, 0x2, 0x2b5, 0x2b9, 0x5, 0xc0, 0x61, 0x2, 
    0x2b6, 0x2b8, 0x5, 0x56, 0x2c, 0x2, 0x2b7, 0x2b6, 0x3, 0x2, 0x2, 0x2, 
    0x2b8, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2b7, 0x3, 0x2, 0x2, 0x2, 
    0x2b9, 0x2ba, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bd, 0x3, 0x2, 0x2, 0x2, 
    0x2bb, 0x2b9, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2b5, 0x3, 0x2, 0x2, 0x2, 
    0x2bd, 0x2be, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bc, 0x3, 0x2, 0x2, 0x2, 
    0x2be, 0x2bf, 0x3, 0x2, 0x2, 0x2, 0x2bf, 0x2c6, 0x3, 0x2, 0x2, 0x2, 
    0x2c0, 0x2c2, 0x5, 0x56, 0x2c, 0x2, 0x2c1, 0x2c0, 0x3, 0x2, 0x2, 0x2, 
    0x2c2, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c1, 0x3, 0x2, 0x2, 0x2, 
    0x2c3, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c4, 0x2c6, 0x3, 0x2, 0x2, 0x2, 
    0x2c5, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c1, 0x3, 0x2, 0x2, 0x2, 
    0x2c6, 0x55, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2cb, 0x5, 0x2c, 0x17, 0x2, 
    0x2c8, 0x2cb, 0x5, 0x22, 0x12, 0x2, 0x2c9, 0x2cb, 0x5, 0xf0, 0x79, 0x2, 
    0x2ca, 0x2c7, 0x3, 0x2, 0x2, 0x2, 0x2ca, 0x2c8, 0x3, 0x2, 0x2, 0x2, 
    0x2ca, 0x2c9, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x57, 0x3, 0x2, 0x2, 0x2, 0x2cc, 
    0x2d0, 0x7, 0x3, 0x2, 0x2, 0x2cd, 0x2cf, 0x7, 0x22, 0x2, 0x2, 0x2ce, 
    0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cf, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d0, 
    0x2ce, 0x3, 0x2, 0x2, 0x2, 0x2d0, 0x2d1, 0x3, 0x2, 0x2, 0x2, 0x2d1, 
    0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d2, 0x2d0, 0x3, 0x2, 0x2, 0x2, 0x2d3, 
    0x2d5, 0x5, 0xd8, 0x6d, 0x2, 0x2d4, 0x2d6, 0x5, 0xe8, 0x75, 0x2, 0x2d5, 
    0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d5, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d6, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2db, 0x7, 0x3, 0x2, 0x2, 0x2d8, 0x2da, 
    0x7, 0x22, 0x2, 0x2, 0x2d9, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2dd, 
    0x3, 0x2, 0x2, 0x2, 0x2db, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dc, 
    0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2db, 
    0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 0x7, 0x4b, 0x2, 0x2, 0x2df, 0x2e0, 
    0x5, 0x5e, 0x30, 0x2, 0x2e0, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x2e1, 0x2e2, 
    0x7, 0x65, 0x2, 0x2, 0x2e2, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e5, 
    0x7, 0x22, 0x2, 0x2, 0x2e4, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e6, 
    0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e7, 
    0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2ea, 
    0x7, 0x55, 0x2, 0x2, 0x2e9, 0x2eb, 0x7, 0x22, 0x2, 0x2, 0x2ea, 0x2e9, 
    0x3, 0x2, 0x2, 0x2, 0x2eb, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ea, 
    0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ed, 0x3, 0x2, 0x2, 0x2, 0x2ed, 0x2ee, 
    0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2f2, 0x7, 0x68, 0x2, 0x2, 0x2ef, 0x2f1, 
    0x7, 0x22, 0x2, 0x2, 0x2f0, 0x2ef, 0x3, 0x2, 0x2, 0x2, 0x2f1, 0x2f4, 
    0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f0, 0x3, 0x2, 0x2, 0x2, 0x2f2, 0x2f3, 
    0x3, 0x2, 0x2, 0x2, 0x2f3, 0x318, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f2, 
    0x3, 0x2, 0x2, 0x2, 0x2f5, 0x2f7, 0x7, 0x22, 0x2, 0x2, 0x2f6, 0x2f5, 
    0x3, 0x2, 0x2, 0x2, 0x2f7, 0x2f8, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f6, 
    0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2f9, 0x2fa, 
    0x3, 0x2, 0x2, 0x2, 0x2fa, 0x2fe, 0x7, 0x4d, 0x2, 0x2, 0x2fb, 0x2fd, 
    0x7, 0x22, 0x2, 0x2, 0x2fc, 0x2fb, 0x3, 0x2, 0x2, 0x2, 0x2fd, 0x300, 
    0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x2fe, 0x2ff, 
    0x3, 0x2, 0x2, 0x2, 0x2ff, 0x318, 0x3, 0x2, 0x2, 0x2, 0x300, 0x2fe, 
    0x3, 0x2, 0x2, 0x2, 0x301, 0x303, 0x7, 0x22, 0x2, 0x2, 0x302, 0x301, 
    0x3, 0x2, 0x2, 0x2, 0x303, 0x304, 0x3, 0x2, 0x2, 0x2, 0x304, 0x302, 
    0x3, 0x2, 0x2, 0x2, 0x304, 0x305, 0x3, 0x2, 0x2, 0x2, 0x305, 0x306, 
    0x3, 0x2, 0x2, 0x2, 0x306, 0x30a, 0x7, 0x4c, 0x2, 0x2, 0x307, 0x309, 
    0x7, 0x22, 0x2, 0x2, 0x308, 0x307, 0x3, 0x2, 0x2, 0x2, 0x309, 0x30c, 
    0x3, 0x2, 0x2, 0x2, 0x30a, 0x308, 0x3, 0x2, 0x2, 0x2, 0x30a, 0x30b, 
    0x3, 0x2, 0x2, 0x2, 0x30b, 0x318, 0x3, 0x2, 0x2, 0x2, 0x30c, 0x30a, 
    0x3, 0x2, 0x2, 0x2, 0x30d, 0x30f, 0x7, 0x22, 0x2, 0x2, 0x30e, 0x30d, 
    0x3, 0x2, 0x2, 0x2, 0x30f, 0x310, 0x3, 0x2, 0x2, 0x2, 0x310, 0x30e, 
    0x3, 0x2, 0x2, 0x2, 0x310, 0x311, 0x3, 0x2, 0x2, 0x2, 0x311, 0x312, 
    0x3, 0x2, 0x2, 0x2, 0x312, 0x318, 0x7, 0x34, 0x2, 0x2, 0x313, 0x318, 
    0x5, 0x60, 0x31, 0x2, 0x314, 0x316, 0x5, 0xe8, 0x75, 0x2, 0x315, 0x314, 
    0x3, 0x2, 0x2, 0x2, 0x315, 0x316, 0x3, 0x2, 0x2, 0x2, 0x316, 0x318, 
    0x3, 0x2, 0x2, 0x2, 0x317, 0x2e4, 0x3, 0x2, 0x2, 0x2, 0x317, 0x2f6, 
    0x3, 0x2, 0x2, 0x2, 0x317, 0x302, 0x3, 0x2, 0x2, 0x2, 0x317, 0x30e, 
    0x3, 0x2, 0x2, 0x2, 0x317, 0x313, 0x3, 0x2, 0x2, 0x2, 0x317, 0x315, 
    0x3, 0x2, 0x2, 0x2, 0x318, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x319, 0x31b, 0x7, 
    0x22, 0x2, 0x2, 0x31a, 0x319, 0x3, 0x2, 0x2, 0x2, 0x31b, 0x31c, 0x3, 
    0x2, 0x2, 0x2, 0x31c, 0x31a, 0x3, 0x2, 0x2, 0x2, 0x31c, 0x31d, 0x3, 
    0x2, 0x2, 0x2, 0x31d, 0x31e, 0x3, 0x2, 0x2, 0x2, 0x31e, 0x320, 0x5, 
    0xd8, 0x6d, 0x2, 0x31f, 0x321, 0x7, 0x22, 0x2, 0x2, 0x320, 0x31f, 0x3, 
    0x2, 0x2, 0x2, 0x321, 0x322, 0x3, 0x2, 0x2, 0x2, 0x322, 0x320, 0x3, 
    0x2, 0x2, 0x2, 0x322, 0x323, 0x3, 0x2, 0x2, 0x2, 0x323, 0x328, 0x3, 
    0x2, 0x2, 0x2, 0x324, 0x329, 0x5, 0x5c, 0x2f, 0x2, 0x325, 0x329, 0x5, 
    0xd8, 0x6d, 0x2, 0x326, 0x329, 0x5, 0xde, 0x70, 0x2, 0x327, 0x329, 0x5, 
    0x4a, 0x26, 0x2, 0x328, 0x324, 0x3, 0x2, 0x2, 0x2, 0x328, 0x325, 0x3, 
    0x2, 0x2, 0x2, 0x328, 0x326, 0x3, 0x2, 0x2, 0x2, 0x328, 0x327, 0x3, 
    0x2, 0x2, 0x2, 0x329, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x32a, 0x32c, 0x7, 
    0x22, 0x2, 0x2, 0x32b, 0x32a, 0x3, 0x2, 0x2, 0x2, 0x32c, 0x32f, 0x3, 
    0x2, 0x2, 0x2, 0x32d, 0x32b, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x32e, 0x3, 
    0x2, 0x2, 0x2, 0x32e, 0x61, 0x3, 0x2, 0x2, 0x2, 0x32f, 0x32d, 0x3, 0x2, 
    0x2, 0x2, 0x330, 0x331, 0x5, 0x64, 0x33, 0x2, 0x331, 0x63, 0x3, 0x2, 
    0x2, 0x2, 0x332, 0x334, 0x7, 0x38, 0x2, 0x2, 0x333, 0x335, 0x5, 0xda, 
    0x6e, 0x2, 0x334, 0x333, 0x3, 0x2, 0x2, 0x2, 0x335, 0x336, 0x3, 0x2, 
    0x2, 0x2, 0x336, 0x334, 0x3, 0x2, 0x2, 0x2, 0x336, 0x337, 0x3, 0x2, 
    0x2, 0x2, 0x337, 0x338, 0x3, 0x2, 0x2, 0x2, 0x338, 0x33c, 0x7, 0x67, 
    0x2, 0x2, 0x339, 0x33b, 0x5, 0xda, 0x6e, 0x2, 0x33a, 0x339, 0x3, 0x2, 
    0x2, 0x2, 0x33b, 0x33e, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33a, 0x3, 0x2, 
    0x2, 0x2, 0x33c, 0x33d, 0x3, 0x2, 0x2, 0x2, 0x33d, 0x33f, 0x3, 0x2, 
    0x2, 0x2, 0x33e, 0x33c, 0x3, 0x2, 0x2, 0x2, 0x33f, 0x343, 0x7, 0xa, 
    0x2, 0x2, 0x340, 0x342, 0x5, 0xda, 0x6e, 0x2, 0x341, 0x340, 0x3, 0x2, 
    0x2, 0x2, 0x342, 0x345, 0x3, 0x2, 0x2, 0x2, 0x343, 0x341, 0x3, 0x2, 
    0x2, 0x2, 0x343, 0x344, 0x3, 0x2, 0x2, 0x2, 0x344, 0x347, 0x3, 0x2, 
    0x2, 0x2, 0x345, 0x343, 0x3, 0x2, 0x2, 0x2, 0x346, 0x348, 0x5, 0x66, 
    0x34, 0x2, 0x347, 0x346, 0x3, 0x2, 0x2, 0x2, 0x347, 0x348, 0x3, 0x2, 
    0x2, 0x2, 0x348, 0x34c, 0x3, 0x2, 0x2, 0x2, 0x349, 0x34b, 0x5, 0xda, 
    0x6e, 0x2, 0x34a, 0x349, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x34e, 0x3, 0x2, 
    0x2, 0x2, 0x34c, 0x34a, 0x3, 0x2, 0x2, 0x2, 0x34c, 0x34d, 0x3, 0x2, 
    0x2, 0x2, 0x34d, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x34c, 0x3, 0x2, 
    0x2, 0x2, 0x34f, 0x353, 0x7, 0xb, 0x2, 0x2, 0x350, 0x352, 0x5, 0xda, 
    0x6e, 0x2, 0x351, 0x350, 0x3, 0x2, 0x2, 0x2, 0x352, 0x355, 0x3, 0x2, 
    0x2, 0x2, 0x353, 0x351, 0x3, 0x2, 0x2, 0x2, 0x353, 0x354, 0x3, 0x2, 
    0x2, 0x2, 0x354, 0x356, 0x3, 0x2, 0x2, 0x2, 0x355, 0x353, 0x3, 0x2, 
    0x2, 0x2, 0x356, 0x357, 0x7, 0xd, 0x2, 0x2, 0x357, 0x65, 0x3, 0x2, 0x2, 
    0x2, 0x358, 0x35c, 0x5, 0x68, 0x35, 0x2, 0x359, 0x35b, 0x5, 0xda, 0x6e, 
    0x2, 0x35a, 0x359, 0x3, 0x2, 0x2, 0x2, 0x35b, 0x35e, 0x3, 0x2, 0x2, 
    0x2, 0x35c, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35c, 0x35d, 0x3, 0x2, 0x2, 
    0x2, 0x35d, 0x360, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35c, 0x3, 0x2, 0x2, 
    0x2, 0x35f, 0x361, 0x7, 0x4, 0x2, 0x2, 0x360, 0x35f, 0x3, 0x2, 0x2, 
    0x2, 0x360, 0x361, 0x3, 0x2, 0x2, 0x2, 0x361, 0x373, 0x3, 0x2, 0x2, 
    0x2, 0x362, 0x364, 0x5, 0xda, 0x6e, 0x2, 0x363, 0x362, 0x3, 0x2, 0x2, 
    0x2, 0x364, 0x367, 0x3, 0x2, 0x2, 0x2, 0x365, 0x363, 0x3, 0x2, 0x2, 
    0x2, 0x365, 0x366, 0x3, 0x2, 0x2, 0x2, 0x366, 0x368, 0x3, 0x2, 0x2, 
    0x2, 0x367, 0x365, 0x3, 0x2, 0x2, 0x2, 0x368, 0x36c, 0x5, 0x68, 0x35, 
    0x2, 0x369, 0x36b, 0x5, 0xda, 0x6e, 0x2, 0x36a, 0x369, 0x3, 0x2, 0x2, 
    0x2, 0x36b, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x36a, 0x3, 0x2, 0x2, 
    0x2, 0x36c, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x36d, 0x36f, 0x3, 0x2, 0x2, 
    0x2, 0x36e, 0x36c, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x370, 0x7, 0x4, 0x2, 
    0x2, 0x370, 0x372, 0x3, 0x2, 0x2, 0x2, 0x371, 0x365, 0x3, 0x2, 0x2, 
    0x2, 0x372, 0x375, 0x3, 0x2, 0x2, 0x2, 0x373, 0x371, 0x3, 0x2, 0x2, 
    0x2, 0x373, 0x374, 0x3, 0x2, 0x2, 0x2, 0x374, 0x379, 0x3, 0x2, 0x2, 
    0x2, 0x375, 0x373, 0x3, 0x2, 0x2, 0x2, 0x376, 0x378, 0x5, 0xda, 0x6e, 
    0x2, 0x377, 0x376, 0x3, 0x2, 0x2, 0x2, 0x378, 0x37b, 0x3, 0x2, 0x2, 
    0x2, 0x379, 0x377, 0x3, 0x2, 0x2, 0x2, 0x379, 0x37a, 0x3, 0x2, 0x2, 
    0x2, 0x37a, 0x37d, 0x3, 0x2, 0x2, 0x2, 0x37b, 0x379, 0x3, 0x2, 0x2, 
    0x2, 0x37c, 0x37e, 0x5, 0x68, 0x35, 0x2, 0x37d, 0x37c, 0x3, 0x2, 0x2, 
    0x2, 0x37d, 0x37e, 0x3, 0x2, 0x2, 0x2, 0x37e, 0x67, 0x3, 0x2, 0x2, 0x2, 
    0x37f, 0x383, 0x7, 0x67, 0x2, 0x2, 0x380, 0x382, 0x5, 0xda, 0x6e, 0x2, 
    0x381, 0x380, 0x3, 0x2, 0x2, 0x2, 0x382, 0x385, 0x3, 0x2, 0x2, 0x2, 
    0x383, 0x381, 0x3, 0x2, 0x2, 0x2, 0x383, 0x384, 0x3, 0x2, 0x2, 0x2, 
    0x384, 0x38e, 0x3, 0x2, 0x2, 0x2, 0x385, 0x383, 0x3, 0x2, 0x2, 0x2, 
    0x386, 0x38a, 0x7, 0x10, 0x2, 0x2, 0x387, 0x389, 0x5, 0xda, 0x6e, 0x2, 
    0x388, 0x387, 0x3, 0x2, 0x2, 0x2, 0x389, 0x38c, 0x3, 0x2, 0x2, 0x2, 
    0x38a, 0x388, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38b, 0x3, 0x2, 0x2, 0x2, 
    0x38b, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x38a, 0x3, 0x2, 0x2, 0x2, 
    0x38d, 0x38f, 0x7, 0x68, 0x2, 0x2, 0x38e, 0x386, 0x3, 0x2, 0x2, 0x2, 
    0x38e, 0x38f, 0x3, 0x2, 0x2, 0x2, 0x38f, 0x69, 0x3, 0x2, 0x2, 0x2, 0x390, 
    0x391, 0x5, 0x6c, 0x37, 0x2, 0x391, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x392, 
    0x396, 0x5, 0x6e, 0x38, 0x2, 0x393, 0x395, 0x5, 0x70, 0x39, 0x2, 0x394, 
    0x393, 0x3, 0x2, 0x2, 0x2, 0x395, 0x398, 0x3, 0x2, 0x2, 0x2, 0x396, 
    0x394, 0x3, 0x2, 0x2, 0x2, 0x396, 0x397, 0x3, 0x2, 0x2, 0x2, 0x397, 
    0x399, 0x3, 0x2, 0x2, 0x2, 0x398, 0x396, 0x3, 0x2, 0x2, 0x2, 0x399, 
    0x39a, 0x5, 0x72, 0x3a, 0x2, 0x39a, 0x39b, 0x7, 0xd, 0x2, 0x2, 0x39b, 
    0x3af, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x3a0, 0x5, 0x6e, 0x38, 0x2, 0x39d, 
    0x39f, 0x5, 0xda, 0x6e, 0x2, 0x39e, 0x39d, 0x3, 0x2, 0x2, 0x2, 0x39f, 
    0x3a2, 0x3, 0x2, 0x2, 0x2, 0x3a0, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x3a0, 
    0x3a1, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3a3, 0x3, 0x2, 0x2, 0x2, 0x3a2, 
    0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a3, 0x3a4, 0x5, 0x7a, 0x3e, 0x2, 0x3a4, 
    0x3af, 0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a9, 0x5, 0x7a, 0x3e, 0x2, 0x3a6, 
    0x3a8, 0x5, 0xda, 0x6e, 0x2, 0x3a7, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a8, 
    0x3ab, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3a7, 0x3, 0x2, 0x2, 0x2, 0x3a9, 
    0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3aa, 0x3ac, 0x3, 0x2, 0x2, 0x2, 0x3ab, 
    0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3ad, 0x5, 0x6e, 0x38, 0x2, 0x3ad, 
    0x3af, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x392, 0x3, 0x2, 0x2, 0x2, 0x3ae, 
    0x39c, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3af, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x3b0, 0x3b8, 0x5, 0xd8, 0x6d, 0x2, 0x3b1, 
    0x3b3, 0x5, 0xda, 0x6e, 0x2, 0x3b2, 0x3b1, 0x3, 0x2, 0x2, 0x2, 0x3b3, 
    0x3b6, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3b2, 0x3, 0x2, 0x2, 0x2, 0x3b4, 
    0x3b5, 0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3b6, 
    0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b7, 0x3b9, 0x5, 0x4e, 0x28, 0x2, 0x3b8, 
    0x3b4, 0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3b9, 
    0x6f, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3bc, 0x5, 0xda, 0x6e, 0x2, 0x3bb, 
    0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3bf, 0x3, 0x2, 0x2, 0x2, 0x3bd, 
    0x3bb, 0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3be, 0x3, 0x2, 0x2, 0x2, 0x3be, 
    0x3c0, 0x3, 0x2, 0x2, 0x2, 0x3bf, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3c0, 
    0x3c4, 0x5, 0x80, 0x41, 0x2, 0x3c1, 0x3c3, 0x5, 0xda, 0x6e, 0x2, 0x3c2, 
    0x3c1, 0x3, 0x2, 0x2, 0x2, 0x3c3, 0x3c6, 0x3, 0x2, 0x2, 0x2, 0x3c4, 
    0x3c2, 0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3c5, 0x3, 0x2, 0x2, 0x2, 0x3c5, 
    0x3cd, 0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c4, 0x3, 0x2, 0x2, 0x2, 0x3c7, 
    0x3ce, 0x5, 0x6e, 0x38, 0x2, 0x3c8, 0x3ca, 0x5, 0x20, 0x11, 0x2, 0x3c9, 
    0x3c8, 0x3, 0x2, 0x2, 0x2, 0x3ca, 0x3cb, 0x3, 0x2, 0x2, 0x2, 0x3cb, 
    0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3cb, 0x3cc, 0x3, 0x2, 0x2, 0x2, 0x3cc, 
    0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3c7, 0x3, 0x2, 0x2, 0x2, 0x3cd, 
    0x3c9, 0x3, 0x2, 0x2, 0x2, 0x3cd, 0x3ce, 0x3, 0x2, 0x2, 0x2, 0x3ce, 
    0x71, 0x3, 0x2, 0x2, 0x2, 0x3cf, 0x3d1, 0x5, 0xda, 0x6e, 0x2, 0x3d0, 
    0x3cf, 0x3, 0x2, 0x2, 0x2, 0x3d1, 0x3d4, 0x3, 0x2, 0x2, 0x2, 0x3d2, 
    0x3d0, 0x3, 0x2, 0x2, 0x2, 0x3d2, 0x3d3, 0x3, 0x2, 0x2, 0x2, 0x3d3, 
    0x3d5, 0x3, 0x2, 0x2, 0x2, 0x3d4, 0x3d2, 0x3, 0x2, 0x2, 0x2, 0x3d5, 
    0x3d9, 0x5, 0x80, 0x41, 0x2, 0x3d6, 0x3d8, 0x5, 0xda, 0x6e, 0x2, 0x3d7, 
    0x3d6, 0x3, 0x2, 0x2, 0x2, 0x3d8, 0x3db, 0x3, 0x2, 0x2, 0x2, 0x3d9, 
    0x3d7, 0x3, 0x2, 0x2, 0x2, 0x3d9, 0x3da, 0x3, 0x2, 0x2, 0x2, 0x3da, 
    0x3e2, 0x3, 0x2, 0x2, 0x2, 0x3db, 0x3d9, 0x3, 0x2, 0x2, 0x2, 0x3dc, 
    0x3e3, 0x5, 0x6e, 0x38, 0x2, 0x3dd, 0x3df, 0x5, 0x20, 0x11, 0x2, 0x3de, 
    0x3dd, 0x3, 0x2, 0x2, 0x2, 0x3df, 0x3e0, 0x3, 0x2, 0x2, 0x2, 0x3e0, 
    0x3de, 0x3, 0x2, 0x2, 0x2, 0x3e0, 0x3e1, 0x3, 0x2, 0x2, 0x2, 0x3e1, 
    0x3e3, 0x3, 0x2, 0x2, 0x2, 0x3e2, 0x3dc, 0x3, 0x2, 0x2, 0x2, 0x3e2, 
    0x3de, 0x3, 0x2, 0x2, 0x2, 0x3e3, 0x73, 0x3, 0x2, 0x2, 0x2, 0x3e4, 0x3e5, 
    0x8, 0x3b, 0x1, 0x2, 0x3e5, 0x3f1, 0x5, 0x7c, 0x3f, 0x2, 0x3e6, 0x3e8, 
    0x7, 0x8, 0x2, 0x2, 0x3e7, 0x3e6, 0x3, 0x2, 0x2, 0x2, 0x3e7, 0x3e8, 
    0x3, 0x2, 0x2, 0x2, 0x3e8, 0x3e9, 0x3, 0x2, 0x2, 0x2, 0x3e9, 0x3ea, 
    0x5, 0x7a, 0x3e, 0x2, 0x3ea, 0x3eb, 0x5, 0x74, 0x3b, 0x4, 0x3eb, 0x3f1, 
    0x3, 0x2, 0x2, 0x2, 0x3ec, 0x3ed, 0x7, 0x6, 0x2, 0x2, 0x3ed, 0x3ee, 
    0x5, 0x74, 0x3b, 0x2, 0x3ee, 0x3ef, 0x7, 0x7, 0x2, 0x2, 0x3ef, 0x3f1, 
    0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3e4, 0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3e7, 
    0x3, 0x2, 0x2, 0x2, 0x3f0, 0x3ec, 0x3, 0x2, 0x2, 0x2, 0x3f1, 0x3fb, 
    0x3, 0x2, 0x2, 0x2, 0x3f2, 0x3f3, 0xc, 0x6, 0x2, 0x2, 0x3f3, 0x3fa, 
    0x5, 0x76, 0x3c, 0x2, 0x3f4, 0x3f5, 0xc, 0x5, 0x2, 0x2, 0x3f5, 0x3f7, 
    0x5, 0x7a, 0x3e, 0x2, 0x3f6, 0x3f8, 0x7, 0x9, 0x2, 0x2, 0x3f7, 0x3f6, 
    0x3, 0x2, 0x2, 0x2, 0x3f7, 0x3f8, 0x3, 0x2, 0x2, 0x2, 0x3f8, 0x3fa, 
    0x3, 0x2, 0x2, 0x2, 0x3f9, 0x3f2, 0x3, 0x2, 0x2, 0x2, 0x3f9, 0x3f4, 
    0x3, 0x2, 0x2, 0x2, 0x3fa, 0x3fd, 0x3, 0x2, 0x2, 0x2, 0x3fb, 0x3f9, 
    0x3, 0x2, 0x2, 0x2, 0x3fb, 0x3fc, 0x3, 0x2, 0x2, 0x2, 0x3fc, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x3fd, 0x3fb, 0x3, 0x2, 0x2, 0x2, 0x3fe, 0x3ff, 0x5, 
    0x78, 0x3d, 0x2, 0x3ff, 0x400, 0x5, 0x7c, 0x3f, 0x2, 0x400, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x401, 0x402, 0x9, 0x5, 0x2, 0x2, 0x402, 0x79, 0x3, 0x2, 
    0x2, 0x2, 0x403, 0x404, 0x9, 0x6, 0x2, 0x2, 0x404, 0x7b, 0x3, 0x2, 0x2, 
    0x2, 0x405, 0x407, 0x7, 0x8, 0x2, 0x2, 0x406, 0x405, 0x3, 0x2, 0x2, 
    0x2, 0x406, 0x407, 0x3, 0x2, 0x2, 0x2, 0x407, 0x40b, 0x3, 0x2, 0x2, 
    0x2, 0x408, 0x40a, 0x5, 0xda, 0x6e, 0x2, 0x409, 0x408, 0x3, 0x2, 0x2, 
    0x2, 0x40a, 0x40d, 0x3, 0x2, 0x2, 0x2, 0x40b, 0x409, 0x3, 0x2, 0x2, 
    0x2, 0x40b, 0x40c, 0x3, 0x2, 0x2, 0x2, 0x40c, 0x40e, 0x3, 0x2, 0x2, 
    0x2, 0x40d, 0x40b, 0x3, 0x2, 0x2, 0x2, 0x40e, 0x412, 0x5, 0x7e, 0x40, 
    0x2, 0x40f, 0x411, 0x5, 0xda, 0x6e, 0x2, 0x410, 0x40f, 0x3, 0x2, 0x2, 
    0x2, 0x411, 0x414, 0x3, 0x2, 0x2, 0x2, 0x412, 0x410, 0x3, 0x2, 0x2, 
    0x2, 0x412, 0x413, 0x3, 0x2, 0x2, 0x2, 0x413, 0x41c, 0x3, 0x2, 0x2, 
    0x2, 0x414, 0x412, 0x3, 0x2, 0x2, 0x2, 0x415, 0x419, 0x7, 0x9, 0x2, 
    0x2, 0x416, 0x418, 0x5, 0xda, 0x6e, 0x2, 0x417, 0x416, 0x3, 0x2, 0x2, 
    0x2, 0x418, 0x41b, 0x3, 0x2, 0x2, 0x2, 0x419, 0x417, 0x3, 0x2, 0x2, 
    0x2, 0x419, 0x41a, 0x3, 0x2, 0x2, 0x2, 0x41a, 0x41d, 0x3, 0x2, 0x2, 
    0x2, 0x41b, 0x419, 0x3, 0x2, 0x2, 0x2, 0x41c, 0x415, 0x3, 0x2, 0x2, 
    0x2, 0x41c, 0x41d, 0x3, 0x2, 0x2, 0x2, 0x41d, 0x7d, 0x3, 0x2, 0x2, 0x2, 
    0x41e, 0x426, 0x5, 0xd8, 0x6d, 0x2, 0x41f, 0x421, 0x5, 0xda, 0x6e, 0x2, 
    0x420, 0x41f, 0x3, 0x2, 0x2, 0x2, 0x421, 0x424, 0x3, 0x2, 0x2, 0x2, 
    0x422, 0x420, 0x3, 0x2, 0x2, 0x2, 0x422, 0x423, 0x3, 0x2, 0x2, 0x2, 
    0x423, 0x425, 0x3, 0x2, 0x2, 0x2, 0x424, 0x422, 0x3, 0x2, 0x2, 0x2, 
    0x425, 0x427, 0x5, 0x4e, 0x28, 0x2, 0x426, 0x422, 0x3, 0x2, 0x2, 0x2, 
    0x426, 0x427, 0x3, 0x2, 0x2, 0x2, 0x427, 0x42c, 0x3, 0x2, 0x2, 0x2, 
    0x428, 0x42c, 0x5, 0xde, 0x70, 0x2, 0x429, 0x42c, 0x5, 0xdc, 0x6f, 0x2, 
    0x42a, 0x42c, 0x5, 0x5c, 0x2f, 0x2, 0x42b, 0x41e, 0x3, 0x2, 0x2, 0x2, 
    0x42b, 0x428, 0x3, 0x2, 0x2, 0x2, 0x42b, 0x429, 0x3, 0x2, 0x2, 0x2, 
    0x42b, 0x42a, 0x3, 0x2, 0x2, 0x2, 0x42c, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x42d, 
    0x43b, 0x7, 0x10, 0x2, 0x2, 0x42e, 0x42f, 0x7, 0x17, 0x2, 0x2, 0x42f, 
    0x43b, 0x7, 0x10, 0x2, 0x2, 0x430, 0x431, 0x7, 0x18, 0x2, 0x2, 0x431, 
    0x43b, 0x7, 0x10, 0x2, 0x2, 0x432, 0x433, 0x7, 0x19, 0x2, 0x2, 0x433, 
    0x43b, 0x7, 0x10, 0x2, 0x2, 0x434, 0x435, 0x7, 0x1a, 0x2, 0x2, 0x435, 
    0x43b, 0x7, 0x10, 0x2, 0x2, 0x436, 0x437, 0x7, 0x1b, 0x2, 0x2, 0x437, 
    0x43b, 0x7, 0x10, 0x2, 0x2, 0x438, 0x439, 0x7, 0x6e, 0x2, 0x2, 0x439, 
    0x43b, 0x7, 0x10, 0x2, 0x2, 0x43a, 0x42d, 0x3, 0x2, 0x2, 0x2, 0x43a, 
    0x42e, 0x3, 0x2, 0x2, 0x2, 0x43a, 0x430, 0x3, 0x2, 0x2, 0x2, 0x43a, 
    0x432, 0x3, 0x2, 0x2, 0x2, 0x43a, 0x434, 0x3, 0x2, 0x2, 0x2, 0x43a, 
    0x436, 0x3, 0x2, 0x2, 0x2, 0x43a, 0x438, 0x3, 0x2, 0x2, 0x2, 0x43b, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x43c, 0x44b, 0x7, 0x51, 0x2, 0x2, 0x43d, 
    0x43f, 0x5, 0xda, 0x6e, 0x2, 0x43e, 0x43d, 0x3, 0x2, 0x2, 0x2, 0x43f, 
    0x442, 0x3, 0x2, 0x2, 0x2, 0x440, 0x43e, 0x3, 0x2, 0x2, 0x2, 0x440, 
    0x441, 0x3, 0x2, 0x2, 0x2, 0x441, 0x443, 0x3, 0x2, 0x2, 0x2, 0x442, 
    0x440, 0x3, 0x2, 0x2, 0x2, 0x443, 0x447, 0x7, 0x8, 0x2, 0x2, 0x444, 
    0x446, 0x5, 0xda, 0x6e, 0x2, 0x445, 0x444, 0x3, 0x2, 0x2, 0x2, 0x446, 
    0x449, 0x3, 0x2, 0x2, 0x2, 0x447, 0x445, 0x3, 0x2, 0x2, 0x2, 0x447, 
    0x448, 0x3, 0x2, 0x2, 0x2, 0x448, 0x44a, 0x3, 0x2, 0x2, 0x2, 0x449, 
    0x447, 0x3, 0x2, 0x2, 0x2, 0x44a, 0x44c, 0x7, 0x9, 0x2, 0x2, 0x44b, 
    0x440, 0x3, 0x2, 0x2, 0x2, 0x44b, 0x44c, 0x3, 0x2, 0x2, 0x2, 0x44c, 
    0x83, 0x3, 0x2, 0x2, 0x2, 0x44d, 0x451, 0x7, 0x52, 0x2, 0x2, 0x44e, 
    0x450, 0x5, 0xda, 0x6e, 0x2, 0x44f, 0x44e, 0x3, 0x2, 0x2, 0x2, 0x450, 
    0x453, 0x3, 0x2, 0x2, 0x2, 0x451, 0x44f, 0x3, 0x2, 0x2, 0x2, 0x451, 
    0x452, 0x3, 0x2, 0x2, 0x2, 0x452, 0x454, 0x3, 0x2, 0x2, 0x2, 0x453, 
    0x451, 0x3, 0x2, 0x2, 0x2, 0x454, 0x455, 0x7, 0x6, 0x2, 0x2, 0x455, 
    0x456, 0x5, 0x50, 0x29, 0x2, 0x456, 0x457, 0x7, 0x7, 0x2, 0x2, 0x457, 
    0x85, 0x3, 0x2, 0x2, 0x2, 0x458, 0x459, 0x7, 0x5d, 0x2, 0x2, 0x459, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x45a, 0x45b, 0x7, 0x5e, 0x2, 0x2, 0x45b, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x45c, 0x45d, 0x9, 0x7, 0x2, 0x2, 0x45d, 0x8b, 
    0x3, 0x2, 0x2, 0x2, 0x45e, 0x462, 0x7, 0x56, 0x2, 0x2, 0x45f, 0x461, 
    0x5, 0xda, 0x6e, 0x2, 0x460, 0x45f, 0x3, 0x2, 0x2, 0x2, 0x461, 0x464, 
    0x3, 0x2, 0x2, 0x2, 0x462, 0x460, 0x3, 0x2, 0x2, 0x2, 0x462, 0x463, 
    0x3, 0x2, 0x2, 0x2, 0x463, 0x465, 0x3, 0x2, 0x2, 0x2, 0x464, 0x462, 
    0x3, 0x2, 0x2, 0x2, 0x465, 0x469, 0x7, 0x8, 0x2, 0x2, 0x466, 0x468, 
    0x5, 0xda, 0x6e, 0x2, 0x467, 0x466, 0x3, 0x2, 0x2, 0x2, 0x468, 0x46b, 
    0x3, 0x2, 0x2, 0x2, 0x469, 0x467, 0x3, 0x2, 0x2, 0x2, 0x469, 0x46a, 
    0x3, 0x2, 0x2, 0x2, 0x46a, 0x46c, 0x3, 0x2, 0x2, 0x2, 0x46b, 0x469, 
    0x3, 0x2, 0x2, 0x2, 0x46c, 0x470, 0x7, 0x68, 0x2, 0x2, 0x46d, 0x46f, 
    0x5, 0xda, 0x6e, 0x2, 0x46e, 0x46d, 0x3, 0x2, 0x2, 0x2, 0x46f, 0x472, 
    0x3, 0x2, 0x2, 0x2, 0x470, 0x46e, 0x3, 0x2, 0x2, 0x2, 0x470, 0x471, 
    0x3, 0x2, 0x2, 0x2, 0x471, 0x473, 0x3, 0x2, 0x2, 0x2, 0x472, 0x470, 
    0x3, 0x2, 0x2, 0x2, 0x473, 0x474, 0x7, 0x9, 0x2, 0x2, 0x474, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x475, 0x477, 0x5, 0xda, 0x6e, 0x2, 0x476, 0x475, 0x3, 
    0x2, 0x2, 0x2, 0x477, 0x47a, 0x3, 0x2, 0x2, 0x2, 0x478, 0x476, 0x3, 
    0x2, 0x2, 0x2, 0x478, 0x479, 0x3, 0x2, 0x2, 0x2, 0x479, 0x47b, 0x3, 
    0x2, 0x2, 0x2, 0x47a, 0x478, 0x3, 0x2, 0x2, 0x2, 0x47b, 0x47f, 0x7, 
    0x4, 0x2, 0x2, 0x47c, 0x47e, 0x5, 0xda, 0x6e, 0x2, 0x47d, 0x47c, 0x3, 
    0x2, 0x2, 0x2, 0x47e, 0x481, 0x3, 0x2, 0x2, 0x2, 0x47f, 0x47d, 0x3, 
    0x2, 0x2, 0x2, 0x47f, 0x480, 0x3, 0x2, 0x2, 0x2, 0x480, 0x8f, 0x3, 0x2, 
    0x2, 0x2, 0x481, 0x47f, 0x3, 0x2, 0x2, 0x2, 0x482, 0x484, 0x9, 0x8, 
    0x2, 0x2, 0x483, 0x485, 0x5, 0xda, 0x6e, 0x2, 0x484, 0x483, 0x3, 0x2, 
    0x2, 0x2, 0x485, 0x486, 0x3, 0x2, 0x2, 0x2, 0x486, 0x484, 0x3, 0x2, 
    0x2, 0x2, 0x486, 0x487, 0x3, 0x2, 0x2, 0x2, 0x487, 0x489, 0x3, 0x2, 
    0x2, 0x2, 0x488, 0x482, 0x3, 0x2, 0x2, 0x2, 0x488, 0x489, 0x3, 0x2, 
    0x2, 0x2, 0x489, 0x48a, 0x3, 0x2, 0x2, 0x2, 0x48a, 0x48e, 0x5, 0x92, 
    0x4a, 0x2, 0x48b, 0x48d, 0x5, 0x94, 0x4b, 0x2, 0x48c, 0x48b, 0x3, 0x2, 
    0x2, 0x2, 0x48d, 0x490, 0x3, 0x2, 0x2, 0x2, 0x48e, 0x48c, 0x3, 0x2, 
    0x2, 0x2, 0x48e, 0x48f, 0x3, 0x2, 0x2, 0x2, 0x48f, 0x498, 0x3, 0x2, 
    0x2, 0x2, 0x490, 0x48e, 0x3, 0x2, 0x2, 0x2, 0x491, 0x493, 0x5, 0xda, 
    0x6e, 0x2, 0x492, 0x491, 0x3, 0x2, 0x2, 0x2, 0x493, 0x496, 0x3, 0x2, 
    0x2, 0x2, 0x494, 0x492, 0x3, 0x2, 0x2, 0x2, 0x494, 0x495, 0x3, 0x2, 
    0x2, 0x2, 0x495, 0x497, 0x3, 0x2, 0x2, 0x2, 0x496, 0x494, 0x3, 0x2, 
    0x2, 0x2, 0x497, 0x499, 0x7, 0xd, 0x2, 0x2, 0x498, 0x494, 0x3, 0x2, 
    0x2, 0x2, 0x498, 0x499, 0x3, 0x2, 0x2, 0x2, 0x499, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x49a, 0x49c, 0x7, 0x36, 0x2, 0x2, 0x49b, 0x49d, 0x5, 0xda, 0x6e, 
    0x2, 0x49c, 0x49b, 0x3, 0x2, 0x2, 0x2, 0x49d, 0x49e, 0x3, 0x2, 0x2, 
    0x2, 0x49e, 0x49c, 0x3, 0x2, 0x2, 0x2, 0x49e, 0x49f, 0x3, 0x2, 0x2, 
    0x2, 0x49f, 0x4a1, 0x3, 0x2, 0x2, 0x2, 0x4a0, 0x49a, 0x3, 0x2, 0x2, 
    0x2, 0x4a0, 0x4a1, 0x3, 0x2, 0x2, 0x2, 0x4a1, 0x4a2, 0x3, 0x2, 0x2, 
    0x2, 0x4a2, 0x4a6, 0x5, 0xb2, 0x5a, 0x2, 0x4a3, 0x4a5, 0x5, 0xda, 0x6e, 
    0x2, 0x4a4, 0x4a3, 0x3, 0x2, 0x2, 0x2, 0x4a5, 0x4a8, 0x3, 0x2, 0x2, 
    0x2, 0x4a6, 0x4a4, 0x3, 0x2, 0x2, 0x2, 0x4a6, 0x4a7, 0x3, 0x2, 0x2, 
    0x2, 0x4a7, 0x4b0, 0x3, 0x2, 0x2, 0x2, 0x4a8, 0x4a6, 0x3, 0x2, 0x2, 
    0x2, 0x4a9, 0x4ad, 0x7, 0x1b, 0x2, 0x2, 0x4aa, 0x4ac, 0x5, 0xda, 0x6e, 
    0x2, 0x4ab, 0x4aa, 0x3, 0x2, 0x2, 0x2, 0x4ac, 0x4af, 0x3, 0x2, 0x2, 
    0x2, 0x4ad, 0x4ab, 0x3, 0x2, 0x2, 0x2, 0x4ad, 0x4ae, 0x3, 0x2, 0x2, 
    0x2, 0x4ae, 0x4b1, 0x3, 0x2, 0x2, 0x2, 0x4af, 0x4ad, 0x3, 0x2, 0x2, 
    0x2, 0x4b0, 0x4a9, 0x3, 0x2, 0x2, 0x2, 0x4b0, 0x4b1, 0x3, 0x2, 0x2, 
    0x2, 0x4b1, 0x4b2, 0x3, 0x2, 0x2, 0x2, 0x4b2, 0x4ba, 0x5, 0xd8, 0x6d, 
    0x2, 0x4b3, 0x4b5, 0x5, 0xda, 0x6e, 0x2, 0x4b4, 0x4b3, 0x3, 0x2, 0x2, 
    0x2, 0x4b5, 0x4b8, 0x3, 0x2, 0x2, 0x2, 0x4b6, 0x4b4, 0x3, 0x2, 0x2, 
    0x2, 0x4b6, 0x4b7, 0x3, 0x2, 0x2, 0x2, 0x4b7, 0x4b9, 0x3, 0x2, 0x2, 
    0x2, 0x4b8, 0x4b6, 0x3, 0x2, 0x2, 0x2, 0x4b9, 0x4bb, 0x5, 0xa2, 0x52, 
    0x2, 0x4ba, 0x4b6, 0x3, 0x2, 0x2, 0x2, 0x4ba, 0x4bb, 0x3, 0x2, 0x2, 
    0x2, 0x4bb, 0x4c3, 0x3, 0x2, 0x2, 0x2, 0x4bc, 0x4be, 0x5, 0xda, 0x6e, 
    0x2, 0x4bd, 0x4bc, 0x3, 0x2, 0x2, 0x2, 0x4be, 0x4c1, 0x3, 0x2, 0x2, 
    0x2, 0x4bf, 0x4bd, 0x3, 0x2, 0x2, 0x2, 0x4bf, 0x4c0, 0x3, 0x2, 0x2, 
    0x2, 0x4c0, 0x4c2, 0x3, 0x2, 0x2, 0x2, 0x4c1, 0x4bf, 0x3, 0x2, 0x2, 
    0x2, 0x4c2, 0x4c4, 0x5, 0x96, 0x4c, 0x2, 0x4c3, 0x4bf, 0x3, 0x2, 0x2, 
    0x2, 0x4c3, 0x4c4, 0x3, 0x2, 0x2, 0x2, 0x4c4, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x4c5, 0x4c7, 0x5, 0xda, 0x6e, 0x2, 0x4c6, 0x4c5, 0x3, 0x2, 0x2, 0x2, 
    0x4c7, 0x4ca, 0x3, 0x2, 0x2, 0x2, 0x4c8, 0x4c6, 0x3, 0x2, 0x2, 0x2, 
    0x4c8, 0x4c9, 0x3, 0x2, 0x2, 0x2, 0x4c9, 0x4cb, 0x3, 0x2, 0x2, 0x2, 
    0x4ca, 0x4c8, 0x3, 0x2, 0x2, 0x2, 0x4cb, 0x4cf, 0x7, 0x4, 0x2, 0x2, 
    0x4cc, 0x4ce, 0x5, 0xda, 0x6e, 0x2, 0x4cd, 0x4cc, 0x3, 0x2, 0x2, 0x2, 
    0x4ce, 0x4d1, 0x3, 0x2, 0x2, 0x2, 0x4cf, 0x4cd, 0x3, 0x2, 0x2, 0x2, 
    0x4cf, 0x4d0, 0x3, 0x2, 0x2, 0x2, 0x4d0, 0x4d2, 0x3, 0x2, 0x2, 0x2, 
    0x4d1, 0x4cf, 0x3, 0x2, 0x2, 0x2, 0x4d2, 0x4da, 0x5, 0xd8, 0x6d, 0x2, 
    0x4d3, 0x4d5, 0x5, 0xda, 0x6e, 0x2, 0x4d4, 0x4d3, 0x3, 0x2, 0x2, 0x2, 
    0x4d5, 0x4d8, 0x3, 0x2, 0x2, 0x2, 0x4d6, 0x4d4, 0x3, 0x2, 0x2, 0x2, 
    0x4d6, 0x4d7, 0x3, 0x2, 0x2, 0x2, 0x4d7, 0x4d9, 0x3, 0x2, 0x2, 0x2, 
    0x4d8, 0x4d6, 0x3, 0x2, 0x2, 0x2, 0x4d9, 0x4db, 0x5, 0xa2, 0x52, 0x2, 
    0x4da, 0x4d6, 0x3, 0x2, 0x2, 0x2, 0x4da, 0x4db, 0x3, 0x2, 0x2, 0x2, 
    0x4db, 0x4df, 0x3, 0x2, 0x2, 0x2, 0x4dc, 0x4de, 0x5, 0xda, 0x6e, 0x2, 
    0x4dd, 0x4dc, 0x3, 0x2, 0x2, 0x2, 0x4de, 0x4e1, 0x3, 0x2, 0x2, 0x2, 
    0x4df, 0x4dd, 0x3, 0x2, 0x2, 0x2, 0x4df, 0x4e0, 0x3, 0x2, 0x2, 0x2, 
    0x4e0, 0x4e3, 0x3, 0x2, 0x2, 0x2, 0x4e1, 0x4df, 0x3, 0x2, 0x2, 0x2, 
    0x4e2, 0x4e4, 0x5, 0x96, 0x4c, 0x2, 0x4e3, 0x4e2, 0x3, 0x2, 0x2, 0x2, 
    0x4e3, 0x4e4, 0x3, 0x2, 0x2, 0x2, 0x4e4, 0x95, 0x3, 0x2, 0x2, 0x2, 0x4e5, 
    0x4e9, 0x7, 0x10, 0x2, 0x2, 0x4e6, 0x4e8, 0x5, 0xda, 0x6e, 0x2, 0x4e7, 
    0x4e6, 0x3, 0x2, 0x2, 0x2, 0x4e8, 0x4eb, 0x3, 0x2, 0x2, 0x2, 0x4e9, 
    0x4e7, 0x3, 0x2, 0x2, 0x2, 0x4e9, 0x4ea, 0x3, 0x2, 0x2, 0x2, 0x4ea, 
    0x4f2, 0x3, 0x2, 0x2, 0x2, 0x4eb, 0x4e9, 0x3, 0x2, 0x2, 0x2, 0x4ec, 
    0x4f3, 0x5, 0x98, 0x4d, 0x2, 0x4ed, 0x4ef, 0x5, 0x20, 0x11, 0x2, 0x4ee, 
    0x4ed, 0x3, 0x2, 0x2, 0x2, 0x4ef, 0x4f0, 0x3, 0x2, 0x2, 0x2, 0x4f0, 
    0x4ee, 0x3, 0x2, 0x2, 0x2, 0x4f0, 0x4f1, 0x3, 0x2, 0x2, 0x2, 0x4f1, 
    0x4f3, 0x3, 0x2, 0x2, 0x2, 0x4f2, 0x4ec, 0x3, 0x2, 0x2, 0x2, 0x4f2, 
    0x4ee, 0x3, 0x2, 0x2, 0x2, 0x4f3, 0x97, 0x3, 0x2, 0x2, 0x2, 0x4f4, 0x4fc, 
    0x7, 0xa, 0x2, 0x2, 0x4f5, 0x4f9, 0x5, 0x9c, 0x4f, 0x2, 0x4f6, 0x4f8, 
    0x5, 0x9a, 0x4e, 0x2, 0x4f7, 0x4f6, 0x3, 0x2, 0x2, 0x2, 0x4f8, 0x4fb, 
    0x3, 0x2, 0x2, 0x2, 0x4f9, 0x4f7, 0x3, 0x2, 0x2, 0x2, 0x4f9, 0x4fa, 
    0x3, 0x2, 0x2, 0x2, 0x4fa, 0x4fd, 0x3, 0x2, 0x2, 0x2, 0x4fb, 0x4f9, 
    0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4f5, 0x3, 0x2, 0x2, 0x2, 0x4fc, 0x4fd, 
    0x3, 0x2, 0x2, 0x2, 0x4fd, 0x4fe, 0x3, 0x2, 0x2, 0x2, 0x4fe, 0x4ff, 
    0x7, 0xb, 0x2, 0x2, 0x4ff, 0x99, 0x3, 0x2, 0x2, 0x2, 0x500, 0x501, 0x7, 
    0x4, 0x2, 0x2, 0x501, 0x502, 0x5, 0x9c, 0x4f, 0x2, 0x502, 0x9b, 0x3, 
    0x2, 0x2, 0x2, 0x503, 0x505, 0x5, 0xda, 0x6e, 0x2, 0x504, 0x503, 0x3, 
    0x2, 0x2, 0x2, 0x505, 0x508, 0x3, 0x2, 0x2, 0x2, 0x506, 0x504, 0x3, 
    0x2, 0x2, 0x2, 0x506, 0x507, 0x3, 0x2, 0x2, 0x2, 0x507, 0x509, 0x3, 
    0x2, 0x2, 0x2, 0x508, 0x506, 0x3, 0x2, 0x2, 0x2, 0x509, 0x50d, 0x5, 
    0x98, 0x4d, 0x2, 0x50a, 0x50c, 0x5, 0xda, 0x6e, 0x2, 0x50b, 0x50a, 0x3, 
    0x2, 0x2, 0x2, 0x50c, 0x50f, 0x3, 0x2, 0x2, 0x2, 0x50d, 0x50b, 0x3, 
    0x2, 0x2, 0x2, 0x50d, 0x50e, 0x3, 0x2, 0x2, 0x2, 0x50e, 0x51b, 0x3, 
    0x2, 0x2, 0x2, 0x50f, 0x50d, 0x3, 0x2, 0x2, 0x2, 0x510, 0x512, 0x5, 
    0xda, 0x6e, 0x2, 0x511, 0x510, 0x3, 0x2, 0x2, 0x2, 0x512, 0x513, 0x3, 
    0x2, 0x2, 0x2, 0x513, 0x511, 0x3, 0x2, 0x2, 0x2, 0x513, 0x514, 0x3, 
    0x2, 0x2, 0x2, 0x514, 0x51b, 0x3, 0x2, 0x2, 0x2, 0x515, 0x517, 0x5, 
    0x9e, 0x50, 0x2, 0x516, 0x515, 0x3, 0x2, 0x2, 0x2, 0x517, 0x518, 0x3, 
    0x2, 0x2, 0x2, 0x518, 0x516, 0x3, 0x2, 0x2, 0x2, 0x518, 0x519, 0x3, 
    0x2, 0x2, 0x2, 0x519, 0x51b, 0x3, 0x2, 0x2, 0x2, 0x51a, 0x506, 0x3, 
    0x2, 0x2, 0x2, 0x51a, 0x511, 0x3, 0x2, 0x2, 0x2, 0x51a, 0x516, 0x3, 
    0x2, 0x2, 0x2, 0x51b, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x51c, 0x51e, 0x5, 0xda, 
    0x6e, 0x2, 0x51d, 0x51c, 0x3, 0x2, 0x2, 0x2, 0x51e, 0x51f, 0x3, 0x2, 
    0x2, 0x2, 0x51f, 0x51d, 0x3, 0x2, 0x2, 0x2, 0x51f, 0x520, 0x3, 0x2, 
    0x2, 0x2, 0x520, 0x52d, 0x3, 0x2, 0x2, 0x2, 0x521, 0x52d, 0x5, 0xdc, 
    0x6f, 0x2, 0x522, 0x52d, 0x5, 0xde, 0x70, 0x2, 0x523, 0x52d, 0x7, 0x67, 
    0x2, 0x2, 0x524, 0x52d, 0x5, 0x5c, 0x2f, 0x2, 0x525, 0x52d, 0x7, 0x66, 
    0x2, 0x2, 0x526, 0x52d, 0x7, 0x35, 0x2, 0x2, 0x527, 0x52d, 0x5, 0xa0, 
    0x51, 0x2, 0x528, 0x52d, 0x5, 0x42, 0x22, 0x2, 0x529, 0x52d, 0x5, 0x3e, 
    0x20, 0x2, 0x52a, 0x52d, 0x5, 0x46, 0x24, 0x2, 0x52b, 0x52d, 0x5, 0xde, 
    0x70, 0x2, 0x52c, 0x51d, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x521, 0x3, 0x2, 
    0x2, 0x2, 0x52c, 0x522, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x523, 0x3, 0x2, 
    0x2, 0x2, 0x52c, 0x524, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x525, 0x3, 0x2, 
    0x2, 0x2, 0x52c, 0x526, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x527, 0x3, 0x2, 
    0x2, 0x2, 0x52c, 0x528, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x529, 0x3, 0x2, 
    0x2, 0x2, 0x52c, 0x52a, 0x3, 0x2, 0x2, 0x2, 0x52c, 0x52b, 0x3, 0x2, 
    0x2, 0x2, 0x52d, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x52e, 0x52f, 0x9, 0x9, 0x2, 
    0x2, 0x52f, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x530, 0x532, 0x5, 0xa4, 0x53, 
    0x2, 0x531, 0x530, 0x3, 0x2, 0x2, 0x2, 0x532, 0x533, 0x3, 0x2, 0x2, 
    0x2, 0x533, 0x531, 0x3, 0x2, 0x2, 0x2, 0x533, 0x534, 0x3, 0x2, 0x2, 
    0x2, 0x534, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x535, 0x539, 0x7, 0x6, 0x2, 0x2, 
    0x536, 0x538, 0x5, 0xda, 0x6e, 0x2, 0x537, 0x536, 0x3, 0x2, 0x2, 0x2, 
    0x538, 0x53b, 0x3, 0x2, 0x2, 0x2, 0x539, 0x537, 0x3, 0x2, 0x2, 0x2, 
    0x539, 0x53a, 0x3, 0x2, 0x2, 0x2, 0x53a, 0x54b, 0x3, 0x2, 0x2, 0x2, 
    0x53b, 0x539, 0x3, 0x2, 0x2, 0x2, 0x53c, 0x540, 0x5, 0xa8, 0x55, 0x2, 
    0x53d, 0x53f, 0x5, 0xa6, 0x54, 0x2, 0x53e, 0x53d, 0x3, 0x2, 0x2, 0x2, 
    0x53f, 0x542, 0x3, 0x2, 0x2, 0x2, 0x540, 0x53e, 0x3, 0x2, 0x2, 0x2, 
    0x540, 0x541, 0x3, 0x2, 0x2, 0x2, 0x541, 0x54c, 0x3, 0x2, 0x2, 0x2, 
    0x542, 0x540, 0x3, 0x2, 0x2, 0x2, 0x543, 0x545, 0x5, 0xa8, 0x55, 0x2, 
    0x544, 0x543, 0x3, 0x2, 0x2, 0x2, 0x544, 0x545, 0x3, 0x2, 0x2, 0x2, 
    0x545, 0x547, 0x3, 0x2, 0x2, 0x2, 0x546, 0x548, 0x5, 0xa6, 0x54, 0x2, 
    0x547, 0x546, 0x3, 0x2, 0x2, 0x2, 0x548, 0x549, 0x3, 0x2, 0x2, 0x2, 
    0x549, 0x547, 0x3, 0x2, 0x2, 0x2, 0x549, 0x54a, 0x3, 0x2, 0x2, 0x2, 
    0x54a, 0x54c, 0x3, 0x2, 0x2, 0x2, 0x54b, 0x53c, 0x3, 0x2, 0x2, 0x2, 
    0x54b, 0x544, 0x3, 0x2, 0x2, 0x2, 0x54b, 0x54c, 0x3, 0x2, 0x2, 0x2, 
    0x54c, 0x550, 0x3, 0x2, 0x2, 0x2, 0x54d, 0x54f, 0x5, 0xda, 0x6e, 0x2, 
    0x54e, 0x54d, 0x3, 0x2, 0x2, 0x2, 0x54f, 0x552, 0x3, 0x2, 0x2, 0x2, 
    0x550, 0x54e, 0x3, 0x2, 0x2, 0x2, 0x550, 0x551, 0x3, 0x2, 0x2, 0x2, 
    0x551, 0x553, 0x3, 0x2, 0x2, 0x2, 0x552, 0x550, 0x3, 0x2, 0x2, 0x2, 
    0x553, 0x554, 0x7, 0x7, 0x2, 0x2, 0x554, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x555, 
    0x557, 0x5, 0xda, 0x6e, 0x2, 0x556, 0x555, 0x3, 0x2, 0x2, 0x2, 0x557, 
    0x55a, 0x3, 0x2, 0x2, 0x2, 0x558, 0x556, 0x3, 0x2, 0x2, 0x2, 0x558, 
    0x559, 0x3, 0x2, 0x2, 0x2, 0x559, 0x55b, 0x3, 0x2, 0x2, 0x2, 0x55a, 
    0x558, 0x3, 0x2, 0x2, 0x2, 0x55b, 0x55f, 0x7, 0x4, 0x2, 0x2, 0x55c, 
    0x55e, 0x5, 0xda, 0x6e, 0x2, 0x55d, 0x55c, 0x3, 0x2, 0x2, 0x2, 0x55e, 
    0x561, 0x3, 0x2, 0x2, 0x2, 0x55f, 0x55d, 0x3, 0x2, 0x2, 0x2, 0x55f, 
    0x560, 0x3, 0x2, 0x2, 0x2, 0x560, 0x563, 0x3, 0x2, 0x2, 0x2, 0x561, 
    0x55f, 0x3, 0x2, 0x2, 0x2, 0x562, 0x564, 0x5, 0xa8, 0x55, 0x2, 0x563, 
    0x562, 0x3, 0x2, 0x2, 0x2, 0x563, 0x564, 0x3, 0x2, 0x2, 0x2, 0x564, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0x565, 0x566, 0x9, 0xa, 0x2, 0x2, 0x566, 0xa9, 
    0x3, 0x2, 0x2, 0x2, 0x567, 0x56b, 0x7, 0x53, 0x2, 0x2, 0x568, 0x56a, 
    0x5, 0xda, 0x6e, 0x2, 0x569, 0x568, 0x3, 0x2, 0x2, 0x2, 0x56a, 0x56d, 
    0x3, 0x2, 0x2, 0x2, 0x56b, 0x569, 0x3, 0x2, 0x2, 0x2, 0x56b, 0x56c, 
    0x3, 0x2, 0x2, 0x2, 0x56c, 0x56e, 0x3, 0x2, 0x2, 0x2, 0x56d, 0x56b, 
    0x3, 0x2, 0x2, 0x2, 0x56e, 0x572, 0x7, 0x8, 0x2, 0x2, 0x56f, 0x571, 
    0x5, 0xda, 0x6e, 0x2, 0x570, 0x56f, 0x3, 0x2, 0x2, 0x2, 0x571, 0x574, 
    0x3, 0x2, 0x2, 0x2, 0x572, 0x570, 0x3, 0x2, 0x2, 0x2, 0x572, 0x573, 
    0x3, 0x2, 0x2, 0x2, 0x573, 0x577, 0x3, 0x2, 0x2, 0x2, 0x574, 0x572, 
    0x3, 0x2, 0x2, 0x2, 0x575, 0x578, 0x7, 0x68, 0x2, 0x2, 0x576, 0x578, 
    0x5, 0x20, 0x11, 0x2, 0x577, 0x575, 0x3, 0x2, 0x2, 0x2, 0x577, 0x576, 
    0x3, 0x2, 0x2, 0x2, 0x578, 0x57c, 0x3, 0x2, 0x2, 0x2, 0x579, 0x57b, 
    0x5, 0xda, 0x6e, 0x2, 0x57a, 0x579, 0x3, 0x2, 0x2, 0x2, 0x57b, 0x57e, 
    0x3, 0x2, 0x2, 0x2, 0x57c, 0x57a, 0x3, 0x2, 0x2, 0x2, 0x57c, 0x57d, 
    0x3, 0x2, 0x2, 0x2, 0x57d, 0x57f, 0x3, 0x2, 0x2, 0x2, 0x57e, 0x57c, 
    0x3, 0x2, 0x2, 0x2, 0x57f, 0x583, 0x7, 0x4, 0x2, 0x2, 0x580, 0x582, 
    0x5, 0xda, 0x6e, 0x2, 0x581, 0x580, 0x3, 0x2, 0x2, 0x2, 0x582, 0x585, 
    0x3, 0x2, 0x2, 0x2, 0x583, 0x581, 0x3, 0x2, 0x2, 0x2, 0x583, 0x584, 
    0x3, 0x2, 0x2, 0x2, 0x584, 0x586, 0x3, 0x2, 0x2, 0x2, 0x585, 0x583, 
    0x3, 0x2, 0x2, 0x2, 0x586, 0x58a, 0x5, 0xd8, 0x6d, 0x2, 0x587, 0x589, 
    0x5, 0xda, 0x6e, 0x2, 0x588, 0x587, 0x3, 0x2, 0x2, 0x2, 0x589, 0x58c, 
    0x3, 0x2, 0x2, 0x2, 0x58a, 0x588, 0x3, 0x2, 0x2, 0x2, 0x58a, 0x58b, 
    0x3, 0x2, 0x2, 0x2, 0x58b, 0x59b, 0x3, 0x2, 0x2, 0x2, 0x58c, 0x58a, 
    0x3, 0x2, 0x2, 0x2, 0x58d, 0x591, 0x7, 0x4, 0x2, 0x2, 0x58e, 0x590, 
    0x5, 0xda, 0x6e, 0x2, 0x58f, 0x58e, 0x3, 0x2, 0x2, 0x2, 0x590, 0x593, 
    0x3, 0x2, 0x2, 0x2, 0x591, 0x58f, 0x3, 0x2, 0x2, 0x2, 0x591, 0x592, 
    0x3, 0x2, 0x2, 0x2, 0x592, 0x594, 0x3, 0x2, 0x2, 0x2, 0x593, 0x591, 
    0x3, 0x2, 0x2, 0x2, 0x594, 0x598, 0x7, 0x2f, 0x2, 0x2, 0x595, 0x597, 
    0x5, 0xda, 0x6e, 0x2, 0x596, 0x595, 0x3, 0x2, 0x2, 0x2, 0x597, 0x59a, 
    0x3, 0x2, 0x2, 0x2, 0x598, 0x596, 0x3, 0x2, 0x2, 0x2, 0x598, 0x599, 
    0x3, 0x2, 0x2, 0x2, 0x599, 0x59c, 0x3, 0x2, 0x2, 0x2, 0x59a, 0x598, 
    0x3, 0x2, 0x2, 0x2, 0x59b, 0x58d, 0x3, 0x2, 0x2, 0x2, 0x59b, 0x59c, 
    0x3, 0x2, 0x2, 0x2, 0x59c, 0x59d, 0x3, 0x2, 0x2, 0x2, 0x59d, 0x59e, 
    0x7, 0x9, 0x2, 0x2, 0x59e, 0xab, 0x3, 0x2, 0x2, 0x2, 0x59f, 0x5a3, 0x7, 
    0x54, 0x2, 0x2, 0x5a0, 0x5a2, 0x5, 0xda, 0x6e, 0x2, 0x5a1, 0x5a0, 0x3, 
    0x2, 0x2, 0x2, 0x5a2, 0x5a5, 0x3, 0x2, 0x2, 0x2, 0x5a3, 0x5a1, 0x3, 
    0x2, 0x2, 0x2, 0x5a3, 0x5a4, 0x3, 0x2, 0x2, 0x2, 0x5a4, 0x5a6, 0x3, 
    0x2, 0x2, 0x2, 0x5a5, 0x5a3, 0x3, 0x2, 0x2, 0x2, 0x5a6, 0x5a7, 0x7, 
    0x8, 0x2, 0x2, 0x5a7, 0x5a8, 0x5, 0xec, 0x77, 0x2, 0x5a8, 0x5a9, 0x7, 
    0xd, 0x2, 0x2, 0x5a9, 0xad, 0x3, 0x2, 0x2, 0x2, 0x5aa, 0x5ae, 0x7, 0x4e, 
    0x2, 0x2, 0x5ab, 0x5ad, 0x5, 0xda, 0x6e, 0x2, 0x5ac, 0x5ab, 0x3, 0x2, 
    0x2, 0x2, 0x5ad, 0x5b0, 0x3, 0x2, 0x2, 0x2, 0x5ae, 0x5ac, 0x3, 0x2, 
    0x2, 0x2, 0x5ae, 0x5af, 0x3, 0x2, 0x2, 0x2, 0x5af, 0x5b1, 0x3, 0x2, 
    0x2, 0x2, 0x5b0, 0x5ae, 0x3, 0x2, 0x2, 0x2, 0x5b1, 0x5b2, 0x7, 0x8, 
    0x2, 0x2, 0x5b2, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x5b3, 0x5b7, 0x5, 0xb2, 
    0x5a, 0x2, 0x5b4, 0x5b6, 0x5, 0xda, 0x6e, 0x2, 0x5b5, 0x5b4, 0x3, 0x2, 
    0x2, 0x2, 0x5b6, 0x5b9, 0x3, 0x2, 0x2, 0x2, 0x5b7, 0x5b5, 0x3, 0x2, 
    0x2, 0x2, 0x5b7, 0x5b8, 0x3, 0x2, 0x2, 0x2, 0x5b8, 0x5bb, 0x3, 0x2, 
    0x2, 0x2, 0x5b9, 0x5b7, 0x3, 0x2, 0x2, 0x2, 0x5ba, 0x5bc, 0x7, 0x1b, 
    0x2, 0x2, 0x5bb, 0x5ba, 0x3, 0x2, 0x2, 0x2, 0x5bb, 0x5bc, 0x3, 0x2, 
    0x2, 0x2, 0x5bc, 0x5c0, 0x3, 0x2, 0x2, 0x2, 0x5bd, 0x5bf, 0x5, 0xda, 
    0x6e, 0x2, 0x5be, 0x5bd, 0x3, 0x2, 0x2, 0x2, 0x5bf, 0x5c2, 0x3, 0x2, 
    0x2, 0x2, 0x5c0, 0x5be, 0x3, 0x2, 0x2, 0x2, 0x5c0, 0x5c1, 0x3, 0x2, 
    0x2, 0x2, 0x5c1, 0x5c3, 0x3, 0x2, 0x2, 0x2, 0x5c2, 0x5c0, 0x3, 0x2, 
    0x2, 0x2, 0x5c3, 0x5c7, 0x7, 0x67, 0x2, 0x2, 0x5c4, 0x5c6, 0x5, 0xda, 
    0x6e, 0x2, 0x5c5, 0x5c4, 0x3, 0x2, 0x2, 0x2, 0x5c6, 0x5c9, 0x3, 0x2, 
    0x2, 0x2, 0x5c7, 0x5c5, 0x3, 0x2, 0x2, 0x2, 0x5c7, 0x5c8, 0x3, 0x2, 
    0x2, 0x2, 0x5c8, 0x5ca, 0x3, 0x2, 0x2, 0x2, 0x5c9, 0x5c7, 0x3, 0x2, 
    0x2, 0x2, 0x5ca, 0x5ce, 0x7, 0x8, 0x2, 0x2, 0x5cb, 0x5cd, 0x5, 0xda, 
    0x6e, 0x2, 0x5cc, 0x5cb, 0x3, 0x2, 0x2, 0x2, 0x5cd, 0x5d0, 0x3, 0x2, 
    0x2, 0x2, 0x5ce, 0x5cc, 0x3, 0x2, 0x2, 0x2, 0x5ce, 0x5cf, 0x3, 0x2, 
    0x2, 0x2, 0x5cf, 0x5d2, 0x3, 0x2, 0x2, 0x2, 0x5d0, 0x5ce, 0x3, 0x2, 
    0x2, 0x2, 0x5d1, 0x5d3, 0x5, 0xb6, 0x5c, 0x2, 0x5d2, 0x5d1, 0x3, 0x2, 
    0x2, 0x2, 0x5d2, 0x5d3, 0x3, 0x2, 0x2, 0x2, 0x5d3, 0x5d4, 0x3, 0x2, 
    0x2, 0x2, 0x5d4, 0x5d5, 0x7, 0x9, 0x2, 0x2, 0x5d5, 0xb1, 0x3, 0x2, 0x2, 
    0x2, 0x5d6, 0x5e0, 0x5, 0xb4, 0x5b, 0x2, 0x5d7, 0x5d9, 0x5, 0xda, 0x6e, 
    0x2, 0x5d8, 0x5d7, 0x3, 0x2, 0x2, 0x2, 0x5d9, 0x5dc, 0x3, 0x2, 0x2, 
    0x2, 0x5da, 0x5d8, 0x3, 0x2, 0x2, 0x2, 0x5da, 0x5db, 0x3, 0x2, 0x2, 
    0x2, 0x5db, 0x5dd, 0x3, 0x2, 0x2, 0x2, 0x5dc, 0x5da, 0x3, 0x2, 0x2, 
    0x2, 0x5dd, 0x5df, 0x5, 0xb4, 0x5b, 0x2, 0x5de, 0x5da, 0x3, 0x2, 0x2, 
    0x2, 0x5df, 0x5e2, 0x3, 0x2, 0x2, 0x2, 0x5e0, 0x5de, 0x3, 0x2, 0x2, 
    0x2, 0x5e0, 0x5e1, 0x3, 0x2, 0x2, 0x2, 0x5e1, 0xb3, 0x3, 0x2, 0x2, 0x2, 
    0x5e2, 0x5e0, 0x3, 0x2, 0x2, 0x2, 0x5e3, 0x5e4, 0x9, 0xb, 0x2, 0x2, 
    0x5e4, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x5e5, 0x5e6, 0x8, 0x5c, 0x1, 0x2, 
    0x5e6, 0x5ea, 0x5, 0xba, 0x5e, 0x2, 0x5e7, 0x5e9, 0x5, 0xda, 0x6e, 0x2, 
    0x5e8, 0x5e7, 0x3, 0x2, 0x2, 0x2, 0x5e9, 0x5ec, 0x3, 0x2, 0x2, 0x2, 
    0x5ea, 0x5e8, 0x3, 0x2, 0x2, 0x2, 0x5ea, 0x5eb, 0x3, 0x2, 0x2, 0x2, 
    0x5eb, 0x5f1, 0x3, 0x2, 0x2, 0x2, 0x5ec, 0x5ea, 0x3, 0x2, 0x2, 0x2, 
    0x5ed, 0x5ee, 0xc, 0x3, 0x2, 0x2, 0x5ee, 0x5f0, 0x5, 0xb8, 0x5d, 0x2, 
    0x5ef, 0x5ed, 0x3, 0x2, 0x2, 0x2, 0x5f0, 0x5f3, 0x3, 0x2, 0x2, 0x2, 
    0x5f1, 0x5ef, 0x3, 0x2, 0x2, 0x2, 0x5f1, 0x5f2, 0x3, 0x2, 0x2, 0x2, 
    0x5f2, 0xb7, 0x3, 0x2, 0x2, 0x2, 0x5f3, 0x5f1, 0x3, 0x2, 0x2, 0x2, 0x5f4, 
    0x5f8, 0x7, 0x4, 0x2, 0x2, 0x5f5, 0x5f7, 0x5, 0xda, 0x6e, 0x2, 0x5f6, 
    0x5f5, 0x3, 0x2, 0x2, 0x2, 0x5f7, 0x5fa, 0x3, 0x2, 0x2, 0x2, 0x5f8, 
    0x5f6, 0x3, 0x2, 0x2, 0x2, 0x5f8, 0x5f9, 0x3, 0x2, 0x2, 0x2, 0x5f9, 
    0x5fb, 0x3, 0x2, 0x2, 0x2, 0x5fa, 0x5f8, 0x3, 0x2, 0x2, 0x2, 0x5fb, 
    0x5ff, 0x5, 0xba, 0x5e, 0x2, 0x5fc, 0x5fe, 0x5, 0xda, 0x6e, 0x2, 0x5fd, 
    0x5fc, 0x3, 0x2, 0x2, 0x2, 0x5fe, 0x601, 0x3, 0x2, 0x2, 0x2, 0x5ff, 
    0x5fd, 0x3, 0x2, 0x2, 0x2, 0x5ff, 0x600, 0x3, 0x2, 0x2, 0x2, 0x600, 
    0xb9, 0x3, 0x2, 0x2, 0x2, 0x601, 0x5ff, 0x3, 0x2, 0x2, 0x2, 0x602, 0x603, 
    0x5, 0x92, 0x4a, 0x2, 0x603, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x604, 0x606, 
    0x5, 0xbe, 0x60, 0x2, 0x605, 0x604, 0x3, 0x2, 0x2, 0x2, 0x606, 0x607, 
    0x3, 0x2, 0x2, 0x2, 0x607, 0x605, 0x3, 0x2, 0x2, 0x2, 0x607, 0x608, 
    0x3, 0x2, 0x2, 0x2, 0x608, 0x61b, 0x3, 0x2, 0x2, 0x2, 0x609, 0x60b, 
    0x5, 0xbe, 0x60, 0x2, 0x60a, 0x609, 0x3, 0x2, 0x2, 0x2, 0x60b, 0x60e, 
    0x3, 0x2, 0x2, 0x2, 0x60c, 0x60a, 0x3, 0x2, 0x2, 0x2, 0x60c, 0x60d, 
    0x3, 0x2, 0x2, 0x2, 0x60d, 0x616, 0x3, 0x2, 0x2, 0x2, 0x60e, 0x60c, 
    0x3, 0x2, 0x2, 0x2, 0x60f, 0x613, 0x5, 0xc0, 0x61, 0x2, 0x610, 0x612, 
    0x5, 0xbe, 0x60, 0x2, 0x611, 0x610, 0x3, 0x2, 0x2, 0x2, 0x612, 0x615, 
    0x3, 0x2, 0x2, 0x2, 0x613, 0x611, 0x3, 0x2, 0x2, 0x2, 0x613, 0x614, 
    0x3, 0x2, 0x2, 0x2, 0x614, 0x617, 0x3, 0x2, 0x2, 0x2, 0x615, 0x613, 
    0x3, 0x2, 0x2, 0x2, 0x616, 0x60f, 0x3, 0x2, 0x2, 0x2, 0x617, 0x618, 
    0x3, 0x2, 0x2, 0x2, 0x618, 0x616, 0x3, 0x2, 0x2, 0x2, 0x618, 0x619, 
    0x3, 0x2, 0x2, 0x2, 0x619, 0x61b, 0x3, 0x2, 0x2, 0x2, 0x61a, 0x605, 
    0x3, 0x2, 0x2, 0x2, 0x61a, 0x60c, 0x3, 0x2, 0x2, 0x2, 0x61b, 0xbd, 0x3, 
    0x2, 0x2, 0x2, 0x61c, 0x61f, 0x5, 0x2c, 0x17, 0x2, 0x61d, 0x61f, 0x5, 
    0xee, 0x78, 0x2, 0x61e, 0x61c, 0x3, 0x2, 0x2, 0x2, 0x61e, 0x61d, 0x3, 
    0x2, 0x2, 0x2, 0x61f, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x620, 0x622, 0x7, 0x8, 
    0x2, 0x2, 0x621, 0x623, 0x5, 0xc2, 0x62, 0x2, 0x622, 0x621, 0x3, 0x2, 
    0x2, 0x2, 0x622, 0x623, 0x3, 0x2, 0x2, 0x2, 0x623, 0x624, 0x3, 0x2, 
    0x2, 0x2, 0x624, 0x625, 0x7, 0x9, 0x2, 0x2, 0x625, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0x626, 0x627, 0x8, 0x62, 0x1, 0x2, 0x627, 0x628, 0x5, 0xbc, 0x5f, 
    0x2, 0x628, 0x62d, 0x3, 0x2, 0x2, 0x2, 0x629, 0x62a, 0xc, 0x3, 0x2, 
    0x2, 0x62a, 0x62c, 0x5, 0xc4, 0x63, 0x2, 0x62b, 0x629, 0x3, 0x2, 0x2, 
    0x2, 0x62c, 0x62f, 0x3, 0x2, 0x2, 0x2, 0x62d, 0x62b, 0x3, 0x2, 0x2, 
    0x2, 0x62d, 0x62e, 0x3, 0x2, 0x2, 0x2, 0x62e, 0xc3, 0x3, 0x2, 0x2, 0x2, 
    0x62f, 0x62d, 0x3, 0x2, 0x2, 0x2, 0x630, 0x631, 0x7, 0x4, 0x2, 0x2, 
    0x631, 0x632, 0x5, 0xbc, 0x5f, 0x2, 0x632, 0xc5, 0x3, 0x2, 0x2, 0x2, 
    0x633, 0x635, 0x9, 0xc, 0x2, 0x2, 0x634, 0x636, 0x5, 0xda, 0x6e, 0x2, 
    0x635, 0x634, 0x3, 0x2, 0x2, 0x2, 0x636, 0x637, 0x3, 0x2, 0x2, 0x2, 
    0x637, 0x635, 0x3, 0x2, 0x2, 0x2, 0x637, 0x638, 0x3, 0x2, 0x2, 0x2, 
    0x638, 0x639, 0x3, 0x2, 0x2, 0x2, 0x639, 0x63d, 0x7, 0x23, 0x2, 0x2, 
    0x63a, 0x63c, 0x5, 0xda, 0x6e, 0x2, 0x63b, 0x63a, 0x3, 0x2, 0x2, 0x2, 
    0x63c, 0x63f, 0x3, 0x2, 0x2, 0x2, 0x63d, 0x63b, 0x3, 0x2, 0x2, 0x2, 
    0x63d, 0x63e, 0x3, 0x2, 0x2, 0x2, 0x63e, 0x640, 0x3, 0x2, 0x2, 0x2, 
    0x63f, 0x63d, 0x3, 0x2, 0x2, 0x2, 0x640, 0x644, 0x7, 0x8, 0x2, 0x2, 
    0x641, 0x643, 0x5, 0xda, 0x6e, 0x2, 0x642, 0x641, 0x3, 0x2, 0x2, 0x2, 
    0x643, 0x646, 0x3, 0x2, 0x2, 0x2, 0x644, 0x642, 0x3, 0x2, 0x2, 0x2, 
    0x644, 0x645, 0x3, 0x2, 0x2, 0x2, 0x645, 0x64e, 0x3, 0x2, 0x2, 0x2, 
    0x646, 0x644, 0x3, 0x2, 0x2, 0x2, 0x647, 0x64b, 0x7, 0x41, 0x2, 0x2, 
    0x648, 0x64a, 0x5, 0xda, 0x6e, 0x2, 0x649, 0x648, 0x3, 0x2, 0x2, 0x2, 
    0x64a, 0x64d, 0x3, 0x2, 0x2, 0x2, 0x64b, 0x649, 0x3, 0x2, 0x2, 0x2, 
    0x64b, 0x64c, 0x3, 0x2, 0x2, 0x2, 0x64c, 0x64f, 0x3, 0x2, 0x2, 0x2, 
    0x64d, 0x64b, 0x3, 0x2, 0x2, 0x2, 0x64e, 0x647, 0x3, 0x2, 0x2, 0x2, 
    0x64e, 0x64f, 0x3, 0x2, 0x2, 0x2, 0x64f, 0x650, 0x3, 0x2, 0x2, 0x2, 
    0x650, 0x651, 0x7, 0x9, 0x2, 0x2, 0x651, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x652, 
    0x654, 0x9, 0xc, 0x2, 0x2, 0x653, 0x655, 0x5, 0xda, 0x6e, 0x2, 0x654, 
    0x653, 0x3, 0x2, 0x2, 0x2, 0x655, 0x656, 0x3, 0x2, 0x2, 0x2, 0x656, 
    0x654, 0x3, 0x2, 0x2, 0x2, 0x656, 0x657, 0x3, 0x2, 0x2, 0x2, 0x657, 
    0x658, 0x3, 0x2, 0x2, 0x2, 0x658, 0x65c, 0x7, 0x24, 0x2, 0x2, 0x659, 
    0x65b, 0x5, 0xda, 0x6e, 0x2, 0x65a, 0x659, 0x3, 0x2, 0x2, 0x2, 0x65b, 
    0x65e, 0x3, 0x2, 0x2, 0x2, 0x65c, 0x65a, 0x3, 0x2, 0x2, 0x2, 0x65c, 
    0x65d, 0x3, 0x2, 0x2, 0x2, 0x65d, 0x65f, 0x3, 0x2, 0x2, 0x2, 0x65e, 
    0x65c, 0x3, 0x2, 0x2, 0x2, 0x65f, 0x663, 0x7, 0x8, 0x2, 0x2, 0x660, 
    0x662, 0x5, 0xda, 0x6e, 0x2, 0x661, 0x660, 0x3, 0x2, 0x2, 0x2, 0x662, 
    0x665, 0x3, 0x2, 0x2, 0x2, 0x663, 0x661, 0x3, 0x2, 0x2, 0x2, 0x663, 
    0x664, 0x3, 0x2, 0x2, 0x2, 0x664, 0x66d, 0x3, 0x2, 0x2, 0x2, 0x665, 
    0x663, 0x3, 0x2, 0x2, 0x2, 0x666, 0x66a, 0x7, 0x41, 0x2, 0x2, 0x667, 
    0x669, 0x5, 0xda, 0x6e, 0x2, 0x668, 0x667, 0x3, 0x2, 0x2, 0x2, 0x669, 
    0x66c, 0x3, 0x2, 0x2, 0x2, 0x66a, 0x668, 0x3, 0x2, 0x2, 0x2, 0x66a, 
    0x66b, 0x3, 0x2, 0x2, 0x2, 0x66b, 0x66e, 0x3, 0x2, 0x2, 0x2, 0x66c, 
    0x66a, 0x3, 0x2, 0x2, 0x2, 0x66d, 0x666, 0x3, 0x2, 0x2, 0x2, 0x66d, 
    0x66e, 0x3, 0x2, 0x2, 0x2, 0x66e, 0x66f, 0x3, 0x2, 0x2, 0x2, 0x66f, 
    0x670, 0x7, 0x9, 0x2, 0x2, 0x670, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x671, 0x673, 
    0x9, 0xc, 0x2, 0x2, 0x672, 0x674, 0x5, 0xda, 0x6e, 0x2, 0x673, 0x672, 
    0x3, 0x2, 0x2, 0x2, 0x674, 0x675, 0x3, 0x2, 0x2, 0x2, 0x675, 0x673, 
    0x3, 0x2, 0x2, 0x2, 0x675, 0x676, 0x3, 0x2, 0x2, 0x2, 0x676, 0x677, 
    0x3, 0x2, 0x2, 0x2, 0x677, 0x67b, 0x7, 0x25, 0x2, 0x2, 0x678, 0x67a, 
    0x5, 0xda, 0x6e, 0x2, 0x679, 0x678, 0x3, 0x2, 0x2, 0x2, 0x67a, 0x67d, 
    0x3, 0x2, 0x2, 0x2, 0x67b, 0x679, 0x3, 0x2, 0x2, 0x2, 0x67b, 0x67c, 
    0x3, 0x2, 0x2, 0x2, 0x67c, 0x67e, 0x3, 0x2, 0x2, 0x2, 0x67d, 0x67b, 
    0x3, 0x2, 0x2, 0x2, 0x67e, 0x682, 0x7, 0x8, 0x2, 0x2, 0x67f, 0x681, 
    0x5, 0xda, 0x6e, 0x2, 0x680, 0x67f, 0x3, 0x2, 0x2, 0x2, 0x681, 0x684, 
    0x3, 0x2, 0x2, 0x2, 0x682, 0x680, 0x3, 0x2, 0x2, 0x2, 0x682, 0x683, 
    0x3, 0x2, 0x2, 0x2, 0x683, 0x68c, 0x3, 0x2, 0x2, 0x2, 0x684, 0x682, 
    0x3, 0x2, 0x2, 0x2, 0x685, 0x689, 0x7, 0x41, 0x2, 0x2, 0x686, 0x688, 
    0x5, 0xda, 0x6e, 0x2, 0x687, 0x686, 0x3, 0x2, 0x2, 0x2, 0x688, 0x68b, 
    0x3, 0x2, 0x2, 0x2, 0x689, 0x687, 0x3, 0x2, 0x2, 0x2, 0x689, 0x68a, 
    0x3, 0x2, 0x2, 0x2, 0x68a, 0x68d, 0x3, 0x2, 0x2, 0x2, 0x68b, 0x689, 
    0x3, 0x2, 0x2, 0x2, 0x68c, 0x685, 0x3, 0x2, 0x2, 0x2, 0x68c, 0x68d, 
    0x3, 0x2, 0x2, 0x2, 0x68d, 0x68e, 0x3, 0x2, 0x2, 0x2, 0x68e, 0x68f, 
    0x7, 0x9, 0x2, 0x2, 0x68f, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x690, 0x692, 0x7, 
    0x42, 0x2, 0x2, 0x691, 0x693, 0x5, 0xda, 0x6e, 0x2, 0x692, 0x691, 0x3, 
    0x2, 0x2, 0x2, 0x693, 0x694, 0x3, 0x2, 0x2, 0x2, 0x694, 0x692, 0x3, 
    0x2, 0x2, 0x2, 0x694, 0x695, 0x3, 0x2, 0x2, 0x2, 0x695, 0x696, 0x3, 
    0x2, 0x2, 0x2, 0x696, 0x69a, 0x7, 0x26, 0x2, 0x2, 0x697, 0x699, 0x5, 
    0xda, 0x6e, 0x2, 0x698, 0x697, 0x3, 0x2, 0x2, 0x2, 0x699, 0x69c, 0x3, 
    0x2, 0x2, 0x2, 0x69a, 0x698, 0x3, 0x2, 0x2, 0x2, 0x69a, 0x69b, 0x3, 
    0x2, 0x2, 0x2, 0x69b, 0x69d, 0x3, 0x2, 0x2, 0x2, 0x69c, 0x69a, 0x3, 
    0x2, 0x2, 0x2, 0x69d, 0x69e, 0x7, 0x8, 0x2, 0x2, 0x69e, 0x69f, 0x5, 
    0xea, 0x76, 0x2, 0x69f, 0x6a0, 0x7, 0x9, 0x2, 0x2, 0x6a0, 0xcd, 0x3, 
    0x2, 0x2, 0x2, 0x6a1, 0x6a3, 0x5, 0xb4, 0x5b, 0x2, 0x6a2, 0x6a4, 0x5, 
    0xda, 0x6e, 0x2, 0x6a3, 0x6a2, 0x3, 0x2, 0x2, 0x2, 0x6a4, 0x6a5, 0x3, 
    0x2, 0x2, 0x2, 0x6a5, 0x6a3, 0x3, 0x2, 0x2, 0x2, 0x6a5, 0x6a6, 0x3, 
    0x2, 0x2, 0x2, 0x6a6, 0x6a7, 0x3, 0x2, 0x2, 0x2, 0x6a7, 0x6ab, 0x7, 
    0x27, 0x2, 0x2, 0x6a8, 0x6aa, 0x5, 0xda, 0x6e, 0x2, 0x6a9, 0x6a8, 0x3, 
    0x2, 0x2, 0x2, 0x6aa, 0x6ad, 0x3, 0x2, 0x2, 0x2, 0x6ab, 0x6a9, 0x3, 
    0x2, 0x2, 0x2, 0x6ab, 0x6ac, 0x3, 0x2, 0x2, 0x2, 0x6ac, 0x6ae, 0x3, 
    0x2, 0x2, 0x2, 0x6ad, 0x6ab, 0x3, 0x2, 0x2, 0x2, 0x6ae, 0x6b2, 0x7, 
    0x8, 0x2, 0x2, 0x6af, 0x6b1, 0x5, 0xda, 0x6e, 0x2, 0x6b0, 0x6af, 0x3, 
    0x2, 0x2, 0x2, 0x6b1, 0x6b4, 0x3, 0x2, 0x2, 0x2, 0x6b2, 0x6b0, 0x3, 
    0x2, 0x2, 0x2, 0x6b2, 0x6b3, 0x3, 0x2, 0x2, 0x2, 0x6b3, 0x6bc, 0x3, 
    0x2, 0x2, 0x2, 0x6b4, 0x6b2, 0x3, 0x2, 0x2, 0x2, 0x6b5, 0x6b9, 0x7, 
    0x41, 0x2, 0x2, 0x6b6, 0x6b8, 0x5, 0xda, 0x6e, 0x2, 0x6b7, 0x6b6, 0x3, 
    0x2, 0x2, 0x2, 0x6b8, 0x6bb, 0x3, 0x2, 0x2, 0x2, 0x6b9, 0x6b7, 0x3, 
    0x2, 0x2, 0x2, 0x6b9, 0x6ba, 0x3, 0x2, 0x2, 0x2, 0x6ba, 0x6bd, 0x3, 
    0x2, 0x2, 0x2, 0x6bb, 0x6b9, 0x3, 0x2, 0x2, 0x2, 0x6bc, 0x6b5, 0x3, 
    0x2, 0x2, 0x2, 0x6bc, 0x6bd, 0x3, 0x2, 0x2, 0x2, 0x6bd, 0x6be, 0x3, 
    0x2, 0x2, 0x2, 0x6be, 0x6bf, 0x7, 0x9, 0x2, 0x2, 0x6bf, 0xcf, 0x3, 0x2, 
    0x2, 0x2, 0x6c0, 0x6c2, 0x9, 0xc, 0x2, 0x2, 0x6c1, 0x6c3, 0x5, 0xda, 
    0x6e, 0x2, 0x6c2, 0x6c1, 0x3, 0x2, 0x2, 0x2, 0x6c3, 0x6c4, 0x3, 0x2, 
    0x2, 0x2, 0x6c4, 0x6c2, 0x3, 0x2, 0x2, 0x2, 0x6c4, 0x6c5, 0x3, 0x2, 
    0x2, 0x2, 0x6c5, 0x6c6, 0x3, 0x2, 0x2, 0x2, 0x6c6, 0x6ca, 0x7, 0x28, 
    0x2, 0x2, 0x6c7, 0x6c9, 0x5, 0xda, 0x6e, 0x2, 0x6c8, 0x6c7, 0x3, 0x2, 
    0x2, 0x2, 0x6c9, 0x6cc, 0x3, 0x2, 0x2, 0x2, 0x6ca, 0x6c8, 0x3, 0x2, 
    0x2, 0x2, 0x6ca, 0x6cb, 0x3, 0x2, 0x2, 0x2, 0x6cb, 0x6cd, 0x3, 0x2, 
    0x2, 0x2, 0x6cc, 0x6ca, 0x3, 0x2, 0x2, 0x2, 0x6cd, 0x6d1, 0x7, 0x8, 
    0x2, 0x2, 0x6ce, 0x6d0, 0x5, 0xda, 0x6e, 0x2, 0x6cf, 0x6ce, 0x3, 0x2, 
    0x2, 0x2, 0x6d0, 0x6d3, 0x3, 0x2, 0x2, 0x2, 0x6d1, 0x6cf, 0x3, 0x2, 
    0x2, 0x2, 0x6d1, 0x6d2, 0x3, 0x2, 0x2, 0x2, 0x6d2, 0x6db, 0x3, 0x2, 
    0x2, 0x2, 0x6d3, 0x6d1, 0x3, 0x2, 0x2, 0x2, 0x6d4, 0x6d8, 0x7, 0x41, 
    0x2, 0x2, 0x6d5, 0x6d7, 0x5, 0xda, 0x6e, 0x2, 0x6d6, 0x6d5, 0x3, 0x2, 
    0x2, 0x2, 0x6d7, 0x6da, 0x3, 0x2, 0x2, 0x2, 0x6d8, 0x6d6, 0x3, 0x2, 
    0x2, 0x2, 0x6d8, 0x6d9, 0x3, 0x2, 0x2, 0x2, 0x6d9, 0x6dc, 0x3, 0x2, 
    0x2, 0x2, 0x6da, 0x6d8, 0x3, 0x2, 0x2, 0x2, 0x6db, 0x6d4, 0x3, 0x2, 
    0x2, 0x2, 0x6db, 0x6dc, 0x3, 0x2, 0x2, 0x2, 0x6dc, 0x6dd, 0x3, 0x2, 
    0x2, 0x2, 0x6dd, 0x6de, 0x7, 0x9, 0x2, 0x2, 0x6de, 0xd1, 0x3, 0x2, 0x2, 
    0x2, 0x6df, 0x6e1, 0x5, 0xb4, 0x5b, 0x2, 0x6e0, 0x6e2, 0x5, 0xda, 0x6e, 
    0x2, 0x6e1, 0x6e0, 0x3, 0x2, 0x2, 0x2, 0x6e2, 0x6e3, 0x3, 0x2, 0x2, 
    0x2, 0x6e3, 0x6e1, 0x3, 0x2, 0x2, 0x2, 0x6e3, 0x6e4, 0x3, 0x2, 0x2, 
    0x2, 0x6e4, 0x6e5, 0x3, 0x2, 0x2, 0x2, 0x6e5, 0x6e9, 0x7, 0x29, 0x2, 
    0x2, 0x6e6, 0x6e8, 0x5, 0xda, 0x6e, 0x2, 0x6e7, 0x6e6, 0x3, 0x2, 0x2, 
    0x2, 0x6e8, 0x6eb, 0x3, 0x2, 0x2, 0x2, 0x6e9, 0x6e7, 0x3, 0x2, 0x2, 
    0x2, 0x6e9, 0x6ea, 0x3, 0x2, 0x2, 0x2, 0x6ea, 0x6ec, 0x3, 0x2, 0x2, 
    0x2, 0x6eb, 0x6e9, 0x3, 0x2, 0x2, 0x2, 0x6ec, 0x6f0, 0x7, 0x8, 0x2, 
    0x2, 0x6ed, 0x6ef, 0x5, 0xda, 0x6e, 0x2, 0x6ee, 0x6ed, 0x3, 0x2, 0x2, 
    0x2, 0x6ef, 0x6f2, 0x3, 0x2, 0x2, 0x2, 0x6f0, 0x6ee, 0x3, 0x2, 0x2, 
    0x2, 0x6f0, 0x6f1, 0x3, 0x2, 0x2, 0x2, 0x6f1, 0x6f3, 0x3, 0x2, 0x2, 
    0x2, 0x6f2, 0x6f0, 0x3, 0x2, 0x2, 0x2, 0x6f3, 0x6f7, 0x7, 0x36, 0x2, 
    0x2, 0x6f4, 0x6f6, 0x5, 0xda, 0x6e, 0x2, 0x6f5, 0x6f4, 0x3, 0x2, 0x2, 
    0x2, 0x6f6, 0x6f9, 0x3, 0x2, 0x2, 0x2, 0x6f7, 0x6f5, 0x3, 0x2, 0x2, 
    0x2, 0x6f7, 0x6f8, 0x3, 0x2, 0x2, 0x2, 0x6f8, 0x6fa, 0x3, 0x2, 0x2, 
    0x2, 0x6f9, 0x6f7, 0x3, 0x2, 0x2, 0x2, 0x6fa, 0x6fe, 0x7, 0x42, 0x2, 
    0x2, 0x6fb, 0x6fd, 0x5, 0xda, 0x6e, 0x2, 0x6fc, 0x6fb, 0x3, 0x2, 0x2, 
    0x2, 0x6fd, 0x700, 0x3, 0x2, 0x2, 0x2, 0x6fe, 0x6fc, 0x3, 0x2, 0x2, 
    0x2, 0x6fe, 0x6ff, 0x3, 0x2, 0x2, 0x2, 0x6ff, 0x701, 0x3, 0x2, 0x2, 
    0x2, 0x700, 0x6fe, 0x3, 0x2, 0x2, 0x2, 0x701, 0x705, 0x7, 0x67, 0x2, 
    0x2, 0x702, 0x704, 0x5, 0xda, 0x6e, 0x2, 0x703, 0x702, 0x3, 0x2, 0x2, 
    0x2, 0x704, 0x707, 0x3, 0x2, 0x2, 0x2, 0x705, 0x703, 0x3, 0x2, 0x2, 
    0x2, 0x705, 0x706, 0x3, 0x2, 0x2, 0x2, 0x706, 0x708, 0x3, 0x2, 0x2, 
    0x2, 0x707, 0x705, 0x3, 0x2, 0x2, 0x2, 0x708, 0x709, 0x7, 0x9, 0x2, 
    0x2, 0x709, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x70a, 0x70c, 0x9, 0xc, 0x2, 0x2, 
    0x70b, 0x70d, 0x5, 0xda, 0x6e, 0x2, 0x70c, 0x70b, 0x3, 0x2, 0x2, 0x2, 
    0x70d, 0x70e, 0x3, 0x2, 0x2, 0x2, 0x70e, 0x70c, 0x3, 0x2, 0x2, 0x2, 
    0x70e, 0x70f, 0x3, 0x2, 0x2, 0x2, 0x70f, 0x710, 0x3, 0x2, 0x2, 0x2, 
    0x710, 0x714, 0x7, 0x2a, 0x2, 0x2, 0x711, 0x713, 0x5, 0xda, 0x6e, 0x2, 
    0x712, 0x711, 0x3, 0x2, 0x2, 0x2, 0x713, 0x716, 0x3, 0x2, 0x2, 0x2, 
    0x714, 0x712, 0x3, 0x2, 0x2, 0x2, 0x714, 0x715, 0x3, 0x2, 0x2, 0x2, 
    0x715, 0x717, 0x3, 0x2, 0x2, 0x2, 0x716, 0x714, 0x3, 0x2, 0x2, 0x2, 
    0x717, 0x71b, 0x7, 0x8, 0x2, 0x2, 0x718, 0x71a, 0x5, 0xda, 0x6e, 0x2, 
    0x719, 0x718, 0x3, 0x2, 0x2, 0x2, 0x71a, 0x71d, 0x3, 0x2, 0x2, 0x2, 
    0x71b, 0x719, 0x3, 0x2, 0x2, 0x2, 0x71b, 0x71c, 0x3, 0x2, 0x2, 0x2, 
    0x71c, 0x725, 0x3, 0x2, 0x2, 0x2, 0x71d, 0x71b, 0x3, 0x2, 0x2, 0x2, 
    0x71e, 0x722, 0x7, 0x41, 0x2, 0x2, 0x71f, 0x721, 0x5, 0xda, 0x6e, 0x2, 
    0x720, 0x71f, 0x3, 0x2, 0x2, 0x2, 0x721, 0x724, 0x3, 0x2, 0x2, 0x2, 
    0x722, 0x720, 0x3, 0x2, 0x2, 0x2, 0x722, 0x723, 0x3, 0x2, 0x2, 0x2, 
    0x723, 0x726, 0x3, 0x2, 0x2, 0x2, 0x724, 0x722, 0x3, 0x2, 0x2, 0x2, 
    0x725, 0x71e, 0x3, 0x2, 0x2, 0x2, 0x725, 0x726, 0x3, 0x2, 0x2, 0x2, 
    0x726, 0x727, 0x3, 0x2, 0x2, 0x2, 0x727, 0x728, 0x7, 0x9, 0x2, 0x2, 
    0x728, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x729, 0x72b, 0x9, 0xc, 0x2, 0x2, 0x72a, 
    0x72c, 0x5, 0xda, 0x6e, 0x2, 0x72b, 0x72a, 0x3, 0x2, 0x2, 0x2, 0x72c, 
    0x72d, 0x3, 0x2, 0x2, 0x2, 0x72d, 0x72b, 0x3, 0x2, 0x2, 0x2, 0x72d, 
    0x72e, 0x3, 0x2, 0x2, 0x2, 0x72e, 0x72f, 0x3, 0x2, 0x2, 0x2, 0x72f, 
    0x733, 0x7, 0x2b, 0x2, 0x2, 0x730, 0x732, 0x5, 0xda, 0x6e, 0x2, 0x731, 
    0x730, 0x3, 0x2, 0x2, 0x2, 0x732, 0x735, 0x3, 0x2, 0x2, 0x2, 0x733, 
    0x731, 0x3, 0x2, 0x2, 0x2, 0x733, 0x734, 0x3, 0x2, 0x2, 0x2, 0x734, 
    0x736, 0x3, 0x2, 0x2, 0x2, 0x735, 0x733, 0x3, 0x2, 0x2, 0x2, 0x736, 
    0x73a, 0x7, 0x8, 0x2, 0x2, 0x737, 0x739, 0x5, 0xda, 0x6e, 0x2, 0x738, 
    0x737, 0x3, 0x2, 0x2, 0x2, 0x739, 0x73c, 0x3, 0x2, 0x2, 0x2, 0x73a, 
    0x738, 0x3, 0x2, 0x2, 0x2, 0x73a, 0x73b, 0x3, 0x2, 0x2, 0x2, 0x73b, 
    0x73d, 0x3, 0x2, 0x2, 0x2, 0x73c, 0x73a, 0x3, 0x2, 0x2, 0x2, 0x73d, 
    0x741, 0x7, 0x36, 0x2, 0x2, 0x73e, 0x740, 0x5, 0xda, 0x6e, 0x2, 0x73f, 
    0x73e, 0x3, 0x2, 0x2, 0x2, 0x740, 0x743, 0x3, 0x2, 0x2, 0x2, 0x741, 
    0x73f, 0x3, 0x2, 0x2, 0x2, 0x741, 0x742, 0x3, 0x2, 0x2, 0x2, 0x742, 
    0x744, 0x3, 0x2, 0x2, 0x2, 0x743, 0x741, 0x3, 0x2, 0x2, 0x2, 0x744, 
    0x748, 0x7, 0x42, 0x2, 0x2, 0x745, 0x747, 0x5, 0xda, 0x6e, 0x2, 0x746, 
    0x745, 0x3, 0x2, 0x2, 0x2, 0x747, 0x74a, 0x3, 0x2, 0x2, 0x2, 0x748, 
    0x746, 0x3, 0x2, 0x2, 0x2, 0x748, 0x749, 0x3, 0x2, 0x2, 0x2, 0x749, 
    0x74b, 0x3, 0x2, 0x2, 0x2, 0x74a, 0x748, 0x3, 0x2, 0x2, 0x2, 0x74b, 
    0x74f, 0x7, 0x67, 0x2, 0x2, 0x74c, 0x74e, 0x5, 0xda, 0x6e, 0x2, 0x74d, 
    0x74c, 0x3, 0x2, 0x2, 0x2, 0x74e, 0x751, 0x3, 0x2, 0x2, 0x2, 0x74f, 
    0x74d, 0x3, 0x2, 0x2, 0x2, 0x74f, 0x750, 0x3, 0x2, 0x2, 0x2, 0x750, 
    0x752, 0x3, 0x2, 0x2, 0x2, 0x751, 0x74f, 0x3, 0x2, 0x2, 0x2, 0x752, 
    0x756, 0x7, 0x4, 0x2, 0x2, 0x753, 0x755, 0x5, 0xda, 0x6e, 0x2, 0x754, 
    0x753, 0x3, 0x2, 0x2, 0x2, 0x755, 0x758, 0x3, 0x2, 0x2, 0x2, 0x756, 
    0x754, 0x3, 0x2, 0x2, 0x2, 0x756, 0x757, 0x3, 0x2, 0x2, 0x2, 0x757, 
    0x759, 0x3, 0x2, 0x2, 0x2, 0x758, 0x756, 0x3, 0x2, 0x2, 0x2, 0x759, 
    0x75d, 0x7, 0x36, 0x2, 0x2, 0x75a, 0x75c, 0x5, 0xda, 0x6e, 0x2, 0x75b, 
    0x75a, 0x3, 0x2, 0x2, 0x2, 0x75c, 0x75f, 0x3, 0x2, 0x2, 0x2, 0x75d, 
    0x75b, 0x3, 0x2, 0x2, 0x2, 0x75d, 0x75e, 0x3, 0x2, 0x2, 0x2, 0x75e, 
    0x760, 0x3, 0x2, 0x2, 0x2, 0x75f, 0x75d, 0x3, 0x2, 0x2, 0x2, 0x760, 
    0x764, 0x7, 0x44, 0x2, 0x2, 0x761, 0x763, 0x5, 0xda, 0x6e, 0x2, 0x762, 
    0x761, 0x3, 0x2, 0x2, 0x2, 0x763, 0x766, 0x3, 0x2, 0x2, 0x2, 0x764, 
    0x762, 0x3, 0x2, 0x2, 0x2, 0x764, 0x765, 0x3, 0x2, 0x2, 0x2, 0x765, 
    0x767, 0x3, 0x2, 0x2, 0x2, 0x766, 0x764, 0x3, 0x2, 0x2, 0x2, 0x767, 
    0x76b, 0x7, 0x1b, 0x2, 0x2, 0x768, 0x76a, 0x5, 0xda, 0x6e, 0x2, 0x769, 
    0x768, 0x3, 0x2, 0x2, 0x2, 0x76a, 0x76d, 0x3, 0x2, 0x2, 0x2, 0x76b, 
    0x769, 0x3, 0x2, 0x2, 0x2, 0x76b, 0x76c, 0x3, 0x2, 0x2, 0x2, 0x76c, 
    0x76e, 0x3, 0x2, 0x2, 0x2, 0x76d, 0x76b, 0x3, 0x2, 0x2, 0x2, 0x76e, 
    0x772, 0x7, 0x67, 0x2, 0x2, 0x76f, 0x771, 0x5, 0xda, 0x6e, 0x2, 0x770, 
    0x76f, 0x3, 0x2, 0x2, 0x2, 0x771, 0x774, 0x3, 0x2, 0x2, 0x2, 0x772, 
    0x770, 0x3, 0x2, 0x2, 0x2, 0x772, 0x773, 0x3, 0x2, 0x2, 0x2, 0x773, 
    0x775, 0x3, 0x2, 0x2, 0x2, 0x774, 0x772, 0x3, 0x2, 0x2, 0x2, 0x775, 
    0x779, 0x7, 0x4, 0x2, 0x2, 0x776, 0x778, 0x5, 0xda, 0x6e, 0x2, 0x777, 
    0x776, 0x3, 0x2, 0x2, 0x2, 0x778, 0x77b, 0x3, 0x2, 0x2, 0x2, 0x779, 
    0x777, 0x3, 0x2, 0x2, 0x2, 0x779, 0x77a, 0x3, 0x2, 0x2, 0x2, 0x77a, 
    0x77c, 0x3, 0x2, 0x2, 0x2, 0x77b, 0x779, 0x3, 0x2, 0x2, 0x2, 0x77c, 
    0x780, 0x7, 0x36, 0x2, 0x2, 0x77d, 0x77f, 0x5, 0xda, 0x6e, 0x2, 0x77e, 
    0x77d, 0x3, 0x2, 0x2, 0x2, 0x77f, 0x782, 0x3, 0x2, 0x2, 0x2, 0x780, 
    0x77e, 0x3, 0x2, 0x2, 0x2, 0x780, 0x781, 0x3, 0x2, 0x2, 0x2, 0x781, 
    0x783, 0x3, 0x2, 0x2, 0x2, 0x782, 0x780, 0x3, 0x2, 0x2, 0x2, 0x783, 
    0x787, 0x7, 0x3f, 0x2, 0x2, 0x784, 0x786, 0x5, 0xda, 0x6e, 0x2, 0x785, 
    0x784, 0x3, 0x2, 0x2, 0x2, 0x786, 0x789, 0x3, 0x2, 0x2, 0x2, 0x787, 
    0x785, 0x3, 0x2, 0x2, 0x2, 0x787, 0x788, 0x3, 0x2, 0x2, 0x2, 0x788, 
    0x78a, 0x3, 0x2, 0x2, 0x2, 0x789, 0x787, 0x3, 0x2, 0x2, 0x2, 0x78a, 
    0x78e, 0x7, 0x1b, 0x2, 0x2, 0x78b, 0x78d, 0x5, 0xda, 0x6e, 0x2, 0x78c, 
    0x78b, 0x3, 0x2, 0x2, 0x2, 0x78d, 0x790, 0x3, 0x2, 0x2, 0x2, 0x78e, 
    0x78c, 0x3, 0x2, 0x2, 0x2, 0x78e, 0x78f, 0x3, 0x2, 0x2, 0x2, 0x78f, 
    0x791, 0x3, 0x2, 0x2, 0x2, 0x790, 0x78e, 0x3, 0x2, 0x2, 0x2, 0x791, 
    0x795, 0x7, 0x67, 0x2, 0x2, 0x792, 0x794, 0x5, 0xda, 0x6e, 0x2, 0x793, 
    0x792, 0x3, 0x2, 0x2, 0x2, 0x794, 0x797, 0x3, 0x2, 0x2, 0x2, 0x795, 
    0x793, 0x3, 0x2, 0x2, 0x2, 0x795, 0x796, 0x3, 0x2, 0x2, 0x2, 0x796, 
    0x798, 0x3, 0x2, 0x2, 0x2, 0x797, 0x795, 0x3, 0x2, 0x2, 0x2, 0x798, 
    0x79c, 0x7, 0x4, 0x2, 0x2, 0x799, 0x79b, 0x5, 0xda, 0x6e, 0x2, 0x79a, 
    0x799, 0x3, 0x2, 0x2, 0x2, 0x79b, 0x79e, 0x3, 0x2, 0x2, 0x2, 0x79c, 
    0x79a, 0x3, 0x2, 0x2, 0x2, 0x79c, 0x79d, 0x3, 0x2, 0x2, 0x2, 0x79d, 
    0x79f, 0x3, 0x2, 0x2, 0x2, 0x79e, 0x79c, 0x3, 0x2, 0x2, 0x2, 0x79f, 
    0x7a3, 0x7, 0x36, 0x2, 0x2, 0x7a0, 0x7a2, 0x5, 0xda, 0x6e, 0x2, 0x7a1, 
    0x7a0, 0x3, 0x2, 0x2, 0x2, 0x7a2, 0x7a5, 0x3, 0x2, 0x2, 0x2, 0x7a3, 
    0x7a1, 0x3, 0x2, 0x2, 0x2, 0x7a3, 0x7a4, 0x3, 0x2, 0x2, 0x2, 0x7a4, 
    0x7a6, 0x3, 0x2, 0x2, 0x2, 0x7a5, 0x7a3, 0x3, 0x2, 0x2, 0x2, 0x7a6, 
    0x7aa, 0x7, 0x47, 0x2, 0x2, 0x7a7, 0x7a9, 0x5, 0xda, 0x6e, 0x2, 0x7a8, 
    0x7a7, 0x3, 0x2, 0x2, 0x2, 0x7a9, 0x7ac, 0x3, 0x2, 0x2, 0x2, 0x7aa, 
    0x7a8, 0x3, 0x2, 0x2, 0x2, 0x7aa, 0x7ab, 0x3, 0x2, 0x2, 0x2, 0x7ab, 
    0x7ad, 0x3, 0x2, 0x2, 0x2, 0x7ac, 0x7aa, 0x3, 0x2, 0x2, 0x2, 0x7ad, 
    0x7b1, 0x7, 0x1b, 0x2, 0x2, 0x7ae, 0x7b0, 0x5, 0xda, 0x6e, 0x2, 0x7af, 
    0x7ae, 0x3, 0x2, 0x2, 0x2, 0x7b0, 0x7b3, 0x3, 0x2, 0x2, 0x2, 0x7b1, 
    0x7af, 0x3, 0x2, 0x2, 0x2, 0x7b1, 0x7b2, 0x3, 0x2, 0x2, 0x2, 0x7b2, 
    0x7b4, 0x3, 0x2, 0x2, 0x2, 0x7b3, 0x7b1, 0x3, 0x2, 0x2, 0x2, 0x7b4, 
    0x7b8, 0x7, 0x67, 0x2, 0x2, 0x7b5, 0x7b7, 0x5, 0xda, 0x6e, 0x2, 0x7b6, 
    0x7b5, 0x3, 0x2, 0x2, 0x2, 0x7b7, 0x7ba, 0x3, 0x2, 0x2, 0x2, 0x7b8, 
    0x7b6, 0x3, 0x2, 0x2, 0x2, 0x7b8, 0x7b9, 0x3, 0x2, 0x2, 0x2, 0x7b9, 
    0x7bb, 0x3, 0x2, 0x2, 0x2, 0x7ba, 0x7b8, 0x3, 0x2, 0x2, 0x2, 0x7bb, 
    0x7bc, 0x7, 0x9, 0x2, 0x2, 0x7bc, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x7bd, 0x7be, 
    0x9, 0xd, 0x2, 0x2, 0x7be, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x7bf, 0x7c0, 0x9, 
    0xe, 0x2, 0x2, 0x7c0, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x7c1, 0x7c3, 0x9, 0xf, 
    0x2, 0x2, 0x7c2, 0x7c1, 0x3, 0x2, 0x2, 0x2, 0x7c2, 0x7c3, 0x3, 0x2, 
    0x2, 0x2, 0x7c3, 0x7c4, 0x3, 0x2, 0x2, 0x2, 0x7c4, 0x7c5, 0x7, 0x68, 
    0x2, 0x2, 0x7c5, 0xdd, 0x3, 0x2, 0x2, 0x2, 0x7c6, 0x7c7, 0x7, 0x6b, 
    0x2, 0x2, 0x7c7, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x7c8, 0x7c9, 0x7, 0x1d, 
    0x2, 0x2, 0x7c9, 0x7ca, 0x7, 0x2c, 0x2, 0x2, 0x7ca, 0x7cb, 0x7, 0x2d, 
    0x2, 0x2, 0x7cb, 0x7cc, 0x7, 0x67, 0x2, 0x2, 0x7cc, 0x7cd, 0x7, 0x2c, 
    0x2, 0x2, 0x7cd, 0xe1, 0x3, 0x2, 0x2, 0x2, 0x7ce, 0x7cf, 0x7, 0x1d, 
    0x2, 0x2, 0x7cf, 0x7d0, 0x7, 0x2c, 0x2, 0x2, 0x7d0, 0x7d1, 0x7, 0x2e, 
    0x2, 0x2, 0x7d1, 0x7d2, 0x7, 0x67, 0x2, 0x2, 0x7d2, 0x7d3, 0x7, 0x2c, 
    0x2, 0x2, 0x7d3, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x7d4, 0x7db, 0x7, 0x8, 0x2, 
    0x2, 0x7d5, 0x7d7, 0xa, 0x10, 0x2, 0x2, 0x7d6, 0x7d5, 0x3, 0x2, 0x2, 
    0x2, 0x7d7, 0x7d8, 0x3, 0x2, 0x2, 0x2, 0x7d8, 0x7d6, 0x3, 0x2, 0x2, 
    0x2, 0x7d8, 0x7d9, 0x3, 0x2, 0x2, 0x2, 0x7d9, 0x7dc, 0x3, 0x2, 0x2, 
    0x2, 0x7da, 0x7dc, 0x5, 0xe4, 0x73, 0x2, 0x7db, 0x7d6, 0x3, 0x2, 0x2, 
    0x2, 0x7db, 0x7da, 0x3, 0x2, 0x2, 0x2, 0x7dc, 0x7dd, 0x3, 0x2, 0x2, 
    0x2, 0x7dd, 0x7de, 0x7, 0x9, 0x2, 0x2, 0x7de, 0xe5, 0x3, 0x2, 0x2, 0x2, 
    0x7df, 0x7e1, 0xa, 0x11, 0x2, 0x2, 0x7e0, 0x7df, 0x3, 0x2, 0x2, 0x2, 
    0x7e1, 0x7e2, 0x3, 0x2, 0x2, 0x2, 0x7e2, 0x7e0, 0x3, 0x2, 0x2, 0x2, 
    0x7e2, 0x7e3, 0x3, 0x2, 0x2, 0x2, 0x7e3, 0xe7, 0x3, 0x2, 0x2, 0x2, 0x7e4, 
    0x7e6, 0xa, 0x12, 0x2, 0x2, 0x7e5, 0x7e4, 0x3, 0x2, 0x2, 0x2, 0x7e6, 
    0x7e7, 0x3, 0x2, 0x2, 0x2, 0x7e7, 0x7e5, 0x3, 0x2, 0x2, 0x2, 0x7e7, 
    0x7e8, 0x3, 0x2, 0x2, 0x2, 0x7e8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x7e9, 0x7eb, 
    0xa, 0x13, 0x2, 0x2, 0x7ea, 0x7e9, 0x3, 0x2, 0x2, 0x2, 0x7eb, 0x7ec, 
    0x3, 0x2, 0x2, 0x2, 0x7ec, 0x7ea, 0x3, 0x2, 0x2, 0x2, 0x7ec, 0x7ed, 
    0x3, 0x2, 0x2, 0x2, 0x7ed, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x7ee, 0x7f0, 0xa, 
    0x14, 0x2, 0x2, 0x7ef, 0x7ee, 0x3, 0x2, 0x2, 0x2, 0x7f0, 0x7f1, 0x3, 
    0x2, 0x2, 0x2, 0x7f1, 0x7ef, 0x3, 0x2, 0x2, 0x2, 0x7f1, 0x7f2, 0x3, 
    0x2, 0x2, 0x2, 0x7f2, 0xed, 0x3, 0x2, 0x2, 0x2, 0x7f3, 0x7f4, 0xa, 0x15, 
    0x2, 0x2, 0x7f4, 0xef, 0x3, 0x2, 0x2, 0x2, 0x7f5, 0x7f6, 0xa, 0x16, 
    0x2, 0x2, 0x7f6, 0xf1, 0x3, 0x2, 0x2, 0x2, 0x7f7, 0x7f8, 0xa, 0x17, 
    0x2, 0x2, 0x7f8, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x10d, 0xf7, 0x100, 0x107, 
    0x10b, 0x110, 0x115, 0x11e, 0x133, 0x137, 0x13d, 0x146, 0x14d, 0x156, 
    0x162, 0x167, 0x16d, 0x173, 0x176, 0x17d, 0x183, 0x188, 0x18b, 0x192, 
    0x199, 0x19f, 0x1a2, 0x1a7, 0x1ae, 0x1bd, 0x1c1, 0x1c8, 0x1cc, 0x1da, 
    0x1de, 0x1e8, 0x1ee, 0x1f5, 0x1fd, 0x203, 0x20a, 0x218, 0x220, 0x226, 
    0x228, 0x22f, 0x23a, 0x23c, 0x245, 0x250, 0x29c, 0x2a0, 0x2a8, 0x2b2, 
    0x2b9, 0x2be, 0x2c3, 0x2c5, 0x2ca, 0x2d0, 0x2d5, 0x2db, 0x2e6, 0x2ec, 
    0x2f2, 0x2f8, 0x2fe, 0x304, 0x30a, 0x310, 0x315, 0x317, 0x31c, 0x322, 
    0x328, 0x32d, 0x336, 0x33c, 0x343, 0x347, 0x34c, 0x353, 0x35c, 0x360, 
    0x365, 0x36c, 0x373, 0x379, 0x37d, 0x383, 0x38a, 0x38e, 0x396, 0x3a0, 
    0x3a9, 0x3ae, 0x3b4, 0x3b8, 0x3bd, 0x3c4, 0x3cb, 0x3cd, 0x3d2, 0x3d9, 
    0x3e0, 0x3e2, 0x3e7, 0x3f0, 0x3f7, 0x3f9, 0x3fb, 0x406, 0x40b, 0x412, 
    0x419, 0x41c, 0x422, 0x426, 0x42b, 0x43a, 0x440, 0x447, 0x44b, 0x451, 
    0x462, 0x469, 0x470, 0x478, 0x47f, 0x486, 0x488, 0x48e, 0x494, 0x498, 
    0x49e, 0x4a0, 0x4a6, 0x4ad, 0x4b0, 0x4b6, 0x4ba, 0x4bf, 0x4c3, 0x4c8, 
    0x4cf, 0x4d6, 0x4da, 0x4df, 0x4e3, 0x4e9, 0x4f0, 0x4f2, 0x4f9, 0x4fc, 
    0x506, 0x50d, 0x513, 0x518, 0x51a, 0x51f, 0x52c, 0x533, 0x539, 0x540, 
    0x544, 0x549, 0x54b, 0x550, 0x558, 0x55f, 0x563, 0x56b, 0x572, 0x577, 
    0x57c, 0x583, 0x58a, 0x591, 0x598, 0x59b, 0x5a3, 0x5ae, 0x5b7, 0x5bb, 
    0x5c0, 0x5c7, 0x5ce, 0x5d2, 0x5da, 0x5e0, 0x5ea, 0x5f1, 0x5f8, 0x5ff, 
    0x607, 0x60c, 0x613, 0x618, 0x61a, 0x61e, 0x622, 0x62d, 0x637, 0x63d, 
    0x644, 0x64b, 0x64e, 0x656, 0x65c, 0x663, 0x66a, 0x66d, 0x675, 0x67b, 
    0x682, 0x689, 0x68c, 0x694, 0x69a, 0x6a5, 0x6ab, 0x6b2, 0x6b9, 0x6bc, 
    0x6c4, 0x6ca, 0x6d1, 0x6d8, 0x6db, 0x6e3, 0x6e9, 0x6f0, 0x6f7, 0x6fe, 
    0x705, 0x70e, 0x714, 0x71b, 0x722, 0x725, 0x72d, 0x733, 0x73a, 0x741, 
    0x748, 0x74f, 0x756, 0x75d, 0x764, 0x76b, 0x772, 0x779, 0x780, 0x787, 
    0x78e, 0x795, 0x79c, 0x7a3, 0x7aa, 0x7b1, 0x7b8, 0x7c2, 0x7d8, 0x7db, 
    0x7e2, 0x7e7, 0x7ec, 0x7f1, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

GrammarParser::Initializer GrammarParser::_init;
