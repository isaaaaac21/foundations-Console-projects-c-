#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"

class clsFindScreen : protected clsScreen
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


public:
    static void showFindScreen()
	{
        if (!checkRights(clsUser::enPermissions::pFindClient))
        {
            return;
        }
        _drawScreenHeader("Find Screen"); 
        cout << setw(30) << left << "" << "=============================================" << endl;
        cout << setw(30) << left << "" << setw(15) << left << "" << "Find client" << endl;
        cout << setw(30) << left << "" << "=============================================" << endl;
        string accNum; cout << "Please enter account number : "; cin >> accNum; 

        if (clsBankClient::IsClientExist(accNum))
        {
          clsBankClient client = clsBankClient::find(accNum); 
          _print(client); 
        }
        else
        {
            cout << "There is no client number with such number." << endl; 
        }





	}
};

