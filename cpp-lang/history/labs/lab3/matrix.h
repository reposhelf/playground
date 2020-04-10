#ifndef MATRIX_H
#define MATRIX_H

#include <list>
#include <string>

class Array;
class Matrix {
public:
    Matrix(int rows_count, int columns_count, int threshold);
    Matrix(const std::string &file_name);
    ~Matrix();

    Array *row(int index) const;
    int rows_count() const;
    void remove_row(int index);
    void print() const;

private:
    std::list<Array*> _arrays;
};

#endif
