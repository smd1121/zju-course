#ifndef CALC_H
#define CALC_H

// Stack for operators and numbers 
extern struct Token opStack[MAXLENGTH], numStack[MAXLENGTH];
extern int opStackHead, numStackHead;

void popOp();
void pushOp(char op);

#endif
