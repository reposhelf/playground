#ifndef MINICALCULATOR_H
#define MINICALCULATOR_H

#include <string>

class MiniCalculator
{
public:
    MiniCalculator() = default;
    MiniCalculator(const std::string &expression)
        : _expression(expression) {}

    void setExpression(const std::string &expression);
    double getResult() const;
    bool hasError() const { return !parse(); }
    std::string errorString() const { return errorString(_error); }

private:
    enum Error {
        NoError
    };

    double calculateExpression(const std::string &infixExpression) const;
    double calculatePostfixExpression(const std::string &postfixExpression) const;
    std::string infixToPostfix(const std::string &infixExpression) const;
    bool parse() const;
    std::string errorString(Error error) const;

    std::string _expression;
    Error _error = NoError;
};

#endif // MINICALCULATOR_H
