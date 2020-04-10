/*
 * Exercise 10.21:
 * Write a lambda that captures a local int variable and decrements that variable
 * until it reaches 0. Once the variable is 0 additional calls should no longer
 * decrement the variable. The lambda should return a bool that indicates whether
 * the captured variable is 0.
 */

#include <iostream>

int main()
{
    int local = -33;
    auto f = [local] () mutable -> bool {
        if (!local)
            return true;
        local = local < 0 ? -local : local;
        while (local)
            --local;
        return false;
    };

    std::cout << f() << std::endl;

    return 0;
}