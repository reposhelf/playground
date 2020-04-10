#include "salesdata.h"

SalesData::SalesData(const std::string &bookNo,
		     unsigned unitsSold,
		     double price)
    : _bookNo(bookNo),
      _unitsSold(unitsSold),
      _revenue(price * unitsSold) 
{
}

SalesData::SalesData(const std::string &bookNo)
    : SalesData(bookNo, 0, 0.0)
{
}

SalesData::SalesData()
    : SalesData(std::string(), 0, 0.0)
{
}

SalesData::SalesData(std::istream &is)
    : SalesData(std::string(), 0, 0.0)
{
    read(is, *this);
}

SalesData &SalesData::combine(const SalesData &rhs)
{
    _unitsSold += rhs._unitsSold;
    _revenue += rhs._revenue;
    return *this;
}

SalesData add(const SalesData &lhs, const SalesData &rhs)
{
    SalesData sum = lhs;
    sum.combine(rhs);
    return sum;
}

std::istream &read(std::istream &is, SalesData &item)
{
    double price = 0.0;
    is >> item._bookNo >> item._unitsSold >> price;
    item._revenue = price * item._unitsSold;
    return is;
}

std::ostream &print(std::ostream &os, const SalesData &item)
{
    os << item.isbn() << " "
       << item._unitsSold << " "
       << item._revenue << " "
       << item.averagePrice();
    return os;       
}
