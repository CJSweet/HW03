#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdexcept>  // Needed for exceptions
#include <limits>     // Needed for limits of system values

using namespace std;

/**
*	Divides x by y
*	@pre y != 0 && x > 0   (this is the pre-condition for this function)
*	@param x	dividend
*	@param y 	divisor
*	@return x divided by y
*/
double division(double x, double y) {
	if (y == 0)
		throw string("denominator cannot be 0.");
	if (x <= 0)
		throw out_of_range("numerator must be postive");
	return x / y;
}

int main() {
	double input_x, input_y;
	do {
		try {
			cin.exceptions(ios::failbit | ios::badbit);
			cout << "Enter a numerator: ";
			cin >> input_x;
			cout << "Enter a denominator: ";
			cin >> input_y;
			cout << "Result of division is " << division(input_x, input_y) << endl;
		}
		catch (ios_base::failure &ex) {
			cout << "Invalid input, try again" << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (string& msg) {
			cout << msg << endl;
		}
		catch (out_of_range &oor) {
			cout << oor.what() << endl;
		}
		catch (...) {
			cout << "oops, something bad has happened" << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	} while (true);
}
