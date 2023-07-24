#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: chars_printed.
 */

void print_buffer(char buffer[], int *buff_index);

int _printf(const char *format, ...)
{
	int i, total_printed = 0, chars_printed = 0;
	int format_flags, field_width, precision, modifier, buff_index = 0;
	va_list arguments;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return -1;

	va_start(arguments, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
        	{
			buffer[buff_index++] = format[i];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			chars_printed++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			format_flags = get_format_flags(format, &i);
			field_width = get_field_width(format, &i, arguments);
			precision = get_precision(format, &i, arguments);
			modifier = get_modifier(format, &i);
			++i;
			total_printed = handle_conversion(format, &i, arguments, buffer,
							format_flags, field_width, precision, modifier);
			if (total_printed == -1)
				return -1;
			chars_printed += total_printed;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(arguments);

	return chars_printed;
}

void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
