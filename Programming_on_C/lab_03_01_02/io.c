#include <stdio.h>

#include "io.h"
#include "errors.h"

int get_matrix_size(size_t *n, size_t *m)
{
    printf("Введите размеры матрицы n и m: ");
    if (scanf("%zu", n) != 1)
        return ERR_IO;

    if (scanf("%zu", m) != 1)
        return ERR_IO;

    if (*n == 0 || *n > N)
        return ERR_RANGE;

    if (*m == 0 || *m > M)
        return ERR_RANGE;

    return ERR_OK;
}

int get_matrix(int (*a)[M], size_t n, size_t m)
{
    printf("Введите матрицу:\n");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (scanf("%d", &a[i][j]) != 1)
                return ERR_IO;
        }
    }
    return ERR_OK;
}

void print_arr(const int *a, size_t n)
{
    printf("Получившийся массив: ");
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    
    printf("\n");
}
