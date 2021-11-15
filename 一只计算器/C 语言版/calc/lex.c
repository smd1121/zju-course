#include "myIncludes.h"
#include "calc.h"

extern struct Token opStack[MAXLENGTH], numStack[MAXLENGTH];
extern int opStackHead, numStackHead;

enum Type lastTokenTy = -1;

/* trans the input string into token stream, and push them onto
 * stacks at the same time.
 */
void lexicalAnalysis(char *input) {
	if (!input) {
		puts("[Error] No input string!");
		return;
	}
	
	int i = 0;
	
	int state = 0, intP = 0;
	double fraP = 0.0, base = 0.1;
	
	while (input[i]) {
		if (input[i] == ' ' || input[i] == '\t') {
			i++;
			continue;
		}
		// The end of reading a number
		if (state != 0 && (input[i] < '0' || input[i] > '9') && input[i] != '.') {
			if (state == 3) {
				lastTokenTy = numStack[numStackHead].ty = RNUM;
				numStack[numStackHead].rval = intP + fraP;
			}
			else {
				lastTokenTy = numStack[numStackHead].ty = INUM;
				numStack[numStackHead].ival = intP;
			}
			numStackHead++;
			state = 0;
		}
		
		switch (input[i]) {
			case '+': case '-': case '*': case '/': case '(': case ')':
				pushOp(input[i]);
				i++;
				break;
			
			case 'S': case 's':
				if ((input[i + 1] != 'I' && input[i + 1] != 'i')
				 || (input[i + 2] != 'N' && input[i + 2] != 'n')) {
					puts("[Error] Lexical Error");
					return;
				}
				pushOp(SIN);
				i += 3;
				break;
			
			case 'C': case 'c':
				if ((input[i + 1] != 'O' && input[i + 1] != 'o')
				 || (input[i + 2] != 'S' && input[i + 2] != 's')) {
					puts("[Error] Lexical Error");
					return;
				}
				pushOp(COS);
				i += 3;
				break;
			
			case 'P': case 'p':
				if (input[i + 1] != 'I' && input[i + 1] != 'i') {
					puts("[Error] Lexical Error");
					return;
				}
				pushOp(PI);
				i += 2;
				break;
			
			default:
				if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.') {
					switch (state) {
						case 0:
							if (input[i] == '.')
								state = 3, intP = fraP = 0, base = 0.1;
							else if (input[i] == '0')
								state = 2, intP = 0;
							else
								state = 1, intP = input[i] - '0';
							break;
						case 1:
							if (input[i] == '.')
								state = 3, fraP = 0, base = 0.1;
							else
								intP = intP * 10 + input[i] - '0';
							break;
						case 2:
							if (input[i] == '.')
								state = 3, fraP = 0, base = 0.1;
							else {
								puts("[Warning] Leading 0 in numbers.");
								state = 1, intP = intP * 10 + input[i] - '0';
							}
							break;
						case 3:
							if (input[i] == '.')
								puts("[Error] Too many decimal points in number.");
							else {
								fraP += base * (input[i] - '0');
								base *= 0.1; 
							}
							break;
					} // end of switch(state) 
					i++; 
				}
				else {
					puts("[Error] Lexical Error");
					return;
				}
		} // end of switch(input[i])
	} // end of while(input[i])
	
	// In case the number is the last token of the input
	if (state != 0) {
		if (state == 3) {
			numStack[numStackHead].ty = RNUM;
			numStack[numStackHead].rval = intP + fraP;
		}
		else {
			numStack[numStackHead].ty = INUM;
			numStack[numStackHead].ival = intP;
		}
		numStackHead++;
		state = 0;
	}
}


