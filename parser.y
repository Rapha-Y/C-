%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "syntree.c"

	extern FILE *yyin;
	extern FILE *yyout;

    extern int line;
    extern int yylex();
    void yyerror();
%}

%union{
	int int_val;
	char *str_val;
}

%token<int_val> ELSE IF INT RETURN VOID WHILE
%token<int_val> ADD SUB MUL DIV
%token<int_val> LT LTE GT GTE EQ DIF
%token<int_val> ASSIGN SEMI COMMA 
%token<int_val> LPAR RPAR LBRACK RBRACK LBRACE RBRACE
%token<str_val> ID 
%token<int_val> NUM

%nonassoc ELSE_AUX
%nonassoc ELSE

%start program

%%

program: 
	declaration-list { 
		insert_syn_tree("program", 0, 1, line);
	}
;

declaration-list: 
	declaration-list declaration {
		insert_syn_tree("declaration-list", 0, 2, line);
	} | 
	declaration {
		insert_syn_tree("declaration-list", 0, 1, line);
	}
;

declaration: 
	var-declaration {
		insert_syn_tree("declaration", 0, 1, line);
	} | 
	fun-declaration {
		insert_syn_tree("declaration", 0, 1, line);
	}
;

var-declaration: 
	type-specifier ID SEMI {
		insert_syn_tree($2, 0, 0, line);
		insert_syn_tree("ID", 0, 1, line);
		insert_syn_tree(";", 0, 0, line);
		insert_syn_tree("var-declaration", 0, 3, line);
	} | 
	type-specifier ID LBRACK NUM RBRACK SEMI {
		insert_syn_tree($2, 0, 0, line);
		insert_syn_tree("ID", 0, 1, line);
		insert_syn_tree("[", 0, 0, line);
		insert_syn_tree(NULL, $4, 0, line);
		insert_syn_tree("NUM", 0, 1, line);
		insert_syn_tree("]", 0, 0, line);
		insert_syn_tree(";", 0, 0, line);
		insert_syn_tree("var-declaration", 0, 6, line);
	}
;

type-specifier: 
	INT {
		insert_syn_tree("int", 0, 0, line);
		insert_syn_tree("type-specifier", 0, 1, line);
	} | 
	VOID {
		insert_syn_tree("void", 0, 0, line);
		insert_syn_tree("type-specifier", 0, 1, line);
	}
;

fun-declaration: 
	type-specifier ID LPAR {
		insert_syn_tree($2, 0, 0, line);
		insert_syn_tree("ID", 0, 1, line);
		insert_syn_tree("LPAR", 0, 0, line);
	} params RPAR {
		insert_syn_tree(")", 0, 0, line);
	} composite-decl {
		insert_syn_tree("fun-declaration", 0, 6, line);	
	}
;

params: 
	param-list {
		insert_syn_tree("params", 0, 1, line);
	} | 
	VOID {
		insert_syn_tree("void", 0, 0, line);
		insert_syn_tree("params", 0, 1, line);
	}
;

param-list: 
	param-list COMMA {
		insert_syn_tree(",", 0, 0, line);
	} param {
		insert_syn_tree("param-list", 0, 3, line);
	} | 
	param {
		insert_syn_tree("param-list", 0, 1, line);
	}
;

param: 
	type-specifier ID {
		insert_syn_tree($2, 0, 0, line);
		insert_syn_tree("ID", 0, 1, line);
		insert_syn_tree("param", 0, 2, line);
	} | 
	type-specifier ID LBRACK RBRACK {
		insert_syn_tree($2, 0, 0, line);
		insert_syn_tree("ID", 0, 1, line);
		insert_syn_tree("[", 0, 0, line);
		insert_syn_tree("]", 0, 0, line);
		insert_syn_tree("param", 0, 4, line);
	}
;

composite-decl: 
	LBRACE {
		insert_syn_tree("{", 0, 0, line);
	} local-declarations statement-list RBRACE {
		insert_syn_tree("}", 0, 0, line);
		insert_syn_tree("composite-decl", 0, 4, line);
	}
;

local-declarations: 
	local-declarations var-declaration {
		insert_syn_tree("local-declarations", 0, 2, line);
	} | 
	/* empty */ {
		insert_syn_tree("@", 0, 0, line);
	}
;

statement-list: 
	statement-list statement {
		insert_syn_tree("statement-list", 0, 2, line);
	} | 
	/* empty */ {
		insert_syn_tree("@", 0, 0, line);
	}
;

statement: 
	expression-decl {
		insert_syn_tree("statement", 0, 1, line);
	} | 
	composite-decl {
		insert_syn_tree("statement", 0, 1, line);
	} | 
	selection-decl {
		insert_syn_tree("statement", 0, 1, line);
	} | 
	iteration-decl {
		insert_syn_tree("statement", 0, 1, line);
	} | 
	return-decl {
		insert_syn_tree("statement", 0, 1, line);
	}
;

expression-decl: 
	expression SEMI {
		insert_syn_tree(";", 0, 0, line);
		insert_syn_tree("expression-decl", 0, 2, line);
	} | 
	SEMI {
		insert_syn_tree(";", 0, 0, line);
		insert_syn_tree("expression-decl", 0, 1, line);
	}
;

selection-decl: 
	if-decl %prec ELSE_AUX {
		insert_syn_tree("selection-decl", 0, 5, line);
	} |
	if-decl ELSE {
		insert_syn_tree("else", 0, 0, line);
	} statement {
		insert_syn_tree("selection-decl", 0, 7, line);
	}
;

// not shown
if-decl:
	IF LPAR {
		insert_syn_tree("if", 0, 0, line);
		insert_syn_tree("(", 0, 0, line);
	} expression RPAR {
		insert_syn_tree(")", 0, 0, line);
	} statement
;

iteration-decl: 
	WHILE LPAR {
		insert_syn_tree("while", 0, 0, line);
		insert_syn_tree("(", 0, 0, line);
	} expression RPAR {
		insert_syn_tree(")", 0, 0, line);
	} statement {
		insert_syn_tree("iteration-decl", 0, 5, line);
	}
;

return-decl: 
	RETURN SEMI {
		insert_syn_tree("return", 0, 0, line);
		insert_syn_tree(";", 0, 0, line);
		insert_syn_tree("return-decl", 0, 2, line);
	} | 
	RETURN {
		insert_syn_tree("return", 0, 0, line);
	} expression SEMI {
		insert_syn_tree(";", 0, 0, line);
		insert_syn_tree("return-decl", 0, 2, line);
	}
;

expression: 
	var ASSIGN {
		insert_syn_tree("=", 0, 0, line);
	} expression {
		insert_syn_tree("expression", 0, 3, line);
	} | 
	simple-expression {
		insert_syn_tree("expression", 0, 1, line);
	}
;

var: 
	ID {
		insert_syn_tree($1, 0, 0, line);
		insert_syn_tree("ID", 0, 1, line);
		insert_syn_tree("var", 0, 1, line);
	} | 
	ID LBRACK {
		insert_syn_tree($1, 0, 0, line);
		insert_syn_tree("ID", 0, 1, line);
		insert_syn_tree("[", 0, 0, line);
	} expression RBRACK {
		insert_syn_tree("]", 0, 0, line);
		insert_syn_tree("var", 0, 4, line);
	}
;

simple-expression: 
	sum-expression relational sum-expression {
		insert_syn_tree("simple-expression", 0, 3, line);
	} | 
	sum-expression {
		insert_syn_tree("simple-expression", 0, 1, line);
	}
;

relational: 
	LTE {
		insert_syn_tree("<=", 0, 0, line);
		insert_syn_tree("relational", 0, 1, line);
	} | 
	LT {
		insert_syn_tree("<", 0, 0, line);
		insert_syn_tree("relational", 0, 1, line);
	} | 
	GT {
		insert_syn_tree(">", 0, 0, line);
		insert_syn_tree("relational", 0, 1, line);
	} | 
	GTE {
		insert_syn_tree(">=", 0, 0, line);
		insert_syn_tree("relational", 0, 1, line);
	} | 
	EQ {
		insert_syn_tree("==", 0, 0, line);
		insert_syn_tree("relational", 0, 1, line);
	} | 
	DIF {
		insert_syn_tree("!=", 0, 0, line);
		insert_syn_tree("relational", 0, 1, line);
	}
;

sum-expression: 
	sum-expression sum term {
		insert_syn_tree("sum-expression", 0, 3, line);
	} | 
	term {
		insert_syn_tree("sum-expression", 0, 1, line);
	}
;

sum: 
	ADD {
		insert_syn_tree("+", 0, 0, line);
		insert_syn_tree("sum", 0, 1, line);
	} | 
	SUB {
		insert_syn_tree("-", 0, 0, line);
		insert_syn_tree("sum", 0, 1, line);
	}
;

term: 
	term mult factor {
		insert_syn_tree("term", 0, 3, line);
	} | 
	factor {
		insert_syn_tree("term", 0, 1, line);
	}
;

mult: 
	MUL {
		insert_syn_tree("*", 0, 0, line);
		insert_syn_tree("mult", 0, 1, line);
	} | 
	DIV {
		insert_syn_tree("/", 0, 0, line);
		insert_syn_tree("mult", 0, 1, line);
	}
;

factor: 
	LPAR {
		insert_syn_tree("(", 0, 0, line);
	} expression RPAR {
		insert_syn_tree(")", 0, 0, line);
		insert_syn_tree("factor", 0, 3, line);
	} | 
	var {
		insert_syn_tree("factor", 0, 1, line);
	} | 
	activation {
		insert_syn_tree("factor", 0, 1, line);
	} | 
	NUM {
		insert_syn_tree(NULL, $1, 0, line);
		insert_syn_tree("NUM", 0, 1, line);
		insert_syn_tree("factor", 0, 1, line);
	}
;

activation: 
	ID LPAR {
		insert_syn_tree($1, 0, 0, line);
		insert_syn_tree("(", 0, 0, line);
	} args RPAR {
		insert_syn_tree(")", 0, 0, line);
		insert_syn_tree("activation", 0, 4, line);
	}
;

args: 
	arg-list {
		insert_syn_tree("args", 0, 1, line);
	} | 
	/* empty */ {
		insert_syn_tree("@", 0, 0, line);
	}
;

arg-list: 
	arg-list COMMA {
		insert_syn_tree(",", 0, 0, line);
	} expression {
		insert_syn_tree("arg-list", 0, 3, line);
	} | 
	expression {
		insert_syn_tree("arg-list", 0, 1, line);
	}
;

%%

//find way to find the token, maybe using the tree
void yyerror() { 
    printf("ERRO SINTÁTICO:\tToken: ");

	char token[128] = "";
	switch(yychar) {
		case ELSE:
			strcat(token, "else");
			break;
		case IF:
			strcat(token, "if");
			break;
		case INT:
			strcat(token, "int");
			break;
		case RETURN:
			strcat(token, "return");
			break;
		case VOID:
			strcat(token, "void");
			break;
		case WHILE:
			strcat(token, "while");
			break;
		case ADD:
			strcat(token, "+");
			break;
		case SUB:
			strcat(token, "-");
			break;
		case MUL:
			strcat(token, "*");
			break;
		case DIV:
			strcat(token, "/");
			break;
		case LT:
			strcat(token, "<");
			break;
		case LTE:
			strcat(token, "<=");
			break;
		case GT:
			strcat(token, ">");
			break;
		case GTE:
			strcat(token, ">=");
			break;
		case EQ:
			strcat(token, "==");
			break;
		case DIF:
			strcat(token, "!=");
			break;
		case ASSIGN:
			strcat(token, "=");
			break;
		case SEMI:
			strcat(token, ";");
			break;
		case COMMA:
			strcat(token, ",");
			break;
		case LPAR:
			strcat(token, "(");
			break;
		case RPAR:
			strcat(token, ")");
			break;
		case LBRACK:
			strcat(token, "[");
			break;
		case RBRACK:
			strcat(token, "]");
			break;
		case LBRACE:
			strcat(token, "{");
			break;
		case RBRACE:
			strcat(token, "}");
			break;
		case ID:
			strcat(token, "ID");
			break;
		case NUM:
			strcat(token, "NUM");
			break;
	}
	printf("%s", token);

	printf("\tNúmero da linha: %d\n", line);
    exit(1);
};

int main(int argc, char *argv[]) {
	init_syn_tree();

	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);

	print_tree();

	return flag;
}