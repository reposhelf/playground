#include "array.h"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>

inline int rand_num(int threshold) {
    time_t t;
    srand((unsigned)time(&t));
    return rand() % threshold + 1;
}

inline void out_of_range_error() {
    std::cerr << "error: out of range" << std::endl;
    exit(1);
}

Array::Array(int size)
    : _data(new int[size]),
      _size(size) {
}

Array::Array(const std::string &line) {
    _size = read_size(line);
    _data = new int[_size];

    std::istringstream input(line);
    std::string number;
    int *it = _data;
    while (input >> number) {
	if (it == _data + _size)
	    out_of_range_error();

	*it = std::stoi(number);
	++it;
    }
}

Array::Array(int size, int threshold)
    : Array(size) {
    for (int *it = _data; it != _data + size; ++it)
	*it = rand_num(threshold);
}

Array::~Array() {
    delete[] _data;
}

int Array::count_of(int value) const {
    int count = 0;

    for (int *it = _data; it != _data + _size; ++it) {
	if (*it == value)
	    ++count;
    }

    return count;
}

void Array::print() const {
    for (int *it = _data; it != _data + _size; ++it)
	std::cout << *it << " ";
    std::cout << std::endl;
}

int Array::read_size(const std::string &line) const {
    std::istringstream input(line);
    int count = 0;
    std::string dummy;
    while (input >> dummy)
	++count;

    return count;
}

