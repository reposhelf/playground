#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

class Multiplies
{
public:
    Multiplies(int value) : m_value(value) {}
    void operator()(int &i) const {
        std::multiplies<int> mul;
        i = mul(i, m_value);
    }
private:
    int m_value;
};

int main()
{
    std::vector<int> ivec{0, 1, 2, 3, 4, 5};
    Multiplies mul(2);
    std::for_each(ivec.begin(), ivec.end(), mul);
    std::for_each(ivec.cbegin(), ivec.cend(), [](int i){std::cout << i << std::endl;});
    std::cout << std::endl;
    return 0;
}
