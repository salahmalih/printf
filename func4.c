// func4.c

#include "main.h"

int print_rot13(va_list l, flags_t *f)
{
    UNUSED(f); // Fix unused parameter warning
    char *str = va_arg(l, char *);
    int count = 0;

    while (*str)
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            char base = (*str >= 'a') ? 'a' : 'A';
            _putchar(((char)(*str - base + 13) % 26) + base);
            count++;
        }
        else
        {
            _putchar(*str);
            count++;
        }
        str++;
    }

    return count;
}

int print_rot13string(va_list l, flags_t *f)
{
    UNUSED(f); // Fix unused parameter warning
    char *str = va_arg(l, char *);
    int count = 0;

    if (!str)
        return -1;

    while (*str)
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            char base = (*str >= 'a') ? 'a' : 'A';
            _putchar(((char)(*str - base + 13) % 26) + base);
            count++;
        }
        else
        {
            if (*str < 32 || *str >= 127)
            {
                _putchar('\\');
                _putchar('x');
                count += 2;
                count += print_hex_helper(*str, 1);
            }
            else
            {
                _putchar(*str);
                count++;
            }
        }
        str++;
    }

    return count;
}
