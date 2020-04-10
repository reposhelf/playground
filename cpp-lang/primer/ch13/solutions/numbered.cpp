#include "numbered.h"

#include <iostream>

using namespace std;

size_t numbered::counter = 0;

numbered::numbered()
    : _mysn(counter++) {}

numbered::numbered(const numbered &)
    : _mysn(counter++) {}

size_t numbered::mysn() const
{
    return _mysn;
}

void f(const numbered &s)
{
    cout << s.mysn() << endl;
}

void test_numbered()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}