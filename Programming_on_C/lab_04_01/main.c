#include <stdio.h>

#include "errors.h"
#include "lim.h"
#include "process.h"

int main(void)
{
    printf("Failed tests: %zu\n", test());
    return ERR_OK;
}
