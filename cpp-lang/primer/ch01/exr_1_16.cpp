#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int sum = 0, val = 0;
    while (cin >> val)
        sum += val;
    cout << "Sum is " << sum << endl;
    return 0;
}