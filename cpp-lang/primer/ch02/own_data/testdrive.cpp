#include "salesdata.h"

#include <iostream>
#include <string>
using namespace std;

int main()
{
    SalesData data1, data2;

    double price = 0.0;
    
    // code to write data for 'data1' and 'data2'
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;

    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;
    
    // code to compare ISBNs from 'data1' and 'data2'
    if (data1.bookNo == data2.bookNo)
    {
        // code to sum prices from 'data1' and 'data2'
        unsigned totalCount = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        // print: ISBN, total count of books, total
        // revenue and average price for a book
        cout << data1.bookNo << " " << totalCount
             << " " << totalRevenue << " ";
        if (totalCount != 0)
        {
            cout << totalRevenue / totalCount << endl;
        }
        else
        {
            cout << "(no sales)" << endl;
        }
        return 0;
    }
    else
    {
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }

    return 0;
}