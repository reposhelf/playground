/*
 * Exercise 10.12:
 * Write a function named compareIsbn that compares the isbn() members of two
 * Sales_data objects. Use that function to sort a vector that holds Sales_data objects.
 */

#include "Sales_data.h"

#include <fstream>
using std::ifstream;

#include <iostream>
using std::cout; using std::cerr; using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort;

bool compareIsbn(const Sales_data &sd1, const Sales_data &sd2)
{
    return sd1.isbn() < sd2.isbn();
}

void print(const vector<Sales_data> &v)
{
    for (const Sales_data &sd : v) {
        print(cout, sd);
        cout << endl;
    }
}

int main()
{
    ifstream in("book_sales");
    if (!in.is_open()) {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    vector<Sales_data> vec;
    Sales_data sd;
    while (read(in, sd))
        vec.push_back(sd);

    sort(vec.begin(), vec.end(), compareIsbn);
    print(vec);

    return 0;
}