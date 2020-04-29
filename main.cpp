/*
  file main.cpp
  date 04/28/2020
  author Frederick Vitug
  author Mohammed Mazous
  author Robert Hartnett
  author Luis Silva
  title Scaling and Conversion system
  brief implementation of the classes Fraction and Conversion into a Scaling and Conversion system.
 */

#include <iostream>
#include <iomanip>
#include "Fraction.h"
#include "Imperial.h"
#include "Metric.h"

using namespace std;

void displayMenu(); //Displays main manu
void launchOption(int option); // Launch the specific option depending on user selection
void scalingFraction(); // Scales a raction or number entered by the user
void displayConversionMenu(); // Display a menu for the Conversions
void conversion(); // read a number and launch the specific conversion
void metricConverter(int option, double value); // Converts Metric units to Imperial units
void imperialConverter(int option, double value); // Converts Imperial units to Metric units

int main() {

	int option;
	const int LOWER_OPTION = 1;
	const int HIGHER_OPTION = 3;

	do {

		displayMenu();
		cin >> option;

		while (option < LOWER_OPTION || option > HIGHER_OPTION) { //Checking for valid input
			cout << "Option out of range, please try again: ";
			cin >> option;
		}

		launchOption(option);

	} while (option != HIGHER_OPTION);

	return 0;
}

void displayMenu() {

	system("cls"); //Clear screen for Windows

	cout << endl << endl;
	cout << "\t\t\t\t--------SCALING AND CONVERSION SYSTEM--------" << endl;
	cout << endl << endl;

	cout << "\t\t1. Scale a fraction." << endl;
	cout << "\t\t2. Converersion calculator" << endl;
	cout << "\t\t3. Exit." << endl;

	cout << "Please select one option of the above. (1-3): ";
}

void displayConversionMenu() {

	system("cls"); //Clear screen for Windows

	cout << endl << endl;
	cout << "\t\t\t\t--------SCALING AND CONVERSION SYSTEM--------" << endl;
	cout << endl << endl;
	cout << "\t\t\t\t Metric \t  Imperial\n\n"
		<< "\t\t\tMass Units:   \n\n"
		<< "\t\t\t1. Ounce->Milligrams ///  Milligrams->Ounce\n"
		<< "\t\t\t2. Ounce->Grams      ///  Grams->Ounce\n"
		<< "\t\t\t3. Pounds->Kilograms ///  Kilograms->Pounds\n\n"
		<< "\t\t\tLength Units:  \n\n"
		<< "\t\t\t4. Inch->Millimeters ///  Millimeters->Inch\n"
		<< "\t\t\t5. Inch->Centimeters ///  Centimeters->Inch\n"
		<< "\t\t\t6. Inch->Meters      ///  Meters->Inch\n"
		<< "\t\t\t7. Feet->Meters      ///  Meters->Feet\n"
		<< "\t\t\t8. Yards->Meters     ///  Meters->Yards\n"
		<< "\t\t\t9. Yards->Kilometers ///  Kilometers->Yards\n"
		<< "\t\t\t10.Miles->Kilometers ///  Kilometers->Miles\n\n"
		<< "\t\t\t11. Go Back, main menu.\n\n";
	cout << "Please select one option of the above. (1-11): ";

}

void launchOption(int option) {

	switch (option) {
	case 1: scalingFraction();
		break;
	case 2:  conversion();
		break;
	case 3: cout << "Exiting...." << endl;
		break;
	}
}

Fraction readFraction() {

	Fraction frac;
	bool tryAgain = true;

	while (tryAgain) {
		try {
			cin >> frac; // If no exception is thrown either by divisionByZero or badInput then procced.
			tryAgain = false;
		}
		catch (Fraction::DivisionByZero) {
			cout << "Fraction can not be divided by zero, please try again: ";
		}
		catch (Fraction::BadInput) {
			cout << "Input format error, please try again: ";
		}
	}

	return frac;
}



void conversion() {

	const int LOWER_OPTION = 1;
	const int HIGHER_OPTION = 11;

	char conversionType;
	int option;
	double value;
	string results;
	Fraction fraction;
	bool tryAgain = true;

	displayConversionMenu();

	cin >> option;

	while (option < LOWER_OPTION || option > HIGHER_OPTION) {
		cout << "Option out of range, please try again: ";
		cin >> option;
	}

	if (option == HIGHER_OPTION)
		return;

	cout << "Enter \"M\" to convert to Metric or \"I\" to convert to Imperial: ";
	cin >> conversionType;
	conversionType = toupper(conversionType);

	while (conversionType != 'M' && conversionType != 'I') {
		cout << "Convesion must be \"M\" for Metric or \"I\" for imperial, please try again: ";
		cin >> conversionType;
		conversionType = toupper(conversionType);
	}

	cout << endl << "Enter the value to be converted: ";
	getchar();

	while (tryAgain) {
		
		fraction = readFraction(); //Using Fraction << overload operator to read numbers from buffer

		value = fraction.getNumerator() / fraction.getDenominator();

		try {
			Conversion conver(value); // If no exception is thrown by negativeInput then procced.
			tryAgain = false;
		}
		catch (Conversion::NegativeInput) {
			cout << "Negative values are not acepted for conversions, please try again: ";
		}

	}

	cout << endl << "Converted Value: ";
	cout << fixed << setprecision(3); 

	switch (conversionType) {
	case 'M':metricConverter(option, value);
		break;
	case 'I':imperialConverter(option, value);
		break;
	}

	cout << endl << endl;
	system("pause");
}

void metricConverter(int option, double value) {
	Metric metricConverter(value);

	switch (option) {
	case 1: cout << value << " ounce/s = " << metricConverter.ounceToMilligrams() << " milligram/s";
		break;
	case 2: cout << value << " ounce/s = " << metricConverter.ounceToGrams() << " gram/s";
		break;
	case 3: cout << value << " pound/s = " << metricConverter.poundsToKilograms() << " kilogram/s";
		break;
	case 4: cout << value << " inch/es = " << metricConverter.inchToMillimeters() << " millimeter/s";
		break;
	case 5: cout << value << " inch/es = " << metricConverter.inchToCentimeters() << " centimeter/s";
		break;
	case 6: cout << value << " inch/es = " << metricConverter.inchToMeters() << " meter/s";
		break;
	case 7: cout << value << " feet = " << metricConverter.feetToMeters() << " meter/s";
		break;
	case 8: cout << value << " yard/s = " << metricConverter.yardsToMeters() << " meter/s";
		break;
	case 9: cout << value << " yard/s = " << metricConverter.yardsToKilometers() << " kilometer/s";
		break;
	case 10: cout << value << " mile/s = " << metricConverter.milesToKilometers() << " kilometer/s";
		break;
	}
}

void imperialConverter(int option, double value) {
	Imperial imperialConverter(value);

	switch (option) {
	case 1: cout << value << " miligram/s = " << imperialConverter.milligramsToOunce() << " ounce/s";
		break;
	case 2: cout << value << " gram/s = " << imperialConverter.gramsToOunce() << " ounce/s";
		break;
	case 3: cout << value << " kilogram/s = " << imperialConverter.kilogramsToPounds() << " pound/s";
		break;
	case 4: cout << value << " milimiter/s = " << imperialConverter.millimetersToInch() << " inche/s";
		break;
	case 5: cout << value << " centimeter/s = " << imperialConverter.centimetersToInch() << " inche/s";
		break;
	case 6: cout << value << " meter/s = " << imperialConverter.metersToInch() << " inche/s";
		break;
	case 7: cout << value << " meter/s = " << imperialConverter.metersToFeet() << " feet";
		break;
	case 8: cout << value << " meter/s = " << imperialConverter.metersToYard() << " yard/s";
		break;
	case 9: cout << value << " kilometer/s = " << imperialConverter.kilometersToYards() << " yard/s";
		break;
	case 10:cout << value << " kilometer/s = " << imperialConverter.kilometersToMiles() << " mile/s";
		break;
	}
}

void scalingFraction() {
	int option;
	char unit;
	Fraction frac1;
	Fraction frac2;
	Fraction result;
	const int LOWER_OPTION = 1;
	const int HIGHER_OPTION = 5;

	system("cls");

	cout << endl << endl;
	cout << "\t\t\t\t--------SCALING AND CONVERSION SYSTEM--------" << endl;
	cout << endl << endl;

	cout << "Enter a number: ";

	getchar();
	frac1 = readFraction();

	cout << endl << endl;

	cout << "You entered: " << frac1 << endl;
	cout << "How do you want to scale?: " << endl << endl;

	cout << "\t\t1. Add." << endl;
	cout << "\t\t2. Substract." << endl;
	cout << "\t\t3. Divide." << endl;
	cout << "\t\t4. Multiply." << endl;
	cout << "\t\t5. Go Back, main menu." << endl;
	cout << "Please select one option of the above. (1-5): ";
	cin >> option;

	while (option < LOWER_OPTION || option > HIGHER_OPTION) {
		cout << "Option out of range, please try again: ";
		cin >> option;
	}

	if (option == HIGHER_OPTION)
		return;

	cout << endl << endl;

	cout << "Enter a number: ";

	getchar();
	frac2 = readFraction();

	switch (option) {
	case 1: result = frac1 + frac2;
		break;
	case 2: result = frac1 - frac2;
		break;
	case 3: result = frac1 / frac2;
		break;
	case 4: result = frac1 * frac2;
		break;
	}

	cout << "The result is: " << result;
	cout << endl << "Press enter to go back..";
	getchar();
}