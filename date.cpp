//
// *******************************************************************************
// *******************************************************************************
// * Name: Shawn Plain
// * File: Data.cpp
// * Class: COP3330 *
// * Description: The date Class file for Assignment #2, COP3330. *
// * Decalares the member functions, getters and accessors of the date Class,
// * as well as constructors. All logic for what is outlined in date.h
// * lives in this file.
// * Author: Shawn Plain *
// * date: February 02, 2024 *
// * NOTE: I tried very hard to find what/where the header that I lost 5 points on in the previous
// * assingment is to be and look like, and I could not find it, but I saw this in the driver file
// * and am using it as a template.
// *******************************************************************************
// *******************************************************************************


#include <iostream>
#include <iomanip>
#include "date.h"



using namespace std;


//Constructors
date::date()
{
    month = 1;
    day = 1;
    year = 2000;

}

date::date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;

    if (!isValidDate(m, d, y))
    {
        Set(1,1,2000);
    }

}

//mutators
bool date::Set(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;

   if (!isValidDate(m, d , y))
   {
       Set(1,1,2000);
       return false;
   } else
   {
       return true;
   }

}

bool date::setFormat(char f)
{
    char formatCode = toupper(f);

    switch(formatCode)
    {
        case 'D':
            format = "Default";
            break;
        case 'T':
            format = "Two-Digit";
            break;
        case 'L':
            format = "Long";
            break;
        case 'J':
            format = "Julian";
            break;
        default:
            //invalid format, do not alter current setting
            return false;
    }

    return true;
}


//accessors
int date::getMonth() const
{
    return month;
}

int date::getDay() const
{
    return day;
}

int date::getYear() const
{
    return year;
}

//member functions

const bool date::isValidDate(int m, int d, int y) {

    if (y < 1582 || (y == 1582 && (m < 10 || (m == 10 && d < 1))))
    {
        return false;
    }

    //days in each month
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //leap year
    if ((y % 4 == 0 && y % 100 != 0 || y % 400 == 0))
    {
        daysInMonth[2] = 29;
    }

    return (d >= 1 && d <= daysInMonth[m]);

}

void date::Input()
{
    int inputMonth, inputDay, inputYear;

    // Prompt user for input
    cout << "\nEnter a date in the format month/day/year (e.g., 1/4/2000): ";
    char separator;
    cin >> inputMonth >> separator >> inputDay >> separator >> inputYear;

    // Check for invalid input and use the default date if necessary
    if ( separator != '/' || !isValidDate(inputMonth, inputDay, inputYear))
    {

        // Set to default date
        Set(1, 1, 2000);
    } else
    {
        // Valid input, set the date
        Set(inputMonth, inputDay, inputYear);
    }
}

const void date::Show()
{
    // Function to display the date based on the current format setting
    if (format == "Default")
    {
        // Default format: M/D/Y
        cout << month << '/' << day << '/' << year;
    } else if (format == "Two-Digit")
    {
        // Two-Digit format: mm/dd/yy
        cout << setfill('0') << setw(2) << month << '/'
             << setw(2) << day << '/' << setw(2) << (year % 100);
    } else if (format == "Long")
    {
        // Long format: month D, Y
        const char* monthNames[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                                    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        cout << monthNames[month] << ' ' << day << ", " << year;
    } else if (format == "Julian")
    {
        // Julian format: DDD, Y
        // a simple calculation assuming January 1 is day 1
        int julianDate = day;
        for (int i = 1; i < month; ++i)
        {
            julianDate += (i == 2 && (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 29 : 28;
            julianDate += (i <= 7) ? ((i % 2 == 1) ? 31 : 30) : ((i % 2 == 0) ? 31 : 30);
        }
        cout << julianDate << ", " << year;
    }
}

void date::Increment(int numDays) {
    // Function to move the date forward by the specified number of days
    if (numDays < 0) {
        cout << "Invalid increment value. Must be a positive integer." << endl;
        return;
    }

    // Loop to increment the date by one day at a time
    for (int i = 0; i <= numDays; ++i) {
        // Calculate the number of days in the current month
        int daysInMonth = 31;  // Default for most months
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        } else if (month == 2) {
            // Adjust for leap years
            daysInMonth = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28;
        }

        // Increment the day
        ++day;

        // Check if day exceeds the number of days in the current month
        if (day > daysInMonth) {
            // Move to the next month and reset day to 1
            ++month;
            day = 1;

            // Check if month exceeds 12
            if (month > 12) {
                // Move to the next year and reset month to 1
                ++year;
                month = 1;
            }
        }
    }
}

int date::Compare(const date& d) const {
    // Function to compare two date objects and return the result
    if (year < d.year || (year == d.year && month < d.month) || (year == d.year && month == d.month && day < d.day)) {
        return -1;  // The calling object comes first chronologically
    } else if (year == d.year && month == d.month && day == d.day) {
        return 0;   // The objects are the same date
    } else {
        return 1;   // The parameter object comes first chronologically
    }
}