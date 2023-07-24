#include "main.h"

/************************* WRITE HANDLE *************************/
/**
 * handle_write_char - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags.
 * @field_width: get field_width.
 * @precision: precision specifier
 * @modifier: Modifier specifier
 *
 * Return: Number of chars total_printed.
 */
int handle_write_char(char c, char buffer[], int format_flags, int field_width, int precision, int modifier)
{ /* char is stored at left and paddind at buffer's right */
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(modifier);

	if (format_flags & F_ZERO)
		padd = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (field_width > 1)
	{
		buffer[BUFF_MODIFIER - 1] = '\0';
		for (i = 0; i < field_width - 1; i++)
			buffer[BUFF_MODIFIER - i - 2] = padd;
																	if (format_flags & F_MINUS)
			return (write(1, &buffer[0], 1) + write(1, &buffer[BUFF_MODIFIER - i - 1], field_width - 1));
		else
			return (write(1, &buffer[BUFF_MODIFIER - i - 1], field_width - 1) + write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}

/************************* WRITE NUMBER *************************/
/**
 * write_number - Prints a string
 * @is_negative: List of arguments
 * @ind: char types.
 * @buffer: Buffer array to handle print
 * @format_flags:  Calculates active format_flags
 * @field_width: get field_width.
 * @precision: precision specifier
 * @modifier: Modifier specifier
 *
 * Return: Number of chars total_printed.
 */

int write_number(int is_negative, int ind, char buffer[], int format_flags, int field_width, int precision, int modifier)
{
	int length = BUFF_MODIFIER - ind - 1;
	char padd = ' ', extra_ch = 0;

	UNUSED(modifier);

	if ((format_flags & F_ZERO) && !(format_flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (format_flags & F_PLUS)
		extra_ch = '+';
	else if (format_flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, format_flags, field_width, precision, length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @format_flags: Format_flags
 * @field_width: field_width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of total_printed chars.
 */

int write_num(int ind, char buffer[], int format_flags, int field_width, int prec, int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_MODIFIER - 2 && buffer[ind] == '0' && field_width == 0)
		return (0); /* printf(".0d", 0)  no char is total_printed */
	if (prec == 0 && ind == BUFF_MODIFIER - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' '; /* field_width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		padd = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_c != 0)
		length++;
	if (field_width > length)
	{
		for (i = 1; i < field_width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (format_flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(format_flags & F_MINUS) && padd == ' ')/* extra char to left of buff */
		{
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(format_flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			return (write(1, &buffer[padd_start], i - padd_start) + write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @format_flags: Format_flags specifiers
 * @field_width: Field_width specifier
 * @precision: Precision specifier
 * @modifier: Modifier specifier
 *
 * Return: Number of written chars.
 */

int write_unsgnd(int is_negative, int ind, char buffer[], int format_flags, int field_width, int precision, int modifier)
{
	/* The number is stored at the bufer's right and starts at position i */
	int length = BUFF_MODIFIER - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(modifier);

	if (precision == 0 && ind == BUFF_MODIFIER - 2 && buffer[ind] == '0')
		return (0); /* printf(".0d", 0)  no char is total_printed */

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((format_flags & F_ZERO) && !(format_flags & F_MINUS))
		padd = '0';

	if (field_width > length)
	{
		for (i = 0; i < field_width - length; i++)
			buffer[i] = padd;
		buffer[i] = '\0';

		if (format_flags & F_MINUS) /* Asign extra char to left of buffer [buffer>padd]*/
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to left of padding [padd>buffer]*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}
	return (write(1, &buffer[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @field_width: Field_width specifier
 * @format_flags: Format_flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */

int write_pointer(char buffer[], int ind, int length, int field_width, int format_flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (field_width > length)
	{
		for (i = 3; i < field_width - length + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (format_flags & F_MINUS && padd == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(format_flags & F_MINUS) && padd == ' ')/* extra char to left of buffer */
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(format_flags & F_MINUS) && padd == '0')/* extra char to left of padd */
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +	write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extra_c)
		buffer[--ind] = extra_c;
	return (write(1, &buffer[ind], BUFF_MODIFIER - ind - 1));
}
