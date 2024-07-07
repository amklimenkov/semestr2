#include <stdio.h>
#include <string.h>

#include "process.h"
#include "io.h"

int main(void)
{
    char word_arr[MAX_WORDS_IN_STR][WORD_LEN];
    char str[STR_LEN];
    char new_str[STR_LEN];
    size_t n;
    int rc = ERR_OK;

    rc = input(str);
    if (rc != ERR_OK)
        return rc;
    
    rc = split(word_arr, &n, str);
    if (rc != ERR_OK)
        return rc;

    rc = create_new_str(word_arr, n, new_str);
    if (rc != ERR_OK)
        return rc;

    if (strlen(new_str) == 0)
        return ERR_EMPTY_STR;

    printf("Result: %s\n", new_str);
    return ERR_OK;
}
