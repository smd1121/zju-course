#pragma once

#include"pch.h"

class Fraction {
private:
	int top, bottom;

	/* greatest common divisor */
	static int Gcd(int a, int b);

protected:
	/* return minimalist fraction top/bottom */
	static const Fraction fracReduction(int top, int bottom);
	void reduction();

public:
	void setValue(int top, int bottom);

	/* constructors */
	Fraction() = default;
	Fraction(int top, int bottom) : top(top), bottom(bottom) {}

	/* copy constructor*/
	Fraction(const Fraction &frac) {
		top = frac.top;
		bottom = frac.bottom;
	}

	/* cast to string and double */
	std::string toString() const;
	double toDouble() const;

	/* conversion from a finite decimal string */
	static Fraction toFrac(std::string str);

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
	friend std::ostream& operator<<(std::ostream& os, const Fraction& right);
	friend std::istream& operator>>(std::istream& is, Fraction& right);
};