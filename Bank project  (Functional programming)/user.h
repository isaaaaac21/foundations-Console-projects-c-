#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "HelpfulThings.h"

using namespace std; 
enum enBitMaxOptions {
	clientListU = 1 << 0, addClientU = 1 << 1, deleteClientU = 1 << 2, updateClientU = 1 << 3, findClientU = 1 << 4,
	transactionsU = 1 << 5, manageU = 1 << 6
};


void clearLines(int numLines)
{
	for (int i = 0; i < numLines; i++)
	{
		cout << "\r"; 

		cout << "\033[K"; 

		if (i < numLines-1)
		{
			cout << "\033[1A"; 
		}
	}
	cout.flush(); 
}

namespace userHeaders
{
	void newLines()
	{
		cout << "\n\n";
	}
	void longLine()
	{
		cout << setw(100) << left << "________________________________________________________________________________________________________________________\n" << endl;
	}
	void loginHeader()
	{
		system("cls");
		cout << setw(30) << left << "_________________________________\n" << endl;
		cout << setw(10) << left << " " << setw(23) << "Login Screen" << endl;
		cout << setw(30) << left << "_________________________________" << endl;
	}




	void userListHeader(int vecSize)
	{
		system("cls"); 
		cout << endl << setw(45) << left << " " << setw(10) << left << "Users List : " << left << vecSize << " user(s)." << endl;
		longLine();
		cout << "| " << setw(20) << left << "User Name " << "| " << setw(15) << left << "Password";
		cout << "| " << setw(40) << left << "Permissions " << endl;
		longLine();
	}

	void addNewUserHeader()
	{
		system("cls");
		cout << setw(30) << left << "_________________________________\n" << endl;
		cout << setw(7) << left << " " << setw(23) << "Add new user Screen" << endl;
		cout << setw(30) << left << "_________________________________" << endl;
		cout << "A D D I N G  N E W  U S E R  : " << endl << endl; 
	}
	void deniedHeader()
	{
		system("cls"); 
		cout << setw(30) << left << "_________________________________\n" << endl; 
		cout << "Access denied,\nYou Don't have permission to do this !!" << endl;
		cout << "Please contact your admin !!!" << endl; 
		cout << setw(30) << left << "_________________________________" << endl;
	}

	void deleteUserScreen()
	{
		system("cls");
		cout << setw(30) << left << "_________________________________\n" << endl;
		cout << setw(10) << left << " " << setw(23) << "Delete user Screen" << endl;
		cout << setw(30) << left << "_________________________________" << endl;
	}
	void updateHeader()
	{
		system("cls");
		cout << setw(30) << left << "_________________________________\n" << endl;
		cout << setw(10) << left << " " << setw(23) << "Update user Screen" << endl;
		cout << setw(30) << left << "_________________________________" << endl;
	}

	void findUserScreen()
	{
		system("cls");
		cout << setw(30) << left << "_________________________________\n" << endl;
		cout << setw(7) << left << " " << setw(23) << "Find user Screen" << endl;
		cout << setw(30) << left << "_________________________________" << endl;
	}






}





namespace user
{
	struct user
	{
		string userName;
		string passWord;
		int access = 0;
	};

	user readUser()
	{
		user s;
		cout << "Enter the user name : "; cin >> s.userName;
	    cout << "Enter the user password : "; cin >> s.passWord;
		return s; 

	}
	string readUsername()
	{
		string userName; cout << "Please enter username user : "; cin >> userName;
		return userName; 
	}
	string userToLine(user s)
	{
		string line;
		line += s.userName + "#//#";
		line += s.passWord + "#//#";
		line += to_string(s.access);
		return line; 
	}
	user lineToUser(string line)
	{
		user s;
		vector <string> users = stringing::spliting(line, "#//#");

		s.userName = users.at(0);
		s.passWord = users.at(1);
		s.access = stoi(users.at(2));
		return s;
	}
	bool findUser(vector <user> users, user& us, bool justName = false)
	{
		for (user u : users)
		{
			if (!justName)
			{
				if (u.userName == us.userName && u.passWord == us.passWord)
				{
					us = u;
					return true;
				}
			}
			else {
				if (u.userName == us.userName) return true;
			}
		}
		return false;
	}
	bool findUserByName(vector <user> users, user& us, string userName)
	{
		for (user u : users)
		{
			if (u.userName == userName)
			{
				us = u;
				return true;
			}
		}
		return false; 
	}

	void addUserToFile(user s, string fileName)
	{
		fstream file;
		file.open(fileName, ios::out | ios::app);
		if (file.is_open())
		{
			file << userToLine(s) << endl; 
			file.close();
		}
	}
	void addUsersTofile(vector <user> users, string fileName)
	{
		for (user s : users)
		{
			addUserToFile(s, fileName); 
		}
	}
	int generateAccesNumber(bool ClientListBool, bool addClientBool, bool deleteClientBool, bool updateClientBool, bool findClientBool, bool transactionBool, bool manageUsersBool)
	{
		int accessNum = 0;
		if (ClientListBool) accessNum |= clientListU;
		if (addClientBool) accessNum |= addClientU;
		if (deleteClientBool) accessNum |= deleteClientU;
		if (updateClientBool) accessNum |= updateClientU;
		if (findClientBool) accessNum |= findClientU;
		if (transactionBool) accessNum |= transactionsU;
		if (manageUsersBool) accessNum |= manageU;

		return accessNum;
	}

	int readPermissionsAndReturnAccessNum()
	{
		bool clList, addCl, delClient, upClient, findCl, trans, manageUs;
		clList = addCl = delClient = upClient = findCl = trans = manageUs = false; 
		char dec;
		cout << "\nDo you want to give access to : " << endl << endl;
		cout << "Show client list ? Y/N : "; cin >> dec; if (tolower(dec) == 'y') clList = true; 
		cout << "Add new client ? Y/N : "; cin >> dec; if (tolower(dec) == 'y') addCl = true; 
		cout << "Delete client  ? Y/N : "; cin >> dec; if (tolower(dec) == 'y') delClient = true; 
		cout << "Update client  ? Y/N : "; cin >> dec; if (tolower(dec) == 'y') upClient = true; 
		cout << "Find client    ? Y/N : "; cin >> dec; if (tolower(dec) == 'y') findCl = true; 
		cout << "Transactions   ? Y/N : "; cin >> dec; if (tolower(dec) == 'y') trans = true; 
		cout << "Manage users   ? Y/N : "; cin >> dec; if (tolower(dec) == 'y') manageUs = true; 


		return generateAccesNumber(clList, addCl, delClient, upClient, findCl, trans, manageUs);




	}

	

	void keepAskingWhileTheUserExists(vector <user> users, user& s, bool justName = false)
	{
		if (justName == true)
		{
			while (findUser(users, s, true))
			{
				cout << "The username [" << s.userName << "] exists please enter another userName !" << endl << endl;
				s = readUser();
			}
		}
		//Here if the user doesn't exits so we cannot login
		else
		{
			while (!findUser(users, s))
			{
				cout << "Invalide Username / password !" << endl;
				userHeaders::newLines();
				s = readUser();
			}
		}
	}




	int accessProblem()
	{
		char dec ;

		cout << "Do you want to give this user full access ? Y/N : "; cin >> dec;
		while (tolower(dec) != 'y' && tolower(dec) != 'n')
		{
			cout << "\nInvalide response choose Y/N : "; cin >> dec; 
		}
		if (tolower(dec) == 'y') return -1;



	   return readPermissionsAndReturnAccessNum(); 

	}
	bool hasAcces(int accesNum, enBitMaxOptions bitmax)
	{
		if (accesNum == -1) return true; 
		return (accesNum & bitmax) != 0;
	}



	void printUsersList(vector <user> users)
	{
		for (user s : users)
		{
			cout << "| " << setw(20) << left << s.userName << "| " << setw(15) << s.passWord << "| " << s.access << endl;
		}
	}




	vector <user> loadUsersFromFile(string fileName)
	{
		fstream file;
		vector <user> users;
		string line;
		file.open(fileName, ios::in);
		if (file.is_open())
		{
			while (getline(file, line))
			{
				users.push_back(lineToUser(line));
			}
			file.close();
		}

		return users;
	}



	void loginScreen(string fileName, user& s)
	{
		system("cls"); 
		userHeaders::loginHeader();
		vector <user> users = loadUsersFromFile(fileName);

		s = readUser();
		keepAskingWhileTheUserExists(users, s); 

	}

	void userList(string fileName)
	{

		fstream file; 
		vector <user> users = loadUsersFromFile(fileName); 

		userHeaders::userListHeader(users.size());
		printUsersList(users); 
	}
	int accessNumberOfAuser(string fileName, user s)
	{
		vector<user> users = loadUsersFromFile(fileName);
		for (user us : users)
		{
			if (us.userName == s.userName && us.passWord == s.passWord)  return us.access;
		}
		return 0;
	}


	bool checkUserIfHasAccess(string fileName, user us, enBitMaxOptions option)
	{
		int accessNumber = accessNumberOfAuser(fileName, us);
		if (hasAcces(accessNumber, option)) return true;
		else
		{
			userHeaders::deniedHeader();
			return false;
		}
	}

	void addNewUser(string fileName)
	{
	    userHeaders::addNewUserHeader();
	    fstream file;
		user s = readUser();
		vector <user> users = loadUsersFromFile(fileName);
		keepAskingWhileTheUserExists(users, s, true);

		s.access = accessProblem();

		addUserToFile(s, fileName);
	
	}
	void printUserDetails(user s)
	{
		cout << "\nThe Following are the user Details : " << endl;
		cout << setw(30) << left << "_________________________________\n" << endl;
		cout << setw(30) << left << "Username : " << s.userName << endl; 
		cout << setw(30) << left << "Password : " << s.passWord << endl; 
		cout << setw(30) << left << "Permissions : " << s.access << endl; 
		cout << setw(30) << left << "_________________________________\n" << endl;

	}

	void deleteUser(vector <user>& users, string fileName)
	{
		userHeaders::deleteUserScreen(); 
		fstream file; 
		vector <user> afterDeleting;
		user s; 
		string userName = readUsername(); 
		char dec; 
		if (findUserByName(users, s,  userName))
		{
				 printUserDetails(s);
			for (user s : users)
			{
				if (s.userName != userName) afterDeleting.push_back(s);
			}
			cout << "\nAre u sure you want to delete This user ? "; cin >> dec;
			if (tolower(dec) == 'y')
			{
				file.open(fileName, ios::out);
				addUsersTofile(afterDeleting, fileName);
				users = afterDeleting; 
			}
		}
		else cout << "This user name [" << userName << "] doesn't exist !!!!" << endl; 
	}

	user changeUserInfo(user s)
	{
		cout << "\nEnter New password : "; cin >> s.passWord; 
		s.access = accessProblem(); 
		return s; 
	}


	void updateUser(string fileName)
	{
		userHeaders::updateHeader(); 
		vector <user> users = loadUsersFromFile(fileName); 
		string userName = readUsername(); 
		
		char dec; 
		fstream file;
		user us;
		if (findUserByName(users, us, userName))
		{
			printUserDetails(us);
			cout << "Are you sure you want to update this user ? Y/N  "; cin >> dec;
			if (tolower(dec) == 'y')
			{
				for (user& s : users)
				{
					if (s.userName == userName)
					{
						s = changeUserInfo(s);
						break;
					}
				}
				file.open(fileName, ios::out);
				addUsersTofile(users, fileName);

				cout << "\nUser has been updated successfully :-)" << endl; 
			}
		}
		else cout << "There is no user with such username !!!" << endl; 
	}

	void findUsers(string fileName)
	{
		userHeaders::findUserScreen(); 
		vector <user> users = loadUsersFromFile(fileName); 
		user us; 
		string userName = readUsername(); 

		if (findUserByName(users, us, userName))
		{
			printUserDetails(us);
		}
		else cout << "There is no user with such username !!!" << endl; 
	}

}



























