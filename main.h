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

int print_c(va_list params);
int print_s(va_list args);

#endif
