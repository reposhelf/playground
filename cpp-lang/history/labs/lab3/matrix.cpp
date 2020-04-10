#include "matrix.h"
#include "array.h"

#include <iostream>
#include <fstream>
#include <sstream>

inline void out_of_range_error() {
    std::cerr << "error: out of range" << std::endl;
    exit(1);
}

Matrix::Matrix(int rows_count, int columns_count, int threshold) {
    for (int i = 0; i < rows_count; ++i)
        _arrays.push_back(new Array(columns_count, threshold));
}

Matrix::Matrix(const std::string &file_name) {
    std::ifstream input(file_name);
    std::string line;
    while (std::getline(input, line)) {
	_arrays.push_back(new Array(line));
    }
}

Matrix::~Matrix() {
    for (size_t i = 0; i < _arrays.size(); ++i)
        delete row(i);

    _arrays.clear();
}

Array *Matrix::row(int index) const {
    if (index < 0 || index >= rows_count())
        out_of_range_error();

    std::list<Array*>::const_iterator it = _arrays.begin();
    std::advance(it, index);
    return *it;
}

int Matrix::rows_count() const {
    return _arrays.size();
}

void Matrix::remove_row(int index) {
    if (index < 0 || index >= rows_count())
        out_of_range_error();

    delete row(index);
    _arrays.remove(row(index));
}

void Matrix::print() const {
    for (size_t i = 0; i < _arrays.size(); ++i)
        row(i)->print();
}
