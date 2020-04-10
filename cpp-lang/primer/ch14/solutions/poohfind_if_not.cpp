#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>

class EqualTo
{
public:
    EqualTo(const std::string &ethalon) : m_ethalon(ethalon) {}
    bool operator()(const std::string &other_val) const {
        std::equal_to<std::string> eq;
        return eq(m_ethalon, other_val);
    }

private:
    std::string m_ethalon;
};

int main()
{
    std::vector<std::string> words{"pooh", "pooh", "vinni", "pooh"};
    EqualTo equalTo("pooh");
    auto p = std::find_if_not(words.cbegin(), words.cend(), equalTo);
    if (p != words.cend())
        std::cout << *p << std::endl;
    return 0;
}
