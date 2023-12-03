#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @l: The argument list containing the unsigned integer to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_unsigned(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str;

	str = convert(u, 10, 0);
	UNUSED(f);
	return (_puts(str));
}

/**
 * print_octal - Prints an octal number
 * @l: The argument list containing the octal number to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_octal(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	char *str;
	int count = 0;

	str = convert(num, 8, 0);
	if (f->hash == 1 && str[0] != '0')
		count += _putchar('0');
	count += _puts(str);
	return (count);
}

/**
 * print_hex - Prints a hexadecimal number in lowercase
 * @l: The argument list containing the hexadecimal number to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_hex(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	int count = 0;

	if (f->hash == 1 && num != 0)
		count += _puts("0x");

	count += convert_and_print(num, 16, 0);
	return (count);
}
/**
 * print_hex_big - Prints a hexadecimal number in uppercase
 * @l: The argument list containing the hexadecimal number to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_hex_big(va_list l, flags_t *f)
{
	unsigned int num = va_arg(l, unsigned int);
	int count = 0;

	if (f->hash == 1 && num != 0)
		count += _puts("0X");

	count += convert_and_print(num, 16, 1);
	return (count);
}
/**
 * print_char - Prints a character
 * @l: The argument list containing the character to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_char(va_list l, flags_t *f)
{
	int count = 0;

	UNUSED(f);
	count += _putchar(va_arg(l, int));

	return (count);
}
