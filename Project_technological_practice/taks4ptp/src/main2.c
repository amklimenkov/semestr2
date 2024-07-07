#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "errors.h"
#include "sort.h"

#ifndef NMAX
#error Not defined array size NMAX
#endif

#define REPEATS 10

void fill_rand_arr(int *arr, size_t size);
unsigned long long calc_elapsed_time(const struct timespec *beg, const struct timespec *end);

int main(void)
{
    int a[NMAX];
    int src[NMAX];
    size_t size = sizeof(a) / sizeof(a[0]);
    unsigned long long time_tmp = 0;

    struct timespec beg = {0, 0};
    struct timespec end = {0, 0};

    srand(time(NULL));
    fill_rand_arr(src, NMAX);
    
    // "Разогрев"
    for (size_t i = 0; i < REPEATS; i++)
    {
        memcpy(a, src, sizeof(src));
        clock_gettime(CLOCK_MONOTONIC_RAW, &beg);
        insertion_sort(a, size);
        clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    }
    memcpy(a, src, sizeof(src));
    clock_gettime(CLOCK_MONOTONIC_RAW, &beg);
    insertion_sort(a, size);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    time_tmp = calc_elapsed_time(&beg, &end);
    

    printf("%llu\n", time_tmp);
    return ERR_OK;
}


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