#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define CORRECT_INPUT 2

// Подсчет функции s(x)=1-2*3*x/2+3*4*x**2/2 ... с точностью eps
double s(double x, double eps);

// Вычисление функции f(x) в точке x
double f(double x);

int main(void)
{
    double x, eps, s_value, f_value;
    double fabs_error, relative_error;

    if ((scanf("%lf%lf", &x, &eps)) != CORRECT_INPUT)
        return ERR_IO;

    if (x <= -1.0 || x >= 1.0 || eps <= 0.0 || eps > 1.0)
        return ERR_RANGE;

    f_value = f(x);
    s_value = s(x, eps);
    fabs_error = f_value - s_value;

    fabs_error = fabs(fabs_error);

    f_value = fabs(f_value);

    relative_error = fabs_error / f_value;

    printf("%f %f %f %f", s_value, f(x), fabs_error, relative_error);

    return ERR_OK;
}

double s(double x, double eps)
{
    double s = 1 - 3 * x;
    int k = 2;
    int q = 4;
    double t = 3 * x;

    while (fabs(t) > eps)
    {
        t = x * q / (q - 2) * t;

        // if (k % 2 == 0) 
        // {
        //     s += t;
        // }
        // else
        // {
        //     s -= t;
        // }
        s += (1 - 2 * (k % 2)) * t;
        // s = s + t * ((k % 2) * 2 - 1);
        q++;
        k++;
    }

    return s;
}

double f(double x)
{
    return 1.0 / ((1 + x) * (1 + x) * (1 + x));
}
