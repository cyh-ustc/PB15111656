#!/usr/bin/env python3
import antlr4
import MultFirstLexer
import MultFirstListener
import MultFirstParser
import PlusFirstLexer
import PlusFirstListener
import PlusFirstParser

class Listener(antlr4.ParseTreeListener):
	def enterAdd(self, ctx):
		pass

	def exitAdd(self, ctx):
		ctx.expr = '+ [' + ctx.getChild(0).expr + '] [' + ctx.getChild(2).expr + ']'
		ctx.val = ctx.getChild(0).val + ctx.getChild(2).val

	def enterMult(self, ctx):
		pass

	def exitMult(self, ctx):
		ctx.expr = '* [' + ctx.getChild(0).expr + '] [' + ctx.getChild(2).expr + ']'
		ctx.val = ctx.getChild(0).val * ctx.getChild(2).val

	def enterInt(self, ctx):
		pass

	def exitInt(self, ctx):
		ctx.expr = str(ctx.getChild(0))
		ctx.val = int(str(ctx.getChild(0)))

	def enterBarc(self, ctx):
		pass

	def exitBarc(self, ctx):
		ctx.expr = '(' + ctx.getChild(1).expr +')'
		ctx.val = ctx.getChild(1).val

if __name__ == '__main__':
	expr = input('Please enter an expression: ')
	MFP = MultFirstParser.MultFirstParser(antlr4.CommonTokenStream(MultFirstLexer.MultFirstLexer(antlr4.InputStream(expr))))
	MFP.addParseListener(Listener())
	PFP = PlusFirstParser.PlusFirstParser(antlr4.CommonTokenStream(PlusFirstLexer.PlusFirstLexer(antlr4.InputStream(expr))))
	PFP.addParseListener(Listener())
	print('MultFirstParser:')
	mfp = MFP.e()
	print('\tTree: ' + mfp.expr)
	print('\tResult: %d'%mfp.val)
	print('PlusFirstParser:')
	pfp = PFP.e()
	print('\tTree: ' + pfp.expr)
	print('\tResult: %d'%pfp.val)
