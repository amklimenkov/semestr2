#ifndef PROCESS_H__

#define PROCESS_H__


#include <stddef.h>

#include "io.h"

#define BASE 10
#define DIGIT 5

/// @brief Вычленяет последнюю цифру числа
/// @param n - Число
/// @return Последнюю цифру
int last_digit(int n);

/// @brief Ищет максимальное число под побочной диагональю заканчивающееся на 5
/// @param a - Матрица
/// @param n - Кол-во строк
/// @param m - Кол-во столбцов
/// @param max - Максимальное число
/// @return Код ошибки
int find_max_above_side_diagonal(int (*a)[M], size_t n, size_t m, int *max);

#endif
