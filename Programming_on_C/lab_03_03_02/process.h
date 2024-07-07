#ifndef PROCESS_H__

#define PROCESS_H__

#include <stddef.h>

#include "io.h"

/// @brief Меняет элементы одного массива на элементы другого
/// @param a - Первый массив
/// @param b - Второй массив
/// @param n - Размерность массивов
void swap(int *a, int *b, size_t n);

/// @brief Считает произведение элементов массива
/// @param a - Массив
/// @param n - Размер массива
/// @return Произведение
int product(const int *a, size_t n);

/// @brief Сортирует строки не пустой матрицы по возврастанию произведения их элементов
/// @param a - Матрица
/// @param n - Кол-во строк
/// @param m - Кол-во столбцов
void matrix_sort(int (*a)[M], size_t n, size_t m);
#endif
