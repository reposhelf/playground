#include <iostream>
using std::cout;
using std::endl;

int factorial(int val)
{
    return val == 0 ? 1 : val * factorial(val - 1);
}

int main()
{
    cout << factorial(5) << endl;
    return 0;
}
