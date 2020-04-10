#include "salesdata.h"

#include <fstream>
#include <iostream>

int main(int argc, char **argv) {
    std::ifstream input(argv[1]);
    std::ofstream output(argv[2]);

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
	std::cerr << "No data&!" << std::endl;
    }
    return 0;
}
