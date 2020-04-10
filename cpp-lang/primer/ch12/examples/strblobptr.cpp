#include "strblobptr.h"
#include "strblob.h"

using namespace std;

StrBlobPtr::StrBlobPtr()
    : curr(0)
{
}

StrBlobPtr::StrBlobPtr(StrBlob &sb, size_t sz)
    : wptr(sb.data), curr(sz)
{
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}
