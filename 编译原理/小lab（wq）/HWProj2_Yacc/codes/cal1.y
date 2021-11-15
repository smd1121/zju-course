%{
#include <stdio.h>
#include <math.h>
int yylex();
void yyerror(char *str){
    fprintf(stderr,"error:%s\n",str);
}
%}
%token PLUS MINUS MUL DIV POW LP RP NUM SUBMIT

%%

query_set	: query
			| query_set query
			;

query		: expr SUBMIT		{printf("=%d\n", $1);}
			;

expr		: expr PLUS term	{$$ = $1 + $3;}
			| expr MINUS term	{$$ = $1 - $3;}
			| term				{$$ = $1;}
			;

term		: term MUL power	{$$ = $1 * $3;}
			| term DIV power	{$$ = $1 / $3;}
			| power				{$$ = $1;}
			;

power		: power POW factor	{$$ = pow($1, $3);}
			| factor			{$$ = $1;}
			;

factor		: LP expr RP		{$$ = $2;}
			| MINUS factor		{$$ = -$2;}
			| NUM				{$$ = $1;}
			;

%%

int main()
{
    yyparse();
}


