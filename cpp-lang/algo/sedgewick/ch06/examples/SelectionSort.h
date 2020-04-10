#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <utility>

template<typename T> void selectionSort(T array[], int left, int right)
{
    for (int i = left; i < right; ++i)
    {
        int min = i;

        for (int j = i + 1; j <= right; ++j)
        {
            if (array[j] < array[min])
                min = j;
        }

        std::swap(array[i], array[min]);
    }
}

#endif
