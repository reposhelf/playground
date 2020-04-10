#include "sharedhasptr.h"

using namespace std;

SharedHasPtr::SharedHasPtr(const string &s)
    : ps(new string(s)), i(0), use(new size_t(1)) { }

SharedHasPtr::SharedHasPtr(const SharedHasPtr &other)
    : ps(other.ps), i(other.i), use(other.use)
{
    ++*use;
}

// copy and swap technology
SharedHasPtr &SharedHasPtr::operator=(SharedHasPtr rhs)
{
    swap(*this, rhs);
    return *this;
}

SharedHasPtr::~SharedHasPtr()
{
    if (--*use == 0) {
        delete use;
        delete ps;
    }
}