#include <iostream>
using std::cout;
using std::endl;

#include <iterator>
using std::begin;
using std::end;

int main()
{
    constexpr size_t row_cnt = 3;
    constexpr size_t col_cnt = 4;

    int ia[row_cnt][col_cnt];

    size_t cntr = 0;
    for (auto &row : ia) {
        for (auto &col : row) {
            col = cntr;
            ++cntr;
        }
    }

    // 1.
    for (auto p = ia; p != ia + row_cnt; ++p) {
        for (auto q = *p; q != *p + col_cnt; ++q)
            cout << *q << ' ';
        cout << endl;
    }

    // 2.
    for (auto p = begin(ia); p != end(ia); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q)
            cout << *q << ' ';
        cout << endl;
    }
    return 0;
}