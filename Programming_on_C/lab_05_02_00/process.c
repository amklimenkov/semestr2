#include "process.h"
#include <assert.h>
#include <math.h>

int get_next_number(FILE *f, double *el)
{
    if (fscanf(f, "%lf", el) != 1)
        return ERR_IO;
    
    return ERR_OK;
}

void calc_average(FILE *f, double *avg)
{
    assert(f != NULL);
    assert(avg != NULL);

    size_t count = 0;
    double el, summa = 0;

    rewind(f); // Смещаем на начало, чтобы начать чтение всех чисел
    while (get_next_number(f, &el) == ERR_OK)
    {
        summa += el;
        count++;
    }

    *avg = summa / count;
}

void find_number_with_min_diff(FILE *f, double avg, double *number)
{
    assert(f != NULL);
    assert(number != NULL);

    rewind(f);
    double el;
    get_next_number(f, &el);
    double min_diff = fabs(el - avg), tmp_ans = el;
    double diff;

    while (get_next_number(f, &el) == ERR_OK)
    {
        diff = fabs(el - avg);
        if (diff < min_diff)
        {
            min_diff = diff;
            tmp_ans = el;
        }
    }

    *number = tmp_ans;
}
