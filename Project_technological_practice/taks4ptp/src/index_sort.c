#include "sort.h"

void insertion_sort(int *a, size_t size)
{
    int j;
    for (size_t i = 1; i < size; i++)
    {
        int el = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > el)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = el;
    }
}

