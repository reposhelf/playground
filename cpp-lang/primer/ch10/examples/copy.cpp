#include <algorithm>
using std::copy;

#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::begin;
using std::end;

int main()
{
    int ia1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ia2[sizeof(ia1) / sizeof(*ia1)];

    copy(begin(ia1), end(ia1), ia2);

    for (int i = 0; i < 10; ++i)
	cout << ia2[i] << " ";
    cout << endl;

    return 0;
}
