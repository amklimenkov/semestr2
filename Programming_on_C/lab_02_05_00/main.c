#include <stddef.h>
#include <stdio.h>

#define MAX_SIZE 10

#define ERR_OK 0
#define ERR_IO 1
#define ERR_EMPTY_ARR 2
#define ERR_ARR_SIZE 3

/// @brief Принимает от пользователя размер массива
/// @param size - Размер массива
/// @return Код ошибки
int get_arr_size(size_t *size);

/// @brief Принимает массив от пользователя
/// @param ps - Указатель на начало массива
/// @param pe - Указатель на конец массива
/// @return Код ошибки
int get_arr(int *ps, int *pe);

/// @brief Считает max(𝐴[0] + 𝐴[𝑛 − 1], 𝐴[1] + 𝐴[𝑛 − 2], 𝐴[2] + 𝐴[𝑛 − 3], . . . , 𝐴[(𝑛 − 1)/2] + 𝐴[𝑛/2]) в массиве
/// @param a - Массив
/// @param p_end - Указатель на конец массива а
/// @param summa - Максимальная сумма
/// @return Код ошибки
int max_summa(const int *a, const int *p_end, int *summa);

/// @brief Находит максимум из двух целых чисел
/// @param a - Первое число
/// @param b - Второе число
/// @return Число максимума
int max(int a, int b);

int main(void)
{
    size_t size;
    int a[MAX_SIZE], sum;

    int rc = get_arr_size(&size);
    if (rc != ERR_OK)
        return rc;

    int *p_end = a + size;
    rc = get_arr(a, p_end);
    if (rc != ERR_OK)
        return rc;

    rc = max_summa(a, p_end, &sum);
    if (rc != ERR_OK)
        return rc;
    printf("%d", sum);
    return ERR_OK;
}

int get_arr_size(size_t *size)
{
    if (scanf("%zu", size) != 1)
        return ERR_IO;

    if (*size == 0 || *size > MAX_SIZE)
        return ERR_ARR_SIZE;

    return ERR_OK;
}

int get_arr(int *ps, int *pe)
{
    for (int *p_start = ps; p_start < pe; p_start++)
    {
        if (scanf("%d", p_start) != 1)
            return ERR_IO;
    }

    return ERR_OK;
}

int max_summa(const int *a, const int *p_end, int *summa)
{
    *summa = *a + *(p_end - 1);
    a++;
    p_end--;
    for (const int *p_start = a; p_start <= p_end; p_start++, p_end--)
    {
        *summa = max(*summa, *p_start + *(p_end - 1));
    }
    return ERR_OK;
}

int max(int a, int b)
{
    return a > b ? a : b;
}
