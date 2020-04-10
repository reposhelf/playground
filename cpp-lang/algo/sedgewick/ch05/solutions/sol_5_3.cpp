/*
 * Exercise 5.3.
 * Give the sequences of argument values that result when program 5.3 is 
 * invoked for each of the integers 1 through 9.
 */

#include "chapter05.h"

using namespace std;

int puzzle(int n)
{
    cout << n << endl;

    if (n == 1)
        return 1;

    if (n % 2 == 0)
        return puzzle(n / 2);
    else
        return puzzle(3 * n +1);
}

void sol_5_3()
{
    cout << "Program invokes program 5.3 for each integers 1 through 9:" << endl;

    for (int i = 1; i <= 9; ++i) {
        cout << "The sequence of agument value " << i << " is:" << endl;
        puzzle(i);
    }
    print_separator();
}
