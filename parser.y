%{
    #include "semantics.c"
	#include "ast.h"
	#include "ast.c"
	#include "symtab.c"
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	extern FILE *yyin;
	extern FILE *yyout;
	
    extern int line;
	extern int yylex();
	void yyerror();

	void add_to_names(Token *entry);
	Token **names;
	int names_count = 0;

	void add_to_vals(Value val);
	Value *vals;
	int vc = 0;
%}

%union{
    Value val;
    Token* symtab_token;
	AST_node* node;

	int data_type;
	int const_type;

	int arr_size;
}

%token<i_val> ELSE IF INT RETURN VOID WHILE
%token<i_val> ADD SUB MULT DIV
%token<i_val> LT LTE GT GTE EQ DIFF
%token<i_val> ASSIGN SEMI COMMA 
%token<i_val> LPAR RPAR LBRACK RBRACK LBRACE RBRACE
%token<symtab_token> ID 
%token<i_val> NUM

%type<node> program
%type<node> declaration-list declaration
%type<data_type> type-specifier
%type<symtab_item> var
%type<symtab_item> expression
%type<node> factor

%start program

%%

program: declaration-list;

declaration-list: declaration-list declaration | declaration;

declaration: var-declaration | fun-declaration;

var-declaration: 
	type-specifier ID SEMI { 
		declare = 0;
		add_to_names($1);

		$$ = new_AST_decl_node($1, ID, names_count);
		names_count = 0;
		
		AST_node_decl *temp = (AST_node_decl*)$$;

		for(int i = 0; i < temp->names_count; i++) {
			if(temp->names[i]->type == UNDEF) {
				set_type(temp->names[i]->name, temp->data_type, UNDEF);
			}
		}

		AST_traversal($$);
	} | 
	type-specifier ID LBRACK NUM RBRACK SEMI { 
		declare = 0;
		add_to_names($1);

		$$ = new_AST_decl_node($1, ID, names_count);
		names_count = 0;
		
		AST_node_decl *temp = (AST_node_decl*)$$;

		for(int i = 0; i < temp->names_count; i++) {
			if(temp->names[i]->type == ARRAY_TYPE) {
				set_type(temp->names[i]->name, ARRAY_TYPE, temp->data_type);
			}
		}

		AST_traversal($$);
	}
;

type-specifier: 
	INT { 
		$$ = INT_TYPE; 
		declare = 1;
	} | 
	VOID { 
		$$ = VOID_TYPE;
		declare = 1; 
	}
;

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

expression: 
	var ASSIGN expression {
		$$ = $1;

		AST_node_const *temp = (AST_node_const*)$$;
		$1->val = temp->val;
		$1->type = temp->const_type;
		$$ = $1;
	} | 
	simple-expression
;

var: ID { $$ = $1; } | 
	ID LBRACK expression RBRACK {
		$1->type = ARRAY_TYPE;
		$1->arr_size = $2;
		$$ = $1;
	}
;

simple-expression: sum-expression relational sum-expression | sum-expression;

relational: LTE | LT | GT | GTE | EQ | DIFF;

sum-expression: sum-expression sum term | term;

sum: ADD | SUB;

term: term mult factor | factor;

mult: MULT | DIV;

factor: LPAR expression RPAR | var | activation | NUM {
	$$ = new_AST_const_node(INT_TYPE, $1);

	AST_node_const *temp = (AST_node_const*)$1;
	add_to_vals(temp->vals);
};

activation: ID LPAR args RPAR;

args: arg-list | /* empty */;

arg-list: arg-list COMMA expression | expression;

%%

void yyerror() {
    fprintf(stderr, "Syntax error at line %d\n", line);
    exit(1);
}

void add_to_names(Token *entry) {
	if(names_count == 0) {
		names_count = 1;
		names = (Token**)malloc(sizeof(Token*));
		names[0] = entry;
	} else {
		names_count++;
		names = (Token**)realloc(names, names_count * sizeof(Token*));
		names[names_count - 1] = entry;
	}
}

void add_to_vals(Value val) {
	if(values_count == 0) {
		values_count = 1;
		vals = (Value*)malloc(sizeof(Value));
		vals[0] = val;
	} else {
		values_count++;
		vals = (Value*)realloc(vals, values_count*sizeof(Value));
		vals[values_count - 1] = val;
	}
}

int main (int argc, char *argv[]) {
	init_table();

	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);

	yyout = fopen("symtab_dump.out", "w");
	symtab_dump(yyout);
	fclose(yyout);	

	return flag;
}