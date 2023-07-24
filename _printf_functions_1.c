#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: Arguments a of arguments
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags
 * @field_width: Field_width
 * @precision: Precision specification
 * @modifier: Modifier specifier
 * Return: Number of chars total_printed
 */

int print_char(va_list types, char buffer[], int format_flags, int field_width, int precision, int modifier)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, format_flags, field_width, precision, modifier));
}

/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: Arguments a of arguments
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags
 * @field_width: get field_width.
 * @precision: Precision specification
 * @modifier: Modifier specifier
 * Return: Number of printed chars
 */

int print_string(va_list types, char buffer[], int format_flags, int field_width, int precision, int modifier)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(format_flags);
	UNUSED(field_width);
	UNUSED(precision);
	UNUSED(modifier);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (field_width > length)
	{
		if (format_flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (i = field_width - length; i > 0; i--)
				write(1, " ", 1);
			return (field_width);
		}
		else
		{
			for (i = field_width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (field_width);
		}
	}
	return (write(1, str, length));
}

/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: list of arguments
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags
 * @field_width: get field_width.
 * @precision: Precision specification
 * @modifier: Modifier specifier
 * Return: Number of printed chars
 */
int print_percent(va_list types, char buffer[], int format_flags, int field_width, int precision, int modifier)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(format_flags);
	UNUSED(field_width);
	UNUSED(precision);
	UNUSED(modifier);
	return (write(1, "%%", 1));
}
