#include "process.h"
#include "io.h"
#include "errors.h"

int process(FILE *f, int *max, int *prev_max)
{
    int max_tmp, prev_max_tmp, el;
    if (get_next_number(f, &max_tmp) != ERR_OK)
        return ERR_NOT_ENOUGH_DATA;
    
    if (get_next_number(f, &prev_max_tmp) != ERR_OK)
        return ERR_NOT_ENOUGH_DATA;

    if (prev_max_tmp > max_tmp)
    {
        int tmp = max_tmp;
        max_tmp = prev_max_tmp;
        prev_max_tmp = tmp;
    }

    while (get_next_number(f, &el) == ERR_OK)
    {
        if (el > max_tmp)
        {
            prev_max_tmp = max_tmp;
            max_tmp = el;
        } 
        else if (el > prev_max_tmp)
        {
            prev_max_tmp = el;
        }
    }

    *max = max_tmp;
    *prev_max = prev_max_tmp;

    return ERR_OK;
}