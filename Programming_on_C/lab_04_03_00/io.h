#ifndef IO_H__

#define IO_H__



#include <stdbool.h>

#include "errors.h"

#define STR_LEN (256 + 1)
#define WORD_LEN (16 + 1)
#define MAX_WORDS_IN_STR ((STR_LEN - 1) / WORD_LEN)

/// @brief Принимает у пользователя строку с словами
/// @param str1 - Строка 1
/// @return Код ошибки
int input(char *str1);

/// @brief Проверяет не состоит ли строкаиз знаков пуктуации и пробелов
/// @param str 
/// @return Пустая строка - true, иначе false
bool check_empty_string(const char *str);
#endif
