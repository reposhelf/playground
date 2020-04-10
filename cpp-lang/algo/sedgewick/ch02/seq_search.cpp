#include <iostream>
using namespace std;

int search(int haystack[], int needle, int begin, int end);

int main()
{
    static const int N = 1000000;
    int array[N];

    for (int i = 0; i < N; ++i)
        array[i] = i;

    cout << search(array, N - 1, 0, N) << endl;

    return 0;
}

int search(int haystack[], int needle, int begin, int end)
{
    for (int i = begin; i < end; ++i) {
        if (haystack[i] == needle)
            return i;
    }
    return -1;
}