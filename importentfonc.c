#include "main.h"

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * Return: On success, returns the number of characters written, otherwise -1
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _puts - Writes a string to stdout
 * @str: The string to print
 * Return: On success, returns the number of characters written, otherwise -1
 */
int _puts(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        _putchar(str[len]);
        len++;
    }
    return len;
}


/**
 * _strlen - Calculates the length of a string
 * @str: The string
 * Return: The length of the string
 */
int _strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;

    return len;
}
