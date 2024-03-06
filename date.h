//
// *******************************************************************************
// *******************************************************************************
// * Name: Shawn Plain
// * File: Data.h
// * Class: COP3330 *
// * Description: The date Class is outlined in this file, with prototypes of what
// * will be defined further in date.cpp
// * lives in this file.
// * Author: Shawn Plain *
// * date: February 02, 2024 *
// *******************************************************************************
// *******************************************************************************


#ifndef DATE_DATE_H
#define DATE_DATE_H

#include <string>

using namespace std;

class date
{
private:
    int month;
    int day;
    int year;
    string format;

    const bool isValidDate(int m, int d, int y) ;

public:
    //CONSTRUCTORS
    date(); // Default constructor
    date(int m, int d, int y); // Specified Values


    //mutators
    bool Set(int m, int d, int y);
    bool setFormat(char f);



    //accessor
    int getMonth() const;
    int getDay() const;
    int getYear() const;


    //member funcs
    void Input();  // Function to input a date from the user
    const void Show();  // Function to display the date based on the curr
    void Increment(int numDays = 0);  // Function to move the date forward by the specified number of days
    int Compare(const date& d) const;  // Function to compare two date objects


};

#endif //DATE_DATE_H
