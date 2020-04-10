#ifndef SALESDATA_H
#define SALESDATA_H

#include <string>
#include <iostream>

class SalesData
{
public:
    SalesData(const std::string &bookNo, unsigned unitsSold, double price);
    SalesData(const std::string &bookNo);
    SalesData();
    SalesData(std::istream &is);

    std::string isbn() const { return _bookNo; }
    SalesData &combine(const SalesData &rhs);

private:
    double averagePrice() const;

    std::string _bookNo;
    unsigned _unitsSold = 0;
    double _revenue = 0.0;

    friend std::istream &read(std::istream &is, SalesData &item);
    friend std::ostream &print(std::ostream &os, const SalesData &item);
};

SalesData add(const SalesData &lhs, const SalesData &rhs);
std::istream &read(std::istream &is, SalesData &item);
std::ostream &print(std::ostream &os, const SalesData &item);

inline double SalesData::averagePrice() const
{
    return _unitsSold ? _revenue / _unitsSold : 0;
}


#endif
