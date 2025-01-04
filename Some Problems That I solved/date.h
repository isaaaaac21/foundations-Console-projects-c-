#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;




namespace date
{
    struct sdate
    {
        int year;
        int month;
        int day;
    };
    bool isLeapYear(int year)
    {
        if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0) return true;

        return false;
    }
    int NumberOfdaysInMonth(int month, bool isLeapYear)
    {
        if (month == 2) return isLeapYear ? 29 : 28;
        return month > 7 ? (month % 2 == 0 ? 31 : 30) : (month % 2 != 0 ? 31 : 30);
    }

    string weekDay(int dayNum)
    {
        string arr[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thirsday", "Friday", "Saturday" };
        return arr[dayNum]; 
    }
    int dayInweek(sdate date)
    {
        string arr[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thirsday", "Friday", "Saturday"};
        int month = date.month; int year = date.year; int day = date.day; 
        int a = (14 - month) / 12;
        int y = year - a;
        int m = month + (12 * a) - 2;
        int d = (day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;

        return d; 
    }

    string numToMonth(int month)
    {
        string arr[13] = { " ", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
        return arr[month];
    }

    void calenHeader(int month)
    {
        cout << setw(15) << left << "_________________" << numToMonth(month) << setw(20) << left << "_______________\n" << endl;
        cout << setw(5) << left << "Sun" << setw(2) << left << " ";
        cout << setw(5) << left << "Mon" << setw(2) << left << " ";
        cout << setw(5) << left << "Tue" << setw(2) << left << " ";
        cout << setw(5) << left << "Wed" << setw(2) << left << " ";
        cout << setw(5) << left << "Thu" << setw(2) << left << " ";
        cout << setw(5) << left << "Fri" << setw(2) << left << " ";
        cout << setw(5) << left << "Sat" << setw(2) << left << " " << endl;
    }

    //void monthCalendar(int month, int year)
    //{
    //    calenHeader(month);

    //    int totalDays = NumberOfdaysInMonth(month, isLeapYear(year));
    //    int firstDay = dayInweek(dyear, month, 1);



    //    int x;
    //    for (x = 0; x < firstDay; x++)
    //    {
    //        cout << "       ";
    //    }
    //    for (int i = 1; i <= totalDays; i++)
    //    {
    //        if (x == 7)
    //        {
    //            cout << "\n";
    //            x = 0;
    //        }
    //        cout << setw(7) << left << i;
    //        x++;
    //    }
    //}

    //void yearClanedar(int year)
    //{
    //    cout << setw(50) << left << "______________________________________________________________\n" << endl;
    //    cout << setw(20) << left << " " << setw(10) << "Calendar " << year << endl;
    //    cout << setw(50) << left << "______________________________________________________________\n" << endl;

    //    cout << "\n\n";

    //    for (int i = 1; i <= 12; i++)
    //    {
    //        monthCalendar(i, year);
    //        cout << "\n\n";
    //    }
    //}

    int daysBeforeDate(int month, int year, int day)
    {
        int days = 0;
        for (int i = 1; i <= day; i++)
        {
            days++;
        }
        return days;
    }

    int numOfDaysFromTheBeginningOfTheYear(int year, int month, int day)
    {
        int totalDays = 0;
        bool isleap = isLeapYear(year);
        for (int i = 1; i < month; i++)
        {
            totalDays += NumberOfdaysInMonth(i, isleap);
        }
        totalDays += day;
        return totalDays;
    }

    sdate dateFromTotalDays(int year, int total)
    {
        sdate date;

        int totalDays = total;
        int month = 1;
        bool isleap = isLeapYear(year);
        while (totalDays - NumberOfdaysInMonth(month, isleap) >= 1)
        {
            totalDays -= NumberOfdaysInMonth(month, isleap);
            month++;

        }
        date.day = totalDays; date.month = month; date.year = year;
        return date;
    }

    sdate addDaysToDate(sdate d, int addDays)
    {
        int remainingDays = addDays + numOfDaysFromTheBeginningOfTheYear(d.year, d.month, d.day);
        short monthDays = 0; 
        d.month = 1; 

        while (true)
        {
            monthDays = NumberOfdaysInMonth(d.month, isLeapYear(d.year)); 

            if (remainingDays > monthDays)
            {
                remainingDays -= monthDays; 
                d.month++; 

                if (d.month > 12)
                {
                    d.month = 1; 
                    d.year++; 
                }
            }
            else
            {
                d.day = remainingDays; break; 
            }
        }
        return d; 

    }


    bool date1LessThanDate2(sdate Date1, sdate Date2)
    {
        return (Date1.year < Date2.year) ? true : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? true : (Date1.month == Date2.month ? Date1.day < Date2.day : false)) : false);

    }




    bool lastDayInMonth(sdate date)
    {
        int lastDay = NumberOfdaysInMonth(date.month, isLeapYear(date.year));

        return date.day == lastDay ? true : false;
    }
    bool lastMonthInYear(int month)
    {
        return month == 12 ? true : false;
    }

    sdate increaseDateByOne(sdate date)
    {
        if (lastDayInMonth(date) && lastMonthInYear(date.month))
        {
            date.year++;
            date.month = date.day = 1;
        }
        else if (lastDayInMonth(date))
        {
            date.month++;
            date.day = 1;
        }
        else
        {
            date.day++;
        }
        return date;
    }
    sdate increaseDateByOneWeek(sdate d)
    {
        return addDaysToDate(d, 7);
    }

    sdate increaseDateByXWeek(sdate d, int weeks)
    {
        int added = weeks * 7;
        return addDaysToDate(d, added);

    }
    sdate increaseDateByOneMonth(sdate d)
    {
        int added = NumberOfdaysInMonth(d.month, isLeapYear(d.year));
        return addDaysToDate(d, added);
    }
    sdate increaseDateByXMonths(sdate d, int months)
    {

        for (int i = 1; i <= months; i++)
        {
            d = increaseDateByOneMonth(d);
        }
        return d;
    }

    sdate increaseDateByOneYear(sdate d)
    {
        return addDaysToDate(d, isLeapYear(d.year) ? 366 : 365);
    }

    sdate increaseDateByXYears(sdate d, int x)
    {
        for (int i = 1; i <= x; i++)
        {
            d = increaseDateByOneYear(d);
        }
        return d;
    }

    sdate increaseDateByDecade(sdate s)
    {
        int x = 1;
        while (x <= 10)
        {
            s.year++;
            x++;
        }
        return s;
    }
    sdate decreaseDateByOneDay(sdate d)
    {
        bool isleap = isLeapYear(d.year);
        if (d.day == 1)
        {
            if (d.month == 1)
            {
                d.day = 31;
                d.month = 12;
                d.year--;
            }
            else
            {
                d.month--;
                d.day = NumberOfdaysInMonth(d.month, isleap);
            }
        }
        else
        {
            d.day--;
        }
        return d;
    }
    sdate decreaseDateByXDays(sdate d, int days)
    {
        for (int i = 1; i <= days; i++)
        {
            d = decreaseDateByOneDay(d);
        }
        return d;
    }
    sdate decreaseDateByOneWeek(sdate d)
    {
        return decreaseDateByXDays(d, 7);
    }
    sdate decreaseDateByXWeeks(sdate d, int weeks)
    {
        for (int i = 1; i <= weeks; i++)
        {
            d = decreaseDateByOneWeek(d);
        }
        return d;
    }
    sdate decreaseDateByOneMonth(sdate d)
    {
        if (d.month == 1)
        {
            d.month = 12;
            d.year--;
        }
        else
        {
            d.month--;
        }
        short numOfDay = NumberOfdaysInMonth(d.month, isLeapYear(d.year));
        if (d.day > numOfDay)
        {
            d.day = numOfDay;
        }
        return d;
    }
    sdate decreaseDateByOneMonth(sdate d, int months)
    {
        for (int i = 1; i <= months; i++)
        {
            d = decreaseDateByOneMonth(d);
        }
        return d;
    }

    void swapDates(sdate& d1, sdate& d2)
    {
        sdate temp;
        temp.day = d1.day;
        temp.month = d1.month;
        temp.year = d1.year;

        d1.year = d2.year;
        d1.month = d2.month;
        d1.day = d2.day;

        d2.day = temp.day;
        d2.month = temp.month;
        d2.year = temp.year;
    }

    bool IsDate1EqualDate2(sdate Date1, sdate Date2)
    {
        return (Date1.year == Date2.year) ? ((Date1.month == Date2.month) ? ((Date1.day == Date2.day) ? true : false) : false) : false;
    }

    int dayDifference(sdate date1, sdate date2)
    {
        int days = 0;
        int swapFlags = 1;
        if (!date1LessThanDate2(date1, date2))
        {
            swapDates(date1, date2);
            swapFlags = -1;
        }
        while (date1LessThanDate2(date1, date2))
        {
            days++;
            date1 = increaseDateByOne(date1);
        }

        return days * swapFlags;
    }

}