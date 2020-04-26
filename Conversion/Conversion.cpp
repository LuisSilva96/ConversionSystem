#include "Conversion.h"
#include <string>

Conversion::Conversion() {
	value = 0;
}

Conversion::Conversion(double v) {
	value = v;
}

void Conversion::setValue(double v) {
	value = v;
}

double Conversion::getValue() {
	return value;
}

