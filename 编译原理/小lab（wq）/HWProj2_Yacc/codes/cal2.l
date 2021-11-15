%option noyywrap
%{
#define YYSTYPE struct valType
#include <stdio.h>
#include "y.tab.h"

struct valType {
	int isD, ival;
	double dval;
};
%}
FLOATNUM [0-9]*\.[0-9]+
INTNUM	 [0-9]+

%%

"+"			printf("%s", yytext); return PLUS;
"-"			printf("%s", yytext); return MINUS;
"*"			printf("%s", yytext); return MUL;
"/"			printf("%s", yytext); return DIV;
"^"			printf("%s", yytext); return POW;
"("			printf("%s", yytext); return LP;
")"			printf("%s", yytext); return RP;
{INTNUM}	printf("%s", yytext); yylval.isD = 0; sscanf(yytext,"%d",&(yylval.ival)); return INUM;
{FLOATNUM}	printf("%s", yytext); yylval.isD = 1; sscanf(yytext,"%lf",&(yylval.dval)); return DNUM;
\n			return SUBMIT;
.			;

%%

