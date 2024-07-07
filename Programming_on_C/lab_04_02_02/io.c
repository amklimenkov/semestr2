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

int print_result(char (*arr_words1)[WORD_LEN], size_t n1, char (*arr_words2)[WORD_LEN], size_t n2)
{
    if (arr_words2 == NULL || arr_words1 == NULL)
        return ERR_NULL_PTR;

    printf("Result: \n");
    for (size_t i = 0; i < n1; i++)
    {
        bool equal = 0;
        if (arr_words1[i][0] == '\0')
            continue;
        for (size_t j = 0; j < n2; j++)
        {
            if (strcmp(arr_words1[i], arr_words2[j]) == 0)
            {
                printf("%s yes\n", arr_words1[i]);
                equal = 1;
                break;
            }
        }
        if (equal == 0)
            printf("%s no\n", arr_words1[i]); 
    }
    return ERR_OK;
}
