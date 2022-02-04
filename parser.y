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
		insert_syn_tree("program", 1);
	}
;

declaration-list: 
	declaration-list declaration {
		insert_syn_tree("declaration-list", 2);
	} | 
	declaration {
		insert_syn_tree("declaration-list", 1);
	}
;

declaration: 
	var-declaration {
		insert_syn_tree("declaration", 1);
	} | 
	fun-declaration {
		insert_syn_tree("declaration", 1);
	}
;

var-declaration: 
	type-specifier ID SEMI {
		char str1[64] = "ID(";
		strcat(str1, $2);
		strcat(str1, ")");
		insert_syn_tree(str1, 0);
		insert_syn_tree(";", 0);
		insert_syn_tree("var-declaration", 3);
	} | 
	type-specifier ID LBRACK NUM RBRACK SEMI {
		char str1[64] = "ID(";
		strcat(str1, $2);
		strcat(str1, ")");
		insert_syn_tree(str1, 0);
		insert_syn_tree("[", 0);
		char str3[15] = "NUM(";
		char str4[10];
		sprintf(str4, "%d", $4);
		strcat(str3, str4);
		strcat(str3, ")");
		insert_syn_tree(str3, 0);
		insert_syn_tree("]", 0);
		insert_syn_tree(";", 0);
		insert_syn_tree("var-declaration", 6);
	}
;

type-specifier: 
	INT {
		insert_syn_tree("int", 0);
		insert_syn_tree("type-specifier", 1);
	} | 
	VOID {
		insert_syn_tree("void", 0);
		insert_syn_tree("type-specifier", 1);
	}
;

fun-declaration: 
	type-specifier ID LPAR {
		char str1[64] = "ID(";
		strcat(str1, $2);
		strcat(str1, ")");
		insert_syn_tree(str1, 0);
		insert_syn_tree("(", 0);
	} params RPAR {
		insert_syn_tree(")", 0);
	} composite-decl {
		insert_syn_tree("fun-declaration", 6);
	}
;

params: 
	param-list {
		insert_syn_tree("params", 1);
	} | 
	VOID {
		insert_syn_tree("void", 0);
		insert_syn_tree("params", 1);
	}
;

param-list: 
	param-list COMMA {
		insert_syn_tree(",", 0);
	} param {
		insert_syn_tree("param-list", 3);
	} | 
	param {
		insert_syn_tree("param-list", 1);
	}
;

param: 
	type-specifier ID {
		char str1[64] = "ID(";
		strcat(str1, $2);
		strcat(str1, ")");
		insert_syn_tree(str1, 0);
		insert_syn_tree("param", 2);
	} | 
	type-specifier ID LBRACK RBRACK {
		char str1[64] = "ID(";
		strcat(str1, $2);
		strcat(str1, ")");
		insert_syn_tree(str1, 0);
		insert_syn_tree("[", 0);
		insert_syn_tree("]", 0);
		insert_syn_tree("param", 4);
	}
;

composite-decl: 
	LBRACE {
		insert_syn_tree("{", 0);
	} local-declarations statement-list RBRACE {
		insert_syn_tree("}", 0);
		insert_syn_tree("composite-decl", 4);
	}
;

local-declarations: 
	local-declarations var-declaration {
		insert_syn_tree("local-declarations", 2);
	} | 
	/* empty */
;

statement-list: 
	statement-list statement {
		insert_syn_tree("statement-list", 2);
	} | 
	/* empty */
;

statement: 
	expression-decl {
		insert_syn_tree("statement", 1);
	} | 
	composite-decl {
		insert_syn_tree("statement", 1);
	} | 
	selection-decl {
		insert_syn_tree("statement", 1);
	} | 
	iteration-decl {
		insert_syn_tree("statement", 1);
	} | 
	return-decl {
		insert_syn_tree("statement", 1);
	}
;

expression-decl: 
	expression SEMI {
		insert_syn_tree(";", 0);
		insert_syn_tree("expression-decl", 2);
	} | 
	SEMI {
		insert_syn_tree(";", 0);
		insert_syn_tree("expression-decl", 1);
	}
;

selection-decl: 
	if-decl %prec ELSE_AUX {
		insert_syn_tree("selection-decl", 5);
	} |
	if-decl ELSE {
		insert_syn_tree("else", 0);
	} statement {
		insert_syn_tree("selection-decl", 7);
	}
;

// not shown
if-decl:
	IF LPAR {
		insert_syn_tree("if", 0);
		insert_syn_tree("(", 0);
	} expression RPAR {
		insert_syn_tree(")", 0);
	} statement
;

iteration-decl: 
	WHILE LPAR {
		insert_syn_tree("while", 0);
		insert_syn_tree("(", 0);
	} expression RPAR {
		insert_syn_tree(")", 0);
	} statement {
		insert_syn_tree("iteration-decl", 5);
	}
;

return-decl: 
	RETURN SEMI {
		insert_syn_tree("return", 0);
		insert_syn_tree(";", 0);
		insert_syn_tree("return-decl", 2);
	} | 
	RETURN {
		insert_syn_tree("return", 0);
	} expression SEMI {
		insert_syn_tree(";", 0);
		insert_syn_tree("return-decl", 2);
	}
;

expression: 
	var ASSIGN {
		insert_syn_tree("=", 0);
	} expression {
		insert_syn_tree("expression", 3);
	} | 
	simple-expression {
		insert_syn_tree("expression", 1);
	}
;

var: 
	ID {
		char str1[64] = "ID(";
		strcat(str1, $1);
		strcat(str1, ")");
		insert_syn_tree(str1, 0);
		insert_syn_tree("var", 1);
	} | 
	ID LBRACK {
		char str1[64] = "ID(";
		strcat(str1, $1);
		strcat(str1, ")");
		insert_syn_tree(str1, 0);
		insert_syn_tree("[", 0);
	} expression RBRACK {
		insert_syn_tree("]", 0);
		insert_syn_tree("var", 4);
	}
;

simple-expression: 
	sum-expression relational sum-expression {
		insert_syn_tree("simple-expression", 3);
	} | 
	sum-expression {
		insert_syn_tree("simple-expression", 1);
	}
;

relational: 
	LTE {
		insert_syn_tree("<=", 0);
		insert_syn_tree("relational", 1);
	} | 
	LT {
		insert_syn_tree("<", 0);
		insert_syn_tree("relational", 1);
	} | 
	GT {
		insert_syn_tree(">", 0);
		insert_syn_tree("relational", 1);
	} | 
	GTE {
		insert_syn_tree(">=", 0);
		insert_syn_tree("relational", 1);
	} | 
	EQ {
		insert_syn_tree("==", 0);
		insert_syn_tree("relational", 1);
	} | 
	DIF {
		insert_syn_tree("!=", 0);
		insert_syn_tree("relational", 1);
	}
;

sum-expression: 
	sum-expression sum term {
		insert_syn_tree("sum-expression", 3);
	} | 
	term {
		insert_syn_tree("sum-expression", 1);
	}
;

sum: 
	ADD {
		insert_syn_tree("+", 0);
		insert_syn_tree("sum", 1);
	} | 
	SUB {
		init_syn_tree("-", 0);
		insert_syn_tree("sum", 1);
	}
;

term: 
	term mult factor {
		insert_syn_tree("term", 3);
	} | 
	factor {
		insert_syn_tree("term", 1);
	}
;

mult: 
	MUL {
		insert_syn_tree("*", 0);
		insert_syn_tree("mult", 1);
	} | 
	DIV {
		insert_syn_tree("/", 0);
		insert_syn_tree("mult", 1);
	}
;

factor: 
	LPAR {
		insert_syn_tree("(", 0);
	} expression RPAR {
		insert_syn_tree(")", 0);
		insert_syn_tree("factor", 3);
	} | 
	var {
		insert_syn_tree("factor", 1);
	} | 
	activation {
		insert_syn_tree("factor", 1);
	} | 
	NUM {
		char str3[15] = "NUM(";
		char str4[10];
		sprintf(str4, "%d", $1);
		strcat(str3, str4);
		strcat(str3, ")");
		insert_syn_tree(str3, 0);
		init_syn_tree("NUM", 0);
		insert_syn_tree("factor", 1);
	}
;

activation: 
	ID LPAR {
		char str1[64] = "ID(";
		strcat(str1, $1);
		strcat(str1, ")");
		insert_syn_tree(str1, 0);
		insert_syn_tree("(", 0);
	} args RPAR {
		insert_syn_tree(")", 0);
		insert_syn_tree("activation", 4);
	}
;

args: 
	arg-list {
		insert_syn_tree("args", 1);
	} | 
	/* empty */
;

arg-list: 
	arg-list COMMA {
		insert_syn_tree(",", 0);
	} expression {
		insert_syn_tree("arg-list", 3);
	} | 
	expression {
		insert_syn_tree("arg-list", 1);
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