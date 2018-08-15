# Kathleen Near
#
# Makefile runs "lex" on the file and compiles the resulting c program whenever wordlengthlab1.l is changed.
# clean recursively removes all files within the directory *Note, user will not be prompted to confirm. Use with caution*

all: 	wordlengthlab1.l
	lex wordlengthlab1.l
	gcc -o wordlength lex.yy.c
clean:	rm -rf *
