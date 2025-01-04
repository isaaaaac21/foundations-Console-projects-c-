#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"
#include "clsDate.h"
class clsTransferScreen : public clsScreen
{
private: 
	static void _print(clsBankClient client)
	{
		cout << "Client card : " << endl<<endl; 
		cout << "_______________________" << endl<<endl;
		cout << "Full name    : " << client.FullName() << endl; 
		cout << "Acc number   : " << client.AccountNumber() << endl; 
		cout << "Acc balanace : " << int(client.AccountBalance) << endl << endl; 
		cout << "_______________________" << endl<<endl;
	}











public:

	static void _showTransferScreen()
	{

		_drawScreenHeader("Transfer screen");

		string accNum; cout << "Please enter account number to transfer from : "; cin >> accNum; 

		while (!clsBankClient::IsClientExist(accNum))
		{
			cout << "There is no client with such account number !! please enter another one : "; 
			cin >> accNum; 
		}

		clsBankClient client = clsBankClient::find(accNum); 
		_print(client); 


         cout << "Please enter account number to transfer to : "; cin >> accNum;

		while (!clsBankClient::IsClientExist(accNum))
		{
			cout << "There is no client with such account number !! please enter another one : ";
			cin >> accNum;
		}

		clsBankClient transferTo = clsBankClient::find(accNum); 
		_print(transferTo); 





		float amount; cout << "Enter transfer amount : "; cin >> amount; 
		float accBlance = client.GetAccountBalance();
		while (amount >accBlance) 
		{
			cout << "The amount exceeds the account balance, please reduce the amount : "; 
			cin >> amount; 
		}

		char dec; cout << "\nAre you sure you want to perform this operation ? y/n : "; cin >> dec; 
		if (tolower(dec) == 'y')
		{
			client.transfer(amount, transferTo);
			cout << "The transfer operation has been done successfully :-)" << endl;
			_print(client);
			_print(transferTo); 
			clsBankClient::saveTransferInfoToFile(client, transferTo, amount);
		}
		else cout << "The operation has been canceled !!!" << endl; 

	}


};

