/**
  * @file Metric.h
  * @version 1.0
  * @date 04/28/2020
  * @author Frederick Vitug
  * @author Mohammed Mazous
  * @author Robert Hartnett
  * @author Luis Silva
  * @title Metric Class
  * @brief Metric class header for conversion Metric-Imperial units.
  */

#ifndef METRIC_H
#define METRIC_H

#include "Conversion.h"

class Metric : public Conversion {

public:
	Metric();
	Metric(int value);
	Metric(double value);

	// Mass
	double ounceToMilligrams();
	double ounceToGrams();
	double poundsToKilograms();

	// Length
	double inchToMillimeters();
	double inchToCentimeters();
	double inchToMeters();
	double feetToMeters();
	double yardsToMeters();
	double yardsToKilometers();
	double milesToKilometers();

};

#endif // !METRIC_H
