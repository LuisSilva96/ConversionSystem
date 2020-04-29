/**
  * @file Metric.cpp
  * @version 1.0
  * @date 04/28/2020
  * @author Frederick Vitug
  * @author Mohammed Mazous
  * @author Robert Hartnett
  * @author Luis Silva
  * @title Metric Class
  * @brief Metric class definition for conversion Metric - Imperial units
  */

#include "Metric.h"


/**
  * @brief default Constructor, Metric Class
  * @param none
  * @return none
  */
Metric::Metric() : Conversion(0) {
	//empty
}


/**
  * @brief integer Constructor, Metric Class
  * @param integer value
  * @return none
  */
Metric::Metric(int value) : Conversion(v) {
	//empty
}


/**
  * @brief double Constructor, Metric Class
  * @param double value
  * @return none
  */
Metric::Metric(double value) : Conversion(v) {
	//empty
}

// MASS

/**
  * @brief conversion ounces to milligrams
  * @param none
  * @return double result;
  */
double Metric::ounceToMilligrams() {
	return value * 28350;
}


/**
  * @brief conversion ounces to grams
  * @param none
  * @return double result;
  */
double Metric::ounceToGrams() {
	return value * 28.35;
}


/**
  * @brief conversion pounds to kilograms
  * @param none
  * @return double result;
  */
double Metric::poundsToKilograms() {
	return value * 0.454;
}


//LENGTH

/**
  * @brief conversion inches to millimeters
  * @param none
  * @return double result;
  */
double Metric::inchToMillimeters() {
	return value * 25.40;
}


/**
  * @brief conversion inches to centimeters
  * @param none
  * @return double result;
  */
double Metric::inchToCentimeters() {
	return value * 2.54;
}


/**
  * @brief conversion inches to meters
  * @param none
  * @return double result;
  */
double Metric::inchToMeters() {
	return value * 0.0254;
}


/**
  * @brief conversion feet to meters
  * @param none
  * @return double result;
  */
double Metric::feetToMeters() {
	return value * 0.30;
}


/**
  * @brief conversion yards to meters
  * @param none
  * @return double result;
  */
double Metric::yardsToMeters() {
	return value * 0.91;
}


/**
  * @brief conversion yards to kilometers
  * @param none
  * @return double result;
  */
double Metric::yardsToKilometers() {
	return value * 0.00091;
}


/**
  * @brief conversion miles to kilometers
  * @param none
  * @return double result;
  */
double Metric::milesToKilometers() {
	return value * 1.61;
}

