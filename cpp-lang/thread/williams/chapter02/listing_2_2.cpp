/*
 * Listing 2.2:
 * Waiting for a thread to finish.
 */

#include <iostream>
#include <thread>

struct func
{
    int &i;

    func(int &i_) : i(i_) {}

    void operator()()
    {
        for (size_t i = 0; i < 1000000; ++i)
            std::cout << i << std::endl;
    }
};

void f()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread t(my_func);
    try
    {
        // do something in current thread
    }
    catch(...)
    {
        t.join();
        throw;
    }
    t.join();
}

int main()
{
    f();
    return 0;
}
