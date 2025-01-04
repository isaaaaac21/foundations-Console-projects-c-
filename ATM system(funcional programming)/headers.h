#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std; 



namespace header
{
	void loginHeader()
	{
		system("cls");
		cout << setw(30) << left << "_________________________________\n" << endl;
		cout << setw(10) << left << " " << setw(20) << "Login Screen" << endl;
		cout << setw(30) << left << "_________________________________" << endl;
	}




    void normalWithDrawScreen()
    {
        system("cls");
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(5) << left << " " << setw(20) << "Normal Withdraw Screen" << endl;
        cout << setw(30) << left << "_________________________________" << endl << endl;
    }

    void quickWithdrawScreen()
    {
        system("cls");
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(5) << left << " " << setw(20) << "Quick WithDraw Screen" << endl;
        cout << setw(30) << left << "_________________________________" << endl << endl;
        cout << setw(5) << left << " " << setw(10) << "[1] 20" << setw(5) << left << " " <<  setw(10) << left <<  "[2] 50" << endl;
        cout << setw(5) << left << " " << setw(10) << "[3] 100" << setw(5) << left << " " <<  setw(10) << left <<  "[4] 200" << endl;
        cout << setw(5) << left << " " << setw(10) << "[5] 400" << setw(5) << left << " " <<  setw(10) << left <<  "[6] 600" << endl;
        cout << setw(5) << left << " " << setw(10) << "[7] 800" << setw(5) << left << " " <<  setw(10) << left <<  "[8] 1000" << endl;
        cout << setw(12) << left << " " << "[9] Exit" << endl; 
        cout << setw(30) << left << "_________________________________" << endl << endl;
    }

    void depositeScreen()
    {
        system("cls");
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(10) << left << " " << setw(20) << "Deposite Screen" << endl;
        cout << setw(30) << left << "_________________________________" << endl << endl;
    }

    void checkBalanceScreen()
    {
        system("cls");
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(10) << left << " " << setw(20) << "Check balance Screen" << endl;
        cout << setw(30) << left << "_________________________________" << endl;
    }
}

namespace stringing
{
    vector <string> spliting(string s, string delimeter = " ") //I live in algeria, do you know algeria ?
    {

        vector <string> result;
        int pos = 0;
        string word;

        while ((pos = s.find(delimeter)) != string::npos)
        {
            word = s.substr(0, pos);
            if (word != " ") result.push_back(word);
            s.erase(0, pos + delimeter.length());
        }
        if (!s.empty()) result.push_back(s);
        return result;
    }
}