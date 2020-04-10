#include <string>
#include <bitset>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

#define BITS_COUNT 16

string randBits(int r)
{
    return bitset<BITS_COUNT>(rand() % r).to_string();
}

unsigned long bits2ulong(const string &bits)
{
    return bitset<BITS_COUNT>(bits).to_ulong();
}

int main()
{
    for (int r = 10; r <= 1000; r *= 10) {
        cout << "r = " << r << endl;

        for (int n = 1000; n <= 1000000; n *= 10) {
            cout << "    n = " << n << endl;

            double m1 = 0.0;
            double m2 = 0.0;

            for (int i = 0; i < n; ++i) {
                string rn_str = randBits(r);
                unsigned long rn = bits2ulong(rn_str);

                m1 += (static_cast<double>(rn)) / n;
                m2 += (static_cast<double>(rn) * rn) / n;
            }
            cout << "        Avg.: " << m1 << endl;
            cout << "        Std. dev.:" << sqrt(m2 - m1 * m1) << endl;
        }
    }
    return 0;
}
