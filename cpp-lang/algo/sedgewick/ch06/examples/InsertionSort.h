#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

template <typename T> void exch(T &A, T &B)
{
    T temp = A;
    A = B;
    B = temp;
}

template<typename T> void compexch(T &A, T &B)
{
    if (B < A)
        exch(A, B);
}

template<typename T> void insertionSort(T array[], int left, int right)
{
    // move signal (min) item at begining
    for (int i = right; i > left; --i)
        compexch(array[i - 1], array[i]);

    for (int i = left + 2; i <= right; ++i)
    {
        int j = i;
        T curr = array[i];

        while (curr < array[j - 1])
        {
            array[j] = array[j - 1];
            --j;
        }
        array[j] = curr;
    }
}

#endif
