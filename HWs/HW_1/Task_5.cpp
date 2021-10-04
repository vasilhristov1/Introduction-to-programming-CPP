/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Vasil Hristov
* @idnumber
* @task 5
* @compiler VC
*
*/


#include <iostream>
#include <limits>
#include <cmath>

using namespace std;

//validation for user input
double SafelyInputInteger(double wrongNum) {

	double doubleNumber = 0.0;

	while (true) {
		cin >> doubleNumber;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (doubleNumber != wrongNum) break;
	}

	return doubleNumber;
}

int main() {
	const double WR_NUM = 0.00000000000001; // just to write something as an argument for the user input validation function
	cout << "Please, enter coefficient a (not 0): "; //a shouldn't be equal to 0 because the equation won't be a biquadratic one
	double a = SafelyInputInteger(0.0);
	cout << "Please, enter coefficient b: ";
	double b = SafelyInputInteger(WR_NUM);
	cout << "Please, enter coefficient c: ";
	double c = SafelyInputInteger(WR_NUM);
	double y1 = 0.0, y2 = 0.0, x1 = 0.0, x2 = 0.0, x3 = 0.0, x4 = 0.0, discriminant = 0.0;

	cout << endl;

	cout << a << "x^4 + " << b << "x^2 + " << c << " = 0\n"; //this is how the biquadratic equation looks like
	cout << "y = x^2\n";
	cout << a << "y^2 + " << b << "y + " << c << " = 0\n"; //this is when we substitute with y
	discriminant = b * b - 4 * a * c; //formula for the discriminant
	cout << "Discriminant = " << discriminant << endl;

	if (discriminant > 0.0) //when the discriminant is bigger than zero there are two solutions
	{
		y1 = (-b + sqrt(discriminant)) / (2 * a);
		y2 = (-b - sqrt(discriminant)) / (2 * a);
		cout << "y1 = " << y1 << " ; " << "y2 = " << y2 << endl;
	}
	else if (discriminant == 0.0) //when the discriminant is zero there is one double solution
	{
		y1 = y2 = (-b + sqrt(discriminant)) / (2 * a);
		cout << "y= " << y1 << endl;
	}
	else
		cout << "There are no real solutions\n";
	//from here to the bottom of the source code there are conditions for the solutions of x
	if (y1 > 0.0 && y2 > 0.0)
	{
		x1 = +sqrt(y1);
		x2 = -sqrt(y1);
		x3 = +sqrt(y2);
		x4 = -sqrt(y2);
		cout << "x1 = " << x1 << "  " << "x2 = " << x2 << "  " << "x3 = " << x3 << "  " << "x4 = " << x4 << endl;
	}
	else if (y1 > 0.0 && y2 < 0.0)
	{
		x1 = +sqrt(y1);
		x2 = -sqrt(y1);
		cout << "x1 = " << x1 << "  " << "x2 = " << x2 << endl;
		cout << "There are no x3 and x4 because y2 is negative and cannot be rooted.\n";
	}
	else if (y1 < 0.0 && y2 > 0.0)
	{
		x3 = +sqrt(y2);
		x4 = -sqrt(y2);
		cout << "x1 = " << x3 << "  " << "x2 = " << x4 << endl;
		cout << "There are no x3 and x4 because y1 is negative and cannot be rooted.\n";
	}
	else if (y1 == 0.0 && y2 > 0.0)
	{
		x3 = +sqrt(y2);
		x4 = -sqrt(y2);
		cout << "x1 = " << x3 << "  " << "x2 = " << x4 << "  " << "x3 = " << y1 << "  " << "x4 = " << y1 << endl;
	}
	else if (y1 > 0.0 && y2 == 0.0)
	{
		x1 = +sqrt(y1);
		x2 = -sqrt(y1);
		cout << "x1 = " << x1 << "  " << "x2 = " << x2 << "  " << "x3 = " << y2 << "  " << "x4 = " << y2 << endl;
	}
	else if (y1 < 0.0 && y2 == 0.0)
	{
		cout << "x1 = " << y2 << "  " << "x2 = " << y2 << endl;
		cout << "x1 = x2 = 0\n";
	}
	else if (y1 == 0.0 && y2 < 0.0)
	{
		cout << "x1 = " << y1 << "  " << "x2 = " << y1 << endl;
		cout << "x1 = x2 = 0\n";
	}
	else
	{
		cout << "There are no solutions for x.\n";
	}

	return 0;
}
