lexer grammar C1Lexer;

tokens {
    Comma,
    SemiColon,
    Assign,
    LeftBracket,
    RightBracket,
    LeftBrace,
    RightBrace,
    LeftParen,
    RightParen,
    If,
    Else,
    While,
    Const,
    Equal,
    NonEqual,
    Less,
    Greater,
    LessEqual,
    GreaterEqual,
    Plus,
    Minus,
    Multiply,
    Divide,
    Modulo,

    Int,
    Void,

    Identifier,
    Number
}

Comma: ',' ;
SemiColon: ';' ;
Assign: '=' ;
LeftBracket: '[' ;
RightBracket: ']' ;
LeftBrace: '{' ;
RightBrace: '}' ;
LeftParen: '(' ;
RightParen: ')' ;
If: 'if' ;
Else: 'else' ;
While: 'while' ;
Const: 'const' ;
Equal: '==' ;
NonEqual: '!=' ;
Less: '<' ;
Greater: '>' ;
LessEqual: '<=' ;
GreaterEqual: '>=' ;
Plus: '+' ;
Minus: '-' ;
Multiply: '*' ;
Divide: '/' ;
Modulo: '%' ;
Int: 'int' ;
Void: 'void' ;
Number: [0-9]+ | '0x' [0-9a-fA-F]+ ;
Identifier: [A-Za-z_][A-Za-z0-9_]*;
WhiteSpace: [ \t\r\n]+ -> skip;
BlockComment: '/*' .*? '*/' -> skip;
LineComment: '//' ((~('\r'|'\n'))|'\\\n'|'\\\n\r')* -> skip;
