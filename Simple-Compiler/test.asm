%include "io64.inc"

common i 8
common x 800

section .data

_L1		db "Enter three integers on their own lines", 0		;global string
_L2		db "You entered for variables i, j and k:", 0		;global string
_L3		db "(i + j) * k =", 0		;global string
_L4		db "(k - j) / 2 =", 0		;global string
_L9		db "This loop should print 1-4", 0		;global string
_L6		db "i equals k", 0		;global string
_L7		db "i is less than k", 0		;global string
_L8		db "i is greater than k", 0		;global string
_L5		db "i is not the same as j", 0		;global string
_L0		db "Void function works", 0		;global string
section .text
	global main

add:		;Start Function

	mov	r8, rsp		;FUNC header RSP has to be at most RBP
	add	r8, -40		;adjust Stack Pointer for Activation
	mov	[r8], rbp	;FUNC header store old BP
	mov	[r8+8], rsp	;FUNC header store old SP
	mov	rbp, rsp		;FUNC header new SP
	mov	rsp, r8		;FUNC header new SP
	mov	rax, 16		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rax, [rax]	;left side of expression is an IDENTIFIER
	mov	[rsp+32], rax	;temporarily store left side of expression
	mov	rax, 24		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rbx, [rax]	;right side of expression is an IDENTIFIER VALUE
	mov	rax, [rsp+32]	;ensure RAX still contains the left side evaluation
	add	rax, rbx		;evaluate addition expression
	mov	[rsp+32], rax	;store the result in the expression's temporary location
	mov	rax, [rsp+32]	;RETURN to an expression
	mov	rbp, [rsp]	;FUNCTION END restore rbp
	mov	rsp, [rsp+8]	;FUNCTION END restore rsp
	ret			;RETURN to caller

	mov	rbp, [rsp]	;FUNC end restore old BP
	mov	rsp, [rsp+8]	;FUNC end restore old SP
	mov	rsp, rbp		;stack and BP need to be same on exit for main
	ret
subtract:		;Start Function

	mov	r8, rsp		;FUNC header RSP has to be at most RBP
	add	r8, -40		;adjust Stack Pointer for Activation
	mov	[r8], rbp	;FUNC header store old BP
	mov	[r8+8], rsp	;FUNC header store old SP
	mov	rbp, rsp		;FUNC header new SP
	mov	rsp, r8		;FUNC header new SP
	mov	rax, 16		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rax, [rax]	;left side of expression is an IDENTIFIER
	mov	[rsp+32], rax	;temporarily store left side of expression
	mov	rax, 24		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rbx, [rax]	;right side of expression is an IDENTIFIER VALUE
	mov	rax, [rsp+32]	;ensure RAX still contains the left side evaluation
	sub	rax, rbx		;evaluate subtraction expression
	mov	[rsp+32], rax	;store the result in the expression's temporary location
	mov	rax, [rsp+32]	;RETURN to an expression
	mov	rbp, [rsp]	;FUNCTION END restore rbp
	mov	rsp, [rsp+8]	;FUNCTION END restore rsp
	ret			;RETURN to caller

	mov	rbp, [rsp]	;FUNC end restore old BP
	mov	rsp, [rsp+8]	;FUNC end restore old SP
	mov	rsp, rbp		;stack and BP need to be same on exit for main
	ret
multiply:		;Start Function

	mov	r8, rsp		;FUNC header RSP has to be at most RBP
	add	r8, -40		;adjust Stack Pointer for Activation
	mov	[r8], rbp	;FUNC header store old BP
	mov	[r8+8], rsp	;FUNC header store old SP
	mov	rbp, rsp		;FUNC header new SP
	mov	rsp, r8		;FUNC header new SP
	mov	rax, 16		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rax, [rax]	;left side of expression is an IDENTIFIER
	mov	[rsp+32], rax	;temporarily store left side of expression
	mov	rax, 24		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rbx, [rax]	;right side of expression is an IDENTIFIER VALUE
	mov	rax, [rsp+32]	;ensure RAX still contains the left side evaluation
	imul	rax, rbx		;evaluate multiplication expression
	mov	[rsp+32], rax	;store the result in the expression's temporary location
	mov	rax, [rsp+32]	;RETURN to an expression
	mov	rbp, [rsp]	;FUNCTION END restore rbp
	mov	rsp, [rsp+8]	;FUNCTION END restore rsp
	ret			;RETURN to caller

	mov	rbp, [rsp]	;FUNC end restore old BP
	mov	rsp, [rsp+8]	;FUNC end restore old SP
	mov	rsp, rbp		;stack and BP need to be same on exit for main
	ret
divide:		;Start Function

	mov	r8, rsp		;FUNC header RSP has to be at most RBP
	add	r8, -40		;adjust Stack Pointer for Activation
	mov	[r8], rbp	;FUNC header store old BP
	mov	[r8+8], rsp	;FUNC header store old SP
	mov	rbp, rsp		;FUNC header new SP
	mov	rsp, r8		;FUNC header new SP
	mov	rax, 16		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rax, [rax]	;left side of expression is an IDENTIFIER
	mov	[rsp+32], rax	;temporarily store left side of expression
	mov	rax, 24		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rbx, [rax]	;right side of expression is an IDENTIFIER VALUE
	mov	rax, [rsp+32]	;ensure RAX still contains the left side evaluation
	xor	rdx, rdx	;clear RDX register
	idiv	rbx	;divide by divisor
	mov	[rsp+32], rax	;store the result in the expression's temporary location
	mov	rax, [rsp+32]	;RETURN to an expression
	mov	rbp, [rsp]	;FUNCTION END restore rbp
	mov	rsp, [rsp+8]	;FUNCTION END restore rsp
	ret			;RETURN to caller

	mov	rbp, [rsp]	;FUNC end restore old BP
	mov	rsp, [rsp+8]	;FUNC end restore old SP
	mov	rsp, rbp		;stack and BP need to be same on exit for main
	ret
f:		;Start Function

	mov	r8, rsp		;FUNC header RSP has to be at most RBP
	add	r8, -16		;adjust Stack Pointer for Activation
	mov	[r8], rbp	;FUNC header store old BP
	mov	[r8+8], rsp	;FUNC header store old SP
	mov	rbp, rsp		;FUNC header new SP
	mov	rsp, r8		;FUNC header new SP
	PRINT_STRING _L0		;print a string
	NEWLINE			;standard Write a NEWLINE

	mov	rbp, [rsp]	;FUNC end restore old BP
	mov	rsp, [rsp+8]	;FUNC end restore old SP
	mov	rsp, rbp		;stack and BP need to be same on exit for main
	ret
main:		;Start Function

	mov	rbp, rsp		;SPECIAL RSP to RSB for MAIN only
	mov	r8, rsp		;FUNC header RSP has to be at most RBP
	add	r8, -152		;adjust Stack Pointer for Activation
	mov	[r8], rbp	;FUNC header store old BP
	mov	[r8+8], rsp	;FUNC header store old SP
	mov	rsp, r8		;FUNC header new SP
	PRINT_STRING _L1		;print a string
	NEWLINE			;standard Write a NEWLINE
	mov	rax, i		;get identifier
	GET_DEC 8, [rax]		;store value
	mov	rax, 16		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	GET_DEC 8, [rax]		;store value
	mov	rax, 24		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	GET_DEC 8, [rax]		;store value
	PRINT_STRING _L2		;print a string
	NEWLINE			;standard Write a NEWLINE
	mov	rax, i		;get identifier
	mov	rsi, [rax]	;load RSI with the identifier VALUE
	PRINT_DEC 8, rsi		;print a number
	NEWLINE			;standard Write a NEWLINE
	mov	rax, 16		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rsi, [rax]	;load RSI with the identifier VALUE
	PRINT_DEC 8, rsi		;print a number
	NEWLINE			;standard Write a NEWLINE
	mov	rax, 24		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rsi, [rax]	;load RSI with the identifier VALUE
	PRINT_DEC 8, rsi		;print a number
	NEWLINE			;standard Write a NEWLINE
	PRINT_STRING _L3		;print a string
	NEWLINE			;standard Write a NEWLINE
	mov	rax, 24		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rax, [rax]	;ARGUMENT identifier VALUE
	mov	[rsp+56], rax	;store argument into arglist offset
	mov	rax, i		;get identifier
	mov	rax, [rax]	;ARGUMENT identifier VALUE
	mov	[rsp+40], rax	;store argument into arglist offset
	mov	rax, 16		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rax, [rax]	;ARGUMENT identifier VALUE
	mov	[rsp+32], rax	;store argument into arglist offset
	mov	rbx, rsp	;store rsp in a register
	sub	rbx, 48	;subtract function size +1 to get location on stack
	mov	rax, [rsp+40]	;temporarily store argument contents
	mov	[rbx+16], rax	;copy contents of rax into the param memory address
	mov	rax, [rsp+32]	;temporarily store argument contents
	mov	[rbx+24], rax	;copy contents of rax into the param memory address
	call	add	;call function
	mov	[rsp+48], rax	;store argument into arglist offset
	mov	rbx, rsp	;store rsp in a register
	sub	rbx, 48	;subtract function size +1 to get location on stack
	mov	rax, [rsp+56]	;temporarily store argument contents
	mov	[rbx+16], rax	;copy contents of rax into the param memory address
	mov	rax, [rsp+48]	;temporarily store argument contents
	mov	[rbx+24], rax	;copy contents of rax into the param memory address
	call	multiply	;call function
	mov	rsi, rax	;ASSIGN function result
	PRINT_DEC 8, rsi		;print a number
	NEWLINE			;standard Write a NEWLINE
	PRINT_STRING _L4		;print a string
	NEWLINE			;standard Write a NEWLINE
	mov	rax, 24		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rax, [rax]	;ARGUMENT identifier VALUE
	mov	[rsp+72], rax	;store argument into arglist offset
	mov	rax, 16		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rax, [rax]	;ARGUMENT identifier VALUE
	mov	[rsp+64], rax	;store argument into arglist offset
	mov	rbx, rsp	;store rsp in a register
	sub	rbx, 48	;subtract function size +1 to get location on stack
	mov	rax, [rsp+72]	;temporarily store argument contents
	mov	[rbx+16], rax	;copy contents of rax into the param memory address
	mov	rax, [rsp+64]	;temporarily store argument contents
	mov	[rbx+24], rax	;copy contents of rax into the param memory address
	call	subtract	;call function
	mov	[rsp+88], rax	;store argument into arglist offset
	mov	rax, 2		;ARGUMENT number
	mov	[rsp+80], rax	;store argument into arglist offset
	mov	rbx, rsp	;store rsp in a register
	sub	rbx, 48	;subtract function size +1 to get location on stack
	mov	rax, [rsp+88]	;temporarily store argument contents
	mov	[rbx+16], rax	;copy contents of rax into the param memory address
	mov	rax, [rsp+80]	;temporarily store argument contents
	mov	[rbx+24], rax	;copy contents of rax into the param memory address
	call	divide	;call function
	mov	rsi, rax	;ASSIGN function result
	PRINT_DEC 8, rsi		;print a number
	NEWLINE			;standard Write a NEWLINE
	mov	rax, i		;get identifier
	mov	rax, [rax]	;left side of expression is an IDENTIFIER
	mov	[rsp+96], rax	;temporarily store left side of expression
	mov	rax, 16		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rbx, [rax]	;right side of expression is an IDENTIFIER VALUE
	mov	rax, [rsp+96]	;ensure RAX still contains the left side evaluation
	cmp	rax, rbx		;not equal comparison
	setne	al		;not equal comparison
	mov	rbx, 1		;set RBX to one to filter RAX
	and	rax, rbx		;filter RAX
	mov	[rsp+96], rax	;store the result in the expression's temporary location
	mov	rax, [rsp+96]	;load RAX with an EXPRESSION

	cmp	rax, 0		;IF compare to false
	je	_L10		;ELSE jump

	PRINT_STRING _L5		;print a string
	NEWLINE			;standard Write a NEWLINE
	jmp	_L11		;skip ELSE jump

_L10:		;ELSE target


_L11:		;End of ELSE

	mov	rax, i		;get identifier
	mov	rax, [rax]	;left side of expression is an IDENTIFIER
	mov	[rsp+104], rax	;temporarily store left side of expression
	mov	rax, 24		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rbx, [rax]	;right side of expression is an IDENTIFIER VALUE
	mov	rax, [rsp+104]	;ensure RAX still contains the left side evaluation
	cmp	rax, rbx		;less or equal to comparison
	setle	al		;less or equal to comparison
	mov	rbx, 1		;set RBX to one to filter RAX
	and	rax, rbx		;filter RAX
	mov	[rsp+104], rax	;store the result in the expression's temporary location
	mov	rax, [rsp+104]	;load RAX with an EXPRESSION

	cmp	rax, 0		;IF compare to false
	je	_L12		;ELSE jump

	mov	rax, i		;get identifier
	mov	rax, [rax]	;left side of expression is an IDENTIFIER
	mov	[rsp+112], rax	;temporarily store left side of expression
	mov	rax, 24		;get identifier offset
	add	rax, rsp		;add the SP to have a direct reference to memory
	mov	rbx, [rax]	;right side of expression is an IDENTIFIER VALUE
	mov	rax, [rsp+112]	;ensure RAX still contains the left side evaluation
	cmp	rax, rbx		;equality comparison
	sete	al		;equality comparison
	mov	rbx, 1		;set RBX to one to filter RAX
	and	rax, rbx		;filter RAX
	mov	[rsp+112], rax	;store the result in the expression's temporary location
	mov	rax, [rsp+112]	;load RAX with an EXPRESSION

	cmp	rax, 0		;IF compare to false
	je	_L14		;ELSE jump

	PRINT_STRING _L6		;print a string
	NEWLINE			;standard Write a NEWLINE
	jmp	_L15		;skip ELSE jump

_L14:		;ELSE target

	PRINT_STRING _L7		;print a string
	NEWLINE			;standard Write a NEWLINE

_L15:		;End of ELSE

	jmp	_L13		;skip ELSE jump

_L12:		;ELSE target

	PRINT_STRING _L8		;print a string
	NEWLINE			;standard Write a NEWLINE

_L13:		;End of ELSE

	PRINT_STRING _L9		;print a string
	NEWLINE			;standard Write a NEWLINE

	mov	rdx, 1		;ASSIGN number
	mov	[rsp+112], rdx	;STORE right side of ASSIGN temporarily
	mov	rax, i		;get identifier
	mov	rdx, [rsp+112]	;FETCH right side of ASSIGN temporarily
	mov	[rax], rdx	;ASSIGN final store

_L16:		;WHILE TOP target

	mov	rax, i		;get identifier
	mov	rax, [rax]	;left side of expression is an IDENTIFIER
	mov	[rsp+120], rax	;temporarily store left side of expression
	mov	rbx, 5		;right side of expression is a VALUE
	mov	rax, [rsp+120]	;ensure RAX still contains the left side evaluation
	cmp	rax, rbx		;less than comparison
	setl	al		;less than comparison
	mov	rbx, 1		;set RBX to one to filter RAX
	and	rax, rbx		;filter RAX
	mov	[rsp+120], rax	;store the result in the expression's temporary location
	mov	rax, [rsp+120]	;load RAX with an expression

	cmp	rax, 0		;WHILE compare to false
	je	_L17		;WHILE branch out


	mov	rax, i		;get identifier
	mov	rdx, [rax]	;ASSIGN identifier VALUE
	mov	[rsp+128], rdx	;STORE right side of ASSIGN temporarily
	mov	rax, i		;get identifier
	mov	rbx, [rax]	;load RBX with the identifier VALUE
	shl	rbx, 3		;ARRAY reference needs WSIZE difference
	mov	rax, x		;get identifier
	add	rax, rbx		;ensure RAX still contains the temporary value
	mov	rdx, [rsp+128]	;FETCH right side of ASSIGN temporarily
	mov	[rax], rdx	;ASSIGN final store
	mov	rax, i		;get identifier
	mov	rbx, [rax]	;load RBX with the identifier VALUE
	shl	rbx, 3		;ARRAY reference needs WSIZE difference
	mov	rax, x		;get identifier
	add	rax, rbx		;ensure RAX still contains the temporary value
	mov	rsi, [rax]	;load RSI with the identifier VALUE
	PRINT_DEC 8, rsi		;print a number
	NEWLINE			;standard Write a NEWLINE

	mov	rax, i		;get identifier
	mov	rax, [rax]	;left side of expression is an IDENTIFIER
	mov	[rsp+136], rax	;temporarily store left side of expression
	mov	rbx, 1		;right side of expression is a VALUE
	mov	rax, [rsp+136]	;ensure RAX still contains the left side evaluation
	add	rax, rbx		;evaluate addition expression
	mov	[rsp+136], rax	;store the result in the expression's temporary location
	mov	rdx, [rsp+136]	;ASSIGN to an expression
	mov	[rsp+144], rdx	;STORE right side of ASSIGN temporarily
	mov	rax, i		;get identifier
	mov	rdx, [rsp+144]	;FETCH right side of ASSIGN temporarily
	mov	[rax], rdx	;ASSIGN final store
	jmp	_L16		;WHILE jump back

_L17:		;End of WHILE

	mov	rbx, rsp	;store rsp in a register
	sub	rbx, 24	;subtract function size +1 to get location on stack
	call	f	;call function
	mov	rdx, rax	;ASSIGN function result
	mov	[rsp+128], rdx	;STORE right side of ASSIGN temporarily

	mov	rbp, [rsp]	;FUNC end restore old BP
	mov	rsp, [rsp+8]	;FUNC end restore old SP
	mov	rsp, rbp		;stack and BP need to be same on exit for main
	ret
