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
        return -1; /* Conversion failed */

    count += _puts(converted);

    free(converted);

    return (count);
}