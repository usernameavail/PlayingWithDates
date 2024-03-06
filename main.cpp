// *******************************************************************************
// *******************************************************************************
// * Name: main *
// * Class: COP3330 *
// * Description: Test driver for the date class, Assignment #2, COP3330. *
// * Tests to see if all of the methods have been declared in *
// * accordance with the specifications AND if the files have *
// * named properly. *
// * Author: Dr. David A. Gaitros *
// * MODIFIED BY : SHAWN PLAIN
// * date: FEB 02 2024 *
// * Copyright: This file is for use by students at Florida State University *
// * for the COP3330 course. *
// *******************************************************************************

#include <iostream>
#include "date.h"

using namespace std;

void PrintDates(date & d)
{
    d.setFormat('D');
    cout<<"Default Format: ";
    d.Show();


    d.setFormat('L');
    cout <<"\nLong Format: ";
    d.Show();


    d.setFormat('T');
    cout <<"\nTwo Digit: ";
    d.Show();


    d.setFormat('J');
    cout <<"\nJulian Format: ";
    d.Show();
}
int main(void) {
    bool status = false;
    int comparestatus = 0;

    date date1; // Test Default constructor
    cout << "\nTest Default Constructor" << endl;
    PrintDates(date1);


    date date2(2, 29, 2000); // Test 3 param with valid date
    cout << "\n\nTest 3 parameter Constructor with valid date" << endl;
    PrintDates(date2);


    date date3(15, 15, 1500); // Test 3 param with invalid date
    cout << "\n\nTest 3 parameter Constructor with invalid date" << endl;
    PrintDates(date3);

    status = date3.Set(2,18,1955);
    cout << "\n\nSet with a valid date of 2-18-1955):\n";
    PrintDates(date3);

    status = date3.Set(60,60,1500);
    cout << "\n\nSet with an invalid date of 60-60-1500:\n";
    PrintDates(date3);
// *******************************************************************************
// * Test input, three values. Valid, valid with leap, invalid *
// *******************************************************************************
    date2.Input(); // Test the Input method
    PrintDates(date2);
    date2.Input();
    PrintDates(date2);
    date2.Input();
    PrintDates(date2);


  // *******************************************************************************
// * Test the GetMonth, GetDay, GetYear methods *
// *******************************************************************************
cout <<"Test GetMonth(), GetDay() and GetYear(): ";

cout << date2.getMonth()<<'/'<<date2.getDay()<<'/'<<date2.getYear()<<endl;

cout <<"\n\nTest Increment() with default date: ";

date1.Increment(); // Test Increment with no parameters

PrintDates(date1);

date1.Increment(365); // Test Increment with one parameter

cout << "\n\nTest Increment(365) to add a year: ";

PrintDates(date1);

cout<<"\nCompare, First date is 2-18-1955, second date is 2-18-2019, status is:";

date1.Set(2,18,1955); date2.Set(2,18,2019);
comparestatus=date1.Compare(date2); // Test Compare method
cout<<comparestatus<< endl;

cout<<"\nCompare, First date is 2-18-1955, second date is 2-18-1955, status is:";
date1.Set(2,18,1955); date2.Set(2,18,1955);
comparestatus=date1.Compare(date2); // Test Compare method
cout<<comparestatus<< endl;
cout<<"Compare, First date is 2-18-1955, second date is 2-18-1945, status is:";
date1.Set(2,18,1955); date2.Set(2,18,1945);
comparestatus=date1.Compare(date2); // Test Compare method
cout<<comparestatus<< endl;
return 0;
}


