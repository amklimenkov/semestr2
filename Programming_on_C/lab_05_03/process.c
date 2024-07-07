#include <assert.h>
#include "process.h"

int get_number_by_pos(FILE *f_bin, long pos, int *number)
{
    assert(f_bin != NULL);
    assert(number != NULL);

    if (fseek(f_bin, pos * sizeof(*number), SEEK_SET) != 0)
        return ERR_IO;

    if (fread(number, sizeof(*number), 1, f_bin) != 1)
        return ERR_IO;
    
    return ERR_OK;
}

int put_number_by_pos(FILE *f_bin, long pos, int number)
{
    assert(f_bin != NULL);

    if (fseek(f_bin, pos * sizeof(number), SEEK_SET) != 0)
        return ERR_IO;
    
    if (fwrite(&number, sizeof(number), 1, f_bin) != 1)
        return ERR_IO;
    
    return ERR_OK;
}

int sort_number_in_bin_file(FILE *f_bin)
{
    long size;
    if (fseek(f_bin, 0, SEEK_END) != 0)
        return ERR_IO;
    
    size = ftell(f_bin);
    if (size == -1)
        return ERR_IO;

    size = size / sizeof(int);
    if (fseek(f_bin, 0, SEEK_SET) != 0)
        return ERR_IO;

    int j, rc = ERR_OK;
    for (long i = 1; rc == ERR_OK && i < size; i++)
    {
        int el, prev_el;
        rc = get_number_by_pos(f_bin, i, &el);
        j = i - 1;
        rc = get_number_by_pos(f_bin, j, &prev_el);
        while (rc == ERR_OK && j >= 0 && prev_el > el)
        {
            rc = put_number_by_pos(f_bin, j + 1, prev_el);
            j--;              
            if (rc == ERR_OK && j >= 0) 
                rc = get_number_by_pos(f_bin, j, &prev_el);
        }
        rc = put_number_by_pos(f_bin, j + 1, el);
    }

    return rc;
}
