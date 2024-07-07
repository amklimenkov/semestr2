#include "io.h"
#include "errors.h"
#include "process.h"

int main(void)
{
    int a[N][M];
    int prime_arr[MAX_ARR_SIZE];
    size_t n, m, pa_n;
    int rc;

    rc = get_matrix_size(&n, &m);
    if (rc != ERR_OK)
        return rc;
    
    rc = get_matrix(a, n, m);
    if (rc != ERR_OK)
        return rc;
    
    rc = fill_prime_arr(prime_arr, &pa_n, a, n, m);
    if (rc != ERR_OK)
        return rc;
        
    if (pa_n == 0)
        return ERR_NO_PRIME;

    reverse_arr(prime_arr, pa_n);
    rc = insert_arr_to_matrix(prime_arr, pa_n, a, n, m);
    if (rc != ERR_OK)
        return rc;
    
    print_matrix(a, n, m);
    return ERR_OK;
}
