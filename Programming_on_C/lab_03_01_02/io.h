#ifndef IO_H__

#define IO_H__

#include <stddef.h>

#include "errors.h"

#define N 10
#define M 10


/// @brief Принимает размеры матрицы от пользователя
/// @param n - Количество строк
/// @param m - Количество столбцов
/// @return Код ошибки
int get_matrix_size(size_t *n, size_t *m);

/// @brief Принимает матрицу от пользователя
/// @param a - Матрица
/// @param n - Количество строк
/// @param m - Количество столбцов
/// @return Код ошибки
int get_matrix(int (*a)[M], size_t n, size_t m);

/// @brief Выводит массив на экран
/// @param a - Массив
/// @param n - Размер массива
void print_arr(const int *a, size_t n);

#endif
