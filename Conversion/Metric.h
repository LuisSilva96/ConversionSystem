#ifndef METRIC_H
#define METRIC_H
#include "Conversion.h"
#include <string>

class Metric : public Conversion {
public:
	Metric();
	Metric(double v);
	// Mass
	double ounceToMilligrams(double ounce);
	double ounceToGrams(double ounce);
	double poundsToKilograms(double pounds);
	// Length
	double inchToMillimeters(double inch);
	double inchToCentimeters(double inch);
	double inchToMeters(double inch);
	double feetToMeters(double feet);
	double yardsToMeters(double yards);
	double yardsToKilometers(double yards);
	double milesToKilometers(double miles);
	virtual std::string convertToFraction(double value);
};

#endif // !METRIC_H
