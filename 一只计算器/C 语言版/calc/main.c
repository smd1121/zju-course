#include "myIncludes.h"
#include "calc.h"
#include "lex.h"

extern enum Type lastTokenTy;
char inp[MAXLENGTH];

int main() {
	// dead loop
	while (1) {
		// input prompt
		printf("\n > ");
		
		// initialize
		opStackHead = 0, numStackHead = 0, lastTokenTy = -1;
		
		// read & calculate
		gets(inp);
		lexicalAnalysis(inp);
		while (opStackHead) {
			popOp();
		}
		
		// if the num stack has 0 or >=2 items, then there is an error
		if (numStackHead != 1) {
			puts("[Error] Syntax Error");
			continue;
		}
		
		// output the result according to its type
		if (numStack[0].ty == INUM)
			printf(">> %d", numStack[0].ival);
		else
			printf(">> %lf", numStack[0].rval);
	}
	return 0;
}
