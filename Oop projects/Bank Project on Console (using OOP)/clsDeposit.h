#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDeposit : protected clsScreen
{

    static void _PrintClient(clsBankClient Client)
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << int(Client.AccountBalance);
        cout << "\n___________________\n";

    }
    static string _readAccNum()
    {
        string accNum; cout << "Please enter account number : "; cin >> accNum;
        return accNum;
    }
public : 

    static void showDepositeScreen()
    {
        _drawScreenHeader("Deposit Screen"); 

        string accNum = _readAccNum(); 

        while (!clsBankClient::IsClientExist(accNum))
        {
            cout << "There is no client with such Account Number !! please enter another : "; 
            cin >> accNum; 
        }

        clsBankClient client = clsBankClient::find(accNum); 
        _PrintClient(client); 

        double amount = clsInputValidate::readIntNumber();

        char dec = 'y';
        cout << "Are you sure you want to perform this operation ? "; cin >> dec; 
        if (tolower(dec) == 'y')
        {
            client.deposit(amount); 
            cout << "The operation has been done successfully :-)" << endl; 
        }
        else
        {
            cout << "The operation has been cancelled !!" << endl; 
        }













    }















};

