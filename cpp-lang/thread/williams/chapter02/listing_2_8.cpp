/*
 * Listing 2.8.
 * A naive parallel version of std::accumulate
 */

#include <numeric>
#include <algorithm>
#include <iterator>
#include <thread>
#include <vector>
#include <functional>
#include <iostream>

template<typename Iterator, typename T>
struct accumulate_block
{
  void operator()(Iterator first, Iterator last, T &result)
  {
    result = std::accumulate(first, last, result);
  }
};

template<typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init)
{
  const unsigned long length = std::distance(first, last);

  if (!length)
    return init;

  const unsigned long min_per_thread = 25;
  const unsigned long max_threads =
    (length + min_per_thread - 1) / min_per_thread;

  const unsigned long hardware_threads = std::thread::hardware_concurrency();

  const unsigned long num_threads =
    std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);

  const unsigned long block_size = length / num_threads;

  std::vector<T> results(num_threads);
  std::vector<std::thread> threads(num_threads - 1);

  Iterator block_start = first;
  for (unsigned long i = 0; i != (num_threads - 1); ++i)
    {
      Iterator block_end = block_start;
      std::advance(block_end, block_size);
      threads[i] = std::thread(accumulate_block<Iterator, T>(),
			       block_start, block_end,
			       std::ref(results[i]));
      block_start = block_end;
    }
  accumulate_block<Iterator, T>()(block_start, last, results[num_threads - 1]);

  std::for_each(threads.begin(), threads.end(),
		std::mem_fn(&std::thread::join));

  return std::accumulate(results.begin(), results.end(), init);
}

int main()
{
  std::vector<int> vec = {11, 42, 81, 49, 15, 12, 45, 89, 55, 23, 45, 56, 89,
			  78, 55, 56, 79, 36, 62, 54, 21, 44, 87, 89, 35, 97,
			  76, 55, 42, 12, 13, 54, 64, 61, 26, 34, 79, 64, 78,
			  76, 42, 54, 31, 64, 10, 12, 78, 97, 96, 98, 94, 45,
			  96, 32, 42, 75, 61, 24, 35, 64, 78, 59, 84, 54, 24,};

  std::cout << "std::accumulate: ";
  std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;

  std::cout << "parallel_accumulate: ";
  std::cout << parallel_accumulate(vec.begin(), vec.end(), 0) << std::endl;
  
  return 0;
}
