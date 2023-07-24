#include "main.h"

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags
 * @field_width: get field_width
 * @precision: Precision specification
 * @modifier: Modifier specifier
 * Return: Number of chars total_printed
 */

int print_octal(va_list types, char buffer[], int format_flags, int field_width, int precision, int modifier)
{
	int i = BUFF_MODIFIER - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(field_width);

	num = convert_modifier_unsgnd(num, modifier);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_MODIFIER - 1] = '\0';
		while (num > 0)
		{
			buffer[i--] = (num % 8) + '0';
			num /= 8;
																	}

	if (format_flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, format_flags, field_width, precision, modifier));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags
 * @field_width: get field_width
 * @precision: Precision specification
 * @modifier: Modifier specifier
 * Return: Number of chars total_printed
 */
int print_hexadecimal(va_list types, char buffer[], int format_flags, int field_width, int precision, int modifier)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
	format_flags, 'x', field_width, precision, modifier));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags
 * @field_width: get field_width
 * @precision: Precision specification
 * @modifier: Modifier specifier
 * Return: Number of chars total_printed
 */
int print_hexa_upper(va_list types, char buffer[], int format_flags, int field_width, int precision, int modifier)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
	format_flags, 'X', field_width, precision, modifier));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: list of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags
 * @flag_ch: Calculates active format_flags
 * @field_width: get field_width
 * @precision: Precision specification
 * @modifier: Modifier specifier
 * @modifier: Modifier specification
 * Return: Number of chars total_printed
 */
int print_hexa(va_list types, char map_to[], char buffer[], int format_flags, char flag_ch, int field_width, int precision, int modifier)
{
	int i = BUFF_MODIFIER - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(field_width);
	num = convert_modifier_unsgnd(num, modifier);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_MODIFIER - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (format_flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;

	return (write_unsgnd(0, i, buffer, format_flags, field_width, precision, modifier));
}
