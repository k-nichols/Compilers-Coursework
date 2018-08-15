#ifndef EMITAST_H
#define EMITAST_H

void emitAST(ASTnode *p, char *filename);
void printASTglobals(ASTnode *p);
void printASTstrings(ASTnode *p);
void emitIdentifier(ASTnode *p);
void emitExpr(ASTnode *p);
void emitFunction(ASTnode *p);
void evaluateArgs(ASTnode *p);
void copyArgsToParams(ASTnode *arg, ASTnode *param, int fSize);
void emitReturn(ASTnode *p);
void printASTtext(ASTnode *p);

#endif
