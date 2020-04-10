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

StrBlobPtr &StrBlobPtr::operator++()
{
    check(_curr, "increment past end of StrBlobPtr");
    ++_curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
    check(--_curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(size_t n)
{
    check(_curr + n, "arithmetic '+' past end of StrBlobPtr");
    _curr += n;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n)
{
    check(_curr - n, "arithmetic '-' past begin of StrBlobPtr");
    _curr -= n;
    return *this;
}

string &StrBlobPtr::operator*() const
{
    auto p = check(_curr, "dereference past end");
    return (*p)[_curr];
}

string *StrBlobPtr::operator->() const
{
    return &(this->operator*());
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
