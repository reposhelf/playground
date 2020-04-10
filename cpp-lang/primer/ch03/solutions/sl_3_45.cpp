/*
 * Exercise 3.45: Rewrite the programs again, this time using auto.
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
    for (auto &row : ia) {
        for (auto col : row) {
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
    for (auto i = ia; i != ia + row_cnt; ++i) {
        for (auto j = *i; j != *i + col_cnt; ++j) {
            cout << *j <<endl;
        }
    }
    return 0;
}