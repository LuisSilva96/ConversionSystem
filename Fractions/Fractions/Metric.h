#ifndef METRIC_H
#define METRIC_H

#include "Conversion.h"

class Metric : public Conversion {

public:
	Metric();
	Metric(int v);
	Metric(double v);

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
