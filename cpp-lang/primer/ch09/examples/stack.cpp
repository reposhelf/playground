#include <stack>
using std::stack;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    stack<int> int_stack;
    for (size_t i = 0; i != 10; ++i)
	int_stack.push(i);
    while (!int_stack.empty()) {
	cout << int_stack.top() << endl;
	int_stack.pop();
    }
    return 0;
}
