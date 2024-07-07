#ifndef IO_H__

#define IO_H__


#include <stdbool.h>

#include "errors.h"

#define STR_LEN (256 + 1)
#define WORD_LEN (16 + 1)  
#define MAX_WORDS_IN_STR ((STR_LEN - 1) / WORD_LEN)

/// @brief Принимает у пользователя 2 строки с словами
/// @param str1 - Строка 1
/// @param str2 - Строка 2
/// @return Код ошибки
int input(char *str1);

/// @brief Проверяет не состоит ли строкаиз знаков пуктуации и пробелов
/// @param str 
/// @return Пустая строка - true, иначе false
bool check_empty_string(const char *str);

/// @brief Делает вывод содержится ли слово из строки 1 во 2 строке и выводит на экран результат
/// @param arr_words1 - Строка 1
/// @param n1 - размер строки 1
/// @param arr_words2 строка 2
/// @param n2  размер строки 2
/// @return Код ошибки
int print_result(char (*arr_words1)[WORD_LEN], size_t n1, char (*arr_words2)[WORD_LEN], size_t n2);
#endif
