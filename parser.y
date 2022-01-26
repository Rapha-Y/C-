%{
	#include "symtab.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int yylex();
	void yyerror();
%}

%token ELSE IF INT RETURN VOID WHILE
%token ADD SUB MULT DIV
%token LT LTE GT GTE EQ DIFF
%token ASSIGN SEMI COMMA 
%token LPAR RPAR LBRACK RBRACK LBRACE RBRACE
%token ID NUM

%start program

%%

program: declaration-list;

declaration-list: declaration-list declaration | declaration;

declaration: var-declaration | fun-declaration;

var-declaration: type-specifier ID SEMI | type-specifier ID LBRACK NUM RBRACK SEMI;

type-specifier: INT | VOID;

fun-declaration: type-specifier ID LPAR params RPAR composite-decl;

params: param-list | VOID;

param-list: param-list COMMA param | param;

param: type-specifier ID | type-specifier ID LBRACK RBRACK;

composite-decl: LBRACE local-declarations statement-list RBRACE;

local-declarations: local-declarations var-declaration | /* empty */;

statement-list: statement-list statement | /* empty */;

statement: expression-decl | composite-decl | selection-decl | iteration-decl | return-decl;

expression-decl: expression SEMI | SEMI;

selection-decl: IF LPAR expression RPAR statement | IF LPAR expression RPAR statement ELSE statement;

iteration-decl: WHILE LPAR expression RPAR statement;

return-decl: RETURN SEMI | RETURN expression SEMI;

expression: var ASSIGN expression | simple-expression;

var: ID | ID LBRACK expression RBRACK;

simple-expression: sum-expression relational sum-expression | sum-expression;

relational: LTE | LT | GT | GTE | EQ | DIFF;

sum-expression: sum-expression sum term | term;

sum: ADD | SUB;

term: term mult factor | factor;

mult: MULT | DIV;

factor: LPAR expression RPAR | var | activation | NUM;

activation: ID LPAR args RPAR;

args: arg-list | /* empty */;

arg-list: arg-list COMMA expression | expression;

%%

void yyerror ()
{
  fprintf(stderr, "Syntax error at line %d\n", lineno);
  exit(1);
}

int main (int argc, char *argv[]){

	// initialize symbol table
	init_hash_table();

	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);

	// symbol table dump
	yyout = fopen("symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);	

	return flag;
}