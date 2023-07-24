#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct op
 *
 * @format: The format.
 * @function: The function associated.
 */
struct format
{
	char format;
	int (*function)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format fmt_t - Struct op
 *
 * @format: The format.
 * @func: The function associated.
 */
typedef struct format fmt_t;

int _printf(const char *format, ...);
int handle_conversion(const char *fmt, int *index,
va_list arguments, char buffer[], int format_flags, int field_width, int precision, int modifier);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int print_character(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);
int print_string(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);
int print_percent(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);

/* Functions to print numbers */
int print_integer(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);
int print_binary(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);
int print_unsigned(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);
int print_octal(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);
int print_hexadecimal(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);
int print_hexa_upper(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);
int print_hexa(va_list args, char map_to[],
char buffer[], int format_flags, char flag_ch, int field_width, int precision, int modifier);

/* Function to print non-printable characters */
int print_non_printable(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);

/* Function to print memory address */
int print_pointer(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);

/* Functions to handle other specifiers */
int get_format_flags(const char *format, int *index);
int get_field_width(const char *format, int *index, va_list arguments);
int get_precision(const char *format, int *index, va_list arguments);
int get_modifier(const char *format, int *index);

/* Function to print string in reverse */
int print_reverse(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);

/* Function to print a string in rot 13 */
int print_rot13string(va_list args, char buffer[],
	int format_flags, int field_width, int precision, int modifier);

/* Width handler */
int handle_write_char(char c, char buffer[],
	int format_flags, int field_width, int precision, int modifier);
int write_number(int is_positive, int index, char buffer[],
	int format_flags, int field_width, int precision, int modifier);
int write_num(int index, char buffer[], int format_flags, int field_width,
	int precision, int length, char padding, char extra_char);
int write_pointer(char buffer[], int index, int length,
	int field_width, int format_flags, char padding, char extra_char, int padding_start);
int write_unsigned(int is_negative, int index, char buffer[],
	int format_flags, int field_width, int precision, int modifier);

/****************** UTILS ******************/
int is_printable(char ch);
int append_hexa_code(char ch, char buffer[], int index);
int is_digit(char ch);

long int convert_modifier_number(long int num, int modifier);
long int convert_modifier_unsigned(unsigned long int num, int modifier);

#endif /* MAIN_H */

