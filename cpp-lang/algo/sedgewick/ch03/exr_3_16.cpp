#include <vector>
#include <iostream>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

static const uint N = 1000;

int main()
{
    vector<bool> vec(N, false);
    int num;
    while (cin >> num) {
        if ((num < 0) || (num > 1000))
            continue;
        if (!vec[num])
            vec[num] = true;
    }

    int count = 0;
    for (auto val : vec) {
        if (val)
            ++count;
    }
    cout << count << " integers in the input stream." << endl;
    return 0;
}