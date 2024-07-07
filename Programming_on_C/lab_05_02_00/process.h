#ifndef PROCESS_H__
#define PROCESS_H__

#include <stdio.h>
#include "errors.h"

/// @brief Получает очередное вещественное число из файла
/// @param f - FILE
/// @param number - число из файла
/// @return Код ошибки
int get_next_stud(FILE *f, double *el);

/// @brief Вычисляет среднее арифметическое вещественных чисел в файле. 
/// Допущение параметры перданы корректно.
/// @param f FILE 
/// @param avg - Среднее арифметическое
void calc_average(FILE *f, double *avg);

/// @brief Ищет в файле число с минимальной разницей с средним арифметическим.
/// Допушение параметры переданы корректно. При возможности 2 ответов, выводит 1 встретившееся число.
/// @param f FILE 
/// @param avg - Среднее арифметическое
/// @param number - Число с минимальной разницей с средним арифметическим
void find_number_with_min_diff(FILE *f, double avg, double *number);

#endif
