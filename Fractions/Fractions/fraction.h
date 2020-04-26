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

	void setNumerator(double);
	void setDenominator(double);

	std::pair<double, double> getNumbersFromString(std::string);
	void simplify();
	int gcd(int, int);

public:

	//Exception class for a division by zero
	class divisionByZero { };

	//Exeption class for bad input
	class badInput { };

	Fraction();
	Fraction(int);
	Fraction(double, double);
	Fraction(const Fraction&);

	double getNumerator();
	double getDenominator();

	Fraction operator + (Fraction const&);
	Fraction operator - (Fraction const&);
	Fraction operator / (Fraction const&);
	Fraction operator * (Fraction const&);

	friend std::istream& operator >> (std::istream&, Fraction&);

	std::string toString();
};

#endif
