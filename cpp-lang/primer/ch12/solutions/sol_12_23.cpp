/*
 * Exercise 12.23:
 * Write a program to concatenate two string literals, putting
 * the result in a dynamically allocated array of char. Write a program to
 * concatenate two library strings that have the same value as the literals
 * used in the first program.
 */

#include "chapter12.h"

#include <cstring>
#include <iostream>
#include <string>

using namespace std;

void sol_12_23_1()
{
    char *res = new char[50];
    strcpy(res, "Gens una ");
    strcat(res, "sumus!");
    cout << res << endl;
    delete [] res;
}

void sol_12_23_2()
{
    string s1("Gens una ");
    string s2("sumus!");
    s1 += s2;
    char *res = new char[50];
    strcpy(res, s1.c_str());
    cout << res << endl;
    delete [] res;
}
