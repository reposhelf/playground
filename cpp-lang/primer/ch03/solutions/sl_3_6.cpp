#include <string>
#include <cctype>
#include <iostream>

int main()
{
    std::string str = "some string";
    for (auto &c : str)
        c = 'X';
    std::cout << str << std::endl;
    return 0;
}