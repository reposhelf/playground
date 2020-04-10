/*
 * Exercise 3.42: Write a program to copy a vector of ints into an array of
 * ints.
 */
#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

int main()
{
    vector<int> vec(3, 333);
    int array[vec.size()];
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i)
        array[i] = vec[i];

    for (auto i : array)
        cout << i << " ";
    cout << endl;

    return 0;
}
