#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include <fstream>



class clsLoginRegister : public clsScreen
{



	static void _printRecordInLine(clsUser::sRecord rs)
	{
		cout << "| " << setw(30) << left << rs.dateTime;
		cout << "| " << setw(20) << left << rs.username;
		cout << "| " << setw(25) << left << rs.password;
		cout << "| " << setw(25) << left << rs.permission << endl;
	}

	static void _printAllLogins()
	{
		vector <clsUser::sRecord> records = clsUser::getRecordsFromFile(); 
		for (clsUser::sRecord re : records)
		{
			_printRecordInLine(re); 
		}
	}


public:

	static void showLoginRegisterScreen()
	{
		if (!checkRights(clsUser::pLoginRegister))
		{
			return ; 
		}
		vector <clsUser::sRecord> records = clsUser::getRecordsFromFile();
		string title = "Login register List Screen"; 
		string subTitle = "(" + to_string(records.size()) + ") record(s)";
		_drawScreenHeader(title, subTitle); 


		cout << "_____________________________________________________________________________________________________________________\n" << endl;
		cout << "| " << setw(30) << left << "Date/Time" << "| " << setw(25) << left << "User name";
		cout << "| " << setw(20) << left << "Password" << "| " << setw(25) << "Permissions" << endl;
		cout << "_____________________________________________________________________________________________________________________\n" << endl;

		_printAllLogins(); 

		cout << "_____________________________________________________________________________________________________________________\n" << endl;









	}













};

