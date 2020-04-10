#include <iostream>
using namespace std;

int search(int haystack[], int needle, int begin, int end);

int main()
{
    static const int N = 1000000;
    int array[N];

    for (int i = 0; i < N; ++i)
        array[i] = i;

    cout << search(array, N - 1, 0, N);

    return 0;
}

int search(int haystack[], int needle, int begin, int end)
{
    while (end >= begin) {
        int m = (begin + end) / 2;
        if (haystack[m] == needle)
            return m;
        if (needle < haystack[m])
            end = m - 1;
        else
            begin = m + 1;
    }
    return -1;
}