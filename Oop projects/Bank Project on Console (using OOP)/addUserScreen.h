#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class addUserScreen : protected clsScreen
{
private: 

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {

        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            return -1;
        }

        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {


            Permissions += clsUser::enPermissions::pListClients;
        }

        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pAddNewClient;
        }

        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pDeleteClient;
        }

        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pUpdateClients;
        }

        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pFindClient;
        }

        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pTranactions;
        }

        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pManageUsers;
        }

        cout << "\nLogin Register? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            Permissions += clsUser::enPermissions::pLoginRegister;
        }

        return Permissions;

    }
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::readString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::readString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::readString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::readString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::readString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }



public: 
    static void _showAddNewUserScreen()
    {
        _drawScreenHeader("Add New User Screen");

        cout << setw(30) << left << "" << "=============================================" << endl;
        cout << setw(30) << left << "" << setw(15) << left << "" << "Add new user" << endl;
        cout << setw(30) << left << "" << "=============================================" << endl;

        string userName; cout << "Please enter a username : "; cin >> userName; 

        while (clsUser::IsUserExist(userName))
        {
            cout << "The username is already exists, please choose another one : ";  cin >> userName;
        }
        
        clsUser user = clsUser::GetAddNewUserObject(userName);
        _ReadUserInfo(user); 


        clsUser::enSaveResults saveResult; 

        saveResult = user.Save(); 
        if (saveResult == clsUser::svSucceeded)
        {
            cout << "User has been added successfully !!!" << endl; 
            return; 
        }
        else
        {
            cout << "save operation has been failed !!!!" << endl; 
        }



    }



};

