#include <stddef.h>
#include <stdio.h>

#define MAX_SIZE 10

#define ERR_OK 0
#define ERR_NO_NEG_EL 1
#define ERR_SIZE 2
#define ERR_INPUT 3

/// @brief Принимает размер массива от пользователя
/// @param size - Размер массива
/// @return Код ошибки
int get_arr_size(size_t *size);

/// @brief Принимает от пользователя массив длиной size
/// @param a - Пользовательский массив
/// @param size - Размер массива
/// @return Код ошибки
int get_arr(int *a, size_t size);

/// @brief Считает значение среднего арифметического отрицательных элементов массива.
/// Записывает результат в переменную
/// @param a - Массив a
/// @param size - Размер массива a
/// @param res - Переменная среднего арифметического отрицательных элементов
/// @return Код ошибки
int neg_elem_average(const int *a, size_t size, double *res);

int main(void)
{
    size_t size;
    double neg_average;
    int a[MAX_SIZE];

    int rc = get_arr_size(&size);
    if (rc != ERR_OK)
        return rc;

    rc = get_arr(a, size);
    if (rc != ERR_OK)
        return rc;

    rc = neg_elem_average(a, size, &neg_average);
    if (rc != ERR_OK)
        return rc;

    printf("%f", neg_average);

    return ERR_OK;
}

int get_arr_size(size_t *size)
{
    printf("Введите количество вводимых элементов массива: ");
    if (scanf("%zu", size) != 1)
        return ERR_INPUT;

    if (*size > MAX_SIZE || *size == 0)
        return ERR_SIZE;

    return ERR_OK;
}

int get_arr(int *a, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (scanf("%d", &a[i]) != 1)
            return ERR_INPUT;
    }

    return ERR_OK;
}

int neg_elem_average(const int *a, size_t size, double *res)
{
    size_t count_neg_el = 0;
    int summa = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            summa += a[i];
            count_neg_el++;
        }
    }

    if (count_neg_el == 0)
    {
        return ERR_NO_NEG_EL;
    }

    *res = summa / (double)count_neg_el;
    return ERR_OK;
}
