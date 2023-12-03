#include "main.h"
/**
 * get_print - Selects the right printing function based on the format specifier
 * @s: The format specifier character
 * Return: A function pointer to the corresponding printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
    fmt_t fmt_types[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'i', print_int},
        {'d', print_int},
        {'b', print_binary},
        {'u', print_unsigned},
        {'o', print_octal},
        {'x', print_hex},
        {'X', print_hex_big},
        {'p', print_address},
        {'S', print_bigS},
        {'r', print_rev},
        {'R', print_rot13},
        {'\0', NULL}};

    int i = 0;

    while (fmt_types[i].specifier != '\0')
    {
        if (fmt_types[i].specifier == s)
            return (fmt_types[i].printer);
        i++;
    }

    return (NULL);
}