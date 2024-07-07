#include <string.h>

#include "process.h"

int split(char (*word_arr)[WORD_LEN], size_t *n, char *str)
{
    if (word_arr == NULL || n == NULL || str == NULL)
        return ERR_NULL_PTR;

    char *word = strtok(str, DELIMS);
    *n = 0;
    while (word)
    {
        if (strlen(word) >= WORD_LEN)
            return ERR_WORD_LEN;
        
        if (strncpy(word_arr[*n], word, WORD_LEN - 1) == NULL)
            return ERR_COPY;
        
        word_arr[*n][WORD_LEN - 1] = 0;

        (*n)++;

        word = strtok(NULL, DELIMS);
    }

    return ERR_OK;
}
int create_new_str(char (*word_arr)[WORD_LEN], size_t n, char *str_dst)
{
    int rc = ERR_OK;
    char *last_word = word_arr[n - 1];
    str_dst[0] = '\0';
    for (size_t i = n - 1; i <= MAX_WORDS_IN_STR; i--)
    {
        if (strcmp(word_arr[i], last_word) != 0)
        {
            rc = del_first_letter(word_arr[i]);
            if (rc != ERR_OK)
                return rc;
            
            strcat(str_dst, word_arr[i]);
            if (i != 0)
                strcat(str_dst, " ");
        }
    }
    return rc;
}
int del_first_letter(char *str)
{
    if (str == NULL)
        return ERR_NULL_PTR;
    
    char fl = str[0];

    for (size_t i = 1; str[i] != '\0'; i++)
    {
        if (fl == str[i])
        {
            shift(str, i);
            i--;
        }
    }

    return ERR_OK;
}

void shift(char *str, size_t index)
{
    size_t j = index, len = strlen(str);
    while (j < len)
    {
        str[j] = str[j + 1];
        j++;
    }
}
