#ifndef PROCESS_H__

#define PROCESS_H__

#include "io.h" 
#include "errors.h"

#define DELIMS ",;:-.!? "

/// @brief Разделяет строку на слова и записывает их в массив слов
/// @param str строка
/// @param word_arr массив слов
/// @param n размер массива слов
/// @return Код ошибки
int split(char (*word_arr)[WORD_LEN], size_t *n, char *str);

/// @brief Формирует строку из массива строк без последнего слова
/// и в словах нет первой буквы
/// @param word_arr массив слов
/// @param n размер массива слов
/// @param str_dst результирующая строка
/// @return Код ошибки
int create_new_str(char (*word_arr)[WORD_LEN], size_t n, char *str_dst);

/// @brief Удаляет первую букву из строки
/// @param str строка
/// @return Код ошибки
int del_first_letter(char *str);

/// @brief Удаляет букву из строки по индексу
/// @param str 
/// @param index 
void shift(char *str, size_t index);

#endif
