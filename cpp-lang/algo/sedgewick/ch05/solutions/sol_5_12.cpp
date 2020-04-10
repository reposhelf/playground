/*
 * Exercise 5.12:
 * Write a recursive program that converts postfix expressions to infix.
 */

#include <cstring>
#include <string>
using std::string;

#include <stack>
using std::stack;

#include <iostream>
using std::cout; using std::endl;

const char *a = "2 2 2 + 3 * +";
size_t i = 0;
string infix;
stack<string> buf;

void postfix_to_infix()
{
    if (i >= strlen(a)) {
        infix = buf.top();
        buf.pop();
        return;
    }

    while (a[i] == ' ')
        ++i;

    if (a[i] == '+' || a[i] == '*') {
        string r_operand = buf.top();
        buf.pop();
        string l_operand = buf.top();
        buf.pop();
        string res = "(" + l_operand
                + " " + string(1, a[i++])
                + " " + r_operand + ")";
        buf.push(res);
        postfix_to_infix();
    } else {
        int val = 0;
        while (a[i] >= '0' && a[i] <= '9')
            val = val * 10 + (a[i++] - '0');
        string res = std::to_string(val);
        buf.push(res);
        postfix_to_infix();
    }
}

int main()
{
    postfix_to_infix();
    cout << infix << endl;
    return 0;
}
