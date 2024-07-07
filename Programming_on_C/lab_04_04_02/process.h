#ifndef PROCESS_H__

#define PROCESS_H__

#include <stdlib.h>
#include "io.h" 
#include "errors.h"

#define DELIMS "\t\n\r\v\f "
#define MONTHS_LEN 10
#define MONTHS_COUNT 12

/// @brief Разделяет строку на слова и записывает их в массив слов
/// @param str строка
/// @param el_arr массив слов
/// @param n размер массива слов
/// @return Код ошибки
int split(char (*el_arr)[WORD_LEN], size_t *n, char *str);

/// @brief Проверяет год на валидность
/// @param str_year 
/// @param year 
/// @return Код ошибки
int check_year(const char *str_year, int *year);

/// @brief Проверяет месяц на валидность
/// @param str_month 
/// @param month 
/// @return Код ошибки
int check_month(const char *str_month, int *month);

/// @brief Проверяет день на валидность
/// @param str_day 
/// @param day 
/// @return Код ошибки
int check_day(const char *str_day, int *day);

/// @brief Проверяет дату на валидность
/// @param day 
/// @param month 
/// @param year 
/// @return Код ошибки
int check_valid_date(int day, int month, int year);

/// @brief Проводит тестирование строки даты по всем функциям
/// @param el_arr 
/// @return Код ошибки
int check_date(char (*el_arr)[WORD_LEN]);

/// @brief Приводит строку к верхнему регистру
/// @param str 
void capitalize(char *str);
#endif
