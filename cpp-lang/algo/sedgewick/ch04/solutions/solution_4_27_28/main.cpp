/*
 *
 * Exercises 4.27 and 4.28.
 *
 * Develop an ADT that provides clients with two differnt pushdown stacks. Use an array
 * implementation. Keep one stack at the beginning of the array and the other at the end.
 * (If the client program is such that the one stack grows while the other one shrinks, this
 * implementation uses less space than other alternatives).
 *
 * Implement an infix-expression-evaluation function for integers usin previously developed
 * ADT.
 *
 * Note: You have to cope with the fact that both stacks have to contain items of the same type.
 *
 */


// 0. програма виводить короткий опис
// 1. програма просить ввести арифметичний вираз
// 2. юзер вводить вираз
//      2.1. якщо юзер ввів 'q' чи 'quit', програма завершує роботу
// 3. якщо юзер НЕ ввів 'q' чи 'quit', програма обчислює вираз
// 4. програма виводить результат
// 5. програма продовжує виконання з пункту 1

#include "minicalculator.h"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

void print_program_description() {
    cout << "This program evaluates simple arithmetic expressions like (1 + (2 + 3) * 4)" << endl;
    cout << "Type 'q' or 'quit' to exit" << endl;
}

void print_offer_input() {
    cout << "expr> ";
}

bool maybe_to_go(const string &input) {
    return input == "q" || input == "quit";
}

int main() {
    print_program_description();

    MiniCalculator calculator;

    do {
        print_offer_input();

        string input;

        std::getline(cin, input);

        if (maybe_to_go(input))
            break;

        calculator.input(input);

        if (calculator.is_good()) {
            cout << calculator.result() << endl;
        } else {
            cout << calculator.error_string() << endl;
        }

    } while (true);
    return 0;
}
