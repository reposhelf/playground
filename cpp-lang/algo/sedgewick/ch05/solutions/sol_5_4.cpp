/*
 * Exercise 5.4.
 * Find the value of n < 10^6 for which program 5.2 makes the maximum number of
 * recurcive calls.
 */

#include "chapter05.h"

using namespace std;

int puzzle(int n, unsigned &counter)
{
    ++counter;

    if (n == 1)
        return 1;

    if (n % 2 == 0)
        return puzzle(n / 2, counter);
    else
        return puzzle(3 * n + 1, counter);
}

struct Buf {
    unsigned value = 0;
    unsigned calls_count = 0;
};

void sol_5_4()
{
    cout << "Program finds the value of n < 10^6 for which program 5.2 "
         << "makes the maximum number of recursive calls:" << endl;

    unsigned counter = 0;
    Buf buf;
    // In my system I got 'Segmentation failed'
    // when i >= 113834
    for (int i = 1; i < 113383; ++i) {
        counter = 0;
        puzzle(i, counter);
        if (counter > buf.calls_count) {
            buf.value = i;
            buf.calls_count = counter;
        }
    }

    cout << "The maximum number of recurcive calls is "
         << buf.calls_count << " for value " << buf.value
         << endl;

    print_separator();
}
