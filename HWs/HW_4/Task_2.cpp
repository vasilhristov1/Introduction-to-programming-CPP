/**
*
* Solution to homework assignment 9
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

const int ROMAN_SIZE = 7; // size of the roman_numerals array
const int START = 2; // the position of the element from where the arabic number starts in the roman_numerals array
const int INPUT_SIZE = 10; // size of the input string
const int SIZE = 20; // the size of the position array

// global array that contains the roman numerals
char roman_numerals[ROMAN_SIZE][ROMAN_SIZE]{
	"I-1",
	"V-5",
	"X-10",
	"L-50",
	"C-100",
	"D-500",
	"M-1000"
};

// function to make a string number in integer one
int strToInt(char* str) {
	int result = 0; // holds the result
	int i = START; // variable which gives the start from the third element of the string (because the string in the array "roman_numerals" is like "X-10"

	// loop to take every digit of the string number and change it so that it becomes integer
	for (; str[i] != '\0'; ++i) {
		result = result * 10 + str[i] - '0';
	}

	// returns the integer number
	return result;
}

// function that converts roman numbers into arabic ones
void convertRoman(char* str) {
	int position[SIZE]; // holds the positions of every element from the input
	int size = 0; // holds the number of elements int the input string
	int arabic_result = 0; // holds the converted roman number
	bool isTrue = true; // it is used for checking if the input is correct
	int input_characters = 0; // holds the number of all elements in the input string

	// loop to count the size of the input string
	for (int l = 0; str[l] != '\0'; l++) {
		input_characters++;
	}

	// loop to check if the elements of the input string are in the global array which contains the roman numerals
	for (int i = 0; str[i] != '\0'; i++) {
		for (int j = 0; j < ROMAN_SIZE; j++) {
			if (str[i] == roman_numerals[j][0]) {
				position[size] = j;
				size++;
			}
		}
	}

	// checks if all the roman numerals from the input are accepted
	if (input_characters > size) {
		isTrue = false;
	}

	for (int i = 0; i < size; i++) {
		// Getting value of symbol s[i] 
		int s1 = 0;

		s1 = strToInt(roman_numerals[position[i]]);

		if (i + 1 < size) {
			// Getting value of symbol s[i+1] 
			int s2 = 0;

			s2 = strToInt(roman_numerals[position[i + 1]]);

			// Comparing both values 
			if (s1 >= s2) {
				// Value of current symbol is greater or equal to the next symbol 
				arabic_result += s1;
			}
			else {
				// Value of current symbol is less than the next symbol 
				arabic_result = arabic_result + s2 - s1;
				i++;
			}
		}
		else {
			arabic_result += s1;
		}
	}

	// if the input is incorrect a message for this is printed on the console
	// else the result is printed
	if (isTrue == 1) {
		cout << arabic_result << endl;
	}
	else {
		cout << "Wrong roman numeral in the input!\n";
	}
}

int main() {
	char x[INPUT_SIZE] = "XIX";
	char y[INPUT_SIZE] = "VIIi";
	char z[INPUT_SIZE] = "MMXX";

	convertRoman(x);
	convertRoman(y);
	convertRoman(z);

	return 0;
}