#include "fraction.h"

Fraction::Fraction() {
	setWhole(0);
	setDecimal(0);
}

Fraction::Fraction(double number) {

	std::pair<double, double> splittedNumber = split(number);

	setWhole(splittedNumber.first);
	setDecimal(splittedNumber.second);
}

Fraction::Fraction(const Fraction &frac) {
	setWhole(frac.whole);
	setDecimal(frac.decimal);
}

void Fraction::setWhole(double wholeNumber) {
	whole = wholeNumber;
}

void Fraction::setDecimal(double decimalNumber) {
	decimal = decimalNumber;
}

double Fraction::getWhole() {
	return whole;
}

double Fraction::getDecimal() {
	return decimal;
}

std::pair<double, double> Fraction::split(double number) {

	double decimalPart, wholePart;

	decimalPart = std::fmod(number, 1);
	wholePart = number - decimalPart;

	return std::make_pair(wholePart, decimalPart);
}

