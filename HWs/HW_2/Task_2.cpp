/**
*
* Solution to homework assignment 2
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

const int ARRLENGTH = 1024;

int Encription_of_Str(char* arr, int m, int l);

int main() {
    const int TASKREQ_L = 100; //" len ≤ 100 " from the task requirements
    const int TASKREQ_M = 20; //" M ≤ 20 " from the task requirements
    char str[ARRLENGTH];
    int arr_length;
    int M = 0, L = 0;

    cout << "Please, enter a string:";
    cin.getline(str, ARRLENGTH);
    arr_length = strlen(str);
    //if the entered string is larger than ARRLENGTH(1024)
    for (; arr_length > ARRLENGTH;) {
        cout << "Please, enter a string:";
        cin.getline(str, ARRLENGTH);
        arr_length = strlen(str);
    }

    cout << "Please, enter M: "; cin >> M;
    //there the program checks if M is in the borders mentioned in the task requirements
    for (; M < 0 || M > TASKREQ_M;) {
        cout << "Please, enter M: "; cin >> M;
    }

    cout << "Please, enter L: "; cin >> L;
    //there the program checks if L is less than the length of the array
    for (; L < 0 || L >= arr_length || L > TASKREQ_L;) {
        cout << "Please, enter L: "; cin >> L;
    }

    Encription_of_Str(str, M, L);  //encryption of the entered string

    cout << endl;
    cout << "The encription of the entered arr is this: " << endl << str << endl;

    return 0;
}

int Encription_of_Str(char* arr, int m, int l) {
    char* arr1 = arr;
    char sub_arr[ARRLENGTH]; //array which contains the substituted characters of the string entered according to M
    int arr_len = strlen(arr); //length of the string
    bool containsInvalidCharacters = 0; //to check for innvalide characters
    const char LOWERBOUND = 32;//ASCII code for the lower bound of valid characters
    const char UPPERBOUND = 126;//ASCII code for the upper bound of valid characters

    //checks if invalide characters were entered
    for (int i = 0; i < strlen(arr); i++)
    {
        char currentChar = arr[i];

        if (currentChar < LOWERBOUND || currentChar > UPPERBOUND)
        {
            containsInvalidCharacters = 1;
        }
    }

    if (!containsInvalidCharacters) {
        //here is the change of the character
        for (int i = 0; i < arr_len; i++) {

            sub_arr[i] = (*arr1++) + m;

            if (i + 1 == arr_len) {
                sub_arr[i + 1] = '\0';
            }
        }
        //here is the displacement of the character
        for (int i = 0, v = 0, s = 0; i < arr_len; i++) {
            if (v < arr_len - l) {
                *(arr + l + v) = sub_arr[i];
                v++;
            }
            else {
                *(arr + s) = sub_arr[i];
                s++;
            }
        }
    }
    else {
        cout << arr << endl;
    }

    return 0;
}