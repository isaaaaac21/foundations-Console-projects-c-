#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include "clsUser.h"
#include "global.h"
#include "clsDate.h"
using namespace std; 

class clsScreen
{

	
protected:


	static bool checkRights(clsUser::enPermissions permission)
	{
		if (currentUser.checkPermissions(permission)) return true;
		else
		{
			system("cls"); 
			cout << setw(30) << left << "" << "=============================================" << endl;
			cout << setw(19) << left << "" << setw(15) << left << "" << "Access Denied!!! Contact your admin!!" << endl;
			cout << setw(30) << left << "" << "=============================================" << endl << endl;
			return false;
		}
	}
	static void _drawScreenHeader(string title, string subTitle = "")
	{
		system("cls");
		cout << setw(30) << left << "" << "_____________________________________________" << endl << endl;
		cout << setw(32) << left << "" << setw(15) << left << "" << title << endl;
		if (subTitle != "") cout << setw(32) << left << "" << left << setw(15) << "" << subTitle << endl;
		cout << setw(30) << left << "" << "_____________________________________________" << endl << endl;

		cout << setw(30) << left << "" << "User : " << currentUser.UserName << endl;
		cout << setw(30) << left << "" << "Date : " << clsDate::DateToString(clsDate::GetSystemDate()) << endl << endl;
	}
};
