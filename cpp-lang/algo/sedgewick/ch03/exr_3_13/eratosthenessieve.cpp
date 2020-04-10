#include "eratosthenessieve.h"

#include <QVector>

uint EratosthenesSieve::primeCount(uint n)
{
    QVector<bool> numbers(n, true);

    for (uint i = 2; i < n; ++i) {
        if (numbers[i]) {
            for (uint j = i; j * i < n; ++j) {
                numbers[i * j] = false;
            }
        }
    }

    uint result = 0;
    foreach (bool b, numbers) {
        if (b) {
            ++result;
        }
    }

    return result;
}
