#ifndef LIMIT_QUOTE_H
#define LIMIT_QUOTE_H

#include "quote.h"

#include <string>

class Limit_quote : public Quote
{
public:
    Limit_quote() = default;
    Limit_quote(const std::string &bookNo, double price,
                std::size_t limit, double discount)
        : Quote(bookNo, price), m_limit(limit), m_discount(discount) {}
    double net_price(std::size_t n) const override {
        if (n <= m_limit)
            return n * (1.0 - m_discount) * m_price;
        else
            return n * m_price;
    }

    Limit_quote *clone() const &
    {
        return new Limit_quote(*this);
    }

    Limit_quote *clone() &&
    {
        return new Limit_quote(std::move(*this));
    }

private:
    std::size_t m_limit = 0;
    double m_discount = 0.0;
};

#endif
