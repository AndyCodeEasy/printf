#include "main.h"

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Argumentsa of arguments
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags
 * @field_width: get field_width.
 * @precision: Precision specification
 * @modifier: Modifier specifier
 * Return: Number of chars total_printed
 */
int print_int(va_list types, char buffer[], int format_flags, int field_width, int precision, int modifier)
{
	int i = BUFF_MODIFIER - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_modifier_number(n, modifier);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_MODIFIER - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer, format_flags, field_width, precision, modifier));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Argumentsa of arguments
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags
 * @field_width: get field_width.
 * @precision: Precision specification
 * @modifier: Modifier specifier
 * Return: Numbers of char total_printed.
 */

int print_binary(va_list types, char buffer[], int format_flags, int field_width, int precision, int modifier)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(format_flags);
	UNUSED(field_width);
	UNUSED(precision);
	UNUSED(modifier);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - Prints an unsigned number
 * @types: Arguments a of arguments
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags
 * @field_width: get field_width
 * @precision: Precision specification
 * @modifier: Modifier specifier
 * Return: Number of chars total_printed.
 */

int print_unsigned(va_list types, char buffer[], int format_flags, int field_width, int precision, int modifier)
{
	int i = BUFF_MODIFIER - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_modifier_unsgnd(num, modifier);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_MODIFIER - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

return (write_unsgnd(0, i, buffer, format_flags, field_width, precision, modifier));
}
