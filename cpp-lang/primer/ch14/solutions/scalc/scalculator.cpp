#include "scalculator.h"

using namespace std;

bool SCalculator::isValid() const
{
    return m_expression.isValid();
}

void SCalculator::clear()
{
    m_expression.clear();
}

void SCalculator::updateValue(const string &value)
{
    m_expression.setOperand(SOperand(value));
}

void SCalculator::updateOperator(const string &op)
{
    m_expression.setOperator(SOperator(op));
}

string SCalculator::result() const
{
    return m_expression.result();
}
