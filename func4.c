#include "main.h"
/**
 * rot13 - Encodes a character using ROT13 algorithm
 * @c: The character to encode
 * Return: The encoded character
 */
char rot13(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
    {
        if ((c >= 'A' && c <= 'Z' && c + 13 > 'Z') || (c >= 'a' && c <= 'z' && c + 13 > 'z'))
        {
            return c - 13;
        }
        else
        {
            return c + 13;
        }
    }

    return (c);
}

/**
 * print_rot13 - Prints a string in ROT13 encoding
 * @l: The argument list containing the string to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_rot13(va_list l, flags_t *f)
{
    char *str;
    int count = 0;

	(void)f;
	str = va_arg(l, char *);
    if (str == NULL)
        return _puts("(null)");

    while (*str)
    {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
        {
            count += _putchar(rot13(*str));
        }
        else
        {
            count += _putchar(*str);
        }
        str++;
    }

    return (count);
}