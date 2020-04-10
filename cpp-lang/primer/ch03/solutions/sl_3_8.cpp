#include <string>
#include <cctype>
#include <iostream>

void while_loop();
void for_loop();

int main()
{
    while_loop();
    for_loop();
    return 0;
}

void while_loop()
{
    std::string str = "some string";
    decltype(str.size()) i = 0;
    while (i != str.size()) {
        str[i] = 'X';
        ++i;
    }
    std::cout << str << std::endl;
}

void for_loop()
{
    std::string str = "some string";
    for (decltype(str.size()) i = 0; i != str.size(); ++i)
        str[i] = 'X';
    std::cout << str << std::endl;
}
