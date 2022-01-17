# Commands

flex lexer.l

gcc lex.yy.c -o lexer

./lexer example_a.c
./lexer example_b.c