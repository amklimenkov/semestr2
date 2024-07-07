#include <stdio.h>

#include "io.h"
#include "errors.h"
#include "process.h"

int main(void)
{
    int a[N][M];
    size_t n, m;
    int rc, max_el;

    rc = get_matrix_size(&n, &m);
    if (rc != ERR_OK)
        return rc;
        
    if (m != n)
        return ERR_NOT_SQUARE_MATRIX;

    rc = get_matrix(a, n, m);
    if (rc != ERR_OK)
        return rc;
    
    rc = find_max_above_side_diagonal(a, n, m, &max_el);
    if (rc != ERR_OK)
        return rc;
    
    printf("Максимальный элемент: %d", max_el);


    return ERR_OK;
}
