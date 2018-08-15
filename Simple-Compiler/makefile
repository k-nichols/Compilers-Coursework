# Kathleen Near
#
# Makefile runs "lex" on the .l & .y files and compiles the resulting c program
# clean recursively removes all files within the directory *Note, user will not be prompted to confirm. Use with caution*

all: 	lab9.l
	yacc -d lab9.y
	lex lab9.l
	gcc y.tab.c lex.yy.c AST.c symtable.c emitAST.c -o lab9
	./lab9 < testcode.c -o test
clean:	rm -rf *
