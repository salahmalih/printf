#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/**
 * struct flags - Struct to hold flags for printf
 * @plus: Flag for '+' character
 * @space: Flag for ' ' character
 * @hash: Flag for '#' character
 * @zero: Flag for '0' character
 * @minus: Flag for '-' character
 * @width: Field width
 * @precision: Precision specifier
 */
struct flags
{
	int plus;
	int space;
	int hash;
	int zero;
	int minus;
	int width;
	int precision;
};
typedef struct flags flags_t;

/**
 * struct format - Struct to function pointers for printf format specifiers
 * @specifier: Format specifier character
 * @printer: Function pointer to the corresponding printing function
 */
struct format
{
	char specifier;
	int (*printer)(va_list, flags_t *);
};
typedef struct format fmt_t;

/* print_nums */
int print_int(va_list l, flags_t *f);
int print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* print_bases */
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);
int convert_and_print(unsigned long int num, int base, int uppercase);
/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, flags_t *);

/* get_flag */
int get_flag(char s, flags_t *f);

/* print_alpha */
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* print_custom */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);

/* print_address */
int print_address(va_list l, flags_t *f);

/* print_percent */
int print_percent(va_list l, flags_t *f);

/* tools */
int _strlen(char *str);
void init_flags(flags_t *flags);
#endif
