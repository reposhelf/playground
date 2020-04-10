#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec;
    while (in_iter != eof)
        vec.push_back(*in_iter++);

    ostream_iterator<int> out_iter(cout, " ");
    copy(vec.begin(), vec.end(), out_iter);
    cout << endl;

    // alternative way for output elements
    for (int i : vec)
        *out_iter++ = i;
    cout << endl;
    return 0;
}