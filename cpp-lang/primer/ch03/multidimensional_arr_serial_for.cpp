#include <iostream>

int main()
{
    constexpr size_t row_cnt = 3;
    constexpr size_t col_cnt = 4;

    int ia[row_cnt][col_cnt];
    size_t counter = 0;
    for (auto &row : ia) {
        for (auto &col : row) {
            col = counter;
            ++counter;
        }
    }

    for (const auto &row : ia)
        for (auto col : row)
            std::cout << col << std::endl;

    return 0;
}