#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

void doExr32();
void doExr33();

int main()
{
    doExr32();
    doExr33();

    return 0;
}

void doExr32()
{
    cout << "exr 3.2 in action" << endl;

    for (int r = 2; r <= 16; r *= r) {
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
}

void doExr33()
{
    cout << "exr 3.3 in action" << endl;

    for (int r = 2; r <= 16; r *= r) {
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
}
