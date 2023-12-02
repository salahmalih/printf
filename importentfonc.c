#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 * Return: 1 on success, -1 on error
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _puts - Writes a string to stdout
 * @str: The string to print
 */
int _puts(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (_putchar(str[i]) == -1)
            return -1;
        i++;
    }
    return i;
}

/**
 * _strdup - Duplicates a string using malloc
 * @str: The string to duplicate
 * Return: Pointer to the duplicated string or NULL on failure
 */
char *_strdup(const char *str)
{
    char *dup;
    int i, len = 0;

    if (!str)
        return NULL;

    while (str[len])
        len++;

    dup = malloc((len + 1) * sizeof(char));

    if (!dup)
        return NULL;

    for (i = 0; i <= len; i++)
        dup[i] = str[i];

    return dup;
}

/**
 * _strlen - Computes the length of a string
 * @str: The string
 * Return: Length of the string
 */
int _strlen(const char *str)
{
    int len = 0;

    while (str[len])
        len++;

    return len;
}

/**
 * _strncat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 * @n: The maximum number of characters to concatenate
 * Return: Pointer to the resulting string
 */
char *_strncat(char *dest, const char *src, int n)
{
    int dest_len = _strlen(dest);
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];

    dest[dest_len + i] = '\0';

    return dest;
}
