#include "func.hpp"
#include "parser.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

//code runner
int main() {

    int choice;
    double moneyIn;
    double moneyOut;
    int initalChoice; // for intial menu questions 
    int userBalance; //will be used to grab data.

    //variable's to search for user account information.
    string fName;
    string lName;
    int sCode;

    int mainLoop = 0; //counter to keep asking options till exit.
    int initLoop = 0; //counter before main to ask questions.

    cout << "\n-----------------------------------\n";
    cout << "     Welcome to Kavin's Bank!\n";
    cout << "-----------------------------------\n\n";

    //getting vistor information to proceed with asking the right questions and giving the write info.
    cout << "To provide you with the best experience.. \n" << endl;
    cout << "Please enter your first name: ";
    cin >> fName;
    cout << "\nPlease enter your last name: ";
    cin >> lName;
    cout << endl;
    cout << "Thank you, "<< fName << "!" << "\n" << endl;

    cout << "How can I help you today?" << endl;
    cout << "[Enter: 1] To open an account" << endl;
    cout << "[Enter: 2] To access your account" << endl;
    cin >> initalChoice;

    while(initLoop < 1) {
        if(initalChoice == 1){
            cout << "Great, lets create a numerical passcode: ";
            cin >> sCode;
            cout << "Don't forget to write this down so you'll be able to access your account later.\n" << endl;
            initLoop++;
        } else if (initalChoice == 2) {
            cout << "Please enter your account numerical security code: ";
            cin >> sCode;
            initLoop++;
        } else {
            cout << "\n";
            cout << "That is not a choice.. please try again. \n" << endl;
            cout << "[Enter: 1] To open an account" << endl;
            cout << "[Enter: 2] To access your account" << endl;
            cin >> initalChoice;
        }
    }
    
    //reading file to check if account exits with name and security code.
    while(mainLoop < 1) {
        cout << "\n";
        cout << "[Enter: 1] Deposit "<< endl;
        cout << "[Enter: 2] Withdraw "<< endl;
        cout << "[Enter: 3] Check Balance" << endl;
        cout << "[Enter: 4] Exit\n " << endl;

        cout << "Enter Choice: ";
        cin >> choice;
    
        if(choice == 1){ // deposit
            cout << "Please enter the amount you would like to deposit:  " ;
            cin >> moneyIn;
            func::deposit(moneyIn);
            } 

        if(choice == 2){ //widthdraw
            cout<< "Please enter the amount you would like to withdraw: ";
            cin >> moneyOut;
            func::widthdraw(moneyOut);
        }
        if(choice == 3){ //checkbalance
            func::checkbalance();
        } 
            
        if(choice == 4){
            func::exit();
            mainLoop++;
        }
            
    } 
    return 0;
}
