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
                double drn = (static_cast<double>(rand()) / (RAND_MAX));
                int irn = static_cast<int>(drn * r);

                m1 += (static_cast<double>(irn)) / n;
                m2 += (static_cast<double>(irn) * irn) / n;
            }
            cout << "        Avg.: " << m1 << endl;
            cout << "        Std. dev.:" << sqrt(m2 - m1 * m1) << endl;
        }
    }
    return 0;
}