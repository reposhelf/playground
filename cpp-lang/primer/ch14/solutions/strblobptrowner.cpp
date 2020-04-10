#include "strblobptr.h"

#include <iostream>

using std::cout;
using std::endl;

class StrBlobPtrOwner
{
public:
    StrBlobPtrOwner(): ptr(new StrBlobPtr) {}
    ~StrBlobPtrOwner() { delete ptr; }

    StrBlobPtr *operator->() const { return &(*ptr); }

    StrBlobPtr *ptr;
};

int main()
{
    StrBlobPtrOwner o;

    cout << o->mem << endl;

    return 0;
}
