/*
 * Listing 3.5
 * A fleshed-out class definition for a thread-safe stack.
 */

#include <exception>
#include <memory>
#include <mutex>
#include <stack>

struct empty_stack : std::exception
{
	const char *what() const throw();
};

template<typename T>
class threadsafe_stack
{
private:
	std::stack<T> _data;
	mutable std::mutex _m;

public:
	threadsafe_stack() = default;
	threadsafe_stack(const threadsafe_stack &other)
	{
		std::lock_guard<std::mutex> lock(other._m);
		_data = other._data;
	}
	threadsafe_stack &operator=(const threadsafe_stack&) = delete;

	void push(const T &new_value)
	{
		std::lock_guard<std::mutex> lock(_m);
		_data.push(new_value);
	}

	std::shared_ptr<T> pop()
	{
		std::lock_guard<std::mutex> lock(_m);
		if (_data.empty())
			throw empty_stack();

		const std::shared_ptr<T> ret(std::make_shared<T>(_data.top()));
		_data.pop();
		return ret;
	}

	void pop(T &value)
	{
		std::lock_guard<std::mutex> lock(_m);
		if (_data.empty())
			throw empty_stack();

		value = _data.top();
		_data.pop();
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lock(_m);
		return _data.empty();
	}
};

int main()
{
	return 0;
}