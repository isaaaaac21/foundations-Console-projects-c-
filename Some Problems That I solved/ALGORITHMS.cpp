#pragma warning(disable : 4996) 

#include <iostream> 
#include <iomanip>
#include <string>
#include <vector> 
#include <set> 
#include <map>
#include <ctime>
#include <algorithm>
#include <cmath>
#include "input.h"
#include "printing.h"
#include <fstream>
#include "stringPro.h"
#include "client.h"
#include "date.h"
using namespace date;
using namespace std;
using namespace client; 

enum enNumbers {One = 1, };


//struct sdate
//{
//    int year; 
//    int month; 
//    int day; 
//};

sdate readDate()
{
    sdate date;
    cout << "Please Enter a year : "; cin >> date.year;
    cout << "Please Enter a month : "; cin >> date.month;
    cout << "Please enter a day : "; cin >> date.day;
    return date; 
}

struct period
{
    sdate start; 
    sdate end; 
};








sdate getSystemDate()
{
    sdate date; 

    time_t tim = time(0); 
    tm* now = localtime(&tim); 

    date.year = now->tm_year + 1900; 
    date.month = now->tm_mon + 1; 
    date.day = now->tm_mday; 

    return date; 

}


int yourAgeWithDays(sdate date)
{
    sdate current;
    current.year = 2024; current.month = 10; current.day = 24; 

    return dayDifference(date, current); 
}


void isEndOfWeek(sdate date)
{
    int orderDay = dayInweek(date); 
    if (orderDay == 6) cout << "Yes  its the end of week :-)" << endl;
    else cout << "No its not the end of week " << endl; 
}
bool isWeekEnd(sdate date)
{
    int dayOrder = dayInweek(date);
    if (dayOrder == 6 || dayOrder == 5)return true;
    return false; 
}

bool isBusinessDay(sdate date)
{
    return(!isWeekEnd(date));
    
}

int daysUntilTheEndOfWeek(sdate d)
{
    int i = 0; 
    while (dayInweek(d) != 6)
    {
        d = increaseDateByOne(d); 
        i++; 
    }
    return i; 
}

int daysUntilTheEndOfMonth(sdate d)
{

    int numOfDays = NumberOfdaysInMonth(d.month, isLeapYear(d.year));
    return numOfDays - d.day + 1;
}

int daysUntilTheEndOfYear(sdate d)
{
    int daysFromBegin = numOfDaysFromTheBeginningOfTheYear(d.year, d.month, d.day);

    return (isLeapYear(d.year) ? 366 : 365) - daysFromBegin + 1; 





}

bool operator == (sdate d1, sdate d2)
{
    return d1.day == d2.day && d1.month == d2.month && d1.year == d2.year; 
}
int vacationPeriod(sdate d1, sdate d2)
{
    int totalVacationDays = dayDifference(d1, d2); 

    while (true)
    {
        if (d1 == d2) break; 
        if (isWeekEnd(d1)) totalVacationDays--; 
        d1 = increaseDateByOne(d1); 
    }
    return totalVacationDays;
}

sdate vacationEndDate(sdate start, int days)
{

    while (days > 0)
    {
        if (!isWeekEnd(start)) days--; 

        start = increaseDateByOne(start); 
    }
    while (isWeekEnd(start))
    {
        start = increaseDateByOne(start);
    }
    return start; 
}

bool date1AfterDate2(sdate d1, sdate d2)
{
    return (!date1LessThanDate2(d1, d2) && !IsDate1EqualDate2(d1, d2)); 
}

//while date 1 before date2, if day == week dont decrease the remaining days else decrease them, and increase the date by one

int compareDates(sdate d1, sdate d2)
{
    return date1LessThanDate2(d1, d2) ? -1 : IsDate1EqualDate2(d1, d2) ? 0 : 1;
}



bool overlapPer(period p1, period p2)
{
    if (date1AfterDate2(p2.start, p1.end) || date1LessThanDate2(p2.end, p1.start)) return false; 
    return true;
    
}

int periodLength(period p, bool endDay = false)
{
    return endDay ? dayDifference(p.start, p.end) +1 : dayDifference(p.start, p.end); 
}

bool isDateWithingPeriod(period p, sdate d)
{
    if (IsDate1EqualDate2(d, p.start) || IsDate1EqualDate2(d, p.end)) return true; 
    if (date1AfterDate2(d, p.start) && date1LessThanDate2(d, p.end)) return true; 
    return false;
}


int overlapingDays(period p1, period p2)
{
    int days = 0; 
    while (overlapPer(p1, p2))
    {
        days++;
        p2.start= increaseDateByOne(p2.start);
    }
    return days; 
}

bool validateDate(sdate d)
{
 
    if (d.day < 1 || d.day > NumberOfdaysInMonth(d.month, isLeapYear(d.year)) || d.month <1 
        || d.month > 12) return false;

    return true; 
}


sdate stringToDate(string date)
{
    sdate d; 
    vector <int> vecDate = stringPro::splitingInt(date, "/"); 
    
    d.day = vecDate[0];
    d.month = vecDate[1]; 
    d.year = vecDate[2]; 
    return d; 
}


string dateToString(sdate d)
{
    string result;
    result += to_string(d.day) + '/'; 
    result += to_string(d.month) + '/'; 
    result += to_string(d.year); 
    return result;
    
}


void dayFormat(sdate d, string format = "dd/mm/yyyy")
{
    cout << dateToString(d) << endl; 
    if (format == "yyyy/dd/mm") cout << d.year << "/" << d.day << "/" << d.month << endl;
    else if (format == "mm/dd/yyyy") cout << d.month << "/" << d.day << "/" << d.year << endl;
    else if (format == "mm-dd-yyyy")cout << d.month << "-" << d.day << "-" << d.year << endl;
    else if (format == "dd-mm-- yyyy") cout << d.day << "-" << d.month << "-" << d.year << endl;

    cout << "Day : " << d.day << ", Month : " << d.month << ", Year : " << d.year << endl; 
}


int main()
{
    //period p1;
    //cout << "Enter period 1 :" << endl; 
    //cout << "Enter start date : \n" << endl;
    //p1.start = readDate();
    //cout << endl << endl;  
    //
    //cout << "Enter end date : \n" << endl;
    //p1.end = readDate();

    //cout << endl << endl; 

    //period p2;
    //cout << "Enter period 2 :" << endl; 
    //cout << "Enter start date : \n" << endl;
    //p2.start = readDate();
    //cout << endl << endl;  
    //
    //cout << "Enter end date : \n" << endl;
    //p2.end = readDate();
    //cout << endl << endl; 
    //

    string stDate = input::strInput();
    
    sdate  d = stringToDate(stDate); 

    //cout << "Day : " << d.day << endl << "Month : " << d.month << endl << "Year : " << d.year << endl; 

    dayFormat(d);

   /* cout << "Overlaping days : " << overlapingDays(p1, p2) << endl;*/

    //if (overlapPer(p1, p2)) cout << "Yes periods overlap" << endl;
    //else cout << "No periods don't overlap " << endl;





}