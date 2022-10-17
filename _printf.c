#include "main.h"
/**
 * handle_conversion - prints something based on the format passed to it
 * @format: the format for specifier
 * Return: a number
 */
int (*handle_conversion(const char *format))(va_list params, int *counter)
{
	int i;

	convert_t functions[] = {
		{'c', print_c},
		{'s', print_s},
		{'d', print_d},
		{'i', print_i},
		{0, NULL}
	};

	for (i = 0; functions[i].callback; i++)
	{
		if (functions[i].specifier == *format)
			return (functions[i].callback);
	}

	return (0);
}
/**
 * _printf - prints a string base on a set of conversion specifiers
 * @format: pointer to the string to be printed which also cinrains specifiers
 * @...: list of arguments that are printed according to a specifier
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list params;
	int i, count = 0;

	va_start(params, format);

	for (i = 0; *(format + i) != '\0'; i++)
	{
		if (*(format + i) == '%')
		{
			if (*(format + i + 1) == '%')
			{
				write(1, format + ++i, 1);
				count++;
				continue;
			}
			handle_conversion(format + ++i)(params, &count);
		}
		else
		{

			write(1, format + i, 1);
			count++;
		}
	}

	return (count);
}
