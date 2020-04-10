#include <iostream>
using namespace std;

static const int N = 6;

int main()
{
    int a[N];

    for (int i = 0; i < N; ++i)
    {
        a[i] = N - 1 - i;
        cout << a[i] << endl;
    }

    cout << "/////////" << endl;

    for (int i = 0; i < N; ++i)
    {
        a[i] = a[a[i]];
        cout << a[i] << endl;
    }

    return 0;
}