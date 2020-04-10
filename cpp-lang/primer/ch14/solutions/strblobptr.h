#ifndef STRBLOBPTR_H
#define STRBLOBPTR_H

#include <memory>
#include <vector>
#include <string>

class StrBlob;
class StrBlobPtr
{
public:
    StrBlobPtr();
    StrBlobPtr(StrBlob &sb, std::size_t sz = 0);
    std::string &operator[](size_t n) { return (*_wptr.lock())[n]; }
    const std::string &operator[](size_t n) const { return (*_wptr.lock())[n]; }
    // prefix
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    // postfix
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    // arithmetic operations
    StrBlobPtr &operator+=(std::size_t n);
    StrBlobPtr &operator-=(std::size_t n);
    // access operations
    std::string &operator*() const;
    std::string *operator->() const;

    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);

    int mem = 31;

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> _wptr;
    std::size_t _curr;
};

inline bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs._wptr.lock() == rhs._wptr.lock() && lhs._curr == rhs._curr;
}

inline bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

inline StrBlobPtr operator+(const StrBlobPtr &sbp, std::size_t n)
{
    StrBlobPtr ret = sbp;
    ret += n;
    return ret;
}

inline StrBlobPtr operator-(const StrBlobPtr &sbp, std::size_t n)
{
    StrBlobPtr ret = sbp;
    ret -= n;
    return ret;
}

#endif
