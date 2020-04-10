/*
 * Exercise 5.2.
 * Modify program 5.1 (ch05/examples/factorial.cpp) to compute N! mod M, such
 * that overflow is no longer issue. Try running your program for M = 997 and
 * N = 10^3, 10^4, 10^5, and 10^6, to get an indication of how your
 * programming system handles deeply nested recursive calls.
 */

#include "chapter05.h"

using namespace std;

void sol_5_2()
{
    cout << "Program to compute N! mode M:" << endl;

    cout << factorial(100000) % 997 << endl;

    print_separator();
}
