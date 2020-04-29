/**
  * @file Conversion.cpp
  * @version 1.0
  * @date 04/28/2020
  * @author Frederick Vitug
  * @author Mohammed Mazous
  * @author Robert Hartnett
  * @author Luis Silva
  * @title Conversion Class
  * @brief Conversion class definition for conversion of units
  */

#include "Conversion.h"


/**
  * @brief default Constructor, Conversion class
  * @param none
  * @return none
  */
Conversion::Conversion() {
	setValue(0);
}


/**
  * @brief integer constructor, Conversion class
  * @param integer value
  * @return none
  */
Conversion::Conversion(int value) {
	setValue(value);
}


/**
  * @brief double constructor, Conversion class
  * @param none
  * @return none
  */
Conversion::Conversion(double value) {
	setValue(value);
}


/**
  * @brief modifier for attribute value, Conversion class
  * @param none
  * @return void
  * @exception NegativeInput() { exception thown if negative input detected for conversion. }
  */
void Conversion::setValue(double val) {

	if (val < 0)
		throw NegativeInput();
	else
		value = val;
}


/*
   brief: modifier for attribute value, Conversion class
   param: none
   return: double
  */
double Conversion::getValue() {
	return value;
}
