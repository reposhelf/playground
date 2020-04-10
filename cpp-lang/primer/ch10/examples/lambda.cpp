#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

void fcn1()
{
    size_t v1 = 42;
    auto f = [v1] { return v1; };
    v1 = 0;
    auto j = f();
    std::cout << j << std::endl;
}

void fcn2()
{
    size_t v1 = 42;
    auto f = [&v1] { return v1; };
    v1 = 0;
    auto j = f();
    std::cout << j << std::endl;
}

void fcn3()
{
    size_t v1 = 42;
    auto f = [v1] () mutable { return ++v1; };
    v1 = 0;
    auto j = f();
    std::cout << j << std::endl;
}

void fcn4()
{
    size_t v1 = 42;
    auto f = [&v1] { return ++v1; };
    v1 = 0;
    auto j = f();
    std::cout << j << std::endl;
}

void fcn5()
{
    size_t v1 = 42;
    size_t *const p = &v1;
    auto f = [p] { return ++*p; };
    auto j = f();
    std::cout << v1 << " " << j << std::endl;
    v1 = 0;
    j = f();
    std::cout << v1 << " " << j << std::endl;
}

int main()
{
    fcn1();
    fcn2();
    fcn3();
    fcn4();
    fcn5();
    return 0;
}