%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "AST.h"
#include "symtable.h"

#define max(x,y) ((x) > (y) ? (x) : (y))

int mydebug;
int lineNum;
static int level = 0;
static int offset = 0;
static int globalOffset = 0;
static int maxOffset = 0;

void yyerror (char *s)  /* Called by yyparse on error */
{
  printf ("YACC Parse Error: %s on line number %d\n", s, lineNum);
}

%}

%start program

%union {
	int value;
	char *string;
	ASTnode *node;
	enum OPERATORS operator;
}
%type <node> program decls dec vardec functdec params paramls param cmpdstmt lcdecs stmtls stmt exprstmt asgnstmt selecstmt itrstmt rtrnstmt readstmt writestmt expr var simplexpr addexpr term factor functcall args argls
%type <operator> typespec relop addop multop
%token <value> NUM INT VOID IF ELSE WHILE RETURN READ WRITE LE GE EQ NE
%token <string> STRING ID

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS


%%	/* end specs, begin rules */

program	:	decls
            { rootNode=$1; }
        ;

decls	:	dec { $$=$1; }
        |	dec decls {
                $1->next=$2;
                $$=$1;
            }
        ;

dec	:	vardec { $$=$1; }
	|	functdec { $$=$1; }
	;

vardec	:	typespec ID ';' {
                /* Search for the specified ID at the current level only */
                /* If the variable does not already exist, insert into the symbol table */
                if(Search($2, level, 0) == NULL) {
                    $$=ASTCreateNode(VARDEC);
                    $$->operator=$1; /* int or void */
                    $$->isType=$1;    /* set type for comparison */
                    $$->name=$2;     /* identifier ID */
                    /* Insert into symbol table */
                    $$->symbol=Insert($2, $1, 0, level, 1, offset, NULL);
                    offset++;     /* offset memory address for next insertion */
                }
                /* Else, throw an error for the ID and the associated error */
                else {
                    yyerror($2);
                    yyerror("symbol already in use");
                    exit(1);
                }
            }
        |	typespec ID '[' NUM ']' ';' {
                /* Search for the specified ID at the current level only */
                /* If the variable does not already exist, insert into the symbol table */
                if(Search($2, level, 0) == NULL) {
                    $$=ASTCreateNode(VARDEC);
                    $$->operator=$1; /* int or void */
                    $$->isType=$1;    /* set type for comparison */
                    $$->name=$2;     /* identifier ID */
                    $$->value=$4;    /* array dimension NUM */
                    /* Insert into symbol table */
                    $$->symbol = Insert($2, $1, 2, level, $4, offset, NULL);
                    offset += $4;    /* offset memory address for next insertion */
                }
                /* Else, throw an error for the ID and the associated error */
                else {
                    yyerror($2);
                    yyerror("symbol already in use");
                    exit(1);
                }
            }
        ;

typespec:	INT { $$=INTTYPE; }
	|	VOID { $$=VOIDTYPE; }
	;

functdec:   typespec ID '(' {
                if(Search($2, level, 0) == NULL) {
                    Insert($2, $1, 1, level, 0, 0, NULL);
                    /* Save current offset as the global offset */
                    globalOffset = offset;
                    /* Set current offset as 0 within the function */
                    offset = 2;
                    maxOffset = offset;
                }
                else {
                    yyerror($2);
                    yyerror("function already in use");
                    exit(1);
                }
            }
            params {
                /* Get function symbol table entry, set fparms to params */
                (Search($2, 0, 0))->fparms = $5;
            }
            ')' cmpdstmt {
                $$=ASTCreateNode(FUNCTDEC);
                $$->operator=$1;/* int or void */
                $$->isType=$1;   /* set type for comparison */
                $$->name=$2;	/* identifier ID */
                $$->value=maxOffset; /* set offset */
                $$->stmt0=$5;	/* function parameters */
                $$->stmt1=$8;	/* compound stmtements */
                /* Get symbol table entry */
                $$->symbol = Search($2, 0, 0);
                $$->symbol->mySize = maxOffset;
                
                offset -= Delete(1);
                offset = globalOffset;  /* return global offset */
                level = 0;              /* reset level */
            }
    ;

params	:	VOID { $$=NULL; }
        |	paramls { $$=$1; }
        ;

paramls	:	param { $$=$1; }
        |	param ',' paramls {
                $1->next=$3;
                $$=$1;
            }
        ;

param	:	typespec ID { 
                /* check if appears in the symbol table at one higher level */
                if(Search($2, level+1, 0) == NULL) {
                    $$=ASTCreateNode(PARAM);
                    $$->operator=$1;/* int or void */
                    $$->isType=$1;   /* set type for comparison */
                    $$->name=$2;	/* identifier ID */
                    $$->symbol = Insert($2, $1, 0, level+1, 1, offset, NULL);
                    if(mydebug) Display();
                    offset++;    /* offset memory address for next insertion */
                }
            }
        |	typespec ID '[' ']' {
                /* check if appears in the symbol table at one higher level */
                if(Search($2, level+1, 0) == NULL) {
                    $$=ASTCreateNode(PARAM);
                    $$->operator=$1;/* int or void */
                    $$->isType=$1;   /* set type for comparison */
                    $$->name=$2;	/* identifier ID */
                    $$->value=-1;	/* no value */
                    $$->symbol = Insert($2, $1, 2, level+1, 1, offset, NULL);
                    offset++;    /* offset memory address for next insertion */
                }
            }
        ;

cmpdstmt:	'{' { level++; }
            lcdecs stmtls '}' {
                $$=ASTCreateNode(CMPDSTMT);
                $$->stmt0=$3;	/* local declarations */
                $$->stmt1=$4;	/* statement list */
                
                if(mydebug) Display();
                /* Remove all symbols within the level */
                maxOffset = max(offset, maxOffset);
                offset -= Delete(level); /*  */
                level--;    /* back out a level */
            }
        ;

lcdecs	:	/*empty*/ { $$=NULL; }
        |	vardec lcdecs {
                $1->next=$2;
                $$=$1;
            }
        ;

stmtls	:	/*empty*/ { $$=NULL; }
        |	stmt stmtls {
                $1->next=$2;
                $$=$1;
            }
        ;

stmt	:	cmpdstmt { $$=$1; }
        |	exprstmt { $$=$1; }
        |	asgnstmt { $$=$1; }
        |	selecstmt { $$=$1; }
        |	itrstmt { $$=$1; }
        |	rtrnstmt { $$=$1; }
        |	readstmt { $$=$1; }
        |	writestmt { $$=$1; }
        ;

exprstmt:	';' { $$=NULL; }
        |	expr ';' {
                $$=ASTCreateNode(EXPRSTMT);
                $$->stmt0=$1;	/* expression */
                $$->isType=$1->isType;
                $$->name=CreateTemp();
                $$->symbol=Insert($$->name, INTTYPE, 0, level, 1, offset, NULL);
                offset ++;
            }
        ;

asgnstmt:	var '=' exprstmt {
                if(($1->isType != VOIDTYPE) && ($1->isType == $3->isType)) {
                    $$=ASTCreateNode(ASGNSTMT);
                    $$->stmt0=$1;	/* variable */
                    $$->stmt1=$3;	/* expression statement */
                }
                else {
                    yyerror("type mismatch, assignment cannot be made");
                    exit(1);
                }
            }
        ;

selecstmt:	IF '(' expr ')' stmt {
                $$=ASTCreateNode(SELECSTMT);
                $$->stmt0=$3;	/* expression */
                $$->stmt1=$5;	/* if statement */
                $$->stmt2=NULL;	/* no else statement */
            }
        |	IF '(' expr ')' stmt ELSE stmt {
                $$=ASTCreateNode(SELECSTMT);
                $$->stmt0=$3;	/* expression */
                $$->stmt1=$5;	/* if statement */
                $$->stmt2=$7;	/* else statement */
            }
        ;

itrstmt	:	WHILE '(' expr ')' stmt {
                $$=ASTCreateNode(ITRSTMT);
                $$->stmt0=$3;	/* expression */
                $$->stmt1=$5;	/* statement */
            }
        ;

rtrnstmt:	RETURN ';'  { $$=ASTCreateNode(RTRNSTMT); }
        |	RETURN expr ';' {
                $$=ASTCreateNode(RTRNSTMT);
                $$->stmt0=$2;	/* expression */
            }
        ;

readstmt:	READ var ';' {
                $$=ASTCreateNode(READSTMT);
                $$->stmt0=$2;	/* variable */
            }
        ;

writestmt:	WRITE expr ';' {
                $$=ASTCreateNode(WRITESTMT);
                $$->stmt0=$2;	/* expression */
            }
        |   WRITE STRING ';' {
                $$=ASTCreateNode(WRITESTMT);
                $$->name=$2;	/* expression */
                $$->label=CreateLabel();
            }
        ;

expr	:	simplexpr { $$=$1; }
        ;

var	:	ID {
            struct SymbTab *p;
            /* check if appears in the symbol table at current level or lower */
            if((p = Search($1, level, 1)) != NULL) {
                $$=ASTCreateNode(IDENTIFIER);
                $$->name=$1;	/* identifier ID */
                
                /* check if the found variable is an array */
                if(p->IsAFunc != 2) {
                    $$->symbol=p;
                    $$->isType=p->Type;
                }
                else {
                    yyerror($1);
                    yyerror("variable is an array");
                    exit(1);
                }
            }
            /* if not found, throw error (variable is undeclared) */
            else {
                yyerror($1);
                yyerror("variable is undeclared");
                exit(1);
            }
            }
    |   ID '[' expr ']' {
            struct SymbTab *p;
            /* check if appears in the symbol table at current level or lower */
            if((p = Search($1, level, 1)) != NULL) {
                $$=ASTCreateNode(IDENTIFIER);
                $$->name=$1;	/* identifier ID */
                $$->stmt0=$3;	/* expression */
                
                /* check if the found variable is an array */
                if(p->IsAFunc == 2) {
                    $$->symbol=p;
                    $$->isType=p->Type;
                }
                else {
                    yyerror($1);
                    yyerror("type mismatch, variable is not an array");
                    exit(1);
                }
            }
            /* if not found, throw error (variable is undeclared) */
            else {
                yyerror($1);
                yyerror("variable is undeclared");
                exit(1);
            }
        }
    ;

simplexpr:	addexpr { $$=$1; }
        |	simplexpr relop addexpr {
                if($1->isType == $3->isType) {
                    $$=ASTCreateNode(EXPRESSION);
                    $$->name=CreateTemp();
                    $$->symbol=Insert($$->name, INTTYPE, 0, level, 1, offset, NULL);
                    offset ++;
                    
                    $$->stmt0=$1;	/* simple expression */
                    $$->operator=$2;/* relational operator */
                    $$->isType=INTTYPE;
                    $$->stmt1=$3;	/* additive expression */
                }
                else {
                    yyerror("type mismatch, cannot perform relational operation");
                    exit(1);
                }
            }
        ;

relop	:	LE { $$=LESSEQ; }
        |	'<' { $$=LESSTH; }
        |	'>' { $$=GREATERTH; }
        |	GE { $$=GREATEREQ; }
        |	EQ { $$=EQUAL; }
        |	NE { $$=NOTEQUAL; }
        ;

addexpr	:	term { $$=$1; }
        |	addexpr addop term {
                if($1->isType == $3->isType) {
                    $$=ASTCreateNode(EXPRESSION);
                    $$->name=CreateTemp();
                    $$->symbol=Insert($$->name, INTTYPE, 0, level, 1, offset, NULL);
                    offset++;
                    
                    $$->stmt0=$1;	/* additive expression */
                    $$->operator=$2;/* '+' or '-' operator */
                    $$->isType=INTTYPE;
                    $$->stmt1=$3;	/* term */
                }
                else {
                    yyerror("type mismatch, cannot perform additive operation");
                    exit(1);
                }
            }
        ;

addop	:	'+' { $$=PLUS; }
        |	'-' { $$=MINUS; }
        ;

term	:	factor { $$=$1; }
        |	term multop factor {
                if($1->isType == $3->isType) {
                    $$=ASTCreateNode(EXPRESSION);
                    $$->name=CreateTemp();
                    $$->symbol=Insert($$->name, INTTYPE, 0, level, 1, offset, NULL);
                    offset++;
                    
                    $$->stmt0=$1;	/* term */
                    $$->operator=$2;/* '*' or '/' operator */
                    $$->isType=INTTYPE;
                    $$->stmt1=$3;	/* factor */
                }
                else {
                    yyerror("type mismatch, cannot perform multiplication operation");
                    exit(1);
                }
            }
        ;

multop	:	'*' { $$=MULT; }
        |	'/' { $$=DIV; }
        ;

factor	:	'(' expr ')' { $$=$2; }
        |	NUM {
                $$=ASTCreateNode(NUMBER);
                $$->value=$1;	/* expression */
                $$->isType=INTTYPE;
            }
        |	var { $$=$1; }
        |	functcall { $$=$1; }
        ;

functcall:	ID '(' args ')' {
            struct SymbTab *p;
            p=Search($1, 0, 0);
            /* If function exists */
            if(p != NULL) {
                /* If call is to a function */
                if(p->IsAFunc == 1) {
                    /* If arguments match required function parameters */
                    if(compareFormal(p->fparms, $3)) {
                        $$=ASTCreateNode(FUNCTIONCALL);
                        $$->name=$1;	/* indentifier ID */
                        $$->stmt0=$3;	/* arguments */
                        $$->isType=p->Type;
                        $$->symbol=p;
                    }
                    else {
                        yyerror($1);
                        yyerror("arguments are not compatible with the function being called");
                        exit(1);
                    }
                }
                else {
                    yyerror($1);
                    yyerror("call must be made to a function");
                    exit(1);
                }
            }
            else {
                yyerror($1);
                yyerror("function does not exist");
                exit(1);
            }
		}
	;

args	:	/*empty*/ { $$=NULL; }
        |	argls { $$=$1; }
        ;

argls	:	expr {
                $$=ASTCreateNode(ARGUMENT);
                $$->name=CreateTemp();
                $$->symbol=Insert($$->name, INTTYPE, 0, level, 1, offset, NULL);
                offset++;
                $$->next=NULL;
                $$->stmt0=$1;	/* expression */
                $$->isType=$1->isType;
            }
        |	expr ',' argls {
                $$=ASTCreateNode(ARGUMENT);
                $$->name=CreateTemp();
                $$->symbol=Insert($$->name, INTTYPE, 0, level, 1, offset, NULL);
                offset++;
                $$->next=$3;    /* argument list */
                $$->stmt0=$1;	/* expression */
                $$->isType=$1->isType;
            }
        ;

%%	/* end of rules, start of program */

main(int argv, char *argc[]) { 
	int i = 1;
	char *nasmFile;
	mydebug = 0;
	
	/* ... -d = debug, ... -o <filename> = output NASM file */
	while(i < argv) {
        if (strcmp(argc[i], "-d") == 0)
            mydebug = 1;
        else if (strcmp(argc[i], "-o") == 0) {
             nasmFile = argc[i + 1];
             i++;
        }
        i++;
    }

	yyparse();
	if(mydebug) fprintf(stderr,"The input has been syntactically checked\n\n");
	emitAST(rootNode, nasmFile);  /* this is where we can do things with the AST like print it or process it */
	if(mydebug) Display();
}
