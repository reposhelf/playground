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

    std::string &deref() const;
    StrBlobPtr &incr();

    friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
    friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);

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

#endif
