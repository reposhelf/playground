#include "stack.h"

#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

void evaluatePostfixExpression(char **argv)
{
    char *expression = argv[1];
    const size_t size = strlen(expression);
    ArrayBased::Stack<int> save(size);
    for (size_t i = 0; i < size; ++i) {
        if (expression[i] == '+') {
            save.push(save.pop() + save.pop());
        }
        if (expression[i] == '-') {
            int subtrahend = save.pop();
            int minuend = save.pop();
            save.push(minuend - subtrahend);
        }
        if(expression[i] == '*') {
            save.push(save.pop() * save.pop());
        }
        if (expression[i] == '/') {
            int divisor = save.pop();
            int dividend = save.pop();
            save.push(dividend / divisor);
        }
        if ((expression[i] >= '0') && (expression[i] <= '9')) {
            save.push(0);
        }
        while ((expression[i] >= '0') && (expression[i] <= '9'))
            save.push(10 * save.pop() + (expression[i++] - '0'));
    }
    cout << save.pop() << endl;
}

void infixToPostfix(char **argv)
{
    char *expression = argv[1];
    const size_t size = strlen(expression);
    ArrayBased::Stack<char> ops(size);
    for (size_t i = 0; i < size; ++i) {
        if (expression[i] == ')')
            cout << ops.pop() << " ";
        if ((expression[i] == '+')
                || (expression[i] == '*')
                || (expression[i] == '-')
                || (expression[i] == '/')) {
            ops.push(expression[i]);
        }
        if ((expression[i] >= '0') && (expression[i] <= '9'))
            cout << expression[i] << " ";
    }
    cout << endl;
}

int main(int, char **argv)
{
    infixToPostfix(argv);
    evaluatePostfixExpression(argv);
    return 0;
}
