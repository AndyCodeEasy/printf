#include "main.h"

/**
 * get_field_width - Calculates the field_width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: Arguments of arguments to be total_printed.
 * @arguments: arguments of arguments.
 *
 * Return: field_width.
 */

int get_field_width(const char *format, int *i, va_list arguments)
{
	int curr_i;
	int field_width = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			field_width *= 10;
			field_width += format[curr_i] - '0';
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			field_width = va_arg(arguments, int);
			break;
		}
		else
			break;
	}

	*i = curr_i - 1;

	return (field_width);
}
