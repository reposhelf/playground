#include <iostream>

using namespace std;

int fibonacci(int value)
{
    if (value < 1)
	return 0;
    if (value == 1)
	return 1;
    return fibonacci(value - 1) + fibonacci(value - 2);
}

int main(int argc, char *argv[])
{
    cout << fibonacci(atoi(argv[1])) << endl;
    return 0;
}
