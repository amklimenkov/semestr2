#ifndef PROCESS_H__

#define PROCESS_H__

#include <stdbool.h>
#include <stddef.h>

#include "io.h"

/// @brief Проверяет простое ли число
/// @param n - Число
/// @return true, если простое, иначе false
bool is_prime(int n);

/// @brief Заполняет массив простыми числами из матрицы
/// @param a - Массив
/// @param n - Размер массива
/// @param matrix - Матрица
/// @param m_n - Количество строк в матрице
/// @param m_m - Количество столбцов в матрице
/// @return Код ошибки
int fill_prime_arr(int *a, size_t *n, int (*matrix)[M], size_t m_n, size_t m_m);

/// @brief Инвертирует массив
/// @param a - Массив
/// @param n - Размер массива
void reverse_arr(int *a, size_t n);

/// @brief Записывает массив простых чисел в матрицу, вместо простых чисел
/// @param a - Массив
/// @param n - Размер массива
/// @param matrix - Матрица
/// @param m_n - Количество строк
/// @param m_m - Количество столбцов
/// @return Код ошибки
int insert_arr_to_matrix(const int *a, size_t n, int (*matrix)[M], size_t m_n, size_t m_m);
#endif
