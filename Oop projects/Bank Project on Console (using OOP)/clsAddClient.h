#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std; 


class clsAddClient : protected clsScreen
{
    static void readClientInfo(clsBankClient& client)
    {
        cout << "Please enter first name : ";
        client.FirstName = clsInputValidate::readString();
        cout << "Please enter last name  : ";
        client.LastName = clsInputValidate::readString();
        cout << "Please enter Email      : ";
        client.Email = clsInputValidate::readString();
        cout << "Please enter Phone      : ";
        client.Phone = clsInputValidate::readString();
        cout << "Please enter PinCode    : ";
        client.PinCode = clsInputValidate::readString();
        cout << "Please enter account Balance : ";
        client.AccountBalance = stod(clsInputValidate::readString());
    }

    static void _print(clsBankClient client)
    {
            cout << "\nClient Card:";
            cout << "\n___________________";
            cout << "\nFirstName   : " << client.FirstName;
            cout << "\nLastName    : " << client.LastName;
            cout << "\nFull Name   : " << client.FullName();
            cout << "\nEmail       : " << client.Email;
            cout << "\nPhone       : " << client.Phone;
            cout << "\nAcc. Number : " << client.AccountNumber();
            cout << "\nPassword    : " << client.PinCode;
            cout << "\nBalance     : " << int(client.AccountBalance);
            cout << "\n___________________\n";
    }

public: 
	static void showAddClientScreen()
	{
        if (!checkRights(clsUser::enPermissions::pAddNewClient))
        {
            return; 
        }
		_drawScreenHeader("Add new client Screen"); 

        cout << setw(30) << left << "" << "=============================================" << endl;
        cout << setw(30) << left << "" << setw(15) << left << "" << "Add new client" << endl;
        cout << setw(30) << left << "" << "=============================================" << endl;

        string accNum; cout << "Please Enter account number : "; accNum = clsInputValidate::readString();

        while (clsBankClient::IsClientExist(accNum))
        {
            cout << "This account number is already exists !!! Please choose another one : ";
            accNum = clsInputValidate::readString();
        }

        clsBankClient newClient = clsBankClient::getNewclient(accNum);

        readClientInfo(newClient);
        clsBankClient::enSaveResult saveResult;
        saveResult = newClient.save();

        switch (saveResult)
        {
        case clsBankClient::svSucceded:
            cout << "Client has been added successfully :-)" << endl;
            _print(newClient);
            break;
        case clsBankClient::svFailed:
            cout << "The adding operation has been failed :-(" << endl;
            break;
        default:
            break;
        }
	}

};

