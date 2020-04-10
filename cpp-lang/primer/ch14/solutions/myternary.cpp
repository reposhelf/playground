#include <string>
#include <iostream>

struct MyTernary
{
    std::string operator()(bool cond, const std::string &s1, const std::string &s2) {
        return cond ? s1 : s2;
    }
};

int main()
{
    MyTernary mt;
    std::cout << mt(true, "true", "false") << std::endl;
    std::cout << mt(false, "true", "false") << std::endl;
    return 0;
}
