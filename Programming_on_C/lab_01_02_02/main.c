#include <stdio.h>
#include <math.h>

#define OK 0

int main(void)
{
    double x_a, y_a, x_b, y_b, x_c, y_c; // Координаты на ввод
    double ab, bc, ac, p;
    
    printf("Введите координаты точек A B C в формате (x y x y x y) -> \n");
    scanf("%lf%lf%lf%lf%lf%lf", &x_a, &y_a, &x_b, &y_b, &x_c, &y_c);

    ab = sqrt(pow((x_b - x_a), 2) + pow((y_b - y_a), 2));
    bc = sqrt(pow((x_c - x_b), 2) + pow((y_c - y_b), 2));
    ac = sqrt(pow((x_c - x_a), 2) + pow((y_c - y_a), 2));
    p = ab + bc + ac;

    printf("Периметр треугольника: %lf", p);

    return OK;
}
