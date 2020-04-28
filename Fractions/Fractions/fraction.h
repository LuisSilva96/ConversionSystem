#pragma once

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <sstream>

class Fraction {

private:
	double numerator;
	double denominator;

	void setNumerator(double value);
	void setDenominator(double value);

	std::pair<double, double> getNumbersFromString(std::string numbers);
	void simplify();
	int gcd(int num, int denum);

public:

	//Exception class for a division by zero
	class divisionByZero { };

	//Exeption class for bad input
	class badInput { };

	Fraction();
	Fraction(int value);
	Fraction(double value);
	Fraction(double num, double denum);
	Fraction(const Fraction& frac);

	double getNumerator();
	double getDenominator();

	Fraction operator + (Fraction const& frac);
	Fraction operator - (Fraction const& frac);
	Fraction operator / (Fraction const& frac);
	Fraction operator * (Fraction const& frac);

	friend std::istream& operator >> (std::istream& in, Fraction& frac);

	std::string toString();
};

#endif
