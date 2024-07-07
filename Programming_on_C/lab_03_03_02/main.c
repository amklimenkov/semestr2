#include "io.h"
#include "errors.h"
#include "process.h"

int main(void)
{
    int a[N][M];
    size_t n, m;
    int rc;

    rc = get_matrix_size(&n, &m);
    if (rc != ERR_OK)
        return rc;
    
    rc = get_matrix(a, n, m);
    if (rc != ERR_OK)
        return rc;
    
    matrix_sort(a, n, m);
    print_matrix(a, n, m);

    return ERR_OK;
}
