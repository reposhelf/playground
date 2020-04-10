#include <iostream>
#include <vector>

static const uint N = 1000;

int main()
{
    std::vector<bool> vec(N, true);
    for (uint i = 2; i < N; ++i) {
        if (vec[i]) {
            for (uint j = i; j * i < N; ++j)
                vec[j * i] = false;
        }
    }
    for (uint i = 2; i < N; ++i) {
        if (vec[i])
            std::cout << i << " " << std::endl;
    }
    return 0;
}