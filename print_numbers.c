#include "main.h"

/**
 * print_number - prints an integer
 * @n: The integer
 * Return: returns count of char
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
	count++;

	return (count);
}

/**
 * print_d - prints a decimal
 * @params: the decimal
 * @counter: args counter
 * Return: a number
 */
int print_d(va_list params, int *counter)
{
	int d;

	d = va_arg(params, int);

	*(counter) += print_number(d);
	return (0);
}

/**
 * print_i - prints a integer
 * @params: the integer
 * @counter: args counter
 * Return: a number
 */
int print_i(va_list params, int *counter)
{
	int i;

	i = va_arg(params, int);

	*(counter) += print_number(i);
	return (0);
}
