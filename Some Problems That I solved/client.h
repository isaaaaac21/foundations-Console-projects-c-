#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "stringPro.h"

using namespace std; 
struct sclient
{
    string accountNumber;
    string pin;
    string name;
    string phone;
    string balance;
    bool markToUpdate = false; 
};

namespace client
{
    sclient readClient()
    {
        sclient s; 
        cout << "Please Enter Client data : \n\n"; 
        cout << "Enter the acc number     : "; cin >> s.accountNumber; 
        cout << "Enter the PIN number     : "; cin >> s.pin; 
        cout << "Enter the Name           : "; cin >> s.name;
        cout << "Enter the Phone number   : "; cin >> s.phone; 
        cout << "Enter the Balance        : "; cin >> s.balance; 
        return s; 
    }

    string readAccNum()
    {
        string accNum; 
        cout << "Please Enter the account Number : "; cin >> accNum; 
        return accNum; 
    }

    string recordToLine(sclient s, string sep = "#//#")
    {
        string line; 
        line += s.accountNumber + sep; 
        line += s.pin + sep; 
        line += s.name + sep;
        line += s.phone + sep; 
        line += s.balance;
        
        return line;
    }

    sclient lineToRecord(string line, string sep = "#//#")
    {
        vector <string> result = stringPro::spliting(line, sep); 


        sclient s; 
        s.accountNumber = result.at(0); 
        s.pin     = result.at(1); 
        s.name    = result.at(2); 
        s.phone   = result.at(3); 
        s.balance = result.at(4); 

        return s; 
    }

    void printClient(sclient s)
    {
        cout << "The client Data : \n\n"; 
        cout << "Acc number        : " << s.accountNumber << endl;
        cout << "Acc PIN           : " << s.pin << endl; 
        cout << "Acc name          : " << s.name << endl; 
        cout << "Acc phone number  : " << s.phone << endl; 
        cout << "Acc balance       : " << s.balance << endl; 
    }

    vector <sclient> readClientsFromFile(string fileName)
    {
        fstream file; 
        vector <sclient> clients; 
        string line; 

        file.open(fileName, ios::in);

        if (file.is_open())
        {
            while (getline(file, line))
            {
                clients.push_back(lineToRecord(line)); 
            }
        }
        return clients; 
    }

    void saveClientInFile(string fileName, sclient s)
    {
        fstream file; 
        file.open(fileName, ios::out | ios::app);
        if (file.is_open())
        {
            file << recordToLine(s) << endl; 
            file.close(); 
        }
    }
    void saveClientsInfile(string fileName, vector <sclient> vec)
    {
        fstream file;
        file.open(fileName, ios::out); 
        if (file.is_open())
        {
            for (sclient s : vec)
            {
                file << recordToLine(s) << endl; 
            }
            file.close(); 
        }
    }
    void printAllClientsInFile(string fileName)
    {
        string line; 
        vector <sclient> clients = readClientsFromFile(fileName); 
        
        for (sclient s : clients)
        {
            printClient(s); 
            cout << "\n\n===================================\n\n"; 
        }





    }
    

    bool findClient(vector<sclient>& clients, string accNumber)
    {

        string line; 
        for (sclient& sc : clients)
        {
            if (sc.accountNumber == accNumber)
            {
                sc.markToUpdate = true; 
                return true; 
            }
        }
        return false;
    }

    //void deleteClientByAccountNumber(string fileName, string accNumber)
    //{
    //    fstream file;
    //    sclient sc;
    //    char dec = 'y';
    //    if (findClient(fileName, accNumber, sc))
    //    {

    //        cout << "Are u sure to delete it ? : "; cin >> dec;
    //        if (tolower(dec) == 'y')
    //        {
    //            vector <sclient> clients = readClientsFromFile(fileName);
    //            vector <sclient> deleted;
    //            for (sclient s : clients)
    //            {
    //                if (s.accountNumber != sc.accountNumber) deleted.push_back(s);
    //                else
    //                {
    //                    cout << "The following are the Client details : \n" << endl;
    //                    printClient(s);
    //                    cout << "\n\n";
    //                }
    //            }

    //            file.open(fileName, ios::out);
    //            if (file.is_open())
    //            {
    //                for (sclient s : deleted)
    //                {
    //                    saveClientInFile(fileName, s);
    //                }
    //            }
    //            cout << "\n\nThe client has been deleted successfuly\n";
    //        }
    //    }
    //    else cout << "There is no item with such data" << endl; 
    //}

    void updateClientMessage(sclient& s)
    {
        cout << "\n\n";
        cout << "Enter the PIN number     : "; cin >> s.pin;
        cout << "Enter the Name           : "; cin >> s.name;
        cout << "Enter the Phone number   : "; cin >> s.phone;
        cout << "Enter the Balance        : "; cin >> s.balance;
    }

    void UpdateClient(vector<sclient>& clients)
    {
        for (sclient& s : clients)
        {
            if (s.markToUpdate == true)
            {
                updateClientMessage(s); 
                break; 
            }
        }
    }

    void printClientByAccNum(vector <sclient> clients, string accNum)
    {
        for (sclient s : clients)
        {
            if (s.accountNumber == accNum)
            {
                printClient(s);
            }
        }
    }

    void updateClientByAccNum(string fileName, string accNum, vector<sclient>& clients)
    {

        char dec = 'y'; 
        if (findClient(clients, accNum))
        {
            printClientByAccNum(clients, accNum); 
            cout << "\n\nAre you sure you want to update this client ? : "; cin >> dec;
            if (tolower(dec) == 'y')
            {
                UpdateClient(clients); 
            }
            saveClientsInfile(fileName, clients);
            cout << "\n\nClient informations have been updated successfully :-)" << endl; 
        }
        else
        {
            cout << "\n\nClient with account number (" << accNum << ") Not found !!!" << endl; 
        }
         
        


    }

}