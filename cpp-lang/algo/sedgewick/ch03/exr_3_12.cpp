#include <iostream>
using namespace std;

int main()
{
    for (uint n = 1000; n <= 1000000; n *= 10)
    {
        bool list[n];
        for (uint i = 0; i < n; ++i)
        {
            list[i] = true;
        }

        for (uint i = 2; i < n; ++i)
        {
            if (list[i])
            {
                for (uint j = i; j * i < n; ++j)
                {
                    list[j * i] = false;
                }
            }
        }

        int count = 0;
        for (uint i = 0; i < n; ++i)
        {
            if (list[i])
            {
                ++count;
            }
        }

        cout << "count of primes for n = " << n << ": " << count << endl;
    }
    
    return 0;
}