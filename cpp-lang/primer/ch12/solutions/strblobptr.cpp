#include "strblobptr.h"
#include "strblob.h"

using namespace std;

StrBlobPtr::StrBlobPtr()
    : _curr(0)
{
}

StrBlobPtr::StrBlobPtr(StrBlob &sb, size_t sz)
    : _wptr(sb._data), _curr(sz)
{
}

string &StrBlobPtr::deref() const
{
    auto p = check(_curr, "dereferense past end");
    return (*p)[_curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(_curr, "increment past end");
    ++_curr;
    return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = _wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}
