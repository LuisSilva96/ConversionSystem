#include <iostream>
#include "fraction.h"

using namespace std;

int main() {

	Fraction frac1;
	Fraction frac2(3.5);

	double number;

	cout << "enter a number: ";
	cin >> number;

	Fraction frac3(number);
	Fraction frac4(frac3);

	cout << frac1.getWhole() << "      " << frac1.getDecimal() << endl;
	cout << frac2.getWhole() << "      " << frac2.getDecimal() << endl;
	cout << frac3.getWhole() << "      " << frac3.getDecimal() << endl;
	cout << frac4.getWhole() << "      " << frac4.getDecimal() << endl;

	return 0;
}