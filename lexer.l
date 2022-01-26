%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h> 
    #include "symtab.h"
    #include "parser.tab.h"
    int lineno = 1;
    void yyerror();  
%}

%x ML_COMMENT

letter [a-zA-Z]
digit [0-9]
blank [ ]+
tab [ \t]+
endLine \n

ID {letter}+
NUM {digit}+

%%

"/*" { printf("Comments starts at line %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/" { printf("and ends at line %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+
<ML_COMMENT>"*"
<ML_COMMENT>"\n" { lineno += 1; }

"else" 	    { return ELSE; }
"if" 	    { return IF; }
"int" 	    { return INT; }
"return"    { return RETURN; }
"void" 	    { return VOID; }
"while"	    { return WHILE; }

"+"         { return ADD; }
"-" 	    { return SUB; }
"*" 	    { return MUL; }
"/" 	    { return DIV; }
"<" 	    { return LT; }
"<=" 	    { return LTE; }
">" 	    { return GT; }
">=" 	    { return GTE; }
"==" 	    { return EQ; }
"!=" 	    { return DIFF; }
"=" 	    { return ASSIGN; }
";" 	    { return SEMI; }
"," 	    { return COMMA; }
"(" 	    { return LPAR; }
")" 	    { return RPAR; }
"[" 	    { return LBRACK; }
"]" 	    { return RBRACK; }
"{" 	    { return LBRACE; }
"}" 	    { return RBRACE; }

{ID} { 
    // insert identifier into symbol table
	insert(yytext, strlen(yytext), UNDEF, lineno);
    return ID; 
}
{NUM} { return NUM; }

[ \t]+
"\n" { lineno += 1; }

. { yyerror("Unrecognized character"); }

%%