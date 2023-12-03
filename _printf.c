#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: Format string containing the characters and specifiers.
 * Return: Length of the formatted output string.
 */
int _printf(const char *format, ...)
{
    int (*printer)(va_list, flags_t *);
    const char *p;
    va_list arguments;
    flags_t flags = {0, 0, 0, 0, 0, 0, 0};  // Initialize all flags to 0.

    register int count = 0;

    va_start(arguments, format);

    if (!format || (format[0] == '%' && !format[1]))
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

            // Reset flags for each new specifier.
            flags = (flags_t){0, 0, 0, 0, 0, 0, 0};

            // Process flags.
            while (get_flag(*p, &flags))
                p++;

            printer = get_print(*p);

            if (printer != NULL)
                count += printer(arguments, &flags);
            else
                count += _printf("%%%c", *p);
        }
        else
        {
            count += _putchar(*p);
        }
    }

    va_end(arguments);

    return (count);
}
