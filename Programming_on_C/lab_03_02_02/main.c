#include "io.h"
#include "errors.h"
#include "process.h"

int main(void)
{
    int a[N_MATRIX][M_MATRIX];
    size_t n, m;
    int rc;
    rc = get_matrix_size(&n, &m);
    if (rc != ERR_OK)
        return rc;
    
    rc = get_matrix(a, n, m);
    if (rc != ERR_OK)
        return rc;

    insert_above_checked_rows(a, &n, m);
    print_matrix(a, n, m);
    
    return ERR_OK;
}
