/*
 * Exercise 4.24
 *
 * Modify the linked-list-based pushdown-stack implementation to call a member function error()
 * if the client attempts to pop when the stack is empty or if there is no memory available
 * from new for a push.
 *
 */

#include "stack.h"

#include <cstring>

int main() {
    ListBased::Stack<int*> numbers;
    int *item = nullptr;
    numbers.push(item);

    ListBased::Stack<char> chars;
    char word[] = "foo";
    size_t length = strlen(word);
    for (size_t i = 0; i < length; ++i)
        chars.push(word[i]);

    for (size_t i = 0; i <= length+1; ++i)
        chars.pop();


    return 0;
}
