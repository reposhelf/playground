#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &bookNo, double price)
        : m_bookNo(bookNo), m_price(price) {}
    virtual ~Quote() = default;
    std::string isbn() const { return m_bookNo; }
    virtual double net_price(std::size_t n) const
    { return n * m_price; }

    virtual Quote *clone() const &
    {
        return new Quote(*this);
    }

    virtual Quote *clone() &&
    {
        return new Quote(std::move(*this));
    }

protected:
    double m_price = 0.0;

private:
    std::string m_bookNo;
};

inline double print_total(std::ostream &os, const Quote &quote, size_t n)
{
    double ret = quote.net_price(n);
    os << "ISBN: " << quote.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

#endif
