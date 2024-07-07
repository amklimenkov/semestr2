#ifndef FT_STUD_H__
#define FT_STUD_H__

#include <stdio.h>
#include "stud.h"

/// @brief Получает очередного студента из файла
/// @param f - FILE
/// @param stud - студент из  файла
/// @return Код ошибки
int get_next_stud(FILE *f_txt, struct stud_t *stud);

/// @brief Вывод информации о студентах, фамилия которых начинается с подстроки
/// @param f_src 
/// @param f_dst 
/// @return 
int print_stud_with_sub_in_surname(FILE *f_src, FILE *f_dst, const char *subs);

#endif
