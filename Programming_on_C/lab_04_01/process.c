#include "process.h"

const char *my_strpbrk(const char *s, const char *accept)
{
    for (const char *s_ch = s; *s_ch != '\0'; s_ch++)
    {
        for (const char *accept_ch = accept; *accept_ch != '\0'; accept_ch++)
        {
            if (*s_ch == *accept_ch)
                return s_ch;
        }
    }
    return NULL;
}

size_t my_strspn(const char *s, const char *accept)
{
    size_t length = 0;

    for (const char *s_ch = s; *s_ch != '\0'; s_ch++)
    {
        bool flag = 0;
        for (const char *accept_sh = accept; *accept_sh != '\0'; accept_sh++)
        {
            if (*accept_sh == *s_ch)
                flag = 1;
        }

        if (!flag)
            return length;
        
        length++;
    }
    return length;
}

size_t my_strcspn(const char *s, const char *reject)
{
    size_t length = 0;

    for (const char *s_ch = s; *s_ch != '\0'; s_ch++)
    {
        for (const char *reject_sh = reject; *reject_sh != '\0'; reject_sh++)
        {
            if (*reject_sh == *s_ch)
                return length;
        }
        length++;
    }
    return length;
}

const char *my_strchr(const char *s, int c)
{
    if (s == NULL)
        return s;
    
    for (const char *s_ch = s; s_ch <= s + strlen(s); s_ch++)
    {
        if (*s_ch == c)
            return s_ch;
    }
    return NULL;
}

const char *my_strrchr(const char *s, int c)
{
    if (s == NULL)
        return NULL;
    
    for (const char *s_ch = s + strlen(s); s_ch >= s; s_ch--)
    {
        if (*s_ch == c)
            return s_ch;
    }
    return NULL;
}

size_t test(void)
{
    size_t count_failed_tests = 0;

    // Один символ в строке 
    if (my_strpbrk("Hello, World!", "o") != strpbrk("Hello, World!", "o"))
        count_failed_tests++;
    // Два символа в строке, один раньше другого
    if (my_strpbrk("Hello, World!", "o") != strpbrk("Hello, World!", "o"))
        count_failed_tests++;
    // Символа не в строке
    if (my_strpbrk("Hello, World!", "a") != strpbrk("Hello, World!", "a"))
        count_failed_tests++;


    // Подстрока из 1 символа в начале 
    if (my_strspn("Hello, World!", "H") != strspn("Hello, World!", "H"))
        count_failed_tests++;
    // Подстрока из 1 символа в середине
    if (my_strspn("Hello, World!", "W") != strspn("Hello, World!", "W"))
        count_failed_tests++;
    // Подстрока из 1 символа в конце
    if (my_strspn("Hello, World!", "!") != strspn("Hello, World!", "!"))
        count_failed_tests++;
    // Подстрока из нескольких символов в начале 
    if (my_strspn("Hello, World!", "Hel") != strspn("Hello, World!", "Hel"))
        count_failed_tests++;
    // Подстрока из нескольких символов в середине
    if (my_strspn("Hello, World!", "o, W") != strspn("Hello, World!", "o, W"))
        count_failed_tests++;
    // Подстрока из нескольких символов в конце
    if (my_strspn("Hello, World!", "ld!") != strspn("Hello, World!", "ld!"))
        count_failed_tests++;
    // Все символы подстроки в строке
    if (my_strspn("Hello, World!", "Hello, World!") != strspn("Hello, World!", "Hello, World!"))
        count_failed_tests++;
    // Подстроки нет в строке
    if (my_strspn("Hello, World!", "abc") != strspn("Hello, World!", "abc"))
        count_failed_tests++;
    // Пустая подстрока
    if (my_strspn("Hello, World!", "") != strspn("Hello, World!", ""))
        count_failed_tests++;

    
    // Пустая подстрока
    if (my_strcspn("Hello, World!", "") != strcspn("Hello, World!", ""))
        count_failed_tests++;
    // Исключаемый символ в начале строки
    if (my_strcspn("Hello, World!", "Habd") != strcspn("Hello, World!", "Habd"))
        count_failed_tests++;
    // Символа нет в строке
    if (my_strcspn("Hello, World!", "ab") != strcspn("Hello, World!", "ab"))
        count_failed_tests++;



    // 2 символа один раньше другого
    if (my_strchr("Hello, World!", 'o') != strchr("Hello, World!", 'o'))
        count_failed_tests++;
    // нулевой байт
    if (my_strchr("Hello, World!", '\0') != strchr("Hello, World!", '\0'))
        count_failed_tests++;
    // Символа нет в строке
    if (my_strchr("Hello, World!", 'a') != strchr("Hello, World!", 'a'))
        count_failed_tests++;
    // Символ в строке
    if (my_strchr("Hello, World!", 'e') != strchr("Hello, World!", 'e'))
        count_failed_tests++;

    
    // 2 символа один раньше другого
    if (my_strrchr("Hello, World!", 'o') != strrchr("Hello, World!", 'o'))
        count_failed_tests++;
    // нулевой байт
    if (my_strrchr("Hello, World!", '\0') != strrchr("Hello, World!", '\0'))
        count_failed_tests++;
    // Символа нет в строке
    if (my_strrchr("Hello, World!", 'a') != strrchr("Hello, World!", 'a'))
        count_failed_tests++;
    // Символ в строке
    if (my_strrchr("Hello, World!", 'e') != strrchr("Hello, World!", 'e'))
        count_failed_tests++;
    
    return count_failed_tests;
}
