#include "main.h"
/**
 * print_c - prints a single character
 * @params: argument list containing the character to be printed
 *
 * Return: 0
 */
int print_c(va_list params, int *counter)
{
	char chr;
	char *chr_ptr;

	chr = va_arg(params, int);
	chr_ptr = &chr;

	write(1, chr_ptr, 1);
	*(counter)++;

	return (0);
}
