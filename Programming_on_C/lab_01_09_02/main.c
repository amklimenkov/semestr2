#include <stdio.h>
#include <math.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_SUMMA_CALC 2
#define CORRECT_INPUT 1

// Возвращает вычисленное значение функции g(x) 
int summa(double *summa);

int main()
{
    int err_code;
    double summa_res;

    err_code = summa(&summa_res);

    if (err_code != ERR_OK)
        return err_code;

    printf("%f", summa_res);
    return ERR_OK;
}

int summa(double *summa)
{
    double summa_t = 0;
    double x;
    unsigned int n = 0;

    int rc;
    while (((rc = scanf("%lf", &x)) == CORRECT_INPUT) && x >= 0.0)
    {
        summa_t += sqrt(n + 1 + x);
        n++;
    }
    if (rc != CORRECT_INPUT)
        return ERR_IO;
    
    if (n == 0)
        return ERR_SUMMA_CALC;
    *summa = summa_t / n;
    return ERR_OK;
}
