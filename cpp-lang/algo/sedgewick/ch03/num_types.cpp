#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef int Number;

Number randNum()
{
    return rand();
}

int main(int argc, char *argv[])
{
    const int N = atoi(argv[1]);
    float m1 = 0.0, m2 = 0.0;

    for (int i = 0; i < N; ++i) {
        Number x = randNum();

        m1 += (static_cast<float>(x)) / N;
        m2 += (static_cast<float>(x) * x) / N;
    }
    cout << "Avg.: " << m1 << endl;
    cout << "Std. dev.: " << sqrt(m2 - m1 * m1) << endl;

    return 0;
}