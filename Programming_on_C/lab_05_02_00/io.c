#include <stddef.h>
#include "io.h"

int is_file_contain_double(FILE *f)
{
    size_t count = 0;
    double el;
    
    if (fscanf(f, "%lf", &el) == 1)
        count++;

    if (count == 0)
        return ERR_NOT_ENOUGH_DATA;

    return ERR_OK;
}
