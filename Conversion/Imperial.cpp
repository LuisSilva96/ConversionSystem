#include "Imperial.h"
#include <string>

Imperial::Imperial() {
	value = 0;
}

Imperial::Imperial(double v) {
	value = v;
}

//MASS
double Imperial::milligramsToOunce(double milligrams)
{
	return milligrams * 0.000035;
}

double Imperial::gramsToOunce(double grams)
{
	return grams * 0.035;
}

double Imperial::kilogramsToPounds(double kilograms)
{
	return kilograms * 2.2046;
}

// LENGTH
double Imperial::millimetersToInch(double millimeters)
{
	return millimeters * 0.039;
}

double Imperial::centimetersToInch(double centimeters)
{
	return centimeters * 0.39;
}

double Imperial::metersToInch(double meters) {
	return meters * 39.37;
}

double Imperial::metersToFeet(double meters)
{
	return meters * 3.28;
}

double Imperial::metersToYard(double meters)
{
	return meters * 1.094;

}

double Imperial::kilometersToYards(double kilometers)
{
	return kilometers * 1094;
}

double Imperial::kilomtersToMiles(double kilometers)
{
	return kilometers * 0.62;
}

std::string Imperial::convertToFraction(double val) {
	// after being converted to imperial, must convert to fraction (scaled form)
}