#include <vector>
using std::vector;

#include <string>
using std::string;

#include <algorithm>
using std::fill;
using std::fill_n;

#include <numeric>
using std::accumulate;

#include <iterator>
using std::back_inserter;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<int> vec(10);             // default initialized to 0
    fill(vec.begin(), vec.end(), 1); // reset each element to 1

    // sum the elements in vec starting the summation with the value 0
    int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << sum << endl;

    // set a subsequence of the container to 10
    fill(vec.begin(), vec.begin() + vec.size() / 2, 10);
    cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;

    // reset the same subsequence to 0
    fill_n(vec.begin(), vec.size() / 2, 0);
    cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;

    // create 10 elements on the end of vec each with the value 42
    fill_n(back_inserter(vec), 10, 42);
    cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;

    // concatenate elements in a vector of strings and store in concat
    vector<string> v;
    string s;
    while (cin >> s)
	v.push_back(s);
    string concat = accumulate(v.cbegin(), v.cend(), string(""));
    cout << concat << endl;

    return 0;
}
