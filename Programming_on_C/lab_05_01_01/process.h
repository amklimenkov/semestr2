#ifndef PROCESS_H__
#define PROCESS_H__

#include <stdio.h>
#include "errors.h"

/// @brief Находит в файле целых чисел максимум и предмаксимум
/// @param f FILE
/// @param max Максимум
/// @param prev_max Предмаксимум
/// @return Код ошибки
int process(FILE *f, int *max, int *prev_max);

#endif
