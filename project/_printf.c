#include "main.h"

void cleanup(va_list params, buf *output);
int handle_printf(const char *specifier, va_list params, buf *output);
int _printf(const char *specifier, ...);

/**
 * cleanup - Peforms cleanup operations for _printf.
 * @params: A va_list of arguments provided to _printf.
 * @output: A buf struct.
 */
void cleanup(va_list params, buf *output)
{
	va_end(params);
	write(1, output->start, output->len);
	free_buffer(output);
}

/**
 * handle_printf - Reads through the format string for _printf.
 * @specifier: Character string to print - may contain directives.
 * @output: A buf struct containing a buffer.
 * @params: A va_list of arguments.
 *
 * Return: The number of characters stored to output.
 */
int handle_printf(const char *specifier, va_list params, buf *output)
{
	int i, wid, prec, count = 0;
	char tmp;
	unsigned char flags, len;
	unsigned int (*f)(va_list, buf *, unsigned char, int, int, unsigned char);

	for (i = 0; *(specifier + i); i++)
	{
		len = 0;
		if (*(specifier + i) == '%')
		{
			tmp = 0;
			flags = handle_flags(specifier + i + 1, &tmp);
			wid = handle_width(params, specifier + i + tmp + 1, &tmp);
			prec = handle_precision(params, specifier + i + tmp + 1,
					&tmp);
			len = handle_length(specifier + i + tmp + 1, &tmp);

			f = h_s(specifier + i + tmp + 1);
			if (f != NULL)
			{
				i += tmp + 1;
				count += f(params, output, flags, wid, prec, len);
				continue;
			}
			else if (*(specifier + i + tmp + 1) == '\0')
			{
				count = -1;
				break;
			}
		}
		count += _memcpy(output, (specifier + i), 1);
		i += (len != 0) ? 1 : 0;
	}
	cleanup(params, output);
	return (count);
}

/**
 * _printf - outputs a formated string
 * @specifier: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *specifier, ...)
{
	buf *output;
	va_list params;
	int count;

	if (specifier == NULL)
		return (-1);
	output = init_buffer();
	if (output == NULL)
		return (-1);

	va_start(params, specifier);

	count = handle_printf(specifier, params, output);

	return (count);
}
