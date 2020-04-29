/**
  * @file fraction.cpp
  * @version 1.0
  * @date 04/28/2020
  * @author Frederick Vitug
  * @author Mohammed Mazous
  * @author Robert Hartnett
  * @author Luis Silva
  * @title Fraction Class
  * @brief Fraction class definition for operations over decimal numbers and fractions
  */

#include "Fraction.h"

/**
  * @brief default Constructor, Fraction Class
  * @param none
  * @return none
  */
Fraction::Fraction() {  
	setNumerator(0);
	setDenominator(1);
}


/**
  * @brief integer constructor, Fraction Class
  * @param integer number
  * @return none
  */
Fraction::Fraction(int number) {   
	setNumerator(number);
	setDenominator(1);
} 


/**
  * @brief double constructor, Fraction Class
  * @param double number
  * @return none
  */
Fraction::Fraction(double numerator_) { 
	setNumerator(numerator_);
	setDenominator(1);

	simplify();
}


/**
  * @brief double, double constructor, Fraction Class
  * @param double nomerator, double denominator of the fraction
  * @return none
  */
Fraction::Fraction(double numerator_, double denominator_) { //    Constructor by two Doubles parameters    

	setNumerator(numerator_);
	setDenominator(denominator_);

	simplify();
}


/**
  * @brief Default Constructor Fraction Class
  * @param none
  * @return none
  */
Fraction::Fraction(const Fraction &frac) {  //    Constructor by Copy 
	setNumerator(frac.numerator);
	setDenominator(frac.denominator);
}


/*
  brief: Modifier for attribute numerator in Fraction class 
  param: double numerator
  return: void
  */
void Fraction::setNumerator(double numberNumerator) { 

	numerator = numberNumerator;
}


/*
  brief: Modifier for attribute denominator in Fraction class
  param: double denominator
  return: void
  exception: Fraction::DivisionByZero() { Exception is thrown when the value of the variable is zero. }
  */
void Fraction::setDenominator(double numberDenominator) { 

	if (numberDenominator == 0)
		throw DivisionByZero(); 
	else if (numerator == 0)
		denominator = 1;
	else
		denominator = numberDenominator;
}


/**
  * @brief accesor the current value of numerator
  * @param none
  * @return double numerator
  */
double Fraction::getNumerator() {    
	return numerator;
}


/**
  * @brief accesor to the current value of denominator
  * @param none
  * @return double denominator
  */
double Fraction::getDenominator() { 
	return denominator;
}


/**
  * @brief Overload of plus operator for Fraction class
  * @param constant reference to a Fraction object
  * @return Fraction object
  */
Fraction Fraction::operator+(Fraction const &frac) { 

	Fraction result;

	result.numerator = (numerator * frac.denominator) + (denominator * frac.numerator);
	result.denominator = denominator * frac.denominator;

	result.simplify();

	return result;
}

/**
  * @brief Overload of minus operator for Fraction class
  * @param constant reference to a Fraction object
  * @return Fraction object
  */
Fraction Fraction::operator -(Fraction const &frac) { //    Operator - overload for Fraction class handling

	Fraction result;

	result.numerator = (numerator * frac.denominator) - (denominator * frac.numerator);
	result.denominator = denominator * frac.denominator;

	result.simplify();

	return result;
}


/**
  * @brief Overload of division operator for Fraction class
  * @param constant reference to a Fraction object
  * @return Fraction object
  */
Fraction Fraction::operator /(Fraction const& frac) { //    Operator / overload for Fraction class handling

	Fraction result;

	result.numerator = numerator * frac.denominator;
	result.denominator = denominator * frac.numerator;

	result.simplify();

	return result;
}


/**
  * @brief Overload of multiplication operator for Fraction class
  * @param constant reference to a Fraction object
  * @return Fraction object
  */
Fraction Fraction::operator *(Fraction const& frac) { //    Operator * overload for Fraction class handling

	Fraction result;

	result.numerator = numerator * frac.numerator;
	result.denominator = denominator * frac.denominator;

	result.simplify();

	return result;
}


/*
  brief: function for calculating the great common divisor used inside simplify()
  param: integer numerator, integer denominator
  return: integer great common divisor
  */
int Fraction::gcd(int numerator, int denominator) { // This recursive function determines what is the general comun divisor from two integers.

	if (denominator == 0)
		return numerator;
	return gcd(denominator, numerator % denominator);
}


/*
  brief: This function simplifies the fraction
  param: none
  return: void
  */
void Fraction::simplify() { 

	const int MAX_PRECISION = 100000; // Maximun presicion for simplification.

	double tempNumerator = fabs(getNumerator());

	if ((tempNumerator - int(tempNumerator)) != 0) { // Checking if the numerator is a decimal number, in that case transforms the numerator to a fraction
		setNumerator(numerator * MAX_PRECISION);
		setDenominator(denominator * MAX_PRECISION);
	}

	int divisor = gcd(int(getNumerator()), int(getDenominator())); //Get the divisor

	int simpleNumerator = int(getNumerator());
	int simpleDenominator = int(getDenominator());

	while (divisor != 1) { //Keep going until is no longer more divisible.

		simpleNumerator = simpleNumerator / divisor;
		simpleDenominator = simpleDenominator / divisor;

		divisor = gcd(simpleNumerator, simpleDenominator);
	}

	if (simpleDenominator < 0) { // Redistributing negative sing
		simpleDenominator = simpleDenominator * (-1);
		simpleNumerator = simpleNumerator * (-1);
	}

	setNumerator(double(simpleNumerator));
	setDenominator(double(simpleDenominator));
}


/*
  brief: This function break a string into pieces to represent a fraction
  param: string input from buffer
  return: pair of doubles, numerator and denominator
  exception: Fraction::BadInput() { Exception is thrown when bad input detected. }
  */
std::pair<double, double> Fraction::getNumbersFromString(std::string numbers) { 

	std::size_t delimiter = numbers.find(' '); //  First delimiter to separe string into two pieces for two numbers
	double firstNumber, secondNumber;
	bool badString = false; // This boolean is a flag to determine if the string is not fixed adequately in the right format

	const int LOW_BOUNDARY_ASCII = 46;
	const int HIGH_BOUNDARY_ASCII = 57;
	const int WHITE_SPACE_ASCII = 32;
	const int NEGATIVE_ASCII = 45;

	if (delimiter != std::string::npos) { // If delimiter was not found, then either the user enter a single number or a single fraction

		std::string firstPart = numbers.substr(0, delimiter);  //Get the first number in the string by finding the ' ' whitespace

		std::string secondPart = numbers.substr(delimiter+1, numbers.size() - delimiter); //Get the second number in the string, from whitespace to end of string

		firstNumber = atof(firstPart.c_str()); //  Converting string to double
		
		delimiter = secondPart.find('/'); // Delimiter to divide the second part od the string into two numbers

		if (delimiter == std::string::npos)  // Bad input detected
			badString = true;
		
		std::string numeratorPart = secondPart.substr(0, delimiter);
		std::string denominatorPart = secondPart.substr(delimiter+1, secondPart.size() - delimiter);

		double tempNumber = atof(numeratorPart.c_str());

		secondNumber = atof(denominatorPart.c_str());

		firstNumber = (firstNumber * secondNumber) + tempNumber; // Cross multipliy
	}
	else { //Case where string is only a number or a single fraction

		delimiter = numbers.find('/');

		if (delimiter != std::string::npos) {

			std::string numeratorPart = numbers.substr(0, delimiter);
			std::string denominatorPart = numbers.substr(delimiter + 1, numbers.size() - delimiter);

			firstNumber = atof(numeratorPart.c_str());

			secondNumber = atof(denominatorPart.c_str());

		}
		else { // Case only number

			firstNumber = atof(numbers.c_str());
			secondNumber = 1;
		}

	}

	for (int i = 0; i < numbers.size(); i++) { // This loop checks in the string if the users have entered a character other than numbers or '.' '/' ' '
		if ((numbers[i] < LOW_BOUNDARY_ASCII || numbers[i] > HIGH_BOUNDARY_ASCII) && numbers[i] != WHITE_SPACE_ASCII) {

			if (i == 0 && (numbers[i] == NEGATIVE_ASCII)) //Case if first character is '-'
				continue;
			else
				badString = true;
		}
			
	}

	if (badString)  // If a bad string was detected, an error is thrown
		throw BadInput();

	return std::make_pair(firstNumber,secondNumber);
}


/**
  * @brief Overload of operator >> for Fraction class
  * @param reference to an istream object , reference to a Fraction object
  * @return reference to an istream object 
  */
std::istream& operator >> (std::istream &in, Fraction &frac) { 

	std::string numbersString;
	std::pair<double, double> numbers;

	std::getline(in, numbersString); // Gets a string from the buffer

	numbers = frac.getNumbersFromString(numbersString); // split and fix the string into numbers

	frac.setNumerator(numbers.first);
	frac.setDenominator(numbers.second);

	frac.simplify(); // simplify the fraction

	return in;
}

/**
  * @brief Overload of operator << for Fraction class
  * @param reference to an ostream object , constant reference to a Fraction object
  * @return reference to an ostream object
  */
std::ostream& operator << (std::ostream& os, const Fraction& frac) {

	if (frac.numerator == 1) 
		os << frac.numerator << std::endl;
	else 
		os << int(frac.numerator / frac.denominator) << " " << int(frac.numerator) % int(frac.denominator) << "/" << frac.denominator << std::endl;

	return os;
}

