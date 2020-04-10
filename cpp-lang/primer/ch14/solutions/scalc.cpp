#include <map>
#include <string>
#include <functional>
#include <iostream>

int add(int lhs, int rhs)
{
    return lhs + rhs;
}

struct Div
{
    int operator()(int lhs, int rhs) const {
        return lhs / rhs;
    }
};

auto mod = [](int lhs, int rhs) { return lhs % rhs; };

int main()
{
    Div div;

    std::map<std::string, std::function<int(int,int)>> binops = {
        {"+", add},
        {"-", std::minus<int>()},
        {"/", div},
        {"*", [](int lhs, int rhs){return lhs * rhs;}},
        {"%", mod}
    };

    const int lhs = 24, rhs = 8;
    std::cout << "24 + 8 = " << binops["+"](lhs, rhs) << std::endl;
    std::cout << "24 - 8 = " << binops["-"](lhs, rhs) << std::endl;
    std::cout << "24 / 8 = " << binops["/"](lhs, rhs) << std::endl;
    std::cout << "24 * 8 = " << binops["*"](lhs, rhs) << std::endl;
    std::cout << "24 % 8 = " << binops["%"](lhs, rhs) << std::endl;

    return 0;
}
