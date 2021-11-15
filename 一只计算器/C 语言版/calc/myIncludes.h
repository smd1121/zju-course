#ifndef MY_INCLUDES_H
#define MY_INCLUDES_H

#define MAXLENGTH 10005
#define MATH_PI 3.14159265358979323846

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* All possible types of tokens. We regard integer and real numbers
 * as 2 different types.
 */
enum Type {PLUS, MINUS, MUL, DIV, LP, RP, SIN, COS, PI, INUM, RNUM};
/*          0      1     2    3   4   5    6    7   8    9     10*/
/* Type: Token
 * When the type is INUM(RNUM), then ival(rval) is used.
 */
struct Token {
	enum Type ty;
	int ival;
	double rval;
};

#endif
