#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDie(){
    return (rand() % 6) + 1;
}

int rollMultipleDice(int numberOfDice){
    int total = 0;
    for (int i = 0; i <= numberOfDice; i++){
        int dieRoll = rollDie();
        total += dieRoll;
        cout << "Roll " << (i + 1) << ": " << dieRoll << endl;
    }

    return total;
}

int playRound(){
    cout << "Player's roll." << endl;
    int playerSum = rollMultipleDice(2);
    cout << "Total: " << playerSum << endl << endl;

    cout << "Comp's roll." << endl;
    int comSum = rollMultipleDice(2);
    cout << "Total: " << comSum << endl << endl;

    if (playerSum > comSum){
        cout << "End of round. Player wins. (+20 points)" << endl << endl;
        return 1;
    }

    if (playerSum == comSum){
        cout << "End of round. Draw." << endl << endl;
        return 0;
    }

    else {
        cout << "End of round. Comp wins." << endl << endl;
        return -1;
    }
}

int shop(int currentScore){
    int playerChoice;

    cout << "🏬 Shop 🏬" << endl;
    cout << "1. Add 5 points (Cost: 5 points)" << endl;
    cout << "2. Add 15 points (Cost: 10 Points)" << endl;
    cout << "3. Exit Shop" << endl << endl;
    
    cout << "Enter your choice: ";
    cin >> playerChoice;
    cout << endl << endl;

    if (playerChoice == 1 && currentScore >= 5) {
        currentScore = currentScore - 5;
        currentScore = currentScore + 5;

        cout << "✅ Purchased +5 points" << endl << endl;
    }

    if (playerChoice == 2 && currentScore >= 10) {
        currentScore = currentScore - 10;
        currentScore = currentScore + 15;

        cout << "✅ Purchased +15 points" << endl << endl;
    }

    else if (playerChoice == 3) {
        cout << "Exiting Shop." << endl << endl;
    }

    if (currentScore < 5){
        cout << "❌ Not enough points." << endl << endl;
    }

    return currentScore;
}

void displayStatistics(int totalRounds, int wins, int draws, int losses, int finalScore){
    cout << "🏆 Game Over 🏆" << endl << endl;

    cout << "Rounds Played: " << totalRounds << endl;
    cout << "Wins: " << wins << " | " << "Draws: " << draws << " | " << "Losses: " << losses << endl;
    cout << " Final Score: " << finalScore << endl << endl;

    cout << "Thanks for playing! 🎊" << endl << endl;
}

int main () 

{
    char playerInput;
    char shopInput;
    int score = 0;
    int rounds = 0;
    int wins = 0, draws = 0, losses = 0;

    srand(time(0));

    cout << "🎲 Welcome to the Dice Battle Game!!! 🎲" << endl << endl;

    cout << "Do you want to play? (y/n): ";
    cin >> playerInput;
    cout << endl << endl;

    while (playerInput != 'n') {
        cout << "Round " << rounds + 1 << endl << endl;

        cout << "Do you want to visit the shop before playing? (y/n): ";
        cin >> shopInput;
        cout << endl << endl;

        if (shopInput == 'y') {
            shop(score);
        }
        
        int result = playRound();

        if (result == 1){
            score = score + 20;
            wins += 1;
        }

        else if (result == 0){
            draws += 1;
        }

        else if (result == -1){
            losses +=1;
        }

        cout << "Current Score: " << score << endl << endl;

        cout << "Do you want play another round? (y/n): ";
        cin >> playerInput;
        cout << endl << endl;

        rounds += 1;
    }

    displayStatistics(rounds, wins, draws, losses, score);
}