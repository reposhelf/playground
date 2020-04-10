#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    bool b = 42;
    cout << "bool b = 42; // b is " << bool(b) << endl;
    b = 0;
    cout << "bool b = 0; // b is " << bool(b) << endl;

    int i = true;
    cout << "int i = true; // i is " << i << endl;
    i = false;
    cout << "int i = false; // i is " << i << endl;

    i = 3.14;
    cout << "int i = 3.14; // i is " << i << endl;

    unsigned char c = -1;
    cout << "unsigned char c = -1; // c is " << int(c) << endl;

    signed char c2 = 256;
    cout << "signed char c2 = 256; // c2 is " << int(c2) << endl;

    //============================================================================================
    unsigned u = 10;
    i = -42;
    cout << "unsigned u = 10, int i = -42: i + i = " << i + i << endl;
    cout << "unsigned u = 10, int i = -42: u + i = " << u + i << endl;

    unsigned u1 = 42, u2 = 10;
    cout << "unsigned u1 = 42, unsigned u2 = 10: u1 - u2 = " << u1 - u2 << endl;
    cout << "unsigned u1 = 42, unsigned u2 = 10: u2 - u1 = " << u2 - u1 << endl;

    //============================================================================================
    // print numberd from 10 to 0. use 'unsigned' type for counter
    // a. error! endless loop here
    // for (unsigned k = 10; k >= 0; --k)
    //     cout << k << endl;

    // b. OK
    unsigned k = 11;
    while (k > 0) {
        --k;
        cout << k << endl;
    }

    return 0;
}