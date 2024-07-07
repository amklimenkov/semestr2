#include <stdio.h> 
#include <ctype.h>
#include <string.h>

#include "io.h"

int input(char *str1)
{
    char buf[STR_LEN + 1];
    if (!fgets(buf, STR_LEN + 1, stdin))
        return ERR_IO;
    if (strlen(buf) >= STR_LEN)
        return ERR_IO;
        
    strncpy(str1, buf, STR_LEN);
    str1[STR_LEN - 1] = 0;

    char *enter = strrchr(str1, '\n');
    if (enter)
        *enter = 0;

    return ERR_OK;
}
