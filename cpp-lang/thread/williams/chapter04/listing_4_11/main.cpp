/*
 * Listing 4.11. Waiting for a condition variable with a timeout.
 */
#include <chrono>
#include <condition_variable>
#include <mutex>

std::condition_variable cond_var;
std::mutex mtx;

int main()
{
    const auto timeout = std::chrono::steady_clock::now()
            + std::chrono::milliseconds(5000);

    std::unique_lock<std::mutex> lk(mtx);
    while (true) {
        if (cond_var.wait_until(lk, timeout) == std::cv_status::timeout)
            break;
    }
    return 0;
}
