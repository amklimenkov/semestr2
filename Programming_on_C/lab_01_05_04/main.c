#include <stdio.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define CORRECT_INPUT 1
// Выводит простые множители числа на экран
void prime_multipliers(int n);

int main(void) 
{
    int number;

    if (scanf("%d", &number) != CORRECT_INPUT)
        return ERR_IO;

    if (number <= 0)
        return ERR_RANGE;

    if (number == 1)
        return OK;

    prime_multipliers(number);

    return OK;
}

void prime_multipliers(int n) 
{
    // Выделяем все множители 2 из числа
    while (n % 2 == 0)
    {
        printf("%d ", 2);
        n = n / 2;
    }

    // Перебираем нечетные числа только среди них может быть простые множители
    // Перебираем до корня числа, так как больший множитель содержит множитель до корня n
    for (int i = 3; i * i <= n; i = i + 2)
    {
        // Пока находим этот множитель в числе
        while (n % i == 0)
        {
            printf("%d ", i);
            n = n / i;
        }
    }

    // Если оставшееся число больше 2, то число простое
    if (n > 2)
    {
        printf("%d ", n);
    }
}
