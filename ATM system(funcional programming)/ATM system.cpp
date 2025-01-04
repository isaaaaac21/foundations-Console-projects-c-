#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include "headers.h"
using namespace std;

string clientFile = "F:\\programming\\Fundamentals\\JUST PRACTICE\\Projects\\Bank project\\Clients Project.txt"; 
enum enATMOptions {eQuickWith = 1, eNormalWith = 2, eDeposite = 3, eCheckBalance = 4, eLogout = 5 };
struct sclient
{
    string accountNumber;
    string pin;
    string name;
    string phone;
    int balance;
};
sclient currentClient;
void newLines()
{
    cout << "\n\n"; 
}
void customPause()
{
    newLines(); 
    cout << "Press any key to go back...";
    _getch(); 
}
void ATMmainMenuScreen(); 
void performATMOptions(enATMOptions choice); 

//reading :
enATMOptions readOption()
{
    int choice; cout << "Choose what do you want to do [1 to 5] : "; cin >> choice; 
    return (enATMOptions)choice; 
}
string readAccNum()
{
    string accNum; cout << "Enter account number : "; cin >> accNum; 
    return accNum; 
}
string readPin()
{
    string pin; cout << "Enter PIN : "; cin >> pin;
    return pin;
}
int readNormalAmount(enATMOptions option)
{
   int amount; 
   if (option == eNormalWith)
   {
       do
       {
           cout << "Enter an amount multiple of 5's : "; cin >> amount;
           cout << endl;
       } while (amount % 5 != 0);
   }
   else
   {
       cout << "Enter a positive deposite amount : "; cin >> amount; 
   }
    return amount; 
}
int readQuickChoice()
{
    short choice; 
    cout << "choose what to withdraw from 1 to 8 : "; cin >> choice; 
    switch (choice)
    {
    case 1 : return 20;
    case 2 : return 50;
    case 3 : return 100;
    case 4 : return 200;
    case 5 : return 400;
    case 6 : return 600;
    case 7 : return 800;
    case 8 : return 1000;
    case 9 :ATMmainMenuScreen(); 
    default:
        break;
    }
}
//Previous functions : 
sclient lineToRecord(string line)
{
    sclient s;
    vector <string> result = stringing::spliting(line, "#//#");
    s.accountNumber = result.at(0);
    s.pin = result.at(1);
    s.name = result.at(2);
    s.phone = result.at(3);
    s.balance = stoi(result.at(4));
    return s;
}
string recordToLine(sclient s, string sep = "#//#")
{
    string line;
    line += s.accountNumber + sep;
    line += s.pin + sep;
    line += s.name + sep;
    line += s.phone + sep;
    line += to_string(s.balance);
    return line;
}
vector <sclient> loadClientsFromFile(string fileName)
{
    fstream file;
    string line;
    vector <sclient> clients;
    file.open(fileName, ios::in);

    if (file.is_open())
    {
        while (getline(file, line))  clients.push_back(lineToRecord(line));
        file.close();
    }
    return clients;
}
bool findClientByAccNumAndPin(vector <sclient> clients, string accNum, string pin, sclient& cl)
{
    for (sclient s : clients)
    {
        if (s.accountNumber == accNum && s.pin == pin)
        {
            cl = s;
            return true;
        }
    }
    return false; 
}
void updateClientInfo(vector <sclient>& clients, sclient updated)
{
    for (sclient& s : clients) if (s.accountNumber == updated.accountNumber) s = updated; 
}
void saveClientInFile(string& fileName, sclient s)
{
    fstream file;
    string line = recordToLine(s);
    file.open(fileName, ios::out | ios::app);
    if (file.is_open())
    {
        file << line << endl;
        file.close();
    }
}
void saveVecClientsInFile(string fileName)
{
    fstream file;
    vector <sclient> clients = loadClientsFromFile(fileName); 
    updateClientInfo(clients, currentClient); 
    file.open(fileName, ios::out);
    if (file.is_open())
    {
        for (sclient s : clients)
        {
            saveClientInFile(fileName, s);
        }
        file.close();
    }
}
//screens 
void ATMmainMenuScreen()
{
    system("cls");
    cout << setw(30) << left << "_________________________________\n" << endl;
    cout << setw(7) << left << " " << setw(23) << "ATM Main Menu Screen" << endl;
    cout << setw(30) << left << "_________________________________" << endl << endl;
    cout << setw(10) << left << " " << setw(20) << "[1] Quick withdraw." << endl;
    cout << setw(10) << left << " " << setw(20) << "[2] Normal withdraw." << endl;
    cout << setw(10) << left << " " << setw(20) << "[3] Deposit." << endl;
    cout << setw(10) << left << " " << setw(20) << "[4] Check balance." << endl;
    cout << setw(10) << left << " " << setw(20) << "[5] Logout." << endl;
    cout << setw(30) << left << "_________________________________" << endl;
    performATMOptions(readOption()); 
}
void login()
{
    header::loginHeader(); 
    vector <sclient> clients = loadClientsFromFile(clientFile); 
    string accNum = readAccNum(); 
    string pin = readPin(); 
    while (!findClientByAccNumAndPin(clients, accNum, pin, currentClient))
    {
        cout << "Invalid Account number / Pin, please try again : " << endl << endl;
        accNum = readAccNum();
        pin = readPin();
    }
    ATMmainMenuScreen(); 
}
void goBackToATMScreen()
{
    customPause(); 
    ATMmainMenuScreen(); 
}

//New Functions
bool performTransaction()
{
    char dec; 
    cout << "\nAre you sure you want to perform this transaction ? Y/N  "; cin >> dec; 
    cout << endl;
    if (tolower(dec) == 'y') return true; 
    return false; 
}
bool amountExceed(int amount, sclient sc)
{
    if (amount == -1) return true;
    if (amount > sc.balance)
    {
        cout << "\nYou don't have this amount of money in your account to withdraw!!!" << endl;
        return true; 
    }
    return false; 
}
void normalWithDraw()
{
    header::normalWithDrawScreen(); 
    int amount = readNormalAmount(eNormalWith);
    if (amountExceed(amount, currentClient)) return; 
    if (performTransaction())
    {
        currentClient.balance -= amount;
        saveVecClientsInFile(clientFile);
        cout << "\nwithdraw operation has been done successfully." << endl << endl;
        cout << "New balance is : " << currentClient.balance << endl;
    }
}
void quickWithdraw()
{
    header::quickWithdrawScreen();  cout << "the account balance : " << currentClient.balance << endl; 
    int amount = readQuickChoice();
    if (amountExceed(amount, currentClient)) return; 
    if ( performTransaction())
    {
        currentClient.balance -= amount; 
        saveVecClientsInFile(clientFile); 
        cout << "\Quick Withdraw operation has been done successfully :-)" << endl << endl; 
        cout << "New balance is : " << currentClient.balance << endl; 
    }
}
void deposite()
{
    header::depositeScreen(); 
    int amount = readNormalAmount(eDeposite);
    if (performTransaction())
    {
        currentClient.balance += amount; 
        saveVecClientsInFile(clientFile); 
        cout << "Deposite operation has been done successfully :-)" << endl << endl; 
        cout << "New balance is : " << currentClient.balance << endl; 
    }
}
void checkBalance()
{
    header::checkBalanceScreen(); 
    cout << "Your balance is : " << currentClient.balance << endl; 
}

void performATMOptions(enATMOptions choice)
{
    switch (choice)
    {
    case eQuickWith:
        quickWithdraw();
        goBackToATMScreen(); 
        break;
    case eNormalWith:
        normalWithDraw();
        goBackToATMScreen();
        break;
    case eDeposite:
        deposite();
        goBackToATMScreen();
        break;
    case eCheckBalance:
        checkBalance(); 
        goBackToATMScreen(); 
        break;
    case eLogout:
        login(); 
        break;
    default:
        break;
    }
}
int main()
{
    login(); 
}

