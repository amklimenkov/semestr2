#include <stdbool.h>

#include "process.h"
#include "errors.h"

int last_digit(int n)
{
    if (n < 0)
        n = -n;
    return n % BASE;
}

// int find_max_above_side_diagonal(int (*a)[M], size_t n, size_t m, int *max)
// {
//     int rc = ERR_OK;
//     bool flag = false;
//     for (size_t i = 0; i < n; i++)
//     {
//         for (size_t j = m - i; j < m; j++)
//         {
//             if (last_digit(a[i][j]) == DIGIT)
//             {
//                 *max = a[i][j];
//                 flag = true;
//                 break;
//             }
//         }
//         if (flag)
//             break;
//     }

//     for (size_t i = 0; i < n; i++)
//     {
//         for (size_t j = m - i; j < m; j++)
//         {
//             if (last_digit(a[i][j]) == DIGIT && *max < a[i][j])
//                 *max = a[i][j];
//         }
//     }

//     if (!flag)
//         rc = ERR_NO_ANS;
    
//     return rc;
// }

int find_max_above_side_diagonal(int (*a)[M], size_t n, size_t m, int *max)
{
    int rc = ERR_OK;
    bool flag = false;
    
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = m - i; j < m; j++)
        {
            if (!flag && last_digit(a[i][j]) == DIGIT)
            {
                flag = true;
                *max = a[i][j];
            }
            if (last_digit(a[i][j]) == DIGIT && *max < a[i][j] && flag)
                *max = a[i][j];
        }
    }

    if (!flag)
        rc = ERR_NO_ANS;
    
    return rc;
}
