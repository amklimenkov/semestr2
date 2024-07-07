#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <x86intrin.h>

#include "statistic.h"
#include "errors.h"
#include "sort.h"

#define MIN_ITER 20
#define MAX_ITER 10000
#define REPEATS 30
#ifndef NMAX
#error Not defined array size NMAX
#endif

void fill_rand_arr(int *arr, size_t size);
unsigned long long calc_elapsed_time(const struct timespec *beg, const struct timespec *end);

int main()
{
    int arr[NMAX];
    int src[NMAX];
    unsigned long long times[MAX_ITER];
    srand(time(NULL));
    fill_rand_arr(src, NMAX);
    
    unsigned long long start_ticks = 0;
    unsigned long long end_ticks = 0;
    unsigned long long time = 0;
    int n = 0;
    size_t size = 0;
    double average_v = 1;
    double dispersion_v = 1;
    double standart_deviation_v = 1;
    double standart_error_v = 1;
    double rse_value = rse(standart_error_v, average_v);
    // "Разогрев"
    for (size_t i = 0; i < REPEATS; i++)
    {
        memcpy(arr, src, sizeof(src));
        start_ticks = __rdtsc();
        insertion_sort(arr, size);
        end_ticks = __rdtsc();
    }

    for (size_t i = 0; (i < MAX_ITER && rse_value > 1) || i <= MIN_ITER;i++)
    {
        memcpy(arr, src, sizeof(src));
        start_ticks = __rdtsc();
        insertion_sort(arr, NMAX);
        end_ticks = __rdtsc();
        arr[0] = arr[1];
        arr[1] = 1234;
        time = end_ticks - start_ticks;
        times[i] = time;
        size++;
        printf("%llu\n", time);
        average(times, size, &average_v, &n);
        dispersion(times, size, &average_v, &dispersion_v, &n);
        standart_deviation(&dispersion_v, &standart_deviation_v);
        standart_err(&standart_deviation_v, n, &standart_error_v);
        rse_value = rse(standart_error_v, average_v);
    }

    return ERR_OK;
}

// вычисляет разность времени в микросекундах
unsigned long long calc_elapsed_time(const struct timespec *beg, const struct timespec *end)
{
    return ((unsigned long long)
        (end->tv_sec - beg->tv_sec) * 1000 * 1000 * 1000 +
                        (end->tv_nsec - beg->tv_nsec)) / 1000; 
}

void fill_rand_arr(int *arr, size_t size)
{
    for (size_t i = 0; i < size; i++)
        arr[i] = rand();
}