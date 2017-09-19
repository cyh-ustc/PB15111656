
// Generated from /home/cyh/Desktop/compiler/labs/c1recognizer/grammar/C1Parser.g4 by ANTLR 4.7


#include "C1ParserListener.h"
#include "C1ParserVisitor.h"

#include "C1Parser.h"


using namespace antlrcpp;
using namespace c1_recognizer;
using namespace antlr4;

C1Parser::C1Parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

C1Parser::~C1Parser() {
  delete _interpreter;
}

std::string C1Parser::getGrammarFileName() const {
  return "C1Parser.g4";
}

const std::vector<std::string>& C1Parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& C1Parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

C1Parser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C1Parser::CompilationUnitContext::getRuleIndex() const {
  return C1Parser::RuleCompilationUnit;
}

void C1Parser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void C1Parser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


antlrcpp::Any C1Parser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::CompilationUnitContext* C1Parser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, C1Parser::RuleCompilationUnit);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

C1Parser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C1Parser::DeclContext::getRuleIndex() const {
  return C1Parser::RuleDecl;
}

void C1Parser::DeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDecl(this);
}

void C1Parser::DeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDecl(this);
}


antlrcpp::Any C1Parser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::DeclContext* C1Parser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, C1Parser::RuleDecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstdeclContext ------------------------------------------------------------------

C1Parser::ConstdeclContext::ConstdeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C1Parser::ConstdeclContext::getRuleIndex() const {
  return C1Parser::RuleConstdecl;
}

void C1Parser::ConstdeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstdecl(this);
}

void C1Parser::ConstdeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstdecl(this);
}


antlrcpp::Any C1Parser::ConstdeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitConstdecl(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::ConstdeclContext* C1Parser::constdecl() {
  ConstdeclContext *_localctx = _tracker.createInstance<ConstdeclContext>(_ctx, getState());
  enterRule(_localctx, 4, C1Parser::RuleConstdecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstdefContext ------------------------------------------------------------------

C1Parser::ConstdefContext::ConstdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C1Parser::ConstdefContext::getRuleIndex() const {
  return C1Parser::RuleConstdef;
}

void C1Parser::ConstdefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstdef(this);
}

void C1Parser::ConstdefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstdef(this);
}


antlrcpp::Any C1Parser::ConstdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitConstdef(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::ConstdefContext* C1Parser::constdef() {
  ConstdefContext *_localctx = _tracker.createInstance<ConstdefContext>(_ctx, getState());
  enterRule(_localctx, 6, C1Parser::RuleConstdef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VardeclContext ------------------------------------------------------------------

C1Parser::VardeclContext::VardeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C1Parser::VardeclContext::getRuleIndex() const {
  return C1Parser::RuleVardecl;
}

void C1Parser::VardeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardecl(this);
}

void C1Parser::VardeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardecl(this);
}


antlrcpp::Any C1Parser::VardeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitVardecl(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::VardeclContext* C1Parser::vardecl() {
  VardeclContext *_localctx = _tracker.createInstance<VardeclContext>(_ctx, getState());
  enterRule(_localctx, 8, C1Parser::RuleVardecl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VardefContext ------------------------------------------------------------------

C1Parser::VardefContext::VardefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C1Parser::VardefContext::getRuleIndex() const {
  return C1Parser::RuleVardef;
}

void C1Parser::VardefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVardef(this);
}

void C1Parser::VardefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVardef(this);
}


antlrcpp::Any C1Parser::VardefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitVardef(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::VardefContext* C1Parser::vardef() {
  VardefContext *_localctx = _tracker.createInstance<VardefContext>(_ctx, getState());
  enterRule(_localctx, 10, C1Parser::RuleVardef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncdefContext ------------------------------------------------------------------

C1Parser::FuncdefContext::FuncdefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C1Parser::FuncdefContext::getRuleIndex() const {
  return C1Parser::RuleFuncdef;
}

void C1Parser::FuncdefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncdef(this);
}

void C1Parser::FuncdefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncdef(this);
}


antlrcpp::Any C1Parser::FuncdefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitFuncdef(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::FuncdefContext* C1Parser::funcdef() {
  FuncdefContext *_localctx = _tracker.createInstance<FuncdefContext>(_ctx, getState());
  enterRule(_localctx, 12, C1Parser::RuleFuncdef);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

C1Parser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C1Parser::BlockContext::getRuleIndex() const {
  return C1Parser::RuleBlock;
}

void C1Parser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void C1Parser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any C1Parser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::BlockContext* C1Parser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 14, C1Parser::RuleBlock);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

C1Parser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C1Parser::StmtContext::getRuleIndex() const {
  return C1Parser::RuleStmt;
}

void C1Parser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void C1Parser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}


antlrcpp::Any C1Parser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::StmtContext* C1Parser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 16, C1Parser::RuleStmt);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LvalContext ------------------------------------------------------------------

C1Parser::LvalContext::LvalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C1Parser::LvalContext::getRuleIndex() const {
  return C1Parser::RuleLval;
}

void C1Parser::LvalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLval(this);
}

void C1Parser::LvalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLval(this);
}


antlrcpp::Any C1Parser::LvalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitLval(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::LvalContext* C1Parser::lval() {
  LvalContext *_localctx = _tracker.createInstance<LvalContext>(_ctx, getState());
  enterRule(_localctx, 18, C1Parser::RuleLval);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CondContext ------------------------------------------------------------------

C1Parser::CondContext::CondContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C1Parser::CondContext::getRuleIndex() const {
  return C1Parser::RuleCond;
}

void C1Parser::CondContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond(this);
}

void C1Parser::CondContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond(this);
}


antlrcpp::Any C1Parser::CondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitCond(this);
  else
    return visitor->visitChildren(this);
}

C1Parser::CondContext* C1Parser::cond() {
  CondContext *_localctx = _tracker.createInstance<CondContext>(_ctx, getState());
  enterRule(_localctx, 20, C1Parser::RuleCond);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

C1Parser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C1Parser::ExpContext *> C1Parser::ExpContext::exp() {
  return getRuleContexts<C1Parser::ExpContext>();
}

C1Parser::ExpContext* C1Parser::ExpContext::exp(size_t i) {
  return getRuleContext<C1Parser::ExpContext>(i);
}

tree::TerminalNode* C1Parser::ExpContext::Plus() {
  return getToken(C1Parser::Plus, 0);
}

tree::TerminalNode* C1Parser::ExpContext::Minus() {
  return getToken(C1Parser::Minus, 0);
}

tree::TerminalNode* C1Parser::ExpContext::LeftParen() {
  return getToken(C1Parser::LeftParen, 0);
}

tree::TerminalNode* C1Parser::ExpContext::RightParen() {
  return getToken(C1Parser::RightParen, 0);
}

tree::TerminalNode* C1Parser::ExpContext::Number() {
  return getToken(C1Parser::Number, 0);
}

tree::TerminalNode* C1Parser::ExpContext::Multiply() {
  return getToken(C1Parser::Multiply, 0);
}

tree::TerminalNode* C1Parser::ExpContext::Divide() {
  return getToken(C1Parser::Divide, 0);
}

tree::TerminalNode* C1Parser::ExpContext::Modulo() {
  return getToken(C1Parser::Modulo, 0);
}


size_t C1Parser::ExpContext::getRuleIndex() const {
  return C1Parser::RuleExp;
}

void C1Parser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void C1Parser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C1ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}


antlrcpp::Any C1Parser::ExpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<C1ParserVisitor*>(visitor))
    return parserVisitor->visitExp(this);
  else
    return visitor->visitChildren(this);
}


C1Parser::ExpContext* C1Parser::exp() {
   return exp(0);
}

C1Parser::ExpContext* C1Parser::exp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C1Parser::ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, parentState);
  C1Parser::ExpContext *previousContext = _localctx;
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C1Parser::RuleExp, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(54);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C1Parser::Plus:
      case C1Parser::Minus: {
        setState(47);
        _la = _input->LA(1);
        if (!(_la == C1Parser::Plus

        || _la == C1Parser::Minus)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(48);
        exp(3);
        break;
      }

      case C1Parser::LeftParen: {
        setState(49);
        match(C1Parser::LeftParen);
        setState(50);
        exp(0);
        setState(51);
        match(C1Parser::RightParen);
        break;
      }

      case C1Parser::Number: {
        setState(53);
        match(C1Parser::Number);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(64);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(62);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(56);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(57);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << C1Parser::Multiply)
            | (1ULL << C1Parser::Divide)
            | (1ULL << C1Parser::Modulo))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(58);
          exp(6);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExp);
          setState(59);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(60);
          _la = _input->LA(1);
          if (!(_la == C1Parser::Plus

          || _la == C1Parser::Minus)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(61);
          exp(5);
          break;
        }

        } 
      }
      setState(66);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool C1Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 11: return expSempred(dynamic_cast<ExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C1Parser::expSempred(ExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> C1Parser::_decisionToDFA;
atn::PredictionContextCache C1Parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN C1Parser::_atn;
std::vector<uint16_t> C1Parser::_serializedATN;

std::vector<std::string> C1Parser::_ruleNames = {
  "compilationUnit", "decl", "constdecl", "constdef", "vardecl", "vardef", 
  "funcdef", "block", "stmt", "lval", "cond", "exp"
};

std::vector<std::string> C1Parser::_literalNames = {
  "", "','", "';'", "'='", "'['", "']'", "'{'", "'}'", "'('", "')'", "'if'", 
  "'else'", "'while'", "'const'", "'=='", "'!='", "'<'", "'>'", "'<='", 
  "'>='", "'+'", "'-'", "'*'", "'/'", "'%'", "'int'", "'void'"
};

std::vector<std::string> C1Parser::_symbolicNames = {
  "", "Comma", "SemiColon", "Assign", "LeftBracket", "RightBracket", "LeftBrace", 
  "RightBrace", "LeftParen", "RightParen", "If", "Else", "While", "Const", 
  "Equal", "NonEqual", "Less", "Greater", "LessEqual", "GreaterEqual", "Plus", 
  "Minus", "Multiply", "Divide", "Modulo", "Int", "Void", "Identifier", 
  "Number", "WhiteSpace", "BlockComment", "LineComment"
};

dfa::Vocabulary C1Parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> C1Parser::_tokenNames;

C1Parser::Initializer::Initializer() {
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
    0x3, 0x21, 0x46, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 
    0xd, 0x39, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x7, 0xd, 0x41, 0xa, 0xd, 0xc, 0xd, 0xe, 0xd, 0x44, 0xb, 0xd, 
    0x3, 0xd, 0x2, 0x3, 0x18, 0xe, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x2, 0x4, 0x3, 0x2, 0x16, 0x17, 0x3, 0x2, 0x18, 
    0x1a, 0x2, 0x3d, 0x2, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x4, 0x1c, 0x3, 0x2, 
    0x2, 0x2, 0x6, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x20, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x22, 0x3, 0x2, 0x2, 0x2, 0xc, 0x24, 0x3, 0x2, 0x2, 0x2, 0xe, 0x26, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x28, 0x3, 0x2, 0x2, 0x2, 0x12, 0x2a, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x16, 0x2e, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x38, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x1b, 0x3, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0x1d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1f, 
    0x7, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x23, 0x3, 0x2, 0x2, 0x2, 0x23, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0x25, 0x3, 0x2, 0x2, 0x2, 0x25, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x26, 0x27, 0x3, 0x2, 0x2, 0x2, 0x27, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x13, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x15, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 
    0x3, 0x2, 0x2, 0x2, 0x2f, 0x17, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 0x8, 
    0xd, 0x1, 0x2, 0x31, 0x32, 0x9, 0x2, 0x2, 0x2, 0x32, 0x39, 0x5, 0x18, 
    0xd, 0x5, 0x33, 0x34, 0x7, 0xa, 0x2, 0x2, 0x34, 0x35, 0x5, 0x18, 0xd, 
    0x2, 0x35, 0x36, 0x7, 0xb, 0x2, 0x2, 0x36, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x37, 0x39, 0x7, 0x1e, 0x2, 0x2, 0x38, 0x30, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x38, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0xc, 0x7, 0x2, 0x2, 0x3b, 0x3c, 0x9, 
    0x3, 0x2, 0x2, 0x3c, 0x41, 0x5, 0x18, 0xd, 0x8, 0x3d, 0x3e, 0xc, 0x6, 
    0x2, 0x2, 0x3e, 0x3f, 0x9, 0x2, 0x2, 0x2, 0x3f, 0x41, 0x5, 0x18, 0xd, 
    0x7, 0x40, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x40, 0x3d, 0x3, 0x2, 0x2, 0x2, 
    0x41, 0x44, 0x3, 0x2, 0x2, 0x2, 0x42, 0x40, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x43, 0x19, 0x3, 0x2, 0x2, 0x2, 0x44, 0x42, 
    0x3, 0x2, 0x2, 0x2, 0x5, 0x38, 0x40, 0x42, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

C1Parser::Initializer C1Parser::_init;
