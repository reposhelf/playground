#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::min;
using std::max;

int main()
{
    cout << "Enter two numbers: " << endl;
    int val1 = 0, val2 = 0;
    cin >> val1 >> val2;

    int min_val = min(val1, val2);
    int max_val = max(val1, val2);

    while (min_val <= max_val) {
        cout << min_val << " ";
        ++min_val;
    }
    cout << endl;
    return 0;
}