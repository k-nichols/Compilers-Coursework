/*   Abstract syntax tree code
     This code is used to define an AST node & print out the AST

     Kathleen Near February-March 2018
*/

#include "AST.h"

/* uses malloc to create an ASTnode and passes back the heap address of 
the newly created node */
ASTnode *ASTCreateNode(enum ASTtype mytype) {
	ASTnode *p;
	if (mydebug) fprintf(stderr,"Creating AST Node \n");
	p=(ASTnode *)malloc(sizeof(ASTnode));
	p->next = NULL;
	p->type=mytype;
	p->stmt0=NULL;
	p->stmt1=NULL;
	p->stmt2=NULL;
	p->value=0;
    p->name=NULL;
    p->label=NULL;
    p->symbol=NULL;
	return(p);
}

/*  Print out the abstract syntax tree */
void ASTprint(int level, ASTnode *p) {
	int i;
	if (p == NULL ) return;
	else {
		for (i=0;i<level;i++) printf(" "); /* print tabbing blanks */
		switch (p->type) {
			case VARDEC :
				/* print variable and its type */
				printf("VARIABLE ");
				if(p->operator == VOIDTYPE)
					printf("VOID ");
				else
					printf("INT ");
				printf("%s",p->name);
				/* if an array and size is given, print it */
				if (p->value > 0)
					printf("[%d]",p->value);
				printf("\n");
				break;
			case FUNCTDEC : 
				/* print function name and type */
				if(p->operator == VOIDTYPE)
					printf("VOID ");
				else
					printf("INT ");
				printf("FUNCTION %s (", p->name);
				/* print function parameters */
				if (p->stmt0 == NULL)
					printf("VOID");
				else
					ASTprint(0,p->stmt0);
				printf(") {\n");
				/* print function contents */
				ASTprint(level,p->stmt1);
				printf("}\n");
				break;
			case CMPDSTMT:
				/* print local declarations */
				ASTprint(level+1,p->stmt0);
				/* print statement list */
				ASTprint(level+1,p->stmt1);
				break;
			case PARAM :
				/* print parameter names and types */
				printf("PARAMETER ");
				if(p->operator == VOIDTYPE)
					printf("VOID ");
				else
					printf("INT ");
				printf("%s",p->name);
				/* if an array print accordingly */
				if(p->value < 0)
					printf("[]");
				printf(", ");
				break;
			case EXPRSTMT:
				printf("EXPRESSION STATEMENT\n");
				/* print expression */
				ASTprint(level+2,p->stmt0);
				printf("\n");
				break;
			case ASGNSTMT:
				printf("ASSIGNMENT STATEMENT\n");
				/* print variable */
				ASTprint(level+2,p->stmt0);
				printf(" = ");
				/* print expression statement */
				ASTprint(level+2,p->stmt1);
				break;
			case SELECSTMT:
				printf("SELECT STATEMENT\n");
				/* if statement */
				printf("   IF(");
				/* print expression */
				ASTprint(0,p->stmt0);
				printf(")");
				/* print statment */
				ASTprint(level+2,p->stmt1);
				/* else statement */
				if(p->stmt2 != NULL) {
					printf("   ELSE");
					ASTprint(level+2,p->stmt2);
				}
				break;
			case ITRSTMT:
				printf("ITERATION STATEMENT\n");
				/* print while expression */
				printf("   WHILE(");
				ASTprint(0,p->stmt0);
				printf(")");
				/* print statment */
				ASTprint(level+2,p->stmt1);
				printf("\n");
				break;
			case RTRNSTMT:
				printf("RETURN STATEMENT\n");
				printf("   RETURN ");
				/* print expression */
				ASTprint(0,p->stmt0);
				printf("\n");
				break;
			case READSTMT:
				printf("READ\n");
				/* print variable */
				ASTprint(level+2,p->stmt0);
				printf("\n");
				break;
			case WRITESTMT:
				printf("WRITE\n");
				/* print expression */
				ASTprint(level+2,p->stmt0);
				printf("\n");
				break;
			case EXPRESSION:
				printf("EXPR ");
				/* print mathmatical operation */
				if(p->operator == PLUS)
					printf("ADD(");
				else if(p->operator == MINUS)
					printf("SUBTRACT(");
				else if(p->operator == MULT)
					printf("MULTIPLY(");
				else if(p->operator == DIV)
					printf("DIVIDE(");
				else
					printf("RELATIONAL(");
				/* print expression */
				ASTprint(0,p->stmt0);
				/* print relational operator or commas if math */
				if(p->operator == EQUAL)
					printf(" == ");
				else if(p->operator == NOTEQUAL)
					printf(" != ");
				else if(p->operator == LESSTH)
					printf(" < ");
				else if(p->operator == LESSEQ)
					printf(" <= ");
				else if(p->operator == GREATERTH)
					printf(" > ");
				else if(p->operator == GREATEREQ)
					printf(" >= ");
				else
					printf(", ");
				/* print expression */
				ASTprint(0,p->stmt1);
				printf(")");
				break;
			case IDENTIFIER:
				/* print identifier */
				printf("IDENTIFIER %s",p->name);
				/* if array, print array size-determining expression */
				if(p->stmt0 != NULL) {
					printf("[");
					ASTprint(0,p->stmt0);
					printf("]");
				}
				break;
			case NUMBER:
				/* print number */
				printf("NUMBER %d",p->value);
				break;
			case FUNCTIONCALL:
				/* print function name */
				printf("FUNCTION CALL %s (",p->name);
				/* print function arguments */
				ASTprint(0,p->stmt0);
				printf(")");
				break;
			case ARGUMENT:
				printf("ARGUMENT ");
				/* print expressions */
				ASTprint(0,p->stmt0);
				printf(", ");
				break;
			default: printf("unknown type in ASTprint\n");
		}
		ASTprint(level,p->next);
	}
}
