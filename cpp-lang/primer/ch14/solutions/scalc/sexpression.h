#ifndef SEXPRESSION_H
#define SEXPRESSION_H

#include "soperand.h"
#include "soperator.h"

class SExpression
{
public:
    SExpression() = default;
    SExpression(const SOperand &lhs, const SOperator &op, const SOperand &rhs);
    bool isValid() const;
    void clear();
    void setOperand(const SOperand &operand);
    void setOperator(const SOperator &op);
    std::string result() const;

private:
    void evaluate();

    SOperand m_leftOperand;
    SOperand m_rightOperand;
    SOperator m_operator;
    SOperand *m_input = &m_leftOperand;
};

#endif // SEXPRESSION_H
