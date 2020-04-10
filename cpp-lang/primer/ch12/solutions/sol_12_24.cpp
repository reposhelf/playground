/*
 * Exercise 12.24:
 * Write a program that reads a string from the standard input
 * into a dynamically allocated character array. Describe how your program
 * handles varying size inputs. Test your program by giving it a string of data
 * that is longer than the array size you’ve allocated.
 */

#include "chapter12.h"

#include <cstring>

using namespace std;

size_t reserve(char* &text, size_t curr_sz)
{
    curr_sz *= 2;
    char *t = new char[curr_sz];
    strcpy(t, text);
    delete [] text;
    text = t;
    return curr_sz;
}

void sol_12_24()
{
    size_t size = 8;
    char *text = new char[size];

    size_t i = 0;
    char c;
    while (cin >> c) {
        text[i++] = c;
        if (i == size)
            size = reserve(text, size);
    }

    cout << text << endl;

    delete [] text;
}
