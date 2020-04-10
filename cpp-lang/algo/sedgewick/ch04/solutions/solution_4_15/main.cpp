#include "stack.h"

#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

#include <cmath>

void evaluatePostfixExpression(char **argv)
{
    char *expression = argv[1];
    const size_t size = strlen(expression);
    ArrayBased::Stack<double> save(size);
    for (size_t i = 0; i < size; ++i) {
        if (expression[i] == '+') {
            save.push(save.pop() + save.pop());
        }
        if (expression[i] == '-') {
            double subtrahend = save.pop();
            double minuend = save.pop();
            save.push(minuend - subtrahend);
        }
        if(expression[i] == '*') {
            save.push(save.pop() * save.pop());
        }
        if (expression[i] == '/') {
            double divisor = save.pop();
            double dividend = save.pop();
            save.push(dividend / divisor);
        }
        if (expression[i] == '$') {
            double d = save.pop();
            if (d < 0.0) d *= -1.0;
            save.push(sqrt(d));
        }
        if ((expression[i] >= '0') && (expression[i] <= '9')) {
            save.push(0.0);
        }
        while ((expression[i] >= '0') && (expression[i] <= '9'))
            save.push(10.0 * save.pop() + (double)(expression[i++] - '0'));
    }
    cout << save.pop() << endl;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '$';
}

bool isOperand(char c)
{
    return (c >= '0' && c <= '9');
}

int getOperatorPriority(char op)
{
    switch (op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '$': return 3;
    default: return -1;
    }
}

bool isRightAssociative(char op)
{
    return op == '$';
}

bool hasHigherPriority(char previousOperator, char currentOperator)
{
    int previousOperatorPriority = getOperatorPriority(previousOperator);
    int currentOperatorPriority = getOperatorPriority(currentOperator);

    if (previousOperatorPriority == currentOperatorPriority)
        return !isRightAssociative(currentOperator);

    return previousOperatorPriority > currentOperatorPriority;
}

void infixToPostfix(char **argv)
{
    char *expression = argv[1];
    const size_t size = strlen(expression);
    ArrayBased::Stack<char> stack(size);
    for (size_t i = 0; i < size; ++i) {
        if (isOperator(expression[i])) {
            if (!stack.empty()) {
                if (expression[i] == '-' && stack.top() == '(')
                    cout << "0 ";
                while (stack.top() != '(' && hasHigherPriority(stack.top(), expression[i]))
                    cout << stack.pop() << " ";
            }
            stack.push(expression[i]);

        } else if (isOperand(expression[i])) {
            cout << expression[i] << " ";

        } else if (expression[i] == '(') {
            stack.push(expression[i]);

        } else if (expression[i] == ')') {
            while (!stack.empty() && stack.top() != '(')
                cout << stack.pop() << " ";
            stack.pop();

        }
    }
    while (!stack.empty())
        cout << stack.pop() << " ";
    cout << endl;
}

int main(int, char *argv[])
{
    infixToPostfix(argv);
    evaluatePostfixExpression(argv);
    return 0;
}
