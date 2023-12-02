#include "main.h"

/**
 * get_flag - Gets the active flags from the format specifier
 * @s: The format specifier character
 * @f: Pointer to flags structure to store active flags
 * Return: 1 if flag is active, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
    int flag_active = 1;

    switch (s)
    {
        case '+':
            f->plus = 1;
            break;
        case ' ':
            f->space = 1;
            break;
        case '#':
            f->hash = 1;
            break;
        case '0':
            f->zero = 1;
            break;
        case '-':
            f->minus = 1;
            break;
        default:
            flag_active = 0;
            break;
    }

    return flag_active;
}