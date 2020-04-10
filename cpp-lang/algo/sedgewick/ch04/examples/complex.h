#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
    Complex(float re, float im);
    float re() const { return m_re; }
    float im() const { return m_im; }
    Complex &operator*=(const Complex &rhs);

private:
    float m_re;
    float m_im;
};

inline std::ostream &operator<<(std::ostream &out, const Complex &complex)
{
    return (out << complex.re() << " " << complex.im());
}


#endif // COMPLEX_H
