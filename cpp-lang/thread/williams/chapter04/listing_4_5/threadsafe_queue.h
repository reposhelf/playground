/*
 * Listing 4.5. Full class definition for a thread-safe queue using condition variables
 */

#ifndef THREADSAFE_QUEUE_H
#define THREADSAFE_QUEUE_H

#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>

template<typename T>
class ThreadSafeQueue
{
public:
    ThreadSafeQueue()
    {
    }
    ThreadSafeQueue(const ThreadSafeQueue &other)
    {
        std::lock_guard<std::mutex> lg(other.mut_);
        data_queue_ = other.data_queue_;
    }
    ThreadSafeQueue &operator=(const ThreadSafeQueue&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lg(mut_);
        data_queue_.push(new_value);
        data_cond_.notify_one();
    }
    void wait_and_pop(T &value)
    {
        std::unique_lock<std::mutex> ul(mut_);
        data_cond_.wait(ul, [this]{return !data_queue_.empty();});
        value = data_queue_.front();
        data_queue_.pop();
    }
    std::shared_ptr<T> wait_and_pop()
    {
        std::unique_lock<std::mutex> ul(mut_);
        data_cond_.wait(ul, [this]{return !data_queue_.empty();});
        std::shared_ptr<T> res(std::make_shared<T>(data_queue_.front()));
        data_queue_.pop();
        return res;
    }
    bool try_pop(T &value)
    {
        std::lock_guard<std::mutex> lg(mut_);
        if (data_queue_.empty())
            return false;
        value = data_queue_.front();
        data_queue_.pop();
        return true;
    }
    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> lg(mut_);
        if (data_queue_.empty())
            return std::shared_ptr<T>();
        std::shared_ptr<T> res(std::make_shared<T>(data_queue_.front()));
        data_queue_.pop();
        return res;
    }
    bool empty() const
    {
        std::lock_guard<std::mutex> lg(mut_);
        return data_queue_.empty();
    }

private:
    mutable std::mutex mut_;
    std::queue<T> data_queue_;
    std::condition_variable data_cond_;
};

#endif // THREADSAFE_QUEUE_H
