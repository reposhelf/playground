#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
public:
    explicit Employee(const std::string &name = std::string());
    Employee(const Employee &) = delete;
    Employee &operator=(const Employee &) = delete;
    ~Employee() = default;
    
    void set_name(const std::string &name) { _name = name; }
    const std::string &name() const { return _name; }
    size_t id() const { return _id; }

private:
    static size_t counter;
    std::string _name;
    size_t _id;
};

#endif