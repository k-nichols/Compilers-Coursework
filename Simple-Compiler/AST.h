//gcc AST.c -c
//gcc _.c _.c _.c
//print vardec name of variable
//assign print left and right sides (name and expressions pointed to by s1...sn)
//num has all null pointers (only value matters)

/*
eg int x;
iny y[10]   <- FOCUS ON GETTING THIS WORKING
void main(int x) {

}

--------
|vardec|->|x 0 type|
--------
   |
|vardec|->|y 100 int|
   |
|fundec|->|main void function|
   |           |
|param 1|  |cmpdstat|
		|
	  lcldec |assign|
		     |
		   value
PRG DL {rootNode=$1}
DL DEC {$$=$1}
	{$1->s1 = $2; $$=$1}
DEC VARDEC {$$=$1}
$$=nweastnode(VARDEC)
*/

#ifndef AST_H
#define AST_H

#include<stdio.h>
#include<malloc.h>
int mydebug;

/* Definitons of the enumerated types for AST. Used to tell us what production rule we came across
*/
/* list of NODE types for the ASTNode */
enum ASTtype {
	VARDEC,
	FUNCTDEC,
	CMPDSTMT,
	PARAM,
	EXPRSTMT,
	ASGNSTMT,
	SELECSTMT,
	ITRSTMT,
	RTRNSTMT,
	READSTMT,
	WRITESTMT,
	EXPRESSION,
	IDENTIFIER,
	NUMBER,
	FUNCTIONCALL,
	ARGUMENT
};

/* list of OPERATORS types for the ASTNode */
enum OPERATORS {
	PLUS,
	MINUS,
	MULT,
	DIV,
	MOD,
	EQUAL,
	NOTEQUAL,
	LESSTH,
	LESSEQ,
	GREATERTH,
	GREATEREQ,
	INTTYPE,
	VOIDTYPE
};

/* define a type AST node which will hold pointers to AST structs that will
   allow us to represent the parsed code
*/

typedef struct ASTnodetype {
	enum ASTtype type;
    enum OPERATORS isType;
	enum OPERATORS operator;
	char * name;
    char * label;
	int value;
	struct ASTnodetype *next; /* connector for statements */
	struct ASTnodetype *stmt0,*stmt1,*stmt2 ; /* connector for statements */
	struct SymbTab *symbol; /* pointer to symbol table entry */
} ASTnode;

/* Function prototypes */
ASTnode *ASTCreateNode(enum ASTtype mytype);
void ASTattachleft(ASTnode *p,ASTnode *q);
void ASTprint(int level,ASTnode *p);

ASTnode *rootNode;

#endif
