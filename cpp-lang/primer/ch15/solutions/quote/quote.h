#ifndef QUOTE_H
#define QUOTE_H

#include <string>
#include <iostream>

class Quote
{
public:
    Quote() = default;
    Quote(const Quote &other)
        : m_bookNo(other.m_bookNo), m_price(other.m_price)
    {
        std::cout << __func__ << std::endl;
    }
    Quote &operator=(const Quote &rhs)
    {
        std::cout << __func__ << std::endl;

        m_bookNo = rhs.m_bookNo;
        m_price = rhs.m_price;
        return *this;
    }
    Quote(Quote &&other)
        : m_bookNo(std::move(other.m_bookNo)), m_price(std::move(other.m_price))
    {
        std::cout << __func__ << std::endl;
    }
    Quote &operator=(Quote &&rhs)
    {
        std::cout << __func__ << std::endl;

        m_bookNo = std::move(rhs.m_bookNo);
        m_price = std::move(rhs.m_price);
        return *this;
    }
    Quote(const std::string &bookNo, double price)
        : m_bookNo(bookNo), m_price(price) {}
    virtual ~Quote() = default;
    std::string isbn() const { return m_bookNo; }
    virtual double net_price(std::size_t n) const
    { return n * m_price; }
    virtual void debug() const
    {
        std::cout << typeid(*this).name() << std::endl;
        std::cout << "\tm_price: " << m_price << std::endl;
        std::cout << "\tm_bookNo: " << m_bookNo << std::endl;
    }

protected:
    double m_price = 0.0;

private:
    std::string m_bookNo;
};

#endif
