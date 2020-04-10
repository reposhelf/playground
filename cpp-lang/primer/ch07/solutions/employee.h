#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
public:
    Employee(const std::string &name,
	     const std::string &position,
	     unsigned experience,
	     float salary)
	: _name(name),
	_position(position),
	_experience(experience),
	_salary(salary)

private:
    std::string _name;
    std::string _position;
    unsigned _experience;
    float _salary;
};

#endif
