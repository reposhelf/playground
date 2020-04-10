#include "chapter07.h"
#include "salesdata.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

void handleTransactions()
{
    SalesData total;
    if (read(cin, total)) {
        SalesData transaction;
        while (read(cin, transaction)) {
            if (total.isbn() == transaction.isbn()) {
                total.combine(transaction);
            } else {
                print(cout, total) << endl;
                total = transaction;
            }
        }
        print(cout, total) << endl;
    } else {
        cerr << "No data?!" << endl;
    }
}

void solution_7_11()
{
    SalesData itemFromStream(cin);
    print(cout, itemFromStream) << endl;

    SalesData itemWithBookNo("0-201-70353-X");
    print(cout, itemWithBookNo) << endl;

    SalesData itemEntirely("0-201-70353-X", 4, 24.99);
    print(cout, itemEntirely) << endl;

    SalesData itemEmpty;
    print(cout, itemEmpty) << endl;
}

void solution_7_13()
{
    SalesData total(cin);
    if (cin) {
	while (cin) {
	    SalesData transaction(cin);
	    if (total.isbn() == transaction.isbn()) {
		total.combine(transaction);
	    } else {
		print(cout, total) << endl;
		total = transaction;
	    }
	}
    } else {
	cerr << "No data?!" << endl;
    }
}

int main(int, char **)
{
    solution_7_13();
    return 0;
}
