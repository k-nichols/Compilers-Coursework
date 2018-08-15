%{
int mydebug = 0;
int lineNum = 1;
#include "AST.h"
#include "y.tab.h"
%}


%%

int             {if (mydebug) fprintf(stderr,"Reserved word 'int' found\n");
				return(INT);}
void			{if (mydebug) fprintf(stderr,"Reserved word 'void' found\n");
				return(VOID);}
if              {if (mydebug) fprintf(stderr,"Reserved word 'if' found\n");
				return(IF);}
else			{if (mydebug) fprintf(stderr,"Reserved word 'else' found\n");
				return(ELSE);}
while			{if (mydebug) fprintf(stderr,"Reserved word 'while' found\n");
				return(WHILE);}
return			{if (mydebug) fprintf(stderr,"Reserved word 'return' found\n");
				return(RETURN);}
read			{if (mydebug) fprintf(stderr,"Reserved word 'read' found\n");
				return(READ);}
write			{if (mydebug) fprintf(stderr,"Reserved word 'write' found\n");
				return(WRITE);}
\".*\"          {if (mydebug) fprintf(stderr,"String found\n"); 
                yylval.string = strdup(yytext); return(STRING);}
[a-zA-Z][a-zA-Z0-9]*	{if (mydebug) fprintf(stderr,"Variable name found\n"); 
				yylval.string = strdup(yytext); return(ID);}
[0-9][0-9]*		{if (mydebug) fprintf(stderr,"Digit found\n"); 
                yylval.value=atoi((const char *)yytext); return(NUM);}
[ \t]			{if (mydebug) fprintf(stderr,"Whitespace found\n");}
[=\-+*/%&|(){}\[\]<>,;] {if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
                return (*yytext);}
"<="			{if (mydebug) fprintf(stderr,"relop '<=' found\n");
				return(LE);}
">="			{if (mydebug) fprintf(stderr,"relop '>=' found\n");
				return(GE);}
"=="			{if (mydebug) fprintf(stderr,"relop '==' found\n");
				return(EQ);}
"!="			{if (mydebug) fprintf(stderr,"relop '!=' found\n");
				return(NE);}
\n              {if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext);
				lineNum++;}
"//.*"          {}

%%

int yywrap(void)
{ return 1;}


