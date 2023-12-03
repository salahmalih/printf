#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @l: The argument list containing the unsigned integer to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_unsigned(va_list l, flags_t *f)
{
    unsigned int num;
    int count = 0;

    UNUSED(f);
    num = va_arg(l, unsigned int);
    count += print_number_unsigned(num);

    return (count);
}

/**
 * print_number_unsigned - Prints an unsigned integer
 * @n: The unsigned integer to print
 * Return: Number of characters printed
 */
int print_number_unsigned(unsigned int n)
{
    int count = 0;

    count += convert_and_print((unsigned long int)n, 10, 0);

    return (count);
}


/**
 * print_octal - Prints an octal number
 * @l: The argument list containing the octal number to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_octal(va_list l, flags_t *f)
{
    unsigned int octal;
    int count = 0;

    octal = va_arg(l, unsigned int);
    if (f->hash && octal != 0)
        count += _putchar('0');

    count += print_number(octal);

    return (count);
}

/**
 * print_hex - Prints a hexadecimal number in lowercase
 * @l: The argument list containing the hexadecimal number to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_hex(va_list l, flags_t *f)
{
    unsigned int hex;
    int count = 0;

    UNUSED(f);
    hex = va_arg(l, unsigned int);
    count += convert_and_print(hex, 16, 0);

    return (count);
}

/**
 * print_hex_big - Prints a hexadecimal number in uppercase
 * @l: The argument list containing the hexadecimal number to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_hex_big(va_list l, flags_t *f)
{
    unsigned int hex;
    int count = 0;

    UNUSED(f);
    hex = va_arg(l, unsigned int);
    count += convert_and_print(hex, 16, 1);

    return (count);
}

/**
 * print_char - Prints a character
 * @l: The argument list containing the character to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_char(va_list l, flags_t *f)
{
    char c;
    int count = 0;

    UNUSED(f);
    c = va_arg(l, int);
    count += _putchar(c);

    return (count);
}
