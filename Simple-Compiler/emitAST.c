//dw for 8 bytes, string & label

#include "AST.h"
#include "emitAST.h"
#include "symtable.h"
#include <string.h>
#define DW 8

FILE *fp;
char* globalFunc;

/* Function outputs the source code as NASM */
void emitAST(ASTnode *p, char *filename) {
	if ((p == NULL) || (filename == NULL)) return;
	else {
        /* Open a file to write the NASM code to */
        strcat(filename, ".asm");
        fp = fopen(filename, "w");
        
        fprintf(fp, "%%include \"io64.inc\"\n\n");
        
        /* Print global variables */
        printASTglobals(p);
        
        fprintf(fp, "\nsection .data\n\n");
        
        /* Print strings */
        printASTstrings(p);
        
        fprintf(fp, "section .text\n");
        fprintf(fp, "\tglobal main\n\n");
        
        /* Print NASM body code */
        printASTtext(p);
	}
}

void printASTglobals(ASTnode *p) {
    /* Traverse tree and output global variables */
    if(p == NULL)
        return;
    
    if(p->type == VARDEC) {
        /* If no value assigned, string offset is 8 bytes*/
        if(p->value == 0)
            fprintf(fp, "common %s %d\n", p->name, 8);
        /* If an array, string offset is 8 bytes * the array size */
        else
            fprintf(fp, "common %s %d\n", p->name, (p->value * 8));
    }
    printASTglobals(p->next);
}

void printASTstrings(ASTnode *p) {
    /* Traverse tree and output the strings */
    if(p == NULL)
        return;
    /* If a write statement is found, print the string as a label */
    if((p->type == WRITESTMT) && (p->label != NULL)) {
        fprintf(fp, "%s\t\tdb %s, 0\t\t;global string\n", p->label, p->name);
    }
    /* traverse all data paths */
    printASTstrings(p->next);
    printASTstrings(p->stmt0);
    printASTstrings(p->stmt1);
    printASTstrings(p->stmt2);
}

void emitIdentifier(ASTnode *p) {
    /* Variable is array */
    if(p->symbol->IsAFunc == 2) {
        switch(p->stmt0->type) {
            case NUMBER:
                fprintf(fp, "\tmov\trbx, %d\t\t;load RBX register with the number's VALUE\n", p->stmt0->value);
                break;
            case IDENTIFIER:
                emitIdentifier(p->stmt0);
                fprintf(fp, "\tmov\trbx, [rax]\t;load RBX with the identifier VALUE\n");
                break;
            case EXPRESSION:
                emitExpr(p->stmt0);
                fprintf(fp, "\tmov\trbx, [rsp+%d]\t;load RBX with an expression\n", p->stmt0->symbol->offset * DW);
                break;
            case FUNCTIONCALL:
                emitFunction(p->stmt0);
                break;
                fprintf(fp, "\tmov\trbx, rax\t;ASSIGN function result\n");
            default:
                printf("Error: unknown type encountered!");
        }
        fprintf(fp, "\tshl\trbx, 3\t\t;ARRAY reference needs WSIZE difference\n");
    }
    
    /* Same regardless of if scalar or an array */
    if(p->symbol->level == 0)
            fprintf(fp, "\tmov\trax, %s\t\t;get identifier\n", p->name);
    else {
        fprintf(fp, "\tmov\trax, %d\t\t;get identifier offset\n", p->symbol->offset * DW);
        fprintf(fp, "\tadd\trax, rsp\t\t;add the SP to have a direct reference to memory\n", DW);
    }
    
    /* If array, restore temporary value since RAX was just used */
    if(p->symbol->IsAFunc == 2)
        fprintf(fp, "\tadd\trax, rbx\t\t;ensure RAX still contains the temporary value\n");
}

void emitExpr(ASTnode *p) {
    /* evaluate left side */
    switch(p->stmt0->type) {
        case NUMBER:
            fprintf(fp, "\tmov\trax, %d\t\t;left side of expression is a VALUE\n", p->stmt0->value);
            break;
        case IDENTIFIER:
            emitIdentifier(p->stmt0);
            fprintf(fp, "\tmov\trax, [rax]\t;left side of expression is an IDENTIFIER\n");
            break;
        case EXPRESSION:
            emitExpr(p->stmt0);
            fprintf(fp, "\tmov\trax, [rsp+%d]\t;left side of expression is an EXPRESSION\n", p->stmt0->symbol->offset * DW);
            break;
        case FUNCTIONCALL:
            emitFunction(p->stmt0);
            break;
        default:
            printf("Error: unknown type encountered!");
    }
    fprintf(fp, "\tmov\t[rsp+%d], rax\t;temporarily store left side of expression\n", p->symbol->offset * DW);
    
    /* evaluate right side */
    switch(p->stmt1->type) {
        case NUMBER:
            fprintf(fp, "\tmov\trbx, %d\t\t;right side of expression is a VALUE\n", p->stmt1->value);
            break;
        case IDENTIFIER:
            emitIdentifier(p->stmt1);
            fprintf(fp, "\tmov\trbx, [rax]\t;right side of expression is an IDENTIFIER VALUE\n");
            break;
        case EXPRESSION:
            emitExpr(p->stmt1);
            fprintf(fp, "\tmov\trbx, [rsp+%d]\t;right side of expression is an EXPRESSION\n", p->stmt1->symbol->offset * DW);
            break;
        case FUNCTIONCALL:
            emitFunction(p->stmt1);
            fprintf(fp, "\tmov rbx, rax\t;load second register with the evaluated function call\n");
            break;
        default:
            printf("Error: unknown type encountered!");
    }
    fprintf(fp, "\tmov\trax, [rsp+%d]\t;ensure RAX still contains the left side evaluation\n", p->symbol->offset * DW);
    
    switch(p->operator) {
        case PLUS:
            fprintf(fp, "\tadd\trax, rbx\t\t;evaluate addition expression\n");
            break;
        case MINUS:
            fprintf(fp, "\tsub\trax, rbx\t\t;evaluate subtraction expression\n");
            break;
        case MULT:
            fprintf(fp, "\timul\trax, rbx\t\t;evaluate multiplication expression\n");
            break;
        case DIV:
            fprintf(fp, "\txor\trdx, rdx\t;clear RDX register\n");
            fprintf(fp, "\tidiv\trbx\t;divide by divisor\n");
            break;
        case EQUAL:
            fprintf(fp, "\tcmp\trax, rbx\t\t;equality comparison\n");
            fprintf(fp, "\tsete\tal\t\t;equality comparison\n");
            fprintf(fp, "\tmov\trbx, 1\t\t;set RBX to one to filter RAX\n");
            fprintf(fp, "\tand\trax, rbx\t\t;filter RAX\n");
            break;
        case NOTEQUAL:
            fprintf(fp, "\tcmp\trax, rbx\t\t;not equal comparison\n");
            fprintf(fp, "\tsetne\tal\t\t;not equal comparison\n");
            fprintf(fp, "\tmov\trbx, 1\t\t;set RBX to one to filter RAX\n");
            fprintf(fp, "\tand\trax, rbx\t\t;filter RAX\n");
            break;
        case LESSTH:
            fprintf(fp, "\tcmp\trax, rbx\t\t;less than comparison\n");
            fprintf(fp, "\tsetl\tal\t\t;less than comparison\n");
            fprintf(fp, "\tmov\trbx, 1\t\t;set RBX to one to filter RAX\n");
            fprintf(fp, "\tand\trax, rbx\t\t;filter RAX\n");
            break;
        case LESSEQ:
            fprintf(fp, "\tcmp\trax, rbx\t\t;less or equal to comparison\n");
            fprintf(fp, "\tsetle\tal\t\t;less or equal to comparison\n");
            fprintf(fp, "\tmov\trbx, 1\t\t;set RBX to one to filter RAX\n");
            fprintf(fp, "\tand\trax, rbx\t\t;filter RAX\n");
            break;
        case GREATERTH:
            fprintf(fp, "\tcmp\trax, rbx\t\t;greater than comparison\n");
            fprintf(fp, "\tsetg\tal\t\t;greater than comparison\n");
            fprintf(fp, "\tmov\trbx, 1\t\t;set RBX to one to filter RAX\n");
            fprintf(fp, "\tand\trax, rbx\t\t;filter RAX\n");
            break;
        case GREATEREQ:
            fprintf(fp, "\tcmp\trax, rbx\t\t;greater or equal to comparison\n");
            fprintf(fp, "\tsetge\tal\t\t;greater or equal to comparison\n");
            fprintf(fp, "\tmov\trbx, 1\t\t;set RBX to one to filter RAX\n");
            fprintf(fp, "\tand\trax, rbx\t\t;filter RAX\n");
            break;
        default:
            printf("Error: unknown operator encountered!");
    }
    fprintf(fp, "\tmov\t[rsp+%d], rax\t;store the result in the expression's temporary location\n", p->symbol->offset * DW);
}

void emitFunction(ASTnode *p) {
    evaluateArgs(p->stmt0);
    copyArgsToParams(p->stmt0, p->symbol->fparms, p->symbol->mySize);
    fprintf(fp, "\tcall\t%s\t;call function\n", p->name);
    return;
}

void evaluateArgs(ASTnode *p) {
    if(p == NULL) {
        return;
    }
    switch(p->stmt0->type) {
        case NUMBER:
            fprintf(fp, "\tmov\trax, %d\t\t;ARGUMENT number\n", p->stmt0->value);
            break;
        case IDENTIFIER:
            emitIdentifier(p->stmt0);
            fprintf(fp, "\tmov\trax, [rax]\t;ARGUMENT identifier VALUE\n");
            break;
        case EXPRESSION:
            emitExpr(p->stmt0);
            fprintf(fp, "\tmov\trax, [rsp+%d]\t;ARGUMENT to an expression\n", p->stmt0->symbol->offset * DW);
            break;
        case FUNCTIONCALL:
            emitFunction(p->stmt0);
            break;
        default:
            printf("Error: unknown type encountered!");
    }
    fprintf(fp, "\tmov\t[rsp+%d], rax\t;store argument into arglist offset\n", p->symbol->offset * DW);
    evaluateArgs(p->next);
}

void copyArgsToParams(ASTnode *arg, ASTnode *param, int fSize) {
    fprintf(fp, "\tmov\trbx, rsp\t;store rsp in a register\n");
    fprintf(fp, "\tsub\trbx, %d\t;subtract function size +1 to get location on stack\n", (fSize + 1) * DW);
    
    while(param != NULL) {
        fprintf(fp, "\tmov\trax, [rsp+%d]\t;temporarily store argument contents\n", arg->symbol->offset * DW);
        fprintf(fp, "\tmov\t[rbx+%d], rax\t;copy contents of rax into the param memory address\n", param->symbol->offset * DW);
        
        /* Traverse all */
        arg = arg->next;
        param = param->next;
    }
}

void emitReturn(ASTnode *p) {
    if((p != NULL) && (p->stmt0 != NULL))
        switch(p->stmt0->type) {
            case NUMBER:
                fprintf(fp, "\tmov\trax, %d\t\t;RETURN number\n", p->stmt0->value);
                break;
            case IDENTIFIER:
                emitIdentifier(p->stmt0);
                fprintf(fp, "\tmov\trax, [rax]\t;RETURN identifier VALUE\n");
                break;
            case EXPRESSION:
                emitExpr(p->stmt0);
                fprintf(fp, "\tmov\trax, [rsp+%d]\t;RETURN to an expression\n", p->stmt0->symbol->offset * DW);
                break;
            case FUNCTIONCALL:
                emitFunction(p->stmt0);
                break;
            default:
                printf("Error: unknown type encountered!");
        }
    else {
        fprintf(fp, "\txor\trax, rax\t;\n");
    }
        fprintf(fp, "\tmov\trbp, [rsp]\t;FUNCTION END restore rbp\n");
        fprintf(fp, "\tmov\trsp, [rsp+%d]\t;FUNCTION END restore rsp\n", DW);
        if(strcmp(globalFunc, "main") == 0)
            fprintf(fp, "\tmov\trsp, rbp\t;rsp and rbp must be same on exit\n");
        fprintf(fp, "\tret\t\t\t;RETURN to caller\n");
}

/* */
void printASTtext(ASTnode *p) {
    /* Prepare if-else/while expression labels*/
    char *L1;
    char *L2;
    /* Traverse tree and output NASM code */
    if(p == NULL)
        return;
    
    switch(p->type) {
        
        case VARDEC:
            break;
            
        case FUNCTDEC:
            /* function name + special line in main ONLY */
            globalFunc = p->name;
            fprintf(fp, "%s:\t\t;Start Function\n\n", p->name);
            if(strcmp(p->name, "main") == 0)
                fprintf(fp, "\tmov\trbp, rsp\t\t;SPECIAL RSP to RSB for MAIN only\n");
            
            /* startup code for every function */
            fprintf(fp, "\tmov\tr8, rsp\t\t;FUNC header RSP has to be at most RBP\n");
            fprintf(fp, "\tadd\tr8, -%d\t\t;adjust Stack Pointer for Activation\n", p->value * DW);
            fprintf(fp, "\tmov\t[r8], rbp\t;FUNC header store old BP\n");
            fprintf(fp, "\tmov\t[r8+%d], rsp\t;FUNC header store old SP\n", DW);
            if(strcmp(p->name, "main") != 0)
                fprintf(fp, "\tmov\trbp, rsp\t\t;FUNC header new SP\n");
            fprintf(fp, "\tmov\trsp, r8\t\t;FUNC header new SP\n");
            
            /* section varies based on the function */
            printASTtext(p->stmt1);
            
            /* ending code for every function */
            fprintf(fp, "\n\tmov\trbp, [rsp]\t;FUNC end restore old BP\n");
            fprintf(fp, "\tmov\trsp, [rsp+8]\t;FUNC end restore old SP\n", DW);
            fprintf(fp, "\tmov\trsp, rbp\t\t;stack and BP need to be same on exit for main\n");
            fprintf(fp, "\tret\n");
            break;
            
        case CMPDSTMT:
            printASTtext(p->stmt0);
            printASTtext(p->stmt1);
            break;
        
        case EXPRSTMT:
            /* Determine type of expression */
            switch(p->stmt0->type) {
                case NUMBER:
                    fprintf(fp, "\tmov\trdx, %d\t\t;ASSIGN number\n", p->stmt0->value);
                    break;
                case IDENTIFIER:
                    emitIdentifier(p->stmt0);
                    fprintf(fp, "\tmov\trdx, [rax]\t;ASSIGN identifier VALUE\n");
                    break;
                case EXPRESSION:
                    emitExpr(p->stmt0);
                    fprintf(fp, "\tmov\trdx, [rsp+%d]\t;ASSIGN to an expression\n", p->stmt0->symbol->offset * DW);
                    break;
                case FUNCTIONCALL:
                    emitFunction(p->stmt0);
                    fprintf(fp, "\tmov\trdx, rax\t;ASSIGN function result\n");
                    break;
                default:
                    printf("Error: unknown type encountered!");
            }
            fprintf(fp, "\tmov\t[rsp+%d], rdx\t;STORE right side of ASSIGN temporarily\n", p->symbol->offset * DW);
            
            break;
            
        case ASGNSTMT:
            fprintf(fp, "\n");
            printASTtext(p->stmt1);
            emitIdentifier(p->stmt0);
            /* Restore value in case of alteration */
            fprintf(fp, "\tmov\trdx, [rsp+%d]\t;FETCH right side of ASSIGN temporarily\n", p->stmt1->symbol->offset * DW);
            fprintf(fp, "\tmov\t[rax], rdx\t;ASSIGN final store\n");
            break;
            
        case SELECSTMT:
            /* Create labels for the start and end of the else statement(s) */
            L1=CreateLabel();
            L2=CreateLabel();
            
            /* Determine type of if expression */
            switch(p->stmt0->type) {
                case NUMBER:
                    fprintf(fp, "\tmov\trax, %d\t\t;load RAX with the number's VALUE\n", p->stmt0->value);
                    break;
                case IDENTIFIER:
                    emitIdentifier(p->stmt0);
                    fprintf(fp, "\tmov\trax, [rax]\t;load RAX with the identifier VALUE\n");
                    break;
                case EXPRESSION:
                    emitExpr(p->stmt0);
                    fprintf(fp, "\tmov\trax, [rsp+%d]\t;load RAX with an EXPRESSION\n", p->stmt0->symbol->offset * DW);
                    break;
                case FUNCTIONCALL:
                    emitFunction(p->stmt0);
                    break;
                default:
                    printf("Error: unknown type encountered!");
            }
            /* If expression evaluates to false, jump to else */
            fprintf(fp, "\n\tcmp\trax, 0\t\t;IF compare to false\n");
            fprintf(fp, "\tje\t%s\t\t;ELSE jump\n\n", L1);
            /* If expression evaluates to true, fall through and jump over else */
            printASTtext(p->stmt1);
            fprintf(fp, "\tjmp\t%s\t\t;skip ELSE jump\n", L2);
            /* Else code */
            fprintf(fp, "\n%s:\t\t;ELSE target\n\n", L1);
            printASTtext(p->stmt2);
            fprintf(fp, "\n%s:\t\t;End of ELSE\n\n", L2);
            break;
            
        case ITRSTMT:
            /* Create labels for the start and en of the while loop */
            L1=CreateLabel();
            L2=CreateLabel();
            
            /* Begin while loop */
            fprintf(fp, "\n%s:\t\t;WHILE TOP target\n\n", L1);
            /* Determine type of while expression */
            switch(p->stmt0->type) {
                case NUMBER:
                    fprintf(fp, "\tmov\trax, %d\t\t;load RAX with the number's VALUE\n", p->stmt0->value);
                    break;
                case IDENTIFIER:
                    emitIdentifier(p->stmt0);
                    fprintf(fp, "\tmov\trax, [rax]\t;load RAX with the identifier VALUE\n");
                    break;
                case EXPRESSION:
                    emitExpr(p->stmt0);
                    fprintf(fp, "\tmov\trax, [rsp+%d]\t;load RAX with an expression\n", p->stmt0->symbol->offset * DW);
                    break;
                case FUNCTIONCALL:
                    emitFunction(p->stmt0);
                    break;
                default:
                    printf("Error: unknown type encountered!");
            }
            /* If expression evaluates to false, jump out of the loop */
            fprintf(fp, "\n\tcmp\trax, 0\t\t;WHILE compare to false\n");
            fprintf(fp, "\tje\t%s\t\t;WHILE branch out\n\n", L2);
            /* Print compound statements */
            printASTtext(p->stmt1);
            /* Next iteration */
            fprintf(fp, "\tjmp\t%s\t\t;WHILE jump back\n", L1);
            fprintf(fp, "\n%s:\t\t;End of WHILE\n\n", L2);
            break;
            
        case RTRNSTMT:
            emitReturn(p);
            break;
            
        case READSTMT:
            emitIdentifier(p->stmt0);
            fprintf(fp, "\tGET_DEC %d, [rax]\t\t;store value\n", DW);
            break;
            
        case WRITESTMT:
            if(p->stmt0 == NULL) {
                fprintf(fp, "\tPRINT_STRING %s\t\t;print a string\n", p->label);
                fprintf(fp, "\tNEWLINE\t\t\t;standard Write a NEWLINE\n");
            }
            else {
                switch(p->stmt0->type) {
                    case NUMBER:
                        fprintf(fp, "\tmov\trsi, %d\t\t;load RSI with the number's VALUE\n", p->stmt0->value);
                        break;
                    case IDENTIFIER:
                        emitIdentifier(p->stmt0);
                        fprintf(fp, "\tmov\trsi, [rax]\t;load RSI with the identifier VALUE\n");
                        break;
                    case EXPRESSION:
                        emitExpr(p->stmt0);
                        fprintf(fp, "\tmov\trsi, [rsp+%d]\t;load RSI with an expression\n", p->stmt0->symbol->offset * DW);
                        break;
                    case FUNCTIONCALL:
                        emitFunction(p->stmt0);
                        fprintf(fp, "\tmov\trsi, rax\t;ASSIGN function result\n");
                        break;
                    default:
                        printf("Error: unknown type encountered!");
                }
                fprintf(fp, "\tPRINT_DEC %d, rsi\t\t;print a number\n", DW);
                fprintf(fp, "\tNEWLINE\t\t\t;standard Write a NEWLINE\n"); 
            }
            break;

        default:
            printf("Error: unknown type encountered!");
    }
    printASTtext(p->next);
}
