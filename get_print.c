#include "main.h"
/**
 * get_print - Selects the printing function based on the format specifier
 * @s: The format specifier character
 * Return: Pointer to the printing function, or NULL if not found
 */
int (*get_print(char s))(va_list, flags_t *)
{
    fmt_t fmt_types[] = {
        {'c', print_char}, {'s', print_string}, {'%', print_percent},
        {'i', print_int}, {'d', print_int}, {'b', print_binary},
        {'u', print_unsigned}, {'o', print_octal}, {'x', print_hex},
        {'X', print_hex_big}, {'p', print_pointer}, {'S', print_non_printable},
        {'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}};

    int i = 0;

    while (fmt_types[i].specifier != '\0')
    {
        if (fmt_types[i].specifier == s)
            return (fmt_types[i].printer);
        i++;
    }

    return (NULL); // Format specifier not found
}