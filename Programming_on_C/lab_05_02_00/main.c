#include <stdio.h>

#include "errors.h"
#include "io.h"
#include "process.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Start application: \"./app.exe <file_name>\"\n");
        return ERR_PARAMS;
    }

    FILE *f;
    int rc;
    double average, answer;

    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Can't open file\n");
        return ERR_IO;
    }

    rc = is_file_contain_double(f);
    if (rc == ERR_OK)
    {
        calc_average(f, &average);
        find_number_with_min_diff(f, average, &answer);
    }
    else
        printf("File doesn't consist double nums.\n");

    if (rc == ERR_OK)
        printf("%f", answer);

    fclose(f);
    return rc;
}
