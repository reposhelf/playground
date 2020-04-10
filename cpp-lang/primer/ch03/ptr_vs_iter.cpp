#include <iostream>

int main()
{
    constexpr size_t size = 10;
    int array[size] = {};
    for (size_t i = 0; i < size; ++i)
        array[i] = i;

    int *end = &array[size];
    for (int *it = array; it != end; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    return 0;
}