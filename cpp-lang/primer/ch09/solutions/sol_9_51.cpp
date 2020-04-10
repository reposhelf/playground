/*
 * Exercise 9.51:
 * Write a class that has three unsigned members representing year, month,
 * and day. Write a constructor that takes a string representing a date. Your
 * constructor should handle a variety of date formats, such as
 * January 1, 1900, 1/1/1900, Jan 1, 1900, and so on.
 */

#include <iostream>
using std::cout;
using std::endl;

#include "date.h"

int main()
{
    Date date("January 1, 1900");
    cout << date.month() << endl;
    cout << date.day() << endl;
    cout << date.year() << endl;

    Date date1("1/1/1900");
    cout << date1.month() << endl;
    cout << date1.day() << endl;
    cout << date1.year() << endl;

    Date date2("Jan 1, 1900");
    cout << date2.month() << endl;
    cout << date2.day() << endl;
    cout << date2.year() << endl;

    return 0;
}
