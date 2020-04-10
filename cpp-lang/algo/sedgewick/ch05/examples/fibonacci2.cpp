#include <iostream>

using namespace std;

int fibonacci(int value)
{
    int buffer[45];
    buffer[0] = 0;
    buffer[1] = 1;

    for (int i = 2; i <= value; ++i)
	buffer[i] = buffer[i - 1] + buffer[i - 2];

    return buffer[value];
}

int main(int argc, char *argv[])
{
    cout << fibonacci(atoi(argv[1])) << endl;
    return 0;
}
