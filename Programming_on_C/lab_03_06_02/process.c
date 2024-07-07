#include "process.h"
#include "errors.h"

void fill_matrix(int (*a)[M], size_t n, size_t m)
{
    int el = 1;
    int j = m - 1;
    int flag = 1;
    while (j >= 0)
    {
        // Начальная иницализация, если flag == 1, то запись ведется вверх, иначе вниз
        int i = (flag == 1) ? (n - 1) : 0;
        int step = (flag == 1) ? -1 : 1;
        
        while (i >= 0 && i < (int) n)
        {
            a[i][j] = el;
            el++;
            i += step;
        }
        j--;
        // Меняем направление заполнения
        flag *= -1;
    }
}
