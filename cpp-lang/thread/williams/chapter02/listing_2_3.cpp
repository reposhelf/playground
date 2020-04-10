/*
 * Listing 2.3:
 * Using RAII to wait for a thread to complete.
 */

#include <iostream>
#include <thread>

using namespace std;

class thread_guard
{
    thread &t;

public:
    explicit thread_guard(thread &t_) : t(t_) {}
    ~thread_guard()
    {
        if (t.joinable())
            t.join();
    }
    thread_guard(const thread_guard&) = delete;
    thread_guard &operator=(const thread_guard&) = delete;
};

struct func
{
    int &i;
    
    func(int i_) : i(i_) {}

    void operator()()
    {
        for (size_t i = 0; i < 1000000; ++i)
            cout << i << endl;
    }
};

void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    thread t(my_func);
    thread_guard g(t);
}

int main()
{
    f();
    return 0;
}
