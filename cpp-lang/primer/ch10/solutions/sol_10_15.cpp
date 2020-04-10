/*
 * Exercise 10.15:
 * Write a lambda that captures an int from its enclosing function and takes an
 * int parameter. The lambda should return the sum of the captured int and the
 * int parameter.
 */

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;

void error(const char *msg)
{
    cerr << msg << endl;
    exit(1);
}

int main(int argc, char **argv)
{
    if (argc < 3)
        error("Type: PROGRAM <INT> <INT>");

    int local = std::atoi(argv[1]);
    auto f = [local] (int a) { return local + a; };
    cout << f(std::atoi(argv[2])) << endl;

    return 0;
}