#include "main.h"

/**
 * get_flag - Updates the flags structure based on a format specifier
 * @s: The format specifier character
 * @f: Pointer to the flags structure to be updated
 * Return: 0 on success, -1 on failure
 */
int get_flag(char s, flags_t *f)
{
	int count = -1;

	switch (s)
	{
		case '+':
			f->plus = 1;
			count = 1;
			break;
		case ' ':
			f->space = 1;
			count = 1;
			break;
		case '#':
			f->hash = 1;
			count = 1;
			break;
		case '0':
			f->zero = 1;
			count = 1;
			break;
		case '-':
			f->minus = 1;
			count = 1;
			break;
	}

	return (count);
}
