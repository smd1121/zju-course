#include "stdafx.h"
#include "myCalculator.h"

// The booter, return the result of calculation or the error message
std::string MyCalculator::calculate(std::string &inp) {
	// initialize
	input = inp;
	lastTokenTy = NOP;
	// clear the stacks
	std::stack<Token>().swap(opStack);
	std::stack<Token>().swap(numStack);

	if (!input.size()) {
		return "[Error] No input string!";
	}

	// main procedure

	// lexical analysis
	std::string tempResult = lexicalAnalysis();
	// if error, return error
	if (tempResult != "") {
		return tempResult;
	}
	while (!opStack.empty()) {
		tempResult = popOp();
		if (tempResult != "") {
			return tempResult;
		}
	}

	// if the num stack has 0 or >=2 items, then there is an error
	if (numStack.size() != 1) {
		return "[Error] Syntax Error";
	}

	// output the result according to its type
	if (numStack.top().ty == INUM)
		return std::to_string(numStack.top().ival);
	else
		return std::to_string(numStack.top().rval);
}

/* trans the input string into token stream, and push them onto
 * stacks at the same time.
 */
std::string MyCalculator::lexicalAnalysis() {
	int i = 0;

	int state = 0, intP = 0;
	double fraP = 0.0, base = 0.1;

	while (i < input.size()) {
		// ignore the blank characters
		if (input[i] == ' ' || input[i] == '\t') {
			i++;
			continue;
		}
		// The end of reading a number
		if (state != 0 && (input[i] < '0' || input[i] > '9') && input[i] != '.') {
			numStack.push(Token());
			if (state == 3) {
				lastTokenTy = numStack.top().ty = RNUM;
				numStack.top().rval = intP + fraP;
			}
			else {
				lastTokenTy = numStack.top().ty = INUM;
				numStack.top().ival = intP;
			}
			state = 0;
		}

		std::string tempResult;
		switch (input[i]) {
		case '+': case '-': case '*': case '/': case '(': case ')':
			// there might be errors to catch when pushing these operators
			tempResult = pushOp(input[i]);
			if (tempResult != "") {
				return tempResult;
			}
			i++;
			break;

		case 'S': case 's':
			// check for sin
			if ((input[i + 1] != 'I' && input[i + 1] != 'i')
				|| (input[i + 2] != 'N' && input[i + 2] != 'n')) {
				return "[Error] Lexical Error";
			}
			pushOp(SIN);
			i += 3;
			break;

		case 'C': case 'c':
			// check for cos
			if ((input[i + 1] != 'O' && input[i + 1] != 'o')
				|| (input[i + 2] != 'S' && input[i + 2] != 's')) {
				return "[Error] Lexical Error";
			}
			pushOp(COS);
			i += 3;
			break;

		case 'P': case 'p':
			// check for PI
			if (input[i + 1] != 'I' && input[i + 1] != 'i') {
				return "[Error] Lexical Error";
			}
			pushOp(PI);
			i += 2;
			break;

		default:
			// reading numbers.
			// state: 
			// 0 - Not Reading a Number
			// 1 - Reading Number w/o Decimal Point
			// 2 - Leading 0
			// 3 - Reading Number w/ Decimal Point
			if ((input[i] >= '0' && input[i] <= '9') || input[i] == '.') {
				switch (state) {
				case 0:
					if (input[i] == '.')
						state = 3, intP = 0, fraP = 0, base = 0.1;
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
						state = 1, intP = intP * 10 + input[i] - '0';
					}
					break;
				case 3:
					if (input[i] == '.')
						return "[Error] Too many decimal points in number.";
					else {
						fraP += base * (input[i] - '0');
						base *= 0.1;
					}
					break;
				} // end of switch(state) 
				i++;
			}
			else {
				return "[Error] Lexical Error";
			}
		} // end of switch(input[i])
	} // end of while(input[i])

	// In case the number is the last token of the input
	if (state != 0) {
		numStack.push(Token());
		if (state == 3) {
			numStack.top().ty = RNUM;
			numStack.top().rval = intP + fraP;
		}
		else {
			numStack.top().ty = INUM;
			numStack.top().ival = intP;
		}
		state = 0;
	}

	return "";
}

/* push one operator onto the stack, before which popping all the operators
 * which have higher or same precedence than / as the pushed operator
 */
std::string MyCalculator::pushOp(char op) {
	if (op == '(') {
		opStack.push(Token());
		lastTokenTy = opStack.top().ty = (Type)LP_;
	}

	else if (op == SIN || op == COS) {
		// if there is something like 2sinPI, it will be transfer to
		// 2 * sinPI by pushing a single MUL before SIN.
		if (lastTokenTy == INUM || lastTokenTy == RNUM || lastTokenTy == RP) {
			opStack.push(Token());
			opStack.top().ty = MUL;
		}
		opStack.push(Token());
		opStack.top().ty = (Type)op;
	}

	// PI will be directly considered as a real number
	else if (op == PI) {
		numStack.push(Token());
		lastTokenTy = numStack.top().ty = RNUM;
		numStack.top().rval = MATH_PI;
	}

	// when calculating * and /, SIN and COS should be operate first
	// e.g. cosPI*2 = (cos PI) * 2 = -2 but not cos(PI*2) = 1.
	else if (op == '*' || op == '/') {
		while (!opStack.empty()
			&& (opStack.top().ty == COS
				|| opStack.top().ty == SIN
				|| opStack.top().ty == MUL
				|| opStack.top().ty == DIV)) 
		{
			// when operating the prior operations, 
			// there may be errors that should be caught
			std::string tempResult = popOp();
			if (tempResult != "") {
				return tempResult;
			}
		}

		opStack.push(Token());
		if (op == '*')	lastTokenTy = opStack.top().ty = MUL;
		else			lastTokenTy = opStack.top().ty = DIV;
	}

	else if (op == '+' || op == '-') {
		while (!opStack.empty()
			&& (opStack.top().ty == COS
				|| opStack.top().ty == SIN
				|| opStack.top().ty == MUL
				|| opStack.top().ty == DIV
				|| opStack.top().ty == PLUS
				|| opStack.top().ty == MINUS))
		{
			std::string tempResult = popOp();
			if (tempResult != "") {
				return tempResult;
			}
		}

		if (op == '+') {
			opStack.push(Token());
			lastTokenTy = opStack.top().ty = PLUS;
		}
		else {
			if (lastTokenTy == NOP || lastTokenTy == LP_) {
				numStack.push(Token());
				lastTokenTy = numStack.top().ty = INUM;
				numStack.top().ival = 0;
			}
			opStack.push(Token());
			lastTokenTy = opStack.top().ty = MINUS;
		}
	}

	// when ')' is met, operations should be done until a '('.
	else if (op == ')') {
		lastTokenTy = RP;
		if (opStack.empty()) {
			return "[Error] Unbalanced parentheses";
		}
		while (opStack.top().ty != LP_) {
			if (opStack.size() == 1) {
				return "[Error] Unbalanced parentheses";
			}
			popOp();
		}
		opStack.pop();
	}

	return "";
}

/* pop one operator from the operator stack,
 * and calculate at the same time
 */
std::string MyCalculator::popOp() {
	// some cases where the numbers in stack is less
	// than the needed operands of operation.
	switch (opStack.top().ty) {
	case SIN: case COS:
		if (numStack.size() < 1) {
			return "[Error] Syntax Error";
		}
		break;
	default:
		if (numStack.size() < 2) {
			return "[Error] Syntax Error";
		}
		break;
	}

	// save the temp value
	double temp = 0.0;

	// for each operator, do the calculation
	Token first, second;
	switch (opStack.top().ty) {
	// we should discuss whether the operation is between integers
	// or involving floating numbers.
	case PLUS:
		first = numStack.top();
		numStack.pop();
		second = numStack.top();

		if (first.ty == INUM && second.ty == INUM)
			second.ival = second.ival + first.ival;
		else {
			temp = second.ty == RNUM ? second.rval
				: second.ival;
			temp += first.ty == RNUM ? first.rval
				: first.ival;
			second.ty = RNUM;
			second.rval = temp;
		}
		numStack.pop();
		numStack.push(second);
		break;
	case MINUS:
		first = numStack.top();
		numStack.pop();
		second = numStack.top();

		if (first.ty == INUM && second.ty == INUM)
			second.ival = second.ival - first.ival;
		else {
			temp = second.ty == RNUM ? second.rval
				: second.ival;
			temp -= first.ty == RNUM ? first.rval
				: first.ival;
			second.ty = RNUM;
			second.rval = temp;
		}
		numStack.pop();
		numStack.push(second);
		break;
	case MUL:
		first = numStack.top();
		numStack.pop();
		second = numStack.top();

		if (first.ty == INUM && second.ty == INUM)
			second.ival = second.ival * first.ival;
		else {
			temp = second.ty == RNUM ? second.rval
				: second.ival;
			temp *= first.ty == RNUM ? first.rval
				: first.ival;
			second.ty = RNUM;
			second.rval = temp;
		}
		numStack.pop();
		numStack.push(second);
		break;
	case DIV:
		first = numStack.top();
		numStack.pop();
		second = numStack.top();

		if ((first.ty == INUM && first.ival == 0)
			|| ((first.ty == RNUM && first.rval < 0.00000001)
				&& (first.ty == RNUM && first.rval > -0.00000001))) {
			return "[Error] Devide by 0";
		}
		if (first.ty == INUM && second.ty == INUM
			&& second.ival % first.ival == 0)
			second.ival = second.ival / first.ival;
		else {
			temp = second.ty == RNUM ? second.rval
				: second.ival;
			temp /= first.ty == RNUM ? first.rval
				: first.ival;
			second.ty = RNUM;
			second.rval = temp;
		}
		numStack.pop();
		numStack.push(second);
		break;
	case SIN:
		temp = numStack.top().ty == RNUM ? numStack.top().rval
			: numStack.top().ival;
		numStack.top().ty = RNUM;
		numStack.top().rval = sin(temp);
		break;
	case COS:
		temp = numStack.top().ty == RNUM ? numStack.top().rval
			: numStack.top().ival;
		numStack.top().ty = RNUM;
		numStack.top().rval = cos(temp);
		break;
	} // end of switch (opStack.top().ty)
	opStack.pop();
	return "";
}