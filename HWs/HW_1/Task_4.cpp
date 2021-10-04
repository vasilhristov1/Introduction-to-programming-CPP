/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Vasil Hristov
* @idnumber
* @task 4
* @compiler VC
*
*/


#include <iostream>
#include <limits>
#include <stdlib.h>

using namespace std;

//validation of user input
int SafelyInputInteger(int lowerBound, int upperBound) {

	int intNumber;

	while (true) {
		cout << "Please, enter a number: "; cin >> intNumber;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if ((intNumber > lowerBound) && (intNumber < upperBound)) break;
	}

	return intNumber;
}

int main() {
	const int LOW_B = 0; //lower bound of user input
	const int UP_B = 65536;//upper bound of user input
	int number = SafelyInputInteger(LOW_B, UP_B);
	system("CLS"); //cleans the screen



	while (number >= 0)
	{
		cout << number << endl;  //shows on the screen number of user input in decreasing order as a timer

		//operations to slow down the counter
		for (double i = 0.0; i < 10000.0; i++) {
			for (double j = 0.0; j < 10000.0; j++) {
				volatile double a = i / j;
			}
		}
		system("CLS");
		number--;
	}

	return 0;
}
