#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define BASE 10

#define ERR_OK 0
#define ERR_SIZE 1
#define ERR_INPUT 2
#define ERR_EMPTY_ARR 3

/// @brief Принимает размер массива от пользователя
/// @param size - Размер массива
/// @return Код ошибки
int get_arr_size(size_t *size);

/// @brief Принимает от пользователя массив длиной size
/// @param a - Пользовательский массив
/// @param size - Размер массива
/// @return Код ошибки
int get_arr(int *a, size_t size);

/// @brief Выводит на экран массив
/// @param a - Массив
/// @param size - Размер массива
void print_arr(const int *a, size_t size);

/// @brief Проверяет заканчивается ли и начинается ли число на одну цифру
/// @param element - число для проверки
/// @return true, если цифры начала и конца совпадают, иначе false
bool check_start_finish_digit(int element);

/// @brief На основе массива формирует новый массив,
///         в котором сначала идут числа с совпадающими цифрами начала и конца
/// @param curr_arr - Начальный массив
/// @param size_curr_arr - Размер начального массива
/// @param new_arr - Новый массив
/// @param size_new_arr - Указатель на размер нового массива
/// @return Код ошибки
int form_new_arr(const int *curr_arr, size_t size_curr_arr, int *new_arr, size_t *size_new_arr);

int main(void)
{
    size_t size, size_new;
    int a[MAX_SIZE];
    int new_a[MAX_SIZE];

    int rc = get_arr_size(&size);
    if (rc != ERR_OK)
        return rc;

    rc = get_arr(a, size);
    if (rc != ERR_OK)
        return rc;

    rc = form_new_arr(a, size, new_a, &size_new);
    if (rc != ERR_OK)
        return rc;

    if (size_new == 0)
        return ERR_EMPTY_ARR;

    print_arr(new_a, size_new);
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

bool check_start_finish_digit(int element)
{
    element = abs(element);
    int last_digit = element % BASE;

    while (element >= 10)
        element /= BASE;

    int first_digit = element;

    if (first_digit == last_digit)
        return true;
    else
        return false;
}

int form_new_arr(const int *curr_arr, size_t size_curr_arr, int *new_arr, size_t *size_new_arr)
{
    size_t new_arr_index = 0;
    for (size_t i = 0; i < size_curr_arr; i++)
    {
        if (check_start_finish_digit(curr_arr[i]))
        {
            new_arr[new_arr_index] = curr_arr[i];
            new_arr_index++;
        }
    }

    *size_new_arr = new_arr_index;

    return ERR_OK;
}
