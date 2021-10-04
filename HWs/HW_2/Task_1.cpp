/**
*
* Solution to homework assignment 2
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


#include <iostream>

using namespace std;

const int ARRLENGTH = 4;//length of the array

//this function finds the length of the entered excel column
int FindSize(char arr[ARRLENGTH])
{
	int i = 0;

	while (arr[i] != '\0')
	{
		i++;
	}
	return i;
}

int Number_of_Column(char arr[ARRLENGTH]) {
	int num_col = 0; //number of column
	int pos = 1; //position
	int arr_len = FindSize(arr) - 1; //length of the array
	const int ALPHABETLET = 26;//number of letters in the alphabet

	for (int i = arr_len; i >= 0; i--) {

		int letPosAlphabet = (int(arr[i]) - 64); //position of the letter in the alphabet
		num_col += letPosAlphabet * pos;
		pos *= ALPHABETLET;

	}

	return num_col;
}

int main() {
	char arr1[ARRLENGTH] = { 0 };

	cout << "Please, enter an excel column: ";
	cin.getline(arr1, ARRLENGTH); //cuts the letters after the third one and takes the result of the first three letters

	cout << "The number of the column is: " << Number_of_Column(arr1) << endl;

	return 0;
}