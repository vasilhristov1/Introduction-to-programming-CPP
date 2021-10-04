/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Vasil Hristov
* @idnumber
* @task 6
* @compiler VC
*
*/


#include <iostream>
#include <limits>
using namespace std;

//validation of user input
double SafelyInputInteger() {
	double doubleNumber = 0.0;

	while (true) {
		cin >> doubleNumber;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		break;
	}

	return doubleNumber;
}

//following source code is to return whether inputted coordinates belong to black, white area or they are outside or they are on the border 
//between the areas
int main() {
	const double SQ_RAD1 = 4.0; //the square of the radius of the smaller circle
	const double SQ_RAD2 = 9.0; //the square of the radius of the bigger circle
	const double RAD1 = 2.0; //radius of the smaller circle
	const double SQ_SIDE = 1; //the side of the square
	cout << "Please, enter the coordinates of a point:\n";
	cout << "Please, enter x= ";
	double x = SafelyInputInteger();
	cout << "Please, enter y= ";
	double y = SafelyInputInteger();
	const double CIRCLE = x * x + y * y; //this formula produces the circle

	if ((CIRCLE > SQ_RAD1&& CIRCLE < SQ_RAD2) || ((-SQ_SIDE < x && x < SQ_SIDE) && (-SQ_SIDE < y && y < SQ_SIDE))) {
		cout << "Black.\n";
	}
	else if (CIRCLE > SQ_RAD2) {
		cout << "Outside.\n";
	}
	else if ((CIRCLE < SQ_RAD1) &&
		((SQ_SIDE < x && x < RAD1) || (-RAD1 < x && x < -SQ_SIDE) || (SQ_SIDE < y && y < RAD1) || (-RAD1 < y && y < -SQ_SIDE))) {
		cout << "White.\n";
	}
	else
		cout << "Undefined.\n";

	return 0;
}
