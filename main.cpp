#include "func.hpp"
#include "parser.hpp"
#include <iostream>
#include <iomanip>
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

    //INITIAL QUESTIONS: getting vistor information to proceed with asking the right questions and giving the write info.
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
            cout << "Please create a numerical passcode: ";
            cin >> sCode;
            //TODO: check if accont exits ask user to use a different numerical code.
            //TODO: calls functions to check for user pass and code in other user so that there are not two of the same accounts.
            //TODO: if fucntion comes back false then account is then created and written in accounts.txt
                if(fileReadWrite::readCSV(fName,lName,sCode) == true) {
                    cout << "" << endl;
                    cout << "Error: Please try a different passcode..\n" << endl;
                    } else {
                        cout << "\n" << endl;             
                        cout << "Don't forget to write this down so you'll be able to access your account later.\n" << endl;

                        //TODO: need to add function to write file to note.
                        fileReadWrite::newAccount(fName,lName,sCode,0.00);
                        func::removeRename();
                        initLoop++;
                    }
        } else if (initalChoice == 2) {
            cout << "Please enter your account numerical security code: ";
            cin >> sCode;

            if(fileReadWrite::readCSV(fName,lName,sCode) == true){
                cout << "" << endl;
                cout<< "Account Has been found! " << endl;
                userBalance = fileReadWrite::getBalance();
                initLoop++;
            } else {
                cout << "" << endl;
                cout << "Error: Account not found, please try again..\n" << endl;
                }
        } else {
            cout << "\n";
            cout << "That is not a choice.. please try again. \n" << endl;
            cout << "[Enter: 1] To open an account" << endl;
            cout << "[Enter: 2] To access your account" << endl;
            cin >> initalChoice;
        }
    }
    //MAIN QUESTIONS!!!
    while(mainLoop < 1) {
        cout << "\n";
        cout << "[Enter: 1] Deposit "<< endl;
        cout << "[Enter: 2] Withdraw "<< endl;
        cout << "[Enter: 3] Check Balance" << endl;
        cout << "[Enter: 4] Exit and Save Changes\n " << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        if(choice == 1){ // deposit
            cout << "Please enter the amount you would like to deposit:  " ;
            cin >> moneyIn;
            userBalance = func::deposit(userBalance,moneyIn);
            } 
        if(choice == 2){ //widthdraw
            cout<< "Please enter the amount you would like to withdraw: ";
            cin >> moneyOut;
            userBalance = func::widthdraw(userBalance,moneyOut);
        }
        if(choice == 3){ //checkbalance
            func::checkbalance(userBalance);
        }                       
        if(choice == 4){
            fileReadWrite::accountRewrite(fName, lName, sCode, userBalance);
            func::removeRename();
            mainLoop++;
        }
    } 
    return 0;
}


