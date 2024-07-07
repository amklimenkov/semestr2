#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

#define ERR_OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define CORRECT_INPUT 2

// Сдвиг числа на n позиций влево
uint32_t left_circular_shift(uint32_t a, int n);
// Выводит на экран биты числа num
void printf_uint32_t(uint32_t num);

int main(void) 
{
    uint32_t a;
    int n;

    if (scanf("%" SCNu32 "%d", &a, &n) != CORRECT_INPUT)
    {
        printf("Error: input err");
        return ERR_IO;
    }
    
    if (n < 0)
    {
        printf("Error: range err");
        return ERR_RANGE;
    }
    
    uint32_t shifted_result = left_circular_shift(a, n);
    printf_uint32_t(shifted_result);

    return ERR_OK;
}

void printf_uint32_t(uint32_t num)
{
    int k = CHAR_BIT * sizeof (num);
    uint32_t mask = (uint32_t) 1 << (k - 1);
    printf("Result: ");
    while (k > 0)
    {
        if (num & mask)
            printf("1");
        else
            printf("0");

        num <<= 1;
        k--;
    }
}

// uint32_t left_circular_shift(uint32_t a, int n)
// {
//     return (a << n) | (a >> ((sizeof (a) * CHAR_BIT) - n));
// }
uint32_t left_circular_shift(uint32_t a, int n)
{   
    /*
    Значение "а" сдвигается на один бит влево с помощью оператора <<, 
    затем старший бит числа, который вышел за пределы 32-битного представления, 
    возвращается обратно и добавляется к "a" с использованием побитового или.
    */
    for (int i = 1;i <= n;i++)
    {
        a = a << 1 | (a >> ((sizeof (a) * CHAR_BIT) - 1));
    }
    return a;
}

