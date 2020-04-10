#include <iostream>

using namespace std;

void mark(int /*p*/, int h)
{
    cout << h << ' ';
}

void rule(int l, int r, int h)
{
    if (h >  0) {
        int m = (l + r) / 2;
        rule(l, m, h - 1);
        mark(m, h);
        rule(m + 1, r, h - 1);
    }
}

int main()
{
    rule(0, 8, 3);
    cout << endl;
    return 0;
}