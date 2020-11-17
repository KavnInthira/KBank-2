#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

string firstName, lastName;
int customerCode;
double accountBalance;
string codeString;
string balanceString;
string line;

namespace fileReadWrite{
    void readCSV(){ //readfile
        ifstream myFileStream("/Users/kavininthirakot/Git/C/KBank/.vscode/accounts.txt");
        if(!myFileStream.is_open()){
            cout<<"File failed to open"<<endl;
        }
        while(getline(myFileStream, line)){
            stringstream ss(line);
            getline(ss, firstName, ',');
            getline(ss, lastName, ',');
            getline(ss, codeString, ',');
            customerCode = stoi(codeString);
            getline(ss, balanceString, ',');
            accountBalance = stod(balanceString);
            cout<<firstName<<endl;
        }

        myFileStream.close(); //closing txt file when done with method
    }
}