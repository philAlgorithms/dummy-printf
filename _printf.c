#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * get_strlen - calculates amount of memory to allocate
 * @format: string format
 * @ap: va_list ap
 * Return: amount of memory to allocate
 */
int get_strlen(const char *format, va_list ap)
{
	int count = 0, index = 0, ap_index;
	char *str;

	while (format[index])
	{
		if (format[index] == '%' && format[index + 1] == 'c')
		{
			count++;
			index += 2;
			continue;
		}

		if (format[index] == '%' && format[index + 1] == 's')
		{
			str = va_arg(ap, char *);
			ap_index = 0;

			while (str[ap_index])
				count++;
			index += 2;
			continue;

		}
		count++;
		index++;
	}
	return (count);

}
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
	char *buff = malloc(sizeof(char) * get_strlen(format, ap));

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
