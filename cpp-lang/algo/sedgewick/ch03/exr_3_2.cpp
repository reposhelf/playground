#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    for (int r = 10; r <= 1000; r *= 10) {
        cout << "r = " << r << endl;

        for (int n = 1000; n <= 1000000; n *= 10) {
            cout << "    n = " << n << endl;

            double m1 = 0.0;
            double m2 = 0.0;

            for (int i = 0; i < n; ++i) {
                int rn = rand() % r;

                m1 += (static_cast<double>(rn)) / n;
                m2 += (static_cast<double>(rn) * rn) / n;
            }
            cout << "        Avg.: " << m1 << endl;
            cout << "        Std. dev.:" << sqrt(m2 - m1 * m1) << endl;
        }
    }
    return 0;
}