#ifndef SHAREDHASPTR_H
#define SHAREDHASPTR_H

#include <string>

class SharedHasPtr
{
public:
    SharedHasPtr(const std::string &s = std::string());
    SharedHasPtr(const SharedHasPtr &);
    SharedHasPtr &operator=(SharedHasPtr);
    ~SharedHasPtr();

    const std::string &data() const { return *ps; }

private:
    std::string *ps;
    int i;
    size_t *use;

    friend bool operator==(const SharedHasPtr&, const SharedHasPtr&);
    friend void swap(SharedHasPtr&, SharedHasPtr&);
};

inline bool operator==(const SharedHasPtr &lhs, const SharedHasPtr &rhs)
{
    return lhs.ps == rhs.ps && *lhs.ps == *rhs.ps && lhs.i == rhs.i;
}

inline void swap(SharedHasPtr &lhs, SharedHasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    swap(lhs.use, rhs.use);
}

#endif