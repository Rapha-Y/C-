# Commands

bison -d parser.y

flex lexer.l

gcc -o lexer parser.tab.c lex.yy.c

./lexer example_a.c
./lexer example_b.c