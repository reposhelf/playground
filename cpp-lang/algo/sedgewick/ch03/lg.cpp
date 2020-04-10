#include <iostream>
using namespace std;

int lg(int);

int main()
{
    for (int i = 1000; i < 1000000000; i *= 10)
        cout << "lg(" << i << ") = " << lg(i) << endl;
    return 0;
}

int lg(int val)
{
    int i;
    for (i = 0; val > 0; ++i, val /=2) {}
    return i;
}