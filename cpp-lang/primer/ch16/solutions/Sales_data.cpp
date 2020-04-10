#include <iostream>
using std::istream; using std::ostream;

#include "Sales_data.h"
Sales_data::Sales_data(std::istream &is) 
{
    // read will read a transaction from is into this object
    is >> *this;
}

Sales_data &Sales_data::operator=(const Sales_data &rhs)
{
    bookNo = rhs.bookNo;
    units_sold = rhs.units_sold;
    revenue = rhs.revenue;
    return *this;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data::operator std::string() const
{
    return bookNo + " " + std::to_string(units_sold)
        + " " + std::to_string(revenue)
        + " " + std::to_string(avg_price());
}

Sales_data::operator double() const
{
    return revenue;
}

double Sales_data::avg_price() const
{
    if (units_sold)
	return revenue/units_sold;
    else
	return 0;
}
/*
int main()
{
    Sales_data sd1("XXX-YYY-ZZZ", 1, 2.5);
    Sales_data sd2("XXX-YYY-ZZZ", 2, 2.5);
    sd1 += sd2;
    std::cout << sd1 << std::endl;

    Sales_data sd3("AAA-BBB-CCC", 10, 0.5);
    sd1 = sd3;
    std::cout << sd3 << std::endl;

    std::string sd3_str = sd3;
    std::cout << sd3_str << std::endl;

    double sd3_revenue = sd3;
    std::cout << sd3_revenue << std::endl;
    return 0;
}
*/
