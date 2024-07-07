#ifndef PROCESS_H__

#define PROCESS_H__

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/// @brief ищет первое вхождение в строку, на которую указывает аргумент s, одного из символов, входящих в строку, на которую указывает аргумент accept.
/// @param s - Строка в которой ведется поиск
/// @param accept - Строка с набором искомых символов
/// @return - Указатель на первый найденный в строке s символ из множества символов строки accept.
/// NULL, если не один символ из троки s не найден в строке accept
const char *my_strpbrk(const char *s, const char *accept);

/// @brief -Определяет максимальную длину начальной подстроки, состоящей исключительно из байтов, перечисленных в accept
/// @param s 
/// @param accept 
/// @return 
size_t my_strspn(const char *s, const char *accept);

/// @brief - Определяет максимальную длину начальной подстроки, состоящей исключительно из байтов, не перечисленных в reject
/// @param s 
/// @param reject 
/// @return 
size_t my_strcspn(const char *s, const char *reject);

/// @brief - Возвращает адрес символа c в строке s, начиная с головы, или NULL, если строка s не содержит символ c
/// @param s 
/// @param c 
/// @return 
const char *my_strchr(const char *s, int c);

/// @brief - Возвращает адрес символа c в строке s, начиная с хвоста, или NULL, если строка s не содержит символ c
/// @param s 
/// @param c 
/// @return 
const char *my_strrchr(const char *s, int c);

/// @brief Проводит модульное тестирование
/// @param  
/// @return кол-во проваленных тестов
size_t test(void);
#endif
