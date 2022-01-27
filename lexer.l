%option noyywrap

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symtab.c"

    extern FILE *yyin;
    extern FILE *yyout;

    int line = 1;
    void ret_print(char *token_type);
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

"else" { ret_print("KEYWORD_ELSE"); }
"if" { ret_print("KEYWORD_IF"); }
"int" { ret_print("KEYWORD_INT"); }
"return" { ret_print("KEYWORD_RETURN"); }
"void" { ret_print("KEYWORD_VOID"); }
"while" { ret_print("KEYWORD_WHILE"); }

"+" { ret_print("ADD"); }
"-" { ret_print("SUB"); }
"*" { ret_print("MULT"); }
"/" { ret_print("DIV"); }
"<" { ret_print("LT"); }
"<=" { ret_print("LTE"); }
">" { ret_print("GT"); }
">=" { ret_print("GTE"); }
"==" { ret_print("EQ"); }
"!=" { ret_print("DIFF"); }
"=" { ret_print("ASSIGN"); }
";" { ret_print("SEMI"); }
"," { ret_print("COMMA"); }
"(" { ret_print("LPAR"); }
")" { ret_print("RPAR"); }
"[" { ret_print("LBRACK"); }
"]" { ret_print("RBRACK"); }
"{" { ret_print("LBRACE"); }
"}" { ret_print("RBRACE"); }

{ID} { 
    insert_token(yytext, strlen(yytext), UNDEF, line);
    ret_print("ID"); 
}
{NUM} { ret_print("NUM"); }

[ \t]+
"\n" { line += 1; }

. { yyerror("Lexical error"); }

%%

void ret_print(char *token_type) {
    printf("yytext: %s\ttoken: %s\tline: %d\n", yytext, token_type, line);
}

void yyerror(char *message) {
    printf("Error: \"%s\" in line %d. Token = %s\n", message, line, yytext);
    exit(1);
}

int main(int argc, char *argv[]) {
    init_table();
    
    yyin = fopen(argv[1], "r");
    yylex();
    fclose(yyin);

    yyout = fopen("symtab_dump.out", "w");
    symtab_dump(yyout);
    fclose(yyout);

    return 0;
}