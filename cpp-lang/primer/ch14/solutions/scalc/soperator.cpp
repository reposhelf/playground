#include "soperator.h"

#include <iostream>

using namespace std;

const string SOperator::ADD_STR = "+";
const string SOperator::SUB_STR = "-";
const string SOperator::MUL_STR = "x";
const string SOperator::DIV_STR = "/";
const string SOperator::MOD_STR = "%";
const string SOperator::RES_STR = "=";

SOperator::SOperator(const string &sign)
    : m_sign(sign)
{

}

bool SOperator::isEmpty() const
{
    return m_sign.empty();
}

bool SOperator::isValid() const
{
    if (m_sign == ADD_STR || m_sign == SUB_STR || m_sign == DIV_STR
            || m_sign == MUL_STR || m_sign == MOD_STR || m_sign == RES_STR) {
        return true;
    }

    cerr << "SOperator::Error: invalid operator " << "'" << m_sign << "'. "
         << "Valid operators are: '+', '-', '*', '/' and '%" << endl;

    return false;
}

void SOperator::clear()
{
    m_sign.clear();
}

void SOperator::setSign(const string &sign)
{
    m_sign = sign;
}
