#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

class IsDivided
{
public:
    IsDivided(int divider) : m_divider(divider) {}
    bool operator()(int val) const {
        std::modulus<int> mod;
        return (mod(m_divider, val) == 0);
    }

private:
    int m_divider;
};

int main()
{
    std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    IsDivided isDivided(20);
    std::cout << count_if(ivec.cbegin(), ivec.cend(), isDivided) << std::endl;
    return 0;
}
