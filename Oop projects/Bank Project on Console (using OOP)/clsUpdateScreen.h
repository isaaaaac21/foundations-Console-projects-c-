#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsUpdateScreen : public clsScreen
{
private:

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
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }

    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::readString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::readString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::readString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::readString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::readString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = stod(clsInputValidate::readString());
    }

public:

    static void ShowUpdateClientScreen()
    {
        if (!checkRights(clsUser::enPermissions::pUpdateClients))
        {
            return;
        }

        _drawScreenHeader("\tUpdate Client Screen");

        cout << setw(30) << left << "" << "=============================================" << endl;
        cout << setw(30) << left << "" << setw(15) << left << "" << "Update client" << endl;
        cout << setw(30) << left << "" << "=============================================" << endl;

        string AccountNumber = "";

        cout << "\nPlease Enter client Account Number: ";
        AccountNumber = clsInputValidate::readString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount number is not found, choose another one: ";
            AccountNumber = clsInputValidate::readString();
        }

        clsBankClient Client1 = clsBankClient::find(AccountNumber);

        _PrintClient(Client1);

        cout << "\nAre you sure you want to update this client y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Client Info:";
            cout << "\n____________________\n";


            ReadClientInfo(Client1);

            clsBankClient::enSaveResult SaveResult;

            SaveResult = Client1.save();

            switch (SaveResult)
            {
            case  clsBankClient::enSaveResult::svSucceded:
            {
                cout << "\nAccount Updated Successfully :-)\n";

                _PrintClient(Client1);
                break;
            }
            case clsBankClient::enSaveResult::svFailed:
            {
                cout << "\nError account was not saved because it's Empty";
                break;

            }

            }

        }

    }

};

