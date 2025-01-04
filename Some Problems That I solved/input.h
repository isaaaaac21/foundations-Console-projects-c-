#pragma once
#include <iostream>
#include <string>

using namespace std; 
namespace input {

	string strInput()
	{
		string word; 
		cout << "Enter : ";
		cin >> word; 
		return word; 
	}

	int intInput()
	{
		int x; 
		cout << "Enter a number : ";
		cin >> x; 
		return x; 
	}

	char charInput()
	{
		char ch;
		cout << "Enter a character : "; cin >> ch; 
		return ch;
	}











}