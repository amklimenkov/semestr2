#include <string.h>
#include <stdlib.h>
#include "process.h"
#include "io.h"
#include "errors.h"

int main(int argc, char **argv)
{
    if (argc != 3 && argc != 4)
    {
        printf("Start command: \"./app.exe <key> <file_name> [<file_name_2>]\"\n");
        return ERR_PARAMS;
    }
    int rc = ERR_OK;
    if (strcmp(argv[1], "c") == 0 && argc == 4)
    {
        FILE *f_bin = fopen(argv[3], "wb");
        int number;
        number = atoi(argv[2]);
        if (f_bin == NULL)
            rc = ERR_IO;

        if (number < 0)
            rc = ERR_PARAMS;

        if (rc == ERR_OK)
            rc = write_rand_number_in_file(f_bin, number);

        if (f_bin != NULL)
            fclose(f_bin);
    } 
    else if (strcmp(argv[1], "p") == 0 && argc == 3)
    {
        FILE *f_bin = fopen(argv[2], "rb");
        rc = check_bin_file(f_bin);

        if (f_bin == NULL)
            rc = ERR_IO;
        
        if (rc == ERR_OK)
            rc = print_bin_file(f_bin);
        
        if (f_bin != NULL)
            fclose(f_bin);
    }
    else if (strcmp(argv[1], "s") == 0 && argc == 3)
    {
        FILE *f_bin = fopen(argv[2], "r+b");
        rc = check_bin_file(f_bin);
        if (f_bin == NULL)
            rc = ERR_IO;
        
        if (rc == ERR_OK)
            rc = sort_number_in_bin_file(f_bin);
        
        if (f_bin != NULL)
            fclose(f_bin);
    }
    else if (strcmp(argv[1], "import") == 0 && argc == 4)
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
        
        rc = check_bin_file(f_bin);
        if (f_txt == NULL || f_bin == NULL)
            rc = ERR_IO;
        
        if (rc == ERR_OK)
            rc = bin_to_text(f_bin, f_txt);

        if (f_txt != NULL)
            fclose(f_txt);
        if (f_bin != NULL)
            fclose(f_bin);
    }
    else
    {
        printf("Start command: \"./app.exe <key> <file_name> [<file_name_2>]\"\n");
        rc = ERR_PARAMS;
    }
    return rc;
}
