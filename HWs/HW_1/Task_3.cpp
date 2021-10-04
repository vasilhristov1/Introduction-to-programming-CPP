/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Vasil Hristov
* @idnumber
* @task 3
* @compiler VC
*
*/

#include <iostream>
using namespace std;

//validation for the user input of an operation(when two operations(operation and letter) are entered it takes only the first one)
char SafelyInputInteger_op(char op1, char op2, char op3, char op4, char op5) {

	char charNumber;

	while (true) {
		cout << "Please, enter an operation (+, -, *, /, %): "; cin >> charNumber;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if ((charNumber == op1) || (charNumber == op2) || (charNumber == op3) || (charNumber == op4) || (charNumber == op5)) break;
	}

	return charNumber;
}
//validation for the user input of number/charachter 1
char SafelyInputInteger_nL1() {

	char charNumber;

	while (true) {
		cout << "Please, enter an one-digit hexadecimal number 1: "; cin >> charNumber;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if ((charNumber == '0') || (charNumber == '1') || (charNumber == '2') || (charNumber == '3') || (charNumber == '4') ||
			(charNumber == '5') || (charNumber == '6') || (charNumber == '7') || (charNumber == '8') || (charNumber == '9') ||
			(charNumber == 'A') || (charNumber == 'B') || (charNumber == 'C') || (charNumber == 'D') || (charNumber == 'E') ||
			(charNumber == 'F')) break;
	}

	return charNumber;
}
//validation for the user input of number/charachter 2
char SafelyInputInteger_nL2(char sym2) {

	char charNumber;

	while (true) {
		cout << "Please, enter an one-digit hexadecimal number 2: "; cin >> charNumber;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if ((charNumber == '1') || (charNumber == '2') || (charNumber == '3') || (charNumber == '4') ||
			(charNumber == '5') || (charNumber == '6') || (charNumber == '7') || (charNumber == '8') || (charNumber == '9') ||
			(charNumber == 'A') || (charNumber == 'B') || (charNumber == 'C') || (charNumber == 'D') || (charNumber == 'E') ||
			(charNumber == 'F')) break;
		else if (charNumber != sym2) continue;
	}

	return charNumber;
}

int main() {
	char op_sign = SafelyInputInteger_op('+', '-', '*', '/', '%'); 
	char numLet1 = SafelyInputInteger_nL1(); //a hexadecimal number
	char numLet2 = SafelyInputInteger_nL2('0'); //a hexadecimal number
	int num1 = 0; // a decimal number
	int num2 = 0; // a decimal number
	int resultDec = 0; //the decimal result which will be converted into hexadecimal one

	//conversion of the hexadecimal number into a decimal one
	if (numLet1 == '0')
		num1 = 0;
	if (numLet1 == '1')
		num1 = 1;
	if (numLet1 == '2')
		num1 = 2;
	if (numLet1 == '3')
		num1 = 3;
	if (numLet1 == '4')
		num1 = 4;
	if (numLet1 == '5')
		num1 = 5;
	if (numLet1 == '6')
		num1 = 6;
	if (numLet1 == '7')
		num1 = 7;
	if (numLet1 == '8')
		num1 = 8;
	if (numLet1 == '9')
		num1 = 9;
	if (numLet1 == 'A')
		num1 = 10;
	if (numLet1 == 'B')
		num1 = 11;
	if (numLet1 == 'C')
		num1 = 12;
	if (numLet1 == 'D')
		num1 = 13;
	if (numLet1 == 'E')
		num1 = 14;
	if (numLet1 == 'F')
		num1 = 15;

	if (numLet2 == '0')
		num2 = 0;
	if (numLet2 == '1')
		num2 = 1;
	if (numLet2 == '2')
		num2 = 2;
	if (numLet2 == '3')
		num2 = 3;
	if (numLet2 == '4')
		num2 = 4;
	if (numLet2 == '5')
		num2 = 5;
	if (numLet2 == '6')
		num2 = 6;
	if (numLet2 == '7')
		num2 = 7;
	if (numLet2 == '8')
		num2 = 8;
	if (numLet2 == '9')
		num2 = 9;
	if (numLet2 == 'A')
		num2 = 10;
	if (numLet2 == 'B')
		num2 = 11;
	if (numLet2 == 'C')
		num2 = 12;
	if (numLet2 == 'D')
		num2 = 13;
	if (numLet2 == 'E')
		num2 = 14;
	if (numLet2 == 'F')
		num2 = 15;

	//what have to happen when the user enters a certain operation
	switch (op_sign) {
	case '+':
		resultDec = num1 + num2;
		break;
	case '-':
		resultDec = num1 - num2;
		break;
	case '*':
		resultDec = num1 * num2;
		break;
	case '/':
		resultDec = num1 / num2;
		break;
	case '%':
		resultDec = num1 % num2;
		break;
	}
	//all the posibilities for a decimal number when you multiply the numbers from 0 to 15
	switch (resultDec) {
	case 0:
		cout << "The hexadecimal result is : 0" << endl;
		break;
	case 1:
		cout << "The hexadecimal result is : 1" << endl;
		break;
	case 2:
		cout << "The hexadecimal result is : 2" << endl;
		break;
	case 3:
		cout << "The hexadecimal result is : 3" << endl;
		break;
	case 4:
		cout << "The hexadecimal result is : 4" << endl;
		break;
	case 5:
		cout << "The hexadecimal result is : 5" << endl;
		break;
	case 6:
		cout << "The hexadecimal result is : 6" << endl;
		break;
	case 7:
		cout << "The hexadecimal result is : 7" << endl;
		break;
	case 8:
		cout << "The hexadecimal result is : 8" << endl;
		break;
	case 9:
		cout << "The hexadecimal result is : 9" << endl;
		break;
	case 10:
		cout << "The hexadecimal result is : A" << endl;
		break;
	case 11:
		cout << "The hexadecimal result is : B" << endl;
		break;
	case 12:
		cout << "The hexadecimal result is : C" << endl;
		break;
	case 13:
		cout << "The hexadecimal result is : D" << endl;
		break;
	case 14:
		cout << "The hexadecimal result is : E" << endl;
		break;
	case 15:
		cout << "The hexadecimal result is : F" << endl;
		break;
	case 16:
		cout << "The hexadecimal result is : 10" << endl;
		break;
	case 18:
		cout << "The hexadecimal result is : 12" << endl;
		break;
	case 20:
		cout << "The hexadecimal result is : 14" << endl;
		break;
	case 21:
		cout << "The hexadecimal result is : 15" << endl;
		break;
	case 22:
		cout << "The hexadecimal result is : 16" << endl;
		break;
	case 24:
		cout << "The hexadecimal result is : 18" << endl;
		break;
	case 25:
		cout << "The hexadecimal result is : 19" << endl;
		break;
	case 26:
		cout << "The hexadecimal result is : 1A" << endl;
		break;
	case 27:
		cout << "The hexadecimal result is : 1B" << endl;
		break;
	case 28:
		cout << "The hexadecimal result is : 1C" << endl;
		break;
	case 30:
		cout << "The hexadecimal result is : 1E" << endl;
		break;
	case 32:
		cout << "The hexadecimal result is : 20" << endl;
		break;
	case 33:
		cout << "The hexadecimal result is : 21" << endl;
		break;
	case 35:
		cout << "The hexadecimal result is : 23" << endl;
		break;
	case 36:
		cout << "The hexadecimal result is : 24" << endl;
		break;
	case 39:
		cout << "The hexadecimal result is : 27" << endl;
		break;
	case 40:
		cout << "The hexadecimal result is : 28" << endl;
		break;
	case 42:
		cout << "The hexadecimal result is : 2A" << endl;
		break;
	case 44:
		cout << "The hexadecimal result is : 2C" << endl;
		break;
	case 45:
		cout << "The hexadecimal result is : 2D" << endl;
		break;
	case 48:
		cout << "The hexadecimal result is : 30" << endl;
		break;
	case 49:
		cout << "The hexadecimal result is : 31" << endl;
		break;
	case 50:
		cout << "The hexadecimal result is : 32" << endl;
		break;
	case 52:
		cout << "The hexadecimal result is : 34" << endl;
		break;
	case 54:
		cout << "The hexadecimal result is : 36" << endl;
		break;
	case 55:
		cout << "The hexadecimal result is : 37" << endl;
		break;
	case 56:
		cout << "The hexadecimal result is : 38" << endl;
		break;
	case 60:
		cout << "The hexadecimal result is : 3C" << endl;
		break;
	case 63:
		cout << "The hexadecimal result is : 3F" << endl;
		break;
	case 64:
		cout << "The hexadecimal result is : 40" << endl;
		break;
	case 65:
		cout << "The hexadecimal result is : 41" << endl;
		break;
	case 66:
		cout << "The hexadecimal result is : 42" << endl;
		break;
	case 70:
		cout << "The hexadecimal result is : 46" << endl;
		break;
	case 72:
		cout << "The hexadecimal result is : 48" << endl;
		break;
	case 75:
		cout << "The hexadecimal result is : 4B" << endl;
		break;
	case 77:
		cout << "The hexadecimal result is : 4D" << endl;
		break;
	case 78:
		cout << "The hexadecimal result is : 4E" << endl;
		break;
	case 80:
		cout << "The hexadecimal result is : 50" << endl;
		break;
	case 81:
		cout << "The hexadecimal result is : 51" << endl;
		break;
	case 84:
		cout << "The hexadecimal result is : 54" << endl;
		break;
	case 88:
		cout << "The hexadecimal result is : 58" << endl;
		break;
	case 90:
		cout << "The hexadecimal result is : 5A" << endl;
		break;
	case 91:
		cout << "The hexadecimal result is : 5B" << endl;
		break;
	case 96:
		cout << "The hexadecimal result is : 60" << endl;
		break;
	case 98:
		cout << "The hexadecimal result is : 62" << endl;
		break;
	case 99:
		cout << "The hexadecimal result is : 63" << endl;
		break;
	case 100:
		cout << "The hexadecimal result is : 64" << endl;
		break;
	case 104:
		cout << "The hexadecimal result is : 68" << endl;
		break;
	case 105:
		cout << "The hexadecimal result is : 69" << endl;
		break;
	case 108:
		cout << "The hexadecimal result is : 6C" << endl;
		break;
	case 110:
		cout << "The hexadecimal result is : 6E" << endl;
		break;
	case 112:
		cout << "The hexadecimal result is : 70" << endl;
		break;
	case 117:
		cout << "The hexadecimal result is : 75" << endl;
		break;
	case 120:
		cout << "The hexadecimal result is : 78" << endl;
		break;
	case 121:
		cout << "The hexadecimal result is : 79" << endl;
		break;
	case 126:
		cout << "The hexadecimal result is : 7E" << endl;
		break;
	case 130:
		cout << "The hexadecimal result is : 82" << endl;
		break;
	case 132:
		cout << "The hexadecimal result is : 84" << endl;
		break;
	case 135:
		cout << "The hexadecimal result is : 87" << endl;
		break;
	case 140:
		cout << "The hexadecimal result is : 8C" << endl;
		break;
	case 143:
		cout << "The hexadecimal result is : 8F" << endl;
		break;
	case 144:
		cout << "The hexadecimal result is : 90" << endl;
		break;
	case 150:
		cout << "The hexadecimal result is : 96" << endl;
		break;
	case 154:
		cout << "The hexadecimal result is : 9A" << endl;
		break;
	case 156:
		cout << "The hexadecimal result is : 9C" << endl;
		break;
	case 165:
		cout << "The hexadecimal result is : A5" << endl;
		break;
	case 168:
		cout << "The hexadecimal result is : A8" << endl;
		break;
	case 169:
		cout << "The hexadecimal result is : A9" << endl;
		break;
	case 180:
		cout << "The hexadecimal result is : B4" << endl;
		break;
	case 182:
		cout << "The hexadecimal result is : B6" << endl;
		break;
	case 195:
		cout << "The hexadecimal result is : C3" << endl;
		break;
	case 196:
		cout << "The hexadecimal result is : C4" << endl;
		break;
	case 210:
		cout << "The hexadecimal result is : D2" << endl;
		break;
	case 225:
		cout << "The hexadecimal result is : E1" << endl;
		break;
	default:
		cout << "Invalide.\n";
	}

	return 0;
}