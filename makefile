# Kathleen Near
#
# Makefile compiles the symtable.c c program
# clean recursively removes all files within the directory *Note, user will not be prompted to confirm. Use with caution*

all: 	symtable.c
	gcc -o symtable symtable.c
clean:	rm -rf *
