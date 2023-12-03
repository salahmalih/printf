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
            flags_t flags;
            int (*printer)(va_list, flags_t *);

            format++;
            get_flag(*format, &flags);

            while (get_flag(*format, &flags))
                format++;

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

            format++;
        }
        else
        {
            count += _putchar(*format);
            format++;
        }
    }

    va_end(args);

    return count;
}