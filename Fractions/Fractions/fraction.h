#pragma once

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <utility>
#include <cmath>

class Fraction {

private:
	double whole;
	double decimal;

	void setWhole(double);
	void setDecimal(double);
public:

	Fraction();
	Fraction(double);
	Fraction(const Fraction&);

	double getWhole();
	double getDecimal();
	std::pair<double, double> split(double);

};

#endif
