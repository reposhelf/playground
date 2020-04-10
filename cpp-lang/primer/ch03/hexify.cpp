#include <string>
#include <iostream>

int main()
{
    const std::string hexdigits = "0123456789ABCDEF";
    std::cout << "Enter a series of number between 0 and 15 "
              << "separated by spaces. Hit ENTER when finished:"
              << std::endl;
    std::string result;
    decltype(result.size()) n;
    while (std::cin >> n) {
        if (n < hexdigits.size())
            result += hexdigits[n];
    }
    std::cout << "Your hex number is: " << result << std::endl;
    return 0;
}