/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Vasil Hristov
* @idnumber
* @task 1
* @compiler VC
*
*/

//user input validation source code
#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

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
	const int UP_B = pow(2, 31) - 1; //upper bound for user input
	const int LOW_B = pow((-2), 31); //lower bound for user input
	int number = SafelyInputInteger(LOW_B, UP_B); //number which is going to be checked if it has repeated digits or not
	int variable = 0; //holds the digits which will be compared

	while (number != 0 && !(variable & 1 << number % 10))
	{ //the bite of the most right digit of the number is activated
	  //it starts with the right digit of the number and compares it to each of the following leftwards
	  //if it finds the same digit it stops and says that there are repeated digits or if it does not find it says there are no repeated digits

		variable = variable | 1 << number % 10;
		number /= 10;
	}
	if (number != 0)
		cout << "There are repeated digits.\n";
	else
		cout << "There are no repeated digits.\n";

	return 0;
}
