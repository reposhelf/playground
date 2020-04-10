#include <iostream>

int main()
{
    unsigned long quiz = 0; // we'll use this value as a collection of bits
    quiz |= 1UL << 27; // indicate student number 27 passed
    quiz &= ~(1UL << 27); // student number 27 failed

    // check result
    bool result = quiz & (1UL << 27);
    std::cout << result << std::endl;
    return 0;
}