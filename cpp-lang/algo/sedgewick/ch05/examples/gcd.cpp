/*
 * Euclid's algorithm.
 */

#include <iostream>
using std::cout;
using std::endl;

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m % n);
}

int main()
{
    cout << gcd(314158, 271828) << endl;
    return 0;
}
