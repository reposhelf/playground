#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
    // get maximum number
    int maxNumber = atoi(argv[1]);
    if (!maxNumber)
    {
        cout << "error: invalid value." << endl;
        return 0;
    }

    // create array dynamically
    bool *array = new bool[maxNumber];
    if (!array)
    {
        cout << "error: out of memory." << endl;
        return 0;
    }

    // fill array's elements by '1'
    for (int i = 2; i < maxNumber; ++i)
        array[i] = true;

    // find primes
    for (int i = 2; i < maxNumber; ++i)
    {
        if (array[i])
        {
            for (int j = i; j * i < maxNumber; ++j)
                array[j * i] = false;
        }
    }

    // print primes
    for (int i = 2; i < maxNumber; ++i)
    {
        if (array[i])
            cout << i << endl;
    }
    return 0;
}