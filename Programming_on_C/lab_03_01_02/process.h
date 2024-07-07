#ifndef PROCESS_H__

#define PROCESS_H__

#include <stdbool.h>
#include <stddef.h>

#include "io.h"

/// @brief Чередуется ли знак в столбце
/// @param a - Матрица
/// @param n - Кол-во строк
/// @param column - Столбец на проверку
/// @return true, если чередуется, иначе false
bool is_column_alternates(int (*a)[M], size_t n, size_t column);

/// @brief Заполняет массив столбцов, если чередуется колонка
/// @param a - Массив
/// @param a_n - Размер массива
/// @param matrix - Матрица
/// @param m_n - Кол-во строк
/// @param m_m - Кол-во столбцов
void fill_col_arr(int *a, size_t a_n, int (*matrix)[M], size_t m_n, size_t m_m);
#endif
