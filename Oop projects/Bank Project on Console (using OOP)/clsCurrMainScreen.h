#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCalculatorScreen.h"
class clsCurrMainScreen : public clsScreen
{
private: 
	enum eCurrOptions {eList = 1, eFind = 2, eUpdate = 3, eCalc = 4, eMain = 5 };
public:
	static eCurrOptions _readChoice()
	{
		int choice; cout << setw(30) << left << "" << "Please enter your choice : "; cin >> choice;
		return eCurrOptions(choice);
	}

	static void customPause()
	{
		cout << "Press any key to go back....";
		_getch();
		showCurrencyMainMenu();
	}
	static void  _List()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen(); 
	}
	static void  _Find()
	{
		clsFindCurrencyScreen::showFindCurrencyScreen(); 
	}
	static void  _Update()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen(); 
	}
	static void  _calc()
	{
		clsCalculatorScreen::showCalculatorScreen(); 
	}
	static void _performTransactionsOptions(eCurrOptions choice)
	{
		switch (choice)
		{
		case eList:
			_List(); 
			customPause(); 
			break;
		case eFind:
			_Find(); 
			customPause();
			break;
		case eUpdate:
			_Update(); 
			customPause();
			break;
		case eCalc:
			_calc(); 
			customPause();
			break;
		case eMain:
			break; 
		default:
			break;
		}
	}
	static void showCurrencyMainMenu()
	{

		_drawScreenHeader("Currency Exchange");
		cout << setw(30) << left << "" << "_____________________________________________" << endl;
		cout << setw(32) << left << "" << setw(15) << left << "" << "Currency Exchange" << endl;
		cout << setw(30) << left << "" << "_____________________________________________" << endl << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[1] Currencies' List." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[2] Find currency." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[3] Update currency." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[4] Currency Calculator." << endl;
		cout << setw(40) << left << " " << setw(20) << left << "[5] mainMenue." << endl;
		cout << setw(30) << left << "" << "_____________________________________________" << endl;
		_performTransactionsOptions(_readChoice());
	}
};

