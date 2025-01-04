#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>

#include "clsScreen.h"
#include "clsClientList.h"
#include "clsAddClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateScreen.h"
#include "clsFindScreen.h"
#include "clsTransaction.h"
#include "clsManageUsers.h"
#include "clsLoginRegister.h"
#include "clsCurrMainScreen.h"
using namespace std; 

class clsMainScreen : protected clsScreen
{
private: 

	enum enOptions { mainMenu = 0, clientList = 1, newClient = 2, deleteClient = 3, updateClient = 4, findClient = 5, transaction = 6, ManageUsers = 7, loginRecords = 8, currencyExchange = 9, Logout = 10 };

	static enOptions _readChoice()
	{
		int choice; cout << setw(30) << left << "" <<  "Please enter your choice : "; cin >> choice; 
		return enOptions(choice);
	}


	static void showClientList()
	{
		clientListScreen::showClientList(); 
	}
	static void _addingScreen()
	{
		clsAddClient::showAddClientScreen(); 
	}


	static void _deleting()
	{
		clsDeleteClient::deleteScreen(); 
	}
	static void _updateHeader()
	{
		clsUpdateScreen::ShowUpdateClientScreen(); 

	}

	static void _findHeader()
	{
       
		clsFindScreen::showFindScreen(); 

	}
	static void _transaction()
	{
		clsTransaction::showTransactionScreen(); 
	}
	static void _manageUsers()
	{
		clsManageUsers::showManageUsersScreen(); 
	}

	static void _logout()
	{
		currentUser = clsUser::Find("", ""); 
		trials = 3; 
	}
	static void _loginRecords()
	{
		clsLoginRegister::showLoginRegisterScreen();
	}
	static void _currencyExchange()
	{
		clsCurrMainScreen::showCurrencyMainMenu(); 
	}

	static void customPause()
	{
		cout << "Press any key to go back....";
		_getch();
		showMainMenu();
	}


	static void performMainMenuOptions(enOptions choice)
	{
		switch (choice)
		{
		case clsMainScreen::clientList:
			showClientList(); 
			customPause(); 
			break;
		case clsMainScreen::newClient:
			_addingScreen(); 
			customPause(); 
			break;
		case clsMainScreen::deleteClient:
			_deleting(); 
			customPause();
			break;
		case clsMainScreen::updateClient:
			_updateHeader();
			customPause();
			break;
		case clsMainScreen::findClient:
			_findHeader(); 
			customPause(); 
			break;
		case clsMainScreen::transaction:
			_transaction(); 
			customPause(); 
			break;
		case clsMainScreen::ManageUsers:
			_manageUsers(); 
			customPause(); 
			break;
		case clsMainScreen::loginRecords:
			_loginRecords();
			customPause(); 
			break; 
		case currencyExchange:
			_currencyExchange();
			customPause(); 
		case clsMainScreen::Logout:
			_logout(); 
			break;
		default:
			break;
		}

	}
public: 

	static void showMainMenu()
	{

		_drawScreenHeader("Main menu Screen");
		cout << setw(30) << left << "" << "=============================================" << endl;
		cout << setw(30) << left << "" << setw(15) << left << "" << "Main menu" << endl;
		cout << setw(30) << left << "" << "=============================================" << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[1] Show Client List." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[2] Add new Client." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[3] Delete Client." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[4] Update Client Info." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[5] Find Client." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[6] Transactions." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[7] Manage users." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[8] Login Register." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[9] Currency Exchange." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[10] Logout." << endl;

		cout << setw(30) << left << " " << "============================================= " << endl;

		performMainMenuOptions(_readChoice());



	}


};

