#ifndef GLOBAL_H
#define GLOBAL_H

inline bool isOperand(char ch)
{
    return ch >= '0' && ch <= '9';
}

inline bool isOperator(char ch)
{
    return ch == '-' || ch == '+' || ch == '/' || ch == '*' || ch == '$';
}

inline int getOperatorPriority(char ch)
{
    switch (ch) {
    case '+': case '-': return 1;
    case '/': case '*': return 2;
    case '$': return 3;
    default: return -1;
    }
}

inline bool isRightAssociative(char ch)
{
    return ch == '$';
}

inline bool hasHigherPriority(char previousOperator, char currentOperator)
{
    int previousOperatorPriority = getOperatorPriority(previousOperator);
    int currentOperatorPriority = getOperatorPriority(currentOperator);

    if (previousOperatorPriority == currentOperatorPriority)
        return !isRightAssociative(currentOperator);

    return previousOperatorPriority > currentOperatorPriority;
}

#endif // GLOBAL_H
