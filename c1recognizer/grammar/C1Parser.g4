parser grammar C1Parser;
options { tokenVocab = C1Lexer; }



compilationUnit:  (decl | funcdef) compilationUnit_;


compilationUnit_:
    (decl | funcdef)compilationUnit_
    |
;

decl: constdecl | vardecl;
constdecl: Const Int constdef (Comma constdef)* SemiColon;
constdef:
    Identifier Assign exp
    | Identifier LeftBracket exp? RightBracket Assign LeftBrace exp (Comma exp)* RightBrace
;
vardecl: Int vardef (Comma vardef)* SemiColon;
vardef: 
    Identifier
    | Identifier LeftBracket exp RightBracket
    | Identifier Assign exp
    | Identifier LeftBracket exp? RightBracket Assign LeftBrace exp (Comma exp)* RightBrace
;
funcdef: Void Identifier LeftParen RightParen block;
block: LeftBrace (decl | stmt)* RightBrace;
stmt: lval Assign exp SemiColon
    | Identifier LeftParen RightParen SemiColon
    | block
    | If LeftParen cond RightParen stmt (Else stmt)?
    | While LeftParen cond RightParen stmt
    | SemiColon
;
lval: 
    Identifier
    | Identifier LeftBracket exp RightBracket
;
cond:
    exp Equal exp
    | exp NonEqual exp
    | exp Less exp
    | exp Greater exp
    | exp LessEqual exp
    | exp GreaterEqual exp
;
exp:
    exp (Multiply | Divide | Modulo) exp
    | exp (Plus | Minus) exp
    | (Plus | Minus) exp
    | LeftParen exp RightParen
    | lval
    | Number
;
