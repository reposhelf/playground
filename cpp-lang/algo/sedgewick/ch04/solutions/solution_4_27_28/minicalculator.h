#ifndef MINICALCULATOR_H
#define MINICALCULATOR_H

// 0. клієнт передав вираз
// 1. клас приймає вираз
// 2. клас обнуляє результат
// 3. клас намагеється обчислити вираз
// 4. якщо вираз обчислюється без проблем, зберегти результат на видачу
// 5. якщо вираз не обчислюється через синтаксичні помилки, зберегти тип помилки
//      5.1. помилка кількості дужок

#include "multistack.h"

#include <string>

class MiniCalculator {
public:
    MiniCalculator() = default;

    void input(const std::string &input);
    int result() const { return _result; }

    bool is_good() const { return _is_good; }
    bool is_bad() const { return !_is_good; }

    std::string error_string() const { return "Syntax Error"; }

private:
    std::string infix_to_postfix(const std::string &expr);
    int evaluate_postfix_expr(const std::string &expr);

    MultiStack<char, int> _buffer;
    int _result = 0;
    bool _is_good = true;
};

#endif // MINICALCULATOR_H
