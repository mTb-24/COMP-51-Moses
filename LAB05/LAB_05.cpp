#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Car {
    public:
    string make, model;
    int year;
    int originalPrice = 10000;
    int currentPrice = 10000;
    bool isOwned = false;

    string getCarInfo(){
        return year + " " + make + " " + model;
    }

    bool buyCar(double &userMoney) {
        if(!isOwned && (userMoney >= currentPrice)){
            isOwned = true;
            userMoney = userMoney - currentPrice;
            currentPrice = currentPrice - (0.1 * originalPrice);
            return true;
        }
        else {
            return false;
        }
    }

    bool sellCar(double &userMoney){
        if(isOwned){
            isOwned = false;
            userMoney = userMoney + originalPrice;
            currentPrice = currentPrice - (0.1 * originalPrice);
            return true;
        }
        else{
            return false;
        }
        
    }

    void reducePriceByTenPercentOfOriginal(){
        currentPrice = currentPrice - (0.1 * originalPrice);
        if (currentPrice < 0){
            currentPrice = 0;
        }
    }
};

int main(){
    srand(static_cast<unsigned>(time(nullptr)));

    double userMoney = 100000;

    Car car1;
    car1.make = "Chevrolet";
    car1.model = "Suburban";
    car1.year = 2022;
    car1.currentPrice;

    Car car2;
    car2.make = "Tesla";
    car2.model = "Model S";
    car2.year = 2023;
    car2.currentPrice;

    Car car3;
    car3.make = "Audi";
    car3.model = "R8";
    car3.year = 2018;
    car3.currentPrice;

    for(int i = 1; i <= 10; i++){
        cout << endl;
        cout << "--- Transaction " << i << " ---" << endl;

        int carIndex = rand() % 3;

        int action = rand() % 2;

        if (carIndex == 0) {
            if (action == 0){
                car1.buyCar(userMoney);
                cout << "Bought " << car1.getCarInfo() << " for $" << car1.originalPrice << "." << endl;
            }
            else {
                car1.sellCar(userMoney);
                cout << "Sold " << car1.getCarInfo() << " for $" << car1.currentPrice << "." << endl;
            }
        }
        if (carIndex == 1){
            if (action == 0){
                car2.buyCar(userMoney);
                cout << "Bought " << car2.getCarInfo() << " for $" << car2.originalPrice << "." << endl;
            }
            else {
                car2.sellCar(userMoney);
                cout << "Sold " << car2.getCarInfo() << " for $" << car2.currentPrice << "." << endl;
            }
        }
        else{
            if (action == 0){
                car3.buyCar(userMoney);
                cout << "Bought " << car3.getCarInfo() << " for $" << car3.originalPrice << "." << endl;
            }
            else {
                car3.sellCar(userMoney);
                cout << "Sold " << car3.getCarInfo() << " for $" << car3.currentPrice << "." << endl;
            }
        }
        cout << "User Balance: $" << userMoney << endl;
    }
    cout << endl;

    cout << "--- Final Report After 10 Transactions ---" << endl;
    cout << "User final balance: $" << userMoney << endl;
    cout << "Car 1: " << car1.getCarInfo() << endl;
    cout << "   Original Price: $" << car1.originalPrice << endl;
    cout << "   Current Price: $" << car1.currentPrice << endl;
    cout << "   Currently Owned? ";
    if (car1.isOwned){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    cout << endl;

    cout << "Car 2: " << car2.getCarInfo() << endl;
    cout << "   Original Price: $" << car2.originalPrice << endl;
    cout << "   Current Price: $" << car2.currentPrice << endl;
    cout << "   Currently Owned? ";
    if (car2.isOwned){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    cout << endl;

    cout << "Car 3: " << car3.getCarInfo() << endl;
    cout << "   Original Price: $" << car3.originalPrice << endl;
    cout << "   Current Price: $" << car3.currentPrice << endl;
    cout << "   Currently Owned? ";
    if (car3.isOwned){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    cout << endl;
}