#ifndef MINICOMPILER_H
#define MINICOMPILER_H

#include "stack.h"

#include <iostream>
#include <string>

template <typename T>
class Stack;
class MiniCompiler {
public:
    using str_size = std::string::size_type;

    enum Status {
        EMPTY,
        NON_PRINTABLE,
        UNDEFINED_VARIABLE_NAME,
        INVALID_VARIABLE_NAME
    };

    MiniCompiler() = default;

    const char *description() const;
    void print_offer_input() const;
    bool maybe_exit(const std::string &input) const;
    void process_expression(const std::string &expr);

private:
    enum { MaxVarsCount = 26 };

    std::string infix_to_postfix(const std::string &expr);
    bool is_operand(char ch) const;
    bool is_operator(char ch) const;
    int operator_priority(char op) const;
    bool has_highest_priority(char prev_op, char curr_op) const;
    bool is_var_name(char ch) const;
    char last_item_in_postfix(const std::string &expr) const;
    bool last_is_var_name(const std::string &postfix) const;
    bool is_defined_var_name(char ch) const;
    int evaluate_postfix_expr(const std::string &expr) const;
    int value_of_var(char var_name) const;
    void set_var_value(char var_name, int value);
    std::string process_operand_occurence(const std::string &expr, str_size &pos) const;
    Status process_assignment_occurence(const std::string &expr, const std::string &postfix,
                                        str_size pos);
    Status process_var_occurrence(char var_name, ArrayBased::Stack<int> &operands) const;

    std::string _defined_var_names;
    int _vars[MaxVarsCount] = {};
    mutable Status _status = EMPTY;
};

inline const char *MiniCompiler::description() const {
    return "This program represents simple compiler/interpreter.\n"
           "It can handle just simple arithmetic expressions "
           "included assignment operator.\n"
           "Type 'q' or 'quit' to exit the program.";
}

inline void MiniCompiler::print_offer_input() const {
    std::cout << "expr> ";
}

inline bool MiniCompiler::maybe_exit(const std::string &input) const {
    return input == "q" || input == "quit";
}

inline bool MiniCompiler::is_operand(char ch) const {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z');
}

inline bool MiniCompiler::is_operator(char ch) const {
    return ch == '=' || ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

inline int MiniCompiler::operator_priority(char op) const {
    switch (op) {
    case '=':
        return 1;

    case '+':
    case '-':
        return 2;

    case '*':
    case '/':
        return 3;

    default:
        return -1;
    }
}

inline bool MiniCompiler::has_highest_priority(char prev_op, char curr_op) const {
    int prev_op_priority = operator_priority(prev_op);
    int curr_op_priority = operator_priority(curr_op);
    return prev_op_priority > curr_op_priority;
}

inline bool MiniCompiler::is_var_name(char ch) const {
    return ch >= 'a' && ch <= 'z';
}

inline char MiniCompiler::last_item_in_postfix(const std::string &expr) const {
    return expr[expr.size() - 2];
}

inline bool MiniCompiler::last_is_var_name(const std::string &postfix) const {
    return is_var_name(last_item_in_postfix(postfix));
}

inline bool MiniCompiler::is_defined_var_name(char ch) const {
    return _defined_var_names.find(ch) != std::string::npos;
}

inline int MiniCompiler::value_of_var(char var_name) const {
    return _vars[var_name - 'a'];
}

inline void MiniCompiler::set_var_value(char var_name, int value) {
    _vars[var_name - 'a'] = value;
}

#endif // MINICOMPILER_H
