#include<iostream>
using namespace std;
int main () 

{
    int temperature;
    double budget;
    int weatherCode;

    cout<<"Input the current temperature: ";
    cin>>temperature;
    cout<<endl;

    cout<<"Input your available budget: $";
    cin>>weatherCode;
    cout<<endl;

    cout<<"Input the current weather(Sunny = 1, Rainy = 2, Cloudy = 3): ";
    cin>>budget;
    cout<<endl;

    cout<<"The current temperature: "<<temperature<<endl;

    cout<<"Your budget: "<<budget<<endl;

    cout<<"The current weather condition: "<<weatherCode<<endl;

    cout<<endl<<"Your Recommendation:"<<endl;

    if ((weatherCode == 1)&&(temperature > 75)) {
        if (budget > 20) {
            cout<<"Go to the beach!";
        }
        else {
            cout<<"Have a picnic";
        }
    }

    if (weatherCode == 2) {
        if (budget > 15) {
            cout<<"Go to a museum."<<endl;
        }
        else {
            cout<<"Watch a movie at home."<<endl;
        }
    }

    if ((weatherCode == 3)||(temperature < 60)) {
        cout<<"Visit a coffee shop."<<endl;
    }

    return 0;
}