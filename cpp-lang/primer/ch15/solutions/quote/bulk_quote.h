#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "disc_quote.h"

class Bulk_quote : public Disc_quote
{
public:
    using Disc_quote::Disc_quote;

    double net_price(std::size_t n) const override
    {
        if (n >= m_quantity)
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
