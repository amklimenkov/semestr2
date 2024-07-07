#ifndef PROCESS_H__

#define PROCESS_H__

#include <stddef.h>

#include "io.h"

/// @brief Заполняет матрицу "ходом быка" с конца, 
/// чтобы минимальное число было в правом нижнем углу
/// @param a - Матрица
/// @param n - Количество строк в матрице
/// @param m  - Количество столбцов в матрице
void fill_matrix(int (*a)[M], size_t n, size_t m);

#endif
