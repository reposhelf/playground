#ifndef SOPERATOR_H
#define SOPERATOR_H

#include <string>

class SOperator
{
public:
    SOperator() = default;
    SOperator(const std::string &sign);
    bool isEmpty() const;
    bool isValid() const;
    void clear();
    void setSign(const std::string &sign);

    static const std::string ADD_STR;
    static const std::string SUB_STR;
    static const std::string MUL_STR;
    static const std::string DIV_STR;
    static const std::string MOD_STR;
    static const std::string RES_STR;

private:
    std::string m_sign;

    friend bool operator==(const SOperator &lhs, const SOperator &rhs);
    friend bool operator!=(const SOperator &lhs, const SOperator &rhs);
    friend bool operator<(const SOperator &lhs, const SOperator &rhs);
};

inline bool operator==(const SOperator &lhs, const SOperator &rhs)
{
    return lhs.m_sign == rhs.m_sign;
}

inline bool operator!=(const SOperator &lhs, const SOperator &rhs)
{
    return !(lhs == rhs);
}

inline bool operator<(const SOperator &lhs, const SOperator &rhs)
{
    return lhs.m_sign < rhs.m_sign;
}

#endif // SOPERATOR_H
