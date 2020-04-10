#ifndef DISC_QUOTE_H
#define DISC_QUOTE_H

#include "quote.h"

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const Disc_quote &other)
        : Quote(other), m_quantity(other.m_quantity), m_discount(other.m_discount)
    {
        std::cout << __func__ << std::endl;
    }
    Disc_quote &operator=(const Disc_quote &rhs)
    {
        std::cout << __func__ << std::endl;

        Quote::operator=(rhs);
        m_quantity = rhs.m_quantity;
        m_discount = rhs.m_discount;
        return *this;
    }
    Disc_quote(Disc_quote &&other)
        : Quote(std::move(other)),
          m_quantity(std::move(other.m_quantity)),
          m_discount(std::move(other.m_discount))
    {
        std::cout << __func__ << std::endl;
    }
    Disc_quote &operator=(Disc_quote &&rhs)
    {
        std::cout << __func__ << std::endl;

        if (this != &rhs) {
            Quote::operator=(std::move(rhs));
            m_quantity = std::move(rhs.m_quantity);
            m_discount = std::move(rhs.m_discount);
        }
        return *this;
    }
    Disc_quote(const std::string &book, double price, std::size_t quantity, double discount)
        : Quote(book, price),
          m_quantity(quantity),
          m_discount(discount)
    {
    }
    double net_price(std::size_t) const = 0;

protected:
    std::size_t m_quantity = 0;
    double m_discount = 0.0;
};

#endif
