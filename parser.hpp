
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

double balance = 0.00;

namespace fileReadWrite{
    bool readCSV(string first, string last, int code){ //readfile
        ifstream myFileStream("accounts.txt");
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

                if(firstName == first && lastName == last && customerCode == code){
                    balance = accountBalance;
                    return true; //for function getting the write customer code.
                } 
        }
        return false;
        myFileStream.close(); //closing txt file when done with method
    }
    double getBalance(){
        return balance;
    }
    void accountRewrite(string first, string last, int code, double bal){
        ifstream myFileStream;
        ofstream myfile;

        myFileStream.open("accounts.txt"); 
        myfile.open ("accountTemp.txt");
            if(!myfile.is_open() || !myFileStream.is_open()){
                cout<<"a file failed to open"<<endl;
            } 
        while(getline(myFileStream, line)){
            stringstream ss(line);
            getline(ss, firstName, ',');
            getline(ss, lastName, ',');
            getline(ss, codeString, ',');
            customerCode = stoi(codeString);
            getline(ss, balanceString, ',');
            accountBalance = stod(balanceString);

                if(firstName == first && lastName == last && customerCode == code){
                    myfile << firstName << "," << lastName << "," << customerCode << "," << bal << endl;
                } else {
                    myfile << line << endl;
                }
        }
        myFileStream.close();
        myfile.close();
    }
    void newAccount(string first, string last, int code, double bal) {
        ifstream myFileStream;
        ofstream myfile;

        myFileStream.open("accounts.txt"); 
        myfile.open ("accountTemp.txt");
            if(!myfile.is_open() || !myFileStream.is_open()){
                cout<<"a file failed to open"<<endl;
            } 
        while(getline(myFileStream, line)){
            stringstream ss(line);
            getline(ss, firstName, ',');
            getline(ss, lastName, ',');
            getline(ss, codeString, ',');
            customerCode = stoi(codeString);
            getline(ss, balanceString, ',');
            accountBalance = stod(balanceString);

            myfile << line << endl;
        }
        myfile << first << "," << last << "," << code << "," << bal << endl;
        myFileStream.close();
        myfile.close();
    }

}