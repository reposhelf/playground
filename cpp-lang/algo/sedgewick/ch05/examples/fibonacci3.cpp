#include <iostream>

using namespace std;

const size_t MAX_NUM = 45;

int fibonacci(int value)
{
    static int known[MAX_NUM];
    known[0] = 0;
    known[1] = 1;

    if (known[value] != 0)
	return known[value];

    int t = value;
    if (value < 1)
	return 0;
    if (value > 1)
	t = fibonacci(value - 1) + fibonacci(value - 2);

    return known[value] = t;
}

int main(int argc, char *argv[])
{
    cout << fibonacci(atoi(argv[1])) << endl;
    return 0;
}
