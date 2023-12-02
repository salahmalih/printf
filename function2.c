#include "main.h"

/**
 * print_hex - Prints a hexadecimal number
 * @l: Argument list
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_hex(va_list l, flags_t *f)
{
    return print_unsigned_helper(va_arg(l, unsigned int), f, 16);
}

/**
 * print_hex_big - Prints a hexadecimal number in uppercase
 * @l: Argument list
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_hex_big(va_list l, flags_t *f)
{
    UNUSED(f);
    char *str = convert(va_arg(l, unsigned long int), 16, 1);
    int len = _puts(str);
    free(str);

    return len;
}

/**
 * print_octal - Prints an octal number
 * @l: Argument list
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_octal(va_list l, flags_t *f)
{
    return print_unsigned_helper(va_arg(l, unsigned int), f, 8);
}

/**
 * print_string - Prints a string
 * @l: Argument list
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_string(va_list l, flags_t *f)
{
    char *str = va_arg(l, char *);
    int len = _puts(str);
    UNUSED(f);

    return len;
}
