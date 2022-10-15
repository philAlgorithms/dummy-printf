#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * check_char - checks if @arg is char
 * @arg: argument to compare
 * Return: returns 1 if arg is char, else 0.
 */
int check_char(va_list arg)
{
	char c = va_arg(arg, int);

	if ((c + '0') >= 0 && ((c + '0') <= '9'))
		return (0);
	return (c);
}
/**
 * _printf - prints characters to the console
 * @format: string format to print
 * Return: returns number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int arg_count = 0;
	int index = 0, c, index2 = 0;
	char buff[45];

	va_start(ap, format);

	while (format[index])
	{
		if (format[index] == '%' && format[index + 1] == 'c')
		{
			c = check_char(ap);
			if (c != 0)
			{
				buff[index2] = c;
				index += 2;
				index2++;
				arg_count += 1;
				continue;
			}
			else
			{
				write(2, "Error occured\n", 15);
				exit(1);
			}

		}
		buff[index2] = format[index];
		arg_count += 1;

		index++;
		index2++;

	}
	buff[index2] = '\0';
	write(1, buff, arg_count);
	va_end(ap);
	return (arg_count);
}
