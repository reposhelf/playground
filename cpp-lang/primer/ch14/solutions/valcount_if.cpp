#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

class GreaterThan
{
public:
    GreaterThan(int ethalon) : m_ethalon(ethalon) {}
    bool operator()(int other_val) const {
        std::greater<int> grt;
        return grt(other_val, m_ethalon);
    }

private:
    int m_ethalon;
};

int main()
{
    std::vector<int> nums{10000, 1024, 87, 3001, 31, 520};
    GreaterThan greaterThan(1024);
    std::cout << std::count_if(nums.cbegin(), nums.cend(), greaterThan) << std::endl;
    return 0;
}
