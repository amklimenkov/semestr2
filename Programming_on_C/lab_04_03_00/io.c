#include <stdio.h> 
#include <ctype.h>
#include <string.h>

#include "io.h"

int input(char *str1)
{
    char buf[STR_LEN + 1];
    printf("Введите первую строку: ");
    if (!fgets(buf, STR_LEN + 1, stdin))
        return ERR_IO;
    if (strlen(buf) >= STR_LEN)
        return ERR_IO;
        
    strncpy(str1, buf, STR_LEN);
    str1[STR_LEN - 1] = 0;

    if (check_empty_string(str1))
        return ERR_EMPTY_STR;

    char *enter = strrchr(str1, '\n');
    if (enter)
        *enter = 0;

    return ERR_OK;
}

bool check_empty_string(const char *str)
{
    size_t counter = 0;
    for (const char *p = str; *p != '\0'; p++)
    {
        if (ispunct(*p) || isspace(*p))
            counter++;
    }

    if (counter == strlen(str))
        return true;
    
    return false;
}
