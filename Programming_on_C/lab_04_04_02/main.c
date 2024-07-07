#include <stdio.h>

#include "process.h"

#include "io.h"

int main(void)
{
    char date_arr[MAX_WORDS_IN_STR][WORD_LEN];
    char str[STR_LEN];
    size_t n;
    int rc = ERR_OK;

    rc = input(str);
    if (rc != ERR_OK)
        return rc;
    
    rc = split(date_arr, &n, str);
    if (rc != ERR_OK)
    {
        printf("NO\n");
        return ERR_OK;
    }

    if (n != 3)
    {
        printf("NO\n");
        return ERR_OK;
    }
    
    if (check_date(date_arr) == ERR_OK)
    {
        printf("YES\n");
        return ERR_OK;
    }

    printf("NO\n");
    return ERR_OK;
}
