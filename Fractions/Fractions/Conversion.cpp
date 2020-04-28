#include "Conversion.h"
#include <string>
#include <cmath>

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

long findGCD(long a, long b) {

    if (a == 0)
        return b;
    else if (b == 0)
        return a;

    if (a < b)
        return findGCD(a, b % a);
    else
        return findGCD(b, a % b);

}

std::string Conversion::convertToFraction(double input) {
    double integral = std::floor(input);
    double frac = input - integral;

    const long PRECISION = 1000000000;

    long gcd = findGCD(round(frac * PRECISION), PRECISION);

    long denominator = PRECISION / gcd;
    long numerator = round(frac * PRECISION) / gcd;

    return std::to_string(integral) + std::to_string(numerator) + "/" + std::to_string(denominator);
}


