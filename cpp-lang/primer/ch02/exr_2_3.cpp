#include <iostream>
using namespace std;

int main()
{
    unsigned u1 = 42, u2 = 10;
    cout << u1 - u2 << endl;
    cout << u2 - u1 << endl;

    int i1 = 42, i2 = 10;
    cout << i1 - i2 << endl;
    cout << i2 -i1 << endl;
    cout << i2 - u2 << endl;
    cout << u2 - i2 << endl;
    return 0;
}