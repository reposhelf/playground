/*
 * Exercise 10.17:
 * Rewrite exercise 10.12 from § 10.3.1 (p. 387) to use a lambda in the call to
 * sort instead of the compareIsbn function.
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

    sort(vec.begin(), vec.end(),
        [] (const Sales_data &d1, const Sales_data &d2)
            { return d1.isbn() < d2.isbn(); });
    print(vec);

    return 0;
}