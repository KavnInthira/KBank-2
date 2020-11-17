#include <iostream>
#include <iomanip>
using namespace std;

double currentBalance = 0.00;

namespace func {
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
}