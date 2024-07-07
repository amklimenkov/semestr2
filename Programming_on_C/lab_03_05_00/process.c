#include "process.h"
#include "errors.h"

bool is_prime(int n)
{
    bool is_prime = true;
    if (n <= 1)
    {
        is_prime = false;
        return is_prime;
    }
    for (int i = 2; is_prime && i * i <= n; i++)
    {
        if (n % i == 0)
        {
            is_prime = false;
        }
    }
    return is_prime;
}
int fill_prime_arr(int *a, size_t *n, int (*matrix)[M], size_t m_n, size_t m_m)
{
    size_t index = 0;
    *n = 0;
    for (size_t i = 0; i < m_n; i++)
    {
        for (size_t j = 0;j < m_m; j++)
        {
            if (is_prime(matrix[i][j]))
            {
                a[index] = matrix[i][j];
                index++;
            }
        }
    }
    *n = index;
    
    return ERR_OK;
}
void reverse_arr(int *a, size_t n)
{
    int temp;
    for (size_t i = 0; i < n / 2; i++)
    {
        temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }
}

int insert_arr_to_matrix(const int *a, size_t n, int (*matrix)[M], size_t m_n, size_t m_m)
{
    size_t index = 0;
    
    for (size_t i = 0; i < m_n; i++)
    {
        for (size_t j = 0; j < m_m; j++)
        {
            if (is_prime(matrix[i][j]))
            {   
                if (index < n)
                {
                    matrix[i][j] = a[index];
                    index++;
                }
                else
                    return ERR_MATRIX;
            }
        }
    }
    
    if (index != n)
        return ERR_MATRIX;

    return ERR_OK;
}
