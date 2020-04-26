#include <iostream>
#include "fraction.h"

using namespace std;


void displayMenu();
void launchOption(int);
void scalingFraction();

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

void launchOption(int option) {

	switch (option) {
	case 1: scalingFraction();
		break;
	case 2: 
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

void scalingFraction() {

	int option;
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