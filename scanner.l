%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "parser.tab.h"

    int line = 1;
    
    void open_comm();
    void close_comm();
    void print_token(char *token);
    void lex_error();
%}

%x ML_COMMENT

letter [a-zA-Z]
digit [0-9]

ID {letter}+
NUM {digit}+

%%

"/*" { open_comm(); }
<ML_COMMENT>"*/" { close_comm(); }
<ML_COMMENT>[^*\n]+
<ML_COMMENT>"*"
<ML_COMMENT>"\n" { line += 1; }

"else" { print_token("ELSE"); return ELSE; }
"if" { print_token("IF"); return IF; }
"int" { print_token("INT"); return INT; }
"return" { print_token("RETURN"); return RETURN; }
"void" { print_token("VOID"); return VOID; }
"while" { print_token("WHILE"); return WHILE; }

"+" { print_token("ADD"); return ADD; }
"-" { print_token("SUB"); return SUB; }
"*" { print_token("MUL"); return MUL; }
"/" { print_token("DIV"); return DIV; }

"<" { print_token("LT"); return LT; }
"<=" { print_token("LTE"); return LTE; }
">" { print_token("GT"); return GT; }
">=" { print_token("GTE"); return GTE; }
"==" { print_token("EQ"); return EQ; }
"!=" { print_token("DIF"); return DIF; }

"=" { print_token("ASSIGN"); return ASSIGN; }
";" { print_token("SEMI"); return SEMI; }
"," { print_token("COMMA"); return COMMA; }

"(" { print_token("LPAR"); return LPAR; }
")" { print_token("RPAR"); return RPAR; }
"[" { print_token("LBRACK"); return LBRACK; }
"]" { print_token("RBRACK"); return RBRACK; }
"{" { print_token("LBRACE"); return LBRACE; }
"}" { print_token("RBRACE"); return RBRACE; }

{ID} { print_token("ID"); return ID; }
{NUM} { print_token("NUM"); return NUM; }

[ \t]+
"\n" { line += 1; }

. { lex_error(); }

%%

void open_comm() {
    //printf("Comentário da linha %d ", line); 
    BEGIN(ML_COMMENT);
};

void close_comm() {
    //printf("até a linha %d\n", line);
    BEGIN(INITIAL);
};

void print_token(char *token) {
    //printf("Token: %s\tLexema: %s\tNúmero da linha: %d\n", token, yytext, line);
}

void lex_error() {
    //printf("ERRO LÉXICO: Lexema: %s\tNúmero da linha: %d\n", yytext, line);
    exit(1);
}

/*int main(int argc, char *argv[]) {
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);
    return 0;
}*/