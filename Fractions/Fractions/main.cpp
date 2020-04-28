#include <iostream>
#include "fraction.h"
#include "Imperial.h"
#include "Metric.h"
using namespace std;

void displayMenu();
void launchOption(int);
void scalingFraction();
void displayConversionMenu();
void conversion();
void metricConverter(int option, double value);
void imperialConverter(int option, double value);

int main() {

	int option;
	const int LOWER_OPTION = 1;
	const int HIGHER_OPTION = 3;

	do {

		displayMenu();
		cin >> option;

		while (option < LOWER_OPTION || option > HIGHER_OPTION) {
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

	cout << "\n\t\t\t\t--------CONVERSION MENU--------\n"
		<< "\t\t\t\t Metric \t  Imperial\n"
		<< "\t\t\tMASS   \n"
		<< "\t\t\t1. Ounce->Milligrams \t 1. Milligrams->Ounce\n"
		<< "\t\t\t2. Ounce->Grams      \t 2. Grams->Ounce\n"
		<< "\t\t\t3. Pounds->Kilograms \t 3. Kilograms->Pounds\n"
		<< "\t\t\tLENGTH  \n"
		<< "\t\t\t4. Inch->Millimeters \t 4. Millimeters->Inch\n"
		<< "\t\t\t5. Inch->Centimeters \t 5. Centimeters->Inch\n"
		<< "\t\t\t6. Inch->Meters      \t 6. Meters->Inch\n"
		<< "\t\t\t7. Feet->Meters      \t 7. Meters->Feet\n"
		<< "\t\t\t8. Yards->Meters     \t 8. Meters->Yards\n"
		<< "\t\t\t9. Yards->Kilometers \t 9. Kilometers->Yards\n"
		<< "\t\t\t10.Miles->Kilometers \t 10.Kilometers->Miles\n\n";

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

Fraction fractionExceptionHandler() {

	Fraction frac;
	bool tryAgain = true;

	while (tryAgain) {
		try {
			cin >> frac; // If no exception is thrown either by divisionByZero or badInput then procced.
			tryAgain = false;
		}
		catch (Fraction::divisionByZero) {
			cout << "Fraction can not be divided by zero, please try again." << endl;
		}
		catch (Fraction::badInput) {
			cout << "Input format error, please try again." << endl;
		}
	}

	return frac;
}

void conversion() {
	char choice;
	int option;
	double numerator;
	double denominator;
	double value;
	string results;
	Fraction fraction;

	displayConversionMenu();

	cout << "Enter the value to be converted: ";
	getchar();
	fraction = fractionExceptionHandler();
	numerator = fraction.getNumerator();
	denominator = fraction.getDenominator();
	value = numerator / denominator;

	cout << "\"M\" -Metric or \"I\" -Imperial: ";
	cin >> choice;
	toupper(choice);

	cout << "Choose your option:";
	cin >> option;

	cout << "Converted Value: ";
	switch (choice) {
	case 'M':metricConverter(option, value);
		break;
	case 'I':imperialConverter(option, value);
		break;
	}

	cout << endl << endl;
	system("pause");
}

void metricConverter(int option, double value) {
	Metric metricConverter;

	switch (option) {
	case 1: cout << metricConverter.ounceToMilligrams(value) << " milligrams";
		break;
	case 2: cout << metricConverter.ounceToGrams(value) << " grams";
		break;
	case 3: cout << metricConverter.poundsToKilograms(value) << " kilograms";
		break;
	case 4: cout << metricConverter.inchToMillimeters(value) << " millimeters";
		break;
	case 5: cout << metricConverter.inchToCentimeters(value) << " centimeters";
		break;
	case 6: cout << metricConverter.inchToMeters(value) << " meters";
		break;
	case 7: cout << metricConverter.feetToMeters(value) << " meters";
		break;
	case 8: cout << metricConverter.yardsToMeters(value) << " meters";
		break;
	case 9: cout << metricConverter.yardsToKilometers(value) << " kilometers";
		break;
	case 10: cout << metricConverter.milesToKilometers(value) << " kilometers";
		break;
	}
}

void imperialConverter(int option, double value) {
	Imperial imperialConverter;

	switch (option) {
	case 1: cout << imperialConverter.milligramsToOunce(value) << " ounce";
		break;
	case 2: cout << imperialConverter.gramsToOunce(value) << " ounce";
		break;
	case 3: cout << imperialConverter.kilogramsToPounds(value) << " pounds";
		break;
	case 4: cout << imperialConverter.millimetersToInch(value) << " inches";
		break;
	case 5: cout << imperialConverter.centimetersToInch(value) << " inches";
		break;
	case 6: cout << imperialConverter.metersToInch(value) << " inches";
		break;
	case 7:cout << imperialConverter.metersToFeet(value) << " feet";
		break;
	case 8: cout << imperialConverter.metersToYard(value) << " yards";
		break;
	case 9: cout << imperialConverter.kilometersToYards(value) << " yards";
		break;
	case 10:cout << imperialConverter.kilometersToMiles(value) << " miles";
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
	frac1 = fractionExceptionHandler();

	cout << endl << endl;

	cout << "You entered: " << frac1.toString() << endl;
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
	frac2 = fractionExceptionHandler();

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

	cout << "The result is: " << result.toString();
	cout << endl << "Press enter to go back..";
	getchar();
}



























/*


Fraction frac1;
Fraction frac2(3, 4);

cout << "enter fraction: ";
cin >> frac1;

cout << frac1.getNumerator() << "   " << frac1.getDenominator() << endl;

//Sum

Fraction frac3 = frac1 + frac2;

cout << frac3.getNumerator() << "/" << frac3.getDenominator() << endl;

//Subtraction

frac3 = frac1 - frac2;

cout << frac3.getNumerator() << "/" << frac3.getDenominator() << endl;


//Division

frac3 = frac1 / frac2;

cout << frac3.getNumerator() << "/" << frac3.getDenominator() << endl;

//Multiplication

frac3 = frac1 * frac2;

cout << frac3.getNumerator() << "/" << frac3.getDenominator() << endl;



cout << "Converting fraction to print out: ";
cout << frac1.toString() << endl;

*/