%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int line = 1;
    
    void open_comm();
    void close_comm();
    void print_token(char *token);
    void yyerror();
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

"else" { print_token("ELSE"); }
"if" { print_token("IF"); }
"int" { print_token("INT"); }
"return" { print_token("RETURN"); }
"void" { print_token("VOID"); }
"while" { print_token("WHILE"); }

"+" { print_token("ADD"); }
"-" { print_token("SUB"); }
"*" { print_token("MUL"); }
"/" { print_token("DIV"); }

"<" { print_token("LT"); }
"<=" { print_token("LTE"); }
">" { print_token("GT"); }
">=" { print_token("GTE"); }
"==" { print_token("EQ"); }
"!=" { print_token("DIF"); }

"=" { print_token("ASSIGN"); }
";" { print_token("SEMI"); }
"," { print_token("COMMA"); }

"(" { print_token("LPAR"); }
")" { print_token("RPAR"); }
"[" { print_token("LBRACK"); }
"]" { print_token("RBRACK"); }
"{" { print_token("LBRACE"); }
"}" { print_token("RBRACE"); }

{ID} { print_token("ID"); }
{NUM} { print_token("NUM"); }

[ \t]+
"\n" { line += 1; }

. { yyerror(); }

%%

void open_comm() {
    printf("Comentário da linha %d ", line); 
    BEGIN(ML_COMMENT);
};

void close_comm() {
    printf("até a linha %d\n", line);
    BEGIN(INITIAL);
};

void print_token(char *token) {
    printf("Token: %s\tLexema: %s\tNúmero da linha: %d\n", token, yytext, line);
}

void yyerror() {
    printf("ERRO LÉXICO: Lexema: %s\tNúmero da linha: %d\n", yytext, line);
    exit(1);
}

int main(int argc, char *argv[]) {
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);
    return 0;
}