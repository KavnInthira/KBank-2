#include <iostream>
#include <iomanip>
using namespace std;

//global variables
double currentBalance = 0.00;

//methods
void deposit(double moneyIn){
    currentBalance = currentBalance + moneyIn;
    cout<<"Transaction Complete!\n";
}
void widthdraw(double moneyOut){
    if(moneyOut < currentBalance){
        cout<<"Error, Insufficent funds! Please add more funds to your account.\n";
    } else {
        currentBalance = currentBalance - moneyOut;
        cout<<"Transaction Complete!\n";
    }
}
void checkbalance(){
    cout<<"Current Balance: " << "$" << fixed << setprecision(2) << currentBalance << "\n\n";
}
void exit(){
    cout << "-----------------------------------\n";
    cout << " Thanks for visiting Kavin's Bank!\n";
    cout << "-----------------------------------\n\n";
}

//code runner
int main() {

    int choice;
    double moneyIn;
    double moneyOut;
    int x = 0; //counter to keep asking options till exit.

    cout << "-----------------------------------\n";
    cout << "     Welcome to Kavin's Bank!\n";
    cout << "-----------------------------------\n\n";

    while(x < 1) {
        x = 0;
        cout << "Please enter the number corresponding to the options below.\n";
        cout << "[Enter: 1] Deposit\n";
        cout << "[Enter: 2] Withdraw\n";
        cout << "[Enter: 3] Check Balance\n";
        cout << "[Enter: 4] Exit\n\n";

        cout << "Enter Choice: ";
        cin >> choice;
    
        if(choice == 1){ // deposit
            cout << "Please enter the amount you would like to deposit:  ";
            cin >> moneyIn;
            deposit(moneyIn);
            } 

        if(choice == 2){ //widthdraw
            cout<< "Please enter the amount you would like to withdraw: ";
            cin >> moneyOut;
            widthdraw(moneyOut);
        }
        if(choice == 3){ //checkbalance
            checkbalance();
        } 
            
        if(choice == 4){
            x++;
        }
            
    }
}
