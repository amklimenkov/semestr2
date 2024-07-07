#include <stdio.h>

#define OK 0
#define SEC_IN_HOUR 3600
#define SEC_IN_MINUTE 60

int main(void)
{
    unsigned int sec, min, hour;
    scanf("%u", &sec);

    hour = sec / SEC_IN_HOUR;
    min = (sec - hour * SEC_IN_HOUR) / SEC_IN_MINUTE;
    sec = sec - hour * SEC_IN_HOUR - min * SEC_IN_MINUTE;

    printf("%d %d %d", hour, min, sec);

    return OK;
}
