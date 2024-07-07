#include <inttypes.h>
#include <string.h>
#include <ctype.h>
#include "ft_stud.h"
#include "io.h"
#include "errors.h"

int print_stud_with_sub_in_surname(FILE *f_src, FILE *f_dst, const char *subs)
{
    int rc = ERR_OK;
    struct stud_t stud;
    struct stud_t students[N_STUDENTS];
    memset(&stud, 0, sizeof(stud));
    if (fseek(f_src, 0, SEEK_END) != 0)
        rc = ERR_IO;
    long end = ftell(f_src);
    if (fseek(f_src, 0, SEEK_SET) != 0)
        rc = ERR_IO;

    size_t size = 0;
    while (rc == ERR_OK && ftell(f_src) < end)
    {
        rc = get_next_stud(f_src, &(students[size]));
        if (rc == ERR_OK)
            size++;
    }

    
    for (size_t i = 0, j = 0; rc == ERR_OK && i < size; i++)
    {
        char *sub_str = strstr(students[i].surname, subs);
        if (sub_str == students[i].surname)
        {
            if (j == 0)
            {
                if (fprintf(f_dst, "%s\n%s\n%d %d %d %d", students[i].surname, students[i].lastname, students[i].grades[0], students[i].grades[1], students[i].grades[2], students[i].grades[3]) < 0)
                    rc = ERR_IO;
            }
            else
            {
                if (fprintf(f_dst, "\n%s\n%s\n%d %d %d %d", students[i].surname, students[i].lastname, students[i].grades[0], students[i].grades[1], students[i].grades[2], students[i].grades[3]) < 0)
                    rc = ERR_IO;
            }
            j++;
        }
    }
    return rc;
}

int get_next_stud(FILE *f_txt, struct stud_t *stud)
{
    int rc = ERR_OK;
    // Читаем фамилию
    char buf_sur[SURNAME_LEN + 1];
    buf_sur[0] = 0;
    if (!fgets(buf_sur, SURNAME_LEN + 1, f_txt))
        rc = ERR_IO;
    char *enter = strrchr(buf_sur, '\n');
    if (enter)
        *enter = 0;

    if (strlen(buf_sur) >= SURNAME_LEN)
        rc = ERR_IO;
    
    if (rc == ERR_OK && strlen(buf_sur) > 0)
    {
        strncpy(stud->surname, buf_sur, SURNAME_LEN);
        stud->surname[SURNAME_LEN - 1] = 0;
    }
    else
        rc = ERR_IO;


    // Читаем имя
    char buf_last[LASTNAME_LEN + 1];
    buf_last[0] = 0;
    if (!fgets(buf_last, LASTNAME_LEN + 1, f_txt))
        rc = ERR_IO;
    enter = strrchr(buf_last, '\n');
    if (enter)
        *enter = 0;
    if (strlen(buf_last) >= LASTNAME_LEN)
        rc = ERR_IO;
    
    if (rc == ERR_OK && strlen(buf_last) > 0)
    {
        strncpy(stud->lastname, buf_last, LASTNAME_LEN);
        stud->lastname[LASTNAME_LEN - 1] = 0;
    }
    else
        rc = ERR_IO;
    
    // Читаем оценки
    if (fscanf(f_txt, "%" SCNu32"%" SCNu32"%" SCNu32"%" SCNu32, &(stud->grades[0]), &(stud->grades[1]), &(stud->grades[2]), &(stud->grades[3])) != 4)
        rc = ERR_IO;
    // Удаляем оставшийся '\n'
    if (rc == ERR_OK)
        fscanf(f_txt, "%c", buf_last);
    
    return rc;
}
