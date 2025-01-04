#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
class clientListScreen : protected clsScreen
{
	static void printClientLine(clsBankClient s)
	{
		cout << "| " << setw(20) << left << s.AccountNumber();
		cout << "| " << setw(15) << left << s.PinCode;
		cout << "| " << setw(20) << left << s.FirstName + " " + s.LastName;
		cout << "| " << setw(25) << left << s.Email;
		cout << "| " << setw(15) << left << s.Phone;
		cout << "| " << int(s.AccountBalance) << endl;
	}
	static void _clientListHeader()
	{
		cout << "_____________________________________________________________________________________________________________________\n" << endl;
		cout << "| " << setw(20) << left << "Accout Number " << "| " << setw(15) << left << "Pin Code";
		cout << "| " << setw(20) << left << "Client Name " << "| " << setw(25) << "Email" << "| " << setw(15) << left << "Phone" << "| Balance" << endl;
		cout << "_____________________________________________________________________________________________________________________\n" << endl;
	}
public : 


	static void showClientList()
	{
		if (!checkRights(clsUser::enPermissions::pListClients))
		{
			return;
		}
		vector <clsBankClient> clients = clsBankClient::getClientsFromFile(); 
		string title = "Client list screen";
		string subTitle = "( " + to_string(clients.size()) + " ) client(s).";
		_drawScreenHeader(title, subTitle); 
		_clientListHeader(); 
		for (clsBankClient cl : clients)
		{
			printClientLine(cl); 
		}
		cout << "\n_____________________________________________________________________________________________________________________\n" << endl;


	}
};

