/**
*
* Solution to homework assignment 3
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
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

const int ARR1 = 10;
const int ARR2 = 100;

//an array which is like a database with the questions for the game
char questions[ARR1][ARR2] = { "Which of the following men does not have a chemical element named for him?",
                           "Which insect shorted out an early supercomputer and inspired the term computer bug?",
                           "During WWII, US soldiers used the first commercial aerosol cans to hold what?",
                           "How many seconds are in 2 years?",
                           "Where is situated the Eiffel Tower?",
                           "Which country share a border with Bulgaria?",
                           "What is the number of countries in the world?",
                           "Who was not a member of the Beatles?",
                           "Which of the following is not a type of pasta?",
                           "Which state has cities named San Francisco and Hollywood?" };

//an array which is like a database with the answers for the questions above
char answers[ARR1][ARR2] = { " A. Albert Einstein\t B. Niels Bohr\n C. Isaac Newton\t D. Enrico Fermi",
                         " A. Moth\t B. Roach\n C. Fly\t D. Japanese beetle",
                         " A. Cleaning fluid\t B. Antiseptic\n C. Insecticide\t D. Shaving cream",
                         " A. 47 336 400\t B. 31 557 600\n C. 60 485 400\t D. 63 115 200",
                         " A. New York\t B. London\n C. Paris\t D. Berlin",
                         " A. The Netherlands\t B. Macedonia\n C. Albania\t D. Croatia",
                         " A. 236\t B. 207\n C. 193\t D. 195",
                         " A. John Lennon\t B. Paul McCartney\n C. Ringo Star\t D. Justin Timberlake",
                         " A. Spaghetti\t B. Escargot\n C. Fettuccine\t D. Ziti",
                         " A. California\t B. Utah\n C. Hawaii\t D. Montana" };

//an array which is like a database for the joker 50/50 
char joker_50_50[ARR1][ARR2] = { " A.\t B.\n C.Isaac Newton\t D.Enrico Fermi",
                             " A. Moth\t B.\n C.\t D. Japanese beetle",
                             " A.\t B. Antiseptic\n C. Insecticide\t D.",
                             " A. \t B. \n C. 60 485 400\t D.63 115 200",
                             " A. New York\t B.\n C. Paris\t D.",
                             " A.\t B. Macedonia\n C.\t D. Croatia",
                             " A.\t B. 207\n C.\t D. 195",
                             " A.\t B.\n C. Ringo Star\t D. Justin Timberlake",
                             " A.\t B.Escargot\n C.\t D.Ziti",
                             " A. California\t B. Utah\n C.\t D." };

//function to choose random number
int RandomChoose()
{
    srand((unsigned)time(0));

    int randIndex = (rand() % 10);

    return randIndex;
}

int main() {
    bool play_again = 0;//if the player want to start a new game

    do
    {
        int variable = RandomChoose();//variable which contains the random number chosen by the function RandomChoose
        char user_answer;//the answer entered by the player
        bool correct = 0;//checks if the answer is correct
        int joker = 0;//if the player want to use the joker 50/50 they have to enter 1 or 0

        system("CLS");

        //show the question and its answers
        cout << questions[variable] << endl << answers[variable] << endl << endl;

        cout << "Do you want to use joker 50:50? (For 'YES' press 1 ,For 'NO' press 0)";
        do
        {
            cin >> joker;
        } while (joker != 1 && joker != 0);

        if (joker == 1)
        {
            system("CLS");

            //if the player want 50:50 there is shown the array where 2 of the wrong answers are removed
            cout << questions[variable] << endl << joker_50_50[variable] << endl;
            cout << "Please, enter your answer: ";
            do {
                cin >> user_answer;
            } while (user_answer != 'a' && user_answer != 'b' && user_answer != 'c' && user_answer != 'd' &&
                user_answer != 'A' && user_answer != 'B' && user_answer != 'C' && user_answer != 'D');
        }
        else
        {
            cout << "Please, enter your answer: ";
            do {
                cin >> user_answer;
            } while (user_answer != 'a' && user_answer != 'b' && user_answer != 'c' && user_answer != 'd' &&
                user_answer != 'A' && user_answer != 'B' && user_answer != 'C' && user_answer != 'D');
        }

        //cases for the correct answer for each question
        switch (variable)
        {
        case 0:
            if (user_answer == 'c' || user_answer == 'C')
            {
                correct = 1;
            }
            break;
        case 1:
            if (user_answer == 'a' || user_answer == 'A')
            {
                correct = 1;
            }
            break;
        case 2:
            if (user_answer == 'c' || user_answer == 'C')
            {
                correct = 1;
            }
            break;
        case 3:
            if (user_answer == 'd' || user_answer == 'D')
            {
                correct = 1;
            }
            break;
        case 4:
            if (user_answer == 'c' || user_answer == 'C')
            {
                correct = 1;
            }
            break;
        case 5:
            if (user_answer == 'b' || user_answer == 'B')
            {
                correct = 1;
            }
            break;
        case 6:
            if (user_answer == 'd' || user_answer == 'D')
            {
                correct = 1;
            }
            break;
        case 7:
            if (user_answer == 'd' || user_answer == 'D')
            {
                correct = 1;
            }
            break;
        case 8:
            if (user_answer == 'b' || user_answer == 'B')
            {
                correct = 1;
            }
            break;
        case 9:
            if (user_answer == 'a' || user_answer == 'A')
            {
                correct = 1;
            }
            break;
        }

        //here the program tells the player if their answer is correct or not
        if (correct == 1)
        {
            cout << "This answer is correct!  YOU WIN! " << endl << endl;
        }
        else
            cout << "This answer is incorrect!  You loose! " << endl << endl;

        //here the program asks if the player want to play again where the variable new_game comes in use
        cout << "Would you like to play again? (if 'YES' enter 1, if 'NO' enter 0)"; cin >> play_again;
    } while (play_again == 1);

    return 0;
}