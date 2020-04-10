#include <iostream>
#include <climits>
using namespace std;

int main()
{
    unsigned u1 = 42, u2 = 10;
    if ((u1 - u2) == 32)
        cout << "OK" << endl;
    else
        cout << "Try Again" << endl;

    if ((u2 - u1) == (UINT_MAX + 1 - 32))
        cout << "OK" << endl;
    else
        cout << "Try Again" << endl;

    int i1 = 42, i2 = 10;
    if ((i1 - i2) == 32)
        cout << "OK" << endl;
    else
        cout << "Try Again" << endl;

    if ((i2 - i1) == -32)
        cout << "OK" << endl;
    else
        cout << "Try Again" << endl;

    if ((i2 - u2) == 0)
        cout << "OK" << endl;
    else
        cout << "Try Again" << endl;

    if ((u2 - i2) == 0)
        cout << "OK" << endl;
    else
        cout << "Try Again" << endl;

    return 0;
}