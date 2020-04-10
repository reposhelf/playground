/*
 * Exercise 9.52:
 * Use a stack to process parenthesized expressions. When you see an open
 * parenthesis, note that it was seen. When you see a close parenthesis after
 * an open parenthesis, pop elements down to and including the open
 * parenthesis off the stack. push a value onto the stack to indicate that a
 * parenthesized expression was replaced.
 */

#include <string>
using std::string;

#include <stack>
using std::stack;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    string expr = "(((2 + 1) * 3) + (4 * 2))";
    stack<string> buf;
    for (string::size_type pos = 0; pos < expr.size(); ++pos) {
	if (expr[pos] == ' ')
	    continue;

	if (expr[pos] == ')') {
	    int lhs = 0;
	    int rhs = 0;
	    char op;

	    while (buf.top() != "(") {
		rhs = std::stoi(buf.top());
		buf.pop();

		if (buf.top() == "(")
		    break;

		op = buf.top()[0];
		buf.pop();

		lhs = std::stoi(buf.top());
		buf.pop();

		switch (op) {
		case '+':
		    rhs = lhs + rhs;
		    break;
		case '-':
		    rhs = lhs - rhs;
		    break;
		case '*':
		    rhs = lhs * rhs;
		    break;
		case '/':
		    rhs = lhs / rhs;
		    break;
		default:
		    // TODO: error occurs
		    break;
		}
		buf.push(std::to_string(rhs));
	    }
	    buf.pop();
	    buf.push(std::to_string(rhs));
	    continue;
	}

	if (!isdigit(expr[pos])) {
	    buf.push(string(1, expr[pos]));
	    continue;
	}

	int digit = std::stoi(expr.substr(pos));
	string str_digit = std::to_string(digit);
	pos += str_digit.size() - 1;
	buf.push(str_digit);
    }

    cout << buf.top() << endl;

    return 0;
}
