#ifndef CONSTSTRBLOBPTR_H
#define CONSTSTRBLOBPTR_H

#include <memory>
#include <string>
#include <vector>

class StrBlob;
class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr();
    ConstStrBlobPtr(const StrBlob &sb, std::size_t sz = 0);
    // access operations
    const std::string &operator*() const;
    const std::string *operator->() const;

    friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
    friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;

    std::weak_ptr<std::vector<std::string>> _wptr;
    std::size_t _curr;
};

inline bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return lhs._wptr.lock() == rhs._wptr.lock() && lhs._curr == rhs._curr;
}

inline bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

#endif
