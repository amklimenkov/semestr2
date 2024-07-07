#include <assert.h>
#include <string.h>
#include "fb_stud.h"

int get_stud_by_pos(FILE *f_bin, long pos, struct stud_t *stud)
{
    assert(f_bin != NULL);
    assert(stud != NULL);

    if (fseek(f_bin, pos * sizeof(*stud), SEEK_SET) != 0)
        return ERR_IO;

    if (fread(stud, sizeof(*stud), 1, f_bin) != 1)
        return ERR_IO;
    
    return ERR_OK;
}

int put_stud_by_pos(FILE *f_bin, long pos, const struct stud_t *stud)
{
    assert(f_bin != NULL);
    assert(stud != NULL);

    if (fseek(f_bin, pos * sizeof(*stud), SEEK_SET) != 0)
        return ERR_IO;
    
    if (fwrite(stud, sizeof(*stud), 1, f_bin) != 1)
        return ERR_IO;
    
    return ERR_OK;
}

int sort_stud_in_bin_file(FILE *f_bin)
{
    long size;
    if (fseek(f_bin, 0, SEEK_END) != 0)
        return ERR_IO;
    
    size = ftell(f_bin);
    if (size == -1)
        return ERR_IO;

    size = size / sizeof(struct stud_t);
    if (fseek(f_bin, 0, SEEK_SET) != 0)
        return ERR_IO;

    int j, rc = ERR_OK;
    for (long i = 1; rc == ERR_OK && i < size; i++)
    {
        struct stud_t stud_curr, stud_prev;
        char full_name_prev[SURNAME_LEN + LASTNAME_LEN - 1];
        char full_name_curr[SURNAME_LEN + LASTNAME_LEN - 1];

        rc = get_stud_by_pos(f_bin, i, &stud_curr);
        j = i - 1;
        rc = get_stud_by_pos(f_bin, j, &stud_prev);
        if (rc == ERR_OK)
        {
            rc = get_full_name(full_name_curr, &stud_curr);
            rc = get_full_name(full_name_prev, &stud_prev);
        }

        while (rc == ERR_OK && j >= 0 && (strcmp(full_name_prev, full_name_curr) > 0))
        {
            rc = put_stud_by_pos(f_bin, j + 1, &stud_prev);
            j--;              
            if (rc == ERR_OK && j >= 0)
            {
                rc = get_stud_by_pos(f_bin, j, &stud_prev);
                rc = get_full_name(full_name_prev, &stud_prev);
            }
        }
        rc = put_stud_by_pos(f_bin, j + 1, &stud_curr);
    }

    return rc;
}

int get_full_name(char *full_name, const struct stud_t *stud)
{
    int rc = ERR_OK;
    strcpy(full_name, stud->surname);
    strcat(full_name, stud->lastname);
    return rc;
}
