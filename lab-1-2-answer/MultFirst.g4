grammar MultFirst;
INT: [1-9] [0-9]*;
WhiteSpace: [ \t\n\r]+ -> skip;
e:
    e '*' e # Mult
    | e '+' e # Add
    | '(' e ')' # Barc
    | INT # Int 
;