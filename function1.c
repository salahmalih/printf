#include "main.h"

/**
 * print_int - Prints an integer
 * @l: Argument list
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_int(va_list l, flags_t *f)
{
    int n = va_arg(l, int);

    if (f->plus)
    {
        if (n >= 0)
            _putchar('+');
    }
    else if (f->space)
    {
        if (n >= 0)
            _putchar(' ');
    }

    return count_digit(n) + print_unsigned_helper(n, f, 10);
}

/**
 * count_digit - Counts the number of digits in an integer
 * @i: The integer
 * Return: Number of digits
 */
int count_digit(int i)
{
    int count = 0;

    if (i == 0)
        return 1;

    while (i != 0)
    {
        i /= 10;
        count++;
    }

    return count;
}

/**
 * print_unsigned - Prints an unsigned integer
 * @l: Argument list
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_unsigned(va_list l, flags_t *f)
{
    return print_unsigned_helper(va_arg(l, unsigned int), f, 10);
}

/**
 * print_unsigned_helper - Helper function to print an unsigned integer
 * @n: The unsigned integer
 * @f: Pointer to flags structure
 * @base: The number base for conversion
 * Return: Number of characters printed
 */
int print_unsigned_helper(unsigned int n, flags_t *f, int base)
{
    char *str = convert(n, base, 0);

    if (!str)
        return -1;

    int len = _puts(str);
    free(str);

    return len;
}

/**
 * print_binary - Prints a binary number
 * @l: Argument list
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_binary(va_list l, flags_t *f)
{
    return print_unsigned_helper(va_arg(l, unsigned int), f, 2);
}
