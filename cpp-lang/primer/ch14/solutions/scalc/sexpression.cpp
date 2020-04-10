#include "sexpression.h"

#include <map>
#include <functional>
#include <iostream>
#include <stdexcept>

using namespace std;

inline int divException(int numerator, int denominator)
{
    if (denominator == 0)
        throw overflow_error("divide by zero exception.");
    return numerator / denominator;
}

namespace Operation {
auto add = [](int a, int b) { return a + b; };
auto sub = [](int a, int b) { return a - b; };
auto mul = [](int a, int b) { return a * b; };
auto div = [](int a, int b) { return divException(a, b); };
auto mod = [](int a, int b) { return a % b; };
}

static map<SOperator, function<int(int,int)>> operations = {
{SOperator(SOperator::ADD_STR), Operation::add},
{SOperator(SOperator::SUB_STR), Operation::sub},
{SOperator(SOperator::MUL_STR), Operation::mul},
{SOperator(SOperator::DIV_STR), Operation::div},
{SOperator(SOperator::MOD_STR), Operation::mod}};

SExpression::SExpression(const SOperand &lhs, const SOperator &op, const SOperand &rhs)
    : m_leftOperand(lhs),
      m_rightOperand(rhs),
      m_operator(op)
{

}

bool SExpression::isValid() const
{
    return !m_leftOperand.isEmpty() && !m_rightOperand.isEmpty()
            && !m_operator.isEmpty() && m_operator.isValid();
}

void SExpression::clear()
{
    m_leftOperand.clear();
    m_rightOperand.clear();
    m_operator.clear();
    m_input = &m_leftOperand;
}

void SExpression::setOperand(const SOperand &operand)
{
    *m_input = operand;
}

void SExpression::setOperator(const SOperator &op)
{
    try {
        if (isValid())
            evaluate();

        if (op != SOperator(SOperator::RES_STR))
            m_operator = op;

        m_input = &m_rightOperand;
    } catch (overflow_error &e) {
        cerr << "SExpression::Error: " << e.what() << endl;
        clear();
        *m_input = SOperand("0");
    }
}

string SExpression::result() const
{
    return m_leftOperand.isEmpty() ? SOperand("0") : m_leftOperand;
}

void SExpression::evaluate()
{
    if (!isValid())
        cerr << "SExpression::Error: invalid expression" << endl;

    string res = to_string(operations[m_operator](m_leftOperand, m_rightOperand));
    clear();
    *m_input = SOperand(res);
}
