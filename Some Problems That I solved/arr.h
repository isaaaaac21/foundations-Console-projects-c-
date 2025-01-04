#pragma once
#include <iostream>
#include <string>
#include "myLib.h"
using namespace std;  
namespace arr
{
    void fillArray(int arr[100], int& length)
    {
        cout << "Please enter how many numbers do you want in your array : "; cin >> length;
        for (int i = 0; i < length; i++)
        {
            arr[i] = myLib::randomNum(1, 100);
        }
    }


    void printArray(int arr[100], int length)
    {
        cout << "[ ";
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << " ]" << endl;
    }


    void fillOrder(int arr[100], int length)
    {
        for (int i = 0; i < length; i++)
        {
            arr[i] = i + 1;
        }
    }

    void printStringArray(string arr[100], int length)
    {

        for (int i = 0; i < length; i++)
        {
            cout << "Array [" << i + 1 << "] : ";
            cout << arr[i] << endl; ;
        }

    }

}
namespace matrix
{
    void matrix(int arr[3][3], int rows, int columns)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                arr[i][j] = myLib::randomNum(1, 5);
            }
        }
    }
    void printMatrix(int arr[3][3], int rows, int columns)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    int minInMatrix(int arr[3][3], short rows, short columns)
    {
        int minim = arr[0][0];
        for (int i = 0; i < rows; i++)
        {
            for (int x = 0; x < columns; x++)
            {
                if (arr[i][x] < minim) minim = arr[i][x];
            }
        }
        return minim;
    }

    int maxInMatrix(int arr[3][3], short rows, short columns)
    {
        int maxim = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int x = 0; x < columns; x++)
            {
                if (arr[i][x] > maxim) maxim = arr[i][x];
            }
        }
        return maxim;
    }
    int sumOfMatrix(int arr[3][3], short rows, short columns)
    {
        int sum = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int x = 0; x < columns; x++)
            {
                sum += arr[i][x];
            }
        }
        return sum;
    }

}