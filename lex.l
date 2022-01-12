%{

%}

%%

"else"      { return ELSE; }
"if"        { return IF; }
"int"       { return INT; }
"return"    { return RETURN; }
"void"      { return VOID; }
"while"     { return WHILE; }

"+"         { return ADD; }
"-"         { return SUB; }
"*"         { return MULT; }
"/"         { return DIV; }
"<"         { return LT; }
"<="        { return LTE; }
">"         { return GT; }
">="        { return GTE; }
"=="        { return EQ; }
"!="        { return NEQ; }
";"         { return SEMICOLON; }
","         { return COMMA; }
"("         { return LPAR; }
")"         { return RPAR; }
"["         { return LQBRACK; }
"]"         { return RSQBRACK; }
"{"         { return LCURBRACK; }
"}"         { return RCURBRACK; }
"/*"        { return LCOMM; }
"*/"        { return RCOMM; }

%%

main() {

}