#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;

int count_calls()
{
    static size_t ctr = 0;
    return ++ctr;
}

int main()
{
    for (size_t i = 0; i != 10; ++i)
        cout << count_calls() << endl;
    return 0;
}