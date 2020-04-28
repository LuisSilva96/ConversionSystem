#include "Conversion.h"

Conversion::Conversion() {
	setValue(0);
}

Conversion::Conversion(int v) {
	setValue(v);
}

Conversion::Conversion(double v) {
	setValue(v);
}

void Conversion::setValue(double v) {

	if (v < 0)
		throw negativeInput();
	else
		value = v;
}

double Conversion::getValue() {
	return value;
}
