/*
 * Exercise 10.32:
 * Rewrite the bookstore problem from § 1.6 (p. 24) using a
 * vector to hold the transactions and various algorithms to do the processing.
 * Use sort with your compareIsbn function from § 10.3.1 (p. 387) to
 * arrange the transactions in order, and then use find and accumulate to
 * do the sum.
 */

#include "Sales_data.h"

#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream file("book_sales");
    istream_iterator<Sales_data> in(file), eof;
    vector<Sales_data> books(in, eof);

    ostream_iterator<Sales_data> out(cout, "\n");
    sort(books.begin(), books.end(), compareIsbn);
    copy(books.begin(), books.end(), out);

    cout << "Total: " << accumulate(books.begin(), books.end(), Sales_data());
    cout << endl;

    return 0;
}