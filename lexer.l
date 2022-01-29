%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>    
    #include "symtab.h"
    #include "semantics.h"
    #include "ast.h"
    #include "parser.tab.h"

    extern FILE *yyin;
    extern FILE *yyout;

    int line = 1;
    void yyerror();  
%}

%x ML_COMMENT

letter [a-zA-Z]
digit [0-9]

ID {letter}+
NUM {digit}+

%%

"/*" { printf("Comments starts at line %d ", line); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/" { printf("and ends at line %d\n", line); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+
<ML_COMMENT>"*"
<ML_COMMENT>"\n" { line += 1; }

"else" { return ELSE; }
"if" { return IF; }
"int" { return INT; }
"return" { return RETURN; }
"void" { return VOID; }
"while" { return WHILE; }

"+" { return ADD; }
"-" { return SUB; }
"*" { return MULT; }
"/" { return DIV; }
"<" { return LT; }
"<=" { return LTE; }
">" { return GT; }
">=" { return GTE; }
"==" { return EQ; }
"!=" { return DIFF; }
"=" { return ASSIGN; }
";" { return SEMI; }
"," { return COMMA; }
"(" { return LPAR; }
")" { return RPAR; }
"[" { return LBRACK; }
"]" { return RBRACK; }
"{" { return LBRACE; }
"}" { return RBRACE; }

{ID} { 
    insert_token(yytext, strlen(yytext), UNDEF, line);
    yylval.symtab_token = search_token(yytext);
    return ID; 
}
{NUM} { 
    yylval.val.i_val = atoi(yytext);
    return NUM; 
}

[ \t]+
"\n" { line += 1; }

. { yyerror("Lexical error at line %d\n", line); }

%%