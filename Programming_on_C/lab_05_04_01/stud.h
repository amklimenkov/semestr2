#ifndef STUD_H__
#define STUD_H__

#include <stdint.h>
#include <stdbool.h>

#define SURNAME_LEN (25 + 1)
#define LASTNAME_LEN (10 + 1)
#define N_GRAGE 4

struct stud_t
{
    char surname[SURNAME_LEN];
    char lastname[LASTNAME_LEN];
    uint32_t grades[N_GRAGE];
};

#endif
