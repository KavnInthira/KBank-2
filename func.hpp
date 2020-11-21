#include <iostream>
#include <iomanip>
using namespace std;

namespace func {
    void deposit(double currentBalance, double moneyIn){
        
        currentBalance = currentBalance + moneyIn;
        cout<<"Transaction Complete!\n";
    }
    void widthdraw(double currentBalance,double moneyOut){
        if(moneyOut < currentBalance){
            cout<<"Error, Insufficent funds! Please add more funds to your account.\n";
        } else {
            currentBalance = currentBalance - moneyOut;
            cout<<"Transaction Complete!\n";
        }
    }
    void checkbalance(double currentBalance){
        cout<<"Current Balance: " << "$" << fixed << setprecision(2) << currentBalance << "\n\n";
    }
    void exit(){
        cout << "-----------------------------------\n";
        cout << " Thanks for visiting Kavin's Bank!\n";
        cout << "-----------------------------------\n\n";
    }
}