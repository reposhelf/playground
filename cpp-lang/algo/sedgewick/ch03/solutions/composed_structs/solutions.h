#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <cstddef>

/*
 * Exercise 3.62.
 * Write a version of program that handles three-dimensional arrays
 */
void solve_3_62();
int ***malloc3d(std::size_t x, std::size_t y, std::size_t z);
void release3d(int ***arr3d, std::size_t x, std::size_t y);
void print3d(int ***arr3d, std::size_t x, std::size_t y, std::size_t z);

/*
 * Exercise 3.63.
 * Modify program to process input string individually (allocate memory
 * for each string agter reading it from the input). You can assume that
 * all strings have less than 100 characters.
 */
int compare(const void *a, const void *b);
void solve_3_63();

/*
 * Exercise 3.64.
 * Write a program to fill in two-dimensional array of 0-1 values by setting
 * a[i][j] to 1 if the greates common divisor of i and j is 1, and to 0 otherwise.
 */
int gcd(int a, int b);
void solve_3_64();

#endif