#ifndef IO_H__
#define IO_H__

#include <stdio.h>
#include "errors.h"

/// @brief Записывает целые числа из текстового файла в бинарный файл.
/// Допущения параметры переданы корректно, f_txt открыт 
/// на чтение f_bin открыт на бинарную запись
/// @param f_txt Текстовый файл
/// @param f_bin Бинарный файл
/// @return Код ошибки
int text_to_bin(FILE *f_txt, FILE *f_bin);

/// @brief Записывает целые числа из бинарного файла в текстовый.
/// Допущения параметры переданы корректно.f_txt открыт 
/// на запись, f_bin открыт на бинарное чтение
/// @param f_txt Текстовый файл
/// @param f_bin Бинарный файл
/// @return Код ошибки
int bin_to_text(FILE *f_bin, FILE *f_txt);

/// @brief Заполняет бинарный файл случайными целыми числами
/// Допущение f_bin открыт на бинарнуб запись
/// @param f_bin 
/// @param number 
/// @return 
int write_rand_number_in_file(FILE *f_bin, size_t number);

/// @brief Выводит на экран целые числа из бинарного файла
/// Допущения параметры переданы корректно, f_txt открыт 
/// на чтение f_bin открыт на бинарное чтение
/// @param f_bin Бинарный файл
/// @return Код ошибки
int print_bin_file(FILE *f_bin);

/// @brief Проверяет бинарный файл на повреждение данных
/// Допущения параметры переданы корректно. Файл бинарный
/// @param f_bin Файл
/// @return Код ошибки
int check_bin_file(FILE *f_bin);
#endif
