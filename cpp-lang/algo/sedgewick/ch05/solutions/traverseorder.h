#ifndef TRAVERSEORDER_H
#define TRAVERSEORDER_H

#include <memory>
#include <vector>
#include <initializer_list>
#include <iostream>

class TraverseOrder
{
public:
    TraverseOrder();
    TraverseOrder(std::initializer_list<int> init);

    void push_back(int i);

private:
    std::shared_ptr<std::vector<int>> _data;

    friend bool operator==(const TraverseOrder&, const TraverseOrder&);
    friend bool operator!=(const TraverseOrder&, const TraverseOrder&);
    friend std::ostream &operator<<(std::ostream&, const TraverseOrder&);
};

inline bool operator==(const TraverseOrder &lhs, const TraverseOrder &rhs)
{
    return *(lhs._data) == *(rhs._data);
}

inline bool operator!=(const TraverseOrder &lhs, const TraverseOrder &rhs)
{
    return !(lhs == rhs);
}

inline std::ostream &operator<<(std::ostream &os, const TraverseOrder &to)
{
    for (const auto &i : *(to._data))
        os << i << ' ';
    return os;
}

#endif