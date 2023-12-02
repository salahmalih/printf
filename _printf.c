#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 * @...: Additional arguments for format specifiers
 * Return: Number of characters printed (excluding null byte)
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
            format++;
            if (*format == '\0')
                break;

            flags_t flags = {0, 0, 0, 0, 0, 0, 0};
            while (get_flag(*format, &flags))
                format++;

            int (*printer)(va_list, flags_t *) = get_print(*format);
            if (printer)
                count += printer(args, &flags);
            else
            {
                _putchar('%');
                _putchar(*format);
                count += 2;
            }
        }
        else
        {
            _putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}
