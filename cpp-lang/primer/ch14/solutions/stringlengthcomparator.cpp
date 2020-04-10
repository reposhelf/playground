#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std::placeholders;

class StringLengthComparator
{
public:
    bool operator()(std::size_t length, const std::string &str) const {
        return str.size() >= length;
    }
};

int main()
{
    std::vector<std::string> file{"hello", "satisfaction", "people", "curiosity", "considering"};
    StringLengthComparator slc;
    std::cout << std::count_if(file.cbegin(), file.cend(), std::bind(slc, 9, _1)) << std::endl;
    return 0;
}
