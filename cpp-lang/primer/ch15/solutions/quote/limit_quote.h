#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include "disc_quote.h"

class Limit_quote : public Disc_quote
{
public:
    Limit_quote() = default;
    Limit_quote(const std::string &bookNo, double price, std::size_t limit, double discount)
        : Disc_quote(bookNo, price,limit, discount)
    {
    }

    double net_price(std::size_t n) const override
    {
        if (n <= m_quantity)
            return n * (1.0 - m_discount) * m_price;
        else
            return n * m_price;
    }
    void debug() const override
    {
        std::cout << typeid(*this).name() << std::endl;
        std::cout << "\tm_quantity: " << m_quantity << std::endl;
        std::cout << "\tm_discount: " << m_discount << std::endl;
    }
};

#endif
