/*
 * Listing 4.9 Running code on a thread using std::packaged_task
 */

#include <deque>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <utility>

// global variables
bool tasks_done = false;
std::deque<std::packaged_task<int()>> tasks;
std::mutex mtx;

/*
 * Returns unique number after each call.
 * Additional does some work.
 * This function will be run on a separate thread
 * and wrapped in std::packaged_task to get result
 * in a future.
 */
int get_unique()
{
    static int n = 0;
    for (int i = 0; i != 100000000; ++i) {}
    return ++n;
}

/*
 * This function will be run on separate thread and receive
 * tasks from queue then run each of them.
 */
void tasks_runner()
{
    while (!tasks_done) {
        std::packaged_task<int()> task;
        {
            std::lock_guard<std::mutex> locker(mtx);
            if (tasks.empty())
                continue;
            task = std::move(tasks.front());
            tasks.pop_front();
        }
        task();
    }
}

template <typename Func>
std::future<int> post_task(Func f)
{
    std::packaged_task<int()> task(f);
    std::future<int> res = task.get_future();
    std::lock_guard<std::mutex> locker(mtx);
    tasks.push_back(std::move(task));
    return res;
}

int main()
{
    std::vector<std::future<int>> results;
    // post first five tasks
    for (int i = 0; i != 5; ++i) {
        std::future<int> res = post_task(get_unique);
        results.push_back(std::move(res));
    }

    // run tasks_runner on separate thread
    std::thread tasks_thread(tasks_runner);
    tasks_thread.detach();

    // post next five tasks
    for (int i = 0; i != 5; ++i) {
        std::future<int> res = post_task(get_unique);
        results.push_back(std::move(res));
    }

    // show results
    for (auto &result : results) {
        result.wait();
        std::cout << result.get() << std::endl;
    }

    tasks_done = true;

    return 0;
}
