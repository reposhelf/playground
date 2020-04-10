#include <iostream>

int main()
{
    constexpr size_t row_cnt = 3;
    constexpr size_t col_cnt = 4;

    int ia[row_cnt][col_cnt];
    for (size_t i = 0; i < row_cnt; ++i)
        for (size_t j = 0; j < col_cnt; ++j)
            ia[i][j] = i * col_cnt + j;

    for (size_t i = 0; i < row_cnt; ++i)
        for (size_t j = 0; j < col_cnt; ++j)
            std::cout << ia[i][j] << std::endl;

    return 0;
}