#ifndef BUBBLESORT_H
#define BUBBLESORT_H

template<typename T> void bubbleSort(T a[], int l, int r)
{
  for (int i = l; i < r; ++i)
    {
      for (int j = r; i < j; --j)
	{
	  if (a[j] < a[j - 1])
	    {
	      T tmp = a[j];
	      a[j] = a[j - 1];
	      a[j - 1] = tmp;
	    }
	}
    }
}

#endif
