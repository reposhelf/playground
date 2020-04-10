#include "employee.h"

using namespace std;

size_t Employee::counter = 0;

Employee::Employee(const string &name)
    : _name(name), _id(counter++) { }