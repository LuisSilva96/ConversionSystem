#include "fraction.h"

Fraction::Fraction() {
	setNumerator(0);
	setDenominator(1);
}

Fraction::Fraction(int number) {
	setNumerator(number);
	setDenominator(1);
}


Fraction::Fraction(double number) {

	//Here we need to figure it out how to conver the decimal number into a fraction
}

Fraction::Fraction(const Fraction &frac) {
	setNumerator(frac.numerator);
	setDenominator(frac.denominator);
}

void Fraction::setNumerator(double numberNumerator) {
	numerator = numberNumerator;
}

void Fraction::setDenominator(double numberDenominator) {
	denominator = numberDenominator;
}

double Fraction::getNumerator() {
	return numerator;
}

double Fraction::getDenominator() {
	return denominator;
}


Fraction Fraction::operator+(Fraction const &frac) { //This should work once we fix how to conver from decimal to fraction

	Fraction result;

	result.numerator = (numerator * frac.denominator) + (denominator * frac.numerator);
	result.denominator = denominator * frac.denominator;

	return result;
}



