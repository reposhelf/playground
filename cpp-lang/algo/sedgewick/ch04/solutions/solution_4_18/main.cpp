/*
 * Exersice 4.18.
 * Write a program that converts a postfix expression to infix,
 * using pushdown stack
 */

#include "stack.h"

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '$';
}

string createSubExpression(const string &leftOperand, const string &rightOperand, char op)
{
    return string("(" + leftOperand + op + rightOperand + ")");
}

string postfixToInfix(const string &expression)
{
    ArrayBased::Stack<string> subExpressions(expression.length());
    for (char ch : expression) {
        if (isOperator(ch)) {
            string rightOperand = subExpressions.pop();
            string leftOperand = subExpressions.pop();
            subExpressions.push(createSubExpression(leftOperand, rightOperand, ch));
        } else {
            subExpressions.push(string(1, ch));
        }
    }
    return subExpressions.pop();
}

void print_program_description()
{
    cout << "Program that converts a postfix expression to infix." << endl;
    cout << "Press 'q' or 'quit' to exit." << endl;
}

bool maybeGoOut(const string &input)
{
    return input == "quit" || input == "q";
}

int main(int, char **)
{
    print_program_description();
    do {
        cout << "expr> ";

        string input;
        std::getline(cin, input);

        if (maybeGoOut(input))
            break;

        cout << postfixToInfix(input) << endl;
    } while (true);

    return 0;
}
