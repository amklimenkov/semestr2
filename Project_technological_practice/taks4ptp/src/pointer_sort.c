#include "sort.h"

void insertion_sort(int *a, size_t size)
{
    int *j;
    for (int *i = a + 1; i < a + size; i++)
    {
        int el = *i;
        j = i - 1;
        while (j >= a && *j > el)
        {
            *(j + 1) = *j;
            j--;
        }
        *(j + 1) = el;
    }
}
