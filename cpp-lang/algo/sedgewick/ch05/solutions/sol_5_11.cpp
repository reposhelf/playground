/*
 * Exercise 5.11:
 * Write a recursive program that converts infix expressions to postfix.
 */

#include <cstring>
#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

const char *a = "(2 + (2 + 2) * 3)";
string postfix;
size_t i = 0;

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

int main()
{
    infix_to_postfix_r();
    cout << postfix << endl;
    return 0;
}
