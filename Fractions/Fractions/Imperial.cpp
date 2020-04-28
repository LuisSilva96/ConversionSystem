#include "Imperial.h"
#include<iostream>

Imperial::Imperial() : Conversion(0) {
	//empty
}

Imperial::Imperial(int v) : Conversion(v) {
	//empty
}

Imperial::Imperial(double v) : Conversion(v) {
	//empty
}

//MASS
double Imperial::milligramsToOunce() {
	return value * 0.000035;
}

double Imperial::gramsToOunce() {
	return value * 0.035;
}

double Imperial::kilogramsToPounds() {
	return value * 2.2046;
}

// LENGTH
double Imperial::millimetersToInch() {
	return value * 0.039;
}

double Imperial::centimetersToInch() {
	return value * 0.39;
}

double Imperial::metersToInch() {
	return value * 39.37;
}

double Imperial::metersToFeet() {
	return value * 3.28;
}

double Imperial::metersToYard() {
	return value * 1.094;

}

double Imperial::kilometersToYards() {
	return value * 1094;
}

double Imperial::kilometersToMiles() {
	return value * 0.62;
}

