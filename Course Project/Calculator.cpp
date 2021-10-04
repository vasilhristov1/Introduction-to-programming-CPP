#include <iostream>
using namespace std;

const int MAX_ARR_LEN = 100; // the max length of an array
const int MAX_INPUT_LEN = 1000; // the max length of the user input

bool inputValid(char input[]); // function to check if the entered expression is valid
bool ifExit(char input[]); // function to check if 'exit' is entered
int convertDigitsIntoNum(int digits[], int lenght, bool negativeNumber); // to transform the simple digits into one number
int factorialFunction(int number); // function to calculate the factorial of a number
int* char_IntConverter(char input[], int& numbersTyped); // function to convert char numbers into int ones
char* opFunction(char input[]); // function to find the operators in the expression
void inputCalc(int numbers[], char operators[], int& numbersTyped); // function to do the calculations according to the operation sign

int main() {
    char expression[MAX_INPUT_LEN]; // the expression entered by the user
    int numbers[MAX_ARR_LEN]; // the numbers in the expression
    char operators[MAX_ARR_LEN]; // the operations in the expression
    bool calcStop = false; // contains the answer of the function ifExit

    do {
        int numsEntered = INT_MAX; // expands to the largest positive value that can be stored in an int
        do {
            cout << "Please, enter an expression to calculate or type 'exit' to stop the calculator: " << endl; // the message on the screen
            cin.getline(expression, MAX_INPUT_LEN); // to enter the expression with all the characters

            // if exit is entered calcStop becomes true and the program finishes
            if (ifExit(expression) == true) {
                calcStop = true;
                break;
            }

            // checks if the expression is valide and if it is not the program show the message below
            if (inputValid(expression) == false) {
                cout << "Invalide expression!" << endl;
            }
        } while (inputValid(expression) == false); // this repeats as long as the expression(input) is invalid

        // when calcStop is not true the comands below are being done
        if (calcStop != true) {
            // converts the character numbers of the expression to their matching integer numbers
            for (int i = 0; i < numsEntered; i++) {
                numbers[i] = char_IntConverter(expression, numsEntered)[i];
            }
            // 
            for (int i = 0; opFunction(expression)[i] != '\0'; i++) {
                operators[i] = opFunction(expression)[i];
            }
            inputCalc(numbers, operators, numsEntered); // calculation of the expression
        }
    } while (calcStop == false); // when ifExit is false, calcStop also becomes false and the program stops

    return 0;
}

void inputCalc(int numbers[], char operators[], int& numbersTyped) {
    int calcResult = 0; // the result of the calculation
    bool error = false; // to check if there is wrong division

    //if only one number is entered
    if (numbersTyped == 1) {
        cout << "The result is: " << numbers[0] << endl;
    }
    else {
        for (int i = 0; i < numbersTyped - 1; i++) {
            switch (operators[i]) {

            // addition when the operator sign is '+'
            case '+':
                if (i == 0) {
                    calcResult = numbers[i] + numbers[i + 1];
                }
                else {
                    calcResult += numbers[i + 1];
                }
                break;
            
            // subtraction when the operator is '-'
            case '-':
                if (i == 0) {
                    calcResult = numbers[i] - numbers[i + 1];
                }
                else {
                    calcResult -= numbers[i + 1];
                }
                break;

            // multiplication when the operator is '*'
            case '*':
                if (i == 0) {
                    calcResult = numbers[i] * numbers[i + 1];
                }
                else {
                    calcResult *= numbers[i + 1];
                }
                break;
            
            // division when the operator is '/'
            case '/':
                if (i == 0) {

                    // when a number is divided by zero
                    if (numbers[i + 1] == 0) {
                        error = true;
                        cout << "Error! Cannot divide by zero!!!" << endl;
                    }
                    else {
                        calcResult = numbers[i] / numbers[i + 1];
                    }
                }
                else {

                    // when a number is divided by zero
                    if (numbers[i + 1] == 0) {
                        error = true;
                        cout << "Error! Cannot divide by zero!!!" << endl;
                    }
                    else {
                        calcResult /= numbers[i + 1];
                    }
                }
                break;
            }
        }

        // when there is no error in any of the operations the program will calculate the result
        if (error != true) {
            cout << "The result is: " << calcResult << endl;
        }
    }
}

char* opFunction(char input[]) {
    char operators[MAX_ARR_LEN]; // the operators in the expression
    int intOfChar = 0;  //operations [intOfChar]
    for (int i = 0; input[i] != '\0'; i++) {

        // checks if the element is an operation sign
        if ((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')) {

            //this check is for negative numbers in the begining
            if (input[i] == '-' && (input[i + 1] >= '0' && input[i + 1] <= '9')) {
                continue;
            }
            operators[intOfChar] = input[i];
            intOfChar++;
        }
    }

    operators[intOfChar] = '\0';

    return operators;
}

int* char_IntConverter(char input[], int& enteredNums) {
    enteredNums = 0; // counts the entered numbers
    bool factorial = false; // if the sign for factorial is entered
    bool negativeNum = false; // if there is negative number
    int intOfInputCharArray = 0; // input[intOfInputCharArray]
    int digits = 0; // counts how many digits are there in a number  
    int num_digits[MAX_ARR_LEN]; // this saves the digits of a number when it is broken down form the char array
    int arrOfNums[MAX_ARR_LEN]; // this saves the actual numbers
    bool inputEnd = false; // when the program gets to the end of the expression

    // this is going to happen as long as an element from the input is not equal to the terminating zero
    while (input[intOfInputCharArray] != '\0') {
        digits = 0;
        factorial = false;

        // to skip the operation symbols so that they will not be converted into int numbers
        if (input[intOfInputCharArray] == '+' || input[intOfInputCharArray] == '-' ||
            input[intOfInputCharArray] == '*' || input[intOfInputCharArray] == '/') {

            if (input[intOfInputCharArray] == '-' &&
                (input[intOfInputCharArray + 1] >= '0' && input[intOfInputCharArray + 1] <= '9')) {
                // checks if the number is negative
                negativeNum = true;
                intOfInputCharArray++;
            }
            else {
                // to skip the symbols of the operations
                intOfInputCharArray += 2;
            }
        }
        else {
            while (input[intOfInputCharArray] != ' ') {
                // it saves the digits of the number until it reaches space
                if (input[intOfInputCharArray] == '\0') {
                    inputEnd = true;
                    break;
                }
                // factorial check
                else if (input[intOfInputCharArray] == '!') {
                    factorial = true;
                    intOfInputCharArray++;
                }
                // the conversion from char to int happens below
                else {
                    num_digits[digits] = input[intOfInputCharArray] - '0';
                    intOfInputCharArray++; digits++;
                }
            }
            if (factorial == true) {
                // this saves the number after it is calculated as factorial
                arrOfNums[enteredNums] = factorialFunction(convertDigitsIntoNum(num_digits, digits, negativeNum));
                enteredNums++; intOfInputCharArray++;
            }
            else {
                // this saves the actual number in the array of numbers
                arrOfNums[enteredNums] = convertDigitsIntoNum(num_digits, digits, negativeNum);
                enteredNums++; intOfInputCharArray++;
                negativeNum = false;
            }
        }

        // stops the conversion when the end of the input is reached
        if (inputEnd == true) {
            break;
        }
    }

    return arrOfNums;
}

// function to find the factorial of a number with recursion
int factorialFunction(int number) {
    if (number < 0) return -1;
    if (number == 0) return 1;

    return number * factorialFunction(number - 1);
}


// function to transform the digits(elements of the array which are consequent digits without space between them) into numbers
int convertDigitsIntoNum(int digits[], int lenght, bool negativeNumber) {
    int newLength = lenght - 1; // the new length of the number's array
    int number = 0; // the number

    // it transform the simple digits into a number
    for (int i = 0; i < lenght; newLength--, i++) {
        number += digits[i] * pow(10, newLength);
    }

    // checks if the number is negative
    if (negativeNumber == true) {
        number *= -1;
        return number;
    }

    return number;
}

bool ifExit(char input[]) {
    //all the possibilities to exit the console
    if ((input[0] == 'e' || input[0] == 'E') && (input[1] == 'x' || input[1] == 'X') &&
        (input[2] == 'i' || input[2] == 'I') && (input[3] == 't' || input[3] == 'T')) {
        return true;
    }
    else {
        return false;
    }
}

bool inputValid(char input[]) {

    // if the first element is not from zero to 9 or '-', the input is not valid and returns false
    if (!((input[0] >= '0' && input[0] <= '9') || input[0] == '-')) {
        return false;
    }

    // this is to check if every element of the expression is valid
    for (int i = 0; input[i] != '\0'; i++) {

        // checks for an element if it is valid
        if ((input[i] >= '0' && input[i] <= '9') || input[i] == ' ' ||
            input[i] == '+' || input[i] == '-' || input[i] == '*' ||
            input[i] == '/' || input[i] == '!') {

            // if the element from above is valid this below checks the next element
            if ((input[i] >= '0' && input[i] <= '9') && ((input[i + 1] >= '0' && input[i + 1] <= '9') ||
                input[i + 1] == ' ' || input[i + 1] == '!' || input[i + 1] == '\0')) {
                continue; // if the number after the symbol is correct
            }
            else if (input[i] == '!' && (input[i + 1] == ' ' || input[i + 1] == '\0')) {
                continue; // if the element after the factorial is valid
            }
            else if ((input[i] == '-') && (input[i + 1] >= '0' && input[i + 1] <= '9')) {
                // if the typed number is negative
                int i_checkup = i + 1;
                while ((input[i_checkup] >= '0' && input[i_checkup] <= '9') || (input[i_checkup] == '!')) {
                    // if the factorial (!) is used correctly
                    if (input[i_checkup] == '!') {
                        return false;
                    }
                    i_checkup++;
                }
                continue;
            }
            else if ((input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') &&
                (input[i + 1] == ' ') && ((input[i + 2] >= '0' && input[i + 2] <= '9') || input[i + 2] == '-') &&
                (input[i + 1] != '\0')) {
                continue; // checks if the symbol after the operation is a valid one
            }
            else if (input[i] == ' ') {
                if (!(input[i - 1] == '+' || input[i - 1] == '-' || input[i - 1] == '*' || input[i - 1] == '/') &&
                    !(input[i + 1] == '+' || input[i + 1] == '-' || input[i + 1] == '*' || input[i + 1] == '/')) {
                    return false; // checks if before and after the space the expression is correct if not the inputValid is false
                }
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    return true;
}