#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector> 
#include "HelpfulThings.h"
#include "user.h" 
#include <conio.h>

using namespace helping; 
using namespace std; 

enum enOptions { mainMenu = 0, clientList = 1, newClient = 2, deleteClient = 3, updateClient = 4, findClient = 5, transaction = 6,ManageUsers = 7, Logout = 8};
enum enTransaction {deposit = 1, withdraw = 2, totalBalnces = 3, mainMenuTra = 4};
enum enManageUsers {usersList = 1, addUser = 2, deleteUser = 3, updateUser = 4, findUser = 5, mainMenuu = 6 };



string projectFile = "Clients Project.txt"; 
string userFile = "us.txt"; 

user::user ourUser;


enManageUsers readUserManage()
{
	int choice = 0;
	cout << "Choose what do you want to do ? "; cin >> choice;
	return (enManageUsers)choice;
}
enTransaction readTran()
{
	int tran; cout << "Choose what do you want to do ? : "; cin >> tran;
	return (enTransaction)tran;
}
enOptions readOption()
{
	int choice = 0 ;
	cout << "Choose what do you want to do ? "; cin >> choice;
	return (enOptions)choice; 
}

void customPause()
{
	cout << "Press any key to go back....";
	_getch(); 
}

//Some definition
void performMainMenuOptions(enOptions option);
void PerformTransactionOptions(enTransaction choice);
void performManageUsersOptions(enManageUsers choice);
void performManageUsersOptions(enManageUsers choice);


//Some headers
void manageUserHeader()
{
	if (!user::checkUserIfHasAccess(userFile, ourUser, manageU)) return;

	system("cls");
	cout << setw(30) << left << "_________________________________\n" << endl;
	cout << setw(7) << left << " " << setw(23) << "Manage users Menu Screen" << endl;
	cout << setw(30) << left << "_________________________________" << endl << endl; 

	cout << setw(10) << left << " " << setw(20) << "[1] Users list." << endl;
	cout << setw(10) << left << " " << setw(20) << "[2] Add user." << endl;
	cout << setw(10) << left << " " << setw(20) << "[3] Delete user." << endl;
	cout << setw(10) << left << " " << setw(20) << "[4] Update user." << endl;
	cout << setw(10) << left << " " << setw(20) << "[5] Find user." << endl;
	cout << setw(10) << left << " " << setw(20) << "[6] Main menu." << endl;
	cout << setw(30) << left << "_________________________________" <<  endl; 
	performManageUsersOptions(readUserManage());
}
void optionsScreen()
{
	cout << setw(10) << left << " " << setw(20) << left << "[1] Show Client List." << endl;
	cout << setw(10) << left << " " << setw(20) << left << "[2] Add new Client." << endl; 
	cout << setw(10) << left << " " << setw(20) << left << "[3] Delete Client." << endl; 
	cout << setw(10) << left << " " << setw(20) << left << "[4] Update Client Info." << endl;
	cout << setw(10) << left << " " << setw(20) << left << "[5] Find Client." << endl; 
	cout << setw(10) << left << " " << setw(20) << left << "[6] Transactions." << endl;
	cout << setw(10) << left << " " << setw(20) << left << "[7] Manage users." << endl;
	cout << setw(10) << left << " " << setw(20) << left << "[8] Logout." << endl;
}
void menuHeader()
{
	system("cls");
	cout << setw(30) << "=============================================" << endl;
	cout << setw(15) << left << " " << setw(20) << left << "Main Menu Screen" << endl; 
	cout << setw(30) << "=============================================" << endl;
	optionsScreen();
	cout << setw(30) << "=============================================" << endl;
	performMainMenuOptions(readOption()); 
}
void login()
{
	

	user::loginScreen(userFile, ourUser);
	menuHeader(); 
}
void transactionHeader()
{
	if (!user::checkUserIfHasAccess(userFile, ourUser, transactionsU)) return;

	system("cls");

	cout << setw(30) << left << "_________________________________\n" << endl;
	cout << setw(7) << left << " " << setw(23) << "Transaction Menu Screen" << endl;
	cout << setw(30) << left << "_________________________________\n" << endl;
	cout << setw(10) << left << " " << setw(20) << "[1] Deposite." << endl;
	cout << setw(10) << left << " " << setw(20) << "[2] Withdraw." << endl;
	cout << setw(10) << left << " " << setw(20) << "[3] Total Balances." << endl;
	cout << setw(10) << left << " " << setw(20) << "[4] Main Menu." << endl;
	cout << setw(30) << left << "_________________________________\n" << endl;
	PerformTransactionOptions(readTran());

}



//Go back function
void goBackToMainMenu()
{
	headers::newLines();
	customPause(); 
	menuHeader(); 
}
void goBackToTransactions()
{
	headers::newLines();
	customPause();
	transactionHeader();
}
void goBackToManageUsers()
{
	userHeaders::newLines();
	customPause();
	manageUserHeader();
}



//Menue Function
void showClientList()
{
	if (!user::checkUserIfHasAccess(userFile, ourUser, clientListU)) return;
	system("cls");

	vector <sclient> clients = loadClientsFromFile(projectFile);

	headers::clientListHeader(clients.size());
	printAllClientsInvector(clients); 
    
	goBackToMainMenu();


}
void addNewClient()
{
	headers::adding();
	fstream file; 
	vector <sclient> clients = loadClientsFromFile(projectFile);
	sclient s; 

	string accNum = readAccNum();
	while (findAcc(clients, accNum))
	{
		cout << "Client with [" << accNum << "] Already exists, Enter another number : "; cin >> accNum; 
	}

	s.accountNumber = accNum; 
    readClient(s);

	saveClientInFile(projectFile, s); 

}
void addClientLoop()
{
	if (!user::checkUserIfHasAccess(userFile, ourUser, addClientU)) return;
	char dec = 'y';
	do
	{
		addNewClient();
	  cout << "\nThe client has been added successfully, Do you want to add another client ? Y/N : "; cin >> dec;

	} while (tolower(dec) == 'y');
}
void deleteAccount()
{
	if (!user::checkUserIfHasAccess(userFile, ourUser, deleteClientU)) return; 
	headers::deleting(); 
	vector <sclient> clients = loadClientsFromFile(projectFile);
	deletingClient(clients, readAccNum(), projectFile); 
	goBackToMainMenu();

}
void updateAccount()
{
	if (!user::checkUserIfHasAccess(userFile, ourUser, updateClientU)) return;

	headers::updateHeader(); 
	vector <sclient> clients = loadClientsFromFile(projectFile);
	updatingClient(clients, projectFile);
	goBackToMainMenu();

}
void findAccount()
{
	if (!user::checkUserIfHasAccess(userFile, ourUser, findClientU)) return;

	headers::findHeader(); 
	string accNum = readAccNum(); 
	vector <sclient> clients = loadClientsFromFile(projectFile); 
	sclient sc;
	if (findAcc(clients, accNum, sc)) printClient(sc);
	else cout << "\nThere is no client with such account number !!" << endl;

}


//UserFinalFunction

void addUsers()
{

	char dec; 
	do
	{
		user::addNewUser(userFile);
		cout << "The user Has been added successfully, do you want to add more users? "; cin >> dec; 
	} while (tolower(dec) == 'y'); 
}
void deleteUsers()
{
	vector <user::user> users = user::loadUsersFromFile(userFile);
	user::deleteUser(users, userFile); 
}

void updateUsers()
{
	user::updateUser(userFile); 
}











void PerformTransactionOptions(enTransaction choice)
{

	switch (choice)
	{
	case deposit:
		depositingAndWithDraw(projectFile, 1);
		goBackToTransactions();
		break;
	case withdraw:
		depositingAndWithDraw(projectFile, 2);
		goBackToTransactions(); 
		break;
	case totalBalnces:
		totalBlance(projectFile);
		goBackToTransactions(); 
		break;
	case mainMenuTra:
		menuHeader(); 
		break;
	}
}



void performManageUsersOptions(enManageUsers choice)
{
	switch (choice)
	{
	case usersList:
		user::userList(userFile);
		goBackToManageUsers(); 
		break;
	case addUser:
		addUsers(); 
		goBackToManageUsers(); 
		break;
	case deleteUser:
		deleteUsers();
		goBackToManageUsers();
		break;
	case updateUser:
		updateUsers(); 
		goBackToManageUsers();
		break;
	case findUser:
		user::findUsers(userFile); 
		goBackToManageUsers(); 
		break;
	case mainMenuu:
		menuHeader();
		break;
	default:
		break;
	}
}

void performMainMenuOptions(enOptions option)
{
	switch (option)
	{

	case clientList:
		showClientList();
		goBackToMainMenu(); 
		break;
	case newClient:
		addClientLoop(); 
		goBackToMainMenu();

		break;
	case deleteClient:
		deleteAccount();
		goBackToMainMenu();
		break;
	case updateClient:
		updateAccount();
		goBackToMainMenu();
		break; 
	case findClient: 
		findAccount(); 
		goBackToMainMenu(); 
		break; 
	case transaction : 
		transactionHeader(); 
		goBackToMainMenu();
		break;
	case ManageUsers : 
		manageUserHeader();
		goBackToMainMenu(); 
	case Logout:
		login(); 
		break;
	}
}




//void finalProgram()
//{
//	
//	enOptions  choice = mainMenu;
//
//	while (choice != Exit)
//	{
//		choice = menuHeader(); 
//
//		if (choice == clientList)
//		{
//			showClientList();
//			choice = mainMenu; 
//		}
//		else if (choice == newClient)
//		{
//			char dec = 'y';
//
//			do
//			{
//				addNewClient(dec);
//			} while (tolower(dec) == 'y');
//          
//			goBack(); 
//			choice = mainMenu; 
//
//		}
//		else if (choice == deleteClient)
//		{
//			deleteAccount();
//		}
//		else if (choice == updateClient)
//		{
//			updateAccount(); 
//			choice = mainMenu;
//		}
//		else if (choice == findClient)
//		{
//			findAccount();
//			choice = mainMenu;
//		}
//		else
//		{
//			choice = Exit;
//		}
//	}
//
//
//
//
//
//}
int main()
{
	
	login(); 






}
