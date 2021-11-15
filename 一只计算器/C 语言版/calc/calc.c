#include "myIncludes.h"
#include "lex.h"

// Stack for operators and numbers 
struct Token opStack[MAXLENGTH], numStack[MAXLENGTH];
int opStackHead = 0, numStackHead = 0;

/* pop one operator from the operator stack, 
 * and calculate at the same time
 */
void popOp() {
	// some cases where the numbers in stack is less
	// than the needed operands of operation.
	switch (opStack[opStackHead - 1].ty) {
		case SIN: case COS:
			if (numStackHead < 1) {
				puts("[Error] Syntax Error");
				exit(0);
			}
			break;
		default:
			if (numStackHead < 2) {
				puts("[Error] Syntax Error");
				exit(0);
			}
			break;			
	}
	
	// save the temp value
	double temp = 0.0;
	
	// for each operator, do the calculation
	switch (opStack[opStackHead - 1].ty) {
		case PLUS:
			if (numStack[numStackHead - 1].ty == INUM && numStack[numStackHead - 2].ty == INUM)
				numStack[numStackHead - 2].ival = numStack[numStackHead - 2].ival + numStack[numStackHead - 1].ival;
			else {
				temp =  numStack[numStackHead - 2].ty == RNUM ? numStack[numStackHead - 2].rval 
															  : numStack[numStackHead - 2].ival;
				temp += numStack[numStackHead - 1].ty == RNUM ? numStack[numStackHead - 1].rval 
															  : numStack[numStackHead - 1].ival;
				numStack[numStackHead - 2].ty = RNUM;
				numStack[numStackHead - 2].rval = temp;
			}
			numStackHead--;
			break;
		case MINUS:
			if (numStack[numStackHead - 1].ty == INUM && numStack[numStackHead - 2].ty == INUM)
				numStack[numStackHead - 2].ival = numStack[numStackHead - 2].ival - numStack[numStackHead - 1].ival;
			else {
				temp =  numStack[numStackHead - 2].ty == RNUM ? numStack[numStackHead - 2].rval 
															  : numStack[numStackHead - 2].ival;
				temp -= numStack[numStackHead - 1].ty == RNUM ? numStack[numStackHead - 1].rval 
															  : numStack[numStackHead - 1].ival;
				numStack[numStackHead - 2].ty = RNUM;
				numStack[numStackHead - 2].rval = temp;
			}
			numStackHead--;
			break;
		case MUL:
			if (numStack[numStackHead - 1].ty == INUM && numStack[numStackHead - 2].ty == INUM)
				numStack[numStackHead - 2].ival = numStack[numStackHead - 2].ival * numStack[numStackHead - 1].ival;
			else {
				temp =  numStack[numStackHead - 2].ty == RNUM ? numStack[numStackHead - 2].rval 
															  : numStack[numStackHead - 2].ival;
				temp *= numStack[numStackHead - 1].ty == RNUM ? numStack[numStackHead - 1].rval 
															  : numStack[numStackHead - 1].ival;
				numStack[numStackHead - 2].ty = RNUM;
				numStack[numStackHead - 2].rval = temp;
			}
			numStackHead--;
			break;
		case DIV:
			if ( (numStack[numStackHead - 1].ty == INUM && numStack[numStackHead - 1].ival == 0) 
			  || (  (numStack[numStackHead - 1].ty == RNUM && numStack[numStackHead - 1].rval <  0.00000001)
			     && (numStack[numStackHead - 1].ty == RNUM && numStack[numStackHead - 1].rval > -0.00000001) ) ){
				puts("[Error] Devide by 0");
				exit(0);									   	
			}
			if (numStack[numStackHead - 1].ty == INUM && numStack[numStackHead - 2].ty == INUM
			 && numStack[numStackHead - 2].ival % numStack[numStackHead - 1].ival == 0)
				numStack[numStackHead - 2].ival = numStack[numStackHead - 2].ival / numStack[numStackHead - 1].ival;
			else {
				temp =  numStack[numStackHead - 2].ty == RNUM ? numStack[numStackHead - 2].rval 
															  : numStack[numStackHead - 2].ival;
				temp /= numStack[numStackHead - 1].ty == RNUM ? numStack[numStackHead - 1].rval 
															  : numStack[numStackHead - 1].ival;
				numStack[numStackHead - 2].ty = RNUM;
				numStack[numStackHead - 2].rval = temp;
			}
			numStackHead--;
			break;
		case SIN:
			temp = numStack[numStackHead - 1].ty == RNUM ? numStack[numStackHead - 1].rval 
														 : numStack[numStackHead - 1].ival;
			numStack[numStackHead - 1].ty = RNUM;
			numStack[numStackHead - 1].rval = sin(temp);
			break;
		case COS:
			temp = numStack[numStackHead - 1].ty == RNUM ? numStack[numStackHead - 1].rval 
														 : numStack[numStackHead - 1].ival;
			numStack[numStackHead - 1].ty = RNUM;
			numStack[numStackHead - 1].rval = cos(temp);
			break;
	} // end of switch (opStack[opStackHead - 1].ty)
	opStackHead--;
}

/* push one operator onto the stack, before which popping all the operators 
 * which have higher or same precedence than / as the pushed operator
 */
void pushOp(char op) {
	if (op == '(') 
		lastTokenTy = opStack[opStackHead++].ty = LP;
		
	else if (op == SIN || op == COS) {
		while (opStackHead
			 && (opStack[opStackHead - 1].ty == COS 
		     ||  opStack[opStackHead - 1].ty == SIN)) popOp();
		if (lastTokenTy == INUM || lastTokenTy == RNUM || lastTokenTy == RP) {
			opStack[opStackHead++].ty = MUL;
		}
		opStack[opStackHead++].ty = op;
	}
	
	// PI will be directly considered as a real number
	else if (op == PI) {
		lastTokenTy = numStack[numStackHead].ty = RNUM;
		numStack[numStackHead++].rval = MATH_PI;
	}
	
	else if (op == '*' || op == '/') {
		while (opStackHead
			&& (opStack[opStackHead - 1].ty == COS 
		    ||  opStack[opStackHead - 1].ty == SIN
			||  opStack[opStackHead - 1].ty == MUL
			||  opStack[opStackHead - 1].ty == DIV)) popOp();
		
		if (op == '*')	lastTokenTy = opStack[opStackHead++].ty = MUL;
		else			lastTokenTy = opStack[opStackHead++].ty = DIV;
	}
	
	else if (op == '+' || op == '-') {
		while (opStackHead
			&& (opStack[opStackHead - 1].ty == COS 
		    ||  opStack[opStackHead - 1].ty == SIN
			||  opStack[opStackHead - 1].ty == MUL
			||  opStack[opStackHead - 1].ty == DIV
			||  opStack[opStackHead - 1].ty == PLUS
			||  opStack[opStackHead - 1].ty == MINUS)) popOp();
		
		if (op == '+')	lastTokenTy = opStack[opStackHead++].ty = PLUS;
		else {
			if (lastTokenTy == -1 || lastTokenTy == LP) {
				lastTokenTy = numStack[numStackHead].ty = INUM;
				numStack[numStackHead++].ival = 0;
			}
			lastTokenTy = opStack[opStackHead++].ty = MINUS;	
		}
	}
	
	else if (op == ')'){
		lastTokenTy = opStack[opStackHead].ty = RP;
		while (opStack[opStackHead - 1].ty != LP) {
			if (opStackHead == 1) {
				puts("[Error] Unbalanced parentheses");
				exit(0);
			}
			popOp();
		}
		opStackHead--;
	}
}

