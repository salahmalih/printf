#include "main.h"

/**
 * print_reverse - Prints a reversed string
 * @l: Argument list
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_reverse(va_list l, flags_t *f)
{
    UNUSED(f);
    char *str = va_arg(l, char *);
    int len = _strlen(str) - 1;

    while (len >= 0)
    {
        _putchar(str[len]);
        len--;
    }

    return _strlen(str);
}

/**
 * print_non_printable - Prints non-printable characters in hexadecimal
 * @l: Argument list
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_non_printable(va_list l, flags_t *f)
{
    int count = 0;
    char *str = va_arg(l, char *);

    if (!str)
        return -1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            _putchar('\\');
            _putchar('x');
            count += 2;
            count += print_hex_helper(str[i], 1);
        }
        else
        {
            _putchar(str[i]);
            count++;
        }
    }

    return count;
}

/**
 * print_pointer - Prints a pointer address
 * @l: Argument list
 * @f: Pointer to flags structure
 * Return: Number of characters printed
 */
int print_pointer(va_list l, flags_t *f)
{
    UNUSED(f); // Fix unused parameter warning
    void *ptr = va_arg(l, void *);
    unsigned long int address = (unsigned long int)ptr;

    _putchar('0');
    _putchar('x');

    return print_hex_helper(address, 0) + 2;
}

/**
 * print_hex_helper - Helper function to print a hexadecimal number
 * @n: The number to print
 * @uppercase: Flag to print in uppercase
 * Return: Number of characters printed
 */
int print_hex_helper(unsigned long int n, int uppercase)
{
    char *hex_digits = (uppercase) ? "0123456789ABCDEF" : "0123456789abcdef";
    int count = 0;

    if (n / 16)
        count += print_hex_helper(n / 16, uppercase);

    _putchar(hex_digits[n % 16]);
    count++;

    return count;
}
