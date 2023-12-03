#include "main.h"

/**
 * print_int - Prints an integer
 * @l: The argument list containing the integer to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_int(va_list l, flags_t *f)
{
	int num;
	int count = 0;

	num = va_arg(l, int);
	if (f->plus && num >= 0)
		count += _putchar('+');
	else if (f->space && num >= 0)
		count += _putchar(' ');

	count += print_number(num);

	return (count);
}

/**
 * print_number - Prints an integer
 * @n: The integer to print
 * Return: Number of characters printed
 */
int print_number(int n)
{
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}
	count += convert_and_print((unsigned int)n, 10, 0);

	return (count);
}

/**
 * print_binary - Prints a binary representation of an unsigned integer
 * @l: The argument list containing the unsigned integer to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_binary(va_list l, flags_t *f)
{
	unsigned int binary = va_arg(l, unsigned int);
	int count = 0;

	UNUSED(f);
	count += convert_and_print(binary, 2, 0);

	return (count);
}


/**
 * print_percent - Prints a percent character '%'
 * @l: The argument list (unused)
 * @f: Pointer to the flags structure (unused)
 * Return: Always returns 1 (the number of characters printed)
 */
int print_percent(va_list l, flags_t *f)
{
	UNUSED(l);
	UNUSED(f);

	return (_putchar('%'));
}
