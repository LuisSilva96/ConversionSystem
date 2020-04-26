#include "fraction.h"

  

Fraction::Fraction() {  //    Default Constructor  
	setNumerator(0);
	setDenominator(1);
}


Fraction::Fraction(int number) {  //    Constructor by Integer parameter    
	setNumerator(number);
	setDenominator(1);
} 

Fraction::Fraction(double numerator_, double denominator_) { //    Constructor by two Doubles parameters    

	setNumerator(numerator_);
	setDenominator(denominator_);

	simplify();
}

Fraction::Fraction(const Fraction &frac) {  //    Constructor by Copy 
	setNumerator(frac.numerator);
	setDenominator(frac.denominator);
}

void Fraction::setNumerator(double numberNumerator) { //    Sets the value of the member variable numerator 

	numerator = numberNumerator;
}

void Fraction::setDenominator(double numberDenominator) { //    Sets the value of the member variable denominator

	if (numberDenominator == 0)
		throw divisionByZero(); //Exception is thrown when the value of the variable is zero.
	else if (numerator == 0)
		denominator = 1;
	else
		denominator = numberDenominator;
}

double Fraction::getNumerator() { //    Accesor to member variable numerator    
	return numerator;
}

double Fraction::getDenominator() { //    Accesor to member variable denominator    
	return denominator;
}

Fraction Fraction::operator+(Fraction const &frac) { //    Operator + overload for Fraction class handling

	Fraction result;

	result.numerator = (numerator * frac.denominator) + (denominator * frac.numerator);
	result.denominator = denominator * frac.denominator;

	result.simplify();

	return result;
}

Fraction Fraction::operator -(Fraction const &frac) { //    Operator - overload for Fraction class handling

	Fraction result;

	result.numerator = (numerator * frac.denominator) - (denominator * frac.numerator);
	result.denominator = denominator * frac.denominator;

	result.simplify();

	return result;
}

Fraction Fraction::operator /(Fraction const& frac) { //    Operator / overload for Fraction class handling

	Fraction result;

	result.numerator = numerator * frac.denominator;
	result.denominator = denominator * frac.numerator;

	result.simplify();

	return result;
}

Fraction Fraction::operator *(Fraction const& frac) { //    Operator * overload for Fraction class handling

	Fraction result;

	result.numerator = numerator * frac.numerator;
	result.denominator = denominator * frac.denominator;

	result.simplify();

	return result;
}

int Fraction::gcd(int numerator, int denominator) { // This recursive function determines what is the general comun divisor from two integers.

	if (denominator == 0)
		return numerator;
	return gcd(denominator, numerator % denominator);
}


void Fraction::simplify() { //This function call the gcd until the fraction is completly simplfied.

	const int MAX_PRECISION = 100000;

	double tempNumerator = fabs(getNumerator());

	if ((tempNumerator - int(tempNumerator)) != 0) { // Checking if the numerator is a decimal number, in that case transforms the numerator to a fraction
		setNumerator(numerator * MAX_PRECISION);
		setDenominator(denominator * MAX_PRECISION);
	}

	int divisor = gcd(int(getNumerator()), int(getDenominator())); //Get the divisor

	int simpleNumerator = int(getNumerator());
	int simpleDenominator = int(getDenominator());

	while (divisor != 1) {

		simpleNumerator = simpleNumerator / divisor;
		simpleDenominator = simpleDenominator / divisor;

		divisor = gcd(simpleNumerator, simpleDenominator);
	}

	setNumerator(double(simpleNumerator));
	setDenominator(double(simpleDenominator));

}

std::pair<double, double> Fraction::getNumbersFromString(std::string numbers) { //  This function break a string into peaces to represent a fraction

	std::size_t delimiter = numbers.find(' '); //  First delimiter to separe string into two pieces for two numbers
	double firstNumber, secondNumber;
	bool badString = false; // This boolean is a flag to determine if the string is not fixed adequately in the right format

	const int LOW_BOUNDARY_ASCII = 46;
	const int HIGH_BOUNDARY_ASCII = 57;
	const int WHITE_SPACE_ASCII = 32;

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
		if ((numbers[i] < LOW_BOUNDARY_ASCII || numbers[i] > HIGH_BOUNDARY_ASCII) && numbers[i] != WHITE_SPACE_ASCII)
			badString = true;
	}

	if (badString)  // If a bad string was detected, an error is thrown
		throw badInput();

	return std::make_pair(firstNumber,secondNumber);
}

std::istream& operator >> (std::istream &in, Fraction &frac) { // Overload operator >> to read an object Fraction 

	std::string numbersString;
	std::pair<double, double> numbers;

	std::getline(in, numbersString); // Gets a string from the buffer

	numbers = frac.getNumbersFromString(numbersString); // split and fix the string into numbers

	frac.setNumerator(numbers.first);
	frac.setDenominator(numbers.second);

	frac.simplify(); // simplify the fraction

	return in;
}

std::string Fraction::toString() {

	std::string theString;
	std::stringstream stream;

	stream << int(getNumerator() / getDenominator()) << " " << int(getNumerator()) % int(getDenominator()) << "/" << getDenominator() << std::endl;

	theString = stream.str();

	return theString;
}
