#include <iostream>
#include <cstdlib>
using namespace std;

// true if tails of coin occurs
bool heads()
{
    return rand() < RAND_MAX / 2;
}

int main(int argc, char *argv[])
{
    // get tossing count
    int tossingCount = atoi(argv[1]);
    if (!tossingCount)
    {
        cout << "error: invalid value or zero occurs." << endl;
        return 0;
    }

    // get experiment count
    int experimentCount = atoi(argv[2]);
    if (!experimentCount)
    {
        cout << "error: invalid value or zero occurs." << endl;
        return 0;
    }

    // create list of results
    int *results = new int[tossingCount + 1];
    for (int i = 0; i <= tossingCount; ++i)
    {
        results[i] = 0;
    }

    // simulation of the tossing of coin
    int tailsCount = 0;
    for (int i = 0; i < experimentCount; ++i, ++results[tailsCount])
    {
        tailsCount = 0;
        for (int j = 0; j < tossingCount; ++j)
        {
            if (heads())
            {
                ++tailsCount;
            }
        }
    }

    // print result
    for (int i = 0;  i < tossingCount; ++i)
    {
        if (results[i] == 0)
        {
            cout << ".";
        }

        for (int j = 0; j < results[i]; j += 10)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}