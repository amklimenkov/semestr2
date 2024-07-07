#include <stdio.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_RANGE 2

#define MAX_SIZE 15

int input_size(size_t *size);
int input_arr(int *a, size_t size);
void sort_odd_elem(int *a, size_t size);
void print_arr(const int *a, size_t size);
void swap(int *a, int *b);

int main(void)
{
    int a[MAX_SIZE];
    int rc;
    size_t size;

    rc = input_size(&size);
    if (rc != ERR_OK)
        return rc;

    rc = input_arr(a, size);
    if (rc != ERR_OK)
        return rc;
    sort_odd_elem(a, size);
    print_arr(a, size);

    return ERR_OK;

}

int input_size(size_t *size)
{
    if (scanf("%zu", size) != 1)
        return ERR_IO;

    if (*size == 0 || *size > MAX_SIZE)
        return ERR_RANGE;

    return ERR_OK;
}

int input_arr(int *a, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            return ERR_IO;
        }
    }
    return ERR_OK;
}

void print_arr(const int *a, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void sort_odd_elem(int *a, size_t size)
{
    for (size_t i = 0; size != 1 && i < size - 2 ; i+=2)
    {
        for (size_t j = 0; size != 1 && j < size - 2; j+=2)
        {
            if (a[j] > a[j+2])
                swap(&a[j], &a[j+2]);
        }
    }
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
