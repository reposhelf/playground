#include <iostream>
#include <thread>

void hello()
{
    std::cout << "Hello, threds!" << std::endl;
}

int main()
{
    std::thread t(hello);

    t.join();

    return 0;
}