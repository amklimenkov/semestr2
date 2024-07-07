#include "io.h"
#include "errors.h"
#include "process.h"

int main(void)
{
    int a[N][M], col_arr[M];
    size_t n, m;
    int rc;

    rc = get_matrix_size(&n, &m);
    if (rc != ERR_OK)
        return rc;
    
    rc = get_matrix(a, n, m);
    if (rc != ERR_OK)
        return rc;
    
    fill_col_arr(col_arr, m, a, n, m);
    print_arr(col_arr, m);

    return ERR_OK;
}
