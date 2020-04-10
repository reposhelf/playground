#include <string>
#include <iostream>

int main()
{
    std::string str = "some string";
    for (auto c : str)
        std::cout << c << std::endl;
    return 0;
}