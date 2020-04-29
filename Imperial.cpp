/**
  * @file Imperial.cpp
  * @version 1.0
  * @date 04/28/2020
  * @author Frederick Vitug
  * @author Mohammed Mazous
  * @author Robert Hartnett
  * @author Luis Silva
  * @title Imperial Class
  * @brief Imperial class definition for conversion Imperial - Metric units
  */

#include "Imperial.h"


/**
  * @brief default Constructor, Imperial Class
  * @param none
  * @return none
  */
Imperial::Imperial() : Conversion(0) {
	//empty
}


/**
  * @brief integer Constructor, Metric Class
  * @param integer value
  * @return none
  */
Imperial::Imperial(int value) : Conversion(v) {
	//empty
}


/**
  * @brief double Constructor, Metric Class
  * @param double value
  * @return none
  */
Imperial::Imperial(double value) : Conversion(v) {
	//empty
}


//MASS

/**
  * @brief conversion milligrams to ounces
  * @param none
  * @return double result;
  */
double Imperial::milligramsToOunce() {
	return value * 0.000035;
}


/**
  * @brief conversion grams to ounces
  * @param none
  * @return double result;
  */
double Imperial::gramsToOunce() {
	return value * 0.035;
}


/**
  * @brief conversion kilograms to pounds
  * @param none
  * @return double result;
  */
double Imperial::kilogramsToPounds() {
	return value * 2.2046;
}


// LENGTH

/**
  * @brief conversion millimeters to inches
  * @param none
  * @return double result;
  */
double Imperial::millimetersToInch() {
	return value * 0.039;
}


/**
  * @brief conversion centimeters to inches
  * @param none
  * @return double result;
  */
double Imperial::centimetersToInch() {
	return value * 0.39;
}


/**
  * @brief conversion meters to inches
  * @param none
  * @return double result;
  */
double Imperial::metersToInch() {
	return value * 39.37;
}


/**
  * @brief conversion meters to feet
  * @param none
  * @return double result;
  */
double Imperial::metersToFeet() {
	return value * 3.28;
}


/**
  * @brief conversion meters to yards
  * @param none
  * @return double result;
  */
double Imperial::metersToYard() {
	return value * 1.094;

}


/**
  * @brief conversion kilometers to yards
  * @param none
  * @return double result;
  */
double Imperial::kilometersToYards() {
	return value * 1094;
}


/**
  * @brief conversion kilometers to miles
  * @param none
  * @return double result;
  */
double Imperial::kilometersToMiles() {
	return value * 0.62;
}

