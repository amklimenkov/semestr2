#ifndef IO_H__

#define IO_H__

#include <stdio.h>
#include "errors.h"

/// @brief Получает очередное целое число из файла
/// @param f - FILE
/// @param number - число из файла
/// @return Код ошибки
int get_next_number(FILE *f, int *number);

#endif
