#include "pch.h"
#include "Fraction.h"

using namespace std;

/* test */

int main() {
	/* default ctor 
	 & ctor takes two integers as parameters
	 & copy ctor
	 */
	Fraction a, b(1, 3), c = b, d = Fraction::toFrac("0.526"), e;

	freopen("test.in", "r", stdin);

	/* inserter and extractor for streams */
	cin >> a >> e;
	cout << "a ~ e" << endl;
	cout << a << " " << b << " " << c << " " << d << " " << e << endl << endl;

	/* type cast to double & to string*/
	cout << "(double)b (string)d" << endl;
	cout << b.toDouble() << " " << d.toString() << endl << endl;

	/* arithmetical operators */
	cout << "a+b a-b a*d a/d" << endl;
	cout << a + b << " " << a - b << " " << a * d << " " << a / d << endl << endl;

	/* relational operators : < <= == != >= > */
	cout << "a>b a<b c>=b d<=b c==b a!=b" << endl;
	if (a > b)	cout << "Yes" << " ";	else cout << "No" << " ";
	if (a < b)	cout << "Yes" << " ";	else cout << "No" << " ";
	if (c >= b)	cout << "Yes" << " ";	else cout << "No" << " ";
	if (d <= b)	cout << "Yes" << " ";	else cout << "No" << " ";
	if (c == b)	cout << "Yes" << " ";	else cout << "No" << " ";
	if (a != b)	cout << "Yes" << " ";	else cout << "No" << " ";
	cout << endl << endl;
	
	return 0;
}