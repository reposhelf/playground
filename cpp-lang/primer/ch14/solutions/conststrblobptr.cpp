#include "conststrblobptr.h"
#include "strblob.h"

using namespace std;

ConstStrBlobPtr::ConstStrBlobPtr()
    : _curr(0)
{
}

ConstStrBlobPtr::ConstStrBlobPtr(const StrBlob &sb, size_t sz)
    : _wptr(sb._data), _curr(sz)
{
}

const string &ConstStrBlobPtr::operator*() const
{
    auto p = check(_curr, "dereference past end");
    return (*p)[_curr];
}

const string *ConstStrBlobPtr::operator->() const
{
    return &(this->operator*());
}

shared_ptr<vector<string>> ConstStrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = _wptr.lock();
    if (!ret)
        throw runtime_error("unbound ConstStrBlobPtr");
    if (i >= ret->size())
        throw out_of_range(msg);
    return ret;
}
