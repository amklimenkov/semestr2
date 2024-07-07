#include <stdio.h>

#include "process.h"

#include "io.h"

int main(void)
{
    char str1[STR_LEN];
    char str2[STR_LEN];
    size_t str_arr1_n, str_arr2_n;
    char str_arr1[MAX_WORDS_IN_STR][WORD_LEN];
    char str_arr2[MAX_WORDS_IN_STR][WORD_LEN];
    int rc = ERR_OK;

    rc = input(str1);
    if (rc != ERR_OK)
        return rc;

    rc = input(str2);
    if (rc != ERR_OK)
        return rc;
        
    rc = split(str1, str_arr1, &str_arr1_n);
    if (rc != ERR_OK)
        return rc;

    rc = split(str2, str_arr2, &str_arr2_n);
    if (rc != ERR_OK)
        return rc;

    rc = delete_duplicate(str_arr1, str_arr1_n);
    if (rc != ERR_OK)
        return rc;
    
    rc = print_result(str_arr1, str_arr1_n, str_arr2, str_arr2_n);
    if (rc != ERR_OK)
        return rc;
    
    return rc;
}
