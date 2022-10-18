#include "main.h"

unsigned int handle_c(va_list params, buf * output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_percent(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_p(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/**
 * handle_c - Converts an argument to an unsigned char and
 *             stores it to a buffer contained in a struct.
 * @params: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buf struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int handle_c(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char c;
	unsigned int count = 0;

	(void)prec;
	(void)len;

	c = va_arg(params, int);

	count += print_width(output, count, flags, wid);
	count += _memcpy(output, &c, 1);
	count += print_neg_width(output, count, flags, wid);

	return (count);
}

/**
 * handle_percent - Stores a percent sign to a
 *                   buffer contained in a struct.
 * @params: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buf struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer (always 1).
 */
unsigned int handle_percent(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char percent = '%';
	unsigned int count = 0;

	(void)params;
	(void)prec;
	(void)len;

	count += print_width(output, count, flags, wid);
	count += _memcpy(output, &percent, 1);
	count += print_neg_width(output, count, flags, wid);

	return (count);
}

/**
 * handle_p - Converts the address of an argument to hex and
 *             stores it to a buffer contained in a struct.
 * @params: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buf struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */
unsigned int handle_p(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *null = "(nil)";
	unsigned long int address;
	unsigned int count = 0;

	(void)len;

	address = va_arg(params, unsigned long int);
	if (address == '\0')
		return (_memcpy(output, null, 5));

	flags |= 32;
	count += handle_ubase(output, address, "0123456789abcdef",
			flags, wid, prec);
	count += print_neg_width(output, count, flags, wid);

	return (count);
}
