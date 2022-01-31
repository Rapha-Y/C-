# C-
Project for the Compilers discipline.

# Commands
bison -d parser.y

flex scanner.l

gcc -o scanner parser.tab.c lex.yy.c

./scanner example.c
