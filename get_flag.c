#include "main.h"

/**
 * get_flag - Calculates active flags based on a character
 * @s: The character representing a flag
 * @f: Pointer to the flags structure to update
 * Return: 1 if successful, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
    int success = 1;

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
        success = 0; /* Not a valid flag character */
        break;
    }

    return success;
}
