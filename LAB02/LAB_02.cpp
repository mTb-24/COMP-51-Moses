#include<iostream>
using namespace std;
int main () 

{
    double curBalance = 1000.00;
    int numChoice;
    double newDep;
    double newWit;
    
    cout<<"Welcome to the Simple ATM"<<endl;

    cout<<endl<<"Your current balance is: $"<<curBalance<<endl;

    cout<<endl<<"Menu:"<<endl;
    cout<<"1. Check Balance"<<endl<<"2. Deposit Money"<<endl<<"3. Withdraw Money"<<endl<<"4. Exit";

    cout<<endl<<endl;

    while (numChoice <= 4) {
        cout<<"Enter your choice: ";
        cin>>numChoice;

        if (numChoice == 1) {
            cout<<"Your current balance is: $"<<curBalance<<endl<<endl;
        }
        else if (numChoice == 2) {
            cout<<"Enter the amount to deposit: ";
            cin>>newDep;
            curBalance = curBalance + newDep;
            cout<<"Deposit successful!";
            cout<<" Your new balance is: $"<<curBalance<<endl<<endl;
        }
        else if (numChoice == 3) {
            cout<<"Enter the amount to withdraw: ";
            cin>>newWit;
            if (newWit < curBalance) {
                curBalance = curBalance - newWit;
                cout<<"Withdrawal successful!"<<" Your new balance is: $"<<curBalance;
                cout<<endl<<endl;
            }
            else {
                cout<<"Insufficient funds."<<endl<<endl;
            }
        }
        else if (numChoice == 4) {
            cout<<"Thank you for using the ATM. Goodbye!"<<endl;
                break;
        }
    }

}