#include "main.h"
/**
 * _putchar - writes characterbti to stdout
 * @c: char input
 * Return: number of characters written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
