/*
 * Exercise 3.36:
 * Write a program to compare two arrays for equality. Write a
 * similar program to compare two vectors.
 */
#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <iterator>
using std::begin;
using std::end;

void compareArrays();
void compareVectors();
bool equal(int *b1, int *e1, int *b2, int *e2);

int main()
{
    compareArrays();
    compareVectors();

    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {1, 2, 3, 4, 5};

    auto b1 = begin(array1);
    auto e1 = end(array1);

    auto b2 = begin(array2);
    auto e2 = end(array2);

    cout << equal(b1, e1, b2, e2) << endl;

    return 0;
}

void compareArrays()
{
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {1, 2, 3, 4, 7};

    auto s1 = sizeof(array1) / sizeof(decltype(array1[0]));
    auto s2 = sizeof(array2) / sizeof(decltype(array2[0]));

    if (s1 != s2)
    {
        cout << "Arrays aren't equal" << endl;
        return;
    }

    for (decltype(s1) i = 0; i < s1; ++i)
    {
        if (array1[i] != array2[i])
        {
            cout << "Arrays aren't equal" << endl;
            return;
        }
    }

    cout << "Arrays are equal" << endl;
}

void compareVectors()
{
    vector<int> vec1{1, 2, 3, 4, 5};
    vector<int> vec2{1, 2, 3, 4, 5, 6};

    if (vec1.size() != vec2.size())
    {
        cout << "Vectors aren't equal" << endl;
        return;
    }

    auto sz = vec1.size();
    for (decltype(sz) i = 0; i < sz; ++i)
    {
        if (vec1[i] != vec2[i])
        {
            cout << "Vectors aren't equal" << endl;
            return;
        }
    }

    cout << "Vectors are equal" << endl;
}

bool equal(int *b1, int *e1, int *b2, int *e2)
{
    while (!(b1 == e1 && b2 == e2))
    {
        if (*b1 != *b2)
        {
            return false;
        }

        ++b1;
        ++b2;

        if ((b1 == e1 && b2 != e2)
            || (b1 != e1 && b2 == e2))
        {
            return false;
        }
    }

    return true;
}