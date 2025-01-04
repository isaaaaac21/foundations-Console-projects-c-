#pragma once
#include "clsScreen.h"
#include "userListScreen.h"
#include "addUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateScreen.h"
#include "clsfindUserScreen.h"
class clsManageUsers : protected clsScreen
{
	enum enManageOptions { eUsersList = 1, eAddUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenu = 6 };
	static enManageOptions _readChoice()
	{
		int choice; cout << setw(30) << left << "" << "Please enter your choice : "; cin >> choice;
		return enManageOptions(choice);
	}

	static void customPause()
	{
		cout << "Press any key to go back....";
		_getch();
		showManageUsersScreen();
	}
	static void _usersList()
	{
		userListScreen::showUsersListScreen(); 
	}
	static void _addUser()
	{
		addUserScreen::_showAddNewUserScreen(); 

	}
	static void _deleteUser()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen(); 

	}
	static void _updateUser()
	{
		clsUpdateScreen::ShowUpdateClientScreen(); 
	}
	static void _findUser()
	{
		clsFindUserScreen::ShowFindUserScreen(); 

	}




	static void _performManageUsersOptions(enManageOptions choice)
	{
		switch (choice)
		{
		case clsManageUsers::eUsersList:
			_usersList();
			customPause(); 
			break;
		case clsManageUsers::eAddUser:
			_addUser();
			customPause(); 
			break;
		case clsManageUsers::eDeleteUser:
			_deleteUser(); 
			customPause(); 
			break;
		case clsManageUsers::eUpdateUser:
			_updateUser(); 
			customPause();
			break;
		case clsManageUsers::eFindUser:
			_findUser(); 
			customPause(); 
			break;
		case clsManageUsers::eMainMenu:
			break;
		default:
			break;
		}
	}


public:

	static void showManageUsersScreen()
	{
		if (!checkRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}
		_drawScreenHeader("Manage Users Screen"); 

		cout << setw(30) << left << "" << "=============================================" << endl;
		cout << setw(30) << left << "" << setw(15) << left << "" << "Manage users menu" << endl;
		cout << setw(30) << left << "" << "=============================================" << endl;

		cout << setw(40) << left << " " << setw(20) << left << "[1] Show Users List." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[2] Add User." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[3] Delete User." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[4] Update User Info." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[5] Find User." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[6] MainMenu." << endl;
		cout << setw(30) << left << " " << "============================================= " << endl;
		_performManageUsersOptions(_readChoice()); 

	}



















};

