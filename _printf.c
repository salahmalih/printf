#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string
 * @...: Variable arguments
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	flags_t flags;
	int (*printer)(va_list, flags_t *);

	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			flags.plus = 0;
			flags.space = 0;
			flags.hash = 0;
			flags.zero = 0;
			flags.minus = 0;
			flags.width = 0;
			flags.precision = 0;
			format++;
			while (get_flag(*format, &flags) == 0)
			{
				format++;
			}
			printer = get_print(*format);

			if (printer != NULL)
			{
				count += printer(args, &flags);
			}
			else
			{
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
