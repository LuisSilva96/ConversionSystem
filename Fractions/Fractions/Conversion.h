#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>
#include <cmath>
 
class Conversion {

protected: 
    double value;
	void setValue(double v);
public:

	//Exception class for a negative input
	class NegativeInput { };

    Conversion();
	Conversion(int v);
    Conversion(double v);
    double getValue();
 
};

#endif // !Conversion.H

