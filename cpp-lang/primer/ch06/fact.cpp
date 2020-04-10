#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>

int fact(int val)
{
    int ret = 1;

    while (val > 1)
        ret *= val--;

    return ret;
}

int main(int argc, char **argv)
{
    cout << fact(atoi(argv[1])) << endl;
    return 0;
}