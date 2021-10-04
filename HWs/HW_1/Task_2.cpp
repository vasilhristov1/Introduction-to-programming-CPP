/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Vasil Hristov
* @idnumber
* @task 2
* @compiler VC
*
*/


#include <iostream>
#include <limits>
using namespace std;

//user input validation
long SafelyInputInteger(long lowerBound, long upperBound) {

	long longNumber;

	while (true) {
		cout << "Please, enter number of days: "; cin >> longNumber;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if ((longNumber >= lowerBound) && (longNumber <= upperBound)) break;
	}

	return longNumber;
}

int main() {
	const int LOW_B = 0;    //lower bound for input data
	const int UP_B = 1000000;  //upper bound for input data
	const int LEAP_Y_DAYS = 366;  //number of days in a leap year
	const int REG_Y_DAYS = 365;  //number of days in a regular year
	const int LEAP_COND1 = 4; //leap year condition
	const int LEAP_COND2 = 100; //leap year condition
	const int LEAP_COND3 = 400; //leap year condition
	int days = SafelyInputInteger(LOW_B, UP_B);   //validating the user input
	int year = 0;  //counter for years
	int numDaysYear = REG_Y_DAYS; //variable that holds days in a year
	int numDays = 0; //counter for days

//Count from 1 to number of the user input and increment the days counter. When it reaches the number of days in a year, the years counter increments
//with 1. Number of days in year is according to the leap year condition.
	for (int i = 1; i <= days; i++) {
		++numDays;

		if (numDays == numDaysYear)
		{
			year++;
			numDays = 0;
		}
		if (((year % LEAP_COND1 == 0) && (year % LEAP_COND2 != 0)) || (year % LEAP_COND3 == 0))
			numDaysYear == LEAP_Y_DAYS;
		else
			numDaysYear == REG_Y_DAYS;
	}
	cout << "The year is: " << year << endl;


	return 0;
}
