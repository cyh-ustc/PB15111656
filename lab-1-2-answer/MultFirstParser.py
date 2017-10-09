# Generated from MultFirst.g4 by ANTLR 4.7
# encoding: utf-8
from antlr4 import *
from io import StringIO
from typing.io import TextIO
import sys

def serializedATN():
    with StringIO() as buf:
        buf.write("\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3\b")
        buf.write("\30\4\2\t\2\3\2\3\2\3\2\3\2\3\2\3\2\5\2\13\n\2\3\2\3\2")
        buf.write("\3\2\3\2\3\2\3\2\7\2\23\n\2\f\2\16\2\26\13\2\3\2\2\3\2")
        buf.write("\3\2\2\2\2\31\2\n\3\2\2\2\4\5\b\2\1\2\5\6\7\5\2\2\6\7")
        buf.write("\5\2\2\2\7\b\7\6\2\2\b\13\3\2\2\2\t\13\7\7\2\2\n\4\3\2")
        buf.write("\2\2\n\t\3\2\2\2\13\24\3\2\2\2\f\r\f\6\2\2\r\16\7\3\2")
        buf.write("\2\16\23\5\2\2\7\17\20\f\5\2\2\20\21\7\4\2\2\21\23\5\2")
        buf.write("\2\6\22\f\3\2\2\2\22\17\3\2\2\2\23\26\3\2\2\2\24\22\3")
        buf.write("\2\2\2\24\25\3\2\2\2\25\3\3\2\2\2\26\24\3\2\2\2\5\n\22")
        buf.write("\24")
        return buf.getvalue()


class MultFirstParser ( Parser ):

    grammarFileName = "MultFirst.g4"

    atn = ATNDeserializer().deserialize(serializedATN())

    decisionsToDFA = [ DFA(ds, i) for i, ds in enumerate(atn.decisionToState) ]

    sharedContextCache = PredictionContextCache()

    literalNames = [ "<INVALID>", "'*'", "'+'", "'('", "')'" ]

    symbolicNames = [ "<INVALID>", "<INVALID>", "<INVALID>", "<INVALID>", 
                      "<INVALID>", "INT", "WhiteSpace" ]

    RULE_e = 0

    ruleNames =  [ "e" ]

    EOF = Token.EOF
    T__0=1
    T__1=2
    T__2=3
    T__3=4
    INT=5
    WhiteSpace=6

    def __init__(self, input:TokenStream, output:TextIO = sys.stdout):
        super().__init__(input, output)
        self.checkVersion("4.7")
        self._interp = ParserATNSimulator(self, self.atn, self.decisionsToDFA, self.sharedContextCache)
        self._predicates = None



    class EContext(ParserRuleContext):

        def __init__(self, parser, parent:ParserRuleContext=None, invokingState:int=-1):
            super().__init__(parent, invokingState)
            self.parser = parser


        def getRuleIndex(self):
            return MultFirstParser.RULE_e

     
        def copyFrom(self, ctx:ParserRuleContext):
            super().copyFrom(ctx)


    class AddContext(EContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a MultFirstParser.EContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def e(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(MultFirstParser.EContext)
            else:
                return self.getTypedRuleContext(MultFirstParser.EContext,i)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterAdd" ):
                listener.enterAdd(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitAdd" ):
                listener.exitAdd(self)


    class MultContext(EContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a MultFirstParser.EContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def e(self, i:int=None):
            if i is None:
                return self.getTypedRuleContexts(MultFirstParser.EContext)
            else:
                return self.getTypedRuleContext(MultFirstParser.EContext,i)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterMult" ):
                listener.enterMult(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitMult" ):
                listener.exitMult(self)


    class IntContext(EContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a MultFirstParser.EContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def INT(self):
            return self.getToken(MultFirstParser.INT, 0)

        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterInt" ):
                listener.enterInt(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitInt" ):
                listener.exitInt(self)


    class BarcContext(EContext):

        def __init__(self, parser, ctx:ParserRuleContext): # actually a MultFirstParser.EContext
            super().__init__(parser)
            self.copyFrom(ctx)

        def e(self):
            return self.getTypedRuleContext(MultFirstParser.EContext,0)


        def enterRule(self, listener:ParseTreeListener):
            if hasattr( listener, "enterBarc" ):
                listener.enterBarc(self)

        def exitRule(self, listener:ParseTreeListener):
            if hasattr( listener, "exitBarc" ):
                listener.exitBarc(self)



    def e(self, _p:int=0):
        _parentctx = self._ctx
        _parentState = self.state
        localctx = MultFirstParser.EContext(self, self._ctx, _parentState)
        _prevctx = localctx
        _startState = 0
        self.enterRecursionRule(localctx, 0, self.RULE_e, _p)
        try:
            self.enterOuterAlt(localctx, 1)
            self.state = 8
            self._errHandler.sync(self)
            token = self._input.LA(1)
            if token in [MultFirstParser.T__2]:
                localctx = MultFirstParser.BarcContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx

                self.state = 3
                self.match(MultFirstParser.T__2)
                self.state = 4
                self.e(0)
                self.state = 5
                self.match(MultFirstParser.T__3)
                pass
            elif token in [MultFirstParser.INT]:
                localctx = MultFirstParser.IntContext(self, localctx)
                self._ctx = localctx
                _prevctx = localctx
                self.state = 7
                self.match(MultFirstParser.INT)
                pass
            else:
                raise NoViableAltException(self)

            self._ctx.stop = self._input.LT(-1)
            self.state = 18
            self._errHandler.sync(self)
            _alt = self._interp.adaptivePredict(self._input,2,self._ctx)
            while _alt!=2 and _alt!=ATN.INVALID_ALT_NUMBER:
                if _alt==1:
                    if self._parseListeners is not None:
                        self.triggerExitRuleEvent()
                    _prevctx = localctx
                    self.state = 16
                    self._errHandler.sync(self)
                    la_ = self._interp.adaptivePredict(self._input,1,self._ctx)
                    if la_ == 1:
                        localctx = MultFirstParser.MultContext(self, MultFirstParser.EContext(self, _parentctx, _parentState))
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_e)
                        self.state = 10
                        if not self.precpred(self._ctx, 4):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 4)")
                        self.state = 11
                        self.match(MultFirstParser.T__0)
                        self.state = 12
                        self.e(5)
                        pass

                    elif la_ == 2:
                        localctx = MultFirstParser.AddContext(self, MultFirstParser.EContext(self, _parentctx, _parentState))
                        self.pushNewRecursionContext(localctx, _startState, self.RULE_e)
                        self.state = 13
                        if not self.precpred(self._ctx, 3):
                            from antlr4.error.Errors import FailedPredicateException
                            raise FailedPredicateException(self, "self.precpred(self._ctx, 3)")
                        self.state = 14
                        self.match(MultFirstParser.T__1)
                        self.state = 15
                        self.e(4)
                        pass

             
                self.state = 20
                self._errHandler.sync(self)
                _alt = self._interp.adaptivePredict(self._input,2,self._ctx)

        except RecognitionException as re:
            localctx.exception = re
            self._errHandler.reportError(self, re)
            self._errHandler.recover(self, re)
        finally:
            self.unrollRecursionContexts(_parentctx)
        return localctx



    def sempred(self, localctx:RuleContext, ruleIndex:int, predIndex:int):
        if self._predicates == None:
            self._predicates = dict()
        self._predicates[0] = self.e_sempred
        pred = self._predicates.get(ruleIndex, None)
        if pred is None:
            raise Exception("No predicate with index:" + str(ruleIndex))
        else:
            return pred(localctx, predIndex)

    def e_sempred(self, localctx:EContext, predIndex:int):
            if predIndex == 0:
                return self.precpred(self._ctx, 4)
         

            if predIndex == 1:
                return self.precpred(self._ctx, 3)
         




