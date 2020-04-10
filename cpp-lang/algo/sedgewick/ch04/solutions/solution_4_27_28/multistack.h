#ifndef MULTISTACK_H
#define MULTISTACK_H

#include <string>
#include <iostream>

template <typename L, typename R>
class MultiStack {
public:
    MultiStack() = default;
    explicit MultiStack(size_t size) {
        _data = new void *[size];
        _max_size = size;
        _rhs_index = size;
    }

    ~MultiStack() {
        free_memory();
    }

    bool empty_lhs() const {
        return _lhs_index == 0;
    }

    bool empty_rhs() const {
        return _rhs_index == _max_size;
    }

    bool empty() const {
        return empty_lhs() && empty_rhs();
    }

    void push_lhs(L item) {
        if (!overflow_lhs()) {
            _data[_lhs_index++] = static_cast<void*>(new L(item));
        } else {
            error("can not push, stack is full");
        }
    }

    void push_rhs(R item) {
        if (!overflow_rhs()) {
            _data[--_rhs_index] = static_cast<void*>(new R(item));
        } else {
            error("can not push, stack is full");
        }
    }

    L pop_lhs() {
        if (!empty_lhs()) {
            L value = *(static_cast<L*>(_data[--_lhs_index]));
            delete static_cast<L*>(_data[_lhs_index]);
            _data[_lhs_index] = nullptr;
            return value;
        }
        return L();
    }

    R pop_rhs() {
        if (!empty_rhs()) {
            R value = *(static_cast<R*>(_data[_rhs_index]));
            delete static_cast<R*>(_data[_rhs_index]);
            _data[_rhs_index++] = nullptr;
            return value;
        }
        return R();
    }

    L top_lhs() const {
        if (!empty_lhs()) {
            return *(static_cast<L*>(_data[_lhs_index - 1]));
        }
        return L();
    }

    R top_rhs() const {
        if (!empty_rhs()) {
            return *(static_cast<R*>(_data[_rhs_index]));
        }
        return R();
    }

    void clear_lhs() {
        while (!empty_lhs()) {
            delete static_cast<L*>(_data[--_lhs_index]);
            _data[_lhs_index] = nullptr;
        }
    }

    void clear_rhs() {
        while (!empty_rhs()) {
            delete static_cast<R*>(_data[_rhs_index]);
            _data[_rhs_index++] = nullptr;
        }
    }

    void clear() {
        clear_lhs();
        clear_rhs();
    }

    void resize(size_t new_size) {
        free_memory();
        _data = new void *[new_size];
        _max_size = new_size;
        _rhs_index = new_size;
    }

private:
    void free_memory() {
        clear();
        delete[] _data;
        _data = nullptr;
    }

    bool overflow_lhs() const {
        return _lhs_index >= _max_size - 1 || _lhs_index == _rhs_index;
    }

    bool overflow_rhs() const {
        return _rhs_index <= 0 || _rhs_index - 1 == _lhs_index;
    }

    void error(const std::string &msg) const {
        std::cout << msg << std::endl;
    }

    void **_data = nullptr;
    size_t _lhs_index = 0;
    size_t _rhs_index = 0;
    size_t _max_size = 0;
};

#endif // MULTISTACK_H
