#include "minicalculator.h"
#include "stack.h"
#include "global.h"

#include <cmath>

using std::string;
using sizeType = string::size_type;

void MiniCalculator::setExpression(const std::string &expression)
{
    _expression = expression;
}

double MiniCalculator::getResult() const
{
    if (_expression.empty())
        return 0.0;

    return calculateExpression(_expression);
}

double MiniCalculator::calculateExpression(const std::string &infixExpression) const
{
    string postfixExpression = infixToPostfix(infixExpression);
    return calculatePostfixExpression(postfixExpression);
}

double MiniCalculator::calculatePostfixExpression(const std::string &postfixExpression) const
{
    const sizeType size = postfixExpression.size();
    ArrayBased::Stack<double> operands(size);

    for (sizeType i = 0; i < size; ++i) {
        if (postfixExpression[i] == '+') {
            operands.push(operands.pop() + operands.pop());

        } else if (postfixExpression[i] == '-') {
            double subtrahend = operands.pop();
            double minuend = operands.pop();
            operands.push(minuend - subtrahend);

        } else if (postfixExpression[i] == '*') {
            operands.push(operands.pop() * operands.pop());

        } else if (postfixExpression[i] == '/') {
            double divisor = operands.pop();
            double dividend = operands.pop();
            operands.push(dividend / divisor);

        } else if (postfixExpression[i] == '$') {
            double d = operands.pop();
            if (d < 0.0)
                d *= -1.0;
            operands.push(sqrt(d));
        }

        if (postfixExpression[i] >= '0' && postfixExpression[i] <= '9')
            operands.push(0.0);

        while (postfixExpression[i] >= '0' && postfixExpression[i] <= '9')
            operands.push(10.0 * operands.pop() + (double)(postfixExpression[i++] - '0'));
    }
    return operands.pop();
}

std::string MiniCalculator::infixToPostfix(const std::string &infixExpression) const
{
    string postfixExpression;
    const sizeType size = infixExpression.size();
    ArrayBased::Stack<char> operators(size);
    bool lastWasOperand = false;

    for (sizeType i = 0; i < size; ++i) {
        if (isOperand(infixExpression[i])) {
            while (isOperand(infixExpression[i]))
                postfixExpression += string(1, infixExpression[i++]);
            postfixExpression += " ";
            lastWasOperand = true;
        }

        if (isOperator(infixExpression[i])) {
            if (!operators.empty()) {
                if (infixExpression[i] == '-' && operators.top() == '(' && !lastWasOperand)
                    postfixExpression += "0 ";

                while (operators.top() != '(' && hasHigherPriority(operators.top(), infixExpression[i]))
                    postfixExpression += string(1, operators.pop()) + " ";
            }
            operators.push(infixExpression[i]);

        } else if (infixExpression[i] == '(') {
            operators.push(infixExpression[i]);
            lastWasOperand = false;

        } else if (infixExpression[i] == ')') {
            while (!operators.empty() && operators.top() != '(')
                postfixExpression += string(1, operators.pop()) + " ";
            operators.pop();
        }
    }

    while (!operators.empty())
        postfixExpression += string(1, operators.pop()) + " ";

    return postfixExpression;
}

bool MiniCalculator::parse() const
{
    if (_expression.empty())
        return true;

    // TODO: add implementation
    // set value for _error
    return true;
}

std::string MiniCalculator::errorString(MiniCalculator::Error error) const
{
    switch (error) {
    case NoError:
        return string();
    default:
        return "unknown error";
    }
}
