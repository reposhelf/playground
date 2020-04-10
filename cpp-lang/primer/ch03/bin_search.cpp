#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        cout << "error: expected one parameter" << endl;
        return 1;
    }
    vector<int> vec;
    for (int i = 1; i <= 100; ++i)
        vec.push_back(i);

    int num = atoi(argv[1]);
    auto beg = vec.cbegin();
    auto end = vec.cend();
    auto mid = beg + (end - beg) / 2;
    while (mid != end && *mid != num) {
        if (num < *mid) 
            end = mid;
        else 
            beg = mid + 1;

        mid = beg + (end - beg) / 2;
    }

    if (mid != end)
        cout << *mid << endl;
    return 0;
}