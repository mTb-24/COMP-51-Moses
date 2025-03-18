#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main () 

{
    int userInput;
    int userAttempts = 0;

    srand(time(0));

    int ranNum = rand() % 100 + 1;

    cout << "Welcome to the Number Guessing Game!!!" << endl << endl;

    cout << "If you wanna quit, press the 'q' key." << endl << endl;

    cout << "Enter a number between 1 and 100: ";
    cin >> userInput;
    cout << endl << endl;

    while (userInput != 'q') {
        for(int i = 0; i < 5; ++i){
            if (userInput > ranNum) {
                cout << "Too High" << endl;
            }
    
            else if (userInput < ranNum) {
                cout << "Too Low" << endl;
            }

            cout << "Enter a number between 1 and 100: ";
            cin >> userInput;
            cout << endl;
    
            if (userInput == ranNum) {
                cout << "Congratulations!!!" << endl;
            }
        }

        if (userInput == 'q') {
            break;
        }
        cout << "No more attempts left. The correct number is " << ranNum << endl << endl;
            break;
    }
}