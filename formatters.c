#include "main.h"
/**
 * print_c - prints a single character
 * @params: argument list containing the character to be printed
 * @counter : args counter
 * Return: 0
 */
int print_c(va_list params, int *counter)
{
	char chr;
	char *chr_ptr;

	chr = va_arg(params, int);
	chr_ptr = &chr;

	write(1, chr_ptr, 1);
	*(counter) += 1;

	return (0);
}
