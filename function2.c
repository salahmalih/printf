#include "main.h"

/**
 * print_address - Prints the address of a pointer
 * @l: The argument list containing the pointer to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_address(va_list l, flags_t *f)
{
    int count = 0;
    void *addr = va_arg(l, void *);

    UNUSED(f);
    count += _puts("0x");
    count += convert_and_print((uintptr_t)addr, 16, 0);

    return (count);
}


/**
 * print_bigS - Prints a string with non-printable characters
 * @l: The argument list containing the string to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_bigS(va_list l, flags_t *f)
{
    char *str ;
    int count = 0;

	UNUSED(f);
	str = va_arg(l, char *);
    if (str == NULL)
        return _puts("(null)");

    while (*str)
    {
        if (*str < 32 || *str >= 127)
        {
            count += _putchar('\\');
            count += _putchar('x');
            count += convert_and_print(((unsigned char)(*str)), 16, 1);
        }
        else
        {
            count += _putchar(*str);
        }
        str++;
    }

    return (count);
}

#include "main.h"

/**
 * print_rev - Prints a reversed string
 * @l: The argument list containing the string to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_rev(va_list l, flags_t *f)
{
    int count = 0;
    char *str = va_arg(l, char *);

    if (str == NULL)
        str = "(null)";

    count += _puts_reverse(str);

    return (count);
}

/**
 * _puts_reverse - Prints a string in reverse
 * @str: The string to print in reverse
 * Return: Number of characters printed
 */
int _puts_reverse(char *str)
{
    int count = 0;
    if (str == NULL)
        return _puts("(null)");

    int length = _strlen(str);

    for (int i = length - 1; i >= 0; i--)
    {
        count += _putchar(str[i]);
    }

    return (count);
}
