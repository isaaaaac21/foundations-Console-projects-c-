#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "global.h"
using namespace std;


class clsBankClient : public clsPerson
{
private:

    enum enMode { EmptyMode = 0, UpdateMode = 1, addNewMode = 2};
 
    enMode _Mode;

    string _AccountNumber;
    string _PinCode;
    float _AccountBalance;
    bool markForDelete = false; 


    struct sTransInfo;





    static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }
    static void _readClientInfo(clsBankClient& client)
    {
        cout << "Please enter first name : "; 
        client._FirstName = clsInputValidate::readString();
        cout << "Please enter last name  : "; 
        client._LastName = clsInputValidate::readString(); 
        cout << "Please enter Email      : ";
        client._Email = clsInputValidate::readString(); 
        cout << "Please enter Phone      : "; 
        client._Phone = clsInputValidate::readString();
        cout << "Please enter PinCode    : ";
        client._PinCode =  clsInputValidate::readString(); 
        cout << "Please enter account Balance : ";
        client._AccountBalance = stod(clsInputValidate::readString()); 
    }
    static  vector <clsBankClient> _LoadClientsDataFromFile()
    {

        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {

                clsBankClient Client = _ConvertLinetoClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();
        }
        return vClients;

    }
    static string _convertTransferInfoToLine(clsBankClient from, clsBankClient to,int amount, string Seperator = "#//#")
    {
        string result;
        result += clsDate::GetSystemDateTimeString() + Seperator; 
        result += from._AccountNumber + Seperator;
        result += from.AccountNumber() + Seperator;
        result += to_string(from._AccountBalance) + Seperator;
        result += to_string(to.AccountBalance) + Seperator;
        result += to_string(amount) + Seperator;
        result += currentUser.UserName;
        return result; 
    }
    static sTransInfo _convertLineToTransferStruct(string line)
    {
        sTransInfo sti; 
        vector<string> vec = clsString::Split(line, "#//#");

        sti.dateTime = vec.at(0);
        sti.accNum1 = vec.at(1);
        sti.accNum2 = vec.at(2);
        sti.balance1 = vec.at(3);
        sti.balance2 = vec.at(4);
        sti.amount= vec.at(5);
        sti.userName = vec.at(6);
        return sti; 
    }

    


  




    static string _ConverClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {

        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;
    }
    void _saveClientsDataToFile(vector<clsBankClient> clients)
    {
        fstream file; 
        file.open("Clients.txt", ios::out); 
        if (file.is_open())
        {
            for (clsBankClient cl : clients)
            {
                if (cl.markForDelete == false)
                {
                    file << _ConverClientObjectToLine(cl) << endl;
                }
            }
            file.close(); 
        }
    }

    void _update()
    {
        vector <clsBankClient> clients = _LoadClientsDataFromFile(); 
        for (clsBankClient& cl : clients)
        {
            if (cl.AccountNumber() == AccountNumber())
            {
                cl = *this; 
                break; 
            }
        }
        _saveClientsDataToFile(clients); 
    }



     void _saveClientInFile(string line)
    {
        fstream file; 
        file.open("Clients.txt", ios::out | ios::app); 

        if (file.is_open())
        {
          
            file <<line << endl; 
            file.close(); 
        }
    }

      void _addNew()
     {
         _saveClientInFile(_ConverClientObjectToLine(*this)); 
     }



     static clsBankClient _getNewClient(string accountNumber)
     {
         return clsBankClient(addNewMode, "", "", "", "", accountNumber, "", 0); 
     }





     static void _clientListHeader(int vecSize)
     {
         cout << endl << setw(45) << left << " " << setw(10) << left << "Client List : " << left << vecSize << " client(s)." << endl;
         cout << "_____________________________________________________________________________________________________________________\n" << endl; 
         cout << "| " << setw(20) << left << "Accout Number " << "| " << setw(15) << left << "Pin Code";
         cout << "| " << setw(20) << left << "Client Name " << "| " << setw(25) << "Email" << "| " << setw(15) << left << "Phone" << "| Balance" << endl;
         cout << "_____________________________________________________________________________________________________________________\n" << endl; 
     }


     static void _printAllClientsInvector(vector <clsBankClient> vec)
     {
         for (clsBankClient s : vec)
         {
             cout << "| " << setw(20) << left << s.AccountNumber();
             cout << "| " << setw(15) << left << s.PinCode;
             cout << "| " << setw(20) << left << s.FirstName + " " + s.LastName;
             cout << "| " << setw(25) << left << s.Email;
             cout << "| " << setw(15) << left << s.Phone;
             cout << "| " <<int (s._AccountBalance) << endl;
         }
     }








public:

    enum enSaveResult { svFailed = 0, svSucceded = 1 };
    clsBankClient(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string AccountNumber, string PinCode,
        float AccountBalance) :
        clsPerson(FirstName, LastName, Email, Phone)

    {
        _Mode = Mode;
        _AccountNumber = AccountNumber;
        _PinCode = PinCode;
        _AccountBalance = AccountBalance;

    }

    struct sTransInfo
    {
        string dateTime; 
        string accNum1;
        string accNum2;
        string balance1; 
        string balance2; 
        string amount; 
        string userName; 
    };

    static vector <sTransInfo> getTransferInfoFromFile()
    {
        vector <sTransInfo> transLogins;
        fstream file; 
        string line; 
        file.open("transferLogin.txt", ios::in);
        if (file.is_open())
        {
            while (getline(file, line))
            {
                transLogins.push_back(_convertLineToTransferStruct(line)); 
            }
            file.close();
        }
        return transLogins;
    }


    static void saveTransferInfoToFile(clsBankClient from, clsBankClient cl1, int amount)
    {
        fstream file;
        file.open("transferLogin.txt", ios::out | ios::app);
        if (file.is_open())
        {
            file << _convertTransferInfoToLine(from, cl1, amount) << endl;
        }
    }


    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

     string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string GetPinCode()
    {
        return _PinCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }


    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;



    static clsBankClient getNewclient(string accNum)
    {
        return _getNewClient(accNum);
    }
    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " <<int(_AccountBalance);
        cout << "\n___________________\n";

    }

    static vector <clsBankClient> getClientsFromFile()
    {
        return _LoadClientsDataFromFile(); 
    }

    static clsBankClient getEmptyClinet()
    {
        return _GetEmptyClientObject(); 
    }
    static clsBankClient find(string accountNumber)
    {
        fstream file; 
        file.open("Clients.txt", ios::in);
        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                clsBankClient client = _ConvertLinetoClientObject(line);
                if (client.AccountNumber() == accountNumber)
                {
                    file.close(); 
                    return client; 
                }
            }
        }
        return _GetEmptyClientObject(); 
    }
   

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLinetoClientObject(Line);
                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }

            }

            MyFile.close();

        }
        return _GetEmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber)
    {

        clsBankClient Client1 = clsBankClient::find(AccountNumber);
        return (!Client1.IsEmpty());
    }



    enSaveResult save()
    {
        switch (_Mode)
        {
        case EmptyMode:
            return svFailed;

        case UpdateMode:
            _update(); 
            return svSucceded;
        case addNewMode:
            _addNew();
            return svSucceded; 
        default: 
            break; 
        }

    }


    static void updateClient()
    {
        string accNum; 
        cout << "Please enter an account number : ";accNum= clsInputValidate::readString();
        
        while (!IsClientExist(accNum))
        {
            cout << "Account number invalid !!! \nPlease enter another account number : ";
            accNum = clsInputValidate::readString();
        }


        clsBankClient  client = clsBankClient::find(accNum); 
        client.Print(); 

        cout << "Update information : \n___________________________\n"; 

        _readClientInfo(client); 
        clsBankClient::enSaveResult saveResult;

        saveResult = client.save();

        switch (saveResult)
        {
        case clsBankClient::svSucceded:
            cout << "Client has been Updated successfully :-)" << endl; 
            client.Print(); 
            break;
        case clsBankClient::svFailed:
            cout << "The update operation has been failed :-(" << endl;
            break;
        default:
            break;
        }


    }



    static void addNewClient()
    {
        string accNum; cout << "Please Enter account number : "; accNum = clsInputValidate::readString(); 

        while(IsClientExist(accNum))
        {
            cout << "This account number is already exists !!! Please choose another one : "; 
            accNum = clsInputValidate::readString(); 
        }

        clsBankClient newClient = _getNewClient(accNum);

        _readClientInfo(newClient); 
        enSaveResult saveResult; 
        saveResult = newClient.save();

        switch (saveResult)
        {
        case clsBankClient::svSucceded:
            cout << "Client has been added successfully :-)" << endl;
            newClient.Print();
            break;
        case clsBankClient::svFailed:
            cout << "The adding operation has been failed :-(" << endl;
            break;
        default:
            break;
        }
    }



    bool Delete()
    {
        vector <clsBankClient> clients = _LoadClientsDataFromFile(); 

        for (clsBankClient &cl : clients)
        {
            if (cl.AccountNumber() == AccountNumber())
            {
                cl.markForDelete = true; 
                break; 
            }
        }
        _saveClientsDataToFile(clients);
        *this = _GetEmptyClientObject();
        return true; 
    }

    static void deleteClient()
    {
        string accNum; cout << "Please enter an account number : "; accNum = clsInputValidate::readString();

        while (!IsClientExist(accNum))
        {
            cout << "There is no client with such account number... Please choose another one : "; 
            accNum = clsInputValidate::readString(); 
        }

        clsBankClient client = find(accNum); 
        client.Print(); 

        string answer = "n"; 
        cout << "\nAre you sure you want to delete this client ? "; cin >> answer; 


        if (answer == "y" || answer == "Y")
        {
            if (client.Delete())
            {
                cout << "Client has been deleted successfully :-)" << endl; 
                client.Print(); 
            }
            else
            {
                cout << "Client has not been deleted :-(" << endl; 
            }

        }

    }

    static double GetTotalBalances()
    {
        vector <clsBankClient> vClients = clsBankClient::_LoadClientsDataFromFile();

        double TotalBalances = 0;

        for (clsBankClient Client : vClients)
        {

            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;
    }

    static void listClient()
    {
        vector <clsBankClient> clients = _LoadClientsDataFromFile(); 
        _clientListHeader(clients.size()); 
        _printAllClientsInvector(clients); 
    }


    void deposit(int amount)
    {
        _AccountBalance += amount; 
        save();
    }


    bool withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            save();
            return true;
        }

    }


    bool transfer(int amount, clsBankClient& to)
    {
        if (this->AccountBalance < amount)
        {
            return false; 
        }
        
        withdraw(amount); 
        to.deposit(amount);
        save(); 
        return true; 
    }




};