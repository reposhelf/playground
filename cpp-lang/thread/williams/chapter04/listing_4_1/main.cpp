/*
 * Listing 4.1. Waiting a data with std::condition_variable
 */
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>

struct data_chunk
{
};

data_chunk prepare_data()
{
    return data_chunk();
}

bool more_data_to_prepare()
{
    return true;
}

bool is_last_chank(const data_chunk&)
{
    return false;
}

void process(data_chunk&)
{
}

std::mutex mut;
std::queue<data_chunk> data_queue;
std::condition_variable data_cond;

void data_preparation_thread()
{
    while (more_data_to_prepare())
    {
        const data_chunk data = prepare_data();
        std::lock_guard<std::mutex> lg(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
}

void data_processing_thread()
{
    while (true)
    {
        std::unique_lock<std::mutex> ul(mut);
        data_cond.wait(ul, [](){return !data_queue.empty();});
        data_chunk data = data_queue.front();
        data_queue.pop();
        ul.unlock();
        process(data);
        if (is_last_chank(data))
            break;
    }
}

int main()
{
    return 0;
}
