#ifndef STATISTIC_H__
#define STATISTIC_H__

#include <stdio.h>
#include "errors.h"

int average(const unsigned long long *times, size_t arr_size, double *average, int *n);
int dispersion(const unsigned long long *times, size_t arr_size, double *average, double *dispersion, int *n);
int standart_err(double *standart_deviation, int n, double *standart_err);
int standart_deviation(double *dispersion, double *standart_deviation);
double rse(double standart_error, double average);
#endif