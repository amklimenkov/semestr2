#ifndef PROCESS_H__

#define PROCESS_H__

#include <stddef.h>

#include "io.h"

#define BASE 10

/// @brief Считает сумму цифр числа
/// @param n - Число
/// @param summa - Сумма
void sum_of_digit(int n, int *summa);

/// @brief Считает кол-во элементов в массиве, сумма цифр которого нечетна
/// @param a - Массив
/// @param n - Размер массива
/// @return Кол-во элементов в массиве, сумма цифр которого нечетна
int count_odd_sum_digit(const int *a, size_t n);

/// @brief Меняет элементы массива на -1
/// @param a - Массив
/// @param n - Размер массива
/// @param filler - Элемент заполнения
void fill_row(int *a, size_t n, int filler);

/// @brief Меняет элементы 1 массива на элементы 2 массива
/// @param array1 - 1 массив
/// @param array2 - 2 массив
/// @param n - Размерности массива
void copy(int *array1, const int *array2, size_t n);

// /// @brief Вставляет строку в матрицу по индексу
// /// @param matrix - Матрица
// /// @param n - Количество строк
// /// @param m - Количество столбцов
// /// @param insert_index - Индекс вставки
// void insert_row(int matrix[][M_MATRIX], size_t *n, size_t m, size_t insert_index);

/// @brief Проверяет строки матрицы на наличие 2 элем. сумма цифр которых нечетна
/// и вставляет перед ними строку -1
/// @param matrix - Матрица
/// @param n - Количество строк
/// @param m - Количество столбцов
void insert_above_checked_rows(int matrix[][M_MATRIX], size_t  *n, size_t m);

/// @brief Вставляет строку в матрицу по индексу
/// @param matrix - Матрица
/// @param n - Количество строк
/// @param m - Количество столбцов
/// @param insert_index - Индекс вставки
/// @param row - Вставляемая строка
void insert_row(int matrix[][M_MATRIX], size_t *n, size_t m, size_t insert_index, const int *row);
#endif
