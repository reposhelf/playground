/*
 *
 * Exercise 8.7.
 *
 * Revise the bookstore program from the previous section to write its
 * output to a file. Pass the name of that file as a second argument to main.
 *
 * Exercise 8.8.
 * 
 * Revise the program from the previous exercise to append its output to its
 * given file. Run the program on the same output file at least twice to
 * ensure that the data are preserved.
 * 
 */

#include "salesdata.h"

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iostream>
#include <string>

int main(int argc, char **argv) {
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);

    if (input) {
	SalesData total;

	if (read(input, total)) {
	    SalesData trans;

	    while (read(input, trans)) {
		if (total.isbn() == trans.isbn()) {
		    total.combine(trans);
		} else {
		    print(output, total) << std::endl;
		    total = trans;
		}
	    }

	    print(output, total) << std::endl;
	} else {
	    std::cerr << "no data?!" << std::endl;
	}
    } else {
	std::cerr << "couldn't open: " + std::string(argv[1]) << std::endl;
    }
    return 0;
}
