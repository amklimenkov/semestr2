#include <assert.h>
#include <inttypes.h>

#include "io.h"
#include "stud.h"
#include "ft_stud.h"

int text_to_bin(FILE *f_txt, FILE *f_bin)
{
    assert(f_bin != NULL);
    assert(f_txt != NULL);

    int rc = ERR_OK;
    struct stud_t students[N_STUDENTS];
    size_t size = 0;
    rewind(f_txt);
    while (rc == ERR_OK && size < N_STUDENTS)
    {
        rc = get_next_stud(f_txt, &(students[size]));
        if (rc == ERR_OK)
            size++; 
    }
    rc = ERR_OK;
    for (size_t i = 0; rc == ERR_OK && i < size; i++)
    {
        if (fwrite(&students[i], sizeof(students[i]), 1, f_bin) != 1)
            rc = ERR_IO;
    }
    return rc;
}

int bin_to_text(FILE *f_bin, FILE *f_txt)
{
    assert(f_bin != NULL);
    assert(f_txt != NULL);

    int rc = ERR_OK;
    struct stud_t stud;
    if (fseek(f_bin, 0, SEEK_END) != 0)
        return ERR_IO;
    
    long size = ftell(f_bin);
    if (fseek(f_bin, 0, SEEK_SET) != 0)
        return ERR_IO;
    
    while (rc == ERR_OK && ftell(f_bin) <= size && (fread(&stud, sizeof(stud), 1, f_bin) == 1))
    {
        if (fprintf(f_txt, "%s\n%s\n%d %d %d %d\n", stud.surname, stud.lastname, stud.grades[0], stud.grades[1], stud.grades[2], stud.grades[3]) < 0)
            rc = ERR_IO;
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

    if (size % sizeof(struct stud_t) != 0)
        return ERR_CORRUPT_FILE;
    
    return ERR_OK;
}

int check_text_file(FILE *f_txt)
{
    long size;
    if (fseek(f_txt, 0, SEEK_END) != 0)
        return ERR_IO;
    
    size = ftell(f_txt);
    if (size == -1)
        return ERR_IO;

    if (size == 0)
        return ERR_NOT_ENOUGH_DATA;

    
    return ERR_OK;
}

