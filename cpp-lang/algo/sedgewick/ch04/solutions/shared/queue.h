#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <cstdlib>
#include <new>

namespace ListBased
{
template <typename T>
class Queue
{
private:
    void error(const char *msg) {
        std::cout << msg << std::endl;
    }

    static void out_of_memory_handler() {
        std::cerr << "Can not allocate memory by new-operator calling" << std::endl;
        std::abort();
    }

    struct node {
        T item;
        node *next;
        node(T i) : item(i), next(nullptr) {}
    };
    typedef node *link;

    link head, tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    bool empty() const {
        return head == nullptr;
    }

    void put(T item) {
        std::set_new_handler(out_of_memory_handler);

        link t = tail;
        tail = new node(item);
        if (!head) {
            head = tail;
        } else {
            t->next = tail;
        }
    }

    T get() {
        if (empty()) {
            error("Can not get item from empty queue");
            return 0;
        }

        T v = head->item;
        link t = head->next;
        delete head;
        head = t;
        return v;
    }
};
}


namespace ArrayBased
{
template <typename T>
class Queue
{
private:
    void error(const char *msg) {
        std::cout << msg << std::endl;
    }

    T *q;
    int N;
    int head;
    int tail;

public:
    explicit Queue(int size)
        : q(new T[size + 1]),
          N(size + 1),
          head(size + 1),
          tail(0) {}

    bool empty() const {
        return head % N == tail;
    }

    void put(T item) {
        if (tail + 1 == head % N) {
            error("Can not put item to full queue");
            return;
        }

        q[tail++] = item;
        tail %= N;
    }

    T get() {
        if (empty()) {
            error("Can not get item from empty queue");
            return 0;
        }

        head %= N;
        return q[head++];
    }
};
}

#endif // QUEUE_H
