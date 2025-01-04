#pragma once
#include <iostream>
#include <string> 
#include <vector>
#include <ctime>

#include "clsDate.h"
class clsInputValidate
{
public:




	static string readString()
	{
		string str; getline(cin >> ws, str); return str;
	}







	static bool isNumberBetween(int a, int b, int c)
	{
		if (a >= b && a <= c) return true; 
		return false; 
	}
	static bool isNumberBetween(float a, float b, float c)
	{
		if (a >= b && a <= c) return true; 
		return false; 
	}
	static bool isDateBetween(clsDate d1, clsDate d2, clsDate d3)
	{
		if (clsDate::IsDate1AfterDate2(d1, d2) && clsDate::IsDate1BeforeDate2(d1, d3)) return true; 
		if (clsDate::IsDate1AfterDate2(d1, d3) && clsDate::IsDate1BeforeDate2(d1, d2)) return true;

		return false; 
		

	}



	static int readIntNumber(string message = "")
	{
		int x; 
		cout << "Please enter a number : "; cin >> x;
			
		while (cin.fail())
		{
			cin.clear(); 
			cin.ignore(INT_MAX, '\n'); 
			cout << message; cin >> x; 
		}
		return x; 
	}


	static int readIntNumberBetween(int a, int b, string message)
	{
		int x = readIntNumber("Please try again : ");
		while (x < a || x> b)
		{
			cout << message << endl; 
			x = readIntNumber("Please try again : ");
		}

		return x; 

	}

	static double readDbNumber()
	{
		double x; 
		cout << "Please enter a double number : "; cin >> x; 
		while (cin.fail() || x / int(x) == 1)
		{
			if (cin.fail())
			{
				cin.clear(); 
				cin.ignore(INT_MAX, '\n'); 
				cout << "Invalide input !!! try again : "; cin >> x; 
			}
			else
			{
				cout << "This input is not a double please try again : "; cin >> x; 
			}
		}
		return x; 
	}

	static double readDbBetween(double a, double b)
	{
		double x = readDbNumber(); 

		while (x < a || x > b)
		{
			cout << "\nThe number is not withing the range, try again : \n"; 
			x = readDbNumber(); 
		}
		return x; 

	}

	static bool isValideDate(clsDate d)
	{
		return  clsDate::IsValidDate(d);
	}


	
};

