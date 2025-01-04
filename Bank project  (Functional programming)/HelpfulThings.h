#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std; 

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
namespace headers
{
    void newLines()
    {
        cout << "\n\n";
    }
    void longLine()
    {
        cout << setw(100) << left << "________________________________________________________________________________________________________________________\n" << endl; 
    }
    void clientListHeader(int vecSize)
    {
        cout << endl << setw(45) << left << " " << setw(10) << left << "Client List : " << left << vecSize << " client(s)." << endl;
        longLine(); 
        cout << "| " << setw(20) << left << "Accout Number " << "| " << setw(15) << left << "Pin Code";
        cout << "| " << setw(40) << left << "Client Name " << "| " << setw(15) << left << "Phone" << "| Balance" << endl;
        longLine();
    }

    void clientList()
    {

    }
    void adding()
    {
        system("cls");
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(7) << left << " " << setw(23) << "Adding New client " << endl;
        cout << setw(30) << left << "_________________________________" << endl;
        cout << "\n" << setw(30) << left << "Adding New Client : \n" << endl; 
    }

    void balanceHeader(int vecSize)
    {
        system("cls");
        cout << endl << setw(45) << left << " " << setw(10) << left << "Balance List : " << left << vecSize << " client(s)." << endl;
        longLine();
        cout << "| " << setw(20) << left << "Accout Number " ;
        cout << "| " << setw(40) << left << "Client Name "  << "| Balance" << endl;
        longLine();
    }

    void deleting()
    {
        system("cls");
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(7) << left << " " << setw(23) << "Deleting client Screen" << endl;
        cout << setw(30) << left << "_________________________________" << endl;
    }
    void updateHeader()
    {
        system("cls");
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(7) << left << " " << setw(23) << "Update client Screen" << endl;
        cout << setw(30) << left << "_________________________________" << endl;
    }

    void findHeader()
    {
        system("cls");
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(7) << left << " " << setw(23) << "Find client Screen" << endl;
        cout << setw(30) << left << "_________________________________" << endl;
    }

    void transactionHeader()
    {
        system("cls");
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(7) << left << " " << setw(23) << "Transaction Menu Screen" << endl;
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(10) << left << " " << setw(20) << "[1] Deposite." << endl;
        cout << setw(10) << left << " " << setw(20) << "[2] Withdraw." << endl;
        cout << setw(10) << left << " " << setw(20) << "[3] Total Balances." << endl;
        cout << setw(10) << left << " " << setw(20) << "[4] Main Menu." << endl;
        cout << setw(30) << left << "_________________________________\n" << endl;

     }
    void depositHeader()
    {
        system("cls");
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(7) << left << " " << setw(23) << "Deposit Screen" << endl;
        cout << setw(30) << left << "_________________________________" << endl;
    }
    void withDrawHeader()
    {
        system("cls");
        cout << setw(30) << left << "_________________________________\n" << endl;
        cout << setw(7) << left << " " << setw(23) << "WithDraw Screen" << endl;
        cout << setw(30) << left << "_________________________________" << endl;
    }

}
namespace helping
{
    struct sclient
    {
        string accountNumber;
        string pin;
        string name;
        string phone;
        int balance;
    };

    void readClient(sclient& s)
    {

        cout << "Enter the PIN number            : "; cin >> s.pin;
        cout << "Enter the Name                  : "; getline(cin >> ws, s.name); 
        cout << "Enter the Phone number          : "; cin >> s.phone;
        cout << "Enter the Balance               : "; cin >> s.balance;

    }

    string readAccNum()
    {
        string accNum;
        cout << "\nPlease Enter the account Number : "; cin >> accNum;
        return accNum;
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

    void printClient(sclient s)
    {
        cout << "\nThe Following are the client Details : " << endl;
        cout << setw(30) << left << "_________________________________\n" << endl;

        cout << "Acc number        : " << s.accountNumber << endl;
        cout << "Acc PIN           : " << s.pin << endl;
        cout << "Acc name          : " << s.name << endl;
        cout << "Acc phone number  : " << s.phone << endl;
        cout << "Acc balance       : " << s.balance << endl;
        cout << setw(30) << left << "_________________________________\n" << endl;

    }

    vector <sclient> loadClientsFromFile(string fileName)
    {
        fstream file; 
        string line; 
        vector <sclient> clients; 
        file.open(fileName, ios::in);

        if (file.is_open())
        {
            while (getline(file, line))
            {
                clients.push_back(lineToRecord(line)); 
            }
            file.close(); 
        }
        return clients; 
    }

    bool findAcc(vector <sclient>& clients, string accNum)
    {
        for (sclient& s : clients)
        {
            if (s.accountNumber == accNum)
            {
                return true;
            }
        }
        return false; 
    }
    bool findAcc(vector <sclient>& clients, string accNum, sclient& sc)
    {
        for (sclient& s : clients)
        {
            if (s.accountNumber == accNum)
            {
                sc = s; 
                return true;
            }
        }
        return false;
    }

    void updateMessage(sclient& s)
    {
        cout << "Enter the PIN number            : "; cin >> s.pin;
        cout << "Enter the Name                  : "; getline(cin >> ws, s.name);
        cout << "Enter the Phone number          : "; cin >> s.phone;
        cout << "Enter the Balance               : "; cin >> s.balance;
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
    void saveVecClientsInFile(vector <sclient> clients, string& fileName)
    {
        fstream file; 
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
    void findAccountToUpdate(vector <sclient>& clients, string accNum, string& fileName)
    {
        char up = 'y';
         for (sclient& s : clients)
        {
            if (s.accountNumber == accNum)
            {
                printClient(s); 
                cout << "\nAre you sure to update this client ? Y/N : "; cin >> up;
                if (tolower(up) == 'y')
                {
                    updateMessage(s);
                    saveVecClientsInFile(clients, fileName); 
                    cout << "\n\nThe client has been updated successfully" << endl;
                }
            }
        }
    }
    void printAllClientsInvector(vector <sclient> vec)
    {
        for (sclient s : vec)
        {
            cout << "| " << setw(20) << left << s.accountNumber;
            cout << "| " << setw(15) << left << s.pin;
            cout << "| " << setw(40) << left << s.name;
            cout << "| " << setw(15) << left << s.phone;
            cout << "| " << s.balance << endl;
        }
    }

    void deletingClient(vector <sclient>& clients, string accNum, string &fileName)
    {
        if (findAcc(clients, accNum))
        {
                vector <sclient> deleted;
                 char del;
                for (sclient s : clients)
                {
                    if (s.accountNumber != accNum) deleted.push_back(s);
                    else  printClient(s);

                }
                cout << "Are you sure do you want to delete this client ? Y/N "; cin >> del; 
                if (tolower(del) == 'y')
                {

                    saveVecClientsInFile(deleted, fileName);
                    clients = deleted;

                    headers::newLines();
                    cout << "Client deleted successfully" << endl;
                }
            
        }
        else
        {
            cout << "Client with account Number (" << accNum << ") not found !!!" << endl;
        }

    }

    void updatingClient(vector <sclient>& clients, string fileName)
    {
        sclient sc; 
        string accNum = readAccNum();
        if (findAcc(clients, accNum, sc))
        {
            findAccountToUpdate(clients, accNum, fileName); 
        }
        else
        {
            cout << "\n\nthere is no client with such number !!! " << endl; 
        }

    }
    void addMoney(sclient& sc)
    {
        int amount; 
        char dec = 'y'; 
        cout << "Please Enter deposite amount : "; cin >> amount;headers::newLines(); 
        cout << "Are you sure you want perform this transaction ? Y/N "; cin >> dec; 
        if (dec == 'y')
        {
            sc.balance += amount; 
            cout << "\nDeposite operation has been done successfully." << endl;
        }
    }
    void withDraw(sclient& sc)
    {
        int amount;
        char dec = 'y';
        cout << "Please Enter withdraw amount : "; cin >> amount; headers::newLines();
        if (amount > sc.balance)
        {
            cout << "You don't have this amount of money in your account to withdraw!!!" << endl;
            return;
        }
        cout << "Are you sure you want perform this transaction ? Y/N "; cin >> dec;
        if (dec == 'y')
        {
            sc.balance -= amount;
            cout << "withdraw operation has been done successfully." << endl;
        }
    }
    void depositingAndWithDraw(string fileName, int num)
    {
        num == 1 ? headers::depositHeader() : headers::withDrawHeader(); 

        string accNum = readAccNum();

        vector <sclient> clients = loadClientsFromFile(fileName);

        while (!findAcc(clients, accNum))
        {
            cout << "There is no Client with [" << accNum << "] Number, Enter another number : "; cin >> accNum;
        }

        for (sclient& s : clients)
        {
            if (s.accountNumber == accNum)
            {
                printClient(s);
                num == 1 ? addMoney(s) : withDraw(s); 
            }
        }
        saveVecClientsInFile(clients, fileName);

    }
    void totalBlance(string fileName)
    {
        int totalBalance = 0; 
        vector <sclient> clients = loadClientsFromFile(fileName);
        headers::balanceHeader(clients.size());
        for (sclient s : clients)
        {
            cout << "| " << setw(20) << left << s.accountNumber;
            cout << "| " << setw(40) << left << s.name;
            cout << "| " << s.balance << endl;
            totalBalance += s.balance; 
        }

        headers::newLines(); 
        cout << "Total balance : " << totalBalance << endl;
    }
}