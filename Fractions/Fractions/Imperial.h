#ifndef IMPERIAL_H
#define IMPERIAL_H
#include "Conversion.h"
#include <string>

class Imperial : public Conversion {
public:
	Imperial();
	Imperial(double val);
	//MASS
	double milligramsToOunce(double milligrams);
	double gramsToOunce(double grams);
	double kilogramsToPounds(double kilograms);
	//LENGTH
	double millimetersToInch(double millimeters);
	double centimetersToInch(double centimeters);
	double metersToInch(double meters);
	double metersToFeet(double meters);
	double metersToYard(double meters);
	double kilometersToYards(double kilometers);
	double kilometersToMiles(double kilomters);
	
};

#endif // !"IMPERIAL_H"
