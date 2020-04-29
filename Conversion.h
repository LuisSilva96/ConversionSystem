/**
  * @file Conversion.h
  * @version 1.0
  * @date 04/28/2020
  * @author Frederick Vitug
  * @author Mohammed Mazous
  * @author Robert Hartnett
  * @author Luis Silva
  * @title Conversion Class
  * @brief Conversion class header for conversion of units
  */

#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>
#include <cmath>
 
class Conversion {

protected: 
    double value;
	void setValue(double val);
public:

	/**
	  * @Exception class for a negative input
	  */
	class NegativeInput { };

    Conversion();
	Conversion(int value);
    Conversion(double value);
    double getValue();
 
};

#endif // !Conversion.H

