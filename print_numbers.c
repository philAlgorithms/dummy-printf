#include "main.h"

/**
 * print_number - prints an integer
 * @n: The integer
 */
int print_number(int n)
{
	unsigned int number = n;
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		number = -1 * number;
	}
	if ((number / 10) > 0)
		print_number(number / 10);
	_putchar((number % 10) + '0');

	return (count);
}

/**
 * print_d - prints a decimal
 * @n: the decimal
 *
 * Return: a number
 */
int print_d(va_list params)
{
	int d;

	d = va_arg(params, int);

	return print_number(d);
}

/**
 * print_i - prints a integer
 * @n: the integer
 *
 * Return: a number
 */
int print_i(va_list params)
{
	int i;

	i = va_arg(params, int);

	return print_number(i);
}
