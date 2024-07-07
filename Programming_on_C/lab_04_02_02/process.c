#include <string.h>

#include "process.h"

int split(const char *str, char (*str_arr)[WORD_LEN], size_t *n)
{
    const char *str_ch = &str[0];
    size_t i = 0;
    while (i < MAX_WORDS_IN_STR && *str_ch != '\0')
    {
        size_t j = 0;
        while (j < WORD_LEN - 1 && !strchr(DELIMS, *str_ch) && *str_ch != '\0')
        {
            str_arr[i][j] = *str_ch;
            str_ch++;
            j++;
        }
        str_arr[i][j] = '\0';
        if (j + 1 >= WORD_LEN)
            return ERR_WORD_LEN;
        if (*str_ch == '\0')
        {
            i++;
            break;
        }
        while (strchr(DELIMS, *str_ch) && *str_ch != '\0')
            str_ch++;
        i++;
    }
    *n = i;
    return ERR_OK;
}

int delete_duplicate(char (*str_arr)[WORD_LEN], size_t n)
{
    if (str_arr == NULL)
        return ERR_NULL_PTR;

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            if (strcmp(str_arr[i], str_arr[j]) == 0)
            {
                str_arr[j][0] = '\0';
            }
        }
    }
    return ERR_OK;
}
