#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer for print functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print
{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_t;

int _printf(const char *format, ...);
int prg_std(va_list __attribute__((unused)), char *, unsigned int);
int character(va_list arguments, char *buf, unsigned int buffer_index);
int str(va_list arguments, char *buf, unsigned int buffer_index);
int integer(va_list arguments, char *buf, unsigned int buffer_index);
int binary(va_list arguments, char *buf, unsigned int buffer_index);
int unsigned_int(va_list arguments, char *buf, unsigned int buffer_index);
int octal(va_list arguments, char *buf, unsigned int buffer_index);
int hexadecimal(va_list arguments, char *buf, unsigned int buffer_index);
int uppex_hex(va_list arguments, char *buf, unsigned int buffer_index);
int usr(va_list arguments, char *buf, unsigned int buffer_index);
int address(va_list arguments, char *buf, unsigned int buffer_index);
int reverse(va_list arguments, char *buf, unsigned int buffer_index);
int str_rot13(va_list arguments, char *buf, unsigned int buffer_index);
int lint(va_list arguments, char *buf, unsigned int buffer_index);
int lunt(va_list arguments, char *buf, unsigned int buffer_index);
int loct(va_list arguments, char *buf, unsigned int buffer_index);
int lhex(va_list arguments, char *buf, unsigned int buffer_index);
int lupx(va_list arguments, char *buf, unsigned int buffer_index);
int hint(va_list arguments, char *buf, unsigned int buffer_index);
int hunt(va_list arguments, char *buf, unsigned int buffer_index);
int hoct(va_list arguments, char *buf, unsigned int buffer_index);
int hhex(va_list arguments, char *buf, unsigned int buffer_index);
int hupx(va_list arguments, char *buf, unsigned int buffer_index);
int pint(va_list arguments, char *buf, unsigned int buffer_index);
int noct(va_list arguments, char *buf, unsigned int buffer_index);
int nhex(va_list arguments, char *buf, unsigned int buffer_index);
int nupx(va_list arguments, char *buf, unsigned int buffer_index);
int sint(va_list arguments, char *buf, unsigned int buffer_index);
int (*select_func(const char *s, int index))(va_list, char *, unsigned int);
int ret_print_id(const char *s, int index);
unsigned int handle_buffer(char *buf, char c, unsigned int buffer_index);
int print_buffer(char *buf, unsigned int nbuf);
char *fill_bin_arr(char *binary, long int int_in, int isneg, int limit);
char *fill_oct_arr(char *bnr, char *oct);
char *fill_long_oct_arr(char *bnr, char *oct);
char *fill_shrt_oct_arr(char *bnr, char *oct);
char *fill_hex_arr(char *bnr, char *hex, int isupp, int limit);

#endif

