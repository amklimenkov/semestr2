#include <stdio.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_RANGE 2

// Функция возведения быстрым методом числа с основанием base в степень n
int pow_quick_method(int base, int n);

int main(void)
{
    int a, n;

    if (scanf("%d%d", &a, &n) != 2)
        return ERR_IO;

    if (n <= 0)
        return ERR_RANGE;

    if (a == 0)
    {
        printf("%d", a);
        return ERR_OK;
    }
    
    
    printf("%d", pow_quick_method(a, n));

    return ERR_OK;
}

int pow_quick_method(int base, int n)
{
    int res = 1;
    int z = base;
    while (n > 0)
    {  
        if (n % 2 == 1)
        {
            res *= z;
            z = z * z;
        } 
        else 
        {
            z = z * z;
        }
        n /= 2;
    }
    return res;
}
