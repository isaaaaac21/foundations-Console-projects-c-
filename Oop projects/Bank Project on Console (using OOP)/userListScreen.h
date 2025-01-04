#pragma once
#include "clsScreen.h"
#include "clsUser.h"
class userListScreen : public clsScreen
{
		static void printUserLine(clsUser s)
	{
		cout << "| " << setw(20) << left << s.UserName;
		cout << "| " << setw(20) << left << s.FirstName + " " + s.LastName;
		cout << "| " << setw(15) << left << s.Phone;
		cout << "| " << setw(25) << left << s.Email;
		cout << "| " << setw(15) << left << s.Password;
		cout << "| " << int(s.Permissions) << endl;
	}
	static void _usersListHeader()
	{
		cout << "_____________________________________________________________________________________________________________________\n" << endl;
		cout << "| " << setw(20) << left << "User Name " << "| " << setw(20) << left << "Full Name";
		cout << "| " << setw(15) << left << "Phone " << "| " << setw(25) << "Email" << "| " << setw(15) << left << "Password" << "| Permissions" << endl;
		cout << "_____________________________________________________________________________________________________________________\n" << endl;
	}

public : 

	static void showUsersListScreen()
	{
		vector <clsUser> users = clsUser::GetUsersList(); 
		string title = "Users List Screen";
		string subTitle = "(" + to_string(users.size()) + ") user(s)."; 
		_drawScreenHeader(title, subTitle); 
		_usersListHeader(); 

		for (clsUser us : users)
		{
			printUserLine(us); 
		}
		cout << "_____________________________________________________________________________________________________________________\n" << endl;


	}

};

