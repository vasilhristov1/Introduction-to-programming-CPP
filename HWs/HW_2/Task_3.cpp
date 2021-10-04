/**
*
* Solution to homework assignment 2
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

const int ARRLENGTH = 1000;//the size of the array
int FindSize(char arr[1000]);//function to find the length of the entered strings
void ShortWordRep(char arr1[ARRLENGTH], char arr2[ARRLENGTH]);//function to change the bigger string

int main()
{
    char arr1[ARRLENGTH];
    char arr2[ARRLENGTH];

    cout << "Please, enter arr1: ";
    cin.getline(arr1, ARRLENGTH);
    cout << "Please, enter arr2: ";
    cin.getline(arr2, ARRLENGTH);

    cout << "The result is: " << endl;
    ShortWordRep(arr1, arr2);
    cout << endl;

    return 0;
}

void ShortWordRep(char arr1[ARRLENGTH], char arr2[ARRLENGTH])
{
    int arr1Size = FindSize(arr1);
    int arr2Size = FindSize(arr2);

    if (arr1Size > arr2Size)
    {
        //here the program changes the elements of arr1 with the elements of arr2(because arr1 size is bigger)
        int i = 0;
        while (arr1[i] != '\0')
        {
            for (size_t j = 0; arr2[j] != '\0'; j++)
            {
                if (arr1[i] == '\0')
                {
                    break;
                }
                arr1[i] = arr2[j];
                i++;
            }
        }
        cout << arr1;
    }
    else
    {
        //here the program changes the elements of arr2 with the elements of arr1(because arr2 size is bigger)
        int i = 0;
        while (arr2[i] != '\0')
        {
            for (size_t j = 0; arr1[j] != '\0'; j++)
            {
                if (arr2[i] == '\0')
                {
                    break;
                }
                arr2[i] = arr1[j];
                i++;
            }
        }
        cout << arr2;

    }
}

//function which finds the length of the string
int FindSize(char arr[1000])
{
    int i = 0;

    while (arr[i] != '\0')
    {
        i++;
    }
    return i;
}