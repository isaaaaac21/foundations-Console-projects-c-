#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;



namespace stringPro
{

    string printFirstLetter(string s)
    {
        bool isFirstLetter = true;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ' ' && isFirstLetter) s[i] = tolower(s[i]);
            isFirstLetter = s[i] == ' ' ? true : false;
        }
        return s;
    }
    bool isVowel(char ch)
    {
        char c = tolower(ch);
        return  (c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i');
    }
    string trimRight(string s)
    {
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] != '#') return s.substr(0, i + 1);
        }
        return s;
    }
    vector <string> spliting(string s, string delimeter = " ") 
    {

        vector <string> result;
        int pos = 0;
        string word;

        while ((pos = s.find(delimeter)) != string::npos)
        {
            word = s.substr(0, pos);
            if (word != " ") result.push_back(word);
            s.erase(0, pos + delimeter.length());
        }
        if (!s.empty()) result.push_back(s);
        return result;
    }   
    
    vector <int> splitingInt(string s, string delimeter = " ") 
    {

        vector <int> result;
        int pos = 0;
        string word;

        while ((pos = s.find(delimeter)) != string::npos)
        {
            word = s.substr(0, pos);
            if (word != " ") result.push_back(stoi(word));
            s.erase(0, pos + delimeter.length());
        }
        if (!s.empty()) result.push_back(stoi(s));
        return result;
    }
    string replaceWord(string s, string word, string replaced, bool matchCase = false)
    {

        vector <string> vResult = spliting(s);

        string result;

        if (matchCase)
        {
            for (string i : vResult)
            {
                transform(i.begin(), i.end(), i.begin(), ::tolower);
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                if (i == word) i = replaced;
                result += i + ' ';
            }
        }
        else
        {
            for (string i : vResult)
            {
                if (i == word) i = replaced;
                result += i + ' ';
            }
        }
        return result;
    }
}