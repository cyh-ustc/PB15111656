grammar PlusFirst;
INT: [1-9] [0-9]*;
WhiteSpace: [ \t\n\r]+ -> skip;
e:
    e '+' e # Add
    | e '*' e # Mult
    | '(' e ')' # Barc
    | INT # Int 
;