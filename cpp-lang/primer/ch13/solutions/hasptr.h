#ifndef HASPTR_H
#define HASPTR_H

#include <string>
#include <iostream>

class HasPtr
{
public:
    HasPtr(const std::string &s = std::string());
    HasPtr(const HasPtr&);
    HasPtr(HasPtr&&) noexcept;
    HasPtr &operator=(HasPtr);
    ~HasPtr();

    const std::string &data() const { return *ps; }
    int value() const { return i; }

private:
    std::string *ps;
    int i;

    friend void swap(HasPtr&, HasPtr&);
    friend bool operator<(const HasPtr&, const HasPtr&);
};

inline void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    // std::cout << "Before swap: lhs.ps: " << *lhs.ps << ";\trhs.ps: " << *rhs.ps << std::endl;
    swap(lhs.ps, rhs.ps);
    // std::cout << "After swap: lhs.ps: " << *lhs.ps << ";\trhs.ps: " << *rhs.ps << std::endl;

    // std::cout << "Before swap: lhs.i: " << lhs.i << ";\trhs.i: " << rhs.i << std::endl;
    swap(lhs.i, rhs.i);
    // std::cout << "After swap: lhs.i: " << lhs.i << ";\trhs.i: " << rhs.i << std::endl;
}

inline bool operator<(const HasPtr &lhs, const HasPtr &rhs)
{
    return *lhs.ps < *rhs.ps;
}

#endif
