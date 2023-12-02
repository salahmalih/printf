#include "main.h"

/**
 * print_binary - Prints a binary number
 * @l: va_list containing the binary number
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_binary(va_list l, flags_t *f)
{
    unsigned int binary = va_arg(l, unsigned int);

    char *str = convert(binary, 2, 1);

    if (!str)
        return -1;

    _puts(str);
    free(str);

    return count_digit(binary);
}

/**
 * print_octal - Prints an octal number
 * @l: va_list containing the octal number
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_octal(va_list l, flags_t *f)
{
    unsigned int octal = va_arg(l, unsigned int);

    char *str = convert(octal, 8, 1);

    if (!str)
        return -1;

    _puts(str);
    free(str);

    return count_digit(octal);
}

/**
 * print_address - Prints an address in hexadecimal
 * @l: va_list containing the address
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_address(va_list l, flags_t *f)
{
    void *addr = va_arg(l, void *);

    char *str = convert((unsigned long)addr, 16, 1);

    if (!str)
        return -1;

    _puts("0x");
    _puts(str);
    free(str);

    return count_digit((unsigned long)addr) + 2;
}

/**
 * print_bigS - Prints a string with non-printable characters escaped
 * @l: va_list containing the string
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_bigS(va_list l, flags_t *f)
{
    char *str = va_arg(l, char *);
    int count = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        if (*str < 32 || *str >= 127)
        {
            _putchar('\\');
            _putchar('x');
            count += 2;
            count += print_hex_big_char(*str);
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
 * print_hex_big_char - Prints a character in uppercase hexadecimal
 * @c: The character to print
 * Return: Number of characters printed
 */
int print_hex_big_char(char c)
{
    char *hex = convert(c, 16, 0);
    int count = 0;

    if (!hex)
        return -1;

    if (hex[1] == '\0')
    {
        _putchar('0');
        count++;
    }

    _puts(hex);
    count += _strlen(hex);
    free(hex);

    return count;
}
