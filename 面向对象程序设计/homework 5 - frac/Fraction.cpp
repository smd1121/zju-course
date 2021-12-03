#include "pch.h"

using namespace std;

class Fraction {
private:
	int top, bottom;

	/* greatest common divisor */
	static int Gcd(int a, int b);

protected:
	/* return minimalist fraction top/bottom */
	static const Fraction fracReduction(int top, int bottom);
	void fracReduction();

public:
	void setValue(int top, int bottom);

	/* constructors */
	Fraction() = default;
	Fraction(int top, int bottom){
		this->top = top;
		this->bottom = bottom;
		fracReduction();
	}

	/* copy constructor*/
	Fraction(const Fraction &frac) {
		top = frac.top;
		bottom = frac.bottom;
	}

	/* cast to string and double */
	string toString() const;
	double toDouble() const;

	/* conversion from a finite decimal string */
	static Fraction toFrac(string str);

	/* arithmetic operators */
	friend const Fraction operator+(const Fraction &left, const Fraction &right);
	friend const Fraction operator-(const Fraction &left, const Fraction &right);
	friend const Fraction operator*(const Fraction &left, const Fraction &right);
	friend const Fraction operator/(const Fraction &left, const Fraction &right);

	/* comparison operators */
	friend bool operator<(const Fraction &left, const Fraction &right);
	friend bool operator>(const Fraction &left, const Fraction &right);
	friend bool operator<=(const Fraction &left, const Fraction &right);
	friend bool operator>=(const Fraction &left, const Fraction &right);
	friend bool operator==(const Fraction &left, const Fraction &right);
	friend bool operator!=(const Fraction &left, const Fraction &right);

	/* inserter and extractor for streams */
	friend ostream& operator<<(ostream& os, const Fraction& right);
	friend istream& operator>>(istream& is, Fraction& right);
};

void Fraction::setValue(int top, int bottom) {
	this->top = top;
	this->bottom = bottom;
	fracReduction();
}

int Fraction::Gcd(int a, int b) {
	if (b == 0)	return 1;
	if (a % b == 0)	return b;
	return Gcd(b, a % b);
}

const Fraction Fraction::fracReduction(int top, int bottom) {
	int gcd = Gcd(bottom, top);
	if (bottom / gcd < 0)	gcd = -gcd;
	return Fraction(top / gcd, bottom / gcd);
}

void Fraction::fracReduction() {
	int gcd = Gcd(bottom, top);
	if (bottom / gcd < 0)	bottom = -bottom, top = -top;
	bottom /= gcd, top /= gcd;
}

string Fraction::toString() const {
	string str = to_string(this->top);
	str += "/";
	str += to_string(this->bottom);
	return str;
}

double Fraction::toDouble() const {
	if (this->bottom == 0) {
		cout << "[Error] Divide by 0." << endl;
		return 0;
	}
	return (double)this->top / this->bottom;
}

Fraction Fraction::toFrac(string str) {
	stringstream ss;
	ss << str;
	if (str.find('.') != string::npos) {
		double value;
		ss >> value;
		int DecNum = str.size() - str.find('.') - 1;	/* number of decimal digits */
		int bottom = pow(10, DecNum), top = value * bottom;
		return fracReduction(top, bottom);
	}
	else {
		int top;
		ss >> top;
		return Fraction(top, 1);
	}
}

const Fraction operator+(const Fraction &left, const Fraction &right) {
	return Fraction::fracReduction(left.top * right.bottom + right.top * left.bottom, left.bottom * right.bottom);
}
const Fraction operator-(const Fraction &left, const Fraction &right) {
	return Fraction::fracReduction(left.top * right.bottom - right.top * left.bottom, left.bottom * right.bottom);
}
const Fraction operator*(const Fraction &left, const Fraction &right) {
	return Fraction::fracReduction(left.top * right.top, left.bottom * right.bottom);
}
const Fraction operator/(const Fraction &left, const Fraction &right) {
	return Fraction::fracReduction(left.top * right.bottom, left.bottom * right.top);
}

bool operator<(const Fraction &left, const Fraction &right) {
	return left.toDouble() < right.toDouble();
}
bool operator>(const Fraction &left, const Fraction &right) {
	return left.toDouble() > right.toDouble();
}
bool operator==(const Fraction &left, const Fraction &right) {
	/* Ensure accuracy */
	return left.top * right.bottom == left.bottom * right.top;
}
bool operator!=(const Fraction &left, const Fraction &right) {
	return !(left == right);
}
bool operator<=(const Fraction &left, const Fraction &right) {
	return left == right || left.toDouble() < right.toDouble();
}
bool operator>=(const Fraction &left, const Fraction &right) {
	return left == right || left.toDouble() > right.toDouble();
}

/* inserter and extractor for streams */
ostream& operator<<(ostream& os, const Fraction& right) {
	return os << right.toString();
}
istream& operator>>(istream& is, Fraction& right) {
	char op;
	is >> right.top >> op >> right.bottom;
	right.fracReduction();
	return is;
}