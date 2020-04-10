#include "complex.h"

Complex::Complex(float re, float im)
    : m_re(re), m_im(im)
{
}

Complex &Complex::operator*=(const Complex &rhs)
{
    float tempRe = re();
    m_re = re() * rhs.re() - im() * rhs.im();
    m_im = tempRe * rhs.im() + im() * rhs.re();
    return *this;
}
