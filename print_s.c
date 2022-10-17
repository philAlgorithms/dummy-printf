#include "main.h"

/**
 * print_s - handles %s format
 * @arg: va_list arg
 * Return: 0
 */
int print_s(va_list arg, int *counter)
{
	char *str;
	int count = 0, index = 0;

	str = va_arg(arg, char *);

	while (str[index])
	{
		count++;
		index++;
	}
	write(1, str, count);
	*(counter) += count;
	return (0);

}
