#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* Flag Modifier Macros */
#define PLUS 1
#define SPACE 2
#define HASH 4
#define ZERO 8
#define NEG 16
#define PLUS_FLAG (flags & 1)
#define SPACE_FLAG ((flags >> 1) & 1)
#define HASH_FLAG ((flags >> 2) & 1)
#define ZERO_FLAG ((flags >> 3) & 1)
#define NEG_FLAG ((flags >> 4) & 1)

/* Length Modifier Macros */
#define SHORT 1
#define LONG 2

/**
 * struct buffer_s - A new type defining a buffer struct.
 * @buffer: A pointer to a character array.
 * @start: A pointer to the start of buffer.
 * @len: The length of the string stored in buffer.
 */
typedef struct buffer_s
{
	char *buffer;
	char *start;
	unsigned int len;
} buf;

/**
 * struct converter_s - A new type defining a converter struct.
 * @specifier: A character representing a conversion specifier.
 * @func: A pointer to a conversion function corresponding to specifier.
 */
typedef struct converter_s
{
	unsigned char specifier;
	unsigned int (*callback)(va_list, buf *,
			unsigned char, int, int, unsigned char);
} converter_t;

/**
 * struct flag_s - A new type defining a flags struct.
 * @flag: A character representing a flag.
 * @value: The integer value of the flag.
 */
typedef struct flag_s
{
	unsigned char flag;
	unsigned char value;
} flag_t;

int _printf(const char *format, ...);

/* Conversion Specifier Functions */
unsigned int handle_c(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_s(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_di(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_percent(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_b(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_u(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_o(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_x(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_X(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_S(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_p(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_r(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);
unsigned int handle_R(va_list params, buf *output,
		unsigned char flags, int wid, int prec, unsigned char len);

/* Handlers */
unsigned char handle_flags(const char *flags, char *index);
unsigned char handle_length(const char *modifier, char *index);
int handle_width(va_list params, const char *modifier, char *index);
int handle_precision(va_list params, const char *modifier, char *index);
unsigned int (*h_s(const char *specifier))(va_list, buf *,
		unsigned char, int, int, unsigned char);

/* Modifiers */
unsigned int print_width(buf *output, unsigned int printed,
		unsigned char flags, int wid);
unsigned int print_string_width(buf *output,
		unsigned char flags, int wid, int prec, int size);
unsigned int print_neg_width(buf *output, unsigned int printed,
		unsigned char flags, int wid);

/* Helper Functions */
buf *init_buffer(void);
void free_buffer(buf *output);
unsigned int _memcpy(buf *output, const char *src, unsigned int n);
unsigned int handle_sbase(buf *output, long int num, char *base,
		unsigned char flags, int wid, int prec);
unsigned int handle_ubase(buf *output, unsigned long int num, char *base,
		unsigned char flags, int wid, int prec);

#endif /* MAIN_H */
