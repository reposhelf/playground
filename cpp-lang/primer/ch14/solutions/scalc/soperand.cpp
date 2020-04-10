#include "soperand.h"

using namespace std;

SOperand::SOperand(const string &value)
    : m_value(value)
{

}

bool SOperand::isEmpty() const
{
    return m_value.empty();
}

void SOperand::clear()
{
    m_value.clear();
}

void SOperand::setValue(const string &value)
{
    m_value = value;
}

SOperand::operator string() const
{
    return m_value;
}

SOperand::operator int() const
{
    return stoi(m_value);
}
