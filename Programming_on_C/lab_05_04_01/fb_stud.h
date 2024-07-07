#ifndef FB_STUD_H__
#define FB_STUD_H__

#include <stdio.h>
#include "stud.h"
#include "errors.h"

/// @brief Читает структуру студента в указанной позиции с начала файла
/// Допущения параметры переданы корректно, f_bin открыт на бинарное чтение
/// @param f_bin Файл
/// @param pos Позиция
/// @param number Считанное число
/// @return Код ошибки
int get_stud_by_pos(FILE *f_bin, long pos, struct stud_t *stud);

/// @brief Записывает структуру студента в указанную позицию с затирание.
/// Допущения параметры переданы корректно, f_bin открыт на бинарное чтение
/// @param f_bin Файл
/// @param pos Позиция
/// @param number Число
/// @return Код ошибки
int put_stud_by_pos(FILE *f_bin, long pos, const struct stud_t *stud);

/// @brief Сортирует структуры студентов в бинарном файле по фамилии, 
/// если фам. совп., то по имени
/// Допущения параметры переданы корректно, f_bin открыт на бинарное чтение
/// @param f_bin Файл
/// @return Код ошибки
int sort_stud_in_bin_file(FILE *f_bin);

/// @brief Объединяет фамилию и имя студента в одну строку
/// Допущение строка full_name имеет размер SURNAME_LEN + LASTNAME_LEN - 1
/// @param full_name - Строка с фамилией и именем
/// @param stud - Студент
/// @return Код ошибки
int get_full_name(char *full_name, const struct stud_t *stud);

#endif
