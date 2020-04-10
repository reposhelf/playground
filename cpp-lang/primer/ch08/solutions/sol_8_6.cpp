/*
 *
 * Exercise 8.6.
 *
 * Rewrite the bookstore program to read transactions from a file. Pass the name
 * of the file as an argument to main()
 *
 */

#include "salesdata.h"

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
    std::ifstream input(argv[1]);

    if (input) {
	SalesData total;

	if (read(input, total)) {
	    SalesData trans;

	    while (read(input, trans)) {
		if (total.isbn() == trans.isbn()) {
		    total.combine(trans);
		} else {
		    print(std::cout, total) << std::endl;
		    total = trans;
		}
	    }

	    print(std::cout, total) << std::endl;
	} else {
	    std::cerr << "no data?!" << std::endl;
	}
    } else {
	std::cerr << "couldn't open: " + std::string(argv[1]) << std::endl;
    }
    return 0;
}
