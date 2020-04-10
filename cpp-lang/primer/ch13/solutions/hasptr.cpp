#include "hasptr.h"

using namespace std;

HasPtr::HasPtr(const string &s)
    : ps(new string(s)), i(0) { }

HasPtr::HasPtr(const HasPtr &orig)
    : ps(new string(*(orig.ps))), i(orig.i) { }

HasPtr::HasPtr(HasPtr &&orig) noexcept
    : ps(orig.ps), i(orig.i)
{
    orig.ps = nullptr;
    i = 0;
}

// copy and swap technology
HasPtr &HasPtr::operator=(HasPtr other)
{
    swap(*this, other);
    return *this;
}

HasPtr::~HasPtr()
{
    delete ps;
}
