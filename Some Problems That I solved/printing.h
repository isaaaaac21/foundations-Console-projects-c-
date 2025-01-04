#pragma once
#include <iostream>
#include <string>
using namespace std; 




namespace printing
{
	void printNumbers()
	{
		for (int i = 1; i <= 10; i++)
		{
			cout << i << " "; 
		}
	}
	void printAlpha()
	{
		for (int i = 'A'; i <= 'Z'; i++)
		{
			cout << char(i) << " "; 
		}
	}
}