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
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 * Return: A pointer to the duplicated string
 */
char *_strdup(const char *str)
{
    int len = 0;
    char *dup_str;

    if (str == NULL)
        return NULL;

    while (str[len] != '\0')
        len++;

    dup_str = malloc((len + 1) * sizeof(char));
    if (dup_str == NULL)
        return NULL;

    for (int i = 0; i <= len; i++)
        dup_str[i] = str[i];

    return dup_str;
}

/**
 * _strlen - Calculates the length of a string
 * @str: The string
 * Return: The length of the string
 */
int _strlen(const char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;

    return len;
}

/**
 * _strncat - Concatenates n characters from a string
 * @dest: The destination string
 * @src: The source string
 * @n: The number of characters to concatenate
 * Return: A pointer to the concatenated string
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
