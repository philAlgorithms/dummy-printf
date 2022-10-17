#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

#ifndef MAIN_H
#define MAIN_H

int _printf(const char *format, ...);

typedef struct converter {
	char specifier;
	int (*callback)(va_list params);
} convert_t;

int (*handle_conversion(const char *format))(va_list params);

/**
 * helper functions
 */
int _putchar(char c);

/**
 * concerning charactees and strings
 */
int print_c(va_list params);
int print_s(va_list args);

/**
 * Concerning numbers
 */
int print_number(int n);
int print_d(va_list params);
int print_i(va_list params);

#endif
