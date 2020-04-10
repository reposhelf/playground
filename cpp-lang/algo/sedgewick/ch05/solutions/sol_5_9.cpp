/*
 * Exercise 5.9:
 * Write a recursive program to evaluate postfix expressions.
 */

#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

const char *a  = "5 9 8 + 4 6 * * 7 + *";
size_t i = strlen(a) - 1;

int eval()
{
    while (a[i] == ' ')
	--i;

    if (a[i] == '+') {
	--i;
	return eval() + eval();
    }

    if (a[i] == '*') {
	--i;
	return eval() * eval();
    }

    int r = 0;
    while (a[i] >= '0' && a[i] <= '9')
	r = 10 * r + (a[i--] - '0');

    return r;
}

int main()
{
    cout << eval() << endl;
    return 0;
}
