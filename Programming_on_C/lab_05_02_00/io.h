#ifndef IO_H__
#define IO_H__

#include <stdio.h>
#include "errors.h"

/// @brief Проверяет содержит ли файл вещественные числа
/// @param f 
/// @return Код ошибки
int is_file_contain_double(FILE *f);

#endif
