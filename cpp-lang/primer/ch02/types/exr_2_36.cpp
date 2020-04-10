#include <iostream>
using namespace std;

int main()
{
    int a = 3, b = 4;
    decltype(a) c = a; // c has type 'int'
    decltype((b)) d = a; // d has type 'int&'
    ++c;
    ++d;
    // a == 4
    // b == 4
    // c == 4
    // d == 4
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;

    return 0;
}