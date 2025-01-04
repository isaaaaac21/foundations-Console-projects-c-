#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
class clsTransferLog : public clsScreen
{
private:
	static void _printTransLine(clsBankClient::sTransInfo trnsfer)
	{

		cout << "| " << setw(25) << left << trnsfer.dateTime;
		cout << "| " << setw(10) << left << trnsfer.accNum1;
		cout << "| " << setw(10) << left << trnsfer.accNum2;
		cout << "| " << setw(10) << left << trnsfer.amount;
		cout << "| " << setw(15) << left << trnsfer.balance1;
		cout << "| " << setw(15) << left << trnsfer.balance2;
		cout << "| " << setw(15) << left << trnsfer.userName << endl;

	}
public:

	static void showTransferLogs()
	{
		vector <clsBankClient::sTransInfo> logs = clsBankClient::getTransferInfoFromFile(); 

		string title = "Transfer log list"; 
		string subTitle = "(" + to_string(logs.size()) + ")" + " Records.";

		_drawScreenHeader(title, subTitle);

		cout << "_____________________________________________________________________________________________________________________\n" << endl;

		cout << "| " << setw(25) << left << "Date/Time" << "| " << setw(10) << left << "s.Acct";
		cout << "| " << setw(10) << left << "d.Acct" << "| " << setw(10) << left << "amount";
		cout << "| " << setw(15) << left << "s.Balance" << "| " << setw(15) << left << "d.Balance" << "| User" << endl; 
		cout << "_____________________________________________________________________________________________________________________\n" << endl;


		for (clsBankClient::sTransInfo trn : logs)
		{
			_printTransLine(trn); 
		}
		cout << "_____________________________________________________________________________________________________________________\n" << endl;

	}
};

