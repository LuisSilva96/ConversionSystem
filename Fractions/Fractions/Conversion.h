#ifndef CONVERSION_H
#define CONVERSION_H
#include <string>
 
class Conversion {
protected: 
    double value;
public:
    Conversion();
    Conversion(double v);
    void setValue(double v);
    double getValue();
    std::string convertToFraction(double v);
};

#endif // !Conversion.H

