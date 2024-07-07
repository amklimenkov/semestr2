#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "io.h"

int text_to_bin(FILE *f_txt, FILE *f_bin)
{
    assert(f_bin != NULL);
    assert(f_txt != NULL);

    int el, rc = ERR_OK;

    rewind(f_txt);
    while (rc == ERR_OK && fscanf(f_txt, "%d", &el) == 1)
    {
        if (fwrite(&el, sizeof(el), 1, f_bin) != 1)
            rc = ERR_IO;
    }

    return rc;
}

int bin_to_text(FILE *f_bin, FILE *f_txt)
{
    assert(f_bin != NULL);
    assert(f_txt != NULL);

    int el, rc = ERR_OK;
    if (fseek(f_bin, 0, SEEK_SET) != 0)
        return ERR_IO;
    
    while (rc == ERR_OK && (fread(&el, sizeof(el), 1, f_bin) == 1))
    {
        if (fprintf(f_txt, "%d ", el) < 0)
            rc = ERR_IO;
    }

    return rc;
}

int write_rand_number_in_file(FILE *f_bin, size_t number)
{
    int el, rc = ERR_OK;
    srand((unsigned)time(NULL));
    for (size_t i = 0; rc == ERR_OK && i < number; i++)
    {
        el = rand();
        if (fwrite(&el, sizeof(el), 1, f_bin) != 1)
            rc = ERR_IO;
    }

    return rc;
}

int print_bin_file(FILE *f_bin)
{
    assert(f_bin != NULL);

    int rc = ERR_OK, el;
    long size;
    if (fseek(f_bin, 0, SEEK_END) != 0)
        return ERR_IO;
    
    size = ftell(f_bin);
    if (size == -1)
        return ERR_IO;
    
    if (fseek(f_bin, 0, SEEK_SET) != 0)
        return ERR_IO;

    for (size_t i = 0; rc == ERR_OK && i < size / sizeof(int); i++)
    {
        if (fread(&el, sizeof(el), 1, f_bin) != 1)
            rc = ERR_IO;

        if (rc == ERR_OK)
            printf("%d ", el);
    }

    return rc;
}

int check_bin_file(FILE *f_bin)
{
    long size;
    if (fseek(f_bin, 0, SEEK_END) != 0)
        return ERR_IO;
    
    size = ftell(f_bin);
    if (size == -1)
        return ERR_IO;

    if (size == 0)
        return ERR_NOT_ENOUGH_DATA;

    if (size % sizeof(int) != 0)
        return ERR_CORRUPT_FILE;
    
    return ERR_OK;
}
