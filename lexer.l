%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h> 
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

"else" { ret_print("KEYWORD_ELSE"); }
"if" { ret_print("KEYWORD_IF"); }
"int" { ret_print("KEYWORD_INT"); }
"return" { ret_print("KEYWORD_RETURN"); }
"void" { ret_print("KEYWORD_VOID"); }
"while" { ret_print("KEYWORD_WHILE"); }

"+"|"-" { ret_print("ADD"); }
"*"|"/" { ret_print("MUL"); }
"<"|"<="|">"|">="|"=="|"!=" { ret_print("COMP"); }
"=" { ret_print("ASSIGN"); }
";" { ret_print("SEMI"); }
"," { ret_print("COMMA"); }
"(" { ret_print("LPAR"); }
")" { ret_print("RPAR"); }
"[" { ret_print("LBRACK"); }
"]" { ret_print("RBRACK"); }
"{" { ret_print("LBRACE"); }
"}" { ret_print("RBRACE"); }

{ID} { ret_print("ID"); }
{NUM} { ret_print("NUM"); }

"\n" { lineno += 1; }
[ \t]+

. { yyerror("Unrecognized character"); }

%%

void ret_print(char *token_type) {
    printf("yytext: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}

void yyerror(char *message) {
    printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
    exit(1);
}

int main(int argc, char *argv[]) {
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);
    return 0;
}