#ifndef PROCESS_H__

#define PROCESS_H__

#include "errors.h"
#include "io.h" 

#define DELIMS ",;:-.!? "

/// @brief Разделяет строку на слова и записывает их в массив слов
/// @param str строка
/// @param str_arr массив слов
/// @param n размер массива слов
/// @return Код ошибки
int split(const char *str, char (*str_arr)[WORD_LEN], size_t *n);

/// @brief Удаляет дубликаты из массива строк
/// @param str_arr Массив строк
/// @param n - Размер массива строк
/// @return Код ошибки
int delete_duplicate(char (*str_arr)[WORD_LEN], size_t n);

#endif
