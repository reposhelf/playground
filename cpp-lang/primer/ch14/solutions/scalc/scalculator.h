#ifndef SCALCULATOR_H
#define SCALCULATOR_H

#include "sexpression.h"

class SCalculator
{
public:
    SCalculator() = default;
    bool isValid() const;
    void clear();
    void updateValue(const std::string &value);
    void updateOperator(const std::string &op);
    std::string result() const;

private:
    SExpression m_expression;
};

#endif // SCALCULATOR_H
