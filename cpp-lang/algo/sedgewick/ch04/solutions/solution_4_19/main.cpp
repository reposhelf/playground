#include "stack.h"
#include "minicalculator.h"

#include <iostream>
#include <string>


inline void print_program_description()
{
    std::cout << "Program that calculates an arithmetic expressions." << std::endl;
    std::cout << "Type 'q' or 'quit' to exit." << std::endl;
}

inline bool maybeGoOut(const std::string &input)
{
    return input == "quit" || input == "q";
}

inline void printResult(const MiniCalculator &calculator)
{
    if (calculator.hasError())
        std::cout << calculator.errorString() << std::endl;
    else
        std::cout << calculator.getResult() << std::endl;
}

int main()
{
    print_program_description();
    MiniCalculator calculator;
    do {
        std::cout << "expr> ";

        std::string input;
        std::getline(std::cin, input);

        if (maybeGoOut(input))
            break;

        calculator.setExpression(input);
        printResult(calculator);
    } while (true);

    return 0;
}
