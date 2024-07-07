#include "process.h"

bool is_column_alternates(int (*a)[M], size_t n, size_t column)
{
    bool is_alternate = true;
    if (n <= 1)
    {
        is_alternate = false;
        return is_alternate;
    }
    for (size_t i = 1; is_alternate && i < n; i++)
    {
        if (a[i - 1][column] * a[i][column] >= 0)
        {
            is_alternate = false;
        }
    }
    
    return is_alternate;
}

void fill_col_arr(int *a, size_t a_n, int (*matrix)[M], size_t m_n, size_t m_m)
{
    for (size_t i = 0; i < a_n && i < m_m; i++)
    {
        a[i] = is_column_alternates(matrix, m_n, i);
    }
}
