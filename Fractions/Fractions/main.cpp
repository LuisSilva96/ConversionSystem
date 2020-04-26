#include <iostream>
#include "fraction.h"

using namespace std;

int main() {

	Fraction frac1;
	Fraction frac2(3,4);

	cout << "enter fraction: ";
	cin >> frac1;

	cout << frac1.getNumerator() << "   " << frac1.getDenominator() << endl;

	//Sum

	Fraction frac3 = frac1 + frac2;

	cout << frac3.getNumerator() << "/" << frac3.getDenominator() << endl;

	//Subtraction

	frac3 = frac1 - frac2;

	cout << frac3.getNumerator() << "/" << frac3.getDenominator() << endl;


	//Division

	frac3 = frac1 / frac2;

	cout << frac3.getNumerator() << "/" << frac3.getDenominator() << endl;

	//Multiplication

	frac3 = frac1 * frac2;

	cout << frac3.getNumerator() << "/" << frac3.getDenominator() << endl;



	cout << "Converting fraction to print out: ";
	cout << frac1.toString() << endl;


		
	return 0;
}