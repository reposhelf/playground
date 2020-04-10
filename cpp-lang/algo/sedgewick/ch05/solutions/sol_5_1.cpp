/*
 * Exercise 5.1.
 * Write a recursiive program to compute lg(N!).
 */

#include "chapter05.h"

#include <cmath>

using namespace std;

int factorial(int value)
{
    return value == 0 ? 1 : value * factorial(value - 1);
}

double log10factorial(int value)
{
    return log10(factorial(value));
}

void sol_5_1()
{
    cout << "A recursiive program to compute lg(N!):" << endl;

    cout << "Type a number: ";
    int number = 0;
    cin >> number;
    cout << log10factorial(number) << endl;

    print_separator();
}
