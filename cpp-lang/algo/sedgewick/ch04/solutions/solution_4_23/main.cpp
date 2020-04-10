/*
 *
 * Exercise 4.23
 *
 * Modify the array-based pushdown-stack implementation to call a member function error() if the
 * client attempts to pop when the stack is empty or to push when the stack is full.
 *
 */

#include "stack.h"

#include <cstring>

int main() {
    ArrayBased::Stack<int> numbers(5);
    for (size_t i = 0; i <= 6; ++i)
        numbers.push(i);

    ArrayBased::Stack<char> chars(3);
    char word[] = "foo";
    size_t length = strlen(word);
    for (size_t i = 0; i < length; ++i)
        chars.push(word[i]);

    for (size_t i = 0; i <= length+1; ++i)
        chars.pop();

    return 0;
}
