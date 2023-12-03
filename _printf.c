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
     flags_t flags = {0, 0, 0, 0, 0, 0, 0};
    int (*printer)(va_list, flags_t *);

    va_start(args, format);
    printer= get_print(*format);
    if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
    while (format && *format)
    {
        if (*format == '%')
            {
                format++;
                if (*format == '%')
                {
                    count += _putchar('%');
                    continue;
                }
                while (get_flag(*format, &flags))
                    format++;
                printer = get_print(*format);
                count += (printer)
                    ? printer(args, &flags)
                    : _printf("%%%c", *format);
            } else
                count += _putchar(*format);
    }
    _putchar(-1);
    va_end(args);
    return (count);
}