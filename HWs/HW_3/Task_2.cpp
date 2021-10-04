/**
*
* Solution to homework assignment 3
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
using namespace std;

int main() {
	const int ELEMENTS = 1;
	const int MAX_LEN = 102;
	char op = 0;
	int x1[ELEMENTS][MAX_LEN];
	int x2[ELEMENTS][MAX_LEN];

	cout << "Simple calculator." << endl;

	cout << "Enter an operation(+, -, *): ";
	cin >> op;

	cout << "Enter X1: ";
	cin >> x1[0][102];

	cout << "Enter X2: ";
	cin >> x2[0][102];

	cout << op << " " << x1 << " " << x2 << endl;

	switch (op) {
	case '+':
		cout << "The addition of X1 and X2 is: " << x1[0][MAX_LEN] + x2[0][MAX_LEN] << endl;
		break;
	case '-':
		cout << "The substitution of X1 and X2 is: " << x1[0][MAX_LEN] - x2[0][MAX_LEN] << endl;
		break;
	case '*':
		cout << "The multiplication of X1 and X2 is: " << x1[0][MAX_LEN] * x2[0][MAX_LEN] << endl;
		break;
	default:
		cout << "Error!" << endl;
	}

	return 0;
}