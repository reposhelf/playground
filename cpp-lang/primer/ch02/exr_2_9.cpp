#include <iostream>
using namespace std;

int main()
{
    cin >> int value; // error: expected ';' before 'int value'
    double salary = wage = 9999.99; // ok
    int a = {3.14}; // error: narrowing conversion
    int b = 3.14; // ok (but bad way)
    return 0;
}