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

    va_start(args, format);

    while (format && *format)
    {
        if (*format == '%')
        {
            flags_t flags = {0, 0, 0, 0, 0, 0, 0};
            int (*printer)(va_list, flags_t *) = get_print(*format);

            if (printer != NULL)
            {
                count += printer(args, &flags);
            }
            else
            {
                count += _putchar('%');
                count += _putchar(*(format));
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