#include "main.h"
/**
 * get_print - Selects the right printing function based on the format specifier
 * @s: The format specifier character
 * Return: A function pointer to the corresponding printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
    fmt_t func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].printer == s)
			return (func_arr[i].printer);
	return (NULL);
}
