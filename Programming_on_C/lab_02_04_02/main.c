#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define MAX_SIZE 10

#define OK 0
#define ERR_IO 1
#define ERR_OVERFLOW 100
#define ERR_NULL_POINTER 2

/// @brief Принимает массив по концевому признаку
/// @param a - Массив
/// @param size - Размер массива
/// @return Код ошибки
int get_arr(int *a, size_t *size);

/// @brief Реализиции сортировки вставками
/// @param a - Массив
/// @param size - Размер массива
void insertion_sort(int *a, size_t size);

/// @brief Выводит на экран массив
/// @param a - Массив
/// @param size - Размер
void print_arr(const int *a, size_t size);

int main(void)
{
    int a[MAX_SIZE];
    size_t size;

    int rc = get_arr(a, &size);
    if (rc == ERR_IO)
        return rc;

    insertion_sort(a, size);

    print_arr(a, size);

    return rc;
}

int get_arr(int *a, size_t *size)
{
    size_t i = 0;
    int rc = OK;

    while (i < MAX_SIZE && scanf("%d", &a[i]) == 1)
        i++;

    *size = i;

    if (*size == 0)
        rc = ERR_IO;
    if (*size >= MAX_SIZE)
        rc = ERR_OVERFLOW;
    return rc;
}

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

void print_arr(const int *a, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}
