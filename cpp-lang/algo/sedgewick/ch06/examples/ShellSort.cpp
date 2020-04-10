#include <iostream>
#include <iterator>
#include <random>

template<typename T>
void shellSort(T seq[], int left, int right)
{
    int step; // initialized below, in for loop

    for (step = left; step <= (right - left) / 9; step = 3 * step + 1) {}

    for (; step > 0; step /= 3)
    {
        for (int i = left + step; i <= right; ++i)
        {
            int j = i;
            T value = seq[i];

            while (j >= left + step && value < seq[j - step])
            {
                seq[j] = seq[j - step];
                j -= step;
            }

            seq[j] = value;
        }
    }
}

int main()
{
    static const int size = 100;
    int seq[size];
    for (int i = 0; i != size; ++i)
        seq[i] = rand() % 100;
    
    shellSort(seq, 0, sizeof(seq) / sizeof(*seq) - 1);

    for (auto it = std::begin(seq); it != std::end(seq); ++it)
        std::cout << *it << std::endl;

    return 0;
}
