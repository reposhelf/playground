#include <algorithm>
using std::replace_copy;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::back_inserter;

int main()
{
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector<int> vec;

    replace_copy(lst.cbegin(), lst.cend(), back_inserter(vec), 0, 42);

    for (auto i : lst)
	cout << i << " ";
    cout << endl;

    for (auto i : vec)
	cout << i << " ";
    cout << endl;

    return 0;
}
