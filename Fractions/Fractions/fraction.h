#pragma once

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <utility>
#include <cmath>
#include <string>

class Fraction {

private:
	double numerator;
	double denominator;

	void setNumerator(double);
	void setDenominator(double);
public:

	Fraction();
	Fraction(int);
	Fraction(double);
	Fraction(const Fraction&);

	double getNumerator();
	double getDenominator();
	std::pair<double, double> split(double);

	Fraction operator + (Fraction const&);
};

#endif
