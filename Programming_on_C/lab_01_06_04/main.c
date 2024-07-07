#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define EPSILON 0.0000001
#define BELONGS_TO_SEGMENT 1
#define NOT_BELONGS_TO_SEGMENT 0

// Скалярное произведение векторов a b
double scalar_product(double x_a, double y_a, double x_b, double y_b);
// Псевдоскалярное произведение векторов a b
double abs_vector_product(double x_a, double y_a, double x_b, double y_b);
// Проверка принадлежности отрезку a b точки m
int is_belongs_to_segment(double x_a, double y_a, double x_b, double y_b, double x_m, double y_m);

int main(void)
{
    double x_q, y_q, x_r, y_r, x_p, y_p;

    if (scanf("%lf%lf%lf%lf%lf%lf", &x_q, &y_q, &x_r, &y_r, &x_p, &y_p) != 6)
        return ERR_IO;

    if (fabs(x_q - x_r) <= EPSILON && fabs(y_q - y_r) <= EPSILON)
        return ERR_RANGE;

    printf("%d", is_belongs_to_segment(x_q, y_q, x_r, y_r, x_p, y_p));

    return OK;
}

double scalar_product(double x_a, double y_a, double x_b, double y_b)
{
    double scalar;
    scalar = x_a * x_b + y_a * y_b;

    return scalar;
}

double abs_vector_product(double x_a, double y_a, double x_b, double y_b)
{
    double vector_product;
    vector_product = x_a * y_b - x_b * y_a;

    return vector_product;
}

int is_belongs_to_segment(double x_a, double y_a, double x_b, double y_b, double x_m, double y_m)
{
    double ab_x, ab_y;
    double am_x, am_y;
    double ma_x, ma_y;
    double mb_x, mb_y;

    ab_x = x_b - x_a;
    ab_y = y_b - y_a;
    am_x = x_m - x_a;
    am_y = y_m - y_a;
    ma_x = x_a - x_m;
    ma_y = y_a - y_m;
    mb_x = x_b - x_m;
    mb_y = y_b - y_m;

    if ((fabs(x_a - x_m) <= EPSILON && fabs(y_a - y_m) <= EPSILON) || (fabs(x_b - x_m) <= EPSILON && fabs(y_b - y_m) <= EPSILON))
        return BELONGS_TO_SEGMENT;

    if (scalar_product(ma_x, ma_y, mb_x, mb_y) <= 0.0 && fabs(abs_vector_product(ab_x, ab_y, am_x, am_y)) <= EPSILON)
        return BELONGS_TO_SEGMENT;
    else
        return NOT_BELONGS_TO_SEGMENT;
}

