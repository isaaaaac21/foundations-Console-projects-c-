#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsCalculatorScreen : public clsScreen
{
private:


	static clsCurrency _readCurr()
	{
		string code; cout << "\nPlease enter currency code : "; cin >> code;
		while (!clsCurrency::IsCurrencyExist(code))
		{
			cout << "Invalide currency code, Please choose another one : "; cin >> code;
		}
		return clsCurrency::FindByCode(code);
	}
	static void _convertFrom(clsCurrency curr)
	{
		cout << "\nConvert from : "  << endl; 
		clsCurrency::currencyCard(curr); 
	}
public:
	static void showCalculatorScreen()
	{
		char ans = 'y'; 
		do
		{
		    _drawScreenHeader("Calculator screen"); 
		 	clsCurrency curr1 = _readCurr();

			clsCurrency curr2 = _readCurr();

			int amount; cout << "\nEnter amount to exchange  : "; cin >> amount;
			_convertFrom(curr1);

			float exchange = clsCurrency::calculateCurrency(curr1, curr2, amount);

			cout << amount << " " << curr1.CurrencyCode() << " = " << exchange << " " << curr2.CurrencyCode() << endl;

			cout << "\nDo you want to perform another calculation ? y/n  "; cin >> ans; 
		} while (tolower(ans) == 'y');

	}

};

