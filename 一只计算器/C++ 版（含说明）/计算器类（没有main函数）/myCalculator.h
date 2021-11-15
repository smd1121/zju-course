#pragma once

constexpr double MATH_PI = 3.1415926;

/* All possible types of tokens. We regard integer and real numbers
 * as 2 different types.
 */
enum Type { PLUS, MINUS, MUL, DIV, LP_, RP, SIN, COS, PI, INUM, RNUM, NOP = -1 };
/*           0      1     2    3   4   5    6    7   8    9     10		-1*/

/* class: Token
 * When the type is INUM(RNUM), then ival(rval) is used.
 */
class Token {
public:
	enum Type ty;
	int ival;
	double rval;
};

/* class: MyCalculator
 * Proceed the calculation.
 * The meanings of the members are trivial.
 */
class MyCalculator {
private:
	std::stack<Token> opStack, numStack;
	std::string input;
	enum Type lastTokenTy;

	/* trans the input string into token stream, and push them onto
	 * stacks at the same time.
	 */
	std::string lexicalAnalysis();

	/* push one operator onto the stack, before which popping all the operators
	 * which have higher or same precedence than / as the pushed operator
	 */
	std::string pushOp(char op);

	/* pop one operator from the operator stack,
	 * and calculate at the same time
	 */
	std::string popOp();
	
public:
	MyCalculator() = default;
	// The booter, return the result of calculation or the error message
	std::string calculate(std::string &input);
};
