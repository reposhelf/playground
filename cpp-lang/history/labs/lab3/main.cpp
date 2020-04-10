#include "matrix.h"
#include "array.h"

#include <string>
#include <iostream>

#define ROWS_COUNT 5
#define COLUMNS_COUNT 5
#define THRESHOLD 1

#define READ_FILE

int main(int argc, char **argv) {
    if (argc < 2) {
	std::cerr << "usage: lab3 [FILE_NAME]" << std::endl;
	return 1;
    }

#ifdef READ_FILE
    Matrix matrix(argv[1]);
#else
    Matrix matrix(ROWS_COUNT, COLUMNS_COUNT, THRESHOLD);
#endif

    std::cout << "matrix before handling" << std::endl;
    matrix.print();

    static const int mid = (COLUMNS_COUNT % 2)
	? COLUMNS_COUNT / 2 + 1 
	: COLUMNS_COUNT / 2;

    int i = 0;
    while (i < matrix.rows_count()) {
        if (matrix.row(i)->count_of(0) < mid) {
            matrix.remove_row(i);
            continue;
        }
        ++i;
    }

    std::cout << "matrix after handling" << std::endl;
    matrix.print();

    return 0;
}
