#ifndef QUEUE_H
#define QUEUE_H

namespace ListBase
{
template <typename T>
class Queue
{
private:
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

    bool enpty() const {
        return head == nullptr;
    }

    void put(T item) {
        link t = tail;
        tail = new node(item);
        if (!head) {
            head = tail;
        } else {
            t->next = tail;
        }
    }

    T get() {
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
        q[tail++] = item;
        tail %= N;
    }

    T get() {
        head %= N;
        return q[head++];
    }
};
}

#endif // QUEUE_H
