/*
 * Exercise 3.43:
 * Write three different versions of a program to print the
 * elements of ia. One version should use a range for to manage the
 * iteration, the other two should use an ordinary for loop in one case using
 * subscripts and in the other using pointers. In all three programs write all the
 * types directly. That is, do not use a type alias, auto, or decltype to
 * simplify the code.
 */
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    constexpr size_t row_cnt = 3;
    constexpr size_t col_cnt = 4;
    int ia[row_cnt][col_cnt];
    // fill ia array
    for (size_t i = 0; i < row_cnt; ++i) {
        for (size_t j = 0; j < col_cnt; ++j) {
            ia[i][j] = i * col_cnt + j;
        }
    }
    // print ia array
    // 1st version
    for (int (&row)[col_cnt] : ia) {
        for (int col : row) {
            cout << col << endl;
        }
    }
    cout << endl;
    // 2nd version
    for (size_t i = 0; i < row_cnt; ++i) {
        for (size_t j = 0; j < col_cnt; ++j) {
            cout << ia[i][j] << endl;;
        }
    }
    cout << endl;
    // 3d version
    for (int (*i)[col_cnt] = ia; i != ia + row_cnt; ++i) {
        for (int *j = *i; j != *i + col_cnt; ++j) {
            cout << *j <<endl;
        }
    }
    return 0;
}