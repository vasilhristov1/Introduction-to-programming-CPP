/**
*
* Solution to homework assignment 9
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

const int SIZE = 20;
const int SIZE_ = 10;

// function to find the shortest string that contains all the words from charSet[] in mainString[]
void findShortest(char mainString[], char charSet[]) {
	bool isTrue = false; // it is used to check if the length 
	int l = 0; // counter for how many elements from charSet are in mainString
	int position[SIZE] = { 0 }; // holds the positions of the letters from charSet in mainString
	int max = 0; // max position in the array above
	int min = 0; // min position in the array above
	int charSet_size = 0; // holds the number of the characters in charSet

	// loop to count the elements in charSet
	for (int m = 0; charSet[m] != '\0'; m++) {
		charSet_size++;
	}

	// loop to count how many elements from charSet are in mainString
	for (int i = 0; charSet[i] != '\0'; i++) {
		for (int j = 0; mainString[j] != '\0'; j++) {
			if (mainString[j] == charSet[i]) {
				l += 1;
			}
		}
	}

	// check if all the elements from charSet are in mainString
	if (l == charSet_size) {
		isTrue = true;
	}

	// if the condition above is true, the positions of the elements from charSet in mainString are being added in the array position[]
	if (isTrue == 1) {
		for (int t = 0; charSet[t] != '\0'; t++) {
			for (int g = 0; mainString[g] != '\0'; g++) {
				if (charSet[t] == mainString[g]) {
					position[t] = g;
				}
			}
		}
	}

	max = position[0]; // max is the first element of the array

	// finding the maximum position of the array
	for (int y = 0; y < l; y++)
	{
		if (max < position[y])
			max = position[y];
	}

	min = position[0]; // min is the first element of the array

	// finding the minimum position of the array
	for (int y = 0; y < l; y++)
	{
		if (min > position[y])
			min = position[y];
	}

	// if isTrue is true, the console prints the string from the element on the min position to the element with max position 
	if (isTrue == 1) {
		for (int s = min; s <= max; s++) {
			cout << mainString[s];
		}
		cout << endl;
	}
	// if isTrue is false, the console prints empty string
	else {
		cout << " " << endl;
	}
}

int main() {
	char charSet1[SIZE_] = "eyqw";
	char mainString1[SIZE] = "asdfgqwertyzxcvb";
	char charSet2[SIZE_] = "qpz";
	char mainString2[SIZE] = "vmxlaoergh";
	char charSet3[SIZE_] = "nlc";
	char mainString3[SIZE] = "flacbenm";

	findShortest(mainString1, charSet1);
	findShortest(mainString2, charSet2);
	findShortest(mainString3, charSet3);

	return 0;
}