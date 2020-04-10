/*
 * Exercise 4.22
 *
 * Suppose that you change the pushdown-stack interface to replace test 'if empty' by 'count',
 * which should return the number if items currently in the data structure. Provide implementations
 * for 'count' for the array representation and the linked-list representation.
 *
 */
#include "stack.h"

#include <iostream>
#include <cstring>

int main() {
    ArrayBased::Stack<int> numbers(10);
    for (size_t i = 0; i < 5; ++i)
        numbers.push(i);

    ListBased::Stack<char> chars(10);
    char word[] = "foo";
    size_t length = strlen(word);
    for (size_t i = 0; i < length; ++i)
        chars.push(word[i]);

    std::cout << "count of numbers: " << numbers.count() << std::endl;
    std::cout << "count of chars: " << chars.count() << std::endl;

    numbers.pop();
    numbers.pop();

    chars.pop();

    std::cout << "count of numbers: " << numbers.count() << std::endl;
    std::cout << "count of chars: " << chars.count() << std::endl;

    return 0;
}
