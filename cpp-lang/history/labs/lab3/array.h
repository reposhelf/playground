#ifndef ARRAY_H
#define ARRAY_H

#include <string>

class Array {
public:
    explicit Array(int size);
    explicit Array(const std::string &line);
    Array(int size, int threshold);
    ~Array();

    int count_of(int value) const;
    void print() const;

private:
    int read_size(const std::string &line) const;

    int *_data;
    int _size;
};

#endif
