#include <string.h>

#include "process.h"

int split(char (*el_arr)[WORD_LEN], size_t *n, char *str)
{
    if (el_arr == NULL || n == NULL || str == NULL)
        return ERR_NULL_PTR;

    char *word = strtok(str, DELIMS);
    *n = 0;
    while (word)
    {
        if (strlen(word) >= STR_LEN)
            return ERR_WORD_LEN;
        if (strncpy(el_arr[*n], word, WORD_LEN - 1) == NULL)
            return ERR_COPY;
        el_arr[*n][WORD_LEN - 1] = 0;

        (*n)++;

        word = strtok(NULL, DELIMS);
    }

    return ERR_OK;
}

int check_year(const char *str_year, int *year)
{
    for (size_t i = 0; str_year[i] != '\0'; i++)
    {
        if (!isdigit(str_year[i]))
            return ERR_YEAR;
    }

    *year = atoi(str_year);
    if (*year < 1000 || *year >= 10000)
        return ERR_YEAR;
    return ERR_OK;
}

int check_month(const char *str_month, int *month)
{
    char months[MONTHS_COUNT][MONTHS_LEN] = {
        "JANUARY",
        "FEBRUARY",
        "MARCH",
        "APRIL",
        "MAY",
        "JUNE",
        "JULY",
        "AUGUST",
        "SEPTEMBER",
        "OCTOBER",
        "NOVEMBER",
        "DECEMBER"
    };
    char str_month_tmp[MONTHS_LEN];

    if (MONTHS_LEN > strlen(str_month))
        strcpy(str_month_tmp, str_month);
    else
        return ERR_MONTH;

    for (size_t i = 0; i < MONTHS_COUNT; i++)
    {
        int flag = 0;
        capitalize(str_month_tmp);
        if (strcmp(str_month_tmp, months[i]) == 0 && strlen(str_month_tmp) == strlen(months[i]))
            flag = 1;
        if (flag == 1)
        {
            *month = i + 1;
            return ERR_OK;
        }
    }
    return ERR_MONTH;
}
int check_day(const char *str_day, int *day)
{
    for (size_t i = 0; str_day[i] != '\0'; i++)
    {
        if (!isdigit(str_day[i]))
            return ERR_DAY;
    }

    *day = atoi(str_day);
    if (*day <= 0 || *day > 31)
        return ERR_DAY;

    return ERR_OK;
}

int check_valid_date(int day, int month, int year)
{
    if (month < 1 || month > 12)
        return ERR_NO_VALID_DATE;
    

    if (month == 2 && day > 28) 
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 100 == 0))
        {
            if (day > 29)
                return ERR_NO_VALID_DATE;
        }
        else
        {
            return ERR_NO_VALID_DATE;
        }
    }
    
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return ERR_NO_VALID_DATE;
    
    return ERR_OK;
}

int check_date(char (*el_arr)[WORD_LEN])
{
    const char *str_day = el_arr[0];
    const char *str_month = el_arr[1];
    const char *str_year = el_arr[2];

    int day = 0, month = 0, year = 0;
    int rc = check_day(str_day, &day);
    rc += check_month(str_month, &month);
    rc += check_year(str_year, &year);
    rc += check_valid_date(day, month, year);
    if (rc != 0)
        return ERR_NO_VALID_DATE;
    
    return ERR_OK;
}

void capitalize(char *str)
{
    for (size_t i = 0; i < strlen(str);i++)
    {
        str[i] = toupper(str[i]);
    }
}
