/**
  * @file Imperial.h
  * @version 1.0
  * @date 04/28/2020
  * @author Frederick Vitug
  * @author Mohammed Mazous
  * @author Robert Hartnett
  * @author Luis Silva
  * @title Imperial Class
  * @brief Imperial class header for conversion Imperial - Metric units
  */

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
