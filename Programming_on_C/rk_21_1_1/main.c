#include <stdio.h>
#include <stdlib.h>

#define ERR_OK 0 
#define ERR_IO 1
#define ERR_ANS 2

#define BASE 10

/// @brief Находит индекс с конца максимальной цифры в числе
/// @param n - число
/// @param index_max - указатель на индекс максимального числа
/// @return Код ошибки
int find_max_digit_index(int n, int *index_max);

/// @brief Находит индекс с конца минимальной цифры в числе
/// @param n - число
/// @param index_min - указатель на индекс минимального числа
/// @return Код ошибки
int find_min_digit_index(int n, int *index_min);

/// @brief Считает длину числа
/// @param n - число
/// @return длина n
size_t num_len(int n);

int main(void)
{
    int n, index_max = -1, index_min = -1;
    int rc;

    if (scanf("%d", &n) != 1)
        return ERR_IO;
    
    if (num_len(n) <= 1)
        return ERR_ANS;

    rc = find_max_digit_index(n, &index_max);
    if (rc != ERR_OK)
        return rc;
    
    rc = find_min_digit_index(n, &index_min);
    if (rc != ERR_OK)
        return rc;

    if (index_max > index_min)
        printf("max min");
    else if (index_max == index_min)
        return ERR_ANS;
    else
        printf("min max");

    return ERR_OK;
}

int find_max_digit_index(int n, int *index_max)
{
    int x = abs(n);
    int max_digit = x % BASE;
    int digit = x % BASE;
    x /= BASE;
    int k = 0;
    *index_max = k;
    k++;
    while (x > 0)
    {
        digit = x % BASE;
        if (digit > max_digit)
        {
            *index_max = k;
            max_digit = digit;
        }
        x /= BASE;
        k++;
    }
    return ERR_OK;
}

int find_min_digit_index(int n, int *index_min)
{
    int x = abs(n);

    int min_digit = x % BASE;
    int digit = x % BASE;
    x /= BASE;
    int k = 0;
    *index_min = 0;
    k++;
    while (x > 0)
    {
        digit = x % BASE;
        if (digit < min_digit)
        {
            *index_min = k;
            min_digit = digit;

        }
        x /= BASE;
        k++;
    }
    return ERR_OK;
}

size_t num_len(int n)
{
    int x = abs(n);
    size_t len = 1;
    x /= BASE;
    while (x > 0)
    {
        len++;
        x /= BASE;
    }
    return len;
}