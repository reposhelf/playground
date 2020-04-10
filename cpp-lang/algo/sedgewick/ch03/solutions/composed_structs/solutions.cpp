#include "solutions.h"

#include <cstddef>
using std::size_t;

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstring>
#include <cstdlib>

/*
 * Exercise 3.62.
 * Write a version of program that handles three-dimensional arrays
 */
void solve_3_62()
{
    constexpr size_t x_sz = 3;
    constexpr size_t y_sz = 3;
    constexpr size_t z_sz = 3;
    int ***arr3d = malloc3d(x_sz, y_sz, z_sz);
    for (size_t i = 0; i != x_sz; ++i) {
        for (size_t j = 0; j != y_sz; ++j) {
            for (size_t k = 0; k != z_sz; ++k) {
                arr3d[i][j][k] = 3;
            }
        }
    }
    print3d(arr3d, x_sz, y_sz, z_sz);
    release3d(arr3d, x_sz, y_sz);
}

int ***malloc3d(size_t x, size_t y, size_t z)
{
    int ***t = new int**[x];
    for (size_t i = 0; i < x; ++i) {
        int **nt = (t[i] = new int*[y]);
        for (size_t j = 0; j < y; ++j) {
            nt[j] = new int[z];
        }
    }
    return t;
}

void release3d(int ***arr3d, std::size_t x, std::size_t y)
{
    for (size_t i = 0; i != x; ++i) {
        for (size_t j = 0; j != y; ++j) {
            delete[] arr3d[i][j];
        }
        delete[] arr3d[i];
    }
    delete[] arr3d;
}

void print3d(int ***arr3d, size_t x, size_t y, size_t z)
{
    for (size_t i = 0; i != x; ++i) {
        for (size_t j = 0; j != y; ++j) {
            for (size_t k = 0; k != z; ++k) {
                cout << arr3d[i][j][k] << endl;
            }
        }
    }
}

/*
 * Exercise 3.63.
 * Modify program to process input string individually (allocate memory
 * for each string agter reading it from the input). You can assume that
 * all strings have less than 100 characters.
 */
int compare(const void *a, const void *b)
{
    return strcmp(*(char**)a, *(char**)b);
}

void solve_3_63()
{
    const size_t ptrs_sz = 1000;
    char *ptrs[ptrs_sz];

    size_t size = 0;
    for (size_t i = 0; i != ptrs_sz; ++i) {
        const size_t char_sz = 256;
        ptrs[i] = new char[char_sz];
        if (!(cin >> ptrs[i]))
            break;
        ++size;
    }

    qsort(ptrs, size, sizeof(char*), compare);

    for (size_t i = 0; i != size; ++i)
        cout << ptrs[i] << endl;
}

/*
 * Exercise 3.64.
 * Write a program to fill in two-dimensional array of 0-1 values by setting
 * a[i][j] to 1 if the greates common divisor of i and j is 1, and to 0 otherwise.
 */
int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve_3_64()
{
    constexpr size_t rows = 10;
    constexpr size_t cols = 10;
    int matrix[rows][cols] = {}; // set all to zero

    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != cols; ++j) {
            if (gcd(i, j) == 1)
                matrix[i][j] = 1;
        }
    }

    // print
    for (size_t i = 0; i != rows; ++i) {
        for (size_t j = 0; j != cols; ++j)
            cout << "[" << i << "][" << j << "]: " << matrix[i][j] << endl;
    }
}
