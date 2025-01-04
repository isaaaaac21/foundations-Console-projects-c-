#pragma once
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsDeposit.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLog.h"
class clsTransaction : protected clsScreen
{
	enum enTranOptions { eDeposite = 1, eWithdraw = 2, eTotalBalances = 3, eTransfer = 4, eTransferLog = 5,  eMainMenu = 6 };
	static enTranOptions _readChoice()
	{
		int choice; cout << setw(30) << left << "" << "Please enter your choice : "; cin >> choice;
		return enTranOptions(choice);
	}
	static void customPause()
	{
		cout << "Press any key to go back....";
		_getch();
		showTransactionScreen();
	}
	static void _deposite()
	{
		clsDeposit::showDepositeScreen(); 
	}
	static void _withdraw()
	{
		system("cls");
		clsWithdrawScreen::ShowWithdrawScreen(); 
	
	}
	static void _totalBalances()
	{
		clsTotalBalancesScreen::ShowTotalBalances(); 
		
	}
	static void _transfer()
	{
		clsTransferScreen::_showTransferScreen(); 
	}
	static void _transferLog()
	{
		clsTransferLog::showTransferLogs();
	}
	static void _performTransactionsOptions(enTranOptions choice)
	{
		switch (choice)
		{
		case clsTransaction::eDeposite:
			_deposite(); 
			customPause();  
			break;
		case clsTransaction::eWithdraw:
			_withdraw(); 
			customPause(); 
			break;
		case clsTransaction::eTotalBalances:
			_totalBalances(); 
			customPause();
			break;
		case eTransfer:
			_transfer();
			customPause();
			break;
		case eTransferLog:
			_transferLog(); 
			customPause(); 
			break;
		case clsTransaction::eMainMenu : 
		default:
			break;
		}
	}



public : 

	

	static void showTransactionScreen()
	{
		if (!checkRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}
		_drawScreenHeader("Transaction screen");


		cout << setw(30) << left << "" << "_____________________________________________" << endl;
		cout << setw(32) << left << "" << setw(15) << left << "" << "Transaction Menu" << endl;
		cout << setw(30) << left << "" << "_____________________________________________" << endl << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[1] Deposite." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[2] Withdraw." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[3] Total balances." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[4] Transfer." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[5] Transfer logins." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[6] mainMenue." << endl;
		cout << setw(30) << left << "" << "_____________________________________________" << endl;
		_performTransactionsOptions(_readChoice()); 
	}












};

