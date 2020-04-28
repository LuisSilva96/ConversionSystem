#include "Metric.h"

Metric::Metric() : Conversion(0) {
	//empty
}

Metric::Metric(int v) : Conversion(v) {
	//empty
}

Metric::Metric(double v) : Conversion(v) {
	//empty
}

// MASS
double Metric::ounceToMilligrams() {
	return value * 28350;
}

double Metric::ounceToGrams() {
	return value * 28.35;
}

double Metric::poundsToKilograms() {
	return value * 0.454;
}

//LENGTH
double Metric::inchToMillimeters() {
	return value * 25.40;
}

double Metric::inchToCentimeters() {
	return value * 2.54;
}

double Metric::inchToMeters() {
	return value * 0.0254;
}

double Metric::feetToMeters() {
	return value * 0.30;
}

double Metric::yardsToMeters() {
	return value * 0.91;
}

double Metric::yardsToKilometers() {
	return value * 0.00091;
}

double Metric::milesToKilometers() {
	return value * 1.61;
}

