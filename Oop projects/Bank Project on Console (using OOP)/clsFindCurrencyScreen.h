#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsFindCurrencyScreen : public clsScreen
{
private: 
	static void _currencyCard(clsCurrency curr)
	{
		cout << "Currency Card : " << endl; 
		cout << "________________________" << endl << endl; 
		cout << "Country      : " << curr.Country() << endl; 
		cout << "Code         : " << curr.CurrencyCode() << endl; 
		cout << "Name         : " << curr.CurrencyName() << endl; 
		cout << "Rate(1$)     : " << curr.Rate()  << endl; 
		cout << "________________________" << endl << endl ; 
	}
public:
	static void showFindCurrencyScreen()
	{
		_drawScreenHeader("Find Currency"); 

		short choice; cout << "Find by : [1] Code  or  [2] Country : "; cin >> choice; 
		while (choice < 1 || choice > 2)
		{
			cout << "\nPlease choose 1 or 2 : "; cin >> choice; 
		}
		if (choice == 1)
		{
			string code; cout << "\nPlease enter currency code : "; cin >> code;
			clsCurrency curr = clsCurrency::FindByCode(code); 
			if (curr.IsEmpty())
			{
				cout << "There is no currency with such code !!!"; return;
			}
			cout << "\nCurrency found :-)" << endl << endl; 
			_currencyCard(curr); 
		}
		else if (choice == 2)
		{
			string country; cout << "\nPlease enter currency country : "; cin >> country;
			clsCurrency curr = clsCurrency::FindByCountry(country);
			if (curr.IsEmpty())
			{
				cout << "There is no currency with such code !!!"; return;
			}
			cout << "\nCurrency found :-)" << endl << endl;
			_currencyCard(curr);
		}
	}
};

