#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: The format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return -1; /* Invalid format string */

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format)
            {
                flags_t flags = {0, 0, 0, 0, 0, 0, 0}; /* Initialize flags */
                int (*printer)(va_list, flags_t *);

                /* Process flags */
                while (get_flag(*format, &flags))
                    format++;

                /* Get printing function */
                printer = get_print(*format);

                if (printer != NULL)
                    count += printer(args, &flags);
                else
                    _putchar('%'); /* Print the '%' character */

                format++;
            }
        }
        else
        {
            _putchar(*format);
            count++;
            format++;
        }
    }

    va_end(args);

    return count;
}
