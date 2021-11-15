#include "myHeader.h"

FILE *fp;

void initDebug() 	{ fp = fopen("debug.log", "w"); }
void dbgI(int x) 	{ fprintf(fp, "%d", x); }
void dbgC(char x)	{ fprintf(fp, "%c", x); }
void dbgD(double x)	{ fprintf(fp, "%lf", x); }
void dbgS(char *x)	{ fprintf(fp, "%s", x); }
