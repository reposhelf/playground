/*
 * Listing 2.1
 * A function that returns while a thread still has access to local variables.
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

void oops()
{
    int some_local_state = 0;
    func my_func(some_local_state);
    std::thread my_thread(my_func);
    my_thread.detach();
}

int main()
{
    oops();
    return 0;
}
