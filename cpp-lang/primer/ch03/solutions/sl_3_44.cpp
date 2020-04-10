/*
 * Exercise 3.44:
 * Rewrite the programs from the previous exercises using a
 * type alias for the type of the loop control variables.
 */
#include <iostream>
using std::cout;
using std::endl;

constexpr size_t row_cnt = 3;
constexpr size_t col_cnt = 4;

 using int_array2d = int[row_cnt][col_cnt];
// equivalent of:
// typedef int int_array2d[row_cnt][col_cnt];

int main()
{
    int_array2d ia;
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
