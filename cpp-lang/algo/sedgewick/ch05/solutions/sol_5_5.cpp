/*
 * Exercise 5.5.
 * Provide a nonrecurcive implementation of Euclid's algorithm.
 */

#include "chapter05.h"

using namespace std;

int gcd(int m, int n)
{
    while (n != 0) {
        int t = m;
        m = n;
        n = t % n;
    }
    return m;
}

void sol_5_5()
{
    cout << "Nonrecursive implementation of Euclid's algorithm" << endl;

    int n = 0;
    int m = 0;

    cout << "Type the first value: ";
    cin >> n;

    cout << "Type the second value: ";
    cin >> m;

    cout << gcd(m, n) << endl;

    print_separator();
}
