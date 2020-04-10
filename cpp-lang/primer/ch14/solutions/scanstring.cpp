#include <iostream>
#include <string>
#include <vector>

class ScanString
{
public:
    ScanString(std::istream &i = std::cin)
        : input(i) {}
    std::string operator()() const {
        std::string ret;
        input >> ret; 
        return ret;
    }
    
private:
    std::istream &input;
};

int main()
{
    std::vector<std::string> svec(3);
    ScanString scanner;
    for (auto &s : svec)
        s = scanner();
    return 0;
}
