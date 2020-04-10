#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data
{
public:
    Sales_data() = default;
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(p*n) { }
    Sales_data(std::istream &);
    Sales_data &operator=(const Sales_data&);
    Sales_data &operator+=(const Sales_data&);
    operator std::string() const;
    operator double() const;

    std::string isbn() const { return bookNo; }
    double avg_price() const;
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    friend std::ostream &operator<<(std::ostream &os, const Sales_data&);
    friend std::istream &operator>>(std::istream &is, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    friend bool operator==(const Sales_data&, const Sales_data&);
    friend bool operator!=(const Sales_data&, const Sales_data&);
};

inline std::ostream &operator<<(std::ostream &os, const Sales_data &rhs)
{
    return os << rhs.isbn() << " " << rhs.units_sold << " "
              << rhs.revenue << " " << rhs.avg_price();
}

inline std::istream &operator>>(std::istream &is, Sales_data &rhs)
{
    double price = 0.0;
    is >> rhs.bookNo >> rhs.units_sold >> price;
    if (is)
        rhs.revenue = price * rhs.units_sold;
    else
        rhs = Sales_data();
    return is;
}

inline Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

inline bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.bookNo == rhs.bookNo;
}

inline bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}

#endif
