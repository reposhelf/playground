#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std::placeholders;

class IntComparator
{
public:
    bool operator()(int a, int b) const { return a == b; }
};

int main()
{
    std::vector<int> ivec{0, 3, 5, 0, 8, 9};
    IntComparator comparator;
    replace_if(ivec.begin(), ivec.end(), bind(comparator, 0, _1), 1);
    for_each(ivec.cbegin(), ivec.cend(), [](int v) {std::cout << v << std::endl;});
    return 0;
}
