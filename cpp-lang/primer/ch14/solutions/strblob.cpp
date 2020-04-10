#include "strblob.h"
#include "strblobptr.h"
#include "conststrblobptr.h"

#include <iostream>
#include <vector>

using namespace std;

StrBlob::StrBlob()
    : _data(make_shared<vector<string>>())
{
}

StrBlob::StrBlob(initializer_list<string> il)
    : _data(make_shared<vector<string>>(il))
{
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    _data->pop_back();
}

string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return _data->front();
}

const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return _data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return _data->back();
}

const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return _data->back();
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, _data->size());
}

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
    return ConstStrBlobPtr(*this, _data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const
{
    return ConstStrBlobPtr(*this, _data->size());
}

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= _data->size())
        throw out_of_range(msg);
}

int main()
{
    StrBlob sb1{"Hello"};
    StrBlob sb2;

    vector<string> v1{"Hello"};
    vector<string> v2;

    cout << (v1 == v2) << endl;
    cout << (sb1 == sb2) << endl << endl;

    cout << (v1 != v2) << endl;
    cout << (sb1 != sb2) << endl << endl;

    cout << (v1 < v2) << endl;
    cout << (sb1 < sb2) << endl << endl;

    cout << (v1 <= v2) << endl;
    cout << (sb1 <= sb2) << endl << endl;

    cout << (v1 > v2) << endl;
    cout << (sb1 > sb2) << endl << endl;

    cout << (v1 >= v2) << endl;
    cout << (sb1 >= sb2) << endl;

    cout << sb1[0] << endl;

//    const StrBlob csb = sb1;
//    csb[0] = 'Y'; // error
    return 0;
}
