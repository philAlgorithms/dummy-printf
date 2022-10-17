#include "main.h"
#include <stdio.h>

int _printf(const char *format, ...);

int main(void)
{
	int args, num = 10;
	char c = 'b';
	char y = 'y';
	char d = '1';

	args = _printf("hello %co%c\nI love the way you role\nYou are my number: %c\n", c, y, d);
	printf("number of args printed: %d\n", args);

	args = _printf("King Lucas Bolt\n");
	printf("number of args printed: %d\n", args);
	args = _printf("You are %d/%d baby.\n", num, num);
	_printf("number of args printed: %i\n", args);
	return (0);
}
