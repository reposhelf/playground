#include <iterator>
using std::begin;
using std::end;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    constexpr size_t size = 10;
    int array[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int *pbeg = begin(array);
    int *pend = end(array);

    while (pbeg != pend) {
        if (*pbeg < 0) {
            cout << *pbeg << endl;
            break;
        }
        ++pbeg;
    }
    return 0;
}