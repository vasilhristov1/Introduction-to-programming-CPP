/**
*
* Solution to homework assignment 2
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

using namespace std;

int ShortWordNum(char arr[1000]);//function to find and count the shortest words
bool isValidSymbol(char ch);//function to check if the characters are valid

int main()
{
	char arr[1000];

	cout << "Please, enter a sentence: ";
	cin.getline(arr, 1000);

	cout << ShortWordNum(arr) << endl;
}

//this function finds how many are the shortest words in a sentence
int ShortWordNum(char arr[1000])
{
	int i = 0;
	int smallestSize = 1000;
	int wordsCounter = 0;
	int symbolCounter = 0;
	bool isValid = true;

	while (true)
	{
		if (arr[i] == '\0')//when the program get to the end of the word it increases the number of words
		{
			if (symbolCounter < smallestSize && isValid == true)
			{
				wordsCounter = 1;
			}
			else if (symbolCounter == smallestSize && isValid == true)
			{
				wordsCounter++;
			}
			break;
		}

		if (arr[i] == ' ')//when the program get to " " it changes the number of the symbols to 0
		{
			if (symbolCounter < smallestSize && isValid == true && symbolCounter > 0)
			{
				smallestSize = symbolCounter;
				wordsCounter = 1;
			}
			else if (symbolCounter == smallestSize && isValid == true)
			{
				wordsCounter++;
			}
			symbolCounter = 0;
			isValid = true;
		}
		else if (isValidSymbol(arr[i]))//when the symbol is from the valid ones it increases the number of the symbols
		{
			symbolCounter++;
		}
		else
		{
			isValid = false;
		}
		i++;
	}
	return wordsCounter;
}

//check for invalid characters
bool isValidSymbol(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '-' || ch == '_';
}