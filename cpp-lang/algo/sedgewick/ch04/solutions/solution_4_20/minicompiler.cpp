#include "minicompiler.h"

using std::string;

void MiniCompiler::process_expression(const std::string &expr) {
    string postfix = infix_to_postfix(expr);
    if (_status == EMPTY) {
        int result = evaluate_postfix_expr(postfix);
        if (_status != UNDEFINED_VARIABLE_NAME)
            std::cout << result << std::endl;
    }
    _status = EMPTY;
}

string MiniCompiler::infix_to_postfix(const string &expr) {
    string postfix;
    const str_size size = expr.size();
    ArrayBased::Stack<char> operators(size);
    bool last_was_operand =false;

    for (str_size i = 0; i < size; ++i) {
        if (is_operand(expr[i])) {
            // 'i' variavle may be changed
            postfix += process_operand_occurence(expr, i);
            last_was_operand = true;
        }

        if (is_operator(expr[i])) {
            if (expr[i] == '=') {
                if (process_assignment_occurence(expr, postfix, i) != EMPTY)
                    return string();
            }

            if (!operators.empty()) {
                if (expr[i] == '-' && operators.top() == '('
                        && !last_was_operand) {
                    postfix += "0 ";
                }

                while (operators.top() != '('
                       && has_highest_priority(operators.top(), expr[i])) {
                    postfix += operators.pop() + " ";
                }
            }
            operators.push(expr[i]);

        } else if (expr[i] == '(') {
            operators.push(expr[i]);
            last_was_operand = false;

        } else if (expr[i] == ')') {
            while (!operators.empty() && operators.top() != '(')
                postfix += string(1, operators.pop()) + " ";
            operators.pop();
        }
    }

    while (!operators.empty())
        postfix += string(1, operators.pop()) + " ";

    return postfix;
}

int MiniCompiler::evaluate_postfix_expr(const string &expr) const {
    const str_size size = expr.size();
    ArrayBased::Stack<int> operands(size);

    for (str_size i = 0; i < size; ++i) {
        if (expr[i] == '+') {
            operands.push(operands.pop() + operands.pop());

        } else if (expr[i] == '-') {
            int subtrahend = operands.pop();
            int minuend = operands.pop();
            operands.push(minuend - subtrahend);

        } else if (expr[i] == '*') {
            operands.push(operands.pop() * operands.pop());

        } else if (expr[i] == '/') {
            int divisor = operands.pop();
            int divident = operands.pop();
            operands.push(divident / divisor);

        } else if (is_var_name(expr[i])) {
            if (process_var_occurrence(expr[i], operands)
                    == UNDEFINED_VARIABLE_NAME) {
                return 0;
            }
        }

        if (expr[i] >= '0' && expr[i] <= '9')
            operands.push(0);

        while (expr[i] >= '0' && expr[i] <= '9')
            operands.push(10 * operands.pop() + (expr[i++] - '0'));
    }
    return operands.pop();
}

std::string MiniCompiler::process_operand_occurence(const std::string &expr, str_size &pos) const {

    string postfix;
    if (isalpha(expr[pos])) {
        postfix += string(1, expr[pos]) + " ";
    } else {
        while (isdigit(expr[pos]))
            postfix += string(1, expr[pos++]);
        postfix += " ";
    }
    return postfix;
}

MiniCompiler::Status MiniCompiler::process_assignment_occurence(const std::string &expr,
                                                                const std::string &postfix,
                                                                MiniCompiler::str_size pos) {
    char var_name = last_item_in_postfix(postfix);

    if (is_var_name(var_name)) {
        string new_postfix = infix_to_postfix(expr.substr(pos + 1));
        int result = evaluate_postfix_expr(new_postfix);

        if (_status != UNDEFINED_VARIABLE_NAME) {
            set_var_value(var_name, result);
            if (!is_defined_var_name(var_name))
                _defined_var_names += string(1, var_name);
            _status = NON_PRINTABLE;
        }

    } else {
        _status = INVALID_VARIABLE_NAME;
    }

    return _status;
}

MiniCompiler::Status MiniCompiler::process_var_occurrence(char var_name,
                                                          ArrayBased::Stack<int> &operands) const {

    if (is_defined_var_name(var_name)) {
        operands.push(value_of_var(var_name));
        return (_status = EMPTY);
    }
    return (_status = UNDEFINED_VARIABLE_NAME);
}
