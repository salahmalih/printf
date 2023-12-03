#include "main.h"

/**
 * print_address - Prints the address of a pointer
 * @l: The argument list containing the pointer to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_address(va_list l, flags_t *f)
{
	int count = 0;
	unsigned long int addr = va_arg(l, unsigned long int);

	UNUSED(f);
	if (!addr)
		return (_puts("(nil)"));
	count += _puts("0x");
	count += convert_and_print((unsigned long int)addr, 16, 0);
	return (count);
}


/**
 * print_bigS - Prints a string with non-printable characters
 * @l: The argument list containing the string to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_bigS(va_list l, flags_t *f)
{
	char *str;
	char *rs;
	int count = 0;

	UNUSED(f);
	str = va_arg(l, char *);
	if (str == NULL)
		return (_puts("(null)"));

	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			_puts("\\x");
			count += 2;
			rs = convert((unsigned char)(*str), 16, 1);
			if (!rs[1])
				count += _putchar('0');
			count += _puts(rs);
		}
		else
		{
			count += _putchar(*str);
		}
		str++;
	}
	return (count);
}
/**
 * print_rev - Prints a reversed string
 * @l: The argument list containing the string to print
 * @f: Pointer to the flags structure
 * Return: Number of characters printed
 */
int print_rev(va_list l, flags_t *f)
{
	char *st;
	int i, length;

	UNUSED(f);
	st = va_arg(l, char *);

	if (st == NULL)
		return (_puts("(null)"));

	length = _strlen(st);

	for (i = length - 1; i >= 0; i--)
	{
		_putchar(st[i]);
	}

	return (length);
}
