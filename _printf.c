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
    const char *p;
    flags_t flags = {0, 0, 0, 0, 0, 0, 0};
    int (*printer)(va_list, flags_t *);

    va_start(args, format);
    if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
    for (p = format; *p; p++)
    {
        if (*p == '%')
            {
                p++;
                if (*p == '%')
                {
                    count += _putchar('%');
                    continue;
                }
                while (get_flag(*p, &flags))
                    p++;
                printer = get_print(*p);
                count += (printer)
                    ? printer(args, &flags)
                    : _printf("%%%c", *p);
            } else
                count += _putchar(*p);
    }
    _putchar(-1);
    va_end(args);
    return (count);
}