#include "process.h"

void sum_of_digit(int n, int *summa)
{
    *summa = 0;
    if (n < 0)
        n = -n;
    
    while (n > 0)
    {
        *summa += (n % BASE);
        n /= BASE;
    }
}

int count_odd_sum_digit(const int *a, size_t n)
{
    size_t counter = 0;
    int summa = 0;

    for (size_t i = 0; i < n; i++)
    {
        sum_of_digit(a[i], &summa);
        if (summa % 2 == 1)
        {
            counter++;
        }
    }

    return counter;
}

void fill_row(int *a, size_t n, int filler)
{
    for (size_t i = 0; i < n; i++)
        a[i] = filler;
}

void copy(int *array1, const int *array2, size_t n)
{
    for (size_t i = 0; i < n; i++)
        array1[i] = array2[i];
}

void insert_row(int matrix[][M_MATRIX], size_t *n, size_t m, size_t insert_index, const int *row)
{
    size_t end = *n;
    while (end > insert_index)
    {
        copy(matrix[end], matrix[end - 1], m);
        end--;
    }
    copy(matrix[insert_index], row, m);
    (*n)++;
}

void insert_above_checked_rows(int matrix[][M_MATRIX], size_t *n, size_t m)
{
    int a[M_MATRIX];
    fill_row(a, M_MATRIX, -1);
    for (size_t i = 0; i < *n; i++)
    {
        if (count_odd_sum_digit(matrix[i], m) >= 2)
        {
            insert_row(matrix, n, m, i, a);
            i++;
        }
    }
}
