/*
 * Exercise 3.39:
 * Write a program to compare two strings. Now write a
 * program to compare the values of two C-style character strings.
 */
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <cstring>

int main()
{
    string s1 = "Simple string";
    string s2 = "Another string";

    if (s1 == s2) 
        cout << "Strings are equal" << endl;
    else if (s1 < s2)
        cout << "First string is less than second" << endl;
    else
        cout << "Second string is less than first" << endl;

    const char *cc1 = "Simple string";
    const char *cc2 = "Another string";

    if (strcmp(cc1, cc2) == 0)
        cout << "Strings are equal" << endl;
    else if (strcmp(cc1, cc2) > 0)
        cout << "Second string is less than first" << endl;
    else
        cout << "First string is less than second" << endl;

    return 0;
}
