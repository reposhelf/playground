/*
 *
 * Exercise 4.25
 *
 * Modify the linked-list-based pushdown-stack implementation to use an array of indices
 * to implement the list
 *
 */

#include <iostream>
#include <cstring>

template <typename T>
class Stack {

private:
    void error(const char *message) const {
        std::cout << message << std::endl;
    }

    static void out_of_memory_handler() {
        std::cerr << "Can not allocate memory by new-operator calling" << std::endl;
        std::abort();
    }

    size_t _index = 0;
    size_t _max_size = 0;

    struct node {
        T item;
        size_t next;
        node(T i, size_t n) {
            item = i;
            next = n;
        }
    };
    typedef node *link;

    link *_buffer;

public:
    explicit Stack(int size) {
        _buffer = new link[size];
        _max_size = size;
    }

    bool empty() const {
        return _index == 0;
    }

    size_t count() const {
        return _index;
    }

    void push(T item) {
        if (_index == _max_size) {
            error("Can not add item into full stack");
            return;
        }

        link l = new node(item, _index + 1);

        _buffer[_index++] = l;
    }

    T pop() {
        if (empty()) {
            error("Can not pop item from empty stack.");
            return 0;
        }

        T res = top();
        delete _buffer[--_index];
        return res;
    }

    T top() {
        return _buffer[_index - 1]->item;
    }
};


int main() {
    Stack<int> numbers(5);
    for (size_t i = 0; i <= 6; ++i)
        numbers.push(i);

    Stack<char> chars(3);
    char word[] = "foo";
    size_t length = strlen(word);
    for (size_t i = 0; i < length; ++i)
        chars.push(word[i]);

    for (size_t i = 0; i <= length+1; ++i)
        chars.pop();

    return 0;
}
