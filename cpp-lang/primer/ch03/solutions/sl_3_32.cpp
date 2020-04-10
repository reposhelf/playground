/*
 * Exercise 3.32:
 * Copy the array you defined in the previous exercise into
 * another array. Rewrite your program to use vectors.
 */
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

 int main()
 {
    // step 1.
    constexpr size_t size = 10;
    int array[size];
    for (size_t i = 0; i < size; ++i)
        array[i] = i;

    int another_array[size];
    for (size_t i = 0; i < size; ++i)
        another_array[i] = array[i];
    for (int i : another_array)
        cout << i << endl;

    // step 2.
    vector<int> vec(size, 0);
    for (decltype(vec.size()) i = 0; i < vec.size(); ++i)
        vec[i] = i;

    vector<int> another_vec = vec;
    for (int i : another_vec)
        cout << i << endl;

    unsigned scores[11] = {};
    for (int i : scores)
        cout << i << " ";
    cout << endl;

    return 0;
 }
