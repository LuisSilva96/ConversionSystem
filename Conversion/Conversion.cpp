#include "Conversion.h"
#include <string>

Conversion::Conversion() {
	value = 0;
}

Conversion::Conversion(double v) {
	
	setValue(v);
}

void Conversion::setValue(double v) {
	if(v<0) v = 0 ;
	value = v;
}

double Conversion::getValue() {
	return value;
}

