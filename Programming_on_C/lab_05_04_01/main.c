#include <string.h>
#include <stdlib.h>
#include "ft_stud.h"
#include "fb_stud.h"
#include "io.h"
#include "errors.h"

int main(int argc, char **argv)
{
    if (argc != 3 && argc != 4 && argc != 5)
    {
        return ERR_PARAMS;
    }
    int rc = ERR_OK;
    if (strcmp(argv[1], "import") == 0 && argc == 4)
    {
        FILE *f_txt = fopen(argv[2], "r");
        FILE *f_bin = fopen(argv[3], "wb");
        rc = ERR_OK;
        if (f_txt == NULL || f_bin == NULL)
            rc = ERR_IO;

        if (rc == ERR_OK)
            rc = text_to_bin(f_txt, f_bin);

        if (f_txt != NULL)
            fclose(f_txt);
        if (f_bin != NULL)
            fclose(f_bin);
    }
    else if (strcmp(argv[1], "export") == 0 && argc == 4)
    {
        FILE *f_bin = fopen(argv[2], "rb");
        FILE *f_txt = fopen(argv[3], "w");
        
        
        if (f_txt == NULL || f_bin == NULL)
            rc = ERR_IO;

        if (rc == ERR_OK)
            rc = check_bin_file(f_bin);

        if (rc == ERR_OK)
            rc = bin_to_text(f_bin, f_txt);

        if (f_txt != NULL)
            fclose(f_txt);
        if (f_bin != NULL)
            fclose(f_bin);
    }
    else if (strcmp(argv[1], "sb") == 0 && argc == 3)
    {
        FILE *f_bin = fopen(argv[2], "r+b");
        
        
        if (f_bin == NULL)
            rc = ERR_IO;

        if (rc == ERR_OK)
            rc = check_bin_file(f_bin);
            
        if (rc == ERR_OK)
            rc = sort_stud_in_bin_file(f_bin);

        if (f_bin != NULL)
        {
            fclose(f_bin);
        }
    }
    else if (strcmp(argv[1], "ft") == 0 && argc == 5)
    {
        FILE *f_src = fopen(argv[2], "r");
        FILE *f_dst = fopen(argv[3], "w");
        char subs[SURNAME_LEN];
        if (strlen(argv[4]) >= SURNAME_LEN)
            return ERR_PARAMS;
        else
            strcpy(subs, argv[4]);

        if (f_src == NULL || f_dst == NULL)
            rc = ERR_IO;

        if (rc == ERR_OK)
            rc = check_text_file(f_src);
        
        if (rc == ERR_OK && strlen(argv[4]) != 0)
            rc = print_stud_with_sub_in_surname(f_src, f_dst, subs);

        if (rc == ERR_OK)
        {
            if (ftell(f_dst) == 0)
                rc = ERR_EMPTY_FILE;
        }
        if (f_src != NULL)
        {
            fclose(f_src);
        }
        
        if (f_dst != NULL)
        {
            fclose(f_dst);
        }
    }
    else
    {
        rc = ERR_PARAMS;
    }
    return rc;
}
