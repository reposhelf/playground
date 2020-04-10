/*
 * Exercise 4.20.
 * Implement a compiler and interpreter for a programming language where
 * each program consists of a single expression preceded by a sequence
 * of assigment statements with arithmetic expressions involving integers
 * and variables named with single lower-case characters. For example, given
 * the input
 *
 * (x = 1)
 * (y = (x + 1))
 * (((x + y) * 3) + (4 * x))
 *
 * your program should print the value 13.
 */

#include "minicompiler.h"

#include <cctype>
#include <iostream>
#include <string>

int main() {
    MiniCompiler compiler;
    std::cout << compiler.description() << std::endl;

    do {
        compiler.print_offer_input();

        std::string input;
        std::getline(std::cin, input);

        if (compiler.maybe_exit(input))
            break;

        compiler.process_expression(input);

    } while (true);

    return 0;
}
