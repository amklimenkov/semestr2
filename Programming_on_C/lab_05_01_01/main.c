#include <stdio.h>

#include "errors.h"
#include "process.h"

int main(void)
{
    FILE *f = stdin;
    int rc = ERR_OK, max, prev_max;

    rc = process(f, &max, &prev_max);
    if (rc == ERR_OK)
        printf("%d %d", max, prev_max);
    
    return rc;
}
