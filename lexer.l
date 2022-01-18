%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h> 
    #include "symtab.h"
    #include "parser.tab.h"
    int lineno = 1;
    void ret_print(char *token_type);
    void yyerror();  
%}

%x ML_COMMENT

letter [a-zA-Z]
digit [0-9]

ID {letter}+
NUM {digit}+

%%

"/*" { printf("Comments starts at line %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/" { printf("and ends at line %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+
<ML_COMMENT>"*"
<ML_COMMENT>"\n" { lineno += 1; }

"else" { return ELSE; }
"if" { return IF; }
"int" { return INT; }
"return" { return RETURN; }
"void" { return VOID; }
"while" { return WHILE; }

"+"|"-" { return ADD; }
"*"|"/" { return MUL; }
"<"|"<="|">"|">="|"=="|"!=" { return COMP; }
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
    // insert identifier into symbol table
	insert(yytext, strlen(yytext), UNDEF, lineno);
    return ID; 
}
{NUM} { return NUM; }

"\n" { lineno += 1; }
[ \t]+

. { yyerror("Unrecognized character"); }

%%