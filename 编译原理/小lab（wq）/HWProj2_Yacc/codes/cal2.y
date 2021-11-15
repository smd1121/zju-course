%{
#include <stdio.h>
#include <math.h>
int yylex();
void yyerror(char *str){
    fprintf(stderr,"error:%s\n",str);
}

struct valType {
	int isD, ival;
	double dval;
};

#define YYSTYPE struct valType

%}
%token PLUS MINUS MUL DIV POW LP RP INUM DNUM SUBMIT

%%

query_set	: query
			| query_set query
			;

query		: expr SUBMIT		{
									if ($1.isD)	printf("=%lf\n", $1.dval);
									else		printf("=%d\n", $1.ival);
								}
			;

expr		: expr PLUS term	{
									if ($1.isD || $3.isD) {
										if (!$1.isD)	$1.dval = (double) $1.ival;
										if (!$3.isD)	$3.dval = (double) $3.ival;
										$$.isD = 1;
										$$.dval = $1.dval + $3.dval;
									}
									else {
										$$.isD = 0;
										$$.ival = $1.ival + $3.ival;
									}
								}
			| expr MINUS term	{
									if ($1.isD || $3.isD) {
										if (!$1.isD)	$1.dval = (double) $1.ival;
										if (!$3.isD)	$3.dval = (double) $3.ival;
										$$.isD = 1;
										$$.dval = $1.dval - $3.dval;
									}
									else {
										$$.isD = 0;
										$$.ival = $1.ival - $3.ival;
									}
								}
			| term				{
									if ($1.isD)		$$.isD = 1, $$.dval = $1.dval;
									else			$$.isD = 0, $$.ival = $1.ival;
								}
			;

term		: term MUL power	{
									if ($1.isD || $3.isD) {
										if (!$1.isD)	$1.dval = (double) $1.ival;
										if (!$3.isD)	$3.dval = (double) $3.ival;
										$$.isD = 1;
										$$.dval = $1.dval * $3.dval;
									}
									else {
										$$.isD = 0;
										$$.ival = $1.ival * $3.ival;
									}
								}
			| term DIV power	{
									if ($1.isD || $3.isD) {
										if (!$1.isD)	$1.dval = (double) $1.ival;
										if (!$3.isD)	$3.dval = (double) $3.ival;
										$$.isD = 1;
										$$.dval = $1.dval / $3.dval;
									}
									else {
										$$.isD = 0;
										$$.ival = $1.ival / $3.ival;
									}
								}
			| power				{
									if ($1.isD)		$$.isD = 1, $$.dval = $1.dval;
									else			$$.isD = 0, $$.ival = $1.ival;
								}
			;

power		: power POW factor	{
									if ($1.isD || $3.isD) {
										if (!$1.isD)	$1.dval = (double) $1.ival;
										if (!$3.isD)	$3.dval = (double) $3.ival;
										$$.isD = 1;
										$$.dval = pow($1.dval, $3.dval);
									}
									else {
										$$.isD = 0;
										$$.ival = pow($1.ival, $3.ival);
									}
								}
			| factor			{
									if ($1.isD)		$$.isD = 1, $$.dval = $1.dval;
									else			$$.isD = 0, $$.ival = $1.ival;
								}
			;

factor		: LP expr RP		{
									if ($2.isD)		$$.isD = 1, $$.dval = $2.dval;
									else			$$.isD = 0, $$.ival = $2.ival;
								}
			| MINUS factor		{
									if ($1.isD)		$$.isD = 1, $$.dval = -$1.dval;
									else			$$.isD = 0, $$.ival = -$1.ival;
								}
			| INUM				{ $$.isD = 0; $$.ival = $1.ival; }
			| DNUM				{ $$.isD = 1; $$.dval = $1.dval; }
			;

%%

int main()
{
    yyparse();
}





