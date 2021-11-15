%option noyywrap
%{
#include <stdio.h>
#include "y.tab.h"
%}
NUM	 [0-9]+

%%

"+"			printf("%s", yytext); return PLUS;
"-"			printf("%s", yytext); return MINUS;
"*"			printf("%s", yytext); return MUL;
"/"			printf("%s", yytext); return DIV;
"^"			printf("%s", yytext); return POW;
"("			printf("%s", yytext); return LP;
")"			printf("%s", yytext); return RP;
{NUM}		printf("%s", yytext); sscanf(yytext,"%d",&yylval); return NUM;
\n			return SUBMIT;
.			;

%%

