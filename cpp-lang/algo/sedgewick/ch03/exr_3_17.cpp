#include <iostream>
#include <vector>
#include <cstdlib>

static const uint N = 1000;

int randNum();

int main()
{
    std::vector<bool> vec(N, false);
    int count;
    while (true) {
        int num = randNum();
        std::cout << num << std::endl;
        if (!vec[num]) {
            vec[num] = true;
            ++count;
        } else {
            break;
        }
    }
    std::cout << count << std::endl;
    return 0;
}

int randNum()
{
    return rand() % N;
}