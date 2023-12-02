#include "main.h"

/**
 * print_int - Prints an integer
 * @l: va_list containing the integer
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_int(va_list l, flags_t *f)
{
    int n = va_arg(l, int);

    if (f->plus && n >= 0)
        _putchar('+');
    else if (f->space && n >= 0)
        _putchar(' ');

    print_number(n);

    return count_digit(n) + ((n < 0) ? 1 : 0);
}

/**
 * print_unsigned - Prints an unsigned integer
 * @l: va_list containing the unsigned integer
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_unsigned(va_list l, flags_t *f)
{
    unsigned int u = va_arg(l, unsigned int);

    print_number(u);

    return count_digit(u);
}

/**
 * print_hex - Prints a hexadecimal number in lowercase
 * @l: va_list containing the hexadecimal number
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_hex(va_list l, flags_t *f)
{
    unsigned int hex = va_arg(l, unsigned int);

    char *str = convert(hex, 16, 1);

    if (!str)
        return -1;

    _puts(str);
    free(str);

    return count_digit(hex);
}

/**
 * print_hex_big - Prints a hexadecimal number in uppercase
 * @l: va_list containing the hexadecimal number
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_hex_big(va_list l, flags_t *f)
{
    unsigned int hex = va_arg(l, unsigned int);

    char *str = convert(hex, 16, 0);

    if (!str)
        return -1;

    _puts(str);
    free(str);

    return count_digit(hex);
}
