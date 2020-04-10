#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <iostream>
#include <new>

namespace ArrayBased {

template <typename T>
class Stack {

private:
    void error(const char *message) const {
        std::cout << message << std::endl;
    }

    T *_buffer = nullptr;
    size_t _index = 0;
    size_t _count = 0;
    size_t _max_count = 0;

public:
    explicit Stack(size_t size) {
        _buffer = new T[size];
        _max_count = size;
    }

    bool empty() const {
        return _index == 0;
    }

    size_t count() const {
        return _index;
    }

    void push(T item) {
        if (_index == _max_count) {
            error("Can not push item into full stack");
            return;
        }

        _buffer[_index++] = item;
    }

    T pop() {
        if (empty()) {
            error("Can not pop item from empty stack.");
            return 0;
        }

        return _buffer[--_index];
    }

    T top() const {
        return _buffer[_index - 1];
    }
};
}

namespace ListBased {

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

    size_t _count = 0;

    struct node {
        T item;
        node *next;
        node(T i, node *n) {
            item = i;
            next = n;
        }
    };
    typedef node *link;
    link _head;

public:
    explicit Stack(int = 0) {
        _head = nullptr;
    }

    bool empty() const {
        return _head == nullptr;
    }

    size_t count() const {
        return _count;
    }

    void push(T item) {
        std::set_new_handler(out_of_memory_handler);
//        new int[10000000000L];

        _head = new node(item, _head);
        ++_count;
    }

    T pop() {
        if (empty()) {
            error("Can not pop item from empty stack.");
            return 0;
        }

        --_count;
        T i = top();
        link t = _head->next;
        delete _head;
        _head = t;
        return i;
    }

    T top() {
        return _head->item;
    }
};
}

#endif // STACK_H
