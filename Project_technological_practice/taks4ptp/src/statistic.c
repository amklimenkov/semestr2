#include <math.h>

#include "statistic.h"

int average(const unsigned long long *times, size_t arr_size, double *average, int *n)
{
    double sum;
    int n_tmp = 0;
    long el;

    for (size_t i = 0; i < arr_size; i++)
    {
        el = times[i];
        sum += el;
        n_tmp++;
    }

    *n = n_tmp;
    *average = sum / n_tmp;

    return ERR_OK;
}
int dispersion(const unsigned long long *times, size_t arr_size, double *average, double *dispersion, int *n)
{
    long el;
    double sum;
    double tmp;
    int n_tmp = 0;
    for (size_t i = 0; i < arr_size; i++)
    {
        el = times[i];
        tmp = el - *average;
        sum += tmp * tmp;
        n_tmp++;
    }
    *dispersion = sum / (n_tmp - 1);
    *n = n_tmp;

    return ERR_OK;
}
int standart_deviation(double *dispersion, double *standart_deviation)
{
    *standart_deviation = sqrt(*dispersion);
    return ERR_OK;
}

int standart_err(double *standart_deviation, int n, double *standart_err)
{
    *standart_err = *standart_deviation / sqrt(n);
    return ERR_OK;
}
double rse(double standart_error, double average)
{
    return standart_error / average * 100;
}