/**
  * @file fraction.h
  * @version 1.0
  * @date 04/28/2020
  * @author Frederick Vitug
  * @author Mohammed Mazous
  * @author Robert Hartnett
  * @author Luis Silva 
  * @title Fraction Class
  * @brief Fraction class header for operations over decimal numbers and fractions
  */

#pragma once

#ifndef FRACTION_H 
#define FRACTION_H

#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <algorithm>

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

	/**
	  * @brief Exception class for a division by zero
	  */
	class DivisionByZero { };

	/**
	  * @Exeption class for bad input
	  */
	class BadInput { };

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
	friend std::ostream& operator << (std::ostream& os, const Fraction& frac);
};

#endif
