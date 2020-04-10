/*
 * Exercise 5.10:
 * Write a recursive program to evaluate infix expressions. You may assume that
 * operands are always enclosed in parenthesess.
 */

#include <cstring>
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

const char *a = "(2 + (2 + 2) * 3)";
size_t i = 0;
string postfix;

void infix_to_postfix_r()
{
    if (i >= strlen(a))
	return;

    while (a[i] == ' ' || a[i] == '(')
	++i;

    if (a[i] == ')') {
	++i;
	return;
    }

    if (a[i] == '+' || a[i] == '*') {
	char op = a[i];
	++i;
	infix_to_postfix_r();
	postfix.push_back(op);
	postfix.push_back(' ');
	infix_to_postfix_r();
    } else {
	int r = 0;
	while (a[i] >= '0' && a[i] <= '9')
	    r = r * 10 + (a[i++] - '0');
	postfix += std::to_string(r);
	postfix.push_back(' ');
	infix_to_postfix_r();
    }
}

int eval()
{
    while (postfix[i] == ' ')
	--i;

    if (postfix[i] == '+') {
	--i;
	return eval() + eval();
    }

    if (postfix[i] == '*') {
	--i;
	return eval() * eval();
    }

    int r = 0;
    while (postfix[i] >= '0' && postfix[i] <= '9')
	r = 10 * r + (postfix[i--] - '0');

    return r;
}

int main()
{
    infix_to_postfix_r();
    i = postfix.size() - 1;
    cout << eval() << endl;
    return 0;
}
