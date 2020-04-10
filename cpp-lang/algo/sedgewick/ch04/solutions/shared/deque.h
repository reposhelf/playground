#ifndef DEQUE_H
#define DEQUE_H

#include <cstdlib>

//#define ARRAY_BASED

#ifdef ARRAY_BASED
template<class T> class Deque {
public:
    Deque()
        : _capacity(1),
          _size(0),
          _front(0),
          _back(_capacity - 1),
          _data(new T[_capacity]) {}

    ~Deque() { delete[] _data; }

    bool empty() const { return _size == 0; }
    size_t size() const { return _size; }

    T front() const {
        if (empty())
            return 0;
        return _data[_front];
    }

    T back() const {
        if (empty())
            return 0;
        return _data[_back];
    }

    void push_front(const T &value) {
        check_increase_space();

        if (_front == 0)
            _front = _capacity - 1;
        else
            --_front;

        _data[_front] = value;
        ++_size;
    }

    void push_back(const T &value) {
        check_increase_space();

        _back = (_back + 1) % _capacity;

        _data[_back] = value;
        ++_size;
    }

    void pop_front() {
        if (!empty()) {
            _front = (_front + 1) % _capacity;
            --_size;

            check_decrease_space();
        }
    }

    void pop_back() {
        if (!empty()) {
            if (_back == 0)
                _back = _capacity - 1;
            else
                --_back;

            --_size;

            check_decrease_space();
        }
    }

    void clear() {
        delete[] _data;
        init();
    }

private:
    void init() {
        _capacity = 1;
        _size = 0;
        _front = 0;
        _back = _capacity - 1;
        _data = new T[_capacity];
    }

    void reserve(size_t new_capacity) {
        T *copy_data = new T[new_capacity];
        for (size_t i = 0; i < _size; ++i) {
            copy_data[i] = _data[_front];
            _front = (_front + 1) % _capacity;
        }
        _capacity = new_capacity;
        delete[] _data;
        _data = copy_data;
        _front = 0;
        _back = _size - 1;
    }

    bool full() const { return _size == _capacity; }
    bool can_shrink() const { return (_size > 0 && _size == _capacity / 4); }

    void check_increase_space() {
        if (full())
            reserve(_capacity * 2);
    }

    void check_decrease_space() {
        if (can_shrink())
            reserve(_capacity / 2);
    }

    size_t _capacity;
    size_t _size;
    size_t _front;
    size_t _back;
    T *_data;
};

#else
template<typename T>
class Deque {
public:
    Deque() : m_front(nullptr), m_back(nullptr), m_size(0) {}
    ~Deque() { clear(); }

    bool empty() const { return m_size == 0; }
    size_t size() const { return m_size; }

    T front() const { return empty() ? 0 : m_front->item; }
    T back() const { return empty() ? 0 : m_back->item; }

    void push_front(const T &value) {
        m_front = new Node(value, nullptr, m_front);

        if (empty())
            m_back = m_front;
        else
            m_front->next->prev = m_front;

        ++m_size;
    }

    void push_back(const T &value) {
        m_back = new Node(value, m_back, nullptr);

        if (empty())
            m_front = m_back;
        else
            m_back->prev->next = m_back;

        ++m_size;
    }

    void pop_front() {
        if (empty())
            return;

        if (m_size > 1) {
            m_front = m_front->next;
            delete m_front->prev;
            m_front->prev = nullptr;
        } else {
            delete m_front;
            m_front = m_back = nullptr;
        }

        --m_size;
    }

    void pop_back() {
        if (empty())
            return;

        if (m_size > 1) {
            m_back = m_back->prev;
            delete m_back->next;
            m_back->next = nullptr;
        } else {
            delete m_back;
            m_back = m_front = nullptr;
        }

        --m_size;
    }

    void clear() {
        while (!empty())
            pop_back();
    }

private:
    struct Node {
        T item;
        Node *prev;
        Node *next;

        Node(const T &i, Node *p, Node *n)
            : item(i), prev(p), next(n) {}
    };

    Node *m_front;
    Node *m_back;
    size_t m_size;
};

#endif

#endif // DEQUE_H
