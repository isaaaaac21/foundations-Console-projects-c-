#pragma once
#include <iostream>
using namespace std; 
namespace myLib
{


	int randomNum(int from, int to)
	{
		return rand() % (to - from + 1) +  from;
	}

	bool isPrime(int num)
	{
		if (num == 0 || num == 1) return false;
		for (int i = 2; i <= num / 2; i++)
		{
			if (num % i == 0) return false;
		}
		return true;

	}

	void swap(int& a, int& b)
	{
		int temp = 0;
		temp = a;
		a = b;
		b = temp;
	}






}