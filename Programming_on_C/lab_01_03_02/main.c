#include <stdio.h>

#define OK 0

int main(void)
{
    float r1, r2, r3, r = 0;
    scanf("%f%f%f", &r1, &r2, &r3);

    r += 1.0f / r1;

    r += 1.0f / r2;


    r += 1.0f / r3;

    r = 1.0f / r;

    printf("%f", r);

    return OK;
}
