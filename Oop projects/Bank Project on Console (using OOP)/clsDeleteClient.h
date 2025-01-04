#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"


class clsDeleteClient : protected clsScreen
{
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

public : 
	static void deleteScreen()
	{
        if (!checkRights(clsUser::enPermissions::pDeleteClient))
        {
            return;
        }
		_drawScreenHeader("Delete screen"); 
        cout << setw(30) << left << "" << "=============================================" << endl;
        cout << setw(30) << left << "" << setw(15) << left << "" << "Delete client" << endl;
        cout << setw(30) << left << "" << "=============================================" << endl;
        string accNum; cout << "Please enter an account number : "; accNum = clsInputValidate::readString();

        while (!clsBankClient::IsClientExist(accNum))
        {
            cout << "There is no client with such account number... Please choose another one : ";
            accNum = clsInputValidate::readString();
        }

        clsBankClient client = clsBankClient::find(accNum);
        _print(client); 

        string answer = "n";
        cout << "\nAre you sure you want to delete this client ? "; cin >> answer;


        if (answer == "y" || answer == "Y")
        {
            if (client.Delete())
            {
                cout << "Client has been deleted successfully :-)" << endl;
                _print(client); 
            }
            else
            {
                cout << "Client has not been deleted :-(" << endl;
            }

        }
	}
};

