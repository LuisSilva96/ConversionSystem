#include "Metric.h"
#include <string>

Metric::Metric() {
	value = 0;
}

Metric::Metric(double v) {
	value = v;
}

// MASS
double Metric::ounceToMilligrams(double ounce) {
	return ounce * 28350;
}

double Metric::ounceToGrams(double ounce) {
	return ounce * 28.35;
}

double Metric::poundsToKilograms(double pounds) {
	return pounds * 0.454;
}

//LENGTH
double Metric::inchToMillimeters(double inch) {
	return inch * 25.40;
}

double Metric::inchToCentimeters(double inch) {
	return inch * 2.54;
}

double Metric::inchToMeters(double inch) {
	return inch * 0.0254;
}

double Metric::feetToMeters(double feet) {
	return feet * 0.30;
}

double Metric::yardsToMeters(double yards) {
	return yards * 0.91;
}

double Metric::yardsToKilometers(double yards) {
	return yards * 0.00091;
}

double Metric::milesToKilometers(double miles) {
	return miles * 1.61;
}

