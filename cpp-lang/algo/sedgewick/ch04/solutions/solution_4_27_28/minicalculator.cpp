#include "minicalculator.h"

using std::string;

inline bool isOperand(char ch) {
    return ch >= '0' && ch <= '9';
}

inline bool isOperator(char ch) {
    return ch == '-' || ch == '+' || ch == '/' || ch == '*';
}

inline int get_operator_priority(char ch)
{
    switch (ch) {
    case '+': case '-': return 1;
    case '/': case '*': return 2;
    default: return -1;
    }
}

inline bool has_higher_priority(char prev_operator, char curr_operator)
{
    int prev_operator_priority = get_operator_priority(prev_operator);
    int curr_operator_priority = get_operator_priority(curr_operator);

    return prev_operator_priority > curr_operator_priority;
}

void MiniCalculator::input(const std::string &input) {
    _result = 0;

    _buffer.resize(input.size());

    string postfix = infix_to_postfix(input);

    if (is_good()) {
        _result = evaluate_postfix_expr(postfix);
    }
}

std::string MiniCalculator::infix_to_postfix(const std::string &expr) {
    string postfix;

    const string::size_type size = expr.size();

    bool lastWasOperand = false;

    for (string::size_type i = 0; i < size; ++i) {
        if (isOperand(expr[i])) {
            while (isOperand(expr[i]))
                postfix += string(1, expr[i++]);
            postfix += " ";
            lastWasOperand = true;
        }

        if (isOperator(expr[i])) {
            if (!_buffer.empty_lhs()) {
                if (expr[i] == '-' && _buffer.top_lhs() == '(' && !lastWasOperand)
                    postfix += "0 ";

                while (_buffer.top_lhs() != '(' && has_higher_priority(_buffer.top_lhs(), expr[i]))
                    postfix += string(1, _buffer.pop_lhs()) + " ";
            }
            _buffer.push_lhs(expr[i]);

        } else if (expr[i] == '(') {
            // TODO: increase count of opening parenthesis
            _buffer.push_lhs(expr[i]);
            lastWasOperand = false;

        } else if (expr[i] == ')') {
            // TODO: increase count of closing parenthesis
            while (!_buffer.empty_lhs() && _buffer.top_lhs() != '(')
                postfix += string(1, _buffer.pop_lhs()) + " ";
            _buffer.pop_lhs();
        }
    }

    while (!_buffer.empty_lhs())
        postfix += string(1, _buffer.pop_lhs()) + " ";

    return postfix;
}

int MiniCalculator::evaluate_postfix_expr(const std::string &expr) {
    const string::size_type size = expr.size();

    for (string::size_type i = 0; i < size; ++i) {
        if (expr[i] == '+') {
            _buffer.push_rhs(_buffer.pop_rhs() + _buffer.pop_rhs());

        } else if (expr[i] == '-') {
            double subtrahend = _buffer.pop_rhs();
            double minuend = _buffer.pop_rhs();
            _buffer.push_rhs(minuend - subtrahend);

        } else if (expr[i] == '*') {
            _buffer.push_rhs(_buffer.pop_rhs() * _buffer.pop_rhs());

        } else if (expr[i] == '/') {
            double divisor = _buffer.pop_rhs();
            double dividend = _buffer.pop_rhs();
            _buffer.push_rhs(dividend / divisor);
        }

        if (expr[i] >= '0' && expr[i] <= '9')
            _buffer.push_rhs(0);

        while (expr[i] >= '0' && expr[i] <= '9')
            _buffer.push_rhs(10 * _buffer.pop_rhs() + (int)(expr[i++] - '0'));
    }
    return _buffer.pop_rhs();
}
