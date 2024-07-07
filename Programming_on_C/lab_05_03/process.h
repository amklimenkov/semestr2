#ifndef PROCESS_H__
#define PROCESS_H__

#include <stdio.h>
#include "errors.h"

/// @brief Читает число в указанной позиции с начала файла
/// Допущения параметры переданы корректно, f_bin открыт на бинарное чтение
/// @param f_bin Файл
/// @param pos Позиция
/// @param number Считанное число
/// @return Код ошибки
int get_number_by_pos(FILE *f_bin, long pos, int *number);

/// @brief Записывает число в указанную позицию с затирание.
/// Допущения параметры переданы корректно, f_bin открыт на бинарное чтение
/// @param f_bin Файл
/// @param pos Позиция
/// @param number Число
/// @return Код ошибки
int put_number_by_pos(FILE *f_bin, long pos, int number);

/// @brief Сортирует целые числа в бинарном файле в порядке возврастания
/// Допущения параметры переданы корректно, f_bin открыт на бинарное чтение
/// @param f_bin Файл
/// @return Код ошибки
int sort_number_in_bin_file(FILE *f_bin);

#endif
