#ifndef SOPERAND_H
#define SOPERAND_H

#include <string>

class SOperand
{
public:
    SOperand() = default;
    SOperand(const std::string &value);
    bool isEmpty() const;
    void clear();
    void setValue(const std::string &value);
    operator std::string() const;
    operator int() const;

private:
    std::string m_value;
};

#endif // SOPERAND_H
