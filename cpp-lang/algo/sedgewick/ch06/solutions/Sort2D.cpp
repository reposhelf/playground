#include <iostream>
#include <utility>

template<typename T>
void sort2d(T &arr, std::size_t rows, std::size_t cols)
{
  for (decltype(rows) curr_row = 0; curr_row != rows; ++curr_row)
    {
      for (decltype(cols) curr_col = 0; curr_col != cols; ++curr_col)
	{
          auto min = std::make_pair(curr_row, curr_col);

	  decltype(curr_row) next_row = (curr_col + 1) % cols ? curr_row : curr_row + 1;
	  decltype(curr_col) next_col = (curr_col + 1) % cols;
	  for (; next_row != rows; ++next_row, next_col = 0)
	    {
	      for (; next_col != cols; ++next_col)
		{
		  if (*(*(arr + next_row) + next_col) < *(*(arr + min.first) + min.second))
		    min = std::make_pair(next_row, next_col);
		}
	    }

	  std::swap(*(*(arr + curr_row) + curr_col), *(*(arr + min.first) + min.second));
	}
    }
}

template<typename T>
void print2d(T &arr, std::size_t rows, std::size_t cols)
{
  for (decltype(rows) row = 0; row != rows; ++row)
    {
      for (decltype(cols) col = 0; col != cols; ++col)
        std::cout << *(*(arr + row) + col) << ' ';

      std::cout << std::endl;
    }
}

int main()
{
  const std::size_t rows = 5;
  const std::size_t cols = 5;

  int arr[rows][cols] = {
	{21, 34, 51, 22, 78},
	{65, 74, 23, 74, 12},
	{13, 31, 24, 56, 89},
	{78, 56, 42, 23, 78},
	{99, 44, 37, 38, 39}};

  sort2d(arr, rows, cols);
  print2d(arr, rows, cols);

  return 0;
}
