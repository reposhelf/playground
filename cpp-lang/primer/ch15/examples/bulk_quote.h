#ifndef BULK_QUOTE_H
#define BULK_QUOTE_H

#include "quote.h"

#include <string>

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& bookNo, double price,
               std::size_t qty, double disc) 
        : Quote(bookNo, price), m_min_qty(qty), m_discount(disc){}
    double net_price(std::size_t n) const override {
        if (n >= m_min_qty)
            return n * (1.0 - m_discount) * m_price;
        else
            return n * m_price;
    }

    Bulk_quote *clone() const &
    {
        return new Bulk_quote(*this);
    }

    Bulk_quote *clone() &&
    {
        return new Bulk_quote(std::move(*this));
    }

private:
    std::size_t m_min_qty = 0;
    double m_discount = 0.0;
};

#endif
