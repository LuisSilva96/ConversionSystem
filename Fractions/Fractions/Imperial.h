#ifndef IMPERIAL_H
#define IMPERIAL_H

#include "Conversion.h"

class Imperial : public Conversion {

public:
	Imperial();
	Imperial(int value);
	Imperial(double value);

	//MASS
	double milligramsToOunce();
	double gramsToOunce();
	double kilogramsToPounds();

	//LENGTH
	double millimetersToInch();
	double centimetersToInch();
	double metersToInch();
	double metersToFeet();
	double metersToYard();
	double kilometersToYards();
	double kilometersToMiles();
	
};

#endif // !"IMPERIAL_H"
