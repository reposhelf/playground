#include <iostream>

using namespace std;

void mark(int p, int h)
{
    // code
}

void rule(int l, int r, int h)
{
    for (int t = 1, j = 1; t <= h; j += j, ++t) {
        for (int i = 0; l + j + i <= r; i += j + j)
            mark(l + j + i, t);
    }
}

int main()
{
    rule(0, 8, 3);
    return 0;
}