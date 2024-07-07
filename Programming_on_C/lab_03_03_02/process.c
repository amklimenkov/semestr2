#include "process.h"

void swap(int *a, int *b, size_t n)
{
    int el;
    for (size_t i = 0; i < n; i++)
    {
        el = a[i];
        a[i] = b[i];
        b[i] = el;
    }
}
int product(const int *a, size_t n)
{
    int product = 1;
    for (size_t i = 0; i < n; i++)
        product *= a[i];
    return product;
}
void matrix_sort(int (*a)[M], size_t n, size_t m)
{
    int product1;
    int product2;
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t j = 0; j < n - i - 1; j++)
        {
            product1 = product(a[j], m);
            product2 = product(a[j + 1], m);
            if (product1 > product2)
                swap(a[j], a[j + 1], m);
        }
    }
}
