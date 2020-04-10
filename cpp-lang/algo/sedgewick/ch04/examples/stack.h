#ifndef STACK_H
#define STACK_H

#include <cstdlib>

namespace ArrayBased
{
template <typename T>
class Stack
{
private:
    T *_buffer = nullptr;
    size_t _index = 0;

public:
    explicit Stack(int size) {
        _buffer = new T[size];
    }

    bool empty() const {
        return _index == 0;
    }

    void push(T item) {
        _buffer[_index++] = item;
    }

    T pop() {
        return _buffer[--_index];
    }
};
}

namespace ListBased
{
template <typename T>
class Stack
{
private:
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
    explicit Stack(int /*size*/) {
        _head = nullptr;
    }

    bool empty() const {
        return _head == nullptr;
    }

    void push(T item) {
        _head = new node(item, _head);
    }

    T pop() {
        T i = _head->item;
        link t = _head->next;
        delete _head;
        _head = t;
        return i;
    }
};
}

#endif // STACK_H
