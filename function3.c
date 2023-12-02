#include "main.h"

/**
 * print_rev - Prints a reversed string
 * @l: va_list containing the string
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_rev(va_list l, flags_t *f)
{
    char *str = va_arg(l, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    count += _strlen(str);

    while (*str)
    {
        _putchar(*(str + count - 1));
        count--;
    }

    return count;
}

/**
 * print_percent - Prints a percent character
 * @l: va_list (unused)
 * @f: Pointer to flags structure
 * Return: Always 1 (number of characters printed)
 */
int print_percent(va_list l, flags_t *f)
{
    (void)l; /* Unused parameter */
    _putchar('%');
    return 1;
}

/**
 * print_rot13 - Prints a string in ROT13 encoding
 * @l: va_list containing the string
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_rot13(va_list l, flags_t *f)
{
    char *str = va_arg(l, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
        {
            _putchar(rotate_13(*str));
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

/**
 * rotate_13 - Applies ROT13 encoding to a character
 * @c: The character to encode
 * Return: The encoded character
 */
char rotate_13(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        char base = (c >= 'a' && c <= 'z') ? 'a' : 'A';
        return ((c - base + 13) % 26) + base;
    }
    return c;
}

/**
 * print_number - Prints an integer without considering flags
 * @n: The integer to print
 */
void print_number(int n)
{
    if (n < 0)
    {
        _putchar('-');
        n = -n;
    }

    if (n / 10)
        print_number(n / 10);

    _putchar((n % 10) + '0');
}
