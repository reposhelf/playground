#include "structx.h"

#include <iostream>
#include <vector>

using namespace std;

X::X()
{
    cout << "X()" << endl;
}

X::X(const X&)
{
    cout << "X(const X&)" << endl;
}

X::~X()
{
    cout << "~X()" << endl;
}

X &X::operator=(const X&)
{
    cout << "operator=(const X&)" << endl;
    return *this;
}

void pass_value_test(X) {}
void pass_ref_test_nc(X&) {}
void pass_ref_test_c(const X&) {}

void test_struct_x()
{
    X orig;
    X copy = orig;
    X copy_2(orig);
    copy = copy_2;
    pass_value_test(orig);
    pass_ref_test_nc(orig);
    pass_ref_test_c(orig);
    X *px = new X;
    X *pxcp = new X(*px);
    vector<X> vex;
    vex.push_back(orig);
    vex.push_back(copy);
    vex.push_back(copy_2);
    vex.push_back(*px);
    vex.push_back(*pxcp);
    delete pxcp;
    delete px;
}