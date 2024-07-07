#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#define MAX_SIZE 10

#define ERR_OK 0
#define ERR_SIZE 1
#define ERR_INPUT 2
#define ERR_EMPTY_ARR 3

/// @brief Принимает размер массива от пользователя
/// @param size - Размер массива
/// @return Код ошибки
int get_arr_size(size_t *size);

/// @brief Принимает от пользователя массив
/// @param a - Массив
/// @param size - Длина массива
/// @return Код ошибки
int get_arr(int *a, size_t size);

/// @brief Выводит на экран массив
/// @param a - Массив
/// @param size - Длина массива
void print_arr(const int *a, size_t size);

/// @brief Удаляет из массива элементы, которые являются полными квадратами
/// @param a - Массив
/// @param size - Размер массива
/// @return Код ошибки
int delete_square(int *a, size_t *size);

/// @brief Вычисляет является ли число полным квадратом
/// @param number - Число на проверку
/// @return true, если является, иначе false
bool is_square(int number);

int main(void)
{
    size_t size;
    int a[MAX_SIZE];

    int rc = get_arr_size(&size);
    if (rc != ERR_OK)
        return rc;

    rc = get_arr(a, size);
    if (rc != ERR_OK)
        return rc;

    rc = delete_square(a, &size);
    if (rc != ERR_OK)
        return rc;

    if (size == 0)
        return ERR_EMPTY_ARR;
    print_arr(a, size);
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

void print_arr(const int *a, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
}

int delete_square(int *a, size_t *size)
{
    size_t j = 0;

    for (size_t i = 0; i < *size; i++)
    {
        if (!is_square(a[i]))
        {
            a[j] = a[i];
            j++;
        }
    }
    *size = j;

    return ERR_OK;
}

bool is_square(int number)
{
    if (number <= 0)
        return false;

    for (int i = 0; i * i <= number; i++)
    {
        if (number == i * i)
            return true;
    }
    return false;
}
