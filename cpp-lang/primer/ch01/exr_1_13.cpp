#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::min;
using std::max;

void exr_1_9();
void exr_1_10();
void exr_1_11();

int main()
{
    exr_1_9();
    exr_1_10();
    exr_1_11();

    return 0;
}

void exr_1_9()
{
    cout << "Reimplementing an exercise 1.9 ..." << endl;

    int sum = 0;
    for (int i = 50; i <= 100; ++i)
        sum += i;
    cout << "Sum of 50 to 100 inclusive is "
         << sum << endl;
    cout << endl;
}

void exr_1_10()
{
    cout << "Reimplementing an exercise 1.10 ..." << endl;

    for (int i = 10; i >= 0; --i)
        cout << i << " ";
    cout << endl << endl;
}

void exr_1_11()
{
    cout << "Reimplementing an exercise 1.10 ..." << endl;

    cout << "Enter two numbers: " << endl;
    int val1 = 0, val2 = 0;
    cin >> val1 >> val2;

    int min_val = min(val1, val2);
    int max_val = max(val1, val2);

    for (; min_val <= max_val; ++min_val)
        cout << min_val << " ";
    cout << endl << endl;
}
