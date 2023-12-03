#include "main.h"

/**
 * _putchar - Writes a character to the standard output
 * @c: The character to write
 * Return: On success, 1 is returned. On error, -1 is returned.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}

/**
 * _puts - Writes a string to the standard output
 * @str: The string to write
 * Return: On success, the number of characters written is returned.
 * On error, -1 is returned.
 */
int _puts(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (_putchar(str[i]) == -1)
            return (-1);
        i++;
    }
    return (i);
}


/**
 * _strlen - Computes the length of a string
 * @str: The input string
 * Return: The length of the string
 */
int _strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;

    return (len);
}
/**
 * convert - Converts a number to a specified base and returns the result as a string
 * @num: The number to convert
 * @base: The base to convert to
 * @lowercase: Flag to indicate whether to use lowercase (1) or uppercase (0) letters
 * Return: A pointer to the converted string, or NULL on failure
 */
char *convert(unsigned long int num, int base, int lowercase)
{
    static char buffer[50];
    char *ptr = &buffer[49];
    static char *rep;

    rep = (lowercase)
        ? "0123456789ABCDEF"
        : "0123456789abcdef";

    *ptr = '\0';
    do {
        *--ptr = rep[num % base];
        num /= base;
    } while (num != 0);

    return (ptr);
}
/**
 * convert_and_print - Converts a number to a specified base and prints it
 * @num: The number to convert
 * @base: The base to convert to
 * @uppercase: Flag to indicate whether to print in uppercase (1) or lowercase (0)
 * Return: Number of characters printed
 */
int convert_and_print(unsigned long int num, int base, int uppercase)
{
    char *converted;
    int count = 0;

    converted = convert(num, base, uppercase);
    if (converted == NULL)
        return -1;

    count += _puts(converted);

    return (count);
}
