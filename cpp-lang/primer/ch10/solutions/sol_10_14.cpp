/*
 * Exercise 10.14:
 * Write a lambda that takes two ints and returns their sum.
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

    auto f = [] (int a, int b) { return a + b; };
    cout << f(std::atoi(argv[1]), std::atoi(argv[2])) << endl;
    return 0;
}