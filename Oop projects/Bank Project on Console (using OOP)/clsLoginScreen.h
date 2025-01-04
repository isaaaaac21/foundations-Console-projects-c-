#pragma once
#include "clsScreen.h"
#include <fstream>
#include "clsMainScreen.h"
#include "clsDate.h"
class clsLoginScreen : public clsScreen
{


	static bool _login()
	{
		bool loginFailed = false;

		string userName, password; 
		do
		{
			if (loginFailed)
			{
				trials--;
				cout << "Invalide username / password !!  " << endl;
				cout << "You have " << trials << " trials to login !!!" << endl << endl; 
				if (trials == 0)
				{
					cout << "You've been locked !!!" << endl;
					return false; 
				}
			}


			cout << "Please enter a user name : "; cin >> userName;
			cout << "Please enter a password : "; cin >> password;
			currentUser = clsUser::Find(userName, password); 

			loginFailed = currentUser.IsEmpty(); 
			
		} while (loginFailed); 

		currentUser.addLoginRecordTofile(); 
		
		clsMainScreen::showMainMenu();
		return true; 
	}

public: 
	static bool showLoginScreen()
	{
		system("cls"); 
		_drawScreenHeader("Login Screen"); 
         
		return _login();


	}








};

