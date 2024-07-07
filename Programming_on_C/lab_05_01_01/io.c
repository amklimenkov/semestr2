#include "io.h"
#include "errors.h"

int get_next_number(FILE *f, int *number)
{
    if (fscanf(f, "%d", number) != 1)
        return ERR_IO;
    
    return ERR_OK;
}
